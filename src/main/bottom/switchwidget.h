#ifndef SWITCHWIDGET_H
#define SWITCHWIDGET_H

#include <QDialog>

class SwitchWidget : public QDialog
{
    Q_OBJECT

public:
    explicit SwitchWidget(QWidget *parent=0);
    void translateLanguage();

private:
    void initConnect();

private:
    QRect location;
    QPushButton *full_scan;
    QPushButton *custom_scan;

signals:
    void fullClicked();
    void customClicked();

};

#endif // SWITCHWIDGET_H
