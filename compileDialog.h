#ifndef COMPILEDIALOG_H
#define COMPILEDIALOG_H

#include <QDialog>
#include <QProcess>
#include <QLineEdit>
#include <QPushButton>
namespace Ui {
class compileDialog;
}

class compileDialog : public QDialog
{
    Q_OBJECT

public:

    static compileDialog* getDialog(QString project_path, QWidget *parent = 0){
        static compileDialog* dialog = new compileDialog(parent);
        dialog->set_project_path(project_path);
        return dialog;
    }



private slots:
    void setting_options();
    void launch_compiling();
    void finish();
    void set_project_path(QString path);




private:
    explicit compileDialog(QWidget *parent = 0);
    ~compileDialog();
    QString ProjectPath;
    QProcess *process;
    QStringList options;


    Ui::compileDialog *ui;
};

#endif // COMPILEDIALOG_H
