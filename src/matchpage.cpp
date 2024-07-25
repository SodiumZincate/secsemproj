#include "appUI.h"
#include "db.h"
#include "logic.h"

void initNextMatch(StackedWidgets *App, QWidget* window, QString username = "username", QString leaguename = "leaguename", League L = League()){
    window->setWindowTitle("League Name");

    QWidget *main_widget = new QWidget(window);
    main_widget->setFixedSize(app_width*3/2, app_height*3/2);
    // main_widget->setStyleSheet("QWidget{background-color:blue}");
    QVBoxLayout *main_widget_layout = new QVBoxLayout(main_widget);
    main_widget_layout->setAlignment(Qt::AlignCenter); // Center align the contents

    QWidget *sub_widget = new QWidget(window);
    sub_widget->setFixedSize(app_width*3/2, app_height*3/2);
    // sub_widget->setStyleSheet("QWidget{background-color:red}");
	// sub_widget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
    QVBoxLayout *sub_widget_layout = new QVBoxLayout(sub_widget);
    sub_widget_layout->setAlignment(Qt::AlignTop);
	sub_widget_layout->setSpacing(80);

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

	// for(int i = 0; i < 8; i++){
	// 	appText *team_name_1 = new appText();
	// 	QString text = M[i].team;
	// 	team_name_1->init(window, text, default_font_size*0.8);

	// 	QObject::connect(league_name, &appClickableText::clicked,
	// 	[=](){
	// 	qDebug() << "Clicked league_name:" << text;
	// 	std::stringstream clientResLeague;
	// 	std::stringstream clientResTeam;
	// 	std::string streamLine;
	// 	std::vector<std::string> streamList;

	// 	std::string clientReq = leagueIdList[i];
	// 	int errorDatabase = updateDatabase(clientReq, "query_league", clientResLeague);
	// 	getline(clientResLeague, streamLine, '\n');
	// 	if(errorDatabase != 0 || strcmp(streamLine.c_str(), "") == 0){
	// 		std::cout << "\nError initializing league database" << std::endl;
	// 	}
	// 	else{
	// 		std::string league_string = clientResLeague.str();

	// 		clientReq = std::to_string(user_id) + "\n" + leagueIdList[i];
	// 		int errorDatabase = updateDatabase(clientReq, "query_team", clientResTeam);
	// 		getline(clientResTeam, streamLine, '\n');
	// 		if(errorDatabase !=0 || strcmp(streamLine.c_str(), "") == 0){
	// 			stringstream temp;
	// 			std::cout << "\nError initializing team database" << std::endl;
	// 			int errorDatabase = updateDatabase(leagueIdList[i], "delete_league", temp);

	// 			if(errorDatabase!=0){
	// 				cout << "Failed to delete league" << endl;
	// 			}
	// 			else{
	// 				cout << "league deleted successfully" << endl;
	// 				initDashboard(
	// 					App,
	// 					App->stacked_windows.widget(2),
	// 					username,
	// 					user_id
	// 				);
	// 				App->changeWindow_dashboard();
	// 			}
	// 		}
	// 		else{
	// 			std::string team_string = clientResTeam.str();
	// 			// cout << "League String: " << league_string << endl;
	// 			// cout << "Team String: " << team_string << endl;
	// 			update(league_string, team_string);
	// 			League L = displayLeague(league_string, team_string);
	// 			vector<Group> groupList = displayGroups(league_string, team_string);
	// 			initShowLeague(
	// 				App,
	// 				App->stacked_windows.widget(5),
	// 				username,
	// 				QString(leagueNameList[i].c_str()),
	// 				L,
	// 				groupList
	// 			);
	// 			App->changeWindow_showLeague();
	// 		}
	// 	}
	// 	});

	// 	button_container_layout->addWidget(league_name, Qt::AlignTop);
	// }

	// //Delete Button
    // appButton *deleteButton= new appButton();
    // deleteButton->init(window,"DELETE LEAGUE",default_font_size*0.9);
    // QPushButton *deleteButton_widget = deleteButton->getWidget_button();
    // deleteButton_widget->setFixedSize(app_width/4,app_height/12);
	// deleteButton_widget->setStyleSheet("QPushButton{background-color: #FB3B3B}");

	// //Delete Container
    // QWidget *deleteButton_container = new QWidget(window);
    // QHBoxLayout *deleteButton_container_layout = new QHBoxLayout(deleteButton_container);
    // deleteButton_container->setFixedHeight(app_height/6);
    // deleteButton_container_layout->setAlignment(Qt::AlignLeft);
    // deleteButton_container_layout->setContentsMargins(0, 0, 0, 0);

    // deleteButton_container_layout->addWidget(deleteButton_widget);

	// NavBar_layout->addWidget(backButton_container);
	// NavBar_layout->addWidget(leaguenameText_widget);
	// NavBar_layout->addWidget(usernameText_widget);
	
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

	// // Scroll Area
	// QScrollArea *scroll_area = new QScrollArea(window);

	// scroll_area->setStyleSheet("QScrollArea { border: none; }");
	// scroll_area->setFixedWidth(app_width*3/2);
	// scroll_area->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	// scroll_area->setWidgetResizable(true);

	// for(int i=0; i<L.league_groups; i++){
	// 	// Label
	// 	appText *group_name = new appText();
	// 	std::string group_name_text = "GROUP: " + std::string(1, (char)(i + 65));
	// 	group_name->init(window, QString::fromStdString(group_name_text), default_font_size * 0.8);
	// 	cout << group_name->getWidget_label()->text().toStdString() << endl;
	// 	QLabel *group_label = group_name->getWidget_label();

	// 	QStringList teamNameList = {};
	// 	QList<QIcon> iconList = {};

	// 	int i1,j1,k1;
	// 	Group groupArray[L.league_groups];

	// 	for (i1 = 0; i1 < L.league_groups; i1++)
	// 	{
	// 		groupArray[i1].group_name = (char) (i1 + 65);
	// 	}

	// 	int no_of_teams = 0;
	// 	k1 = 0;
	// 	for (j1 = 0; j1 < L.league_team_number; j1++)
	// 	{
	// 		if (L.T[j1].team_group == groupArray[i].group_name)
	// 		{
	// 			groupArray[i].T[k1] = L.T[j1];
	// 			no_of_teams++;

	// 			cout << "Added Teams: " << groupArray[i].T[k1].team_name << endl;

	// 			QIcon icon;
	// 			downloadIcon(to_string(groupArray[i].T[k1].team_id) + ".png", icon);

	// 			iconList.push_back(icon);
    //             k1++;
	// 		}
	// 	}

	// 	// Table
	// 	QTableWidget *league_table = new QTableWidget(no_of_teams, 9, window);
	// 	league_table->setMinimumSize(app_width*3/2, app_height*5/4);
	// 	league_table->setColumnWidth(0, app_width*0.4);

	// 	QSize icon_size(app_width/16, app_height/16);
	// 	league_table->setIconSize(icon_size);

	// 	QStringList header_label_list = {
	// 		"Team Name",
	// 		"MP",
	// 		"W",
	// 		"D",
	// 		"L",
	// 		"GF",
	// 		"GA",
	// 		"GD",
	// 		"Pts",
	// 	};


	// 	// for(const auto& entry : std::filesystem::directory_iterator("requisite/assets/images/logo")){
	// 	// 	std::string logo_name = entry.path().filename().string();
	// 	// 	std::string logo_dir = "requisite/assets/images/logo/" + logo_name;
	// 	// 	std::cout << logo_dir << std::endl;
	// 	// 	icons.push_back(QString(logo_dir.c_str()));
	// 	// 	icons.push_back(QString(logo_dir.c_str()));
	// 	// }

	// 	league_table->setHorizontalHeaderLabels(header_label_list);
    //     league_table->horizontalHeader()->setFont(QFont("Sans", default_font_size*0.6));
    //     league_table->verticalHeader()->setFont(QFont("Sans", default_font_size*0.6));

	// 	for (int j = 0; j < league_table->rowCount(); j++) {
	// 		// QPixmap pixmap(iconList[j]);
	// 		// QIcon icon(pixmap.scaled(800, 800, Qt::KeepAspectRatio, Qt::SmoothTransformation));
	// 		QTableWidgetItem *table_item = new QTableWidgetItem(iconList[j], QString(groupArray[i].T[j].team_name.c_str()), 0);
    //         table_item->setFont(QFont("Sans", default_font_size*0.8));
	// 		table_item->setFlags(table_item->flags() & ~Qt::ItemIsEditable);
	// 		league_table->setItem(j, 0, table_item);

	// 		QStringList properties = {
	// 			QString(groupArray[i].T[j].team_name.c_str()),
	// 			QString::number(groupArray[i].T[j].team_mp),
	// 			QString::number(groupArray[i].T[j].team_w),
	// 			QString::number(groupArray[i].T[j].team_d),
	// 			QString::number(groupArray[i].T[j].team_l),
	// 			QString::number(groupArray[i].T[j].team_gf),
	// 			QString::number(groupArray[i].T[j].team_ga),
	// 			QString::number(groupArray[i].T[j].team_gf),
	// 			QString::number(groupArray[i].T[j].team_points)
	// 		};

    //         for(int k = 1; k < league_table->columnCount(); k++){
    //             QTableWidgetItem *table_item = new QTableWidgetItem(properties[k], 0);
    //             table_item->setFont(QFont("Sans", default_font_size*0.6));
    //             table_item->setTextAlignment(Qt::AlignCenter);
    //             table_item->setFlags(table_item->flags() & ~Qt::ItemIsEditable);
    //             league_table->setItem(j, k, table_item);
    //         }
	// 	}
		
	// 	for (int j = 0; j < league_table->columnCount(); j++) {
	// 		if (j == 0) { 
	// 			league_table->horizontalHeader()->setSectionResizeMode(j, QHeaderView::Fixed);
	// 		} else {
	// 			league_table->horizontalHeader()->setSectionResizeMode(j, QHeaderView::Stretch);
	// 		}
	// 	}
	// 	if(league_table->rowCount()<=4){
	// 		league_table->setMinimumSize(app_width*5/4, app_height/2);
	// 		league_table->setIconSize(QSize(app_width/14, app_height/14));
	// 	}
	// 	else if(league_table->rowCount()<=8){
	// 		league_table->setMinimumSize(app_width*5/4, app_height*5/6);
	// 		league_table->setIconSize(QSize(app_width/16, app_height/16));
	// 	}
	// 	if(league_table->rowCount()<12){
	// 		league_table->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	// 	}
	// 	else{
    //         league_table->verticalHeader()->setMinimumSectionSize(app_height/10);
	// 		for (int j = 0; j < league_table->rowCount(); j++) {
	// 			league_table->verticalHeader()->setSectionResizeMode(j, QHeaderView::Fixed);
	// 		}
	// 	}
	// 	sub_widget_layout->addWidget(group_label);
	// 	sub_widget_layout->addWidget(league_table);
	// }

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

    // scroll_area->setWidget(sub_widget);

    main_widget_layout->addWidget(NavBar, 0, Qt::AlignTop);
    main_widget_layout->addWidget(sub_widget);
    // main_widget_layout->addWidget(deleteButton_widget, 0, Qt::AlignRight | Qt::AlignBottom);
    main_widget_layout->addWidget(nextButton_widget, 0, Qt::AlignCenter | Qt::AlignBottom);

	resetPage(window);
	
    QVBoxLayout *main_layout = new QVBoxLayout(window);
    main_layout->addWidget(main_widget);
    main_layout->setAlignment(Qt::AlignCenter);
    window->setLayout(main_layout);
}