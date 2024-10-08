#include "appUI.h"
#include <QtCore/QDebug>

// delete all contents of windows so new contents can be displayed
void deleteAllWidgetsAndLayouts(QWidget* widget) {
    if (!widget) return;

    // Recursively delete child widgets and layouts
    QLayout* layout = widget->layout();
    if (layout) {
        QLayoutItem* item;
        while ((item = layout->takeAt(0)) != nullptr) {
            if (item->widget()) {
                deleteAllWidgetsAndLayouts(item->widget());
            }
            delete item;
        }
        delete layout;
    }
}

void resetPage(QWidget* window) {
    if (!window) return;

    // Use a QPointer to safely manage the deletion process
    QPointer<QWidget> safeWidget(window);

    deleteAllWidgetsAndLayouts(safeWidget);

    // Ensure that the widget itself is not deleted if it is managed by its parent
    // This avoids potential double-free issues
}

appDesign::appDesign(){
	app_palette.setColor(QPalette::WindowText, QColor::fromRgbF(0, 0, 0));
    app_palette.setColor(QPalette::Button, QColor::fromRgbF(0.937255, 0.937255, 0.937255));
    app_palette.setColor(QPalette::Light, QColor::fromRgbF(1, 1, 1));
    app_palette.setColor(QPalette::Midlight, QColor::fromRgbF(0.793042, 0.793042, 0.793042));
    app_palette.setColor(QPalette::Dark, QColor::fromRgbF(0.624826, 0.624826, 0.624826));
    app_palette.setColor(QPalette::Mid, QColor::fromRgbF(0.720958, 0.720958, 0.720958));
    app_palette.setColor(QPalette::Text, QColor::fromRgbF(0, 0, 0));
    app_palette.setColor(QPalette::BrightText, QColor::fromRgbF(1, 1, 1));
    app_palette.setColor(QPalette::ButtonText, QColor::fromRgbF(0, 0, 0));
    app_palette.setColor(QPalette::Base, QColor::fromRgbF(1, 1, 1));
    app_palette.setColor(QPalette::Window, QColor::fromRgbF(0.937255, 0.937255, 0.937255));
    app_palette.setColor(QPalette::Shadow, QColor::fromRgbF(0.462821, 0.462821, 0.462821));
    app_palette.setColor(QPalette::Highlight, QColor::fromRgbF(0.188235, 0.54902, 0.776471));
    app_palette.setColor(QPalette::HighlightedText, QColor::fromRgbF(1, 1, 1));
    app_palette.setColor(QPalette::Link, QColor::fromRgbF(0, 0, 1));
    app_palette.setColor(QPalette::LinkVisited, QColor::fromRgbF(1, 0, 1));
    app_palette.setColor(QPalette::AlternateBase, QColor::fromRgbF(0.968627, 0.968627, 0.968627));
    app_palette.setColor(QPalette::ToolTipBase, QColor::fromRgbF(1, 1, 0.862745));
    app_palette.setColor(QPalette::ToolTipText, QColor::fromRgbF(0, 0, 0));
    app_palette.setColor(QPalette::PlaceholderText, QColor::fromRgbF(0, 0, 0, 0.5));
    app_palette.setColor(QPalette::Accent, QColor::fromRgbF(0.188235, 0.54902, 0.776471));

    app_style_sheet = R"(
    QWidget {
        color: #000000;
        background-color:  #e8daef;
    }
    QLineEdit {
        border: 2px solid #000000;
        padding: 5px;
    }
    QPushButton {
        border: 2px solid #000000;
        border-radius: 5px;
    }
    QPushButton:hover {
        background-color: #E0E0E0;
    }
    QPushButton:pressed {
        background-color: #D0D0D0;
    }
    QComboBox {
        border: 2px solid #000000;
        border-radius: 5px;
        padding: 5px;
       
    }
    QTableWidget {
        border: 1px solid #CCCCCC;
        background-color: #f4ecf7 ;
    }

    QHeaderView::section {
        background-color: #E0E0E0;
    }

    QTableWidget::item:selected {
        border: 1px solid #1889C1;
    }
    )";
}

void StackedWidgets::changeWindow_forward() {
    setCurrentIndex(stacked_windows.currentIndex()+1);
}

void StackedWidgets::changeWindow_backward() {
    setCurrentIndex(stacked_windows.currentIndex()-1);
}

