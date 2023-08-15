#include <QApplication>
#include <QPushButton>

int main(int argc, char* argv[]) {
    auto a = QApplication{argc, argv};

    auto button = QPushButton{"Quit"};
    button.show();
    QObject::connect(&button, &QPushButton::clicked, &a, &QApplication::quit);

    return QApplication::exec();
}
