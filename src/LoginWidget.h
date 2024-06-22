#pragma once

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>

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