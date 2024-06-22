#ifndef WIDGETCOMPONENT_H
#define WIDGETCOMPONENT_H

#include <QObject>
#include <QLabel>
#include <QLineEdit>
#include <QFont>
#include <QSize>

class WidgetComponent : public QObject{
    Q_OBJECT
    private:
        QLabel *widget_desc;
        QLineEdit *widget_edit;
        QSize component_container;
        QSize description_container;
        QFont description_font;
        QFont component_font;
    public:
        WidgetComponent(QWidget*, QString);
        QLabel* getWidget_desc();
        QLineEdit* getWidget_edit();
};

#endif