#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QObject>
#include <QWidget>
#include <QHBoxLayout>
#include "WidgetComponent.h"

class WidgetComponent;

class LoginWidget : public QObject{
    Q_OBJECT
    private:
        QWidget *sub_widget;
        QHBoxLayout *sub_widget_layout;
        QSize sub_widget_size;
    public: 
        LoginWidget(QWidget*);
        QWidget* getWidget();
        void addWidget(WidgetComponent* temp_widget_component);
};

#endif