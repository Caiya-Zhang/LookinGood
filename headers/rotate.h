/*! \Author		    Group 18 (Caiya Zhang, Tianyang Yang, Yuzhuo Lei, Yifei Han, Haohan Liu)
	\Name		    rotate.h
    \Description    Header file for Rotate class.
	\Date		    Oct 2021
*/

#ifndef ROTATE_H
#define ROTATE_H

#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

class Rotate
{
public:
    // constructor
    Rotate(cv::Mat& image);
    // destructor
    ~Rotate();
};

#endif