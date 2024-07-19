#include "appUI.h"
#include <QtCore/QDebug>

// delete all contents of windows(dashboardApp) so new contents can be displayed
void resetPage(QWidget* window){
	if ( window->layout() != NULL )
	{
		QLayoutItem* item;
		while ( ( item = window->layout()->takeAt( 0 ) ) != NULL )
		{
			delete item->widget();
			delete item;
		}
		delete window->layout();
	}
}

void StackedWidgets::changeWindow_forward() {
    setCurrentIndex(stacked_windows.currentIndex()+1);
	std::cout << stacked_windows.currentIndex() << std::endl;
}

void StackedWidgets::changeWindow_backward() {
    setCurrentIndex(stacked_windows.currentIndex()-1);
	std::cout << stacked_windows.currentIndex() << std::endl;
}


void appUI::init(QWidget* parent) {
    QSize widget_size(app_width, app_height / 10);

    login_widget = new QWidget(parent);
    login_widget->setFixedSize(widget_size);
    login_layout = new QHBoxLayout(login_widget);
    login_layout->setAlignment(Qt::AlignLeft);
    login_layout->setContentsMargins(app_width / 12, 0, 0, 0);
}

QWidget* appUI::getWidget() {
    return login_widget;
}

QHBoxLayout* appUI::getHLayout() {
    return login_layout;
}

void appText::init(QWidget* parent, QString text, int font_size) {
    login_text = new QLabel(parent);
    login_text->setFont(QFont("Sans", font_size));
    login_text->setText(text);
    login_text->setAlignment(Qt::AlignCenter);
    login_text->setMargin(app_width/42);
}

QLabel* appText::getWidget_label() {
    return login_text;
}

void appButton::init(QWidget* parent, QString text, int font_size) {
    button_widget = new QPushButton(parent);
    button_widget->setText(text);
    button_widget->setFont(QFont("Sans", font_size - 12));
    button_widget->setFixedSize(QSize(app_width / 4, app_height / 16));
}

QPushButton* appButton::getWidget_button() {
    return button_widget;
}

void LabelEditComponent::init(QWidget* parent, QString widget_text) {
    widget_label = new QLabel(parent);
    widget_label->setFont(QFont("Sans", default_font_size - 6));
    widget_label->setText(widget_text);
    widget_label->setAlignment(Qt::AlignLeft);
    widget_label->setFixedSize(QSize(app_width / 6, app_height / 10));
    widget_label->setContentsMargins(0, app_height / 40, 0, 0);

    widget_edit = new QLineEdit(parent);
    widget_edit->setFixedSize(QSize(app_width * 2 / 3, app_height / 10));
    widget_edit->setFont(QFont("Sans", default_font_size - 10));
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
    widget_label->setFont(QFont("Sans", font_size));
    widget_label->setText(widget_text);
    widget_label->setAlignment(Qt::AlignLeft);
	widget_label->setContentsMargins(0,20,0,0);
    widget_label->setFixedSize(QSize(app_width / 3, app_height / 10));

    widget_combobox = new QComboBox(parent);
    widget_combobox->setFixedSize(QSize(app_width*63/100, app_height / 10));
    widget_combobox->setFont(QFont("Sans", font_size));
    widget_combobox->addItems(combobox_list);
}

QLabel* LabelComboComponent::getWidget_label() {
    return widget_label;
}

QComboBox* LabelComboComponent::getWidget_combo() {
    return widget_combobox;
}