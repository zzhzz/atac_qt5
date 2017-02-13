#include "atactmdialog.h"
#include "ui_atactmdialog.h"

AtactmDialog::AtactmDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AtactmDialog)
{
    ui->setupUi(this);
}

AtactmDialog::~AtactmDialog()
{
    delete ui;
}
