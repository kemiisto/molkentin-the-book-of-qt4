#include "ByteConverterDialog.h"
#include "ByteConverter.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QIntValidator>
#include <QRegularExpressionValidator>

ByteConverterDialog::ByteConverterDialog() {
    // Create the layouts needed.
    auto* mainLayout = new QVBoxLayout(this);
    auto* editLayout = new QGridLayout;
    auto* buttonLayout = new QHBoxLayout;

    mainLayout->addLayout(editLayout);
    mainLayout->addStretch();
    mainLayout->addLayout(buttonLayout);

    // Create labels and line edits and add them to editLayout
    auto* decLabel = new QLabel(tr("Decimal"));
    auto* hexLabel = new QLabel(tr("Hex"));
    auto* binLabel = new QLabel(tr("Binary"));
    auto* decEdit = new QLineEdit;
    auto* hexEdit = new QLineEdit;
    auto* binEdit = new QLineEdit;

    editLayout->addWidget(decLabel, 0, 0);
    editLayout->addWidget(decEdit, 0, 1);
    editLayout->addWidget(hexLabel, 1, 0);
    editLayout->addWidget(hexEdit, 1, 1);
    editLayout->addWidget(binLabel, 2, 0);
    editLayout->addWidget(binEdit, 2, 1);

    // Create "Quit" button and add it to buttonLayout
    auto* exitButton = new QPushButton(tr("Quit"));

    buttonLayout->addStretch();
    buttonLayout->addWidget(exitButton);

    // Set window title and default button
    setWindowTitle(tr("Byte Converter"));
    exitButton->setDefault(true);

    // Limit input to valid values
    auto* decValidator =
        new QIntValidator(0, 255, decEdit);
    decEdit->setValidator(decValidator);

    auto* hexValidator =
        new QRegularExpressionValidator(QRegularExpression("[0-9A-Fa-f]{1,2}"), hexEdit);
    hexEdit->setValidator(hexValidator);

    auto* binValidator =
        new QRegularExpressionValidator(QRegularExpression("[01]{1,8}"), binEdit);
    binEdit->setValidator(binValidator);

    // Signal/slot connections
    connect(exitButton, SIGNAL(clicked()),
            this, SLOT(accept()));

    auto* bc = new ByteConverter(this);

    connect(decEdit, &QLineEdit::textChanged,
            bc, &ByteConverter::setDec);
    connect(hexEdit, &QLineEdit::textChanged,
            bc, &ByteConverter::setHex);
    connect(binEdit, &QLineEdit::textChanged,
            bc, &ByteConverter::setBin);

    connect(bc, &ByteConverter::decChanged,
            decEdit, &QLineEdit::setText);
    connect(bc, &ByteConverter::hexChanged,
            hexEdit, &QLineEdit::setText);
    connect(bc, &ByteConverter::binChanged,
            binEdit, &QLineEdit::setText);
}
