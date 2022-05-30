/*! \Author		    Group 18 (Caiya Zhang, Tianyang Yang, Yuzhuo Lei, Yifei Han, Haohan Liu)
	\Name		    filter.cpp
    \Description    Source / Implementation file for Filter class.
	\Date		    Oct 2021
*/

#include "../headers/filter.h"

using namespace std;

Filter::Filter(cv::Mat& image) 
{
    // cv::GaussianBlur(image, image, cv::Size(5, 5), 0, 0);
    cv::Mat dst;

    int val1 = 3, val2 = 1;
    int dx = val1 * 5;
    double fc = val1 * 12.5;
    int p = 50;
    cv::Mat temp1, temp2, temp3, temp4;

    cv::bilateralFilter(image, temp1, dx, fc, fc);

    temp2 = (temp1 - image + 128);

    cv::GaussianBlur(temp2, temp3, cv::Size(2 * val2 - 1, 2 * val2 - 1), 0, 0);

    temp4 = image + 2 * temp3 - 255;

    dst = (image * (100 - p) + temp4 * p) / 100;
    dst.copyTo(image);
}

Filter::~Filter() {}
