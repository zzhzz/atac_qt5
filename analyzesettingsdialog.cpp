#include "analyzesettingsdialog.h"
#include "ui_analyzesettingsdialog.h"
#include "atacfiledsettingwidget.h"
#include "atacsummarysettingwidget.h"
#include <QTabWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>

AnalyzeSettingsDialog::AnalyzeSettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AnalyzeSettingsDialog)
{
    QHBoxLayout *mainLayout = new QHBoxLayout;
    QTabWidget *tabview = new QTabWidget(this);
    filedsetting = new AtacFiledSettingWidget(this);
    summarysetting = new AtacSummarySettingWidget(this);
    tabview->addTab(filedsetting,"filed setting");
    tabview->addTab(summarysetting,"Summary Setting");

    mainLayout->addWidget(tabview);

    setLayout(mainLayout);

    ui->setupUi(this);
}

AnalyzeSettingsDialog::~AnalyzeSettingsDialog()
{
    delete ui;
}

QStringList AnalyzeSettingsDialog::getoptions(){
    QStringList options;
    options = options + summarysetting->get_options();
    options = options + filedsetting->get_options();
    return options;
}
