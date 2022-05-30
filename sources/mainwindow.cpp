/*! \Author		    Group 18 (Caiya Zhang, Tianyang Yang, Yuzhuo Lei, Yifei Han, Haohan Liu)
	\Name		    mainwindow.cpp
    \Description    Source file for MainWindow class.
	\Date		    Oct 2021
*/

#include "../headers/mainwindow.h"
#include "../headers/detect.h"
#include "../headers/flip.h"
#include "../headers/rotate.h"
#include "../headers/filter.h"
#include "../headers/zoom.h"
#include "../headers/bright.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    gridRowCount = 0;
    gridColCount = 0;

    zoomRec = 600;

    imageUploaded = false;

    // Initialize grid view
    grid = new QGridLayout(this);

    // Set main window size depending on the current display
    desktopWidth = desktopWidget.width() * 0.5;
    desktopHeight = desktopWidget.height() * 0.5;
    this->setFixedSize(desktopWidth, desktopHeight);

    // Add functional components
    createButtonGroup();
    createImageDisplay();

    setLayout(grid);
}

void MainWindow::createButtonGroup()
{
    auto *uploadBtn = new QPushButton("Upload", this);
    grid->addWidget(uploadBtn, gridRowCount, gridColCount, 1, 1);

    auto *detectBtn = new QPushButton("Detect", this);
    grid->addWidget(detectBtn, gridRowCount, ++gridColCount, 1, 1);

    // auto *swapBtn = new QPushButton("Swap Face", this);
    // grid->addWidget(swapBtn, gridRowCount, ++gridColCount, 1, 1);

    auto *flipBtn = new QPushButton("Flip", this);
    grid->addWidget(flipBtn, gridRowCount, ++gridColCount, 1, 1);

    auto *rotateBtn = new QPushButton("Rotate", this);
    grid->addWidget(rotateBtn, gridRowCount, ++gridColCount, 1, 1);

    auto *filterBtn = new QPushButton("Filter", this);
    grid->addWidget(filterBtn, gridRowCount, ++gridColCount, 1, 1);

    auto *zoomInBtn = new QPushButton("Zoom In", this);
    grid->addWidget(zoomInBtn, gridRowCount, ++gridColCount, 1, 1);

    auto *BrightBtn = new QPushButton("Brighter", this);
    grid->addWidget(BrightBtn, gridRowCount, ++gridColCount, 1, 1);

    auto *resetBtn = new QPushButton("Reset", this);
    grid->addWidget(resetBtn, gridRowCount, ++gridColCount, 1, 1);

    // Connect button signals to appropriate slots
    connect(resetBtn, &QPushButton::released, this, &MainWindow::handleResetButton);
    connect(uploadBtn, &QPushButton::released, this, &MainWindow::handleUploadButton);
    connect(detectBtn, &QPushButton::released, this, &MainWindow::handleDetectButton);
    // swap btn handler here
    connect(flipBtn, &QPushButton::released, this, &MainWindow::handleFlipButton);
    connect(rotateBtn, &QPushButton::released, this, &MainWindow::handleRotateButton);
    connect(filterBtn, &QPushButton::released, this, &MainWindow::handleFilterButton);
    connect(zoomInBtn, &QPushButton::released, this, &MainWindow::handleZoomInButton);
    connect(BrightBtn, &QPushButton::released, this, &MainWindow::handleBrightButton);
}

void MainWindow::createImageDisplay()
{
    imageDisplay = new QLabel(this);

    imageDisplay->setFixedHeight(desktopWidget.height() * 0.45);
    imageDisplay->setAlignment(Qt::AlignCenter | Qt::AlignVCenter);

    grid->addWidget(imageDisplay, ++gridRowCount, 0, 1, gridColCount + 1);

    // Default image
    cv::Mat defaultImg = cv::imread("assets/default.png", cv::IMREAD_COLOR);
    imageDisplay->setPixmap(QPixmap::fromImage(QImage(defaultImg.data, defaultImg.cols, defaultImg.rows, QImage::Format_RGB888).rgbSwapped()));
}

void MainWindow::handleResetButton()
{
    if (!imageUploaded)
        return;

    originalImg.copyTo(firstImage);
    imageDisplay->setPixmap(QPixmap::fromImage(QImage(firstImage.data, firstImage.cols, firstImage.rows, QImage::Format_RGB888).rgbSwapped()));
}

void MainWindow::handleUploadButton()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Choose"), "", tr("Images (*.png *.jpg * .jpeg * .bmp)"));

    if (QString::compare(filename, QString()) != 0)
    {
        firstImage = cv::imread(filename.toStdString(), cv::IMREAD_COLOR);

        // Error handling
        if (firstImage.empty())
        {
            cerr << "Error loading image" << endl;
            return;
        }

        imageUploaded = true;
        firstImage.copyTo(originalImg);

        imageDisplay->setPixmap(QPixmap::fromImage(QImage(firstImage.data, firstImage.cols, firstImage.rows, QImage::Format_RGB888).rgbSwapped()));
    }
}

void MainWindow::handleDetectButton()
{
    if (!imageUploaded)
        return;

    Detect detect(firstImage);
    imageDisplay->setPixmap(QPixmap::fromImage(QImage(firstImage.data, firstImage.cols, firstImage.rows, QImage::Format_RGB888).rgbSwapped()));
}

void MainWindow::handleFlipButton()
{
    if (!imageUploaded)
        return;

    Flip flip(firstImage);
    imageDisplay->setPixmap(QPixmap::fromImage(QImage(firstImage.data, firstImage.cols, firstImage.rows, QImage::Format_RGB888).rgbSwapped()));
}

void MainWindow::handleRotateButton()
{
    if (!imageUploaded)
        return;

    Rotate rotate(firstImage);
    imageDisplay->setPixmap(QPixmap::fromImage(QImage(firstImage.data, firstImage.cols, firstImage.rows, QImage::Format_RGB888).rgbSwapped()));
}

void MainWindow::handleFilterButton()
{
    if (!imageUploaded)
        return;

    Filter filter(firstImage);
    imageDisplay->setPixmap(QPixmap::fromImage(QImage(firstImage.data, firstImage.cols, firstImage.rows, QImage::Format_RGB888).rgbSwapped()));
}

void MainWindow::handleZoomInButton()
{
    if (!imageUploaded)
        return;

    Zoom zoom(firstImage, originalImg, zoomRec);
    imageDisplay->setPixmap(QPixmap::fromImage(QImage(firstImage.data, firstImage.cols, firstImage.rows, QImage::Format_RGB888).rgbSwapped()));
}

void MainWindow::handleBrightButton()
{
    if (!imageUploaded)
        return;

    Bright bright(firstImage);
    imageDisplay->setPixmap(QPixmap::fromImage(QImage(firstImage.data, firstImage.cols, firstImage.rows, QImage::Format_RGB888).rgbSwapped()));
}