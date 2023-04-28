#include "fontpreviewwidget.hpp"

#include <QPainter>
#include <QPaintEvent>

static const char* const preview_text =
    "The quick brown fox jumps over the lazy dog\n"
    "\n"
    "abcdefghijklmnoprstuvwxyz\n"
    "ABCDEFGHIJKLMNOPRSTUVWXYZ\n"
    R"xx(0123456789.:,;(*!?'/\")£$€%^&-+@~#<>{}[])xx";

FontPreviewWidget::FontPreviewWidget(QWidget *parent)
    : QWidget{parent}
    , _preview_text(QString::fromUtf8(preview_text))
{
}

void FontPreviewWidget::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.drawText(rect(), _preview_text, {Qt::AlignCenter});
    event->accept();
}
