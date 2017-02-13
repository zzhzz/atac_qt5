#include "analyzesettingsdialog.h"
#include "ui_analyzesettingsdialog.h"

AnalyzeSettingsDialog::AnalyzeSettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AnalyzeSettingsDialog)
{
    ui->setupUi(this);
}

AnalyzeSettingsDialog::~AnalyzeSettingsDialog()
{
    delete ui;
}

QStringList AnalyzeSettingsDialog::getoptions(){

}
