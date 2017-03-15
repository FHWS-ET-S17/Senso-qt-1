#ifndef SENSO_V_H
#define SENSO_V_H

#include <QtWidgets/QMainWindow>
//#include <QtWidgets>
#include "ui_senso_v.h"
#include "queue.h"
 
#ifndef TRUE
#define TRUE !0
#endif

#ifndef FALSE
#define FALSE 0
#endif

#define YEL 1
#define GRE 2
#define RED 3
#define BLU 4

class Senso_v : public QMainWindow
{
	Q_OBJECT

public:
	Senso_v(QWidget *parent = 0);
	~Senso_v();
	//int showQueue(void);
	int u;
	//http://stackoverflow.com/questions/8544665/qtimersingleshot-looks-for-the-specified-slot-in-the-given-objects-parent-c

private:
	FiFo Queue;					//  Lege neues Fifo-Liste an 
	Item Element, *pElement;	//  Elemente der Fifo-Liste
								//  0  1   2    3   4   5   
	char CTU[6] = { '0','Y','X','C','V', 0 };  // Code Table Upper Keys
	char CTL[6] = { '0','y','x','c','v', 0 };  // Code Table Lower Keys
	QString CTC[6] = { "", "background-color: yellow",
		"background-color: green",
		"background-color: red",
		"background-color: blue","" };  // Code Table Color
	int  BT[6] = { 0 ,200,300,400,500, 0 };  // Beep Table 
	int  SoundLength = 1000;
	int  Ok = 1000;							 // OK Beep
	int  OkLength = 500;					 // OK Beep
											 //int  SoundLength = 1000;
	int SLEEP = 1000;
	int SHOWTIME = 200;
	int counter = 0;
	int WinCounter = 0;

	int bo_Play;  // playing, started by user
	int bo_Show;  // queue is showing
	int bo_Intro; // Intro is showing
	int bo_Hit;   // input OK --> bo_HIT=TRUE;
	QTimer *ShowTimer;

	Ui::Senso_vClass ui;
	int seedRandom(void);
	int getRandom(void);
	void Fanfare(void);
	void Panther(void);

	int play(void);

	int chkInput(int data);		// Vergleich
	int decode(int);			// Eingabe und Tastenumrechnung
	void delay(int);

protected:
	// http://stackoverflow.com/questions/14356121/how-to-call-function-after-window-is-shown
	// void showEvent(QShowEvent *event);

private slots:  // slots müssen so definiert werden
	int showQueue(void);
	void blauKlicked(void);
	void gruenKlicked(void);
	void gelbKlicked(void);
	void rotKlicked(void);
	void blauUnKlick(void);
	void gruenUnKlick(void);
	void gelbUnKlick(void);
	void rotUnKlick(void);
	void ExitKlicked(void);
	void runKlicked(void);
	void singleShotFunc(void);
	void helpKlicked(void);
	void SetIntro(void);


};

#endif // SENSO_V_H
