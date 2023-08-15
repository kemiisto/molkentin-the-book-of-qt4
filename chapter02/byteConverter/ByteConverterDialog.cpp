#include "ByteConverterDialog.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QIntValidator>
#include <QRegularExpressionValidator>

ByteConverterDialog::ByteConverterDialog() {
    // Generate the necessary layouts
    auto* mainLayout = new QVBoxLayout(this);
    auto* editLayout = new QGridLayout;
    auto* buttonLayout = new QHBoxLayout;

    mainLayout->addLayout(editLayout);
    mainLayout->addStretch();
    mainLayout->addLayout(buttonLayout);

    // Generate the labels and line-edits and add them to the object pointed at by editLayout
    auto* decLabel = new QLabel(tr("Decimal"));
    auto* hexLabel = new QLabel(tr("Hex"));
    auto* binLabel = new QLabel(tr("Binary"));
    decEdit = new QLineEdit;
    hexEdit = new QLineEdit;
    binEdit = new QLineEdit;

    editLayout->addWidget(decLabel, 0, 0);
    editLayout->addWidget(decEdit, 0, 1);
    editLayout->addWidget(hexLabel, 1, 0);
    editLayout->addWidget(hexEdit, 1, 1);
    editLayout->addWidget(binLabel, 2, 0);
    editLayout->addWidget(binEdit, 2, 1);

    // Create the Quit button and add it to the object pointed at by buttonLayout
    auto* exitButton = new QPushButton(tr("Quit"));

    buttonLayout->addStretch();
    buttonLayout->addWidget(exitButton);

    exitButton->setDefault(true);

    // Limit input to valid values
    auto* decValidator = new QIntValidator(0, 255, decEdit);
    decEdit->setValidator(decValidator);

    auto* hexValidator =
        new QRegularExpressionValidator(QRegularExpression("[0-9A-Fa-f]{1,2}"), hexEdit);
    hexEdit->setValidator(hexValidator);

    auto* binValidator =
        new QRegularExpressionValidator(QRegularExpression("[01]{1,8}"), binEdit);
    binEdit->setValidator(binValidator);

    setWindowTitle(tr("Byte Converter"));

    connect(exitButton, &QPushButton::clicked,
            this, &ByteConverterDialog::accept);
    connect(decEdit, &QLineEdit::textChanged,
            this, &ByteConverterDialog::decChanged);
    connect(hexEdit, &QLineEdit::textChanged,
            this, &ByteConverterDialog::hexChanged);
    connect(binEdit, &QLineEdit::textChanged,
            this, &ByteConverterDialog::binChanged);
}

void ByteConverterDialog::decChanged(const QString& newValue) {
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

void ByteConverterDialog::hexChanged(const QString& newValue) {
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

void ByteConverterDialog::binChanged(const QString& newValue) {
    bool ok;
    int num = newValue.toInt(&ok, 2);
    if (ok) {
        decEdit->setText(QString::number(num));
        hexEdit->setText(QString::number(num, 16));
    } else {
        decEdit->setText("");
        hexEdit->setText("");
    }
}
