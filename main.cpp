#include "mainwindow.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication::setApplicationName(QStringLiteral("Font Preview"));
    QApplication::setOrganizationName(QStringLiteral("Nick Korotysh"));
    QApplication::setOrganizationDomain(QStringLiteral("com.github.kolcha.font-preview"));
    QApplication::setApplicationVersion(QStringLiteral("0.1.0"));

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
