#include "senso_v.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Senso_v w;
	w.show();

	return a.exec();
}
