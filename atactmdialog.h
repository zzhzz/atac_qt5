#ifndef ATACTMDIALOG_H
#define ATACTMDIALOG_H

#include <QDialog>

namespace Ui {
class AtactmDialog;
}

class AtactmDialog : public QDialog
{
    Q_OBJECT

public:
    static AtactmDialog* getDialog(QWidget *parent=0){
        static AtactmDialog* dialog = new AtactmDialog(parent);
        return dialog;
    }

    void set_path(QString path);

private:
    explicit AtactmDialog(QWidget *parent = 0);
    ~AtactmDialog();

    Ui::AtactmDialog *ui;
};

#endif // ATACTMDIALOG_H
