#include "dialog.h"
#include "ui_dialog.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QFileDialog>
#include <QLabel>
#include "compileDialog.h"
#include "testdialog.h"
#include "analyzedialog.h"

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
    connect(testingbtn,SIGNAL(clicked(bool)),this,SLOT(testingProject()));
    connect(analyzebtn,SIGNAL(clicked(bool)),this,SLOT(analyzeProject()));
    setWindowTitle("atac user interface");
    setLayout(mainlayout);
}

void Dialog::changeDirectory()
{
    ProjectPath = pathedit->text();
}

void Dialog::openProjectDir()
{
    ProjectPath = QFileDialog::getExistingDirectory(this,tr("choose the Project Directory"),QString("/home"));
    pathedit->setText(ProjectPath);
}

void Dialog::compilingProject()
{
    compileDialog *dialog = compileDialog::getDialog(this);
    dialog->set_project_path(ProjectPath);
    dialog->exec();
    Out_file_path = dialog->get_OutPut_Path();
}

void Dialog::testingProject()
{
    TestDialog *dialog = TestDialog::getDialog(this);
    dialog->set_Program_name(Out_file_path);
    dialog->exec();
}

void Dialog::analyzeProject()
{
    AnalyzeDialog *dialog = AnalyzeDialog::getDialog(this);
    dialog->set_Project_path(ProjectPath);
    dialog->exec();
}

QString Dialog::getProjectPath(){
    return ProjectPath;
}



Dialog::~Dialog()
{
    delete ui;
}
