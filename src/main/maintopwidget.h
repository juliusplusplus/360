#ifndef MainTOPWidget_H
#define MainTOPWidget_H

#include "../common/basestylewidget.h"
#include "../common/sysupdate.h"
#include "../common/staticbutton.h"
#include <QWidget>

class QStackedLayout;
class MainExamineWidget;
class QPropertyAnimation;
class MainTopFirstWidget;

class QStackedWidget;
class UserWidget;
class WenliWidget;
class MainScoreWidget;
class TopBottomWidget;
class QParallelAnimationGroup;

class MaintopWidget : public BaseStyleWidget
{
    Q_OBJECT

public:
    explicit MaintopWidget(QWidget *parent = 0);
    bool eventFilter(QObject *watched, QEvent *event);

public slots:
    void goExamine();
    void goMain();

private slots:
    void goExamineFinished();
    void goMainFinished();
    void goupdate();
    void returnMain();

signals:
    void safeClicked();
    void cleanClicked();
    void youhuaClicked();
//    void advtoolMoreClicked();

    void showSkin();
    void showMenu();
    void showMin();
    void closeWidget();

private:
    void initUI();
    void initAnimation();
    void initConnect();
    void initTopTitleWidget();

private:
    QStackedLayout        *m_stackedWidget;
    MainExamineWidget     *m_examineWidget;
    QPropertyAnimation    *m_examineAnimation;
    QPropertyAnimation    *m_returnAnimation;
    MainTopFirstWidget      *m_firstWidget;


    QWidget                 *m_titleWidget;
    QStackedWidget          *m_titleStacked;
    SysUpdate               *m_sysUpdate;
    StaticButton            *updateButton;
    QLabel            *suspendLabel;
};

#endif // MainTOPWidget_H
