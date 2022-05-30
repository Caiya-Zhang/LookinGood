/*! \Author		    Group 18 (Caiya Zhang, Tianyang Yang, Yuzhuo Lei, Yifei Han, Haohan Liu)
	\Name		    filter.h
    \Description    Header file for Filter class.
	\Date		    Oct 2021
*/

#ifndef FILTER_H
#define FILTER_H

#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

class Filter
{
public:
    // constructor
    Filter(cv::Mat& image);
    // destructor
    ~Filter();
};

#endif
