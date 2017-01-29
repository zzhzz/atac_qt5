#ifndef TESTWIDGET_H
#define TESTWIDGET_H

#include <QWidget>

namespace Ui {
class TestWidget;
}
class QLabel;
class TestWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TestWidget(QWidget *parent = 0);
    ~TestWidget();

    void set_Program_Path(QString path);
    void set_Widget_ID(int id);

private slots:

    void open_dialog();

private:
    QString program_path;
    int Widget_ID;
    QLabel *label;
    QLabel *name_label;
    Ui::TestWidget *ui;
};

#endif // TESTWIDGET_H
