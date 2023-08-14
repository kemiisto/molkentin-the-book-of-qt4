#include <QApplication>
#include <QVBoxLayout>
#include <QLabel>

int main(int argc, char* argv[]) {
    auto a = QApplication{argc, argv};

    auto window = QWidget{};

    auto* mainLayout = new QVBoxLayout{&window};
    auto* label1 = new QLabel{"One"};
    auto* label2 = new QLabel{"Two"};

    mainLayout->addWidget(label1);
    mainLayout->addWidget(label2);

    window.show();

    return QApplication::exec();
}
