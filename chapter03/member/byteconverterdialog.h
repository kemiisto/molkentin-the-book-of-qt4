#ifndef BYTECONVERTERDIALOG_H
#define BYTECONVERTERDIALOG_H

#include <QDialog>
#include "ui_byteconverterdialog.h"

class QLineEdit;

class ByteConverterDialog : public QDialog {
    Q_OBJECT
public:
    explicit ByteConverterDialog(QWidget* parent = nullptr);
private slots:
    void decChanged(const QString&);
    void hexChanged(const QString&);
    void binChanged(const QString&);
private:
    Ui::ByteConverterDialog ui{};
};

#endif
