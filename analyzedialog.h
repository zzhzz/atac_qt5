#ifndef ANALYZEDIALOG_H
#define ANALYZEDIALOG_H

#include <QDialog>

namespace Ui {
class AnalyzeDialog;
}
class QProcess;
class QTextBrowser;

class AnalyzeDialog : public QDialog
{
    Q_OBJECT

public:
   static AnalyzeDialog* getDialog(QWidget *parent = 0){
       static AnalyzeDialog *dialog = new AnalyzeDialog(parent);
       return dialog;
   }

   void set_Project_path(QString path);

private slots:
   void choose_tracefile();
   void choose_atacfiles();
   void setting_options();
   void launch_analyzing();
   void launch_atactmDialog();
   void set_output_info();
   void set_error_info();
private:
    explicit AnalyzeDialog(QWidget *parent = 0);
    ~AnalyzeDialog();

    QString Project_path;
    QString tracefile;
    QStringList atacfiles;
    QStringList options;
    QProcess *process;

    QTextBrowser *output_browser;
    QTextBrowser *error_browser;
    Ui::AnalyzeDialog *ui;
};

#endif // ANALYZEDIALOG_H
