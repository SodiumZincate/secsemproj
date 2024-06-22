#include "WidgetComponent.h"
#include <iostream>

extern int app_width, app_height;

WidgetComponent::WidgetComponent(QWidget *sub_widget, QString component_text){
    // Create and configure QLabel for the description
    widget_desc = new QLabel(sub_widget);
    description_container = QSize(app_width / 6, app_height / 10);
    description_font = QFont("Sans", 28);
    widget_desc->setText(component_text);
    widget_desc->setFont(description_font);
    widget_desc->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    widget_desc->setFixedSize(description_container);
    widget_desc->setContentsMargins(0, app_height / 40, 0, 0);

    // Create and configure QLineEdit for the input
    widget_edit = new QLineEdit(sub_widget);
    component_container = QSize(app_width * 2 / 3, app_height / 10);
    component_font = QFont("Sans", 24);
    widget_edit->setPlaceholderText(component_text);
    widget_edit->setFont(component_font);
    widget_edit->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    widget_edit->setFixedSize(component_container);
    widget_edit->setTextMargins(20, 0, 0, 0);  // Adjust text margins if needed
}

QLabel* WidgetComponent::getWidget_desc(){
        std::cout << "NO" << std::endl;
    return widget_desc;
}

QLineEdit* WidgetComponent::getWidget_edit(){
        std::cout << "NO" << std::endl;
    return widget_edit;
}
