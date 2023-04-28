#pragma once

#include <QWidget>

class FontPreviewWidget : public QWidget
{
    Q_OBJECT
public:
    explicit FontPreviewWidget(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    QString _preview_text;
};
