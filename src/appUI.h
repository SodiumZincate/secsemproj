#pragma once

#include <QtCore/QObject>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QSizePolicy>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QScrollArea>
#include <QtGui/QMouseEvent>
#include <QtGui/QPainter>
#include <QtGui/QLinearGradient>
#include <QtGui/QRadialGradient>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFileDialog>
#include <QtCore/QBuffer>
#include <QtCore/QPointer>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QTimeEdit>
#include <iostream>
#include "logic.h"
#include "db.h"

extern int default_font_size;
extern int app_width, app_height, screenWidth, screenHeight;

class appDesign{
public:
    appDesign();
    QPalette app_palette;
    QString app_style_sheet;
};

// Class for stacked widgets to store widgets in a stack
class StackedWidgets : public QObject{
	Q_OBJECT // A QT macro that allows the use of slots
public:
	QWidget mainWidget;
	QHBoxLayout *appLayout;
    QStackedWidget stacked_windows;
	StackedWidgets(){
    	appLayout = new QHBoxLayout(&mainWidget);
		appLayout->addWidget(&stacked_windows);
	}
	void addWidget(QWidget* widget){
		stacked_windows.addWidget(widget);
	}
    // void addtoLayout() {

    // }
    void setCurrentIndex(int index) {
        stacked_windows.setCurrentIndex(index);
	}
	public slots:
		void changeWindow_forward();
		void changeWindow_backward();
		void changeWindow_showLeague();
		void changeWindow_dashboard();
};

class TeamDialogBox : public QDialog{
	Q_OBJECT
public:
    QLineEdit *teamEdit;
    QLineEdit *teamGroundEdit;
    QPushButton *teamButton_widget;
    QPixmap icon;
    QString iconPath;
	QString team_name;
	QString team_ground_name;
	QString file_name;
	bool iconAdded = false;

	TeamDialogBox(QWidget *parent);
	QString getTeamName();
	QString getGroundName();
	QIcon getTeamIcon();
	QString getTeamIconPath();
	
public slots:
	void addIcon();
	void updateEditText();
};

// Functions to initialize Register page
void initRegister(StackedWidgets *App, QWidget* window);
// Functions to initialize Login page
void initLogin(StackedWidgets *App, QWidget* window);

void initDashboard(StackedWidgets *App, QWidget* window, QString username, int user_id);

void initAddLeague(StackedWidgets *App, QWidget* window, QString username, int user_id);

void initAddTeam(
	StackedWidgets *App, 
	QWidget* window, 
	QString username = "username", 
	QString leaguename = "leaguename", 
	int league_id = 0, 
	int user_id = 0, 
	int no_of_teams = 0);

void initShowLeague(StackedWidgets *App, QWidget* window, QString username, QString leaguename, League L);

void initShowMatch(
	StackedWidgets *App, 
	QWidget* window, 
	QString username, 
	QString leaguename, 
	League L);

void initNextMatch(
	StackedWidgets *App, 
	QWidget* window, 
	QString username,
	QString leaguename,
	League L,
	vector<Match> matchVector,
	QList<QIcon> iconList_1,
	QList<QIcon> iconList_2);

void resetPage(QWidget* window);

void deleteAllWidgetsAndLayouts(QWidget* widget);

void deleteAllWidgetsAndLayouts(QLayout* layout);

// Main class for the widgets in the app
// (Username, Email, Password) widgets
class appUI {
private:
    QWidget *app_widget;
    QHBoxLayout *app_layout;
public:
    void init(QWidget*);
    QWidget* getWidget();
    QHBoxLayout* getHLayout();
};

// Class for Head Text and other miscellanous text in the app
class appText {
private:
    QLabel* app_text;
public:
    void init(QWidget*, QString, int font_size = default_font_size);
    QLabel* getWidget_label();
};

// Class for buttons in the app
class appButton{
public:
    QPushButton* button_widget;
    void init(QWidget*, QString, int font_size = default_font_size);
    QPushButton* getWidget_button();
};

class appClickableText : public QLabel{
	Q_OBJECT
public:
	void init(QWidget*, QString, int font_size = default_font_size);
	void mousePressEvent(QMouseEvent* event) override;

signals:
	void clicked();
};

class MatchWidget : public QWidget {
    Q_OBJECT

public:
    MatchWidget(QWidget* parent = nullptr);
    void init(const QString& matchNumber, 
			  const QString& team1Name, const QIcon& team1Icon, QString team1Score,
              const QString& team2Name, const QIcon& team2Icon, QString team2Score,
			  const QString& matchGround);

    QLabel* matchNumberLabel;
    QLabel* matchGroundLabel;
    QLabel* matchTimeLabel;
    QLabel* team1NameLabel;
    QLabel* team1IconLabel;
    QLabel* team1ScoreLabel;
    QLabel* team2NameLabel;
    QLabel* team2IconLabel;
    QLabel* team2ScoreLabel;

	QLineEdit *team1ScoreInput;
    QLineEdit *team2ScoreInput;
};

class EditableMatchWidget : public MatchWidget {
    Q_OBJECT

public:
    EditableMatchWidget(QWidget* parent = nullptr);
};

// Sub class for the individual input field widgets in the app
// each object of this class represents a text label and its input field
class LabelEditComponent : public QObject {
    Q_OBJECT // A QT macro that allows the use of slots
private:
    QLabel *widget_label;
    QLineEdit *widget_edit;
public:
	QString field_text;
    void init(QWidget*, QString, int font_size = default_font_size);
    QLabel* getWidget_label();
    QLineEdit* getWidget_edit();
	QString getFieldText();
	void togglePasswordVisibility(QPushButton*);
    bool checkSamePassword(LabelEditComponent* password_component);
	void usernameExists(bool userExists);
public slots:
	void updateEditText();
	void deleteEditText();
};

// Sub class for the individual input field widgets in the app
// each object of this class represents a text label and its combobox i.e dropdown
class LabelComboComponent : public QObject {
    Q_OBJECT // A QT macro that allows the use of slots
private:
    QLabel *widget_label;
    QComboBox *widget_combobox;
	int combo_number;
public:
    void init(QWidget*, QString, QStringList, int font_size = default_font_size);
	int getComboNumber();
    QLabel* getWidget_label();
    QComboBox* getWidget_combo();
};