#include "appUI.h"
#include "db.h"
#include "logic.h"

void initNextMatch(
	StackedWidgets *App, 
	QWidget* window, 
	QString username,
	QString leaguename,
	League L = League()
){
    window->setWindowTitle("League Name");

    QWidget *main_widget = new QWidget(window);
    main_widget->setFixedSize(app_width*3/2, app_height*3/2);
    // main_widget->setStyleSheet("QWidget{background-color:blue}");
    QVBoxLayout *main_widget_layout = new QVBoxLayout(main_widget);
    main_widget_layout->setAlignment(Qt::AlignCenter); // Center align the contents

    // QWidget *sub_widget = new QWidget(window);
    // sub_widget->setFixedSize(app_width*3/2, app_height*3/2);
    // // sub_widget->setStyleSheet("QWidget{background-color:red}");
	// // sub_widget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
    // QVBoxLayout *sub_widget_layout = new QVBoxLayout(sub_widget);
    // sub_widget_layout->setAlignment(Qt::AlignTop);
	// sub_widget_layout->setSpacing(80);

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
	string clientReq = to_string(L.league_id);
	std::stringstream clientResMatchNumber;
	std::string token;
	int errorDatabase = updateDatabase(clientReq, "query_match_number", clientResMatchNumber);
	if(errorDatabase != 0){
		std::cout << "\nError initializing match database" << std::endl;
		exit(1);
	}
	else{
		getline(clientResMatchNumber, token, '\n');
	}

	int no_of_match = stoi(token);
	Match M[no_of_match];
	QList<QIcon> iconList_1 = {}, iconList_2 ={};

	cout << "Number of match: " << no_of_match << endl;
	clientReq.clear();
	clientReq = to_string(L.league_user_id) + "\n" + to_string(L.league_id);
	std::stringstream clientResMatch;
	
	errorDatabase = updateDatabase(clientReq, "query_match", clientResMatch);
	if(errorDatabase != 0){
		std::cout << "\nError initializing match database" << std::endl;
		exit(1);
	}
	else{
		int i;
		stringstream tokenStream;
		vector<string> list;
		string match_string;
		for(i = 0; i < no_of_match; i++)
		{
			match_string.clear();
			for(int j = 0; j < 8; j++)
			{
				getline(clientResMatch, token, '\n');
				match_string += token + "\n";
			}

			tokenStream.clear();
			tokenStream << match_string;
			list.clear();
			while(getline(tokenStream, token, '\n'))
			{
				list.push_back(token);
			}

			M[i].T1 = Team();
			M[i].T2 = Team();
			M[i].match_id=stoi(list[0]);
		    M[i].match_user_id = stoi(list[1]);
		    M[i].match_league_lid = stoi(list[2]);
			int tid_1 = stoi(list[3]);
			int tid_2 = stoi(list[4]);
			M[i].T1_score = stoi(list[5]);
			M[i].T2_score = stoi(list[6]);
			M[i].match_occur = stoi(list[7]);

			for(int j=0; j<L.league_team_number; j++){
				if(L.T[j].team_id == tid_1){
					M[i].T1 = L.T[j];
					break;
				}
			}
			for(int j=0; j<L.league_team_number; j++){
				if(L.T[j].team_id == tid_2){
					M[i].T2 = L.T[j];
					break;
				}
			}
			QIcon icon_1, icon_2;
			downloadIcon(to_string(M[i].T1.team_id) + ".png", icon_1);
			downloadIcon(to_string(M[i].T2.team_id) + ".png", icon_2);

			iconList_1.push_back(icon_1);
			iconList_2.push_back(icon_2);
			cout << "Pairing Match " << i << ": Team1 ID " << M[i].T1.team_id << " vs Team2 ID " << M[i].T2.team_id << endl;
		}
	}

	
    //Container for league buttons
    QWidget *button_container = new QWidget(window);
    QVBoxLayout *button_container_layout = new QVBoxLayout(button_container);
    button_container_layout->setSpacing(app_height/8);
    button_container_layout->setAlignment(Qt::AlignTop | Qt::AlignHCenter);
    button_container_layout->setContentsMargins(0, app_height / 10, 0, 0);

	// Scroll Area
	QScrollArea *scroll_area = new QScrollArea(window);

	scroll_area->setStyleSheet("QScrollArea { border: none; }");
	scroll_area->setFixedWidth(app_width*3/2);
	scroll_area->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	scroll_area->setWidgetResizable(true);

	for(int i = 0; i < no_of_match; i++){
		MatchWidget* matchWidget = new MatchWidget(window);
        
        // Assuming you have icon paths as strings
        QString team1Name = QString::fromStdString(M[i].T1.team_name);
        QIcon team1Icon(iconList_1[i]); // Replace with actual 

        QString team2Name = QString::fromStdString(M[i].T2.team_name);
        QIcon team2Icon(iconList_2[i]);

		QString team1Score, team2Score;
        if(M[i].match_occur){
       		team1Score = QString::number(M[i].T1_score);
			team2Score = QString::number(M[i].T2_score);
		}
		else{
			team1Score = "-";
			team2Score = "-";
		}

        matchWidget->init(QString(to_string(i+1).c_str()), team1Name, team1Icon, team1Score, team2Name, team2Icon, team2Score);

		button_container_layout->addWidget(matchWidget, Qt::AlignTop);
	}
	
	//Next Button
    appButton *nextButton= new appButton();
    nextButton->init(window,"NEXT MATCH",default_font_size*0.9);
    QPushButton *nextButton_widget = nextButton->getWidget_button();
    nextButton_widget->setFixedSize(app_width/4,app_height/12);
	nextButton_widget->setStyleSheet("QPushButton{background-color: #48FF4D}");

	//Next Container
    QWidget *nextButton_container = new QWidget(window);
    QHBoxLayout *nextButton_container_layout = new QHBoxLayout(nextButton_container);
    nextButton_container->setFixedHeight(app_height/6);
    nextButton_container_layout->setAlignment(Qt::AlignLeft);
    nextButton_container_layout->setContentsMargins(0, 0, 0, 0);

    // deleteButton_container_layout->addWidget(deleteButton_widget);

	QObject::connect(backButton_widget, &QPushButton::clicked, App, &StackedWidgets::changeWindow_backward);
	// QObject::connect(deleteButton_widget, &QPushButton::clicked,
	// [=](){
	// 	QMessageBox::StandardButton reply;
    //     reply = QMessageBox::question(window, "Confirm Deletion",
    //                                   "Are you sure you want to delete?",
    //                                   QMessageBox::Yes | QMessageBox::No);
        
    //     if (reply == QMessageBox::Yes) {
	// 		stringstream temp;
	// 			cout << "del League ID: " << L.league_id << endl;
	// 			int errorDatabase = updateDatabase(to_string(L.league_id), "delete_league", temp);

	// 			if(errorDatabase!=0){
	// 				cout << "Failed to delete league" << endl;
	// 			}
	// 			else{
	// 				cout << "league deleted successfully" << endl;
	// 				initDashboard(
	// 					App,
	// 					App->stacked_windows.widget(2),
	// 					username,
	// 					L.league_user_id
	// 				);
	// 				App->changeWindow_dashboard();
	// 			}
    //         qDebug() << "User chose to delete.";
    //     } else {
    //         qDebug() << "User canceled the deletion.";
    //     }
	// });

    scroll_area->setWidget(button_container);

    main_widget_layout->addWidget(NavBar, 0, Qt::AlignTop);
    main_widget_layout->addWidget(scroll_area);
    // main_widget_layout->addWidget(deleteButton_widget, 0, Qt::AlignRight | Qt::AlignBottom);
    main_widget_layout->addWidget(nextButton_widget, 0, Qt::AlignCenter | Qt::AlignBottom);

	cout << "Hello" << endl;
	resetPage(window);
	cout << "Hello" << endl;
	
    QVBoxLayout *main_layout = new QVBoxLayout(window);
    main_layout->addWidget(main_widget);
    main_layout->setAlignment(Qt::AlignCenter);
    window->setLayout(main_layout);
}