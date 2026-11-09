#include <QCoreApplication>
#include <QDebug>
#include <QObject>
#include <string>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int x = 47;
    double y = 3.2478;
    QString t = "Ok";

    QString qtcadena = QString("%1 %2 %3").arg(t).arg(y).arg(x);

    std::string cadena = qtcadena.toStdString(); //convertir QString a string estandar
    qDebug() << cadena.c_str();  //convertir para mostrar en el debug
    qDebug() << qtcadena;

    qtcadena = "arequipa ciudad blanca 2021";
    qDebug() << qtcadena.contains("ciudad");   //devuelve bool
    qDebug() << qtcadena.indexOf("2021");      //devuelve la posicion

    return 0;
}
