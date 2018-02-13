#pragma once

#include <assert.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <string.h>

#include "map.h"

struct __attribute__((__packed__)) Pixel_ABGR8888
{
   union
   {
      struct
      {
         uint8_t A;
         uint8_t B;
         uint8_t G;
         uint8_t R;
      } Channel;
      uint8_t Data [4];
   };
};

struct Pixel_ABGR8888 const Map_Pixel_ABGR8888_Heat256 [256] = {{  0, 255, 255, 255}, {  0, 253, 253, 253}, {  0, 251, 251, 251}, {  0, 249, 249, 249}, {  0, 247, 247, 247}, {  0, 245, 245, 245}, {  0, 243, 243, 243}, {  0, 241, 241, 241}, {  0, 239, 239, 239}, {  0, 237, 237, 237}, {  0, 235, 235, 235}, {  0, 233, 233, 233}, {  0, 231, 231, 231}, {  0, 229, 229, 229}, {  0, 227, 227, 227}, {  0, 225, 225, 225}, {  0, 223, 223, 223}, {  0, 221, 221, 221}, {  0, 219, 219, 219}, {  0, 217, 217, 217}, {  0, 215, 215, 215}, {  0, 213, 213, 213}, {  0, 211, 211, 211}, {  0, 209, 209, 209}, {  0, 207, 207, 207}, {  0, 205, 205, 205}, {  0, 203, 203, 203}, {  0, 201, 201, 201}, {  0, 199, 199, 199}, {  0, 197, 197, 197}, {  0, 195, 195, 195}, {  0, 193, 193, 193}, {  0, 191, 191, 191}, {  0, 189, 189, 189}, {  0, 187, 187, 187}, {  0, 185, 185, 185}, {  0, 183, 183, 183}, {  0, 181, 181, 181}, {  0, 179, 179, 179}, {  0, 177, 177, 177}, {  0, 175, 175, 175}, {  0, 173, 173, 173}, {  0, 171, 171, 171}, {  0, 169, 169, 169}, {  0, 167, 167, 167}, {  0, 165, 165, 165}, {  0, 163, 163, 163}, {  0, 161, 161, 161}, {  0, 159, 159, 159}, {  0, 157, 157, 157}, {  0, 155, 155, 155}, {  0, 153, 153, 153}, {  0, 151, 151, 151}, {  0, 149, 149, 149}, {  0, 147, 147, 147}, {  0, 145, 145, 145}, {  0, 143, 143, 143}, {  0, 141, 141, 141}, {  0, 139, 139, 139}, {  0, 137, 137, 137}, {  0, 135, 135, 135}, {  0, 133, 133, 133}, {  0, 131, 131, 131}, {  0, 129, 129, 129}, {  0, 126, 126, 126}, {  0, 124, 124, 124}, {  0, 122, 122, 122}, {  0, 120, 120, 120}, {  0, 118, 118, 118}, {  0, 116, 116, 116}, {  0, 114, 114, 114}, {  0, 112, 112, 112}, {  0, 110, 110, 110}, {  0, 108, 108, 108}, {  0, 106, 106, 106}, {  0, 104, 104, 104}, {  0, 102, 102, 102}, {  0, 100, 100, 100}, {  0,  98,  98,  98}, {  0,  96,  96,  96}, {  0,  94,  94,  94}, {  0,  92,  92,  92}, {  0,  90,  90,  90}, {  0,  88,  88,  88}, {  0,  86,  86,  86}, {  0,  84,  84,  84}, {  0,  82,  82,  82}, {  0,  80,  80,  80}, {  0,  78,  78,  78}, {  0,  76,  76,  76}, {  0,  74,  74,  74}, {  0,  72,  72,  72}, {  0,  70,  70,  70}, {  0,  68,  68,  68}, {  0,  66,  66,  66}, {  0,  64,  64,  64}, {  0,  62,  62,  62}, {  0,  60,  60,  60}, {  0,  58,  58,  58}, {  0,  56,  56,  56}, {  0,  54,  54,  54}, {  0,  52,  52,  52}, {  0,  50,  50,  50}, {  0,  48,  48,  48}, {  0,  46,  46,  46}, {  0,  44,  44,  44}, {  0,  42,  42,  42}, {  0,  40,  40,  40}, {  0,  38,  38,  38}, {  0,  36,  36,  36}, {  0,  34,  34,  34}, {  0,  32,  32,  32}, {  0,  30,  30,  30}, {  0,  28,  28,  28}, {  0,  26,  26,  26}, {  0,  24,  24,  24}, {  0,  22,  22,  22}, {  0,  20,  20,  20}, {  0,  18,  18,  18}, {  0,  16,  16,  16}, {  0,  14,  14,  14}, {  0,  12,  12,  12}, {  0,  10,  10,  10}, {  0,   8,   8,   8}, {  0,   6,   6,   6}, {  0,   4,   4,   4}, {  0,   2,   2,   2}, {  0,   0,   0,   0}, {  0,   9,   0,   0}, {  0,  16,   0,   2}, {  0,  24,   0,   4}, {  0,  31,   0,   6}, {  0,  38,   0,   8}, {  0,  45,   0,  10}, {  0,  53,   0,  12}, {  0,  60,   0,  14}, {  0,  67,   0,  17}, {  0,  74,   0,  19}, {  0,  82,   0,  21}, {  0,  89,   0,  23}, {  0,  96,   0,  25}, {  0, 103,   0,  27}, {  0, 111,   0,  29}, {  0, 118,   0,  31}, {  0, 120,   0,  36}, {  0, 121,   0,  41}, {  0, 122,   0,  46}, {  0, 123,   0,  51}, {  0, 124,   0,  56}, {  0, 125,   0,  61}, {  0, 126,   0,  66}, {  0, 127,   0,  71}, {  0, 128,   1,  76}, {  0, 129,   1,  81}, {  0, 130,   1,  86}, {  0, 131,   1,  91}, {  0, 132,   1,  96}, {  0, 133,   1, 101}, {  0, 134,   1, 106}, {  0, 135,   1, 111}, {  0, 136,   1, 116}, {  0, 136,   1, 121}, {  0, 137,   2, 125}, {  0, 137,   2, 130}, {  0, 137,   3, 135}, {  0, 138,   3, 139}, {  0, 138,   3, 144}, {  0, 138,   4, 149}, {  0, 139,   4, 153}, {  0, 139,   5, 158}, {  0, 139,   5, 163}, {  0, 140,   5, 167}, {  0, 140,   6, 172}, {  0, 140,   6, 177}, {  0, 141,   7, 181}, {  0, 141,   7, 186}, {  0, 137,  10, 189}, {  0, 132,  13, 191}, {  0, 127,  16, 194}, {  0, 121,  19, 196}, {  0, 116,  22, 198}, {  0, 111,  25, 200}, {  0, 106,  28, 203}, {  0, 101,  31, 205}, {  0,  95,  34, 207}, {  0,  90,  37, 209}, {  0,  85,  40, 212}, {  0,  80,  43, 214}, {  0,  75,  46, 216}, {  0,  69,  49, 218}, {  0,  64,  52, 221}, {  0,  59,  55, 223}, {  0,  49,  57, 224}, {  0,  47,  60, 225}, {  0,  44,  64, 226}, {  0,  42,  67, 227}, {  0,  39,  71, 228}, {  0,  37,  74, 229}, {  0,  34,  78, 230}, {  0,  32,  81, 231}, {  0,  29,  85, 231}, {  0,  27,  88, 232}, {  0,  24,  92, 233}, {  0,  22,  95, 234}, {  0,  19,  99, 235}, {  0,  17, 102, 236}, {  0,  14, 106, 237}, {  0,  12, 109, 238}, {  0,  12, 112, 239}, {  0,  12, 116, 240}, {  0,  12, 119, 240}, {  0,  12, 123, 241}, {  0,  12, 127, 241}, {  0,  12, 130, 242}, {  0,  12, 134, 242}, {  0,  12, 138, 243}, {  0,  13, 141, 243}, {  0,  13, 145, 244}, {  0,  13, 149, 244}, {  0,  13, 152, 245}, {  0,  13, 156, 245}, {  0,  13, 160, 246}, {  0,  13, 163, 246}, {  0,  13, 167, 247}, {  0,  13, 171, 247}, {  0,  14, 175, 248}, {  0,  15, 178, 248}, {  0,  16, 182, 249}, {  0,  18, 185, 249}, {  0,  19, 189, 250}, {  0,  20, 192, 250}, {  0,  21, 196, 251}, {  0,  22, 199, 251}, {  0,  23, 203, 252}, {  0,  24, 206, 252}, {  0,  25, 210, 253}, {  0,  27, 213, 253}, {  0,  28, 217, 254}, {  0,  29, 220, 254}, {  0,  30, 224, 255}, {  0,  39, 227, 255}, {  0,  53, 229, 255}, {  0,  67, 231, 255}, {  0,  81, 233, 255}, {  0,  95, 234, 255}, {  0, 109, 236, 255}, {  0, 123, 238, 255}, {  0, 137, 240, 255}, {  0, 151, 242, 255}, {  0, 165, 244, 255}, {  0, 179, 246, 255}, {  0, 193, 248, 255}, {  0, 207, 249, 255}, {  0, 221, 251, 255}, {  0, 235, 253, 255}, {  0,  24, 255, 255}};

