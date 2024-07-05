#include "LoginUI.h"

void initRegister(StackedWidgets *App, QWidget* window) {

	window->setWindowTitle("Sign in");

    // Main Widget
    QWidget *textbox_widget = new QWidget(window);
    QVBoxLayout *textbox_widget_layout = new QVBoxLayout(textbox_widget);
    textbox_widget_layout->setAlignment(Qt::AlignCenter); // Center align the contents

    // Username Widget
    LoginUI *username = new LoginUI();
    username->init(window);
    QWidget *username_widget = username->getWidget();
    QHBoxLayout *username_layout = username->getHLayout();

    // Email Widget
    LoginUI *email = new LoginUI();
    email->init(window);
    QWidget *email_widget = email->getWidget();
    QHBoxLayout *email_layout = email->getHLayout();

    // Password Widget
    LoginUI *password = new LoginUI();
    password->init(window);
    QWidget *password_widget = password->getWidget();
    QHBoxLayout *password_layout = password->getHLayout();

	//Retype Password Widget
	LoginUI *retype_password = new LoginUI();
    retype_password->init(window);
    QWidget *retype_password_widget = retype_password->getWidget();
    QHBoxLayout *retype_password_layout = retype_password->getHLayout();

    // Login Text Widget
    LoginText *login_text = new LoginText();
    login_text->init(window, "Register");
    QLabel *login_label = login_text->getWidget_label();

    // Submit Button Widget
    LoginButton *button = new LoginButton();
    button->init(window, "Submit");
    QPushButton *button_widget = button->getWidget_button();

    // Submit Button Widget
	LoginButton *signin_button = new LoginButton();
    signin_button->init(window, "Already have an account? Sign in", default_font_size-5);
    QPushButton *signin_button_widget = signin_button->getWidget_button();
	signin_button_widget->setCursor(Qt::PointingHandCursor);
	signin_button_widget->setStyleSheet("QPushButton{text-decoration:underline;border:none;}");

    // Submit Button Container Widget (Made so the Submit Button Widget could be centered as a Widget)
    QWidget *button_container = new QWidget(window);
    QHBoxLayout *button_container_layout = new QHBoxLayout(button_container);
    button_container_layout->setAlignment(Qt::AlignCenter);
    button_container_layout->setContentsMargins(0, app_height / 10, 0, 0);
	
	QWidget *signin_button_container = new QWidget(window);
    QHBoxLayout *signin_button_container_layout = new QHBoxLayout(signin_button_container);
    signin_button_container_layout->setAlignment(Qt::AlignCenter);
    signin_button_container_layout->setContentsMargins(0, app_height / 10, 0, 0);
    signin_button_widget->setFixedSize(QSize(app_width / 2, app_height / 32));

    // Initialization of Widget Components
    WidgetComponent *username_component = new WidgetComponent();
    WidgetComponent *email_component = new WidgetComponent();
    WidgetComponent *password_component = new WidgetComponent();
	WidgetComponent *retype_password_component = new WidgetComponent();

    username_component->init(username_widget, "Username");
    email_component->init(email_widget, "Email");

    password_component->init(password_widget, "Password");
	password_component->getWidget_edit()->setPlaceholderText("Enter Password");
	// Hiding text input on Password Field
    password_component->getWidget_edit()->setEchoMode(QLineEdit::Password);

    retype_password_component->init(retype_password_widget, "Password");
	retype_password_component->getWidget_edit()->setPlaceholderText("Confirm Password");
	// Hiding text input on Password Field
    retype_password_component->getWidget_edit()->setEchoMode(QLineEdit::Password);
	
	QPushButton *showButton = new QPushButton(password_component->getWidget_edit());
	showButton->setIcon(QIcon("requisite/assets/images/eye_shown.png"));
	showButton->setFixedHeight(password_component->getWidget_edit()->height()/2);
	QObject::connect(showButton, &QPushButton::clicked, 
    	[password_component, showButton]() {
			password_component->togglePasswordVisibility(showButton);
			});

	QPushButton *showRetypeButton = new QPushButton(retype_password_component->getWidget_edit());
	showRetypeButton->setIcon(QIcon("requisite/assets/images/eye_shown.png"));
	showRetypeButton->setFixedHeight(retype_password_component->getWidget_edit()->height()/2);
	QObject::connect(showRetypeButton, &QPushButton::clicked, 
    	[retype_password_component, showRetypeButton]() {
			retype_password_component->togglePasswordVisibility(showRetypeButton);
			});
	
    // Addition of Username Label and Text Box to Username Widget
    username_layout->addWidget(username_component->getWidget_label());
    username_layout->addWidget(username_component->getWidget_edit());

    // Addition of Email Label and Text Box to Email Widget
    email_layout->addWidget(email_component->getWidget_label());
    email_layout->addWidget(email_component->getWidget_edit());

    // Addition of Password Label and Text Box to Password Widget
    password_layout->addWidget(password_component->getWidget_label());
    password_layout->addWidget(password_component->getWidget_edit());
	password_layout->addWidget(showButton);

	retype_password_layout->addWidget(retype_password_component->getWidget_label());
	retype_password_layout->addWidget(retype_password_component->getWidget_edit());
	retype_password_layout->addWidget(showRetypeButton);

    // Addition of Submit Button Widget to the Submit Button Container Widget
    button_container_layout->addWidget(button_widget);
	signin_button_container_layout->addWidget(signin_button_widget);

    // Addition of sub-widgets to the main Widget
    textbox_widget_layout->addWidget(login_label);
    textbox_widget_layout->addWidget(username_widget);
    textbox_widget_layout->addWidget(email_widget);
    textbox_widget_layout->addWidget(password_widget);
	textbox_widget_layout->addWidget(retype_password_widget);
    textbox_widget_layout->addWidget(button_container);
	textbox_widget_layout->addWidget(signin_button_container);

	// Connection of submit button with username, email and password text fields
    QObject::connect(button_widget, &QPushButton::clicked, username_component, &WidgetComponent::updateEditText);
    QObject::connect(button_widget, &QPushButton::clicked, email_component, &WidgetComponent::updateEditText);
    QObject::connect(button_widget, &QPushButton::clicked, password_component, &WidgetComponent::updateEditText);
    QObject::connect(button_widget, &QPushButton::clicked, retype_password_component, &WidgetComponent::updateEditText);

	QObject::connect(button_widget, &QPushButton::clicked, 
    	[password_component, retype_password_component]() {
			password_component->checkSamePassword(retype_password_component);
			});

	QObject::connect(signin_button_widget, &QPushButton::clicked, App, &StackedWidgets::changeWindow_backward);

    // Layout of the main UI
    QVBoxLayout *main_layout = new QVBoxLayout(window);
    main_layout->addWidget(textbox_widget);
    main_layout->setAlignment(Qt::AlignCenter);
    window->setLayout(main_layout);
}

