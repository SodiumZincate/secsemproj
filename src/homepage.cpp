#include "appUI.h"
#include "db.h"

void initDashboard(StackedWidgets *App, QWidget* window){
	window->setWindowTitle("Dashboard");

	QWidget *textbox_widget = new QWidget(window);
	textbox_widget->setFixedSize(app_width*3/2, app_height*3/2);
	// textbox_widget->setStyleSheet("QWidget{background-color:red}");
	QVBoxLayout *textbox_widget_layout = new QVBoxLayout(textbox_widget);
	//textbox_widget_layout->setAlignment(Qt::AlignCenter); // Center align the contents

    appText *maintext = new appText();
    maintext->init(window,"League Manager");
    QLabel *mainLabel= maintext->getWidget_label();
	mainLabel->setMargin(0);
	mainLabel->setFixedHeight(app_height/8);
	// mainLabel->setStyleSheet("QLabel{background-color:blue}");
    mainLabel->setAlignment(Qt::AlignTop | Qt::AlignHCenter);

    //League Text
    appText *leaguetext = new appText();
    leaguetext->init(window,"Your Leagues",default_font_size-3);
    QLabel *leagueLabel_widget= leaguetext->getWidget_label();
    leagueLabel_widget->setMargin(10);
    leagueLabel_widget->setAlignment(Qt::AlignTop | Qt::AlignCenter);

	//Back Button
    appButton *backButton= new appButton();
    backButton->init(window,"BACK",default_font_size-2);
    QPushButton *backButton_widget = backButton->getWidget_button();
    backButton_widget->setFixedSize(app_width/8,app_height/12);
	// backButton_widget->setStyleSheet("QPushButton{background-color:green}");
	
    //Username text
 	/*appText *usernameText = new appText();
    usernameText ->init(window,"Username",default_font_size-3);
    QLabel *usernameText_widget=usernameText->getWidget_label();
	usernameText_widget->setFixedHeight(app_height/4);
    usernameText_widget->setAlignment(Qt::AlignRight);*/


    appText *usernameText = new appText();
    usernameText ->init(window, "username" ,default_font_size-3);
    QLabel *usernameText_widget=usernameText->getWidget_label();
    usernameText_widget->setAlignment(Qt::AlignRight);
    usernameText_widget->setFixedHeight(app_height/4);


    //League button 1
    appButton *button1 =new appButton();
    button1->init(window,"League 1",default_font_size+6);
    QPushButton *button1_widget=button1->getWidget_button();
    button1_widget->setCursor(Qt::PointingHandCursor);
	button1_widget->setStyleSheet("QPushButton{text-decoration:underline;border:none;}");
  
    //League button 2
    appButton *button2= new appButton();
    button2->init(window,"League 2",default_font_size+6);
    QPushButton *button2_widget=button2->getWidget_button();
	button2_widget->setCursor(Qt::PointingHandCursor);
	button2_widget->setStyleSheet("QPushButton{text-decoration:underline;border:none;}");

    appButton *leagueButton =new appButton();
    leagueButton->init(window,"Add league",default_font_size+10);
    QPushButton *leagueButton_widget=leagueButton->getWidget_button();
    leagueButton_widget->setFixedSize(app_width/4,app_width/14);

	//NavBar
    QWidget *NavBar = new QWidget(window);
    QHBoxLayout *NavBar_layout = new QHBoxLayout(NavBar);
    NavBar->setFixedHeight(app_height/6);
    NavBar_layout->setContentsMargins(0, 0, 0, 0);
	//NavBar->setStyleSheet("QWidget{background-color:yellow}");

	//Backbutton Container
    QWidget *backButton_container = new QWidget(window);
    QHBoxLayout *backButton_container_layout = new QHBoxLayout(backButton_container);
    backButton_container->setFixedHeight(app_height/6);
    backButton_container_layout->setAlignment(Qt::AlignLeft);
    backButton_container_layout->setContentsMargins(0, 0, 0, 0);

    backButton_container_layout->addWidget(backButton_widget);
    // backButton_container_layout->addWidget(usernameText_widget, 0, Qt::AlignRight);

	NavBar_layout->addWidget(backButton_container);
	NavBar_layout->addWidget(usernameText_widget);

    //Container for league buttons
    QWidget *button_container = new QWidget(window);
    QVBoxLayout *button_container_layout = new QVBoxLayout(button_container);
    button_container_layout->setAlignment(Qt::AlignCenter);
    button_container_layout->setContentsMargins(0, app_height / 10, 0, 0);

    button_container_layout->addWidget(leagueLabel_widget);
    button_container_layout->addWidget(button1_widget);
    button_container_layout->addWidget(button2_widget);

    //Container for League button
    QWidget *leagueButton_container = new QWidget(window);
    QVBoxLayout *leagueButton_container_layout = new QVBoxLayout(leagueButton_container);
    leagueButton_container_layout->setAlignment(Qt::AlignCenter);
    leagueButton_container_layout->setContentsMargins(0, app_height /5, 0, 0);

    leagueButton_container_layout->addWidget(leagueButton_widget);

    textbox_widget_layout->addWidget(NavBar);
    textbox_widget_layout->addWidget(mainLabel);
    textbox_widget_layout->addWidget(button_container);
    textbox_widget_layout->addWidget(leagueButton_container);

	QObject::connect(backButton_widget, &QPushButton::clicked, App, &StackedWidgets::changeWindow_backward);
	QObject::connect(leagueButton_widget, &QPushButton::clicked, App, &StackedWidgets::changeWindow_forward);

	QVBoxLayout *main_layout = new QVBoxLayout(window);
    main_layout->addWidget(textbox_widget);
    main_layout->setAlignment(Qt::AlignCenter);
    window->setLayout(main_layout);
}