struct Pixel_ABGR8888 const Map_Pixel_ABGR8888_BW2 [2] = {{0, 0, 0, 0}, {0, 255, 255, 255}};




void Copy_u16_ABGR8888 
(
   size_t Pixmap_Count,
   uint16_t const Source [Pixmap_Count],
   struct Pixel_ABGR8888 Destination [Pixmap_Count]
)
{
   for (size_t I = 0; I < Pixmap_Count; I = I + 1)
   {
      Destination [I].Channel.R = Source [I];
      Destination [I].Channel.G = Source [I];
      Destination [I].Channel.B = Source [I];
      Destination [I].Channel.A = 255;
   }
}


void Map_Pixel_u16_ABGR8888 
(
   uint16_t const * Source, 
   struct Pixel_ABGR8888 * Destination, 
   size_t Pixmap_Count, 
   struct Pixel_ABGR8888 const * Colormap,
   size_t Color_Count
)
{
   for (size_t I = 0; I < Pixmap_Count; I = I + 1)
   {
      assert (Source [I] < Color_Count);
      Destination [I].Channel.R = Colormap [Source [I]].Channel.R;
      Destination [I].Channel.G = Colormap [Source [I]].Channel.G;
      Destination [I].Channel.B = Colormap [Source [I]].Channel.B;
      Destination [I].Channel.A = 255;
   }
}


void Map_Pixel_float_ABGR8888 
(
   float const * Source, 
   struct Pixel_ABGR8888 * Destination, 
   size_t Pixmap_Count, 
   float Min, 
   float Max,
   struct Pixel_ABGR8888 const * Colormap,
   size_t Color_Count
)
{
   for (size_t I = 0; I < Pixmap_Count; I = I + 1)
   {
      size_t Index = (int) Map_Linear_float (Source [I], Min, Max, 0.0f, (float) Color_Count-1.0f);
      assert (Index < Color_Count);
      Destination [I].Channel.R = Colormap [Index].Channel.R;
      Destination [I].Channel.G = Colormap [Index].Channel.G;
      Destination [I].Channel.B = Colormap [Index].Channel.B;
      Destination [I].Channel.A = 255;
   }
}
