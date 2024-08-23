#include "appUI.h"
#include "db.h"
#include "logic.h"

void initRegister(StackedWidgets *App, QWidget* window) {

	window->setWindowTitle("Sign in");

    // Main Widget
    QWidget *main_widget = new QWidget(window);
    QVBoxLayout *main_widget_layout = new QVBoxLayout(main_widget);
    main_widget_layout->setAlignment(Qt::AlignCenter); // Center align the contents
   
    // Username Widget
    appUI *username = new appUI();
    username->init(window);
    QWidget *username_widget = username->getWidget();
    QHBoxLayout *username_layout = username->getHLayout();

    // Email Widget
    appUI *email = new appUI();
    email->init(window);
    QWidget *email_widget = email->getWidget();
    QHBoxLayout *email_layout = email->getHLayout();

    // Password Widget
    appUI *password = new appUI();
    password->init(window);
    QWidget *password_widget = password->getWidget();
    QHBoxLayout *password_layout = password->getHLayout();

	//Retype Password Widget
	appUI *retype_password = new appUI();
    retype_password->init(window);
    QWidget *retype_password_widget = retype_password->getWidget();
    QHBoxLayout *retype_password_layout = retype_password->getHLayout();

    // Login Text Widget
    appText *login_text = new appText();
    login_text->init(window, "Register");
    QLabel *login_label = login_text->getWidget_label();

    // Submit Button Widget
    appButton *button = new appButton();
    button->init(window, "Submit");
    QPushButton *button_widget = button->getWidget_button();
	button_widget->setStyleSheet("QPushButton{background-color: #a2d9ce}");

    // Submit Button Widget
	appButton *signin_button = new appButton();
    signin_button->init(window, "Already have an account? Sign in", default_font_size*0.8);
    QPushButton *signin_button_widget = signin_button->getWidget_button();
	signin_button_widget->setCursor(Qt::PointingHandCursor);
	signin_button_widget->setStyleSheet("QPushButton{text-decoration:underline;border:none;}");

    // Submit Button Container Widget (Made so the Submit Button Widget could be centered as a Widget)
    QWidget *button_container = new QWidget(window);
    QHBoxLayout *button_container_layout = new QHBoxLayout(button_container);
    button_container_layout->setAlignment(Qt::AlignCenter);
    button_container_layout->setContentsMargins(0, app_height / 10, 0, 0);
	
	// Submit Button Container Widget (Made so the Submit Button Widget could be centered as a Widget)
	QWidget *signin_button_container = new QWidget(window);
    QHBoxLayout *signin_button_container_layout = new QHBoxLayout(signin_button_container);
    signin_button_container_layout->setAlignment(Qt::AlignCenter);
    signin_button_container_layout->setContentsMargins(0, app_height / 10, 0, 0);
    signin_button_widget->setFixedSize(QSize(app_width / 2, app_height / 32));

    // Initialization of Widget Components
    LabelEditComponent *username_component = new LabelEditComponent();
    LabelEditComponent *email_component = new LabelEditComponent();
    LabelEditComponent *password_component = new LabelEditComponent();
	LabelEditComponent *retype_password_component = new LabelEditComponent();

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
	
	// Widget for showing and hiding password field
	QPushButton *showButton = new QPushButton(password_component->getWidget_edit());
	showButton->setIcon(QIcon("requisite/assets/images/eye_shown.png"));
	showButton->setFixedHeight(password_component->getWidget_edit()->height()/2);
	QObject::connect(showButton, &QPushButton::clicked, 
    	[password_component, showButton]() {
			password_component->togglePasswordVisibility(showButton);
			});

	// Widget for showing and hiding retype password field
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
    main_widget_layout->addWidget(login_label);
    main_widget_layout->addWidget(username_widget);
    main_widget_layout->addWidget(email_widget);
    main_widget_layout->addWidget(password_widget);
	main_widget_layout->addWidget(retype_password_widget);
    main_widget_layout->addWidget(button_container);
	main_widget_layout->addWidget(signin_button_container);

	// Connection of submit button with username, email and password text fields
    QObject::connect(button_widget, &QPushButton::clicked, username_component, &LabelEditComponent::updateEditText);
    QObject::connect(button_widget, &QPushButton::clicked, email_component, &LabelEditComponent::updateEditText);
    QObject::connect(button_widget, &QPushButton::clicked, password_component, &LabelEditComponent::updateEditText);
    QObject::connect(button_widget, &QPushButton::clicked, retype_password_component, &LabelEditComponent::updateEditText);

	// QObject::disconnect(button_widget, &QPushButton::clicked, username_component, &LabelEditComponent::updateEditText);
    // QObject::disconnect(button_widget, &QPushButton::clicked, email_component, &LabelEditComponent::updateEditText);
    // QObject::disconnect(button_widget, &QPushButton::clicked, password_component, &LabelEditComponent::updateEditText);
    // QObject::disconnect(button_widget, &QPushButton::clicked, retype_password_component, &LabelEditComponent::updateEditText);

	// Connection for checking same password in both password fields
	QObject::connect(button_widget, &QPushButton::clicked, 
    	[=]() {
			bool isSamePassword = password_component->checkSamePassword(retype_password_component);
			std::string username_text, email_text, password_text;
			username_text = (username_component->getFieldText()).toStdString();
			email_text = (email_component->getFieldText()).toStdString();
			password_text = (password_component->getFieldText()).toStdString();

		std::string clientReq = username_text + "\n";
		std::stringstream clientRes;
		std::string streamLine;
		std::vector<std::string> streamList;

		if(username_text != "" && password_text != ""){
			int errorDatabase = updateDatabase(clientReq, "query", clientRes);
			if(errorDatabase!=0){
				std::cout << "\nError initializing database" << std::endl;
			}
			else{
				while(getline(clientRes, streamLine, '\n')){
					streamList.push_back(streamLine);
					std::cout << "Streamline: " << streamLine << std::endl;
					std::cout << "Username: " << username_text << std::endl;
					std::cout << "Password: " << password_text << std::endl;
				}
				if(strcmp(username_text.c_str(), streamList[1].c_str())==0) {
					std::cout << "You are already registered" << std::endl;
					username_component->usernameExists(true);
					email_component->deleteEditText();
					password_component->deleteEditText();
					retype_password_component->deleteEditText();
				}
				else{
					clientReq = username_text + "\n" + email_text + "\n" + password_text + "\n"; 
					clientRes.clear();

					if(isSamePassword){
						if(username_text != "" && email_text != "" && password_text != ""){
							int errorDatabase = updateDatabase(clientReq, "register", clientRes);
							if(errorDatabase!=0){
								std::cout << "\nError initializing database" << std::endl;
							}
							else{
								username_component->deleteEditText();
								email_component->deleteEditText();
								password_component->deleteEditText();
								retype_password_component->deleteEditText();
								App->changeWindow_forward();
							}
						}
					}
					else{
						std::cout << "Passwords do not match" << std::endl;
					}
				}
			}
		}
		else{
			std::cout << "Fields can't be empty" << std::endl;
		}});

	// Connection for changing pages
	QObject::connect(signin_button_widget, &QPushButton::clicked, App, &StackedWidgets::changeWindow_forward);

    // Layout of the main UI
    QVBoxLayout *main_layout = new QVBoxLayout(window);
    main_layout->addWidget(main_widget);
    main_layout->setAlignment(Qt::AlignCenter);
    window->setLayout(main_layout);
}

