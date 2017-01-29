#ifndef COMPILESETTINGDIALOG_H
#define COMPILESETTINGDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QString>
#include <QComboBox>

namespace Ui {
class CompileSettingDialog;
}

class CompileSettingDialog : public QDialog
{
    Q_OBJECT

public:

    ~CompileSettingDialog();

    QStringList getOptions();
    QString get_Output_path();

    static CompileSettingDialog* getDialog(QWidget * parent = 0){
        static CompileSettingDialog* dialog = new CompileSettingDialog(parent);
        return dialog;
    }

    void set_Project_path(QString path);

private slots:
    void Set_Mainfile_Name(const QString & filename);
    void Choose_Mainfile_Name();
    void Set_Outputfile_Name(const QString & filename);
    void Set_Directory_Type(const QString & text);
    void Set_CPP_FLAGS(const QString & flags);
    void Set_LD_FLAGS(const QString & flags);
    void Set_Include_Dir(const QString & dir_path);
    void Set_Program_Version(const QString & version);

private:
    explicit CompileSettingDialog(QWidget *parent = 0);

    Ui::CompileSettingDialog *ui;

    QString Project_Path;
    QString main_filename;
    QString output_filename;
    QString directory_type;
    QString CPP_FLAGS;
    QString LD_FLAGS;
    QString INCLUDE_DIR;
    QString program_version;

    QLineEdit *mainfile_path_Edit;

    static CompileSettingDialog* dialog;

};

#endif // COMPILESETTINGDIALOG_H
