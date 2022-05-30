/*! \Author		    Group 18 (Caiya Zhang, Tianyang Yang, Yuzhuo Lei, Yifei Han, Haohan Liu)
	\Name		    main.cpp
    \Description    Main function for the program.
	\Date		    Oct 2021
*/

#include "../headers/mainwindow.h"
#include <QApplication>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    
    MainWindow mainWindow;
    mainWindow.show();
    
    return app.exec();
}