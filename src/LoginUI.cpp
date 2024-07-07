#include "LoginUI.h"   // Include header file for LoginUI class
#include <QtWidgets/QVBoxLayout>   // Include necessary Qt widgets module
#include <QtCore/QDebug>   // Include necessary Qt core module for debugging

void StackedWidgets::changeWindow_forward() {
    setCurrentIndex(stacked_windows.currentIndex()+1);   // Move to the next widget in the stacked windows
}

void StackedWidgets::changeWindow_backward() {
    setCurrentIndex(stacked_windows.currentIndex()-1);   // Move to the previous widget in the stacked windows
}

void LoginUI::init(QWidget* parent) {
    QSize widget_size(app_width, app_height / 10);   // Calculate size for the login widget

    login_widget = new QWidget(parent);   // Create a new QWidget for the login UI
    login_widget->setFixedSize(widget_size);   // Set fixed size for the login widget
    login_layout = new QHBoxLayout(login_widget);   // Create a horizontal layout for the login UI
    login_layout->setAlignment(Qt::AlignLeft);   // Set alignment of the login layout to left 
    login_layout->setContentsMargins(app_width / 12, 0, 0, 0);   // Set margins for the login layout
}

QWidget* LoginUI::getWidget() {
    return login_widget;   // Return the login widget
}

QHBoxLayout* LoginUI::getHLayout() {
    return login_layout;   // Return the horizontal layout of the login UI
}

void LoginText::init(QWidget* parent, QString text, int font_size) {
    login_text = new QLabel(parent);   // Create a new QLabel for displaying text
    login_text->setFont(QFont("Sans", font_size));   // Set font and size for the label
    login_text->setText(text);   // Set text to display in the label
    login_text->setAlignment(Qt::AlignCenter);   // Set alignment of the text in the label
    login_text->setMargin(60);   // Set margin around the label
}

QLabel* LoginText::getWidget_label() {
    return login_text;   // Return the label widget
}

void LoginButton::init(QWidget* parent, QString text, int font_size) {
    button_widget = new QPushButton(parent);   // Create a new QPushButton for user interaction
    button_widget->setText(text);   // Set text to display on the button
    button_widget->setFont(QFont("Sans", font_size - 12));   // Set font and size for the button text
    button_widget->setFixedSize(QSize(app_width / 4, app_height / 16));   // Set fixed size for the button
}

QPushButton* LoginButton::getWidget_button() {
    return button_widget;   // Return the button widget
}

void WidgetComponent::init(QWidget* parent, QString widget_text) {
    widget_label = new QLabel(parent);   // Create a new QLabel for displaying widget text
    widget_label->setFont(QFont("Sans", default_font_size - 6));   // Set font and size for the label
    widget_label->setText(widget_text);   // Set text to display in the label
    widget_label->setAlignment(Qt::AlignLeft);   // Set alignment of the text in the label
    widget_label->setFixedSize(QSize(app_width / 6, app_height / 10));   // Set fixed size for the label
    widget_label->setContentsMargins(0, app_height / 40, 0, 0);   // Set margins for the label

    widget_edit = new QLineEdit(parent);   // Create a new QLineEdit for user input
    widget_edit->setFixedSize(QSize(app_width * 2 / 3, app_height / 10));   // Set fixed size for the line edit
    widget_edit->setFont(QFont("Sans", default_font_size - 10));   // Set font and size for the text input
    widget_edit->setPlaceholderText(widget_text);   // Set placeholder text for the line edit
    widget_edit->setAlignment(Qt::AlignLeft);   // Set alignment of text in the line edit
    widget_edit->setTextMargins(20, 0, 0, 5);   // Set text margins for the line edit
}

QLabel* WidgetComponent::getWidget_label() {
    return widget_label;   // Return the label widget
}

QLineEdit* WidgetComponent::getWidget_edit() {
    return widget_edit;   // Return the line edit widget
}

QString WidgetComponent::getEditText(){
	return field_text;   // Return the text stored in the widget component
}

void WidgetComponent::updateEditText() {
	if(QString(widget_edit->text()) == ""){
		widget_edit->setText("");   // Clear text if empty
		widget_edit->setPlaceholderText("Field can't be empty");   // Set placeholder text if field is empty
		widget_edit->setStyleSheet("QLineEdit { placeholder-text-color: #FB3B3B }");   // Set stylesheet for placeholder text color
	}
}

void WidgetComponent::checkSamePassword(WidgetComponent* retype_password_component) {
    if(QString(this->widget_edit->text()) == QString(retype_password_component->widget_edit->text())){
		qDebug(qUtf8Printable(this->widget_edit->text()));   // Print debug message if passwords match
	}
	else{
		this->widget_edit->setText("");   // Clear text if passwords don't match
		this->widget_edit->setPlaceholderText("Passwords don't match");   // Set placeholder text for password mismatch
		this->widget_edit->setStyleSheet("QLineEdit { placeholder-text-color: #FB3B3B }");   // Set stylesheet for placeholder text color
		retype_password_component->widget_edit->setText("");   // Clear text in retype password component
		retype_password_component->widget_edit->setPlaceholderText("Passwords don't match");   // Set placeholder text for retype password component
		retype_password_component->widget_edit->setStyleSheet("QLineEdit { placeholder-text-color: #FB3B3B }");   // Set stylesheet for placeholder text color
	}
}

void WidgetComponent::togglePasswordVisibility(QPushButton *showButton){
	if(widget_edit->echoMode() == QLineEdit::Password){
		widget_edit->setEchoMode(QLineEdit::Normal);   // Show password
		showButton->setIcon(QIcon("requisite/assets/images/eye_hidden.png"));   // Set icon for hiding password
	}
	else if(widget_edit->echoMode() == QLineEdit::Normal){
		widget_edit->setEchoMode(QLineEdit::Password);   // Hide password
		showButton->setIcon(QIcon("requisite/assets/images/eye_shown.png"));   // Set icon for showing password
	}
}
