#ifndef TESTDIALOG_H
#define TESTDIALOG_H

#include <QDialog>
#include "testwidget.h"
#include <QVBoxLayout>

namespace Ui {
class TestDialog;
}

class TestDialog : public QDialog
{
    Q_OBJECT

public:
   static TestDialog* getDialog(QWidget *parent = 0){
       static TestDialog *dialog = new TestDialog(parent);
       return dialog;
   }

   void set_Program_name(QString path);

private slots:
   void add_TestCase();

private:
    explicit TestDialog(QWidget *parent = 0);
    ~TestDialog();

   QVBoxLayout *widget_Layout;
   int last_id;
   QString program_name;

   Ui::TestDialog *ui;
};

#endif // TESTDIALOG_H
