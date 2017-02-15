#include "analyzedialog.h"
#include "ui_analyzedialog.h"
#include "analyzesettingsdialog.h"
#include "atactmdialog.h"
#include <QProcess>
#include <QLineEdit>
#include <QPushButton>
#include <QTextBrowser>
#include <QFileDialog>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QMessageBox>

AnalyzeDialog::AnalyzeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AnalyzeDialog)
{
    process = new QProcess(this);

   // QPushButton *atactm_btn = new QPushButton("atactm", this);
    QPushButton *close_btn = new QPushButton("close", this);
    QPushButton *analyze_btn = new QPushButton("analyze", this);
    QPushButton *setting_btn = new QPushButton("settings", this);
    QPushButton *browse_atacfile = new QPushButton("browse", this);
    QPushButton *browse_tracefile = new QPushButton("browse", this);
    tracefile_path = new QLineEdit(this);
    atacfile_path = new QLineEdit(this);
    QLabel *trace_label = new QLabel("tracefile: ", this);
    QLabel *atacfile_label = new QLabel("atacfile: ", this);
    output_browser = new QTextBrowser(this);
    error_browser = new QTextBrowser(this);
    QLabel *output_label = new QLabel("output: ", this);
    QLabel *error_label = new QLabel("error: ", this);
    QHBoxLayout *trace_layout = new QHBoxLayout;
    QHBoxLayout *atac_layout = new QHBoxLayout;
    QVBoxLayout *file_layout = new QVBoxLayout;

    trace_layout->addWidget(trace_label);
    trace_layout->addWidget(tracefile_path);
    trace_layout->addWidget(browse_tracefile);

    atac_layout->addWidget(atacfile_label);
    atac_layout->addWidget(atacfile_path);
    atac_layout->addWidget(browse_atacfile);

    file_layout->addLayout(trace_layout);
    file_layout->addLayout(atac_layout);

    QHBoxLayout *btn_layout = new QHBoxLayout;

    btn_layout->addWidget(setting_btn);
    btn_layout->addWidget(analyze_btn);
  //  btn_layout->addWidget(atactm_btn);
    btn_layout->addWidget(close_btn);

    QVBoxLayout *output_layout = new QVBoxLayout;
    QVBoxLayout *error_layout = new QVBoxLayout;

    output_layout->addWidget(output_label);
    output_layout->addWidget(output_browser);

    error_layout->addWidget(error_label);
    error_layout->addWidget(error_browser);

    QVBoxLayout *main_layout = new QVBoxLayout;

    main_layout->addLayout(btn_layout);
    main_layout->addLayout(file_layout);
    main_layout->addLayout(output_layout);
    main_layout->addLayout(error_layout);


    connect(setting_btn,SIGNAL(clicked(bool)),this,SLOT(setting_options()));
    connect(analyze_btn,SIGNAL(clicked(bool)),this,SLOT(launch_analyzing()));
//    connect(atactm_btn,SIGNAL(clicked(bool)),this,SLOT(launch_atactmDialog()));
    connect(browse_tracefile,SIGNAL(clicked(bool)),this,SLOT(choose_tracefile()));
    connect(browse_atacfile,SIGNAL(clicked(bool)),this,SLOT(choose_atacfiles()));
    connect(close_btn,SIGNAL(clicked(bool)),this,SLOT(close()));
    connect(process,SIGNAL(readyReadStandardError()),this,SLOT(set_error_info()));
    connect(process,SIGNAL(readyReadStandardOutput()),this,SLOT(set_output_info()));

    setLayout(main_layout);

    ui->setupUi(this);
}

AnalyzeDialog::~AnalyzeDialog()
{
    delete ui;
}

void AnalyzeDialog::setting_options(){
    AnalyzeSettingsDialog *dialog = AnalyzeSettingsDialog::getDialog(this);
    dialog->exec();
    options = dialog->getoptions();
}

void AnalyzeDialog::launch_analyzing(){
    if(!atacfiles.isEmpty()){
            output_browser->setText(QString(options.join(" ").constData()));
            process->start("atac", QStringList() << options << atacfiles);
    } else {
          QMessageBox::warning(this,tr("no path"),tr("no atacfiles path specified, please check"),QMessageBox::Ok);
    }
}

void AnalyzeDialog::launch_atactmDialog(){
    AtactmDialog *dialog = AtactmDialog::getDialog(this);
    dialog->exec();
}

void AnalyzeDialog::choose_atacfiles(){
    QStringList files = QFileDialog::getOpenFileNames(this,tr("choose atac files"),Project_path);
    atacfiles = files;
    atacfile_path->setText(QString(files.join(",").constData()));
}

void AnalyzeDialog::choose_tracefile(){
    QString file = QFileDialog::getOpenFileName(this,tr("choose trace file"),Project_path);
    tracefile = file;
    tracefile_path->setText(file);
}

void AnalyzeDialog::set_Project_path(QString path){
    Project_path = path;
}

void AnalyzeDialog::set_error_info(){
    QByteArray array = process->readAllStandardError();
    QString result = QString(array.constData());
    error_browser->setText(result);
}

void AnalyzeDialog::set_output_info(){
    QByteArray array = process->readAllStandardOutput();
    QString result = QString(array.constData());
    output_browser->setText(result);
}


