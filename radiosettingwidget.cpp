#include "radiosettingwidget.h"
#include "ui_radiosettingwidget.h"
#include <QCheckBox>

RadioSettingWidget::RadioSettingWidget(QString name, QString opt, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RadioSettingWidget)
{
    statu = false;
    option = opt;
    QCheckBox *box = new QCheckBox(name,this);
    connect(box,SIGNAL(clicked(bool)),this,SLOT(change_statu()));
    ui->setupUi(this);
}

RadioSettingWidget::~RadioSettingWidget()
{
    delete ui;
}

void RadioSettingWidget::change_statu(){
    statu = !statu;
}

QString RadioSettingWidget::get_option(){
    if(statu) return option;
    else  return QString("");
}

bool RadioSettingWidget::get_statu(){
    return statu;
}
