#include "testwidget.h"
#include "ui_testwidget.h"
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <detaildialog.h>
#include <cstdlib>

TestWidget::TestWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestWidget)
{
    QHBoxLayout *layout = new QHBoxLayout;
    label = new QLabel(QString("Test case ")+ Widget_ID + QString(" : "),this);
    name_label = new QLabel(program_path,this);
    QPushButton *open_btn = new QPushButton("show details");

    connect(open_btn,SIGNAL(clicked(bool)),this,SLOT(open_dialog()));

    layout->addWidget(label);
    layout->addWidget(name_label);
    layout->addWidget(open_btn);

    setLayout(layout);

    ui->setupUi(this);
}

void TestWidget::open_dialog(){
    DetailDialog* dialog = new DetailDialog(this);
    dialog->set_Program(program_path);
    dialog->show();
}

void TestWidget::set_Program_Path(QString path){
    program_path = path;
    name_label->setText(program_path);
}

void TestWidget::set_Widget_ID(int id){
    Widget_ID = id;
    label->setText(QString("Test case ")+ QString::number(Widget_ID)+ QString(" : "));
}

TestWidget::~TestWidget()
{
    delete ui;
}
