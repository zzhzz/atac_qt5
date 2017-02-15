#ifndef RADIOSETTINGWIDGET_H
#define RADIOSETTINGWIDGET_H

#include <QWidget>

namespace Ui {
class RadioSettingWidget;
}

class RadioSettingWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RadioSettingWidget(QString name, QString opt, QWidget *parent = 0);
    ~RadioSettingWidget();

    QString get_option();
private slots:
    void change_statu();
private:
    bool statu;
    QString  option;

    Ui::RadioSettingWidget *ui;
};

#endif // RADIOSETTINGWIDGET_H
