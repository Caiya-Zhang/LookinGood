/*! \Author		    Group 18 (Caiya Zhang, Tianyang Yang, Yuzhuo Lei, Yifei Han, Haohan Liu)
	\Name		    bright.h
    \Description    Header file for Rotate class.
	\Date		    Oct 2021
*/

#ifndef BRIGHT_H
#define BRIGHT_H

#include <iostream>

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

class Bright
{
public:
    // constructor
    Bright(cv::Mat& image);
    // destructor
    ~Bright();
};

#endif