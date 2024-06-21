#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QFont>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Main window
    QWidget mainWindow;
    mainWindow.setWindowTitle("Rectangle with Centered Labels Example");

    // Create a rectangle widget
    QWidget *rectangleWidget = new QWidget(&mainWindow);
    rectangleWidget->setGeometry(50, 50, 400, 200); // Position (50, 50) and size (400x200)

    // Layout for the rectangle widget
    QVBoxLayout *rectangleLayout = new QVBoxLayout(rectangleWidget);
    rectangleLayout->setAlignment(Qt::AlignCenter); // Align contents to center

    // Adding labels to the rectangle layout
    QLabel *label1 = new QLabel("Label 1", rectangleWidget);
    QLabel *label2 = new QLabel("Label 2", rectangleWidget);
    QLabel *label3 = new QLabel("Label 3", rectangleWidget);

    // Set font for labels
    QFont font("Times New Roman", 24);
    label1->setFont(font);
    label2->setFont(font);
    label3->setFont(font);

    // Align labels to center
    label1->setAlignment(Qt::AlignCenter);
    label2->setAlignment(Qt::AlignCenter);
    label3->setAlignment(Qt::AlignCenter);

    rectangleLayout->addWidget(label1);
    rectangleLayout->addWidget(label2);
    rectangleLayout->addWidget(label3);

    // Main window layout
    QVBoxLayout *mainLayout = new QVBoxLayout(&mainWindow);
    mainLayout->addWidget(rectangleWidget);

    mainWindow.setLayout(mainLayout);
    mainWindow.resize(500, 300); // Set initial size of the main window
    mainWindow.show();

    return app.exec();
}
