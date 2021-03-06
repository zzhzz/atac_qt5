#ifndef ANALYZESETTINGSDIALOG_H
#define ANALYZESETTINGSDIALOG_H

#include <QDialog>
#include "atacfiledsettingwidget.h"
#include "atacsummarysettingwidget.h"

namespace Ui {
class AnalyzeSettingsDialog;
}

class AnalyzeSettingsDialog : public QDialog
{
    Q_OBJECT

public:
    static AnalyzeSettingsDialog* getDialog(QWidget *parent=0){
        static AnalyzeSettingsDialog *dialog = new AnalyzeSettingsDialog(parent);
        return dialog;
    }

    QStringList getoptions();

private slots:

private:
    explicit AnalyzeSettingsDialog(QWidget *parent = 0);
    ~AnalyzeSettingsDialog();
    AtacFiledSettingWidget *filedsetting;
    AtacSummarySettingWidget *summarysetting;
    QStringList options;
    Ui::AnalyzeSettingsDialog *ui;
};

#endif // ANALYZESETTINGSDIALOG_H
