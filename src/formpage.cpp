#include "appUI.h"
#include "db.h"
#include "logic.h"

void initAddLeague(StackedWidgets *App, QWidget* window, QString username = "username", int user_id = 0){
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
    main_text->init(window,"ADD LEAGUE");
    QLabel *main_label=main_text->getWidget_label();

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
	NavBar_layout->addWidget(usernameText_widget);

	//
	QWidget *league_name = new QWidget(window);
	// league_name->setStyleSheet("QWidget{background-color:red}");
    league_name->setFixedHeight(app_height/8);
    QHBoxLayout *league_name_layout=new QHBoxLayout(league_name);
    league_name_layout->setAlignment(Qt::AlignLeft);

    LabelEditComponent *league_name_component=new LabelEditComponent();
    league_name_component->init(league_name,"League Name");
    QLabel *league_name_label=league_name_component->getWidget_label();
    league_name_label->setFixedSize(QSize(app_width / 4, app_height / 10));
    QLineEdit *league_name_edit=league_name_component->getWidget_edit();
	league_name_edit->setFixedSize(app_width*71/100, app_height/10);

    league_name_layout->addWidget(league_name_label);
    league_name_layout->addWidget(league_name_edit);

	//
	QWidget *no_of_teams = new QWidget(window);
	// league_name->setStyleSheet("QWidget{background-color:red}");
    no_of_teams->setFixedHeight(app_height/8);
    QHBoxLayout *no_of_teams_layout=new QHBoxLayout(no_of_teams);
    no_of_teams_layout->setAlignment(Qt::AlignLeft);

    LabelEditComponent *no_of_teams_component=new LabelEditComponent();
    no_of_teams_component->init(no_of_teams,"No. of Teams", default_font_size*0.8);
    QLabel *no_of_teams_label  = no_of_teams_component->getWidget_label();
    no_of_teams_label->setFixedSize(QSize(app_width / 4, app_height / 10));
    QLineEdit *no_of_teams_edit = no_of_teams_component->getWidget_edit();
	no_of_teams_edit->setFixedSize(app_width*71/100, app_height/10);

    no_of_teams_layout->addWidget(no_of_teams_label);
    no_of_teams_layout->addWidget(no_of_teams_edit);
    
	//
    QWidget *group_stage=new QWidget(window);
	// group_stage->setStyleSheet("QWidget{background-color:red}");
    group_stage->setFixedHeight(app_height/8);
    QHBoxLayout *group_stage_layout=new QHBoxLayout(group_stage);
    group_stage_layout->setAlignment(Qt::AlignLeft);

	LabelComboComponent *group_stage_component = new LabelComboComponent();
	group_stage_component->init(window, "No. of Group Stages: ", {"0","1","2"}, default_font_size*0.8);
    QLabel *group_stage_label = group_stage_component->getWidget_label();
    QComboBox *group_stage_combobox = group_stage_component->getWidget_combo();
	
    group_stage_layout->addWidget(group_stage_label);
    group_stage_layout->addWidget(group_stage_combobox);

	//
    QWidget *round_robin=new QWidget(window);
    round_robin->setFixedHeight(app_height/8);
    QHBoxLayout *round_robin_layout=new QHBoxLayout(round_robin);
    round_robin_layout->setAlignment(Qt::AlignLeft);

	LabelComboComponent *round_robin_component = new LabelComboComponent();
	round_robin_component->init(window, "Round Robin: ", {"1","2"}, default_font_size*0.8);
    QLabel *round_robin_label = round_robin_component->getWidget_label();
    QComboBox *round_robin_combobox = round_robin_component->getWidget_combo();
	
    round_robin_layout->addWidget(round_robin_label);
    round_robin_layout->addWidget(round_robin_combobox);

	//
	QWidget *qualifiers=new QWidget(window);
    qualifiers->setFixedHeight(app_height/8);
    QHBoxLayout *qualifiers_layout=new QHBoxLayout(qualifiers);
    qualifiers_layout->setAlignment(Qt::AlignLeft);

	LabelComboComponent *qualifiers_component = new LabelComboComponent();
	qualifiers_component->init(window, "Qualifiers: ", {"1","2","4"}, default_font_size*0.8);
    QLabel *qualifiers_label = qualifiers_component->getWidget_label();
    QComboBox *qualifiers_combobox = qualifiers_component->getWidget_combo();

    qualifiers_layout->addWidget(qualifiers_label);
    qualifiers_layout->addWidget(qualifiers_combobox);

	//
	QWidget *no_of_groups=new QWidget(window);
    no_of_groups->setFixedHeight(app_height/8);
    QHBoxLayout *no_of_groups_layout=new QHBoxLayout(no_of_groups);
    no_of_groups_layout->setAlignment(Qt::AlignLeft);

	LabelComboComponent *no_of_groups_component = new LabelComboComponent();
	no_of_groups_component->init(window, "No of groups: ", {"1","2","4","8"}, default_font_size*0.8);
    QLabel *no_of_groups_label = no_of_groups_component->getWidget_label();
    QComboBox *no_of_groups_combobox = no_of_groups_component->getWidget_combo();

    no_of_groups_layout->addWidget(no_of_groups_label);
    no_of_groups_layout->addWidget(no_of_groups_combobox);

	// Submit Button Widget
    appButton *continue_button = new appButton();
    continue_button->init(window, "Continue");
    QPushButton *continue_button_widget = continue_button->getWidget_button();

	 // Submit Button Container Widget (Made so the Submit Button Widget could be centered as a Widget)
    QWidget *continue_button_container = new QWidget(window);
    QHBoxLayout *continue_button_container_layout = new QHBoxLayout(continue_button_container);
    continue_button_container_layout->setAlignment(Qt::AlignCenter);
    continue_button_container_layout->setContentsMargins(0, app_height / 8, 0, 0);
	continue_button_container_layout->addWidget(continue_button_widget);

	QObject::connect(backButton_widget, &QPushButton::clicked,
	[=](){
		initDashboard(
			App,
			App->stacked_windows.widget(App->stacked_windows.currentIndex()-1),
			username,
			user_id
		);
		App->changeWindow_backward();
	});

	QObject::connect(continue_button_widget, &QPushButton::clicked, league_name_component, &LabelEditComponent::updateEditText);
	QObject::connect(continue_button_widget, &QPushButton::clicked, no_of_teams_component, &LabelEditComponent::updateEditText);
	QObject::connect(continue_button_widget, &QPushButton::clicked, 
	[=]() {
		std::string league_text;
		league_text = (league_name_component->getFieldText()).toStdString();

		int number_group_stage, number_round_robin, number_qualifiers, number_no_of_groups;

		number_group_stage = (group_stage_component->getComboNumber());
		number_round_robin = (round_robin_component->getComboNumber());
		number_qualifiers = (qualifiers_component->getComboNumber());
		number_no_of_groups = (no_of_groups_component->getComboNumber());

		// char group[20];
		// int i, j, k;
		// for (i = 0; i < number_no_of_groups; i++)
		// {
		// 	group[i] = (char) (65 + i);
		// }

		// k = 0;
		// for(int j = 0; j < number_no_of_groups; j++)
		// {
		// 	for (i = j; i < number_no_of_groups; i += number_no_of_groups)
		// 	{
		// 		T[i].team_group = group[j];
		// 	}
		// 	k++;
		// }
		
		std::string number_no_of_teams;
		number_no_of_teams = (no_of_teams_component->getFieldText()).toStdString();

		std::cout << "User ID: " << user_id << std::endl;

		std::string clientReq = 
		std::to_string(user_id)
		+ "\n" + league_text
		+ "\n" + std::to_string(number_group_stage) 
		+ "\n" + std::to_string(number_round_robin) 
		+ "\n" + std::to_string(number_qualifiers) 
		+ "\n" + std::to_string(number_no_of_groups)
		+ "\n" + number_no_of_teams;

		std::stringstream clientRes;

		std::string streamLine;
		std::vector<std::string> streamList;

		if(league_text != ""){
			int errorDatabase = updateDatabase(clientReq, "insert_league", clientRes);
			if(errorDatabase!=0){
				std::cout << "\nError initializing database" << std::endl;
			}
			else{
				getline(clientRes, streamLine, '\n');
				QString league_id(streamLine.c_str());
				cout << "League ID: " << league_id.toStdString() << endl;
				std::cout << App->stacked_windows.currentIndex() << std::endl;
				initAddTeam(
					App,
					App->stacked_windows.widget(App->stacked_windows.currentIndex()+1),
					username,
					QString(league_text.c_str()),
					stoi(league_id.toStdString()),
					user_id,
					stoi(number_no_of_teams)
				);
				App->changeWindow_forward();
			}
		}
		else{
			std::cout << "Fields can't be empty" << std::endl;
		}
		});

    sub_widget_layout->addWidget(main_label);
    sub_widget_layout->addWidget(league_name);
    sub_widget_layout->addWidget(no_of_teams);
    sub_widget_layout->addWidget(group_stage);
    sub_widget_layout->addWidget(round_robin);
    sub_widget_layout->addWidget(qualifiers);
    sub_widget_layout->addWidget(no_of_groups);
	sub_widget_layout->addWidget(continue_button_container);

	main_widget_layout->addWidget(NavBar,0,Qt::AlignTop);
	main_widget_layout->addWidget(sub_widget,0, Qt::AlignCenter);

	resetPage(window);

    QVBoxLayout *main_layout = new QVBoxLayout(window);
    main_layout->addWidget(main_widget);
    main_layout->setAlignment(Qt::AlignCenter);
    window->setLayout(main_layout);
}