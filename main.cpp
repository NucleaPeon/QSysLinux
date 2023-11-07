#include <qsyslinux.h>
#include <QDebug>

int main(int argc, char *argv[])
{
    qDebug() << QSysLinux::kernelVersion();
    qDebug() << QSysLinux::kernelType();
    return 0;
}
