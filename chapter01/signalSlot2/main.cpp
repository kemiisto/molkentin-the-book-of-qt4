#include <QApplication>
#include <QVBoxLayout>
#include <QLabel>
#include <QSpinBox>
#include <QSlider>

int main(int argc, char* argv[]) {
    auto a = QApplication{argc, argv};

    auto window = QWidget{};

    auto* mainLayout = new QVBoxLayout{&window};
    auto* label = new QLabel{"0"};
    auto* spinBox = new QSpinBox{};
    auto* slider = new QSlider{Qt::Horizontal};

    mainLayout->addWidget(label);
    mainLayout->addWidget(spinBox);
    mainLayout->addWidget(slider);

#if QT_VERSION < QT_VERSION_CHECK(5, 7, 0)
    QObject::connect(spinBox, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
                     label, static_cast<void (QLabel::*)(int)>(&QLabel::setNum));
    QObject::connect(spinBox, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
                     slider, &QSlider::setValue);
    QObject::connect(slider, &QSlider::valueChanged,
                     label, static_cast<void (QLabel::*)(int)>(&QLabel::setNum));
    
#else
    QObject::connect(spinBox, qOverload<int>(&QSpinBox::valueChanged),
                     label, qOverload<int>(&QLabel::setNum));
    QObject::connect(spinBox, qOverload<int>(&QSpinBox::valueChanged),
                     slider, &QSlider::setValue);
    QObject::connect(slider, &QSlider::valueChanged,
                     label, qOverload<int>(&QLabel::setNum));
#endif    
    QObject::connect(slider, &QSlider::valueChanged,
                     spinBox, &QSpinBox::setValue);

    window.show();

    return QApplication::exec();
}
