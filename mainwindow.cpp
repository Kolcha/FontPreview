#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include <QIntValidator>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->fontsBox->addItems(_fdb.families());
    ui->fontsBox->setCurrentText(font().family());
    ui->styleBox->addItems(_fdb.styles(ui->fontsBox->currentText()));
    ui->styleBox->setCurrentText(font().styleName());

    ui->sizeBox->setValidator(new QIntValidator(4, 256, this));
    const auto std_sizes = QFontDatabase::standardSizes();
    for (const auto& s : std_sizes)
        ui->sizeBox->addItem(QString::number(s));
    ui->sizeBox->setCurrentText(QString::number(font().pointSize()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updatePreview()
{
    auto family = ui->fontsBox->currentText();
    auto fstyle = ui->styleBox->currentText();
    auto fsize = ui->sizeBox->currentText().toInt();
    ui->fontPreview->setFont(_fdb.font(family, fstyle, fsize));
}

void MainWindow::on_fontsBox_currentTextChanged(const QString &arg1)
{
    ui->styleBox->clear();
    ui->styleBox->addItems(_fdb.styles(arg1));
}

void MainWindow::on_styleBox_currentTextChanged(const QString &arg1)
{
    updatePreview();
}

void MainWindow::on_sizeBox_currentTextChanged(const QString &arg1)
{
    updatePreview();
}
