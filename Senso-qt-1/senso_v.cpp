/*
Qt main Starter
W.Spieﬂ 16.03.2017
Random numbers. Origin
*/
#include "senso_v.h"
#include <QTimer>
#include <QTime>
#include <QDir>

// Konstruktor
Senso_v::Senso_v(QWidget *parent)
	: QMainWindow(parent)
{

	setWindowIcon(QIcon("./icon/Icon1.ico"));
	QString s = QDir::currentPath();  // Get current path
	ui.setupUi(this);
	// coonect aus 	ui_senso_v.h ¸berschreiben
   	connect(ui.pushButton,SIGNAL(clicked()),qApp ,SLOT(quit()) );
	// siehe ui_senso_v.h dort bereits connectec()
	//connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(ExitKlicked(void)));
	//connect(ui.pushButton_3, SIGNAL(clicked()), this, SLOT(rotKlicked())  );  // rot
	//connect(ui.pushButton_4, SIGNAL(clicked()), &w , SLOT(gelbKlicked()) );  // gelb
	QString str = "Intro";
	ui.textEdit->setText(str);
	// Intro();
	/* Buttons einf‰rben
	ui.pushButton_3->setStyleSheet("background-color: red");
	ui.pushButton_4->setStyleSheet("background-color: yellow");
	ui.pushButton_5->setStyleSheet("background-color: green");
	ui.pushButton_6->setStyleSheet("background-color: blue");
	*/
	// intro mit monoflop ...
	//QTimer::singleShot(1000, this, SLOT(Intro()));
	// alternativ mit timer
	QFont f1 = ui.textEdit_3->font();
	QFontMetrics fm(f1);
	f1.setPointSize(65);
	ui.textEdit_3->setFont(f1);
	//ui.textEdit->setReadOnly(true);
	//ui.textEdit_2->setReadOnly(true);
	ui.textEdit->setEnabled(false);
	ui.textEdit_2->setEnabled(false);
	ui.textEdit_3->setEnabled(false);
	ui.textEdit->hide();   // hide Debug
	ui.textEdit_2->hide(); // hide Status
	ui.label->hide();
	ui.label_2->hide();
	bo_Play=FALSE;  // playing is disabled
	bo_Show=FALSE;   // queue is showing
	bo_Intro = FALSE;
	SetIntro();		// fill queue with Intro data
	ShowTimer = new QTimer(this);  // set showtimer
	connect(ShowTimer, SIGNAL(timeout()), this, SLOT(showQueue()));
	ShowTimer->start(SHOWTIME);   
}

void Senso_v::singleShotFunc(void) {
QString str;
counter++;
str = QString::number(counter);
ui.textEdit->setText(str);
};

Senso_v::~Senso_v()
{
;
}

// run=Play
void Senso_v::runKlicked(void) {

	// background-color: rgb(255, 255, 255)
	// reset all buttons
	ui.pushButton_2->setStyleSheet("");
	ui.pushButton_3->setStyleSheet("");
	ui.pushButton_4->setStyleSheet("");
	ui.pushButton_5->setStyleSheet("");
	ui.pushButton_6->setStyleSheet("");
	play();
}

void Senso_v::ExitKlicked(void){
	close();
}

int Senso_v::play(void) {
	int myRandomNumber;
	myRandomNumber = getRandom();
	bo_Play = TRUE;
	bo_Show = TRUE;		// Show Queue enabled
	Queue.setAtIndex(0);// reset index to position 0
	return TRUE;
}

void Senso_v::helpKlicked(void) {
	//QString str = "help";
	//QString col_str = "background - color: yellow";
	//	ui.pushButton_4->setStyleSheet("background-color: yellow");
	//ui.pushButton_4->setStyleSheet(col_str);
	//ui.textEdit->setText(str);
	ui.textEdit->show();   // show Debug
	ui.textEdit_2->show(); // show Status
	ui.label->show();
	ui.label_2->show();
}

void Senso_v::gelbKlicked(void){
	QString str = "gelb";
	QString col_str = "background - color: yellow";
	ui.pushButton_4->setStyleSheet("background-color: yellow");
	//ui.pushButton_4->setStyleSheet(col_str);
	ui.textEdit->setText(str);
	repaint();
	_beep(BT[YEL], SoundLength);
	gelbUnKlick();
	if (bo_Play == TRUE && bo_Show == FALSE) {
		bo_Hit=chkInput(YEL);
		if (bo_Hit == -1) bo_Play = FALSE;
		}
}

void Senso_v::gelbUnKlick(void) {
	QString str = "ungelb";
	QString col_str = "background - color: yellow";
	//ui.pushButton_4->setStyleSheet("background-color: yellow");
	//ui.pushButton_4->setStyleSheet(col_str);
	ui.textEdit->setText(str);
	ui.pushButton_4->setStyleSheet("");

}
              