void StackedWidgets::changeWindow_showLeague() {
    setCurrentIndex(5);
}

void StackedWidgets::changeWindow_dashboard() {
    setCurrentIndex(2);
}

TeamDialogBox::TeamDialogBox(QWidget *parent){
	setParent(parent);

	QVBoxLayout *team_layout = new QVBoxLayout(this);

	LabelEditComponent *team_component = new LabelEditComponent();
	team_component->init(this, "Team name");
	teamEdit = team_component->getWidget_edit();

	LabelEditComponent *team_ground_component = new LabelEditComponent();
	team_ground_component->init(this, "Venue");
	teamGroundEdit = team_ground_component->getWidget_edit();

	delete team_component->getWidget_label();
	delete team_ground_component->getWidget_label();

	QWidget *teamButtonContainer = new QWidget(this);
	QHBoxLayout *teamButtonContainerLayout = new QHBoxLayout(teamButtonContainer); 

	appButton *teamButton = new appButton();
	teamButton->init(this, "Add Icon");
	teamButton_widget = teamButton->getWidget_button();
    teamButton_widget->setStyleSheet("QPushButton{background-color: #a2d9ce}");

	teamButtonContainerLayout->addWidget(teamButton_widget, 0, Qt::AlignCenter);

	team_layout->addWidget(teamEdit);
	team_layout->addWidget(teamGroundEdit);
	team_layout->addWidget(teamButtonContainer);

	QObject::connect(teamButton_widget, &QPushButton::clicked, this, &TeamDialogBox::addIcon);
}

void TeamDialogBox::addIcon(){
	file_name = QFileDialog::getOpenFileName(this, "Select Icon", "", "Images (*.png)");
	if(!file_name.isEmpty()){
		icon.load(file_name);
		teamEdit->setText(QFileInfo(file_name).baseName());
	}
}

void TeamDialogBox::updateEditText() {
	if(QString(teamEdit->text()) == ""){
		team_name = "";
		teamEdit->setText("");
		teamEdit->setPlaceholderText("Field can't be empty");
		teamEdit->setStyleSheet("QLineEdit { placeholder-text-color: #FB3B3B }");
	}
	else{
		team_name = teamEdit->text();
	}
	if(QString(teamGroundEdit->text()) == ""){
		team_name = "";
		teamGroundEdit->setText("");
		teamGroundEdit->setPlaceholderText("Field can't be empty");
		teamGroundEdit->setStyleSheet("QLineEdit { placeholder-text-color: #FB3B3B }");
	}
	else{
		team_ground_name = teamGroundEdit->text();
	}
}

QString TeamDialogBox::getTeamName(){
	return team_name;
}

QString TeamDialogBox::getGroundName(){
	return team_ground_name;
}

QIcon TeamDialogBox::getTeamIcon(){
	return icon;
}

QString TeamDialogBox::getTeamIconPath(){
	return iconPath;
}

void appUI::init(QWidget* parent) {
    QSize widget_size(app_width, app_height / 10);

    app_widget = new QWidget(parent);
    app_widget->setFixedSize(widget_size);
    app_layout = new QHBoxLayout(app_widget);
    app_layout->setAlignment(Qt::AlignLeft);
    app_layout->setContentsMargins(app_width / 12, 0, 0, 0);
}

QWidget* appUI::getWidget() {
    return app_widget;
}

QHBoxLayout* appUI::getHLayout() {
    return app_layout;
}

void appText::init(QWidget* parent, QString text, int font_size) {
    app_text = new QLabel(parent);
    app_text->setFont(QFont("Sans", font_size));
    app_text->setText(text);
    app_text->setAlignment(Qt::AlignCenter);
    app_text->setMargin(app_width/42);
}

QLabel* appText::getWidget_label() {
    return app_text;
}

void appButton::init(QWidget* parent, QString text, int font_size) {
    button_widget = new QPushButton(parent);
    button_widget->setText(text);
    button_widget->setFont(QFont("Sans", font_size*0.6));
    button_widget->setFixedSize(QSize(app_width / 4, app_height / 16));
}

QPushButton* appButton::getWidget_button() {
    return button_widget;
}

void appClickableText::init(QWidget* parent, QString text, int font_size) {
	setParent(parent);
    setFont(QFont("Sans", font_size));
    setText(text);
    setMargin(app_width/42);
	setAlignment(Qt::AlignLeft);
	setCursor(Qt::PointingHandCursor);
	setFixedHeight(app_height/7);
}

