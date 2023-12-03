#include "widgets.h"
void Widgets:: addWidget(QWidget* widget)
{
    widgets.append(widget);
}
void Widgets:: printWidgets() const{
    for (int i = 0; i < widgets.size(); ++i)
    {
        qDebug() << "Widget" << i << ":" << widgets[i]->objectName();
    }
}
void Widgets:: connectWidgets(){
    for (auto widget : widgets) //Сигнал может быть соединён со слотом или другим сигналом с помощью функции connect().
    {
        QLabel* label = qobject_cast<QLabel*>(widget);
        if (label)
        {
            connect(label, &QLabel::linkActivated, this, &Widgets::handleLinkActivated);
            continue;
        }

        QSlider* slider = qobject_cast<QSlider*>(widget);
        if (slider)
        {
            connect(slider, &QSlider::valueChanged, this, &Widgets::handleValueChanged);
            continue;
        }

        QScrollBar* scrollBar = qobject_cast<QScrollBar*>(widget);
        if (scrollBar)
        {
            connect(scrollBar, &QScrollBar::valueChanged, this, &Widgets::handleScrollValueChanged);
            continue;
        }

        QSpinBox* spinBox = qobject_cast<QSpinBox*>(widget);
        if (spinBox)
        {
            connect(spinBox, QOverload<int>::of(&QSpinBox::valueChanged), this, &Widgets::handleSpinBoxValueChanged);
            continue;
        }
    }
}
