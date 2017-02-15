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
    opts << only_testable->get_option();
    opts << test_cost->get_option();
    opts << cumulative_coverage_pertest->get_option();
    opts << per_function->get_option();
    opts << per_sourcefile->get_option();
    opts << per_testcase->get_option();
    return opts;
}
