#include "compileDialog.h"
#include "ui_compileDialog.h"
#include "compilesettingdialog.h"
#include <QPushButton>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QProcess>

compileDialog::compileDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::compileDialog)
{
    ui->setupUi(this);

    // variable initialzie
    ProjectPath = projectpath;



    //global widget and layout setting



    //project path




    //make makefile (mkMakefile)



    //compiling (make CC=atacCC)



    //settings widget
    QPushButton *setbtn = new QPushButton("Settings", this);
    connect(setbtn,SIGNAL(clicked(bool)),this,SLOT(setting_options()));


    // output information (2 widgets)



    //global settings


}

compileDialog::~compileDialog()
{
    delete ui;
}

void compileDialog::setting_options(){
    CompileSettingDialog *dialog = CompileSettingDialog::getDialog(this);
    dialog->exec();
    options = dialog->getOptions();

    QString opt;

    for(auto x : options){
        opt += x;
    }

    QMessageBox *box = new QMessageBox(this);
    box->setText(opt);
    box->show();
}

void compileDialog::launch_compiling(){

}



void compileDialog::set_project_path(QString path){
    ProjectPath = path;
}

