#pragma once

#include <QObject>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QWidget>

class WidgetComponent{
    private:
        QLabel *widget_label;
        QLineEdit *widget_edit;
    public:
        void init(QWidget*, QString);
        QLabel* getWidget_label();
        QLineEdit* getWidget_edit();
};