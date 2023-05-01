#include "fontpreviewwidget.hpp"

#include <QPainter>
#include <QPaintEvent>

static const char* const preview_text =
    "The quick brown fox jumps over the lazy dog\n"
    "\n"
    "abcdefghijklmnoprstuvwxyz\n"
    "ABCDEFGHIJKLMNOPRSTUVWXYZ\n"
    R"xx(0123456789.:,;(*!?'/\")£$€%^&-+@~#<>{}[])xx";

namespace {
const QString default_sample_text = QString::fromUtf8(preview_text);
}  // namespace

FontPreviewWidget::FontPreviewWidget(QWidget *parent)
    : QWidget{parent}
    , _preview_text(QString::fromUtf8(preview_text))
{
}

QString FontPreviewWidget::sampleText() const
{
    return _preview_text;
}

void FontPreviewWidget::setSampleText(const QString &text)
{
    if (text.isEmpty())
        _preview_text = default_sample_text;
    else
        _preview_text = QString("%1\n\n%2").arg(default_sample_text, text);
    update();
}

void FontPreviewWidget::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.drawText(rect(), _preview_text, {Qt::AlignCenter});
    event->accept();
}
