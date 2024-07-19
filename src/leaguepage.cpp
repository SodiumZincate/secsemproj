#include "appUI.h"
#include "db.h"

void initShowLeague(StackedWidgets *App, QWidget* window, QString username = "username", QString leaguename = "leaguename"){
    window->setWindowTitle("League Name");

    QWidget *main_widget = new QWidget(window);
    main_widget->setFixedSize(app_width*3/2, app_height*3/2);
    // main_widget->setStyleSheet("QWidget{background-color:blue}");
    QVBoxLayout *main_widget_layout = new QVBoxLayout(main_widget);
    main_widget_layout->setAlignment(Qt::AlignCenter); // Center align the contents

    QWidget *sub_widget = new QWidget(window);
    sub_widget->setFixedSize(app_width*3/2, app_height*3/2);
    // sub_widget->setStyleSheet("QWidget{background-color:red}");
    QVBoxLayout *sub_widget_layout = new QVBoxLayout(sub_widget);
    sub_widget_layout->setAlignment(Qt::AlignTop);

	//NavBar
    QWidget *NavBar = new QWidget(window);
    NavBar->setFixedSize(app_width*3/2, app_height/6);
	// NavBar->setStyleSheet("QWidget{background-color:yellow}");
    QHBoxLayout *NavBar_layout = new QHBoxLayout(NavBar);
    NavBar_layout->setAlignment(Qt::AlignTop);

	//Username text
    appText *usernameText = new appText();
    usernameText ->init(window, username ,default_font_size-3);
    QLabel *usernameText_widget=usernameText->getWidget_label();
    usernameText_widget->setAlignment(Qt::AlignRight);
    usernameText_widget->setFixedHeight(app_height/4);

	//League Name Text
	appText *leaguenameText = new appText();
    leaguenameText ->init(window, leaguename ,default_font_size+10);
    QLabel *leaguenameText_widget = leaguenameText->getWidget_label();
    leaguenameText_widget->setAlignment(Qt::AlignCenter);
    leaguenameText_widget->setFixedHeight(app_height/6);

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
	NavBar_layout->addWidget(leaguenameText_widget);
	NavBar_layout->addWidget(usernameText_widget);

	// Table
	QTableWidget *league_table = new QTableWidget(10, 9, window);
	league_table->setWindowTitle("QTableWidget Example");
    // league_table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    league_table->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    // league_table->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
	league_table->setMinimumSize(app_width*5/4, app_height*5/4);
	league_table->setColumnWidth(0, app_width/3);

	QSize icon_size(app_width/league_table->rowCount()/2, app_width/league_table->rowCount()/2);
	league_table->setIconSize(icon_size);

	for (int i = 0; i < league_table->columnCount(); i++) {
        if (i == 0) {
            league_table->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Fixed);
        } else {
            league_table->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);
        }
    }
	for (int i = 0; i < league_table->rowCount(); i++) {
		league_table->setRowHeight(i, app_height/8);
    }

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

	league_table->setHorizontalHeaderLabels(header_label_list);
	for (int i = 0; i < league_table->rowCount(); i++) {
		QTableWidgetItem *table_item = new QTableWidgetItem(QIcon("requisite/assets/images/real_madrid"), "Real Madrid", 0);
		table_item->setFlags(table_item->flags() & ~Qt::ItemIsEditable);
		league_table->setItem(i, 0, table_item);
    }
	
	for(int row=0; row < league_table->rowCount(); row++){
		for(int col=1; col < league_table->columnCount(); col++){
			QIcon *table_icon = new QIcon("requisite/assets/images/real_madrid");
			QTableWidgetItem *table_item = new QTableWidgetItem("0", 0);
			table_item->setFlags(table_item->flags() & ~Qt::ItemIsEditable);
			table_item->setSizeHint(icon_size);
			league_table->setItem(row, col, table_item);
		}
	}

	QObject::connect(backButton_widget, &QPushButton::clicked, App, &StackedWidgets::changeWindow_backward);

	resetPage(window);

	sub_widget_layout->addWidget(league_table, 0, Qt::AlignCenter);

    main_widget_layout->addWidget(NavBar, 0, Qt::AlignTop);
    main_widget_layout->addWidget(sub_widget, 1, Qt::AlignCenter | Qt::AlignTop);

    QVBoxLayout *main_layout = new QVBoxLayout(window);
    main_layout->addWidget(main_widget);
    main_layout->setAlignment(Qt::AlignCenter);
    window->setLayout(main_layout);
}