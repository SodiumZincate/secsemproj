#include "appUI.h"
#include "db.h"
#include "logic.h"

void initNextMatch(
	StackedWidgets *App, 
	QWidget* window, 
	QString username,
	QString leaguename,
	League L,
	vector<Match> matchVector,
	QList<QIcon> iconList_1,
	QList<QIcon> iconList_2
){
    window->setWindowTitle("League Name");

    QWidget *main_widget = new QWidget(window);
    main_widget->setFixedSize(app_width*3/2, app_height*3/2);
    // main_widget->setStyleSheet("QWidget{background-color:blue}");
    QVBoxLayout *main_widget_layout = new QVBoxLayout(main_widget);
    main_widget_layout->setAlignment(Qt::AlignCenter); // Center align the contents

	//NavBar
    QWidget *NavBar = new QWidget(window);
    NavBar->setFixedSize(app_width*3/2, app_height/6);
	// NavBar->setStyleSheet("QWidget{background-color:yellow}");
    QHBoxLayout *NavBar_layout = new QHBoxLayout(NavBar);
    NavBar_layout->setAlignment(Qt::AlignTop);

	//Username text
    appText *usernameText = new appText();
    usernameText ->init(window, username ,default_font_size*0.9);
    QLabel *usernameText_widget=usernameText->getWidget_label();
    usernameText_widget->setAlignment(Qt::AlignRight);
    usernameText_widget->setFixedHeight(app_height/4);

	//League Name Text
	appText *leaguenameText = new appText();
    leaguenameText ->init(window, leaguename ,default_font_size*1.2);
    QLabel *leaguenameText_widget = leaguenameText->getWidget_label();
    leaguenameText_widget->setAlignment(Qt::AlignCenter);
    leaguenameText_widget->setFixedHeight(app_height/6);

	//Back Button
    appButton *backButton= new appButton();
    backButton->init(window,"BACK",default_font_size*0.9);
    QPushButton *backButton_widget = backButton->getWidget_button();
    backButton_widget->setFixedSize(app_width/8,app_height/12);
	// backButton_widget->setStyleSheet("QPushButton{background-color:green}");

	//Backbutton Container
    QWidget *backButton_container = new QWidget(window);
    QHBoxLayout *backButton_container_layout = new QHBoxLayout(backButton_container);
    backButton_container->setFixedHeight(app_height/6);
    backButton_container_layout->setAlignment(Qt::AlignLeft);
    backButton_container_layout->setContentsMargins(0, 0, 0, 0);

    backButton_container_layout->addWidget(backButton_widget);

	NavBar_layout->addWidget(backButton_container);
	NavBar_layout->addWidget(leaguenameText_widget);
	NavBar_layout->addWidget(usernameText_widget);

	// Match Array
	int no_of_match = matchVector.size();
	Match M[no_of_match];

	for(int i=0;i<no_of_match;i++){
		M[i] = matchVector[i];
	}

	//Container for match
    QWidget *match_container = new QWidget(window);
    QVBoxLayout *match_container_layout = new QVBoxLayout(match_container);
    match_container_layout->setSpacing(app_height/8);
    match_container_layout->setAlignment(Qt::AlignTop | Qt::AlignHCenter);
    match_container_layout->setContentsMargins(0, app_height / 10, 0, 0);

	// Scroll Area
	QScrollArea *scroll_area = new QScrollArea(window);

	scroll_area->setStyleSheet("QScrollArea { border: none; }");
	scroll_area->setFixedWidth(app_width*3/2);
	scroll_area->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	scroll_area->setWidgetResizable(true);

	EditableMatchWidget* matchWidget = new EditableMatchWidget();
	for(int i = 0; i < no_of_match; i++){
		if(!M[i].match_occur){
			QString team1Name = QString::fromStdString(M[i].T1.team_name);
			QIcon team1Icon(iconList_1[i]);

			QString team2Name = QString::fromStdString(M[i].T2.team_name);
			QIcon team2Icon(iconList_2[i]);

			QString match_ground = QString::fromStdString(M[i].T1.team_ground);

			QString team1Score, team2Score;
			
			team1Score = "-";
			team2Score = "-";
			
			matchWidget->init(
			QString(to_string(i+1).c_str()), 
			team1Name, team1Icon, team1Score, 
			team2Name, team2Icon, team2Score, 
			match_ground);

			match_container_layout->addWidget(matchWidget, Qt::AlignTop);
			break;		
		}
	}
	
	//Next Button
    appButton *updateButton= new appButton();
    updateButton->init(window,"NEXT MATCH",default_font_size*0.9);
    QPushButton *updateButton_widget = updateButton->getWidget_button();
    updateButton_widget->setFixedSize(app_width/4,app_height/12);
	updateButton_widget->setStyleSheet("QPushButton{background-color: #48FF4D}");

	//Next Container
    QWidget *updateButton_container = new QWidget(window);
    QHBoxLayout *updateButton_container_layout = new QHBoxLayout(updateButton_container);
    updateButton_container->setFixedHeight(app_height/6);
    updateButton_container_layout->setAlignment(Qt::AlignLeft);
    updateButton_container_layout->setContentsMargins(0, 0, 0, 0);

	QObject::connect(backButton_widget, &QPushButton::clicked, App, &StackedWidgets::changeWindow_backward);

    scroll_area->setWidget(match_container);

    main_widget_layout->addWidget(NavBar, 0, Qt::AlignTop);
	main_widget_layout->addWidget(scroll_area);
    // main_widget_layout->addWidget(deleteButton_widget, 0, Qt::AlignRight | Qt::AlignBottom);
    main_widget_layout->addWidget(updateButton_widget, 0, Qt::AlignCenter | Qt::AlignBottom);

	resetPage(window);
	
    QVBoxLayout *main_layout = new QVBoxLayout(window);
    main_layout->addWidget(main_widget);
    main_layout->setAlignment(Qt::AlignCenter);
    window->setLayout(main_layout);
}