void appClickableText::mousePressEvent(QMouseEvent* event){
	if(event->button() == Qt::LeftButton){
		emit clicked();
	}
}

MatchWidget::MatchWidget(QWidget* parent) {
	setParent(parent);
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

	// Create label for match number
    matchNumberLabel = new QLabel(parent);
    matchNumberLabel->setAlignment(Qt::AlignCenter);
	matchNumberLabel->setFont(QFont("Times", default_font_size*1.1));
    matchNumberLabel->setStyleSheet("font-weight: bold;");

	// Create label for match info
    matchGroundLabel = new QLabel(parent);
    matchGroundLabel->setAlignment(Qt::AlignCenter);
	matchGroundLabel->setFont(QFont("Sans", default_font_size*1.1));
	
    matchTimeLabel = new QLabel(parent);
    matchTimeLabel->setAlignment(Qt::AlignCenter);
	matchTimeLabel->setFont(QFont("Sans", default_font_size*0.8));

	// Create horizontal layout for the match details
    QWidget *matchDetailsWidget = new QWidget(parent);
    QHBoxLayout* matchDetailsLayout = new QHBoxLayout(matchDetailsWidget);

    // Create layouts for each team's information
    QWidget *team1Widget = new QWidget(parent);
    QVBoxLayout* team1Layout = new QVBoxLayout(team1Widget);
    QWidget *team2Widget = new QWidget(parent);
    QVBoxLayout* team2Layout = new QVBoxLayout(team2Widget);

    // Initialize team 1 widgets
    team1NameLabel = new QLabel(parent);
	team1NameLabel->setFont(QFont("Sans", default_font_size));
    team1NameLabel->setStyleSheet("font-weight: bold;");
	team1NameLabel->setAlignment(Qt::AlignCenter);

    team1IconLabel = new QLabel(parent);
    team1IconLabel->setAlignment(Qt::AlignCenter);
	
    team1ScoreLabel = new QLabel(parent);
	team1ScoreLabel->setFont(QFont("Sans", default_font_size));
    team1ScoreLabel->setAlignment(Qt::AlignCenter);

    team1Layout->addWidget(team1IconLabel);
    team1Layout->addWidget(team1NameLabel);
    team1Layout->addWidget(team1ScoreLabel);
	team1Layout->setAlignment(Qt::AlignCenter);

    // Initialize team 2 widgets
    team2NameLabel = new QLabel(parent);
	team2NameLabel->setFont(QFont("Sans", default_font_size));
    team2NameLabel->setStyleSheet("font-weight: bold;");
	team2NameLabel->setAlignment(Qt::AlignCenter);

    team2IconLabel = new QLabel(parent);
    team2IconLabel->setAlignment(Qt::AlignCenter);
	
    team2ScoreLabel = new QLabel(parent);
	team2ScoreLabel->setFont(QFont("Sans", default_font_size));
    team2ScoreLabel->setAlignment(Qt::AlignCenter);

    team2Layout->addWidget(team2IconLabel);
    team2Layout->addWidget(team2NameLabel);
    team2Layout->addWidget(team2ScoreLabel);
	team2Layout->setAlignment(Qt::AlignCenter);

	//Seperator
    QLabel *seperatorLabel = new QLabel(parent);
	seperatorLabel->setText("VS");
	seperatorLabel->setFont(QFont("Sans", default_font_size));

	QSpacerItem* spacer = new QSpacerItem(app_width/8, app_width/8, QSizePolicy::Fixed, QSizePolicy::Minimum);
	
    // Add team layouts to the main layout
    matchDetailsLayout->addWidget(team1Widget);
    matchDetailsLayout->addItem(spacer);
    matchDetailsLayout->addWidget(seperatorLabel);
    matchDetailsLayout->addItem(spacer);
    matchDetailsLayout->addWidget(team2Widget);

	mainLayout->addWidget(matchNumberLabel, 0, Qt::AlignTop);
	mainLayout->addWidget(matchDetailsWidget, 0, Qt::AlignTop);
	mainLayout->addWidget(matchGroundLabel, 0, Qt::AlignTop);
	mainLayout->addWidget(matchTimeLabel, 0, Qt::AlignTop);
}

