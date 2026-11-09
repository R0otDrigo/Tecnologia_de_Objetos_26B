#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->addTaskButton, &QPushButton::clicked,
            this, &MainWindow::addTask);
    updateStatus();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addTask()
{
    qDebug() << "Slot corresponde al clic en el boton ...";

    //MainWindow -> Task: se le pone el nombre desde afuera
    Task *task = new Task(QString("Tarea %1").arg(mTasks.size() + 1));
    mTasks.append(task);
    ui->tasksLayout->addWidget(task);

    //Task -> MainWindow: cuando se marca o desmarca, se actualiza el status
    connect(task, &Task::statusChanged, this, &MainWindow::updateStatus);
    updateStatus();
}

void MainWindow::updateStatus()
{
    int hechas = 0;
    for (Task *t : mTasks) {
        if (t->isCompleted()) {
            hechas++;
        }
    }
    int pendientes = mTasks.size() - hechas;
    ui->statusLabel->setText(QString("Status: %1 todo / %2 hecho")
                             .arg(pendientes).arg(hechas));
}
