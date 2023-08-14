#include <QApplication>
#include <QGridLayout>
#include <QLabel>

int main(int argc, char* argv[]) {
    auto a = QApplication{argc, argv};

    auto window = QWidget{};

    auto* mainLayout = new QGridLayout(&window);
    auto* label1 = new QLabel("One");
    auto* label2 = new QLabel("Two");
    auto* label3 = new QLabel("Three");
    auto* label4 = new QLabel("Four");
    auto* label5 = new QLabel("Five");
    auto* label6 = new QLabel("Six");

    mainLayout->addWidget(label1, 0, 0);
    mainLayout->addWidget(label2, 0, 1);
    mainLayout->addWidget(label3, 1, 0);
    mainLayout->addWidget(label4, 1, 1);
    mainLayout->addWidget(label5, 2, 0);
    mainLayout->addWidget(label6, 2, 1);

    window.show();

    return QApplication::exec();
}
