#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <X11/Xlib.h> // Only needed on X11 systems
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QGraphicsScene>
//#include <QTextEdit>

int main(int argc, char *argv[]) {
    Display* disp = XOpenDisplay(NULL); // Only needed on X11 systems
    Screen*  scrn = DefaultScreenOfDisplay(disp); // Only needed on X11 systems
    int app_width = scrn->width/2; // Only needed on X11 systems
    int app_height = scrn->height/2; // Only needed on X11 systems

    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("League Manager");

    QWidget *rectangular_widget = new QWidget(&window);
    QSize container_size(app_width/2, app_width/16);
    QRect rect_container(app_width/4, app_height/4, app_width/2, app_width/4); // Expanded the width of rect_container

    rectangular_widget->setGeometry(rect_container);

    QVBoxLayout *login_layout = new QVBoxLayout(rectangular_widget);
    login_layout->setAlignment(Qt::AlignCenter); // Center align the contents

    QFont new_font("Sans", 24);

    QLineEdit *username_edit = new QLineEdit(rectangular_widget);
    username_edit->setFixedSize(container_size);
    username_edit->setFont(new_font);
    username_edit->setPlaceholderText("Username");
    username_edit->setAlignment(Qt::AlignCenter); // Center align text within QLineEdit
    username_edit->setTextMargins(20, 0, 0, 5);

    QLineEdit *password_edit = new QLineEdit(rectangular_widget);
    password_edit->setFixedSize(container_size);
    password_edit->setFont(new_font);
    password_edit->setPlaceholderText("Password");
    password_edit->setEchoMode(QLineEdit::Password);
    password_edit->setAlignment(Qt::AlignCenter); // Center align text within QLineEdit
    password_edit->setTextMargins(20, 0, 0, 5);

    login_layout->addWidget(username_edit);
    login_layout->addWidget(password_edit);

    QVBoxLayout *main_layout = new QVBoxLayout(&window);
    main_layout->addWidget(rectangular_widget);

    window.setLayout(main_layout);
    window.resize(scrn->width/2, scrn->height/2);

    window.show();

    return app.exec();
}
