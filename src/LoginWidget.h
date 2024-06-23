#pragma once

#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QHBoxLayout>

class LoginWidget{
    private:
        QWidget *login_widget;
        QHBoxLayout *login_layout;
    public:
        void init(QWidget*);
        QWidget* getWidget();
        QHBoxLayout* getHLayout();
};

class LoginHead{
    private:
        QLabel* login_text;
    public:
        void init(QWidget*);
        QLabel* getWidget_label();
};

class LoginFoot{
    private:
        QPushButton* button_widget;
        QHBoxLayout* button_layout;
    public:
        void init(QWidget*);
        QPushButton* getWidget_button();
};

class WidgetComponent{
    private:
        QLabel *widget_label;
        QLineEdit *widget_edit;
    public:
        void init(QWidget*, QString);
        QLabel* getWidget_label();
        QLineEdit* getWidget_edit();
};