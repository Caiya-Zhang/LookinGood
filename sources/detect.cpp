/*! \Author		    Group 18 (Caiya Zhang, Tianyang Yang, Yuzhuo Lei, Yifei Han, Haohan Liu)
	\Name		    detect.cpp
    \Description    Source / Implementation file for Detect class.
	\Date		    Oct 2021
*/

#include "../headers/detect.h"

using namespace std;
using namespace cv;

Detect::Detect(Mat& image) 
{
    // Load cascade file (.xml file)
    CascadeClassifier cascade;
    cascade.load("model/haarcascade_frontalface_alt.xml");

    if (cascade.empty())
    {
        cerr << "Error loading model file" << endl;
    }
 
    // Face detection
    vector<Rect> faces;
    cascade.detectMultiScale(image, faces, 1.1, 2, 0|CASCADE_SCALE_IMAGE, Size(30, 30));

    int scale = 1.2;

    // Draw rects on the detected faces
    for(unsigned i = 0; i < faces.size(); i++)
    {
        Scalar color = Scalar(255, 0, 255);
        rectangle(
            image, 
            Point(cvRound(faces[i].x * scale), cvRound(faces[i].y * scale)), 
            Point(cvRound((faces[i].x + faces[i].width - 1) * scale), cvRound((faces[i].y + faces[i].height-1)*scale)), 
            color, 2, 2, 0);
    }
}

Detect::~Detect() {}
