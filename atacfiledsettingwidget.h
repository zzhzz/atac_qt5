#ifndef ATACFILEDSETTINGWIDGET_H
#define ATACFILEDSETTINGWIDGET_H

#include <QWidget>
#include "radiosettingwidget.h"

namespace Ui {
class AtacFiledSettingWidget;
}

class AtacFiledSettingWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AtacFiledSettingWidget(QWidget *parent = 0);
    ~AtacFiledSettingWidget();

    QStringList get_options();
private slots:
    void set_testnames(QString name);
    void set_threshold(QString times);
    void set_entry(QString entry);
private:
    QStringList testnames;
    int threshold;
    QString function;
    RadioSettingWidget *block_box;
    RadioSettingWidget *decision_box;
    RadioSettingWidget *entries_box;
    RadioSettingWidget *computational_box;
    RadioSettingWidget *predicate_box;
    Ui::AtacFiledSettingWidget *ui;
};

#endif // ATACFILEDSETTINGWIDGET_H
