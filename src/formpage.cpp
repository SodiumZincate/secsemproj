#include "appUI.h"
#include "db.h"

void initAddLeague(StackedWidgets *App, QWidget* window){
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
    usernameText ->init(window, "username" ,default_font_size-3);
    QLabel *usernameText_widget=usernameText->getWidget_label();
    usernameText_widget->setAlignment(Qt::AlignRight);
    usernameText_widget->setFixedHeight(app_height/4);

	//Back Button
    appButton *backButton= new appButton();
    backButton->init(window,"BACK",default_font_size-2);
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
	league_name_edit->setFixedSize(app_width*72/100, app_height/10);

    league_name_layout->addWidget(league_name_label);
    league_name_layout->addWidget(league_name_edit);
    
	//
    QWidget *group_stage=new QWidget(window);
	// group_stage->setStyleSheet("QWidget{background-color:red}");
    group_stage->setFixedHeight(app_height/8);
    QHBoxLayout *group_stage_layout=new QHBoxLayout(group_stage);
    group_stage_layout->setAlignment(Qt::AlignLeft);

	LabelComboComponent *group_stage_component = new LabelComboComponent();
	group_stage_component->init(window, "No. of Group Stages: ", {"0","1","2"}, default_font_size-10);
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
	round_robin_component->init(window, "Round Robin: ", {"1","2"}, default_font_size-10);
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
	qualifiers_component->init(window, "Qualifiers: ", {"1","2","4"}, default_font_size-10);
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
	no_of_groups_component->init(window, "No of groups: ", {"1","2","4","8"}, default_font_size-10);
    QLabel *no_of_groups_label = no_of_groups_component->getWidget_label();
    QComboBox *no_of_groups_combobox = no_of_groups_component->getWidget_combo();

    no_of_groups_layout->addWidget(no_of_groups_label);
    no_of_groups_layout->addWidget(no_of_groups_combobox);

    sub_widget_layout->addWidget(main_label);
    sub_widget_layout->addWidget(league_name);
    sub_widget_layout->addWidget(group_stage);
    sub_widget_layout->addWidget(round_robin);
    sub_widget_layout->addWidget(qualifiers);
    sub_widget_layout->addWidget(no_of_groups);

	main_widget_layout->addWidget(NavBar,0,Qt::AlignTop);
	main_widget_layout->addWidget(sub_widget,0, Qt::AlignCenter);

	QObject::connect(backButton_widget, &QPushButton::clicked, App, &StackedWidgets::changeWindow_backward);

    QVBoxLayout *main_layout = new QVBoxLayout(window);
    main_layout->addWidget(main_widget);

    main_layout->setAlignment(Qt::AlignCenter);
    window->setLayout(main_layout);
}