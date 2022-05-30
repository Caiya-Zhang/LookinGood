/*! \Author		    Group 18 (Caiya Zhang, Tianyang Yang, Yuzhuo Lei, Yifei Han, Haohan Liu)
	\Name		    flip.cpp
    \Description    Source / Implementation file for Flip class.
	\Date		    Oct 2021
*/

#include "../headers/flip.h"

using namespace std;

Flip::Flip(cv::Mat& image) 
{
    cv::flip(image, image, 1);
}

Flip::~Flip() {}
