#include "appUI.h"
#include "db.h"

void initAddLeague(StackedWidgets *App, QWidget* window){
    window->setWindowTitle("Add League");

    QWidget *main_widget = new QWidget(window);
    main_widget->setFixedSize(app_width*3/2, app_height*3/2);
    // main_widget->setStyleSheet("QWidget{background-color:red}");
    QVBoxLayout *main_widget_layout = new QVBoxLayout(main_widget);
    main_widget_layout->setAlignment(Qt::AlignCenter); // Center align the contents

    appText *main_text=new appText();
    main_text->init(window,"ADD LEAGUE");
    QLabel *main_label=main_text->getWidget_label();

    appUI *team_name=new appUI();
    team_name->init(window);
    QWidget *team_name_widget=team_name->getWidget();
    QHBoxLayout *team_name_layout=team_name->getHLayout();

    WidgetComponent *team_name_component=new WidgetComponent();
    team_name_component->init(team_name_widget,"Team Name");
    
    QLabel *team_name_label=team_name_component->getWidget_label();

    QLineEdit *team_name_edit=team_name_component->getWidget_edit();

    team_name_layout->addWidget(team_name_label);
    team_name_layout->addWidget(team_name_edit);
    
    QWidget *group_stage=new QWidget(window);
    group_stage->setFixedHeight(app_height/8);
    QHBoxLayout *group_stage_layout=new QHBoxLayout(group_stage);
    group_stage_layout->setAlignment(Qt::AlignLeft);

    appText *group_text=new appText();
    group_text->init(window,"No. of group stages: ",default_font_size-10);
    QLabel *group_label=group_text->getWidget_label();
    group_label->setFixedWidth(app_width/2);

    QComboBox *combobox=new QComboBox(window);
    combobox->addItems({"1","2","3"});
    group_stage_layout->addWidget(group_label);
    group_stage_layout->addWidget(combobox);

    QWidget *round_robin=new QWidget(window);
    round_robin->setFixedHeight(app_height/8);
    QHBoxLayout *round_robin_layout=new QHBoxLayout(round_robin);
    round_robin_layout->setAlignment(Qt::AlignLeft);
    appText *round_robin_text=new appText();
    round_robin_text->init(window,"Round Robin: ",default_font_size-10);
    QLabel *round_robin_label=round_robin_text->getWidget_label();
    round_robin_label->setFixedWidth(app_width/2);
    QComboBox *round_robin_combobox=new QComboBox(window);
    round_robin_combobox->addItems({"1","2"});
    round_robin_layout->addWidget(round_robin_label);
    round_robin_layout->addWidget(round_robin_combobox); 

    QWidget *qualifiers=new QWidget(window);
    qualifiers->setFixedHeight(app_height/8);
    QHBoxLayout *qualifiers_layout=new QHBoxLayout(qualifiers);
    qualifiers_layout->setAlignment(Qt::AlignLeft);
    appText *qualifiers_text=new appText();
    qualifiers_text->init(window,"Qualifier: ",default_font_size-10);
    QLabel *qualifiers_label=qualifiers_text->getWidget_label();
    qualifiers_label->setFixedWidth(app_width/2);
    QComboBox *qualifiers_combobox=new QComboBox(window);
    qualifiers_combobox->addItems({"1","2","4"});
    qualifiers_layout->addWidget(qualifiers_label);
    qualifiers_layout->addWidget(qualifiers_combobox);

    QWidget *no_of_groups=new QWidget(window);
    no_of_groups->setFixedHeight(app_height/8);
    QHBoxLayout *no_of_groups_layout=new QHBoxLayout(no_of_groups);
    no_of_groups_layout->setAlignment(Qt::AlignLeft);
    appText *no_of_groups_text=new appText();
    no_of_groups_text->init(window,"No of groups: ",default_font_size-10);
    QLabel *no_of_groups_label=no_of_groups_text->getWidget_label();
    no_of_groups_label->setFixedWidth(app_width/2);
    QComboBox *no_of_groups_combobox=new QComboBox(window);
    no_of_groups_combobox->addItems({"1","2","4","8"});
    no_of_groups_layout->addWidget(no_of_groups_label);
    no_of_groups_layout->addWidget(no_of_groups_combobox);

    main_widget_layout->addWidget(main_label);
    main_widget_layout->addWidget(team_name_widget);
    main_widget_layout->addWidget(group_stage);
    main_widget_layout->addWidget(round_robin);
    main_widget_layout->addWidget(qualifiers);
    main_widget_layout->addWidget(no_of_groups);

    QVBoxLayout *main_layout = new QVBoxLayout(window);
    main_layout->addWidget(main_widget);

    main_layout->setAlignment(Qt::AlignCenter);
    window->setLayout(main_layout);
}