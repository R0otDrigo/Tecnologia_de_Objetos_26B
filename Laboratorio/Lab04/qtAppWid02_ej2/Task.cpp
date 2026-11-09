#include "Task.h"
#include "ui_Task.h"

Task::Task(const QString &name, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Task)
{
    ui->setupUi(this);
    setName(name);

    connect(ui->checkbox, &QCheckBox::toggled, this, &Task::checked);
}

Task::~Task()
{
    delete ui;
}

void Task::setName(const QString &name)
{
    ui->Mitext->setText(name);
}

QString Task::name() const
{
    return ui->Mitext->text();
}

bool Task::isCompleted() const
{
    return ui->checkbox->isChecked();
}

void Task::checked(bool marcado)
{
    //tachar el texto cuando la tarea esta hecha
    QFont font(ui->Mitext->font());
    font.setStrikeOut(marcado);
    ui->Mitext->setFont(font);

    emit statusChanged();
}
