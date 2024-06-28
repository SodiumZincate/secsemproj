#include <QtWidgets/QApplication>
#include <QtGui/QScreen>
#include <QtWidgets/QVBoxLayout>
#include "LoginUI.h"

int app_height = 0;
int app_width = 0;

#ifdef _WIN32
    int default_font_size = 26;
#elif defined(__linux__)
    int default_font_size = 34;
#endif

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);
    QScreen *screen = QGuiApplication::primaryScreen();

    QSize screenSize = screen->size();
    int screenWidth = screenSize.width();
    int screenHeight = screenSize.height();

    app_width = screenWidth / 2;
    app_height = screenHeight / 2;

    QWidget window;
    window.setWindowTitle("League Manager");

    // Main Widget
    QWidget *textbox_widget = new QWidget(&window);
    QVBoxLayout *textbox_widget_layout = new QVBoxLayout(textbox_widget);
    textbox_widget_layout->setAlignment(Qt::AlignCenter); // Center align the contents

    // Username Widget
    LoginUI *username = new LoginUI();
    username->init(&window);
    QWidget *username_widget = username->getWidget();
    QHBoxLayout *username_layout = username->getHLayout();

    // Email Widget
    LoginUI *email = new LoginUI();
    email->init(&window);
    QWidget *email_widget = email->getWidget();
    QHBoxLayout *email_layout = email->getHLayout();

    // Password Widget
    LoginUI *password = new LoginUI();
    password->init(&window);
    QWidget *password_widget = password->getWidget();
    QHBoxLayout *password_layout = password->getHLayout();

    // Login Text Widget
    LoginHead *login = new LoginHead();
    login->init(&window);
    QLabel *login_label = login->getWidget_label();

    // Submit Button Widget
    LoginFoot *button = new LoginFoot();
    button->init(&window);
    QPushButton *button_widget = button->getWidget_button();

    // Submit Button Container Widget (Made so the Submit Button Widget could be centered as a Widget)
    QWidget *button_container = new QWidget(&window);
    QHBoxLayout *button_container_layout = new QHBoxLayout(button_container);
    button_container_layout->setAlignment(Qt::AlignCenter);
    button_container_layout->setContentsMargins(0, app_height / 10, 0, 0);

    // Initialization of Widget Components
    WidgetComponent *username_component = new WidgetComponent();
    WidgetComponent *email_component = new WidgetComponent();
    WidgetComponent *password_component = new WidgetComponent();

    username_component->init(username_widget, "Username");
    email_component->init(email_widget, "Email");
    password_component->init(password_widget, "Password");
    // Hiding text input on Password Field
    password_component->getWidget_edit()->setEchoMode(QLineEdit::Password);

    QObject::connect(button_widget, &QPushButton::clicked, username_component, &WidgetComponent::getEditText);

    // Addition of Username Label and Text Box to Username Widget
    username_layout->addWidget(username_component->getWidget_label());
    username_layout->addWidget(username_component->getWidget_edit());

    // Addition of Email Label and Text Box to Email Widget
    email_layout->addWidget(email_component->getWidget_label());
    email_layout->addWidget(email_component->getWidget_edit());

    // Addition of Password Label and Text Box to Password Widget
    password_layout->addWidget(password_component->getWidget_label());
    password_layout->addWidget(password_component->getWidget_edit());

    // Addition of Submit Button Widget to the Submit Button Container Widget
    button_container_layout->addWidget(button_widget);

    // Addition of sub-widgets to the main Widget
    textbox_widget_layout->addWidget(login_label);
    textbox_widget_layout->addWidget(username_widget);
    textbox_widget_layout->addWidget(email_widget);
    textbox_widget_layout->addWidget(password_widget);
    textbox_widget_layout->addWidget(button_container);

    // Layout of the main UI
    QVBoxLayout *main_layout = new QVBoxLayout(&window);
    main_layout->addWidget(textbox_widget);
    main_layout->setAlignment(Qt::AlignCenter);
    window.setLayout(main_layout);

    window.resize(app_width, app_height);
    window.show();

    return app.exec();
}
