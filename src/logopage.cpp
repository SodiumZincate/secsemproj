#include "appUI.h"
#include "db.h"
#include "logic.h"

void initLeagueIcon(StackedWidgets *App, QWidget* window){

    QWidget *main_widget = new QWidget(window);
    main_widget->setFixedSize(app_width * 3 / 2, app_height * 3 / 2);
    QVBoxLayout *main_widget_layout = new QVBoxLayout(main_widget);
    main_widget_layout->setAlignment(Qt::AlignCenter);

	QPushButton *leagueIcon = new QPushButton(window);
	QPixmap pixmap("requisite/assets/images/leaguepage_icon.jpeg");

	QPixmap scaledPixmap = pixmap.scaled(app_width * 3 / 2, app_height * 3 / 2, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    QIcon icon(scaledPixmap);

	// Set the icon and adjust the button size
    leagueIcon->setIcon(icon);
    leagueIcon->setIconSize(scaledPixmap.size());
    leagueIcon->setFixedSize(scaledPixmap.size());

    // Add the button to the main widget layout
    main_widget_layout->addWidget(leagueIcon);

    QVBoxLayout *main_layout = new QVBoxLayout(window);
    main_layout->addWidget(main_widget);
    main_layout->setAlignment(Qt::AlignCenter);
    window->setLayout(main_layout);

	 QTimer::singleShot(2000, [=]() {
        // Create a QGraphicsOpacityEffect to control the opacity
        QGraphicsOpacityEffect *opacityEffect = new QGraphicsOpacityEffect(leagueIcon);
        leagueIcon->setGraphicsEffect(opacityEffect);

        // Create the animation to change opacity from 1.0 to 0.0 over 2 seconds
        QPropertyAnimation *fadeOutAnimation = new QPropertyAnimation(opacityEffect, "opacity");
        fadeOutAnimation->setDuration(2000);
        fadeOutAnimation->setStartValue(1.0);
        fadeOutAnimation->setEndValue(0.0);

        QObject::connect(fadeOutAnimation, &QPropertyAnimation::finished, [=]() {
            qDebug() << "Fade-out animation finished.";
            App->setCurrentIndex(1);
        });

        // Start the animation
        fadeOutAnimation->start(QAbstractAnimation::DeleteWhenStopped);
    });
}