#include "LoginUI.h"
#include <QtWidgets/QVBoxLayout>
#include <QtCore/QDebug>
#include <iostream>

extern int app_width, app_height, default_font_size;

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

void LoginHead::init(QWidget* parent) {
    login_text = new QLabel(parent);
    login_text->setFont(QFont("Sans", default_font_size));
    login_text->setText("Register");
    login_text->setAlignment(Qt::AlignCenter);
    login_text->setMargin(60);
}

QLabel* LoginHead::getWidget_label() {
    return login_text;
}

void LoginFoot::init(QWidget* parent) {
    button_widget = new QPushButton(parent);
    button_widget->setText("Submit");
    button_widget->setFont(QFont("Sans", default_font_size - 12));
    button_widget->setFixedSize(QSize(app_width / 4, app_height / 16));
}

QPushButton* LoginFoot::getWidget_button() {
    return button_widget;
}

WidgetComponent::WidgetComponent(QObject *parent)
    : QObject(parent), widget_label(nullptr), widget_edit(nullptr) {
}

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

void WidgetComponent::getEditText() {
    QString text = widget_edit->text();
    std::cout << "Entered text: " << text.toStdString() << std::endl;
}
