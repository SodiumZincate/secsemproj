#include "appUI.h"
#include "db.h"

void initShowLeague(StackedWidgets *App, QWidget* window, QString username = "username", QString leaguename = "leaguename") {
    window->setWindowTitle("League Name");

    QWidget *main_widget = new QWidget(window);
    main_widget->setFixedSize(app_width*3/2, app_height*3/2); // Fixed size for main_widget
    QVBoxLayout *main_widget_layout = new QVBoxLayout(main_widget);
    main_widget_layout->setAlignment(Qt::AlignCenter); // Center align the contents
    main_widget_layout->setContentsMargins(0, 0, 0, 0); // Remove margins

    QWidget *sub_widget = new QWidget(window);
    QVBoxLayout *sub_widget_layout = new QVBoxLayout(sub_widget);
    sub_widget_layout->setAlignment(Qt::AlignTop); // Align content to the top
    sub_widget_layout->setContentsMargins(0, 0, 0, 0); // Remove margins

    // NavBar
    QWidget *NavBar = new QWidget(window);
    NavBar->setFixedSize(app_width*3/2, app_height/6);
    QHBoxLayout *NavBar_layout = new QHBoxLayout(NavBar);
    NavBar_layout->setAlignment(Qt::AlignTop);

    // Username text
    appText *usernameText = new appText();
    usernameText->init(window, username, default_font_size*0.9);
    QLabel *usernameText_widget = usernameText->getWidget_label();
    usernameText_widget->setAlignment(Qt::AlignRight);
    usernameText_widget->setFixedHeight(app_height/4);

    // League Name Text
    appText *leaguenameText = new appText();
    leaguenameText->init(window, leaguename, default_font_size*1.2);
    QLabel *leaguenameText_widget = leaguenameText->getWidget_label();
    leaguenameText_widget->setAlignment(Qt::AlignCenter);
    leaguenameText_widget->setFixedHeight(app_height/6);

    // Back Button
    appButton *backButton = new appButton();
    backButton->init(window, "BACK", default_font_size*0.9);
    QPushButton *backButton_widget = backButton->getWidget_button();
    backButton_widget->setFixedSize(app_width/8, app_height/12);

    // Back button Container
    QWidget *backButton_container = new QWidget(window);
    QHBoxLayout *backButton_container_layout = new QHBoxLayout(backButton_container);
    backButton_container->setFixedHeight(app_height/6);
    backButton_container_layout->setAlignment(Qt::AlignLeft);
    backButton_container_layout->setContentsMargins(0, 0, 0, 0);
    backButton_container_layout->addWidget(backButton_widget);

    NavBar_layout->addWidget(backButton_container);
    NavBar_layout->addWidget(leaguenameText_widget);
    NavBar_layout->addWidget(usernameText_widget);

    // Scroll Area
    QScrollArea *scroll_area = new QScrollArea(window);
    scroll_area->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scroll_area->setWidgetResizable(true); // Ensure the scroll area resizes properly

    // Add tables to the sub-widget layout
    for (int i = 0; i < 4; i++) {
        QTableWidget *league_table = new QTableWidget(8, 9, window);
        league_table->setMinimumSize(app_width*3/2, app_height*5/4); // Set minimum size
        league_table->setColumnWidth(0, app_width/3);

        QScrollBar *scroll_bar = new QScrollBar();
        league_table->setVerticalScrollBar(scroll_bar);

        QSize icon_size(app_width/16, app_height/16);
        league_table->setIconSize(icon_size);

        QStringList header_label_list = {
            "Team Name", "MP", "W", "D", "L", "GF", "GA", "GD", "Pts"
        };

        QStringList icons;
        QStringList team_names = {
            "Atletic Club", "Atletico Madrid", "Barcelona", "Girona", "Real Betis",
            "Real Madrid", "Real Sociedad", "Sevilla"
        };

        for (const auto& entry : team_names) {
            QString logo_dir = "requisite/assets/images/logo/" + entry + ".png";
            icons.push_back(logo_dir);
        }

        league_table->setHorizontalHeaderLabels(header_label_list);
        for (int j = 0; j < league_table->rowCount(); j++) {
            QPixmap pixmap(icons[j]);
            QIcon icon(pixmap.scaled(800, 800, Qt::KeepAspectRatio, Qt::SmoothTransformation));
            QTableWidgetItem *table_item = new QTableWidgetItem(icon, team_names[j]);
            table_item->setFlags(table_item->flags() & ~Qt::ItemIsEditable);
            league_table->setItem(j, 0, table_item);
        }

        for (int j = 0; j < league_table->columnCount(); j++) {
            if (j == 0) {
                league_table->horizontalHeader()->setSectionResizeMode(j, QHeaderView::Fixed);
            } else {
                league_table->horizontalHeader()->setSectionResizeMode(j, QHeaderView::Stretch);
            }
        }

        if (league_table->rowCount() <= 4) {
            league_table->setMinimumSize(app_width*5/4, app_height*5/10); // Adjust minimum size
            league_table->setIconSize(QSize(app_width/14, app_height/14));
        } else if (league_table->rowCount() <= 8) {
            league_table->setMinimumSize(app_width*5/4, app_height*5/6); // Adjust minimum size
            league_table->setIconSize(QSize(app_width/16, app_height/16));
        }

        if (league_table->rowCount() < 12) {
            league_table->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        } else {
            for (int j = 0; j < league_table->rowCount(); j++) {
                league_table->setRowHeight(j, app_height/10);
                league_table->verticalHeader()->setSectionResizeMode(j, QHeaderView::Fixed); // Set resize mode for rows
            }
        }

        sub_widget_layout->addWidget(league_table); // Add table to layout
    }

    QObject::connect(backButton_widget, &QPushButton::clicked, App, &StackedWidgets::changeWindow_backward);

    scroll_area->setWidget(sub_widget); // Set sub_widget as the widget for the scroll area

    main_widget_layout->addWidget(NavBar); // Add NavBar to main layout
    main_widget_layout->addWidget(scroll_area); // Add scroll area to main layout

    QVBoxLayout *main_layout = new QVBoxLayout(window);
    main_layout->addWidget(main_widget);
    main_layout->setAlignment(Qt::AlignCenter);
    window->setLayout(main_layout);
}