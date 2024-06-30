#include <QtWidgets/QApplication>
#include <QtGui/QScreen>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QHBoxLayout>
#include "LoginUI.h"

int app_height = 0;
int app_width = 0;
int screenWidth;
int screenHeight;

#ifdef _WIN32
    int default_font_size = 26;
#elif defined(__linux__)
    int default_font_size = 34;
#endif

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QScreen *screen = QGuiApplication::primaryScreen();
	QSize screenSize = screen->size();

	screenWidth = screenSize.width();
    screenHeight = screenSize.height();

    app_width = screenWidth / 2;
    app_height = screenHeight / 2;

	QWidget mainWidget;
	QWidget loginWidget, registerWidget;
	initLogin(&loginWidget);
	
	QStackedWidget app_windows;

	app_windows.addWidget(&loginWidget);
	app_windows.setCurrentWidget(&loginWidget);
	
	QHBoxLayout *app_layout = new QHBoxLayout(&mainWidget);
	app_layout->addWidget(&app_windows);

	mainWidget.setLayout(app_layout);
	mainWidget.resize(app_width, app_height);
	mainWidget.show();

    return app.exec();
}