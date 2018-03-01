// g++ test_blobmqtt.cpp -lopencv_core -lopencv_highgui -lopencv_features2d -lopencv_imgproc -lopencv_video -o blobber && ./grab | ./blobber

#include <stdio.h>
#include <unistd.h>
#include <vector>

#include <errno.h>


#include <opencv2/core/core.hpp>
#include <opencv2/core/utility.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/video/background_segm.hpp>

#include "../Lepton/Lepton.h"
#include "../Lepton/Lepton_Pixels.h"


#include "util.h"



struct CM_Tracker
{
	cv::Point2f P;
	cv::Point2f D;
	int Duration;
	int Persistence;
	int Id;
};



void Reciever (struct Lepton_Pixel_Grayscale16 * Pixmap)
{
   size_t const Size = sizeof (struct Lepton_Pixel_Grayscale16 [Lepton3_Width * Lepton3_Height]);
   int R = read (STDIN_FILENO, Pixmap, Size);
   assert (R == Size);
}


void Persistent_Tracker 
(
	std::vector<cv::KeyPoint>& Targets,
	std::vector<CM_Tracker>& Trackers,
	float Proximity = 10.0f,
	int Persistence = 100
)
{
	for (size_t I = 0; I < Targets.size (); I = I + 1)
	{
		float Distance_Min = 10000;
		float Distance;
		ssize_t Index_Min = -1;
		
		//Find the closest tracker to the target and
		//exchange information.
		for (size_t J = 0; J < Trackers.size (); J = J + 1)
		{
			Distance = cv::norm (Trackers [J].P - Targets [I].pt);
			
			//It is very important to update used trackers also.
			//If the tracker is being used then only track the target in proximity.
			if ((Trackers [J].Persistence > 0) && (Distance > Proximity)) {continue;};
			if (Distance < Distance_Min)
			{
				Distance_Min = Distance;
				Index_Min = J;
			}
		}
		if (Index_Min == -1) {continue;};
		
		Trackers [Index_Min].D = Trackers [Index_Min].pt - Targets [I].pt;
		Trackers [Index_Min].P = Targets [I].pt;
		Trackers [Index_Min].Persistence = Persistence;
		Trackers [Index_Min].Duration += 1.0f;
	}


	//Tracker that does not track will lose interest and 
	//release it self to tracke other targets.
	for (size_t I = 0; I < Trackers.size (); I = I + 1)
	{
		if (Trackers [I].Persistence > 0) 
		{
			Trackers [I].Persistence -= 1;
		};
	}
}




struct CM_Counter
{
	size_t N;
	size_t S;
	size_t W;
	size_t E;
};

size_t const CM_Size = 10;
cv::Rect const CM_N (CM_Size, 0, Lepton3_Width - (CM_Size*2), CM_Size);
cv::Rect const CM_S (CM_Size, Lepton3_Height - CM_Size, Lepton3_Width - (CM_Size*2), CM_Size);
cv::Rect const CM_W (0, CM_Size, CM_Size, Lepton3_Height - (CM_Size*2));
cv::Rect const CM_E (Lepton3_Width - CM_Size, CM_Size, CM_Size, Lepton3_Height - (CM_Size*2));

cv::Rect const CM_NW (0, 0, CM_Size, CM_Size);
cv::Rect const CM_NE (Lepton3_Width - CM_Size, 0, CM_Size, CM_Size);
cv::Rect const CM_SW (0, Lepton3_Height - CM_Size, CM_Size, CM_Size);
cv::Rect const CM_SE (Lepton3_Width - CM_Size, Lepton3_Height - CM_Size, CM_Size, CM_Size);


void Countman 
(
	std::vector<CM_Tracker>& Trackers,
	struct CM_Counter& Counter
)
{
	for (size_t I = 0; I < Trackers.size (); I = I + 1)
	{
		if (Trackers [I].Persistence == 1)
		{
			cv::Point2f P = Trackers [I].P;
			float Duration = Trackers [I].Duration;
			Trackers [I].Duration = 0;
			//printf ("P: %i %f %f\n", Trackers [I].class_id, P.x, P.y);
			//printf ("P: %i %f\n", Trackers [I].class_id, Trackers [I].response);
			if (Duration < 30.0f){continue;}
			
			
			//printf ("P: %i %f\n", Trackers [I].class_id, (180.0f / M_PI) * Trackers [I].angle);
			
			if (0) {}
			
			else if (CM_N.contains (P)) 
			{
				Counter.N ++;
				printf ("N : %d\n", Counter.N);
			}
			else if (CM_S.contains (P)) 
			{
				Counter.S ++;
				printf ("S : %d\n", Counter.S);
			}
			else if (CM_W.contains (P)) 
			{
				Counter.W ++;
				printf ("W : %d\n", Counter.W);
			}
			else if (CM_E.contains (P)) 
			{
				Counter.E ++;
				printf ("E : %d\n", Counter.E);
			}
			else if (CM_NE.contains (P)) 
			{
				
			}
			
			Trackers [I].P = {Lepton3_Width / 2.0f, Lepton3_Height/2.0f};
		}
	}
}

