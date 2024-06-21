#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <X11/Xlib.h> // Only needed on X11 systems
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QGraphicsScene>
#include <QLabel>
//#include <QTextEdit>

int main(int argc, char *argv[]) {
    Display* disp = XOpenDisplay(NULL); // Only needed on X11 systems
    Screen*  scrn = DefaultScreenOfDisplay(disp); // Only needed on X11 systems
    int app_width = scrn->width/2; // Only needed on X11 systems
    int app_height = scrn->height/2; // Only needed on X11 systems

    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("League Manager");

    QFont placeholder_font("Sans", 24);
    QFont login_text_font("Sans", 36);
    QFont description_text_font("Sans", 28);

    QWidget *textbox_widget = new QWidget(&window);
    QSize container_size(app_width*2/3, app_height/10);
    QSize description_size(app_width/6, app_height/10);
    QSize widget_size(app_width, app_height/10);

    QRect right_container(app_width/2, app_height/8, app_width/2, app_height/4); //aleft, atop, awidth, aheight

    QWidget *username_widget = new QWidget(&window);
    username_widget->setFixedSize(widget_size);
    QHBoxLayout *username_layout = new QHBoxLayout(username_widget);
    username_layout->setAlignment(Qt::AlignLeft);
    username_layout->setContentsMargins(app_width/12,0,0,0);
    QWidget *email_widget = new QWidget(&window);
    email_widget->setFixedSize(widget_size);
    QHBoxLayout *email_layout = new QHBoxLayout(email_widget);
    email_layout->setAlignment(Qt::AlignLeft);
    email_layout->setContentsMargins(app_width/12,0,0,0);
    QWidget *password_widget = new QWidget(&window);
    password_widget->setFixedSize(widget_size);
    QHBoxLayout *password_layout = new QHBoxLayout(password_widget);
    password_layout->setAlignment(Qt::AlignLeft);
    password_layout->setContentsMargins(app_width/12,0,0,0);
 
    QVBoxLayout *textbox_widget_layout = new QVBoxLayout(textbox_widget);
    textbox_widget_layout->setAlignment(Qt::AlignCenter); // Center align the contents
        
    QLabel *login_text = new QLabel(textbox_widget);
    login_text->setFont(login_text_font);
    login_text->setText("Register: ");
    login_text->setAlignment(Qt::AlignCenter);
    login_text->setMargin(60);

    QLabel *username_desc = new QLabel(username_widget);
    QLabel *email_desc = new QLabel(email_widget);
    QLabel *password_desc = new QLabel(password_widget);

    username_desc->setFont(description_text_font);
    username_desc->setText("Username: ");
    username_desc->setAlignment(Qt::AlignLeft);
    username_desc->setFixedSize(description_size);
    username_desc->setContentsMargins(0,20,0,0);

    email_desc->setFont(description_text_font);
    email_desc->setText("Email: ");
    email_desc->setAlignment(Qt::AlignLeft);
    email_desc->setFixedSize(description_size);
    email_desc->setContentsMargins(0,20,0,0);

    password_desc->setFont(description_text_font);
    password_desc->setText("Password: ");
    password_desc->setAlignment(Qt::AlignLeft);
    password_desc->setFixedSize(description_size);
    password_desc->setContentsMargins(0,20,0,0);

    QLineEdit *username_edit = new QLineEdit(username_widget);
    QLineEdit *email_edit = new QLineEdit(email_widget);
    QLineEdit *password_edit = new QLineEdit(password_widget);

    username_edit->setFixedSize(container_size);
    username_edit->setFont(placeholder_font);
    username_edit->setPlaceholderText("Username");
    username_edit->setAlignment(Qt::AlignLeft); // Left align text within QLineEdit
    username_edit->setTextMargins(20, 0, 0, 5);

    email_edit->setFixedSize(container_size);
    email_edit->setFont(placeholder_font);
    email_edit->setPlaceholderText("adarshanub@gmail.com");
    email_edit->setAlignment(Qt::AlignLeft); // Left align text within QLineEdit
    email_edit->setTextMargins(20, 0, 0, 5);

    password_edit->setFixedSize(container_size);
    password_edit->setFont(placeholder_font);
    password_edit->setPlaceholderText("Password");
    password_edit->setEchoMode(QLineEdit::Password);
    password_edit->setAlignment(Qt::AlignLeft); // Left align text within QLineEdit
    password_edit->setTextMargins(20, 0, 0, 5);

    username_layout->addWidget(username_desc);
    username_layout->addWidget(username_edit);

    email_layout->addWidget(email_desc);
    email_layout->addWidget(email_edit);
    
    password_layout->addWidget(password_desc);
    password_layout->addWidget(password_edit);

    textbox_widget_layout->addWidget(login_text);
    textbox_widget_layout->addWidget(username_widget);
    textbox_widget_layout->addWidget(email_widget);
    textbox_widget_layout->addWidget(password_widget);

    QVBoxLayout *main_layout = new QVBoxLayout(&window);

    main_layout->addWidget(textbox_widget);
    main_layout->setAlignment(Qt::AlignCenter);

    window.setLayout(main_layout);
    
    window.resize(scrn->width/2, scrn->height/2);

    window.show();

    return app.exec();
}
