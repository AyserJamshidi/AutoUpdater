#include "AutoUpdater.h"
#include <QtWidgets\QApplication>
#include <QtWidgets\qgraphicsview.h>
#include <QtWidgets\qlabel.h>
#include <qmovie.h>
#include <qbitmap.h>

#include <Windows.h>

//#include <qt_windows.h>

int main(int argc, char *argv[]) {
	// TODO 1 - Create debugger check thread and allow creation if OK
	QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
	QApplication::setStyle("Fusion");
	QApplication a(argc, argv);
	AutoUpdater w;
	w.show();
	return a.exec();
}