#include <iostream>
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <X11/Xlib.h> // Only needed on X11 systems
#include <QLabel>
#include <QPushButton>

#include "WidgetComponent.h"
#include "LoginWidget.h"
//#include <QTextEdit>

Display* disp = XOpenDisplay(NULL); // Only needed on X11 systems
Screen*  scrn = DefaultScreenOfDisplay(disp); // Only needed on X11 systems
int app_width = scrn->width/2; // Only needed on X11 systems
int app_height = scrn->height/2; // Only needed on X11 systems

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("League Manager");

    //Main Widget
    QWidget *textbox_widget = new QWidget(&window);
    QVBoxLayout *textbox_widget_layout = new QVBoxLayout(textbox_widget);
    textbox_widget_layout->setAlignment(Qt::AlignCenter); // Center align the contents

    //Username Widget
    LoginWidget *username = new LoginWidget();
    username->init(&window);
    QWidget *username_widget = username->getWidget();
    QHBoxLayout *username_layout = username->getHLayout();

    //Email Widget
    LoginWidget *email = new LoginWidget();
    email->init(&window);
    QWidget* email_widget = email->getWidget();
    QHBoxLayout *email_layout = email->getHLayout();

    //Password Widget
    LoginWidget *password = new LoginWidget();
    password->init(&window);
    QWidget* password_widget = password->getWidget();
    QHBoxLayout *password_layout = password->getHLayout();

    //Login Text Widget
    LoginHead *login = new LoginHead();
    login->init(&window);
    QLabel* login_label = login->getWidget_label();
    
    //Submit Button Widget
    LoginFoot *button = new LoginFoot();
    button->init(&window);
    QPushButton* button_widget = button->getWidget_button();

    //Submit Button Container Widget (Made so the Submit Button Widget could be centered as a Widget)
    QWidget *button_container = new QWidget(&window);
    QHBoxLayout *button_container_layout = new QHBoxLayout(button_container);
    button_container_layout->setAlignment(Qt::AlignCenter);
    button_container_layout->setContentsMargins(0,app_height/10,0,0);
    
    //Initialization of Widget Components
    WidgetComponent *username_component = new WidgetComponent();
    WidgetComponent *email_component = new WidgetComponent();
    WidgetComponent *password_component = new WidgetComponent();

    username_component->init(username_widget, "Username");
    email_component->init(email_widget, "Email");
    password_component->init(password_widget, "Password");
    //Hiding text input on Password Field
    password_component->getWidget_edit()->setEchoMode(QLineEdit::Password);

    //Addition of Username Label and Text Box to Username Widget
    username_layout->addWidget(username_component->getWidget_label());
    username_layout->addWidget(username_component->getWidget_edit());

    //Addition of Username Label and Text Box to Email Widget
    email_layout->addWidget(email_component->getWidget_label());
    email_layout->addWidget(email_component->getWidget_edit());

    //Addition of Username Label and Text Box to Password Widget
    password_layout->addWidget(password_component->getWidget_label());
    password_layout->addWidget(password_component->getWidget_edit());

    //Addition of Submit Button Widget to the Submit Button Container Widget
    button_container_layout->addWidget(button_widget);

    //Addition of sub-widgets to the main Widget
    textbox_widget_layout->addWidget(login_label);
    textbox_widget_layout->addWidget(username_widget);
    textbox_widget_layout->addWidget(email_widget);
    textbox_widget_layout->addWidget(password_widget);
    textbox_widget_layout->addWidget(button_container);

    //Layout of the main UI
    QVBoxLayout *main_layout = new QVBoxLayout(&window);
    main_layout->addWidget(textbox_widget);
    main_layout->setAlignment(Qt::AlignCenter);
    window.setLayout(main_layout);
    
    window.resize(scrn->width/2, scrn->height/2);
    window.show();

    return app.exec();
}