int main (int argc, char * argv [])
{
	Assert (argc == 1, "argc %i.", argc);
	Assert (argv[0] != NULL, "argv0 %p.", argv[0]);


	int Should_Run = 1;

	struct Lepton_Pixel_Grayscale16 Pixmap [Lepton3_Width * Lepton3_Height];
	cv::Mat M1 (Lepton3_Height, Lepton3_Width, CV_16U, Pixmap);
	cv::Mat M2 (Lepton3_Height, Lepton3_Width, CV_8UC1);
	cv::Mat M3 (Lepton3_Height, Lepton3_Width, CV_8UC3);
	cv::Mat Foreground;

	cv::namedWindow ("W1", CV_WINDOW_NORMAL | CV_WINDOW_OPENGL);
	//cv::setWindowProperty ("W1", CV_WND_PROP_FULLSCREEN, CV_WINDOW_FULLSCREEN);
	cv::resizeWindow ("W1", Lepton3_Width*2, Lepton3_Height*2);

	cv::SimpleBlobDetector::Params Params;
	Params.minThreshold = 60;
	Params.maxThreshold = 255;
	Params.filterByColor = false;
	Params.blobColor = 100;
	Params.filterByArea = true;
	Params.minArea = 10;
	Params.maxArea = 100;
	Params.filterByCircularity = false;
	Params.minCircularity = 0.1;
	Params.maxCircularity = 1.0;
	Params.filterByConvexity = false;
	Params.minConvexity = 0.0;
	Params.maxConvexity = 0.5;
	Params.filterByInertia = false;
	Params.minInertiaRatio = 0.0;
	Params.maxInertiaRatio = 0.5;

	cv::Ptr<cv::SimpleBlobDetector> Blobber = cv::SimpleBlobDetector::create (Params);
	std::vector<cv::KeyPoint> Targets;
	std::vector<CM_Tracker> Trackers (4);

	cv::Ptr<cv::BackgroundSubtractor> Subtractor = cv::createBackgroundSubtractorMOG2 ();

	cv::RNG rng (0xFFF1231);

	for (size_t I = 0; I < Trackers.size (); I = I + 1)
	{
		Trackers [I].Id = I;
		Trackers [I].P.x = rng.uniform (0, Lepton3_Width);
		Trackers [I].P.y = rng.uniform (0, Lepton3_Height);
	}
	
	struct CM_Counter Counter = {0, 0, 0, 0};
	


	while (Should_Run)
	{

		Reciever (Pixmap);
		Subtractor->apply (M1, Foreground);
		Foreground.convertTo (M2, CV_8U);
		cv::GaussianBlur (M2, M2, cv::Size (11, 11), 3.5, 3.5);
		Blobber->detect (M2, Targets);
		cv::cvtColor (M2, M3, cv::COLOR_GRAY2BGR);
		//cv::drawTargets (M2, Targets, M3, cv::Scalar (0, 100, 255), cv::DrawMatchesFlags::DRAW_RICH_Targets);
		
		Persistent_Tracker (Targets, Trackers);
		Countman (Trackers, Counter);
		
		
		
		for (size_t I = 0; I < Trackers.size (); I = I + 1)
		{
			char Buffer [128];
			sprintf (Buffer, "%d", Trackers [I].Id);
			cv::putText (M3, Buffer, Trackers [I].P + cv::Point2f (-3.0f, 3.0f), CV_FONT_HERSHEY_SCRIPT_SIMPLEX, 0.4, cv::Scalar (0, 0, 255), 1);
			cv::circle (M3, Trackers [I].P, 6.0f, cv::Scalar (0, 255, 0), 1);
		}


		for (size_t I = 0; I < Targets.size (); I = I + 1)
		{
			cv::circle (M3, Targets [I].pt, 6.0f, cv::Scalar (255, 0, 0), 1);
		}
		
		
		cv::rectangle (M3, CM_N, cv::Scalar (255, 0, 255));
		cv::rectangle (M3, CM_S, cv::Scalar (255, 0, 255));
		cv::rectangle (M3, CM_W, cv::Scalar (255, 0, 255));
		cv::rectangle (M3, CM_E, cv::Scalar (255, 0, 255));
		
		cv::rectangle (M3, CM_NE, cv::Scalar (255, 0, 255));
		cv::rectangle (M3, CM_NW, cv::Scalar (255, 0, 255));
		cv::rectangle (M3, CM_SE, cv::Scalar (255, 0, 255));
		cv::rectangle (M3, CM_SW, cv::Scalar (255, 0, 255));
		
		//Draw_Triangle (M3, CM_NWN);
		
		cv::imshow ("W1", M3);
		//cv::imshow ("W1", M2);

		int Key = cv::waitKey (1);
		if (Key == 'q') {Should_Run = 0;};
		if (Key == 'u') {Foreground = M1;}
		
		
		if (Key == 'p') 
		{
			while (1) 
			{
				Key = cv::waitKey (1);
				if (Key == 'p') {break;};
			}
		};
	}
	return 0;
}
