/*! \Author		    Group 18 (Caiya Zhang, Tianyang Yang, Yuzhuo Lei, Yifei Han, Haohan Liu)
	\Name		    flip.h
    \Description    Header file for Flip class.
	\Date		    Oct 2021
*/

#ifndef FLIP_H
#define FLIP_H

#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

class Flip
{
public:
    // constructor
    Flip(cv::Mat& image);
    // destructor
    ~Flip();
};

#endif
