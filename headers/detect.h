/*! \Author		    Group 18 (Caiya Zhang, Tianyang Yang, Yuzhuo Lei, Yifei Han, Haohan Liu)
	\Name		    detect.h
    \Description    Header file for Detect class.
	\Date		    Oct 2021
*/

#ifndef DETECT_H
#define DETECT_H

#include <iostream>

#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

class Detect
{
public:
    // constructor
    Detect(cv::Mat& image);
    // destructor
    ~Detect();
};

#endif
