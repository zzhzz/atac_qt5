#include "compilesettingdialog.h"
#include "ui_compilesettingdialog.h"

#include <QPushButton>
#include <QLineEdit>
#include <QMessageBox>
#include <QComboBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QFileDialog>


CompileSettingDialog::CompileSettingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CompileSettingDialog)
{
    // the global widget settings
    QPushButton *closebtn = new QPushButton("close", this);

    QVBoxLayout *mainlayout = new QVBoxLayout;

    connect(closebtn,SIGNAL(clicked(bool)),this,SLOT(close()));

    //the main file dock widget settings
    QHBoxLayout *mainfile_Layout = new QHBoxLayout;
    QLabel *mainfile_label = new QLabel("Mainfile name",this);
    mainfile_path_Edit = new QLineEdit(this);
    QPushButton *browse_mainfile = new QPushButton("Browse", this);

    mainfile_Layout->addWidget(mainfile_label);
    mainfile_Layout->addWidget(mainfile_path_Edit);
    mainfile_Layout->addWidget(browse_mainfile);
    connect(browse_mainfile, SIGNAL(clicked(bool)), this, SLOT(Choose_Mainfile_Name()));
    connect(mainfile_path_Edit, SIGNAL(textChanged(QString)), this, SLOT(Set_Mainfile_Name(
                                                                             const QString &)));

    //the output file dock widget settings
    QHBoxLayout *outputfile_Layout = new QHBoxLayout;
    QLabel *outputfile_label = new QLabel("OutPutfile name",this);
    QLineEdit *outputfile_path_Edit = new QLineEdit(this);

    outputfile_Layout->addWidget(outputfile_label);
    outputfile_Layout->addWidget(outputfile_path_Edit);
    connect(outputfile_path_Edit, SIGNAL(textChanged(QString)), this, SLOT(Set_Outputfile_Name(
                                                                               const QString &)));

    //the version widget settings
    QHBoxLayout *version_Layout = new QHBoxLayout;
    QLabel *version_label = new QLabel("Version", this);
    QLineEdit *version_Edit = new QLineEdit(this);

    version_Layout->addWidget(version_label);
    version_Layout->addWidget(version_Edit);
    connect(version_Edit, SIGNAL(textChanged(QString)), this, SLOT(Set_Program_Version(
                                                                       const QString &)));
    mainfile_path_Edit->setText(main_filename);
    //the directory type dock widget settings
    QHBoxLayout *type_Layout = new QHBoxLayout;
    QLabel *type_Label = new QLabel("Directory type",this);

    QComboBox *type_Choose = new QComboBox(this);
    type_Choose->addItem(tr("FLAT"));
    type_Choose->addItem(tr("SHALLOW"));
    type_Choose->addItem(tr("DEEP"));

    type_Layout->addWidget(type_Label);
    type_Layout->addWidget(type_Choose);

    directory_type = type_Choose->currentText();
    connect(type_Choose,SIGNAL(currentIndexChanged(QString)),this,SLOT(Set_Directory_Type(
                                                                             const QString &)));

    //the CPPFLAGS dock widget settings
    QHBoxLayout *cpp_flags_Layout = new QHBoxLayout;
    QLabel *cpp_flags_Label = new QLabel("CPP_FLAGS:",this);
    QLineEdit *cpp_flags_Edit = new QLineEdit(this);

    cpp_flags_Layout->addWidget(cpp_flags_Label);
    cpp_flags_Layout->addWidget(cpp_flags_Edit);
    connect(cpp_flags_Edit, SIGNAL(textChanged(QString)), this, SLOT(Set_CPP_FLAGS(QString)));

    //the LDFLAGS dock widget settings
    QHBoxLayout *ld_flags_Layout = new QHBoxLayout;
    QLabel *ld_flags_Label = new QLabel("LD_FLAGS:",this);
    QLineEdit *ld_flags_Edit = new QLineEdit(this);

    ld_flags_Layout->addWidget(ld_flags_Label);
    ld_flags_Layout->addWidget(ld_flags_Edit);
    connect(ld_flags_Edit, SIGNAL(textChanged(QString)), this, SLOT(Set_LD_FLAGS(QString)));

    //the INCLUDE DIR dock widget settings
    QHBoxLayout *include_dir_Layout = new QHBoxLayout;
    QLabel *include_dir_Label = new QLabel("INCLUDE_DIRS: ",this);
    QLineEdit *include_dir_Edit = new QLineEdit(this);

    include_dir_Layout->addWidget(include_dir_Label);
    include_dir_Layout->addWidget(include_dir_Edit);
    connect(include_dir_Edit, SIGNAL(textChanged(QString)), this, SLOT(Set_Include_Dir(QString)));

    //the global layout settings;

    mainlayout->addLayout(mainfile_Layout);
    mainlayout->addLayout(outputfile_Layout);
    mainlayout->addLayout(version_Layout);
    mainlayout->addLayout(type_Layout);
    mainlayout->addLayout(cpp_flags_Layout);
    mainlayout->addLayout(ld_flags_Layout);
    mainlayout->addLayout(include_dir_Layout);
    mainlayout->addWidget(closebtn);

    setLayout(mainlayout);


    ui->setupUi(this);
}

CompileSettingDialog::~CompileSettingDialog()
{
    delete ui;
}


QStringList CompileSettingDialog::getOptions(){
    QStringList result;
    result.clear();
    if(main_filename.isEmpty() == false) result << QString("-f") << main_filename;
    if(output_filename.isEmpty() == false) result << QString("-o") << output_filename;
    if(program_version.isEmpty() == false) result << QString("-v") + program_version;
    if(directory_type.isEmpty() == false) result << QString("-D") + directory_type;
    if(CPP_FLAGS.isEmpty() == false) result << QString("-C" + QString("\"" + CPP_FLAGS + "\""));
    if(LD_FLAGS.isEmpty() == false) result << QString("-L" + QString("\""+ LD_FLAGS + "\""));
    if(INCLUDE_DIR.isEmpty() == false) result << QString("-I" + QString("\"" + INCLUDE_DIR +"\""));

    return result;
}

void CompileSettingDialog::Set_Mainfile_Name(const QString &filename){
    main_filename = filename;
}

void CompileSettingDialog::Set_Outputfile_Name(const QString &filename){
    output_filename = filename;
}

void CompileSettingDialog::Choose_Mainfile_Name(){
    main_filename = QFileDialog::getOpenFileName(this,"choose the file contains main function",
                                                 Project_Path);
    main_filename.replace(Project_Path,QString(""));
    mainfile_path_Edit->setText(main_filename);
}

void CompileSettingDialog::Set_CPP_FLAGS(const QString &flags){
    CPP_FLAGS = flags;
}

void CompileSettingDialog::Set_Include_Dir(const QString &dir_path){
    INCLUDE_DIR = dir_path;
}

void CompileSettingDialog::Set_LD_FLAGS(const QString &flags){
    LD_FLAGS = flags;
}

void CompileSettingDialog::Set_Directory_Type(const QString &text){
    directory_type = text;
}

void CompileSettingDialog::Set_Program_Version(const QString &version){
    program_version = version;
}

QString CompileSettingDialog::get_Output_path(){
    return output_filename;
}

void CompileSettingDialog::set_Project_path(QString path){
    Project_Path = path;
}
