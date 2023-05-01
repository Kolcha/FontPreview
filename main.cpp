#include "mainwindow.hpp"

#include <QApplication>

int main(int argc, char* argv[])
{
#if (QT_VERSION < QT_VERSION_CHECK(6, 0, 0))
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
#endif
    QApplication a(argc, argv);

    QApplication::setApplicationName(QStringLiteral("Font Preview"));
    QApplication::setApplicationDisplayName(QApplication::applicationName());
    QApplication::setOrganizationName(QStringLiteral("Nick Korotysh"));
    QApplication::setOrganizationDomain(QLatin1String("kolcha.github.com"));
    QApplication::setDesktopFileName(QLatin1String("com.github.kolcha.font-preview"));
    QApplication::setApplicationVersion(QStringLiteral("0.1.0"));

    const auto args = QApplication::arguments().mid(1);
    MainWindow w(args.isEmpty() ? QString() : args.first());
    w.show();
    return a.exec();
}
