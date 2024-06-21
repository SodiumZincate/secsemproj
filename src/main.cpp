#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>
//#include <QTextEdit>

int main(int argc, char *argv[]){
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("League Manager");

    QVBoxLayout *layout = new QVBoxLayout();

    QLineEdit *username_edit = new QLineEdit();
    username_edit->setPlaceholderText("Username");
    QLineEdit *password_edit = new QLineEdit();
    password_edit->setPlaceholderText("Password");
    password_edit->setEchoMode(QLineEdit::Password);

    layout->addWidget(username_edit, 0, Qt::AlignCenter);
    layout->addWidget(password_edit,0, Qt::AlignCenter);

    window.setLayout(layout);
    window.show();

    return app.exec();
}