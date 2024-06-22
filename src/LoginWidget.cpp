#include "LoginWidget.h"

extern int app_width, app_height;

void LoginWidget::init(QWidget* parent){
    QSize widget_size(app_width, app_height/10);

    login_widget = new QWidget(parent);
    login_widget->setFixedSize(widget_size);
    login_layout = new QHBoxLayout(login_widget);
    login_layout->setAlignment(Qt::AlignLeft);
    login_layout->setContentsMargins(app_width/12,0,0,0);
}

QWidget* LoginWidget::getWidget(){
    return login_widget;
}

QHBoxLayout* LoginWidget::getHLayout(){
    return login_layout;
}

void LoginHead::init(QWidget* parent){
    login_text = new QLabel(parent);
    login_text->setFont(QFont("Sans", 36));
    login_text->setText("Register: ");
    login_text->setAlignment(Qt::AlignCenter);
    login_text->setMargin(60);
}

QLabel* LoginHead::getWidget_label(){
    return login_text;
}

void LoginFoot::init(QWidget* parent){
    button_widget = new QPushButton(parent);
    button_widget->setText("Submit");
    button_widget->setFont(QFont("Sans", 20));
    button_widget->setFixedSize(QSize(app_width/4, app_height/16));
}

QPushButton* LoginFoot::getWidget_button(){
    return button_widget;
}