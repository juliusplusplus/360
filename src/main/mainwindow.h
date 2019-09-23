#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "common/shadowwidget.h"

class SafeWidget;
class CleanWidget;
class VideoWidget;
class YouhuaWidget;
class MainBottomWidget;
class OpacityWidget;
class QStackedWidget;
class BaseStyleWidget;
class MaintopWidget;
class QParallelAnimationGroup;

class MainWindow : public ShadowWidget
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);

private:
    void initUI();
    void initAnim();
    void initConnect();

private slots:
    void showMin();
    void showSkin();
    void showMenu();
    void goToSafe();
    void goToMain();
    void goToClean();
    void goToYouhua();
    void closeWidget();
    void upAnimFinished();

private:
    MainBottomWidget              *m_safeWidget;
    VideoWidget             *m_video;
    CleanWidget             *m_cleanWidget;
    YouhuaWidget            *m_youhuaWidget;
    MainBottomWidget        *m_bottomWidget;
    OpacityWidget           *m_grayWidget;
    QStackedWidget          *m_stackWidget;
    MaintopWidget           *m_topWidget;
    QParallelAnimationGroup *m_upGroup;
    QParallelAnimationGroup *m_downGroup;
};

#endif // MAINWINDOW_H
