#ifndef TOPBOTTOMWIDGET_H
#define TOPBOTTOMWIDGET_H

#include <QWidget>

#include "switchwidget.h"
#include "../../safe/customscan.h"

class StaticButton;
class QStackedWidget;
class QPushButton;

class TopBottomWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TopBottomWidget(QWidget *parent = 0);
public slots:
    void setStackedButton(int index);
signals:
    void payinsureClicked();
    void securityClicked();
    void examineClicked();
    void viewClicked();


private slots:
    void showSwitch();
    void quickClicked();
    void fullClicked();
    void customClicked();

private:
    void initUI();
    void initConnect();
private:
    QStackedWidget *m_stacked;
    StaticButton *m_payinsureButton;
    StaticButton *m_securityButton;
    StaticButton *m_examineButton;
    StaticButton *m_viewButton;

    QPushButton  *switch_button;
    QPushButton  *quick_button;
    SwitchWidget *m_switchwidget;
    CustomScan   *m_scan;
};

#endif // TOPBOTTOMWIDGET_H
