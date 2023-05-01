#pragma once

#include <QWidget>

class FontPreviewWidget : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QString sampleText READ sampleText WRITE setSampleText)
public:
    explicit FontPreviewWidget(QWidget *parent = nullptr);

    QString sampleText() const;

public slots:
    void setSampleText(const QString &text);

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    QString _preview_text;
};
