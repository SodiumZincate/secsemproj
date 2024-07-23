#include "appUI.h"
#include "db.h"
#include "logic.h"

void initAddTeam(
StackedWidgets *App, 
QWidget* window, 
QString username, 
QString leaguename, 
int league_id, 
int user_id, 
int no_of_teams)
{
    window->setWindowTitle("Add League");

    QWidget *main_widget = new QWidget(window);
    main_widget->setFixedSize(app_width*3/2, app_height*3/2);
    // main_widget->setStyleSheet("QWidget{background-color:blue}");
    QVBoxLayout *main_widget_layout = new QVBoxLayout(main_widget);
    main_widget_layout->setAlignment(Qt::AlignCenter); // Center align the contents

    QWidget *sub_widget = new QWidget(window);
    sub_widget->setFixedSize(app_width, app_height*3/2);
    // sub_widget->setStyleSheet("QWidget{background-color:red}");
    QVBoxLayout *sub_widget_layout = new QVBoxLayout(sub_widget);
    sub_widget_layout->setAlignment(Qt::AlignTop);

    appText *main_text=new appText();
    main_text->init(window,"ADD TEAMS");
    QLabel *main_label=main_text->getWidget_label();

	//NavBar
    QWidget *NavBar = new QWidget(window);
    NavBar->setFixedSize(app_width*3/2, app_height/6);
	// NavBar->setStyleSheet("QWidget{background-color:yellow}");
    QHBoxLayout *NavBar_layout = new QHBoxLayout(NavBar);
    NavBar_layout->setAlignment(Qt::AlignTop);

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
	
	//League Name Text
	appText *leaguenameText = new appText();
    leaguenameText ->init(window, leaguename ,default_font_size*1.2);
    QLabel *leaguenameText_widget = leaguenameText->getWidget_label();
    leaguenameText_widget->setAlignment(Qt::AlignCenter);
    leaguenameText_widget->setFixedHeight(app_height/6);

	//Username text
    appText *usernameText = new appText();
    usernameText ->init(window, username ,default_font_size*0.9);
    QLabel *usernameText_widget=usernameText->getWidget_label();
    usernameText_widget->setAlignment(Qt::AlignRight);
    usernameText_widget->setFixedHeight(app_height/4);

	// Submit Button Widget
    appButton *continue_button = new appButton();
    continue_button->init(window, "Add Team");
    QPushButton *continue_button_widget = continue_button->getWidget_button();
	continue_button_widget->setFixedSize(app_width/2, app_height/8);

	 // Submit Button Container Widget (Made so the Submit Button Widget could be centered as a Widget)
    QWidget *continue_button_container = new QWidget(window);
    QHBoxLayout *continue_button_container_layout = new QHBoxLayout(continue_button_container);
    continue_button_container_layout->setAlignment(Qt::AlignCenter);
    continue_button_container_layout->setContentsMargins(0, app_height / 6, 0, 0);
	continue_button_container_layout->addWidget(continue_button_widget);

    backButton_container_layout->addWidget(backButton_widget);

	NavBar_layout->addWidget(backButton_container);
	NavBar_layout->addWidget(leaguenameText_widget);
	NavBar_layout->addWidget(usernameText_widget);

	QObject::connect(backButton_widget, &QPushButton::clicked,
	[=](){
		initAddLeague(
			App,
			App->stacked_windows.widget(App->stacked_windows.currentIndex()-1),
			username,
			user_id
		);
		App->changeWindow_backward();
	});

	std::stringstream clientRes;
	std::string token;
	std::vector<std::string> tokenList;

	std::string clientReq = to_string(league_id);
	int errorDatabase = updateDatabase(clientReq, "query_team_id", clientRes);
	getline(clientRes, token, '\n');
	static int max_team_id = stoi(token) + 1;

	if(errorDatabase != 0){
		std::cout << "\nError initializing league database" << std::endl;
	}
	else
	{
	TeamDialogBox *team_input = new TeamDialogBox(window);

	static vector<string> teamList = {};
	static vector<string> teamIconPathList = {};

	QObject::connect(continue_button_widget, &QPushButton::clicked, team_input, &TeamDialogBox::updateEditText);

	static int count=0;
	QObject::connect(continue_button_widget, &QPushButton::clicked, 
    [=]() {
		if(count >= no_of_teams){
			std::stringstream clientResLeague;
			std::stringstream clientResTeam;
			std::string streamLine;
			std::vector<std::string> streamList;
			vector<string> list;

			static int position = 1;

			std::string clientReq = to_string(league_id);
			int errorDatabase = updateDatabase(clientReq, "query_league", clientResLeague);
			while(getline(clientResLeague, streamLine, '\n')){
				list.push_back(streamLine);
			}
			if(errorDatabase != 0){
				std::cout << "\nError initializing league database" << std::endl;
			}
			else{
				int league_id = stoi(list[0]);
				int league_user_id = stoi(list[1]);
				string league_name = list[2];
				int league_group_stages = stoi(list[3]);
				int league_round_robin = stoi(list[4]);
				int league_qualifiers = stoi(list[5]);
				int league_number_of_groups = stoi(list[6]);
				int league_team_number = stoi(list[7]);

				cout << "league_id :: " << league_id << endl;
				cout << "league_user_id :: " << league_user_id << endl;
				cout << "league_name :: " << league_name << endl;
				cout << "league_group_stages :: " << league_group_stages<< endl;
				cout << "league_round_robin :: " << league_round_robin << endl;
				cout << "league_qualifiers :: " << league_qualifiers << endl;
				cout << "league_number_of_groups :: " << league_number_of_groups << endl;
				cout << "league_team_number :: " << league_team_number << endl;

				char group[20];
				int i, j, k;
				for (i = 0; i < league_number_of_groups; i++)
				{
					group[i] = (char) (65 + i);
				}

				k = 0;
				for(int j = 0; j < league_number_of_groups; j++)
				{
					for (i = j; i < no_of_teams; i += league_number_of_groups)
					{
						clientReq = to_string(user_id) + "\n"
						+ to_string(league_id) + "\n"
						+ teamList[i] + "\n"
						+ group[j] + "\n"
						+ to_string(position) + "\n"
						+ "0\n"
						+ "0\n"
						+ "0\n"
						+ "0\n"
						+ "0\n"
						+ "0\n"
						+ "0\n"
						+ "0";

						int errorDatabase = updateDatabase(clientReq, "insert_team", clientResTeam);
						if(errorDatabase != 0){
							std::cout << "\nError initializing league database" << std::endl;
						}
						else{
							std::cout << "qPosition inserted correctly: " << position << std::endl;
							position++;
						}
					}
					k++;
				}
			}
			initShowLeague(
				App,
				App->stacked_windows.widget(5),
				username,
				leaguename,
				no_of_teams
			);
			App->changeWindow_showLeague();
		}
		else{
			// Check if team_input is valid
			if (!team_input) {
				qDebug() << "team_input is null";
				return;
			}

			QString sourceFilePath = QFileInfo(team_input->file_name).filePath();
			QString newFilePath = QDir::currentPath() + "/requisite/assets/images/" + QString(to_string(max_team_id).c_str()) + ".png";

			// Ensure destination directory exists
			QDir dir(QFileInfo(newFilePath).path());
			if (!dir.exists()) {
				if (!dir.mkpath(".")) {
					qDebug() << "Failed to create directory:" << QFileInfo(newFilePath).path();
					return;
				}
			}

			QFile sourceFile(sourceFilePath);
			if (!sourceFile.exists()) {
				qDebug() << "Source file does not exist:" << sourceFilePath;
				return;
			}

			if (!QFile::exists(newFilePath) && sourceFile.copy(newFilePath)) {
				team_input->iconAdded = true;
				qDebug() << "File copied successfully.";
			} else {
				qDebug() << "File copy failed.";
				qDebug() << "Error:" << sourceFile.errorString();
				return;
			}

			if (!team_input->team_name.isEmpty() && team_input->iconAdded) {
				if (count < no_of_teams) {
					qDebug() << team_input->getTeamName().toStdString();
					teamList.push_back(team_input->getTeamName().toStdString());
					qDebug() << newFilePath.toStdString();
					teamIconPathList.push_back(newFilePath.toStdString());
					team_input->iconAdded = false;
					count++;
					max_team_id++;
				}
				if (count == no_of_teams) {
					continue_button_widget->setText("Continue to League");
					continue_button_widget->setStyleSheet("QPushButton{background-color: #48FF4D}");
				}
			} else {
				qDebug() << "Fields can't be empty";
			}
		}
    });

    sub_widget_layout->addWidget(main_label);
    sub_widget_layout->addWidget(team_input, 0, Qt::AlignCenter);

	main_widget_layout->addWidget(NavBar,0,Qt::AlignTop);
	main_widget_layout->addWidget(sub_widget,0, Qt::AlignCenter);
	main_widget_layout->addWidget(continue_button_widget,0, Qt::AlignCenter);

	resetPage(window);

    QVBoxLayout *main_layout = new QVBoxLayout(window);
    main_layout->addWidget(main_widget);
    main_layout->setAlignment(Qt::AlignCenter);
    window->setLayout(main_layout);
	}
}