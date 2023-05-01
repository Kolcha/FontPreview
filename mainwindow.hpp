#pragma once

#include <QWidget>

#include <QFontDatabase>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(const QString &filename, QWidget *parent = nullptr);
    ~MainWindow();

private:
    void updatePreview();

private slots:
    void on_fontsBox_currentTextChanged(const QString &arg1);
    void on_styleBox_currentTextChanged(const QString &arg1);
    void on_sizeBox_currentTextChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    QFontDatabase _fdb;
};
