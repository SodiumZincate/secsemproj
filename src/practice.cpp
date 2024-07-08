#include<QtWidgets/QApplication>
#include<QtWidgets/QPushButton>
int main(int argc,char **argv){

    QApplication app(argc,argv);
   QPushButton button1,button2;
   button1.setText("I");
   button1.setToolTip("X");
   QFont font;
   font.setItalic(true);
   button1.setFont(font);
   button1.show();

 QIcon icon("requisite/assets/images/eye_show");
    QSize iconSize(120, 120); // Desired icon size
    QIcon scaledIcon = icon.pixmap(iconSize);
    button2.setIcon(scaledIcon);
    button2.setIconSize(iconSize); // Set the icon size for button2
    button2.setFixedSize(600, 600); // Set fixed size for button2
    button2.show();
    return app.exec();
}