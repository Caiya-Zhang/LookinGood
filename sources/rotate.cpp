/*! \Author		    Group 18 (Caiya Zhang, Tianyang Yang, Yuzhuo Lei, Yifei Han, Haohan Liu)
	\Name		    rotate.cpp
    \Description    Source / Implementation file for Rotate class.
	\Date		    Nov 2021
*/

#include "../headers/rotate.h"

using namespace std;

Rotate::Rotate(cv::Mat& image) 
{
    cv::transpose(image, image);
    cv::flip(image, image, 1);
}

Rotate::~Rotate() {}