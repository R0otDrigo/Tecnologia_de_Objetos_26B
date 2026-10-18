#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->listaColores->addItems({"Rojo", "Verde", "Azul", "Amarillo",
                                "Naranja", "Morado", "Negro", "Blanco"});

    connect(ui->listaColores, &QListWidget::itemClicked,
            this, &MainWindow::mostrarColor);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mostrarColor(QListWidgetItem *item)
{
    QString nombre = item->text();
    ui->etiquetaColor->setText("Color elegido: " + nombre);
    qDebug() << "Se hizo clic en:" << nombre;

    //pintar el fondo de la etiqueta con el color elegido
    QString css;
    if (nombre == "Rojo")          css = "#e53935";
    else if (nombre == "Verde")    css = "#43a047";
    else if (nombre == "Azul")     css = "#1e88e5";
    else if (nombre == "Amarillo") css = "#fdd835";
    else if (nombre == "Naranja")  css = "#fb8c00";
    else if (nombre == "Morado")   css = "#8e24aa";
    else if (nombre == "Negro")    css = "#212121";
    else                           css = "#ffffff";

    QString letra = (nombre == "Negro" || nombre == "Morado") ? "white" : "black";
    ui->etiquetaColor->setStyleSheet("background-color:" + css + "; color:" + letra + ";");
}
