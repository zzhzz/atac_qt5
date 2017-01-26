#include "dialog.h"
#include "ui_dialog.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QFileDialog>
#include <QLabel>
#include "compileDialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QPushButton *openbtn = new QPushButton("open Project",this);
    QPushButton *compilebtn = new QPushButton("compile Project",this);
    QPushButton *testingbtn = new QPushButton("test Project",this);
    QPushButton *analyzebtn = new QPushButton("analyze Project",this);
    pathedit     = new QLineEdit(this);
    QLabel *label = new QLabel("Path :",this);
    QHBoxLayout *pathlayout = new QHBoxLayout;
    QHBoxLayout *layout1 = new QHBoxLayout;
    QHBoxLayout *layout2 = new QHBoxLayout;
    QVBoxLayout *mainlayout = new QVBoxLayout;
    pathlayout->addWidget(label);
    pathlayout->addWidget(pathedit);
    layout1->addWidget(openbtn);
    layout1->addWidget(compilebtn);
    layout2->addWidget(testingbtn);
    layout2->addWidget(analyzebtn);
    mainlayout->addLayout(pathlayout);
    mainlayout->addLayout(layout1);
    mainlayout->addLayout(layout2);

    connect(pathedit,SIGNAL(textChanged(QString)),this,SLOT(changeDirectory()));
    connect(openbtn,SIGNAL(clicked(bool)),this,SLOT(openProjectDir()));
    connect(compilebtn,SIGNAL(clicked(bool)),this,SLOT(compilingProject()));
    setWindowTitle("atac user interface");
    setLayout(mainlayout);
}

void Dialog::changeDirectory()
{
    ProjectPath = pathedit->text();
}

void Dialog::openProjectDir()
{
    ProjectPath = QFileDialog::getExistingDirectory(this,tr("choose the Project Directory"),"/home");
    pathedit->setText(ProjectPath);
}

void Dialog::compilingProject()
{
    compileDialog *dialog = compileDialog::getDialog(this);
    dialog->show();
}

void Dialog::testingProject()
{

}

void Dialog::analyzeProject()
{

}

QString Dialog::getProjectPath(){
    return ProjectPath;
}



Dialog::~Dialog()
{
    delete ui;
}
