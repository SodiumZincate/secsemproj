#include "LoginWidget.h"
#include <iostream>

extern int app_width, app_height;

LoginWidget::LoginWidget(QWidget *parent_widget){
    sub_widget = new QWidget(parent_widget);
    sub_widget_size = QSize(app_width, app_height/10);
    sub_widget->setFixedSize(sub_widget_size);
    
    sub_widget_layout = new QHBoxLayout(sub_widget);
    sub_widget_layout->setAlignment(Qt::AlignLeft);
    sub_widget_layout->setContentsMargins(0,app_width/12,0,0);
}

void LoginWidget::addWidget(WidgetComponent* temp_widget_component){
    QLabel *widget1 = temp_widget_component->getWidget_desc();
    QLineEdit *widget2 = temp_widget_component->getWidget_edit();
    sub_widget_layout->addWidget(widget1);
    sub_widget_layout->addWidget(widget2);
}

QWidget* LoginWidget::getWidget(){
    return sub_widget;
}