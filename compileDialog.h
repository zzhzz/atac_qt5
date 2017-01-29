#ifndef COMPILEDIALOG_H
#define COMPILEDIALOG_H

#include <QDialog>
#include <QProcess>
#include <QLineEdit>
#include <QPushButton>
#include <QTextBrowser>

namespace Ui {
class compileDialog;
}

class compileDialog : public QDialog
{
    Q_OBJECT

public:

    static compileDialog* getDialog(QWidget *parent = 0){
        static compileDialog* dialog = new compileDialog(parent);
        return dialog;
    }

    QString get_OutPut_Path();
    void set_project_path(QString path);

private slots:
    void setting_options();
    void launch_compiling();
    void set_Output_Info();
    void set_Error_Info();
    void launch_automake();


private:
    explicit compileDialog(QWidget *parent = 0);
    ~compileDialog();

    void set_Content(QTextBrowser *browser, QString content);

    QTextBrowser *error_Info_Browser;
    QTextBrowser *output_Info_Browser;

    QString ProjectPath;
    QProcess *process;
    QStringList options;
    QString OutPut_Path;
    Ui::compileDialog *ui;
};

#endif // COMPILEDIALOG_H
