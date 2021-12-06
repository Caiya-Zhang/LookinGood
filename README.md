# Lookin' Good #

### Description ###
Lookin' Good is a photo processing application, being able to recognize faces, swaping faces, adjusting color tone, and smoothing noisy points. 

The program will be realized as a self-service shooting device allows tourists to edit or beautify photos with interesting special effects in the parks, playgrounds, and scenic spots. 

Once hardware like cameras and Raspberry Pi kits available, this program will also be able to run in a Raspberry Pi environment. 


### Environment ###
A Linux or Raspberry Pi environment is needed tocompile and run this program.  Also, it's better to install C++ compiler tools, OpenCV, and Qt 5 in advance. 


#### OpenCV setup instructions (Ubuntu 20.04) ####
*   Step 1. Update the Ubuntu System Package
    ```
    sudo apt-get update && sudo apt-get upgrade
    ```

*   Step 2. Install Required tools and packages
    ```
    sudo apt install software-properties-common
    sudo apt install apt-file
    sudo apt-get install build-essential cmake git libgtk2.0-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev
    sudo apt-get install python3.5-dev python3-numpy libtbb2 libtbb-dev
    sudo apt-get install libjpeg-dev libpng-dev libtiff5-dev libjasper-dev libdc1394-22-dev libeigen3-dev libtheora-dev libvorbis-dev libxvidcore-dev libx264-dev sphinx-common    libtbb-dev yasm libfaac-dev libopencore-amrnb-dev libopencore-amrwb-dev libopenexr-dev libgstreamer-plugins-base1.0-dev libavutil-dev libavfilter-dev libavresample-dev
    ```

*   Step 3. Download OpenCV Sources using git
    ```
    sudo -s
    cd /opt
    git clone https://github.com/Itseez/opencv.git
    git clone https://github.com/Itseez/opencv_contrib.git
    ```

*   Step 4. Build & Install OpenCV
    ```
    cd opencv
    mkdir release
    cd release
    cmake -D BUILD_TIFF=ON -D WITH_CUDA=OFF -D ENABLE_AVX=OFF -D WITH_OPENGL=OFF -D WITH_OPENCL=OFF -D WITH_IPP=OFF -D WITH_TBB=ON -D BUILD_TBB=ON -D WITH_EIGEN=OFF -D WITH_V4L=OFF -D WITH_VTK=OFF -D BUILD_TESTS=OFF -D BUILD_PERF_TESTS=OFF -D OPENCV_GENERATE_PKGCONFIG=ON -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=/usr/local -D OPENCV_EXTRA_MODULES_PATH=/opt/opencv_contrib/modules /opt/opencv/
    make -j4
    make install
    ldconfig
    exit
    cd ~
    ```

*   Step 5. Check OpenCV version installed
    ```
    pkg-config --modversion opencv
    ```

*   Step 6. Compile & Run a Test Program 
    ```
    mkdir opencv_test
    cd opencv_test
    gedit test.cpp
    ```

*   Step7. Copy & Paste the code posted in Step 6
    ```
    g++ test.cpp -o testoutput -std=c++11 
    pkg-config --cflags --libs opencv
    ./testoutput
    ```


### Compile and Run ###
*   #1: 'qmake LookinGood.pro'
    #2: 'make'                    (compile the program)
    #3: './LookinGood'            (run the program)

### Usage ###

![](C:\UWO\Academics\thirdYear\CS3307\group asn\gui.jpg)

#### Steps ####
1. Build and launch using the instructions above;
2. Click "upload" to upload a photo;
3. Click on a feature button to start;
4. Click "reset" to reset a new photo;

#### Features ####
* Detect: recognize a clear frontal face
* Swap: swap two faces
* Flip: horizontal flip the image
* Rotate: rotate the image 90° clockwise
* Zoom in: zoom in the image by selecting magnification
* Brighter: brighten the image
* Filter: smooth the image mainly by bilateral filtering and Gaussian Blur


### Development  ###
* Modulization
* Writing test cases
* Code review
* Other guidelines


### Users ###
* Repo owner or admin
* Other community or team contact
* Markers


### Contributors ###
* Western University
* 2021 fall, CS3307A
* Group #18: Caiya Zhang, Haohan Liu, Tianyang Yang, Yifei Han, Yuzhuo Lei


### References ###
* [Learn OpenCV](http://techawarey.com/programming/install-opencv-c-c-in-ubuntu-18-04-lts-step-by-step-guide/)
* [Learn Markdown](https://bitbucket.org/tutorials/markdowndemo)