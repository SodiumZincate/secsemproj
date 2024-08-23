#include "appUI.h"
#include "db.h"
#include "logic.h"

void initDashboard(StackedWidgets *App, QWidget* window, QString username = "username", int user_id = 0){
	window->setWindowTitle("Dashboard");

	QWidget *main_widget = new QWidget(window);
	main_widget->setFixedSize(app_width*3/2, app_height*3/2);
	// main_widget->setStyleSheet("QWidget{background-color:red}");
	QVBoxLayout *main_widget_layout = new QVBoxLayout(main_widget);
	//main_widget_layout->setAlignment(Qt::AlignCenter); // Center align the contents
	
	//Username Text
    appText *usernameText = new appText();
    usernameText ->init(window, username ,default_font_size*0.8);
    QLabel *usernameText_widget=usernameText->getWidget_label();
    usernameText_widget->setAlignment(Qt::AlignRight);
    usernameText_widget->setFixedHeight(app_height/4);

    // //League Text
    // appText *leaguetext = new appText();
    // leaguetext->init(window,"Your Leagues",default_font_size);
    // QLabel *leagueLabel_widget= leaguetext->getWidget_label();
    // leagueLabel_widget->setMargin(10);
	// mainLabel->setStyleSheet("QLabel{text-decoration:bold;}");
    // leagueLabel_widget->setAlignment(Qt::AlignTop | Qt::AlignCenter);
	
	//League Name Text
	appText *mainText = new appText();
    mainText ->init(window, "League Manager" ,default_font_size*1.2);
    QLabel *mainText_widget = mainText->getWidget_label();
    mainText_widget->setAlignment(Qt::AlignCenter);
    mainText_widget->setFixedHeight(app_height/6);

	//Backbutton Container
    QWidget *backButton_container = new QWidget(window);
    QHBoxLayout *backButton_container_layout = new QHBoxLayout(backButton_container);
    backButton_container->setFixedHeight(app_height/6);
    backButton_container_layout->setAlignment(Qt::AlignLeft);
    backButton_container_layout->setContentsMargins(0, 0, 0, 0);

	//Back Button
    appButton *backButton= new appButton();
    backButton->init(window,"Log Out",default_font_size*0.9);
    QPushButton *backButton_widget = backButton->getWidget_button();
    backButton_widget->setFixedSize(app_width/8,app_height/12);
	backButton_widget->setStyleSheet("QPushButton{background-color:#bb8fce}");

    backButton_container_layout->addWidget(backButton_widget);
    // backButton_container_layout->addWidget(usernameText_widget, 0, Qt::AlignRight);
	
	//NavBar
    QWidget *NavBar = new QWidget(window);
    QHBoxLayout *NavBar_layout = new QHBoxLayout(NavBar);
    NavBar->setFixedHeight(app_height/6);
    NavBar_layout->setContentsMargins(0, 0, 0, 0);
	//NavBar->setStyleSheet("QWidget{background-color:yellow}");

	NavBar_layout->addWidget(backButton_container);
	NavBar_layout->addWidget(mainText_widget);
	NavBar_layout->addWidget(usernameText_widget);

    appText *league_text = new appText();
    league_text->init(window,"Your Leagues");
    QLabel *leagueLabel_widget= league_text->getWidget_label();
	leagueLabel_widget->setMargin(0);
	leagueLabel_widget->setFixedHeight(app_height/6);
	leagueLabel_widget->setStyleSheet("QLabel{color:blue}");
    leagueLabel_widget->setAlignment(Qt::AlignTop | Qt::AlignHCenter);

    //Container for league buttons
    QWidget *button_container = new QWidget(window);
    QVBoxLayout *button_container_layout = new QVBoxLayout(button_container);
    button_container_layout->setAlignment(Qt::AlignTop | Qt::AlignHCenter);
    button_container_layout->setContentsMargins(0, app_height / 10, 0, 0);

	// Scroll Area
	QScrollArea *scroll_area = new QScrollArea(window);

	scroll_area->setStyleSheet("QScrollArea { border: none; }");
	scroll_area->setFixedWidth(app_width);
	scroll_area->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	scroll_area->setWidgetResizable(true);

	std::string clientReq = std::to_string(user_id);
	std::stringstream clientRes;
	std::string streamLine;
	std::vector<std::string> leagueNameList;
	std::vector<std::string> leagueIdList;
	
	int no_of_leagues = 0;
	int errorDatabase = updateDatabase(clientReq, "query_league_list", clientRes);
	if(errorDatabase!=0){
		std::cout << "\nError initializing database" << std::endl;
	}
	else{
		while(getline(clientRes, streamLine, '\n')){
			leagueIdList.push_back(streamLine);
			getline(clientRes, streamLine, '\n');
			leagueNameList.push_back(streamLine);
			// std::cout << "League name: " << streamLine << std::endl;
			if(strcmp(streamLine.c_str(), "") != 0){
				no_of_leagues++;
			}
		}
	}
	std::cout << "Number of leagues: " << no_of_leagues << std::endl;

	if(no_of_leagues == 0){
		leagueLabel_widget->setStyleSheet({"QLabel{color:#FB3B3B}"});
		leagueLabel_widget->setText("YOU DON'T HAVE ANY LEAGUES CURRENLY\nPRESS \"ADD LEAGUE\" TO ADD MORE LEAGUES");
	}
	else{
		leagueLabel_widget->setText(("Your Leagues (" + std::to_string(no_of_leagues) + ")").c_str());
	}
    button_container_layout->addWidget(leagueLabel_widget);

	for(int i = 0; i < no_of_leagues; i++){
		appClickableText *league_name = new appClickableText();
		QString text = (std::to_string(i+1) + ") <u>" + leagueNameList[i] + "</u>").c_str();
		league_name->init(window, text, default_font_size*0.8);

		QObject::connect(league_name, &appClickableText::clicked,
		[=](){
			qDebug() << "Clicked league_name:" << text;
			std::stringstream clientResLeague;
			std::stringstream clientResTeam;
			std::string streamLine;
			std::vector<std::string> streamList;

			std::string clientReq = leagueIdList[i];
			int errorDatabase = updateDatabase(clientReq, "query_league", clientResLeague);
			getline(clientResLeague, streamLine, '\n');
			if(errorDatabase != 0 || strcmp(streamLine.c_str(), "") == 0){
				std::cout << "\nError initializing league database" << std::endl;
			}
			else{
				std::string league_string = clientResLeague.str();

				clientReq = std::to_string(user_id) + "\n" + leagueIdList[i];
				int errorDatabase = updateDatabase(clientReq, "query_team", clientResTeam);
				getline(clientResTeam, streamLine, '\n');
				if(errorDatabase !=0 || strcmp(streamLine.c_str(), "") == 0){
					stringstream temp;
					std::cout << "\nError initializing team database" << std::endl;
					int errorDatabase = updateDatabase(leagueIdList[i], "delete_league", temp);

					if(errorDatabase!=0){
						cout << "Failed to delete league" << endl;
					}
					else{
						cout << "league deleted successfully" << endl;
						initDashboard(
							App,
							App->stacked_windows.widget(2),
							username,
							user_id
						);
						App->changeWindow_dashboard();
					}
				}
				else{
					std::string team_string = clientResTeam.str();
					// cout << "League String: " << league_string << endl;
					// cout << "Team String: " << team_string << endl;
					// update(league_string, team_string);
					League L = displayLeague(league_string, team_string);

					initShowLeague(
						App,
						App->stacked_windows.widget(5),
						username,
						QString(leagueNameList[i].c_str()),
						L
					);
					App->changeWindow_showLeague();
				}
			}
		});

		button_container_layout->addWidget(league_name, Qt::AlignTop);
	}

    appButton *leagueButton =new appButton();
    leagueButton->init(window,"Add league",default_font_size*1.2);
    QPushButton *leagueButton_widget=leagueButton->getWidget_button();
    leagueButton_widget->setFixedSize(app_width/4,app_width/14);
	leagueButton_widget->setStyleSheet("QPushButton{background-color: #a2d9ce}");
	
    //Container for League button
    QWidget *leagueButton_container = new QWidget(window);
    QVBoxLayout *leagueButton_container_layout = new QVBoxLayout(leagueButton_container);
    leagueButton_container_layout->setAlignment(Qt::AlignCenter);
    leagueButton_container_layout->setContentsMargins(0, app_height /5, 0, 0);

    leagueButton_container_layout->addWidget(leagueButton_widget);

	scroll_area->setWidget(button_container);

    main_widget_layout->addWidget(NavBar);
    main_widget_layout->addWidget(leagueLabel_widget);
    main_widget_layout->addWidget(scroll_area, 0, Qt::AlignHCenter);
    main_widget_layout->addWidget(leagueButton_container);

	QObject::connect(backButton_widget, &QPushButton::clicked, App, &StackedWidgets::changeWindow_backward);
	QObject::connect(leagueButton_widget, &QPushButton::clicked,
	[=](){
		std::cout << App->stacked_windows.currentIndex() << std::endl;
		initAddLeague(
			App,
			App->stacked_windows.widget(App->stacked_windows.currentIndex()+1),
			QString(username),
			user_id
		);
		App->changeWindow_forward();
	}
	);

	resetPage(window);

	QVBoxLayout *main_layout = new QVBoxLayout(window);
    main_layout->addWidget(main_widget);
    main_layout->setAlignment(Qt::AlignCenter);
    window->setLayout(main_layout);
}