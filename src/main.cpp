#include <iostream>
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <X11/Xlib.h> // Only needed on X11 systems
#include <QLabel>
#include <QPushButton>

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

    QFont placeholder_font("Sans", 24);
    QFont login_text_font("Sans", 36);
    QFont description_text_font("Sans", 28);
    QFont button_font("Sans", 20);

    QSize button_size(app_width/4, app_height/16);

    QWidget *textbox_widget = new QWidget(&window);
    QVBoxLayout *textbox_widget_layout = new QVBoxLayout(textbox_widget);
    textbox_widget_layout->setAlignment(Qt::AlignCenter); // Center align the contents

    LoginWidget *username_widget = new LoginWidget(&window);
    LoginWidget *email_widget = new LoginWidget(&window);
    LoginWidget *password_widget = new LoginWidget(&window);
    
    QLabel *login_text = new QLabel(textbox_widget);
    login_text->setFont(login_text_font);
    login_text->setText("Register: ");
    login_text->setAlignment(Qt::AlignCenter);
    login_text->setMargin(60);

    WidgetComponent *username_component = new WidgetComponent(username_widget->getWidget(),"Username");
    WidgetComponent *email_component = new WidgetComponent(email_widget->getWidget(),"Email");
    WidgetComponent *password_component = new WidgetComponent(password_widget->getWidget(),"Password");

    QPushButton *submit_button = new QPushButton(textbox_widget);
    submit_button->setText("Submit");
    submit_button->setFont(button_font);
    submit_button->setFixedSize(button_size);

    QWidget *button_widget = new QWidget(textbox_widget);
    QHBoxLayout *button_layout = new QHBoxLayout(button_widget);
    button_layout->addWidget(submit_button);
    
    username_widget->addWidget(username_component);
    email_widget->addWidget(email_component);
    password_widget->addWidget(password_component);

    textbox_widget_layout->addWidget(login_text);
    textbox_widget_layout->addWidget(username_widget->getWidget());
    textbox_widget_layout->addWidget(email_widget->getWidget());
    textbox_widget_layout->addWidget(password_widget->getWidget());
    textbox_widget_layout->addWidget(button_widget);

    QVBoxLayout *main_layout = new QVBoxLayout(&window);
    main_layout->addWidget(textbox_widget);
    main_layout->setAlignment(Qt::AlignCenter);
    window.setLayout(main_layout);
    
    window.resize(scrn->width/2, scrn->height/2);
    window.show();

    return app.exec();
}