void MatchWidget::init(const QString& matchNumber, 
					   const QString& team1Name, const QIcon& team1Icon, QString team1Score,
                       const QString& team2Name, const QIcon& team2Icon, QString team2Score,
					   const QString& matchGround, const QString& matchDate, const QString& matchTime) {
	matchNumberLabel->setText("Match: " + matchNumber);
	matchGroundLabel->setText("Venue: " + matchGround);
	matchTimeLabel->setText("Time: " + matchDate + "\n" + matchTime);

    team1NameLabel->setText(team1Name);
    team1IconLabel->setPixmap(team1Icon.pixmap(100, 100)); // Adjust icon size
    team1ScoreLabel->setText(team1Score);

    team2NameLabel->setText(team2Name);
    team2IconLabel->setPixmap(team2Icon.pixmap(100, 100)); // Adjust icon size
    team2ScoreLabel->setText(team2Score);

	team1NameLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    team2NameLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
}

EditableMatchWidget::EditableMatchWidget(QWidget* parent) : MatchWidget(parent) {
    // Remove the existing score labels
    QVBoxLayout *mainLayout = dynamic_cast<QVBoxLayout*>(layout());
    if (mainLayout) {
        QWidget *matchDetailsWidget = mainLayout->itemAt(1)->widget();
        QHBoxLayout *matchDetailsLayout = dynamic_cast<QHBoxLayout*>(matchDetailsWidget->layout());

        if (matchDetailsLayout) {
            QWidget *team1Widget = matchDetailsLayout->itemAt(0)->widget();
            QWidget *team2Widget = matchDetailsLayout->itemAt(4)->widget();
            
            QVBoxLayout *team1Layout = dynamic_cast<QVBoxLayout*>(team1Widget->layout());
            QVBoxLayout *team2Layout = dynamic_cast<QVBoxLayout*>(team2Widget->layout());

			// Update old score labels
			team1ScoreLabel->hide();
			team2ScoreLabel->hide();
			QLabel *team1GoalLabel = new QLabel();
            team1GoalLabel->setText("GOALS:");
            team1GoalLabel->setFont(QFont("Sans", default_font_size*0.8));
            team1GoalLabel->setContentsMargins(0,app_height/16,0,0);

			QLabel *team2GoalLabel = new QLabel();
            team2GoalLabel->setText("GOALS:");
            team2GoalLabel->setFont(QFont("Sans", default_font_size*0.8));
            team2GoalLabel->setContentsMargins(0,app_height/16,0,0);
            
            // Initialize input fields for scores
			QIntValidator* validator = new QIntValidator(0, 20, parent);

            team1ScoreInput = new QLineEdit(parent);
            team1ScoreInput->setAlignment(Qt::AlignCenter);
            team1ScoreInput->setFixedSize(app_width/4, app_height/10);
			team1ScoreInput->setFont(QFont("Sans", default_font_size*0.8));
            team1ScoreInput->setValidator(validator);
            
            team2ScoreInput = new QLineEdit(parent);
            team2ScoreInput->setAlignment(Qt::AlignCenter);
            team2ScoreInput->setFixedSize(app_width/4, app_height/10);
			team2ScoreInput->setFont(QFont("Sans", default_font_size*0.8));
            team2ScoreInput->setValidator(validator);

			QObject::connect(team1ScoreInput, &QLineEdit::textEdited, [this](){
				team1ScoreInput->setPlaceholderText("");
				QPalette palette = team1ScoreInput->palette();
				palette.setColor(QPalette::PlaceholderText, QColor(0, 0, 0, 128));
				team1ScoreInput->setPalette(palette);
			});
            
            team1Layout->addWidget(team1GoalLabel, 0, Qt::AlignHCenter);
			team1Layout->addWidget(team1ScoreInput, 0, Qt::AlignHCenter);
            
			team2Layout->addWidget(team2GoalLabel, 0, Qt::AlignHCenter);
			team2Layout->addWidget(team2ScoreInput, 0, Qt::AlignHCenter);

            team1ScoreInput->setVisible(true);
            team2ScoreInput->setVisible(true);
        }
    }
}

