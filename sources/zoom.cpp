/*! \Author		    Group 18 (Caiya Zhang, Tianyang Yang, Yuzhuo Lei, Yifei Han, Haohan Liu)
	\Name		    zoom.cpp
    \Description    Source / Implementation file for Zoom class.
	\Date		    Oct 2021
*/

#include "../headers/zoom.h"

using namespace std;

Zoom::Zoom(cv::Mat& image, cv::Mat& originalImg, int& zoomRec) 
{
	int x = originalImg.size().width / 2;
    int y = originalImg.size().height / 2;

    int width = zoomRec, height = zoomRec;
	int ptoX = x - (zoomRec / 2), ptoY = y - (zoomRec / 2);

	if((x + (zoomRec / 2)) > image.size().width)
		width = width - ((x + (zoomRec / 2)) - image.size().width);

	if((y + (zoomRec / 2)) > image.size().height)
		height = height - ((y + (zoomRec / 2)) - image.size().height);		

	if((x - (zoomRec / 2)) < 0)
		ptoX = 0;

	if((y - (zoomRec / 2)) < 0)
		ptoY = 0;

	cv::Rect roi = cv::Rect(ptoX, ptoY, width, height);
	cv::Mat roiImage = image(roi);
	cv::resize(roiImage, roiImage, cv::Size(originalImg.size().width, originalImg.size().height), 0, 0, cv::INTER_LINEAR);

    image = roiImage;
}

Zoom::~Zoom() {}