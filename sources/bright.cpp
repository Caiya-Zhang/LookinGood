/*! \Author		    Group 18 (Caiya Zhang, Tianyang Yang, Yuzhuo Lei, Yifei Han, Haohan Liu)
	\Name		    filter.h
    \Description    Header file for Filter class.
	\Date		    Nov. 2021
*/

#include "../headers/bright.h"

using namespace std;

Bright::Bright(cv::Mat& image) 
{
    if(image.empty())
        return;

    cv::Mat new_image = cv::Mat::zeros(image.size(), image.type());
    double alpha = 2.0;  // Simple contrast control
    int beta = 10;       // Simple brightness control
    image.convertTo(image, -1, alpha, beta);
}

Bright::~Bright() {}