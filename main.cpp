#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <zbar.h>
#include <iostream>

using namespace cv;
using namespace std;
using namespace zbar;


int main(int argc, char* argv[])
{
    VideoCapture cap(0); // open the video camera no. 0


    if (!cap.isOpened())  // if not success, exit program
    {
    	printf("Cannot open the video cam");
      return -1;
    }


    ImageScanner scanner;
      scanner.set_config(ZBAR_NONE, ZBAR_CFG_ENABLE, 1);

    while (1)
    {
        Mat frame;

        bool bSuccess = cap.read(frame); // read a new frame from video

         if (!bSuccess) //if not success, break loop
        {
          printf("Cannot read a frame from video stream");
          break;
        }

        Mat grey;
        cvtColor(frame,grey,CV_BGR2GRAY);

        int width = frame.cols;
        int height = frame.rows;
        uchar *raw = (uchar *)grey.data;
        // wrap image data
        Image image(width, height, "Y800", raw, width * height);
        // scan the image for barcodes
        scanner.scan(image);

        // extract results
        for(Image::SymbolIterator symbol = image.symbol_begin();  symbol != image.symbol_end();  ++symbol) {
          vector<Point> vp;
          printf("%s\n", symbol->get_data().c_str());
          return 0;
        }

    }
    return 0;

}
