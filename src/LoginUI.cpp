#include "LoginUI.h"
#include <QtWidgets/QVBoxLayout>
#include <QtCore/QDebug>
#include <iostream>

void LoginUI::init(QWidget* parent) {
    QSize widget_size(app_width, app_height / 10);

    login_widget = new QWidget(parent);
    login_widget->setFixedSize(widget_size);
    login_layout = new QHBoxLayout(login_widget);
    login_layout->setAlignment(Qt::AlignLeft);
    login_layout->setContentsMargins(app_width / 12, 0, 0, 0);
}

QWidget* LoginUI::getWidget() {
    return login_widget;
}

QHBoxLayout* LoginUI::getHLayout() {
    return login_layout;
}

void LoginText::init(QWidget* parent, QString text, int font_size) {
    login_text = new QLabel(parent);
    login_text->setFont(QFont("Sans", font_size));
    login_text->setText(text);
    login_text->setAlignment(Qt::AlignCenter);
    login_text->setMargin(60);
}

QLabel* LoginText::getWidget_label() {
    return login_text;
}

// void LoginText::changeText(){
// 	if(login_text->text() == QString("Login"))
// 	{
// 		login_text->setText("Register");
// 	}
// 	else
// 	{
// 		login_text->setText("Login");
// 	}
// }

void LoginButton::init(QWidget* parent, QString text, int font_size) {
    button_widget = new QPushButton(parent);
    button_widget->setText(text);
    button_widget->setFont(QFont("Sans", font_size - 12));
    button_widget->setFixedSize(QSize(app_width / 4, app_height / 16));
}

QPushButton* LoginButton::getWidget_button() {
    return button_widget;
}

// void LoginButton::changeMode(){
// 	if(button_widget->text() == QString("Sign in"))
// 		button_widget->setText("Sign up");
// 	else
// 		button_widget->setText("Sign in");
// }

void WidgetComponent::init(QWidget* parent, QString widget_text) {
    widget_label = new QLabel(parent);
    widget_label->setFont(QFont("Sans", default_font_size - 6));
    widget_label->setText(widget_text);
    widget_label->setAlignment(Qt::AlignLeft);
    widget_label->setFixedSize(QSize(app_width / 6, app_height / 10));
    widget_label->setContentsMargins(0, app_height / 40, 0, 0);

    widget_edit = new QLineEdit(parent);
    widget_edit->setFixedSize(QSize(app_width * 2 / 3, app_height / 10));
    widget_edit->setFont(QFont("Sans", default_font_size - 10));
    widget_edit->setPlaceholderText(widget_text);
    widget_edit->setAlignment(Qt::AlignLeft);
    widget_edit->setTextMargins(20, 0, 0, 5);
}

QLabel* WidgetComponent::getWidget_label() {
    return widget_label;
}

QLineEdit* WidgetComponent::getWidget_edit() {
    return widget_edit;
}

QString WidgetComponent::getEditText(){
	return field_text;
}

void WidgetComponent::updateEditText() {
    field_text = widget_edit->text();
	std::cout<<"Hello"<<std::endl;
}