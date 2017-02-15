#include "compileDialog.h"
#include "ui_compileDialog.h"
#include "compilesettingdialog.h"
#include <QPushButton>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QProcess>
#include <QTextBrowser>
#include <QLabel>
#include <QFile>

compileDialog::compileDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::compileDialog)
{

    // variable initialzie
    process = new QProcess(this);

    //global widget and layout setting
    QVBoxLayout *main_Layout = new QVBoxLayout;
    QPushButton *close_btn   = new QPushButton("close", this);
    connect(close_btn, SIGNAL(clicked(bool)), this, SLOT(close()));

    //make makefile (mkMakefile)
    QPushButton *make_btn = new QPushButton("build makefile", this);
    connect(make_btn,SIGNAL(clicked(bool)),this, SLOT(launch_automake()));

    //compiling (make CC=atacCC)
    QPushButton *compile_btn = new QPushButton("compile", this);
    connect(compile_btn,SIGNAL(clicked(bool)), this, SLOT(launch_compiling()));

    //settings widget
    QPushButton *setbtn = new QPushButton("Settings", this);
    connect(setbtn,SIGNAL(clicked(bool)),this,SLOT(setting_options()));

    QHBoxLayout *button_Layout = new QHBoxLayout;

    button_Layout->addWidget(setbtn);
    button_Layout->addWidget(make_btn);
    button_Layout->addWidget(compile_btn);
    button_Layout->addWidget(close_btn);

    // output information (2 widgets)
    QVBoxLayout *output_all_Layout = new QVBoxLayout;

    QLabel *error_Label = new QLabel("error information: ", this);
    QLabel *output_Label = new QLabel("output information: ", this);

    QVBoxLayout *error_Layout = new QVBoxLayout;
    QVBoxLayout *output_Layout = new QVBoxLayout;

    error_Info_Browser = new QTextBrowser(this);
    output_Info_Browser = new QTextBrowser(this);

    error_Layout->addWidget(error_Label);
    error_Layout->addWidget(error_Info_Browser);

    output_Layout->addWidget(output_Label);
    output_Layout->addWidget(output_Info_Browser);

    output_all_Layout->addLayout(output_Layout);
    output_all_Layout->addLayout(error_Layout);

    connect(process,SIGNAL(readyReadStandardOutput()),this, SLOT(set_Output_Info()));
    connect(process,SIGNAL(readyReadStandardError()), this, SLOT(set_Error_Info()));

    //global settings
    main_Layout->addLayout(button_Layout);
    main_Layout->addLayout(output_all_Layout);

    setLayout(main_Layout);

    ui->setupUi(this);
}

compileDialog::~compileDialog()
{
    delete ui;
}

void compileDialog::setting_options(){
    CompileSettingDialog *dialog = CompileSettingDialog::getDialog(this);
    dialog->set_Project_path(ProjectPath);
    dialog->exec();
    options << dialog->getOptions();
    OutPut_Path = ProjectPath + "/" + dialog->get_Output_path();
}

void compileDialog::launch_compiling(){
    if(ProjectPath.isEmpty()){
        QMessageBox::warning(this,tr("no path"),tr("no project path specified, please check"),QMessageBox::Ok);
    } else {
        QFile *configurefile = new QFile(QString(ProjectPath+"configure"));
        if(configurefile->exists()){
            process->start("./configure");
            if(!process->waitForStarted()){
                error_Info_Browser->setText("configure false");
                return;
            }
            while(false == process->waitForFinished()){
                output_Info_Browser->setText("configuring");
            }
        } else {
            QMessageBox::warning(this,tr("no configurefile"),tr("no configurefile found under the project path, please check"),QMessageBox::Ok);
        }

        QFile *makefile = new QFile(QString(ProjectPath+"Makefile"));
        if(makefile->exists()){
            //compiling
            process->start("make CC=atacCC");
            if(!process->waitForStarted()){
                error_Info_Browser->setText("compile false");
                return;
            }
            while(false == process->waitForFinished()){
                output_Info_Browser->setText("Compiling");
            }
        } else {
            QMessageBox::warning(this,tr("no makefile"),tr("no makefile found under the project path, please check"),QMessageBox::Ok);
        }
    }
}

void compileDialog::set_project_path(QString path){
    ProjectPath = path;
    process->setWorkingDirectory(ProjectPath);
}

QString compileDialog::get_OutPut_Path(){
    return OutPut_Path;
}

void compileDialog::set_Content(QTextBrowser *browser, QString content){
    browser->setText(content);
}

void compileDialog::set_Output_Info(){
    QByteArray array = process->readAllStandardOutput();
    QString content = QString(array.constData());
    this->set_Content(output_Info_Browser, content);
}

void compileDialog::set_Error_Info(){
    QByteArray array = process->readAllStandardError();
    QString content = QString(array.constData());
    this->set_Content(error_Info_Browser, content);
}

void compileDialog::launch_automake(){
    if(ProjectPath.isEmpty()){
        QMessageBox::warning(this,tr("no path"),tr("no project path specified, please check"),QMessageBox::Ok);
    } else {
        QString opt;
        for(auto x:options){
            opt += x;
        }
        QMessageBox *box = new QMessageBox(this);
        box->setText(opt);
        box->show();
        process->start("/bin/bash", QStringList() << "/home/zzhzz/Documents/auto/mkMakefile.sh" << options);
    }
}