void LabelEditComponent::init(QWidget* parent, QString widget_text, int font_size) {
    widget_label = new QLabel(parent);
    widget_label->setFont(QFont("Sans", font_size*0.8));
    widget_label->setText(widget_text);
    widget_label->setAlignment(Qt::AlignLeft);
    widget_label->setFixedSize(QSize(app_width / 6, app_height / 10));
    widget_label->setContentsMargins(0, app_height / 40, 0, 0);

    widget_edit = new QLineEdit(parent);
    widget_edit->setFixedSize(QSize(app_width * 2 / 3, app_height / 10));
    widget_edit->setFont(QFont("Sans", font_size*0.8));
    widget_edit->setPlaceholderText(widget_text);     
	
	QObject::connect(widget_edit, &QLineEdit::textEdited, [this, widget_text](){
		widget_edit->setPlaceholderText(widget_text);
		QPalette palette = widget_edit->palette();
		palette.setColor(QPalette::PlaceholderText, QColor(0, 0, 0, 128));
		widget_edit->setPalette(palette);
	});

    widget_edit->setAlignment(Qt::AlignLeft);
    widget_edit->setTextMargins(20, 0, 0, 5);
}

QLabel* LabelEditComponent::getWidget_label() {
    return widget_label;
}

QLineEdit* LabelEditComponent::getWidget_edit() {
    return widget_edit;
}

QString LabelEditComponent::getFieldText(){
	return field_text;
}

void LabelEditComponent::updateEditText() {
	if(QString(widget_edit->text()) == ""){
		field_text = "";
		widget_edit->setText("");
		widget_edit->setPlaceholderText("Field can't be empty");
		widget_edit->setStyleSheet("QLineEdit { placeholder-text-color: #FB3B3B }");
	}
	else{
		field_text = widget_edit->text();
	}
}

void LabelEditComponent::deleteEditText() {
	widget_edit->setText("");
	field_text = "";
}

void LabelEditComponent::usernameExists(bool userExists) {
	if(userExists){
		field_text = "";
		widget_edit->setText("");
		widget_edit->setPlaceholderText("Username already exists");
		widget_edit->setStyleSheet("QLineEdit { placeholder-text-color: #FB3B3B }");
	}
	else{
		field_text = "";
		widget_edit->setText("");
		widget_edit->setPlaceholderText("Incorrect Credentials");
		widget_edit->setStyleSheet("QLineEdit { placeholder-text-color: #FB3B3B }");
	}
}

bool LabelEditComponent::checkSamePassword(LabelEditComponent* retype_password_component) {
    if(QString(this->widget_edit->text()) == QString(retype_password_component->widget_edit->text())){
		qDebug(qUtf8Printable(this->widget_edit->text()));
		return true;
	}
	else{
		this->widget_edit->setText("");
		this->widget_edit->setPlaceholderText("Passwords don't match");
		this->widget_edit->setStyleSheet("QLineEdit { placeholder-text-color: #FB3B3B }");
		retype_password_component->widget_edit->setText("");
		retype_password_component->widget_edit->setPlaceholderText("Passwords don't match");
		retype_password_component->widget_edit->setStyleSheet("QLineEdit { placeholder-text-color: #FB3B3B }");
		return false;
	}
}

void LabelEditComponent::togglePasswordVisibility(QPushButton *showButton){
	if(widget_edit->echoMode() == QLineEdit::Password){
		widget_edit->setEchoMode(QLineEdit::Normal);
		showButton->setIcon(QIcon("requisite/assets/images/eye_hidden.png"));
	}
	else if(widget_edit->echoMode() == QLineEdit::Normal){
		widget_edit->setEchoMode(QLineEdit::Password);
		showButton->setIcon(QIcon("requisite/assets/images/eye_shown.png"));
	}
}

void LabelComboComponent::init(
	QWidget* parent,
	QString widget_text,
	QStringList combobox_list,
	int font_size)
	{
	widget_label = new QLabel(parent);
    widget_label->setFont(QFont("Sans", font_size*0.8));
    widget_label->setText(widget_text);
    widget_label->setAlignment(Qt::AlignLeft);
	widget_label->setContentsMargins(0,20,0,0);
    widget_label->setFixedSize(QSize(app_width / 3, app_height / 10));

    widget_combobox = new QComboBox(parent);
    widget_combobox->setFixedSize(QSize(app_width*63/100, app_height / 10));
    widget_combobox->setFont(QFont("Sans", font_size*0.9));
    widget_combobox->addItems(combobox_list);
}

QLabel* LabelComboComponent::getWidget_label() {
    return widget_label;
}

QComboBox* LabelComboComponent::getWidget_combo() {
    return widget_combobox;
}

int LabelComboComponent::getComboNumber() {
    combo_number = widget_combobox->currentText().toInt();
	return combo_number;
}