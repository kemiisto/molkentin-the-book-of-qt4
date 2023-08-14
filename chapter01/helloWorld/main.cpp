#include <QApplication>
#include <QLabel>

int main(int argc, char* argv[]) {
    auto a = QApplication{argc, argv};

    auto label = QLabel{"Hello World"};
    label.show();

    return QApplication::exec();
}
