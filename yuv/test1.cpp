#include <iostream>
#include "opencv2/opencv.hpp"
#include "scaleprocess.h"
#include "colorspace.h"
#include "perforval.h"

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << "[usage] ./out/demo [path-to-your-picture]" << std::endl;
		return -1;
	}

	cv::Mat image = cv::imread(argv[1]);

	if (image.empty())
	{
		std::cout << "[ERROR] Can't open image: " << argv[1] << std::endl;
		return -1;
	}

    long long t1 = gct();

    int len = image.cols*image.rows;
    float *y = (float*)malloc(sizeof(float)*len);
    float *new_y = (float*)malloc(sizeof(float)*len);
    float *u = (float*)malloc(sizeof(float)*len);
    float *v = (float*)malloc(sizeof(float)*len);

    bgr2yuv(image.data,image.cols,image.rows,y,u,v) ;

    float y_max=fmax(y,len);
    float y_min=fmin(y,len);

    sca2max(y,len,y_max,y_min,new_y);

    delete []y;

    cv::Mat new_image = cv::Mat(image.rows, image.cols, CV_8UC3, cv::Scalar(0, 0, 0));

    yuv2bgr(new_image.data,image.cols,image.rows,new_y,u,v);

    delete []new_y;
    delete []u;
    delete []v;

    long long t2 = gct();

    std::cout << "Execution time: " << t2 - t1 << " ms" << std::endl;

    cv::imshow("old image", image);
	cv::imshow("new image", new_image);
	cv::imwrite("./newimage.jpg",new_image);
	cv::waitKey(0);

	return 0;
}
