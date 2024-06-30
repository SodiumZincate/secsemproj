#pragma once

#include <QtCore/QObject>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QHBoxLayout>

extern int default_font_size;
extern int app_width, app_height, screenWidth, screenHeight;

void initLogin(QWidget* window);
void initRegister(QWidget* window);

class LoginUI {
private:
    QWidget *login_widget;
    QHBoxLayout *login_layout;
public:
    void init(QWidget*);
    QWidget* getWidget();
    QHBoxLayout* getHLayout();
};

class LoginText : public QObject{
	Q_OBJECT
private:
    QLabel* login_text;
public:
    void init(QWidget*, QString, int font_size = default_font_size);
    QLabel* getWidget_label();
// public slots:
// 	void changeText();
};

class LoginButton : public QObject{
	Q_OBJECT
public:
    QPushButton* button_widget;
    void init(QWidget*, QString, int font_size = default_font_size);
    QPushButton* getWidget_button();
// public slots:
// 	void changeMode();
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