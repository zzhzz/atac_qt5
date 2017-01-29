#include "testdialog.h"
#include "ui_testdialog.h"
#include "testwidget.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

TestDialog::TestDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TestDialog)
{
    QVBoxLayout *main_Layout = new QVBoxLayout;
    QPushButton *add_btn = new QPushButton("add", this);
    QPushButton *close_btn = new QPushButton("close", this);

    QHBoxLayout *button_Layout = new QHBoxLayout;
    button_Layout->addWidget(add_btn);
    button_Layout->addWidget(close_btn);

    widget_Layout = new QVBoxLayout;
    main_Layout->addLayout(button_Layout);
    main_Layout->addLayout(widget_Layout);
    last_id = 0;

    connect(add_btn,SIGNAL(clicked(bool)),this,SLOT(add_TestCase()));
    connect(close_btn,SIGNAL(clicked(bool)),this,SLOT(close()));

    setLayout(main_Layout);

    ui->setupUi(this);
}

TestDialog::~TestDialog()
{
    delete ui;
}
void TestDialog::set_Program_name(QString path){
    program_name = path;
}

void TestDialog::add_TestCase(){
    TestWidget *widget = new TestWidget(this);
    widget->set_Program_Path(program_name);
    widget->set_Widget_ID(++last_id);
    widget_Layout->addWidget(widget);
}
