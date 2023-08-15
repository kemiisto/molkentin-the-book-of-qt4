#include <QApplication>
#include "ByteConverterDialog.h"

int main(int argc, char* argv[]) {
    auto a = QApplication{argc, argv};

    auto bc = ByteConverterDialog{};
    bc.setAttribute(Qt::WA_QuitOnClose);
    bc.show();

    return QApplication::exec();
}
