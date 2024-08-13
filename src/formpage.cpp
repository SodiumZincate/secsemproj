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
    // sub_widget->setFixedSize(app_width*3/2, app_height*3/2);
    // sub_widget->setStyleSheet("QWidget{background-color:red}");
	// sub_widget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
    QVBoxLayout *sub_widget_layout = new QVBoxLayout(sub_widget);
    sub_widget_layout->setAlignment(Qt::AlignCenter);

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
	NavBar_layout->addWidget(main_label);
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

	QIntValidator* validator = new QIntValidator(0, 200, window);
	no_of_teams_edit->setValidator(validator);

    no_of_teams_layout->addWidget(no_of_teams_label);
    no_of_teams_layout->addWidget(no_of_teams_edit);

	//
	QWidget *calendarContainer = new QWidget(window);
	QHBoxLayout *calendarContainer_layout = new QHBoxLayout(calendarContainer);
	calendarContainer_layout->setAlignment(Qt::AlignLeft);
	calendarContainer_layout->setSpacing(app_width/8);

	appText *match_date_text = new appText();
	match_date_text->init(window, "Starting Date:", default_font_size*0.64);
	QLabel *match_date_label = new QLabel();
	match_date_label->setFixedSize(app_width/3, app_height/4);
	match_date_label = match_date_text->getWidget_label();
	match_date_label->setMargin(0);

	QCalendarWidget *match_date = new QCalendarWidget(window);
	match_date->setMinimumDate(QDate::currentDate()); 
	match_date->setFont(QFont("Sans", default_font_size*0.4));
	match_date->setFixedSize(QSize(app_width*63/100, app_height / 3));
	match_date->setVerticalHeaderFormat(QCalendarWidget::VerticalHeaderFormat::NoVerticalHeader);

	calendarContainer_layout->addWidget(match_date_label);
	calendarContainer_layout->addWidget(match_date);

	//
	QWidget *no_of_match_time=new QWidget(window);
	// group_stage->setStyleSheet("QWidget{background-color:red}");
    no_of_match_time->setFixedHeight(app_height/8);
    QHBoxLayout *no_of_match_time_layout=new QHBoxLayout(no_of_match_time);
    no_of_match_time_layout->setAlignment(Qt::AlignLeft);

	LabelComboComponent *no_of_match_time_component = new LabelComboComponent();
	no_of_match_time_component->init(window, "No. of Match Times: ", {"1","2","3","4"}, default_font_size*0.8);
    QLabel *no_of_match_time_label = no_of_match_time_component->getWidget_label();
    QComboBox *no_of_match_time_edit = no_of_match_time_component->getWidget_combo();
	
    no_of_match_time_layout->addWidget(no_of_match_time_label);
    no_of_match_time_layout->addWidget(no_of_match_time_edit);

	QWidget *timeLabelContainer = new QWidget(window);
	QHBoxLayout *timeLabelContainer_layout = new QHBoxLayout(timeLabelContainer);
	timeLabelContainer_layout->setAlignment(Qt::AlignLeft);
	timeLabelContainer_layout->setSpacing(app_width/8);

	//
	QWidget *timeContainer = new QWidget(window);
	QVBoxLayout *timeContainer_layout = new QVBoxLayout(timeContainer);
	timeContainer_layout->setSpacing(app_height/16);

	appText *match_time_text = new appText();
	match_time_text->init(window, "Match Times (Select from top):", default_font_size*0.64);
	QLabel *match_time_label = new QLabel();
	match_time_label->setFixedSize(app_width/3, app_height/4);
	match_time_label = match_time_text->getWidget_label();
	match_time_label->setMargin(0);

	//
	QTimeEdit *match_time1 = new QTimeEdit();
	match_time1->setFont(QFont("Sans", default_font_size*0.64));
	match_time1->setFixedSize(QSize(app_width/4, app_height / 10));
	match_time1->setDisplayFormat("HH:mm");
	match_time1->setAlignment(Qt::AlignCenter);
	//
	QTimeEdit *match_time2 = new QTimeEdit();
	match_time2->setFont(QFont("Sans", default_font_size*0.64));
	match_time2->setFixedSize(QSize(app_width/4, app_height / 10));
	match_time2->setDisplayFormat("HH:mm");
	match_time2->setAlignment(Qt::AlignCenter);
	//
	QTimeEdit *match_time3 = new QTimeEdit();
	match_time3->setFont(QFont("Sans", default_font_size*0.64));
	match_time3->setFixedSize(QSize(app_width/4, app_height / 10));
	match_time3->setDisplayFormat("HH:mm");
	match_time3->setAlignment(Qt::AlignCenter);
	//
	QTimeEdit *match_time4 = new QTimeEdit();
	match_time4->setFont(QFont("Sans", default_font_size*0.64));
	match_time4->setFixedSize(QSize(app_width/4, app_height / 10));
	match_time4->setDisplayFormat("HH:mm");
	match_time4->setAlignment(Qt::AlignCenter);

	timeContainer_layout->addWidget(match_time1);
	timeContainer_layout->addWidget(match_time2);
	timeContainer_layout->addWidget(match_time3);
	timeContainer_layout->addWidget(match_time4);

	timeLabelContainer_layout->addWidget(match_time_label);
	timeLabelContainer_layout->addWidget(timeContainer);

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
    continue_button->init(window, "Continue", default_font_size*1.2);
    QPushButton *continue_button_widget = continue_button->getWidget_button();
	

	//  Submit Button Container Widget (Made so the Submit Button Widget could be centered as a Widget)
    QWidget *continue_button_container = new QWidget(window);
    QHBoxLayout *continue_button_container_layout = new QHBoxLayout(continue_button_container);
    continue_button_container_layout->setAlignment(Qt::AlignCenter);
    continue_button_container_layout->setContentsMargins(0, app_height / 8, 0, 0);
	continue_button_container_layout->addWidget(continue_button_widget);
	// calendarContainer_layout->addWidget(continue_button_widget);

	QObject::connect(backButton_widget, &QPushButton::clicked, App , &StackedWidgets::changeWindow_backward);

	QObject::connect(continue_button_widget, &QPushButton::clicked, league_name_component, &LabelEditComponent::updateEditText);
	QObject::connect(continue_button_widget, &QPushButton::clicked, no_of_teams_component, &LabelEditComponent::updateEditText);
	
	QObject::connect(continue_button_widget, &QPushButton::clicked, 
	[=]() {
		std::string league_text;
		league_text = (league_name_component->getFieldText()).toStdString();

		int number_round_robin, number_qualifiers, number_no_of_groups, number_no_of_match_times;

		number_round_robin = (round_robin_component->getComboNumber());
		number_qualifiers = (qualifiers_component->getComboNumber());
		number_no_of_groups = (no_of_groups_component->getComboNumber());
		number_no_of_match_times = (no_of_match_time_component->getComboNumber());

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

		bool number_of_teams_valid = false;
		if(number_no_of_teams != ""){
			if(stoi(number_no_of_teams)/number_no_of_groups <= number_qualifiers){
				no_of_teams_component->deleteEditText();
				no_of_teams_edit->setPlaceholderText("Invalid number of qualifiers and teams per group");
				no_of_teams_edit->setStyleSheet("QLineEdit { placeholder-text-color: #FB3B3B }");
			}
			if(stoi(number_no_of_teams)/number_no_of_groups <= 1){
				no_of_teams_component->deleteEditText();
				no_of_teams_edit->setPlaceholderText("Invalid number of groups and teams");
				no_of_teams_edit->setStyleSheet("QLineEdit { placeholder-text-color: #FB3B3B }");
			}
			if(no_of_teams_component->field_text != ""){
				number_of_teams_valid = true;
			}
		}
		else{
			std::cout << "Fields can't be empty" << std::endl;
		}

		std::cout << "User ID: " << user_id << std::endl;

		std::string timeString;
		timeString = 
		match_time1->time().toString().toStdString()
		+ "\t" + match_time2->time().toString().toStdString()
		+ "\t" + match_time3->time().toString().toStdString()
		+ "\t" + match_time4->time().toString().toStdString();

		std::string clientReq = 
		std::to_string(user_id)
		+ "\n" + league_text
		+ "\n" + std::to_string(number_round_robin) 
		+ "\n" + std::to_string(number_qualifiers) 
		+ "\n" + std::to_string(number_no_of_groups)
		+ "\n" + number_no_of_teams
		+ "\n" + match_date->selectedDate().toString().toStdString()
		+ "\n" + std::to_string(number_no_of_match_times)
		+ "\n" + timeString;

		std::stringstream clientRes;

		std::string streamLine;
		std::vector<std::string> streamList;

		if(league_text != "" && number_of_teams_valid){
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

	// Scroll Area
	QScrollArea *scroll_area = new QScrollArea(window);

	scroll_area->setStyleSheet("QScrollArea { border: none; }");
	scroll_area->setFixedWidth(app_width*3/2);
	scroll_area->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	scroll_area->setWidgetResizable(true);
    scroll_area->setWidget(sub_widget);

    sub_widget_layout->addWidget(league_name, 0, Qt::AlignCenter);
    sub_widget_layout->addWidget(no_of_teams, 0, Qt::AlignCenter);
    sub_widget_layout->addWidget(round_robin, 0, Qt::AlignCenter);
    sub_widget_layout->addWidget(qualifiers, 0, Qt::AlignCenter);
    sub_widget_layout->addWidget(no_of_groups, 0, Qt::AlignCenter);
	sub_widget_layout->addWidget(calendarContainer, 0, Qt::AlignCenter);

    sub_widget_layout->addWidget(no_of_match_time, 0, Qt::AlignCenter);
	sub_widget_layout->addWidget(timeLabelContainer, 0, Qt::AlignCenter);

	main_widget_layout->addWidget(NavBar,0,Qt::AlignTop);
	main_widget_layout->addWidget(scroll_area);
	main_widget_layout->addWidget(continue_button_widget, 0, Qt::AlignCenter | Qt::AlignBottom);

	resetPage(window);

    QVBoxLayout *main_layout = new QVBoxLayout(window);
    main_layout->addWidget(main_widget);
    main_layout->setAlignment(Qt::AlignCenter);
    window->setLayout(main_layout);
}