void initLogin(StackedWidgets *App, QWidget* window) {

	window->setWindowTitle("Sign up");

    // Main Widget
    QWidget *main_widget = new QWidget(window);
    QVBoxLayout *main_widget_layout = new QVBoxLayout(main_widget);
    main_widget_layout->setAlignment(Qt::AlignCenter); // Center align the contents

    // Username Widget
    appUI *username = new appUI();
    username->init(window);
    QWidget *username_widget = username->getWidget();
    QHBoxLayout *username_layout = username->getHLayout();

    // Password Widget
    appUI *password = new appUI();
    password->init(window);
    QWidget *password_widget = password->getWidget();
    QHBoxLayout *password_layout = password->getHLayout();

    // Login Text Widget
    appText *login_text = new appText();
    login_text->init(window, "Login");
    QLabel *login_label = login_text->getWidget_label();

    // Submit Button Widget
    appButton *button = new appButton();
    button->init(window, "Submit");
    QPushButton *button_widget = button->getWidget_button();
	button_widget->setStyleSheet("QPushButton{background-color: #a2d9ce}");

    // Submit Button Widget
	appButton *signin_button = new appButton();
    signin_button->init(window, "Don't already have an account? Sign up", default_font_size*0.8);
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
    LabelEditComponent *username_component = new LabelEditComponent();
    LabelEditComponent *email_component = new LabelEditComponent();
    LabelEditComponent *password_component = new LabelEditComponent();

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
    main_widget_layout->addWidget(login_label);
    main_widget_layout->addWidget(username_widget);
    main_widget_layout->addWidget(password_widget);
    main_widget_layout->addWidget(button_container);
	main_widget_layout->addWidget(signin_button_container);

	// Connection of submit button with username and password text fields
	QObject::connect(button_widget, &QPushButton::clicked, username_component, &LabelEditComponent::updateEditText);
    QObject::connect(button_widget, &QPushButton::clicked, password_component, &LabelEditComponent::updateEditText);

	QObject::connect(button_widget, &QPushButton::clicked, 
	[=]() {
		std::string username_text, password_text;
		username_text = (username_component->getFieldText()).toStdString();
		password_text = (password_component->getFieldText()).toStdString();

		std::string clientReq = username_text + "\n";
		std::stringstream clientRes;
		std::string streamLine;
		std::vector<std::string> streamList;

		if(username_text != "" && password_text != ""){
			int errorDatabase = updateDatabase(clientReq, "query", clientRes);
			if(errorDatabase!=0){
				std::cout << "\nError initializing database" << std::endl;
			}
			else{
				while(getline(clientRes, streamLine, '\n')){
					streamList.push_back(streamLine);
					std::cout << "Streamline: " << streamLine << std::endl;
					std::cout << "Username: " << username_text << std::endl;
					std::cout << "Password: " << password_text << std::endl;
				}
				if(strcmp(username_text.c_str(), streamList[1].c_str())==0 
				&& strcmp(password_text.c_str(), streamList[3].c_str())==0) {
					int user_id = stoi(streamList[0]);
					std::cout << "You are logged in" << std::endl;
					std::cout << App->stacked_windows.currentIndex() << std::endl;
					initDashboard(
						App,
						App->stacked_windows.widget(App->stacked_windows.currentIndex()+1),
						QString(username_text.c_str()),
						user_id
					);
					cout << user_id << endl;
					username_component->deleteEditText();
					password_component->deleteEditText();
					App->changeWindow_forward();
				}
				else{
					std::cout << "Incorrect Credentials" << std::endl;
					username_component->usernameExists(false);
					password_component->usernameExists(false);
				}
			}
		}
		else{
			std::cout << "Fields can't be empty" << std::endl;
		}
		});

	// Connection for checking same password in both password fields
	QObject::connect(signin_button_widget, &QPushButton::clicked, App, &StackedWidgets::changeWindow_backward);

    // Layout of the main UI
    QVBoxLayout *main_layout = new QVBoxLayout(window);
    main_layout->addWidget(main_widget);
    main_layout->setAlignment(Qt::AlignCenter);
    window->setLayout(main_layout);
}
