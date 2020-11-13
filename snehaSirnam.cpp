

#include <QApplication>
#include <QVBoxLayout>
#include <QSlider>
#include <QSpinBox>
#include <QLabel>
#include <QDial>
#include <QLCDNumber>
#include <QRadioButton>
#include <QPushButton>
#include <QProgressBar>
#include <QtGui>
#include "globj.h"
#include <QGridLayout>

int main(int argc, char *argv[])

	{
		QApplication app(argc, argv);
		QWidget *window = new QWidget;
		GLobj *globj = new GLobj();
        	QLabel *labelVol = new QLabel;
		QLabel *labelBass =new QLabel;
		QLabel *labelTrebel =new QLabel;
		QLabel *labelMod = new QLabel;
		QDial *dial = new QDial;
		QLCDNumber *lcd = new QLCDNumber;
		QLCDNumber *lcdTrebel = new QLCDNumber;
		QLCDNumber *lcdStation = new QLCDNumber;
		QLCDNumber *lcdVol = new QLCDNumber;
		QRadioButton *rad1 = new QRadioButton;
		QRadioButton *rad2 = new QRadioButton;
		QPushButton *saveBtn = new QPushButton;
		QPushButton *loadBtn = new QPushButton;
		QPushButton *exitBtn = new QPushButton;
		QSpinBox *spinBox = new QSpinBox;
		QSlider *slider = new QSlider(Qt::Vertical);
		QSlider *sliderTrebel = new QSlider(Qt::Horizontal);
		window->setWindowTitle("Software Radio");
		spinBox->setRange(0, 100);
		slider->setRange(0, 100);
		slider->setMaximumSize(60,120);
		slider->setValue(80);
		sliderTrebel->setRange(0, 100);
		sliderTrebel->setMaximumSize(60,120);
		sliderTrebel->setValue(50);
		dial->setMinimum(0.0);
		dial->setMaximum(99.9);
		//connection established between spinBox(Volume) and progressBar
        	QObject::connect(spinBox,SIGNAL(valueChanged(int)), lcdVol,SLOT(display(int)));
		//connection established between bass and LCD display
		QObject::connect(slider, SIGNAL(valueChanged(int)),lcd , SLOT(display(int)));
		//connection established between Trebel and LCD display
		QObject::connect(sliderTrebel, SIGNAL(valueChanged(int)),lcdTrebel , SLOT(display(int)));
		//clicking the exit button closes the window
		QObject::connect(exitBtn, SIGNAL(clicked()),window , SLOT(close()));
		//SpinBox for Volume
		spinBox->setValue(35);
		spinBox->setMaximumSize(60,30);
		//SaveBtn to save songs
   		saveBtn->setStyleSheet("color : white;background-color : blue");
		//LoadBtn to load the songs 
		loadBtn->setStyleSheet("color : white;background-color : blue");
		loadBtn->setMaximumSize(90,30);
		//To exit
		exitBtn->setStyleSheet("color : white;background-color : blue");
		exitBtn->setMaximumSize(90,30);
		//Dial to adjust station 
		dial->setStyleSheet("background-color:GoldenRod");
		dial->setNotchesVisible(true);
		//Display for Bass
		lcd->setStyleSheet("background-color:Black");
		lcd->setMaximumSize(90,30);
		lcd->display(80);
		//Display for Trebel
		lcdTrebel->setStyleSheet("background-color:Black");
		lcdTrebel->setMaximumSize(90,30);
		lcdTrebel->display(50);
		//Display for lcdStation
		lcdStation->setStyleSheet("background-color:Black");
		lcdStation->setMaximumSize(90,30);
		lcdStation->display(98.5);
		//Displays how much volume is set
		lcdVol->setStyleSheet("background-color:Black");
		lcdVol->setMaximumSize(90,30);
		QGridLayout *grid = new QGridLayout;
		labelMod->setText("Modulation");
		labelVol->setText("Volume");
		labelBass->setText("Bass");
		labelBass->setStyleSheet("padding:0 0 0 50px");
		labelTrebel->setText("Trebel");
		labelTrebel->setStyleSheet("padding:0 0 0 20px");
		rad1->setText("AM");
		rad2->setText("FM");
		rad2->setChecked(true);
		saveBtn->setText("Save Song");
		loadBtn->setText("Load Song");
		exitBtn->setText("EXIT");
		grid->addWidget(labelMod,1,0,1,1);
		grid->addWidget(rad1,2,0,1,1);
		grid->addWidget(rad2,2,1,1,1);
		grid->addWidget(dial,3,0,1,1);
		grid->addWidget(lcdStation,3,1,1,1);
		grid->addWidget(saveBtn,7,3,1,1);
		grid->addWidget(loadBtn,7,5,1,1);
		grid->addWidget(labelVol,4,0,1,5);
		grid->addWidget(labelBass,4,1,2,1);
		grid->addWidget(labelTrebel,4,2,2,2);
		grid->addWidget(spinBox,5,0,1,1);
		grid->addWidget(slider,5,1,1,1);
		grid->addWidget(sliderTrebel,5,2,1,1);
		grid->addWidget(lcdVol,6,0,1,1);
		grid->addWidget(lcd,6,1,1,1);
		grid->addWidget(lcdTrebel,6,2,1,1);
		grid->addWidget(exitBtn,7,4,1,1);
		grid->addWidget(globj,0,3,6,4);
		window->resize(500,500);
		window->setLayout(grid);
		window->show();
		

		return app.exec();

      }