void Senso_v::rotKlicked(void) {
	QString str = "rot";
	ui.pushButton_3->setStyleSheet("background-color: red");
	ui.textEdit->setText(str);
	repaint();
	_beep(BT[RED], SoundLength);
	rotUnKlick();
	if (bo_Play == TRUE && bo_Show ==FALSE) {
		bo_Hit = chkInput(RED);
		if (bo_Hit == -1) bo_Play = FALSE;
		}

}

void Senso_v::rotUnKlick(void){
	QString str = "unrot";
	// ui.pushButton_3->setStyleSheet("background-color: red");
	ui.textEdit->setText(str);
	ui.pushButton_3->setStyleSheet("");
	repaint();
}

void Senso_v::gruenKlicked(void) {
	QString str = "gruen";
	ui.pushButton_5->setStyleSheet("background-color: green");
	ui.textEdit->setText(str);
	repaint();
	_beep(BT[GRE], SoundLength);
	gruenUnKlick();
	if (bo_Play == TRUE && bo_Show == FALSE) {
		bo_Hit = chkInput(GRE);
		if (bo_Hit == -1) bo_Play = FALSE;
		}
}

void Senso_v::gruenUnKlick(void) {
	QString str = "ungruen";
	// ui.pushButton_5->setStyleSheet("background-color: green");
	ui.textEdit->setText(str);
	ui.pushButton_5->setStyleSheet("");
	repaint();
}

void Senso_v::blauKlicked(void) {
	QString str = "blau";
	ui.pushButton_6->setStyleSheet("background-color: blue");
	ui.textEdit->setText(str);
	repaint();
	_beep(BT[BLU], SoundLength);
	blauUnKlick();
	if (bo_Play == TRUE && bo_Show == FALSE) {
		bo_Hit = chkInput(BLU);
		if (bo_Hit == -1) bo_Play = FALSE;
		}
}

void Senso_v::blauUnKlick(void) {
	QString str = "unblau";
	//ui.pushButton_6->setStyleSheet("background-color: blue");
	ui.textEdit->setText(str);
	ui.pushButton_6->setStyleSheet("");
	repaint();
}

void Senso_v::SetIntro(void) {
/*
_beep(0, 1000);
while (CTU[i]) {
	printf("%c ", CTU[i]);
	_beep(BT[i], 800);
	pElement = Queue.getNext();
	i++;
	}
*/
// Fifo Bef¸llen
// Load Intro into Queue
Queue.add(1);
Queue.add(2);
Queue.add(3);
Queue.add(4);
// Fifo Auslesen
Queue.setAtIndex(0); // reset to begin of queue 
bo_Show = TRUE;  // Show Queue enabled
bo_Intro = TRUE; // Intro enabled
//bo_Play = TRUE;  // Play 
return ;
}

int Senso_v::getRandom(void) {
	/*
	// min + rand() % ( max - min );
	// rand() % 6 + min  -->  1 ...6
	//  rand() % (iBis-iVon +1) + iVon

	srand(42); // seed
	for (int i = 0; i < 5; i++) {
	int x = 100 + (rand() % 101);  // 100 ...200
	std::cout << x << std::endl;
	}
	std::cout << "=====" << std::endl;
	srand(42);   // seed
	for (int i = 0; i < 5; i++) {
	int x = 100 + (rand() % 101);
	std::cout << x << std::endl;
	}
	*/
	//srand((unsigned int)time(NULL));  // seed
	int iVon = 1;
	int iBis = 4;
	int MyRandomNumber;
	/*
	// 5 Zufallszahlen erzeugen
	for (int iCount = 0; iCount < 20; iCount++) {
	printf("%i ", rand() % (iBis - iVon + 1) + iVon);
	} // end of for
	*/
	MyRandomNumber= rand() % (iBis - iVon + 1) + iVon;
	Queue.add(MyRandomNumber);
	//return (rand() % (iBis - iVon + 1) + iVon);
	return(MyRandomNumber);
}


