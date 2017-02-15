#include "atacfiledsettingwidget.h"
#include "ui_atacfiledsettingwidget.h"
#include "radiosettingwidget.h"
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>

AtacFiledSettingWidget::AtacFiledSettingWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AtacFiledSettingWidget)
{
    threshold = 0;
    testnames.clear();

    QVBoxLayout *mainLayout = new QVBoxLayout;

    QHBoxLayout *testnameLayout = new QHBoxLayout;
    QLabel *namelabel = new QLabel("test names: (seperated by space)",this);
    QLineEdit *nameEditor = new QLineEdit(this);
    testnameLayout->addWidget(namelabel);
    testnameLayout->addWidget(nameEditor);
    connect(nameEditor,SIGNAL(textChanged(QString)),this,SLOT(set_testnames(QString)));
    mainLayout->addLayout(testnameLayout);

    QHBoxLayout *thresholdLayout = new QHBoxLayout;
    QLabel *thresholdlabel = new QLabel("threshold: ", this);
    QLineEdit  *thresholdEditor = new QLineEdit(this);
    thresholdLayout->addWidget(thresholdlabel);
    thresholdLayout->addWidget(thresholdEditor);
    connect(thresholdEditor,SIGNAL(textChanged(QString)),this,SLOT(set_threshold(QString)));
    mainLayout->addLayout(thresholdLayout);

    QHBoxLayout *entryLayout = new QHBoxLayout;
    QLabel *entrylabel = new QLabel("entry: ", this);
    QLineEdit  *entryEditor = new QLineEdit(this);
    entryLayout->addWidget(entrylabel);
    entryLayout->addWidget(entryEditor);
    connect(entryEditor,SIGNAL(textChanged(QString)),this,SLOT(set_entry(QString)));
    mainLayout->addLayout(entryLayout);

    QHBoxLayout  *measureLayout = new QHBoxLayout;
    block_box = new RadioSettingWidget("Block","-mb",this);
    computational_box = new RadioSettingWidget("C-use","-mc",this);
    predicate_box = new RadioSettingWidget("P-use","-mp",this);
    decision_box = new RadioSettingWidget("Decision","-md",this);
    entries_box = new RadioSettingWidget("Entries","-me",this);
    measureLayout->addWidget(block_box);
    measureLayout->addWidget(decision_box);
    measureLayout->addWidget(entries_box);
    measureLayout->addWidget(computational_box);
    measureLayout->addWidget(predicate_box);
    mainLayout->addLayout(measureLayout);

    setLayout(mainLayout);
    ui->setupUi(this);
}

AtacFiledSettingWidget::~AtacFiledSettingWidget()
{
    delete ui;
}

QStringList AtacFiledSettingWidget::get_options(){
    QStringList options;
    if(!testnames.isEmpty()){
        options << QString("-c") << testnames;
    }
    if(threshold){
        options << QString("-t") << QString::number(threshold);
    }
    if(!function.isEmpty()){
        options << QString("-F") << function;
    }
    if(block_box->get_statu()) options << block_box->get_option();
    if(decision_box->get_statu()) options << decision_box->get_option();
    if(computational_box->get_statu()) options << computational_box->get_option();
    if(predicate_box->get_statu()) options << predicate_box->get_option();
    if(entries_box->get_statu()) options << entries_box->get_option();

    return options;
}

void AtacFiledSettingWidget::set_testnames(QString name){
    testnames = name.split(" ");
}

void AtacFiledSettingWidget::set_threshold(QString times){
    threshold = times.toInt();
}

void AtacFiledSettingWidget::set_entry(QString entry){
    function = entry;
}
