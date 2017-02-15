#ifndef ATACSUMMARYSETTINGWIDGET_H
#define ATACSUMMARYSETTINGWIDGET_H

#include <QWidget>
#include "radiosettingwidget.h"

namespace Ui {
class AtacSummarySettingWidget;
}

class AtacSummarySettingWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AtacSummarySettingWidget(QWidget *parent = 0);
    ~AtacSummarySettingWidget();
    QStringList get_options();

private:
    RadioSettingWidget *only_testable;//-A
    RadioSettingWidget *per_function;//-f
    RadioSettingWidget *per_sourcefile;//-g
    RadioSettingWidget *test_cost;//-K
    RadioSettingWidget *per_testcase;//-p
    RadioSettingWidget *cumulative_coverage_pertest;//-q;

    Ui::AtacSummarySettingWidget *ui;
};

#endif // ATACSUMMARYSETTINGWIDGET_H