/* Compare Input with Queue @ current index
 return : 
         FALSE=0   Queue is empty
          -1       Compaire false
          +1       Compair  true
Compairing Queue and User Input Sequence
*/
int Senso_v::chkInput(int data) {
Item *pElement;
QString str; 

pElement = Queue.getNext(); // read next Element of Queue
if (pElement == NULL) return FALSE;
if (pElement->data == data) {
	// Beep(BT[decode(key)], 800);
	ui.textEdit->setText("O.K.");
	repaint();

	if (Queue.last() == TRUE) {
		ui.textEdit->setText("Complete Sequence Equal");
		ui.textEdit_2->setText("");  // Delete Debugging
		WinCounter++;
		str = QString::number(WinCounter);
		str = "  " + str;
		ui.textEdit_3->setText(str);  // Delete Debugging
		repaint();
		Fanfare();
		delay(1);
		getRandom();
		Queue.setAtIndex(0);
		bo_Show = TRUE;
		repaint();
		}
	return +1;
	}
// wrong user input
ui.textEdit_3->setText(" X");
ui.textEdit->setText("not equal");
ui.pushButton_2->setStyleSheet("background-color: grey");
repaint();
Panther();   // unhappy
bo_Play = FALSE;
return -1;
}
// ShowQueue is controlling the Intro and play sequences via bo_Intro, bo_play, bo_show 
int Senso_v::showQueue(void){
Item *Data;
if (bo_Show == FALSE) return FALSE;
// Fifo Auslesen
Data = Queue.getNext();  // index=index +1
if (Data == NULL){
	bo_Show = FALSE;  // Queue is read out !!!

	if (bo_Intro == TRUE) { // Intro-Mode Actice?
		bo_Intro = FALSE;	// ... then set Intro off
		Queue.reset();      // erase Queue
		ui.textEdit->setText("hit Blei to start");
		ui.pushButton_2->setStyleSheet("background-color: grey");
		ui.pushButton->setStyleSheet("background-color: grey");
		ui.pushButton_7->setStyleSheet("background-color: grey");
		return FALSE;
		}

	if (bo_Play == TRUE) { // Playmode active ? 
		Queue.setAtIndex(0);   // ... then set to first Queue to compair user's input 
		ui.textEdit->setText("make your decision");
		repaint();
	return FALSE;
	}
}
QString s;
s = QString::number(Data->data);
//ui.textEdit_2->append(s);
ui.textEdit_2->insertPlainText(s);
repaint();
if (Data->data == YEL) {
	gelbKlicked();
	// repaint();
	// _beep(BT[Data->data], SoundLength);
	// _sleep(sleep);
	//gelbUnKlick();
	//repaint();
	}
else if (Data->data == GRE) {
	gruenKlicked();
	// repaint();
	// _beep(BT[2], SoundLength);
	// _sleep(sleep);
	//gruenUnKlick();
	//repaint();
	}
else if (Data->data == RED) {
	rotKlicked();
	// repaint();
	// _beep(BT[3], SoundLength);
	//_sleep(sleep);
	//rotUnKlick();
	//repaint();
	}
else if (Data->data == BLU) {
	blauKlicked();
	// repaint();
	// _beep(BT[4], SoundLength);
	//_sleep(sleep);
	//blauUnKlick();
	//repaint();
	}
return TRUE;
}


void Senso_v::delay(int sec)
{
	QTime dieTime = QTime::currentTime().addSecs(sec);
	while (QTime::currentTime() < dieTime)
		QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void Senso_v::Fanfare(void) {

	int speed = 500; 
	_beep(261, speed / 2);
	_beep(261, speed / 2);
	_beep(293, speed);
	_beep(261, speed);
	_beep(349, speed);
	_beep(329, speed);
}

void Senso_v::Panther(void) {
#define c 261
#define d 294
#define e 329
#define f 349
#define g 391
#define gS 415
#define a 440
#define aS 455
#define b 466
#define cH 523
#define cSH 554
#define dH 587
#define dSH 622
#define eH 659
#define fH 698
#define fSH 740
#define gH 784
#define gSH 830
#define aH 880
	_beep(a, 500);
	_beep(a, 500);
	_beep(a, 500);
	_beep(f, 350);
	_beep(cH, 150);
	_beep(a, 500);
	_beep(f, 350);
	_beep(cH, 150);
	_beep(a, 650);
	return;
	//delay_ms(150);
	//end of first bit

	_beep(eH, 500);
	_beep(eH, 500);
	_beep(eH, 500);
	_beep(fH, 350);
	_beep(cH, 150);
	_beep(gS, 500);
	_beep(f, 350);
	_beep(cH, 150);
	_beep(a, 650);

	//delay_ms(150);
	//end of second bit...

	_beep(aH, 500);
	_beep(a, 300);
	_beep(a, 150);
	_beep(aH, 400);
	_beep(gSH, 200);
	_beep(gH, 200);
	_beep(fSH, 125);
	_beep(fH, 125);
	_beep(fSH, 250);

	//delay_ms(250);

	_beep(aS, 250);
	_beep(dSH, 400);
	_beep(dH, 200);
	_beep(cSH, 200);
	_beep(cH, 125);
	_beep(b, 125);
	_beep(cH, 250);

	//delay_ms(250);

	_beep(f, 125);
	_beep(gS, 500);
	_beep(f, 375);
	_beep(a, 125);
	_beep(cH, 500);
	_beep(a, 375);
	_beep(cH, 125);
	_beep(eH, 650);

	//end of third bit... (Though it doesn't play well)
	//let's repeat it

	_beep(aH, 500);
	_beep(a, 300);
	_beep(a, 150);
	_beep(aH, 400);
	_beep(gSH, 200);
	_beep(gH, 200);
	_beep(fSH, 125);
	_beep(fH, 125);
	_beep(fSH, 250);

	//delay_ms(250);

	_beep(aS, 250);
	_beep(dSH, 400);
	_beep(dH, 200);
	_beep(cSH, 200);
	_beep(cH, 125);
	_beep(b, 125);
	_beep(cH, 250);

	//delay_ms(250);

	_beep(f, 250);
	_beep(gS, 500);
	_beep(f, 375);
	_beep(cH, 125);
	_beep(a, 500);
	_beep(f, 375);
	_beep(cH, 125);
	_beep(a, 650);
	//end of the song
}