void initLogin(StackedWidgets *App, QWidget* window) {

	window->setWindowTitle("Sign up");

    // Main Widget
    QWidget *textbox_widget = new QWidget(window);
    QVBoxLayout *textbox_widget_layout = new QVBoxLayout(textbox_widget);
    textbox_widget_layout->setAlignment(Qt::AlignCenter); // Center align the contents

    // Username Widget
    LoginUI *username = new LoginUI();
    username->init(window);
    QWidget *username_widget = username->getWidget();
    QHBoxLayout *username_layout = username->getHLayout();

    // Password Widget
    LoginUI *password = new LoginUI();
    password->init(window);
    QWidget *password_widget = password->getWidget();
    QHBoxLayout *password_layout = password->getHLayout();

    // Login Text Widget
    LoginText *login_text = new LoginText();
    login_text->init(window, "Login");
    QLabel *login_label = login_text->getWidget_label();

    // Submit Button Widget
    LoginButton *button = new LoginButton();
    button->init(window, "Submit");
    QPushButton *button_widget = button->getWidget_button();

    // Submit Button Widget
	LoginButton *signin_button = new LoginButton();
    signin_button->init(window, "Don't already have an account? Sign up", default_font_size-5);
    QPushButton *signin_button_widget = signin_button->getWidget_button();
	signin_button_widget->setCursor(Qt::PointingHandCursor);
	signin_button_widget->setStyleSheet("QPushButton{text-decoration:underline;border:none;}");

    // Submit Button Container Widget (Made so the Submit Button Widget could be centered as a Widget)
    QWidget *button_container = new QWidget(window);
    QHBoxLayout *button_container_layout = new QHBoxLayout(button_container);
    button_container_layout->setAlignment(Qt::AlignCenter);
    button_container_layout->setContentsMargins(0, app_height / 10, 0, 0);
	
	QWidget *signin_button_container = new QWidget(window);
    QHBoxLayout *signin_button_container_layout = new QHBoxLayout(signin_button_container);
    signin_button_container_layout->setAlignment(Qt::AlignCenter);
    signin_button_container_layout->setContentsMargins(0, app_height / 10, 0, 0);
    signin_button_widget->setFixedSize(QSize(app_width / 2, app_height / 32));

    // Initialization of Widget Components
    WidgetComponent *username_component = new WidgetComponent();
    WidgetComponent *email_component = new WidgetComponent();
    WidgetComponent *password_component = new WidgetComponent();

    username_component->init(username_widget, "Username");
    password_component->init(password_widget, "Password");
	// Hiding text input on Password Field
    password_component->getWidget_edit()->setEchoMode(QLineEdit::Password);

	QPushButton *showButton = new QPushButton(password_component->getWidget_edit());
	showButton->setIcon(QIcon("requisite/assets/images/eye_shown.png"));
	showButton->setFixedHeight(password_component->getWidget_edit()->height()/2);
	QObject::connect(showButton, &QPushButton::clicked, 
    	[password_component, showButton]() {
			password_component->togglePasswordVisibility(showButton);
			});

    // Addition of Username Label and Text Box to Username Widget
    username_layout->addWidget(username_component->getWidget_label());
    username_layout->addWidget(username_component->getWidget_edit());

    // Addition of Password Label and Text Box to Password Widget
    password_layout->addWidget(password_component->getWidget_label());
    password_layout->addWidget(password_component->getWidget_edit());
    password_layout->addWidget(showButton);

    // Addition of Submit Button Widget to the Submit Button Container Widget
    button_container_layout->addWidget(button_widget);
	signin_button_container_layout->addWidget(signin_button_widget);

    // Addition of sub-widgets to the main Widget
    textbox_widget_layout->addWidget(login_label);
    textbox_widget_layout->addWidget(username_widget);
    textbox_widget_layout->addWidget(password_widget);
    textbox_widget_layout->addWidget(button_container);
	textbox_widget_layout->addWidget(signin_button_container);

	// Connection of submit button with username and password text fields
	QObject::connect(button_widget, &QPushButton::clicked, username_component, &WidgetComponent::updateEditText);
    QObject::connect(button_widget, &QPushButton::clicked, password_component, &WidgetComponent::updateEditText);
	QObject::connect(signin_button_widget, &QPushButton::clicked, App, &StackedWidgets::changeWindow_forward);

    // Layout of the main UI
    QVBoxLayout *main_layout = new QVBoxLayout(window);
    main_layout->addWidget(textbox_widget);
    main_layout->setAlignment(Qt::AlignCenter);
    window->setLayout(main_layout);
}