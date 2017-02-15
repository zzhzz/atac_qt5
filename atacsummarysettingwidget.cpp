#include "atacsummarysettingwidget.h"
#include "ui_atacsummarysettingwidget.h"
#include "radiosettingwidget.h"
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>

AtacSummarySettingWidget::AtacSummarySettingWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AtacSummarySettingWidget)
{
    QHBoxLayout *chooseLayout = new QHBoxLayout;
    QHBoxLayout *otherLayout = new QHBoxLayout;
    QVBoxLayout *mainLayout = new QVBoxLayout;
    cumulative_coverage_pertest = new RadioSettingWidget("cumulative coverage pertest",
                                                         "-q",this);

    only_testable = new RadioSettingWidget("testable attribute only", "-A",this);
    per_function = new RadioSettingWidget("base on per function","-f",this);
    per_sourcefile = new RadioSettingWidget("base on source file","-g",this);
    per_testcase = new RadioSettingWidget("base on per testcase", "-p",this);
    test_cost = new RadioSettingWidget("count test cost","-K",this);
    otherLayout->addWidget(only_testable);
    otherLayout->addWidget(test_cost);
    otherLayout->addWidget(cumulative_coverage_pertest);
    chooseLayout->addWidget(per_function);
    chooseLayout->addWidget(per_sourcefile);
    chooseLayout->addWidget(per_testcase);
    mainLayout->addLayout(otherLayout);
    mainLayout->addLayout(chooseLayout);
    setLayout(mainLayout);
    ui->setupUi(this);
}

AtacSummarySettingWidget::~AtacSummarySettingWidget()
{
    delete ui;
}

QStringList AtacSummarySettingWidget::get_options(){
    QStringList opts;
    opts << "-s";
    if(only_testable->get_statu()) opts << only_testable->get_option();
    if(test_cost->get_statu()) opts << test_cost->get_option();
    if(cumulative_coverage_pertest->get_statu()) opts << cumulative_coverage_pertest->get_option();
    if(per_function->get_statu()) opts << per_function->get_option();
    if(per_sourcefile->get_statu()) opts << per_sourcefile->get_option();
    if(per_testcase->get_statu()) opts << per_testcase->get_option();
    return opts;
}
