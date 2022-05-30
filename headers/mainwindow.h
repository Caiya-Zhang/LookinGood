/*! \Author		    Group 18 (Caiya Zhang, Tianyang Yang, Yuzhuo Lei, Yifei Han, Haohan Liu)
	\Name		    mainwindow.h
    \Description    Header file for MainWindow class.
	\Date		    Oct 2021
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>

#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include <QtWidgets>

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);

private:
    QDesktopWidget desktopWidget;
    int desktopWidth;
    int desktopHeight;

    int zoomRec;

    int gridRowCount;
    int gridColCount;

    bool imageUploaded;

    QGridLayout *grid;
    QLabel *imageDisplay;

    cv::Mat originalImg;
    cv::Mat firstImage;
    cv::Mat secondImage;

    void createButtonGroup();
    void createImageDisplay();

    void handleResetButton();
    void handleUploadButton();
    void handleDetectButton();
    void handleFlipButton();
    void handleRotateButton();
    void handleFilterButton();
    void handleZoomInButton();
    void handleBrightButton();
};

#endif // MAINWINDOW_H