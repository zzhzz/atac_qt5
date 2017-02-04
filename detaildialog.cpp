#include "detaildialog.h"
#include "ui_detaildialog.h"
#include <QProcess>
#include <QLineEdit>
#include <QTextBrowser>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QFileDialog>

DetailDialog::DetailDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DetailDialog)
{
    process = new QProcess(this);

    QVBoxLayout *main_layout = new QVBoxLayout;

    QHBoxLayout *Input_Layout = new QHBoxLayout;
    edit = new QLineEdit(this);
    QLabel *editor = new QLabel("inputfile: ", this);
    QPushButton *browse_btn = new QPushButton("browse",this);

    Input_Layout->addWidget(editor);
    Input_Layout->addWidget(edit);
    Input_Layout->addWidget(browse_btn);


    QVBoxLayout *out_Layout = new QVBoxLayout;
    QVBoxLayout *error_Layout = new QVBoxLayout;
    QLabel *out_Label = new QLabel("output:",this);
    QLabel *error_Label = new QLabel("error:", this);
    Program_Output = new QTextBrowser(this);
    Program_Error = new QTextBrowser(this);

    out_Layout->addWidget(out_Label);
    out_Layout->addWidget(Program_Output);
    error_Layout->addWidget(error_Label);
    error_Layout->addWidget(Program_Error);

    QHBoxLayout *button_Layout = new QHBoxLayout;
    QPushButton *run_btn = new QPushButton("run", this);
    QPushButton *close_btn = new QPushButton("close", this);

    button_Layout->addWidget(run_btn);
    button_Layout->addWidget(close_btn);

    main_layout->addLayout(Input_Layout);
    main_layout->addLayout(out_Layout);
    main_layout->addLayout(error_Layout);
    main_layout->addLayout(button_Layout);

    setLayout(main_layout);

    connect(process,SIGNAL(readyReadStandardOutput()),this,SLOT(set_Output()));
    connect(process,SIGNAL(readyReadStandardError()),this,SLOT(set_Error()));
    connect(run_btn,SIGNAL(clicked(bool)),this,SLOT(running()));
    connect(close_btn,SIGNAL(clicked(bool)),this,SLOT(close()));
    connect(edit,SIGNAL(textChanged(QString)),this,SLOT(set_Input_File(QString)));
    connect(browse_btn,SIGNAL(clicked(bool)),this,SLOT(browse_Inputfile()));

    ui->setupUi(this);
}

DetailDialog::~DetailDialog()
{
    delete ui;
}

void DetailDialog::set_Program(QString path){
    program_path = path;
}

void DetailDialog::set_Output(){
    QByteArray array = process->readAllStandardOutput();
    QString text = QString(array.constData());
    Program_Output->setText(text);
}

void DetailDialog::set_Error(){
    QByteArray array = process->readAllStandardError();
    QString text = QString(array.constData());
    Program_Error->setText(text);
}

void DetailDialog::running(){
    if(program_path.isEmpty()){
        QMessageBox::warning(this,"no program setting",
                             "no program to run,please check",QMessageBox::Ok);
    } else {
        Program_Output->clear();
        Program_Error->clear();
        process->start(program_path,QStringList() << Input_file);
        // input
    }
}

void DetailDialog::set_Input_File(QString name){
    Input_file = name;
}

void DetailDialog::browse_Inputfile(){
    Input_file = QFileDialog::getOpenFileName(this,"choose input file",program_path);
    edit->setText(Input_file);
}
