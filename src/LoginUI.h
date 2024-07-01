#pragma once

#include <QtCore/QObject>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QStackedWidget>
#include <iostream>

extern int default_font_size;
extern int app_width, app_height, screenWidth, screenHeight;

class StackedWidgets : public QObject{
	Q_OBJECT
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

void initLogin(StackedWidgets *App, QWidget* window);
void initRegister(StackedWidgets *App, QWidget* window);

class LoginUI {
private:
    QWidget *login_widget;
    QHBoxLayout *login_layout;
public:
    void init(QWidget*);
    QWidget* getWidget();
    QHBoxLayout* getHLayout();
};

class LoginText{
private:
    QLabel* login_text;
public:
    void init(QWidget*, QString, int font_size = default_font_size);
    QLabel* getWidget_label();
};

class LoginButton{
public:
    QPushButton* button_widget;
    void init(QWidget*, QString, int font_size = default_font_size);
    QPushButton* getWidget_button();
};

class WidgetComponent : public QObject {
    Q_OBJECT
private:
	QString field_text;
    QLabel *widget_label;
    QLineEdit *widget_edit;
public:
    void init(QWidget*, QString);
    QLabel* getWidget_label();
    QLineEdit* getWidget_edit();
	QString getEditText();
public slots:
    void updateEditText();
};