#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLineEdit>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

    QString getProjectPath();
private slots:
    void openProjectDir();
    void changeDirectory();
    void compilingProject();
    void testingProject();
    void analyzeProject();

private:
    QString ProjectPath;
    QLineEdit *pathedit;
    Ui::Dialog *ui;
};

#endif // DIALOG_H
