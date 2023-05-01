#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include <QIntValidator>
#include <QSignalBlocker>

namespace ComboUtils {

int findAnyOf(const QComboBox* box, const QStringList& l)
{
    int idx = -1;
    for (const auto& k : l) {
        idx = box->findText(k);
        if (idx != -1)
            break;
    }
    return idx;
}

int setAnyOf(QComboBox* box, const QStringList& l)
{
    int idx = findAnyOf(box, l);
    if (idx != -1)
        box->setCurrentIndex(idx);
    return idx;
}

}  // namespace ComboUtils

namespace {

QStringList common_styles{QLatin1String("Regular"), QLatin1String("Normal")};

}  // namespace

MainWindow::MainWindow(const QString &filename, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    if (filename.isEmpty()) {
        ui->fontsBox->addItems(_fdb.families());
        ui->fontsBox->setCurrentText(font().family());
    } else {
        if (int id = QFontDatabase::addApplicationFont(filename); id != -1)
            ui->fontsBox->addItems(QFontDatabase::applicationFontFamilies(id));
        setWindowFilePath(filename);
    }
    ui->sizeBox->setValidator(new QIntValidator(4, 256, this));
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
    ui->systemBox->clear();
    auto any_name = QFontDatabase::writingSystemName(QFontDatabase::Any);
    ui->systemBox->addItem(any_name, QFontDatabase::Any);
    auto wss = _fdb.writingSystems(arg1);
    for (const auto& ws : std::as_const(wss))
        ui->systemBox->addItem(QFontDatabase::writingSystemName(ws), ws);
    on_systemBox_activated(0);

    const QSignalBlocker _(ui->styleBox);
    ui->styleBox->clear();
    ui->styleBox->addItems(_fdb.styles(arg1));
    ComboUtils::setAnyOf(ui->styleBox, common_styles);
    on_styleBox_currentTextChanged(ui->styleBox->currentText());
}

void MainWindow::on_systemBox_activated(int index)
{
    auto ws = ui->systemBox->itemData(index).value<QFontDatabase::WritingSystem>();
    QString sample;
    if (ws != QFontDatabase::Any)
        sample = QFontDatabase::writingSystemSample(ws);
    ui->fontPreview->setSampleText(sample);
}

void MainWindow::on_styleBox_currentTextChanged(const QString &arg1)
{
    const QSignalBlocker _(ui->sizeBox);

    auto best_sizes = _fdb.smoothSizes(ui->fontsBox->currentText(), arg1);
    if (best_sizes.isEmpty())
        best_sizes = _fdb.pointSizes(ui->fontsBox->currentText(), arg1);
    if (best_sizes.isEmpty())
        best_sizes = QFontDatabase::standardSizes();

    auto curr_size = ui->sizeBox->currentText();
    if (curr_size.isEmpty())
        curr_size = QString::number(font().pointSize());

    ui->sizeBox->clear();
    for (const auto& s : std::as_const(best_sizes))
        ui->sizeBox->addItem(QString::number(s));
    ComboUtils::setAnyOf(ui->sizeBox, {curr_size});

    on_sizeBox_currentTextChanged(ui->sizeBox->currentText());
}

void MainWindow::on_sizeBox_currentTextChanged(const QString &arg1)
{
    Q_UNUSED(arg1);
    updatePreview();
}
