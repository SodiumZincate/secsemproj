#include "WidgetComponent.h"

extern int app_height, app_width;

void WidgetComponent::init(QWidget* parent, QString widget_text){
    widget_label = new QLabel(parent);
    widget_label->setFont(QFont("Sans", 28));
    widget_label->setText(widget_text);
    widget_label->setAlignment(Qt::AlignLeft);
    widget_label->setFixedSize(QSize(app_width/6, app_height/10));
    widget_label->setContentsMargins(0,app_height/40,0,0);

    widget_edit = new QLineEdit(parent);
    widget_edit->setFixedSize(QSize(app_width*2/3, app_height/10));
    widget_edit->setFont(QFont("Sans", 24));
    widget_edit->setPlaceholderText(widget_text);
    widget_edit->setAlignment(Qt::AlignLeft);
    widget_edit->setTextMargins(20, 0, 0, 5);
}

QLabel* WidgetComponent::getWidget_label(){
    return widget_label;
}

QLineEdit* WidgetComponent::getWidget_edit(){
    return widget_edit;
}