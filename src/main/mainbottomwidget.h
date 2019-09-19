#ifndef MAINBOTTOMWIDGET_H
#define MAINBOTTOMWIDGET_H

#include "../common/basestylewidget.h"
#include "../common/sysupdate.h"
#include <QWidget>

class QStackedLayout;
class MainExamineWidget;
class QPropertyAnimation;
class MainBottomFirstWidget;

class QStackedWidget;
class UserWidget;
class WenliWidget;
class MainScoreWidget;
class TopBottomWidget;
class QParallelAnimationGroup;

class MainBottomWidget : public BaseStyleWidget
{
    Q_OBJECT

public:
    explicit MainBottomWidget(QWidget *parent = 0);

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

    void playVideo();
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
    MainBottomFirstWidget *m_firstWidget;


    QWidget                 *m_titleWidget;
    QStackedWidget          *m_titleStacked;
    SysUpdate               *m_sysUpdate;
};

#endif // MAINBOTTOMWIDGET_H
