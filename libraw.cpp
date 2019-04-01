#include <iostream>
#include <memory>
#include <libraw/libraw.h>

int main()
{
   LibRaw RawProcessor;
   RawProcessor.open_file("sample/bench_frame.dng");
   printf("Image size: %d x %d\n", RawProcessor.imgdata.sizes.width, RawProcessor.imgdata.sizes.height);
   RawProcessor.unpack();
   RawProcessor.raw2image();
   
   RawProcessor.dcraw_ppm_tiff_writer("sample.ppm");

   for(int i = 0; i < 100; i++)
   {
      printf("i=%d R=%d G=%d B=%d G2=%d\n", i,
         RawProcessor.imgdata.image[i][0],
         RawProcessor.imgdata.image[i][1],
         RawProcessor.imgdata.image[i][2],
         RawProcessor.imgdata.image[i][3]  );
   }

   RawProcessor.recycle();
   return 0;

}



