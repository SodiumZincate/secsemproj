#pragma once

#include <QtCore/QObject>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QHBoxLayout>

class LoginUI {
private:
    QWidget *login_widget;
    QHBoxLayout *login_layout;
public:
    void init(QWidget*);
    QWidget* getWidget();
    QHBoxLayout* getHLayout();
};

class LoginHead {
private:
    QLabel* login_text;
public:
    void init(QWidget*);
    QLabel* getWidget_label();
};

class LoginFoot {
private:
    QPushButton* button_widget;
public:
    void init(QWidget*);
    QPushButton* getWidget_button();
};

class WidgetComponent : public QObject {
    Q_OBJECT
private:
    QLabel *widget_label;
    QLineEdit *widget_edit;
public:
    explicit WidgetComponent(QObject *parent = nullptr);
    void init(QWidget*, QString);
    QLabel* getWidget_label();
    QLineEdit* getWidget_edit();
public slots:
    void getEditText();
};
