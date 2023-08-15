#include <QtGui>
#include "byteconverterdialog.h"

ByteConverterDialog::ByteConverterDialog(QWidget* parent)
    : QDialog(parent)
{
    setupUi(this);

    connect(decEdit, &QLineEdit::textChanged,
            this, &ByteConverterDialog::decChanged);
    connect(hexEdit, &QLineEdit::textChanged,
            this, &ByteConverterDialog::hexChanged);
    connect(binEdit, &QLineEdit::textChanged,
            this, &ByteConverterDialog::binChanged);
}

void ByteConverterDialog::decChanged(const QString& newValue)
{
    bool ok;
    int num = newValue.toInt(&ok);
    if (ok) {
        hexEdit->setText(QString::number(num, 16));
        binEdit->setText(QString::number(num, 2));
    } else {
        hexEdit->setText("");
        binEdit->setText("");
    }
}

void ByteConverterDialog::hexChanged(const QString& newValue)
{
    bool ok;
    int num = newValue.toInt(&ok, 16);
    if (ok) {
        decEdit->setText(QString::number(num));
        binEdit->setText(QString::number(num, 2));
    } else {
        decEdit->setText("");
        binEdit->setText("");
    }
}

void ByteConverterDialog::binChanged(const QString& newValue)
{
    bool ok;
    int num = newValue.toInt(&ok, 2);
    if (ok) {
        decEdit->setText(QString::number(num));
        hexEdit->setText(QString::number(num, 16));
    } else {
    }
}
