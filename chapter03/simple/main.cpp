#include <QtGui>

#include "ui_byteconverterdialog.h"

int main(int argc, char* argv[]) {
    auto app = QApplication{argc, argv};

    auto dlg = QDialog{};
    auto ui = Ui::ByteConverterDialog{};
    ui.setupUi(&dlg);
    dlg.setAttribute(Qt::WA_QuitOnClose);
    dlg.show();

    return QApplication::exec();
}
