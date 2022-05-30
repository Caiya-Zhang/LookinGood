/*! \Author		    Group 18 (Caiya Zhang, Tianyang Yang, Yuzhuo Lei, Yifei Han, Haohan Liu)
	\Name		    zoom.h
    \Description    Header file for Zoom class.
	\Date		    Oct 2021
*/

#ifndef ZOOM_H
#define ZOOM_H

#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

class Zoom
{
public:
    // constructor
    Zoom(cv::Mat& image, cv::Mat& originalImg, int& zoomRec);
    // destructor
    ~Zoom();
};

#endif
