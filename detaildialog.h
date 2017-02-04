#ifndef DETAILDIALOG_H
#define DETAILDIALOG_H

#include <QDialog>

namespace Ui {
class DetailDialog;
}
class QTextBrowser;
class QProcess;
class QLineEdit;
class DetailDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DetailDialog(QWidget *parent = 0);
    ~DetailDialog();
    void set_Program(QString path);

private slots:
    void set_Output();
    void set_Error();
    void running();
    void set_Input_File(QString name);
    void browse_Inputfile();

private:
    QString program_path;
    QString Input_file;
    QLineEdit *edit;
    QProcess *process;
    QTextBrowser *Program_Output;
    QTextBrowser *Program_Error;
    Ui::DetailDialog *ui;
};

#endif // DETAILDIALOG_H
