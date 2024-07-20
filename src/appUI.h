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
#include <iostream>

extern int default_font_size;
extern int app_width, app_height, screenWidth, screenHeight;

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
};

// Functions to initialize Register page
void initRegister(StackedWidgets *App, QWidget* window);
// Functions to initialize Login page
void initLogin(StackedWidgets *App, QWidget* window);

void initDashboard(StackedWidgets *App, QWidget* window, QString username);

void initAddLeague(StackedWidgets *App, QWidget* window, QString username);

void initShowLeague(StackedWidgets *App, QWidget* window, QString username, QString leaguename);

void resetPage(QWidget* window);

// Main class for the widgets in login/Register page
// (Username, Email, Password) widgets
class appUI {
private:
    QWidget *login_widget;
    QHBoxLayout *login_layout;
public:
    void init(QWidget*);
    QWidget* getWidget();
    QHBoxLayout* getHLayout();
};

// Class for Head Text and other miscellanous text in login/Register page
class appText {
private:
    QLabel* login_text;
public:
    void init(QWidget*, QString, int font_size = default_font_size);
    QLabel* getWidget_label();
};

// Class for buttons in login/Register page
class appButton{
public:
    QPushButton* button_widget;
    void init(QWidget*, QString, int font_size = default_font_size);
    QPushButton* getWidget_button();
};

// Sub class for the individual input field widgets in login/Register page
// each object of this class represents a text label and its input field
class LabelEditComponent : public QObject {
    Q_OBJECT // A QT macro that allows the use of slots
private:
	QString field_text;
    QLabel *widget_label;
    QLineEdit *widget_edit;
public:
    void init(QWidget*, QString);
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

class LabelComboComponent : public QObject {
    Q_OBJECT // A QT macro that allows the use of slots
private:
    QLabel *widget_label;
    QComboBox *widget_combobox;
public:
    void init(QWidget*, QString, QStringList, int font_size = default_font_size);
    QLabel* getWidget_label();
    QComboBox* getWidget_combo();
};