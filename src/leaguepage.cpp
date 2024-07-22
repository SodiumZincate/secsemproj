#include "appUI.h"
#include "db.h"
#include "logic.h"

void initShowLeague(StackedWidgets *App, QWidget* window, QString username = "username", QString leaguename = "leaguename"){
    window->setWindowTitle("League Name");

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

	// // Table
	// QTableWidget *league_table = new QTableWidget(8, 9, window);
	// // league_table->setWindowTitle("QTableWidget Example");
    // // league_table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    // // league_table->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    // // league_table->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
	// league_table->setMinimumSize(app_width*5/4, app_height*5/4);
	// league_table->setColumnWidth(0, app_width/3);

	// QScrollBar *scroll_bar = new QScrollBar();
	// league_table->setVerticalScrollBar(scroll_bar);

	// // QSize icon_size(app_width/league_table->rowCount()/2, app_width/league_table->rowCount()/2);
	// QSize icon_size(app_width/16, app_height/16);
	// league_table->setIconSize(icon_size);

	// Scroll Area
	QScrollArea *scroll_area = new QScrollArea(window);

	scroll_area->setStyleSheet("QScrollArea { border: none; }");
	scroll_area->setFixedWidth(app_width*3/2);
	scroll_area->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	scroll_area->setWidgetResizable(true);

	for(int i=0; i<4; i++){
		// Label
		appText *group_name = new appText();
		group_name->init(window, QString((std::string("GROUP: ") + std::to_string(i+1)).c_str()), default_font_size*0.8);
		QLabel *group_label = group_name->getWidget_label();

		// Table
		QTableWidget *league_table = new QTableWidget(8, 9, window);
		// league_table->setWindowTitle("QTableWidget Example");
		// league_table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
		// league_table->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
		// league_table->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
		league_table->setMinimumSize(app_width*3/2, app_height*5/4);
		league_table->setColumnWidth(0, app_width*0.4);

		// QScrollBar *scroll_bar = new QScrollBar();
		// league_table->setVerticalScrollBar(scroll_bar);

		// QSize icon_size(app_width/league_table->rowCount()/2, app_width/league_table->rowCount()/2);
		QSize icon_size(app_width/16, app_height/16);
		league_table->setIconSize(icon_size);

		QStringList header_label_list = {
			"Team Name",
			"MP",
			"W",
			"D",
			"L",
			"GF",
			"GA",
			"GD",
			"Pts",
		};

		QStringList icons;

		QStringList team_names = {
			"Atletic Club",
			"Atletico Madrid",
			"Barcelona",
			"Girona",
			"Real Betis",
			"Real Madrid",
			"Real Sociedad",
			"Sevilla",
		};

		// for(const auto& entry : std::filesystem::directory_iterator("requisite/assets/images/logo")){
		// 	std::string logo_name = entry.path().filename().string();
		// 	std::string logo_dir = "requisite/assets/images/logo/" + logo_name;
		// 	std::cout << logo_dir << std::endl;
		// 	icons.push_back(QString(logo_dir.c_str()));
		// 	icons.push_back(QString(logo_dir.c_str()));
		// }
		for(const auto& entry : team_names){
			std::string logo_dir = "requisite/assets/images/logo/" + entry.toStdString() + ".png";
			// std::cout << logo_dir << std::endl;
			icons.push_back(QString(logo_dir.c_str()));
		}

		league_table->setHorizontalHeaderLabels(header_label_list);
        league_table->horizontalHeader()->setFont(QFont("Sans", default_font_size*0.6));
        league_table->verticalHeader()->setFont(QFont("Sans", default_font_size*0.6));

		for (int j = 0; j < league_table->rowCount(); j++) {
			QPixmap pixmap(icons[j]);
			QIcon icon(pixmap.scaled(800, 800, Qt::KeepAspectRatio, Qt::SmoothTransformation));
			QTableWidgetItem *table_item = new QTableWidgetItem(icon, team_names[j], 0);
            table_item->setFont(QFont("Sans", default_font_size*0.8));
			table_item->setFlags(table_item->flags() & ~Qt::ItemIsEditable);
			league_table->setItem(j, 0, table_item);
		}

		for (int j = 0; j < league_table->rowCount(); j++) {
            for(int k = 1; k < league_table->columnCount(); k++){
                QTableWidgetItem *table_item = new QTableWidgetItem("12", 0);
                table_item->setFont(QFont("Sans", default_font_size*0.6));
                table_item->setTextAlignment(Qt::AlignCenter);
                table_item->setFlags(table_item->flags() & ~Qt::ItemIsEditable);
                league_table->setItem(j, k, table_item);
            }
		}
		
		for (int j = 0; j < league_table->columnCount(); j++) {
			if (j == 0) { 
				league_table->horizontalHeader()->setSectionResizeMode(j, QHeaderView::Fixed);
			} else {
				league_table->horizontalHeader()->setSectionResizeMode(j, QHeaderView::Stretch);
			}
		}
		if(league_table->rowCount()<=4){
			league_table->setMinimumSize(app_width*5/4, app_height/2);
			league_table->setIconSize(QSize(app_width/14, app_height/14));
		}
		else if(league_table->rowCount()<=8){
			league_table->setMinimumSize(app_width*5/4, app_height*5/6);
			league_table->setIconSize(QSize(app_width/16, app_height/16));
		}
		if(league_table->rowCount()<12){
			league_table->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
		}
		else{
            league_table->verticalHeader()->setMinimumSectionSize(app_height/10);
			for (int j = 0; j < league_table->rowCount(); j++) {
				league_table->verticalHeader()->setSectionResizeMode(j, QHeaderView::Fixed);
			}
		}
		sub_widget_layout->addWidget(group_label);
		sub_widget_layout->addWidget(league_table);
	}

	QObject::connect(backButton_widget, &QPushButton::clicked, App, &StackedWidgets::changeWindow_backward);


    scroll_area->setWidget(sub_widget);

    main_widget_layout->addWidget(NavBar, 0, Qt::AlignTop);
    main_widget_layout->addWidget(scroll_area);

	resetPage(window);
	
    QVBoxLayout *main_layout = new QVBoxLayout(window);
    main_layout->addWidget(main_widget);
    main_layout->setAlignment(Qt::AlignCenter);
    window->setLayout(main_layout);
}