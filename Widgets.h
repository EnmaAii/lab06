#ifndef WIDGETS_H
#define WIDGETS_H
#include <QObject>
#include <QLabel>
#include <QSlider>
#include <QScrollBar>
#include <QSpinBox>
#include <QVector>

class Widgets: public QObject
{
    Q_OBJECT//Для использования механизма сигналов и слотов объявление класса
    //должно содержать специальный макрос Q_OBJECT
    QVector<QWidget*> widgets;
public:
    Widgets(QObject *parent = nullptr) : QObject(parent) {}
    void printWidgets() const;
    void addWidget(QWidget* widget);
    void connectWidgets();
public slots:
    void handleLinkActivated(const QString &link)
    {
        qDebug() << "Link activated: " << link;
    }

    void handleValueChanged(int value)
    {
        qDebug() << "Value changed: " << value;
    }

    void handleScrollValueChanged(int value)
    {
        qDebug() << "Scroll value changed: " << value;
    }

    void handleSpinBoxValueChanged(int value)
    {
        qDebug() << "SpinBox value changed: " << value;
    }

};

#endif // WIDGETS_H
