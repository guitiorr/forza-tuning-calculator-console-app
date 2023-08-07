#include <QApplication>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Create the main window
    QWidget *window = new QWidget();
    window->setWindowTitle("Tuning Calculator");

    // Create the input fields
    QLineEdit *minInput = new QLineEdit();
    QLineEdit *maxInput = new QLineEdit();
    QLineEdit *frontInput = new QLineEdit();

    // Create the output labels
    QLabel *frontOutput = new QLabel();
    QLabel *backOutput = new QLabel();

    // Create the calculate button
    QPushButton *calculateButton = new QPushButton("Calculate");

    // Create the layout
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(new QLabel("Min:"));
    layout->addWidget(minInput);
    layout->addWidget(new QLabel("Max:"));
    layout->addWidget(maxInput);
    layout->addWidget(new QLabel("Front:"));
    layout->addWidget(frontInput);
    layout->addWidget(calculateButton);
    layout->addWidget(new QLabel("Tuning front:"));
    layout->addWidget(frontOutput);
    layout->addWidget(new QLabel("Tuning back:"));
    layout->addWidget(backOutput);
    window->setLayout(layout);

    // Connect the calculate button to the calculation code
    QObject::connect(calculateButton, &QPushButton::clicked, [=]() {
        double min = minInput->text().toDouble();
        double max = maxInput->text().toDouble();
        double front = frontInput->text().toDouble();
        double back = 100 - front;
        back /= 100;
        front /= 100;
        frontOutput->setText(QString("Tuning front: %1").arg((max - min) * front + min));
        backOutput->setText(QString("Tuning back: %1").arg((max - min) * back + min));
    });

    // Show the window and start the event loop
    window->show();
    return app.exec();
}
