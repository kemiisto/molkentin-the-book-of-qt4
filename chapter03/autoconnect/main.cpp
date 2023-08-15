#include "byteconverterdialog.h"
#include <QtGui>

int main(int argc, char* argv[]) {
    auto app = QApplication{argc, argv};

    auto dlg = ByteConverterDialog{};
    dlg.setAttribute(Qt::WA_QuitOnClose);
    dlg.show();

    return QApplication::exec();
}
