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

    QObject::connect(spinBox, &QSpinBox::valueChanged,
                     label, qOverload<int>(&QLabel::setNum));
    QObject::connect(spinBox, &QSpinBox::valueChanged,
                     slider, &QSlider::setValue);
    QObject::connect(slider, &QSlider::valueChanged,
                     label, qOverload<int>(&QLabel::setNum));
    QObject::connect(slider, &QSlider::valueChanged,
                     spinBox, &QSpinBox::setValue);

    window.show();

    return a.exec();
}
