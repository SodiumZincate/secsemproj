#include <QtWidgets/QApplication>
#include <QtGui/QScreen>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QHBoxLayout>
#include "appUI.h"
#include "loginpage.cpp"
#include "appUI.cpp"
#include "homepage.cpp"
#include "formpage.cpp"
#include "leaguepage.cpp"
#include "db.cpp"

int app_height = 0;
int app_width = 0;
int screenWidth;
int screenHeight;

int default_font_size;

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);
    QApplication::setStyle("Fusion");
    QScreen *screen = QGuiApplication::primaryScreen();
	QSize screenSize = screen->size();

	screenWidth = screenSize.width();
    screenHeight = screenSize.height();
	std::cout << screenWidth << std::endl;
	std::cout << screenHeight << std::endl;

	#ifdef _WIN32
        default_font_size = screenWidth/70;
	#elif defined(__linux__)
		default_font_size = screenWidth/75;
	#endif

    app_width = screenWidth / 2;
    app_height = screenHeight / 2;
	
	std::cout << screenWidth << std::endl;

	StackedWidgets stack1;
	QWidget registerApp;
	QWidget loginApp;
	QWidget dashboardApp;
	QWidget addleagueApp;
	QWidget showLeagueApp;

	// Initializa login and register pages
	initRegister(&stack1, &registerApp);
	initLogin(&stack1, &loginApp);
	initDashboard(&stack1, &dashboardApp);
	initAddLeague(&stack1, &addleagueApp);
	initShowLeague(&stack1, &showLeagueApp);

	stack1.addWidget(&registerApp);
	stack1.addWidget(&loginApp);
	stack1.addWidget(&dashboardApp);
	stack1.addWidget(&addleagueApp);
	stack1.addWidget(&showLeagueApp);

	// Set initial page to login page
	stack1.setCurrentIndex(4);

	// stack1.addtoLayout();
	stack1.mainWidget.setLayout(stack1.appLayout);

    appDesign *app_design = new appDesign();

	stack1.mainWidget.setWindowTitle("League Manager");
	stack1.mainWidget.setFont(QFont("Sans", default_font_size));
    stack1.mainWidget.resize(app_width*3/2, app_height*3/2);
    stack1.mainWidget.setPalette(app_design->app_palette);
    stack1.mainWidget.setStyleSheet(app_design->app_style_sheet);
    stack1.mainWidget.show();
    stack1.mainWidget.showMaximized();

    return app.exec();
}