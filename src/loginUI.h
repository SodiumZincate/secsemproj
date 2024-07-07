#pragma once

#include <QtCore/QObject>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolButton>
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

class StackedWidgets : public QObject { // Inherits from QObject, the base class for all Qt objects.
    Q_OBJECT // Macro for enabling Qt's meta-object features, such as signals and slots.
public:
    QWidget mainWidget; // The main widget container. This is the parent widget for other UI elements.
    QHBoxLayout *appLayout; // A horizontal layout to arrange widgets within mainWidget.
    QStackedWidget stacked_windows; // A stack of widgets, where only one widget is visible at a time.

    StackedWidgets() { // Constructor
        appLayout = new QHBoxLayout(&mainWidget); // Initialize the horizontal layout with mainWidget as its parent.
        appLayout->addWidget(&stacked_windows); // Add the QStackedWidget to the horizontal layout.
    }

    void addWidget(QWidget* widget) { // Adds a new widget to the QStackedWidget.
        stacked_windows.addWidget(widget); // Adds the widget to the stack.
    }

    void setCurrentIndex(int index) { // Sets the current visible widget by index.
        stacked_windows.setCurrentIndex(index); // Changes the visible widget in the QStackedWidget to the specified index.
    }

public slots:
    void changeWindow_forward(); // Slot to change the visible widget to the next one.
    void changeWindow_backward(); // Slot to change the visible widget to the previous one.
};

// Functions to initialize Login page
void initLogin(StackedWidgets *App, QWidget* window);
// Functions to initialize Register page
void initRegister(StackedWidgets *App, QWidget* window);

// Main class for the widgets in login/Register page
// (Username, Email, Password) widgets
class LoginUI {
private:
    QWidget *login_widget;    // Widget container for the login UI
    QHBoxLayout *login_layout;    // Horizontal layout for arranging login UI elements
public:
    void init(QWidget*);    // Method to initialize the login UI
    QWidget* getWidget();    // Method to retrieve the login widget
    QHBoxLayout* getHLayout();    // Method to retrieve the horizontal layout
};

// Class for Head Text and other miscellanous text in login/Register page
class LoginText {
private:
    QLabel* login_text;    // Label widget for displaying text in the login UI
public:
    void init(QWidget*, QString, int font_size = default_font_size);    // Method to initialize the text label
    QLabel* getWidget_label();    // Method to retrieve the label widget
};

// Class for buttons in login/Register page
class LoginButton{
public:
    QPushButton* button_widget;    // Button widget for user interaction
    void init(QWidget*, QString, int font_size = default_font_size);    // Method to initialize the button
    QPushButton* getWidget_button();    // Method to retrieve the button widget
};

// Sub class for the individual input field widgets in login/Register page
// each object of this class represents a text label and its input field
class WidgetComponent : public QObject {
    Q_OBJECT // A QT macro that allows the use of slots
private:
    QString field_text;    // Text stored within the widget component
    QLabel *widget_label;    // Label widget for displaying text
    QLineEdit *widget_edit;    // Line edit widget for user input
public:
    void init(QWidget*, QString);    // Method to initialize the widget component
    QLabel* getWidget_label();    // Method to retrieve the label widget
    QLineEdit* getWidget_edit();    // Method to retrieve the line edit widget
    QString getEditText();    // Method to retrieve text entered in the line edit
    void togglePasswordVisibility(QPushButton*);    // Method to toggle password visibility
    void checkSamePassword(WidgetComponent* password_component);    // Method to check if passwords match
public slots:
    void updateEditText();    // Slot method to update text in the line edit
};