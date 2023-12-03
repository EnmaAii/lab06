#include "widgets.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widgets collection;
    QLabel *label = new QLabel("I'm still standing");
    QSlider *slider = new QSlider(Qt::Horizontal);
    QScrollBar scrollbar;
    QSpinBox spinbox;
    collection.addWidget(label);
    collection.addWidget(slider);
    collection.connectWidgets();
    collection.addWidget(&scrollbar);
    collection.addWidget(&spinbox);
    collection.printWidgets();
    return a.exec();
}
