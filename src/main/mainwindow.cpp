#include "mainwindow.h"
#include "mainbottomwidget.h"
#include "maintopwidget.h"
#include "../safe/safewidget.h"
#include "common/videowidget.h"
#include "../clean/cleanwidget.h"
#include "../optimize/youhuawidget.h"
#include "common/opacitywidget.h"
#include "../optimize/common/optimizebutton.h"

#include <QFile>
#include <QIcon>
#include <QLabel>
#include <QApplication>
#include <QStackedWidget>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>

MainWindow::MainWindow(QWidget *parent)
    : ShadowWidget(parent)
{
    this->initUI();
    this->initAnim();
    this->initConnect();
}

void MainWindow::initUI()
{
    this->setFixedSize(900, 600);
    this->setWindowIcon(QIcon(":/main/Logo"));
    this->setWindowTitle(QStringLiteral("360安全卫士"));
    m_video = new VideoWidget(this);
    m_stackWidget = new QStackedWidget(this);
    m_stackWidget->setGeometry(0,200,900,400);
    m_stackWidget->lower();

    //m_grayWidget = new BaseStyleWidget(this);
    m_grayWidget = new OpacityWidget(this);
    m_grayWidget->setGeometry(rect());
    m_grayWidget->setColor(QColor(Qt::gray));

    m_bottomWidget = new MainBottomWidget(this);
    m_topWidget = new MaintopWidget(this);

    m_safeWidget = new MainBottomWidget(this);
    m_stackWidget->addWidget(m_safeWidget);
    m_cleanWidget = new CleanWidget(this);
    m_stackWidget->addWidget(m_cleanWidget);
    m_youhuaWidget = new YouhuaWidget();
    m_stackWidget->addWidget(m_youhuaWidget);
}

void MainWindow::initConnect()
{
    connect(m_bottomWidget, SIGNAL(goExamine()), m_topWidget, SLOT(goExamine()));
    connect(m_bottomWidget, SIGNAL(goMain()), m_topWidget, SLOT(goMain()));
    connect(m_bottomWidget, SIGNAL(showMin()), this, SLOT(showMinimized()));
    connect(m_bottomWidget, SIGNAL(closeWidget()), this, SLOT(closeWidget()));
    connect(m_bottomWidget, SIGNAL(showSkin()), this, SLOT(showSkin()));
//    connect(m_safeWidget, SIGNAL(goToMain()), this, SLOT(goToMain()));
    connect(m_cleanWidget, SIGNAL(goToMain()), this, SLOT(goToMain()));
//    connect(m_youhuaWidget, SIGNAL(goToMain()), this, SLOT(goToMain()));
    connect(m_topWidget, SIGNAL(safeClicked()), this, SLOT(goToSafe()));
    connect(m_topWidget, SIGNAL(cleanClicked()), this, SLOT(goToClean()));
    connect(m_topWidget, SIGNAL(youhuaClicked()), this, SLOT(goToYouhua()));
    connect(m_topWidget, SIGNAL(showMin()), this, SLOT(showMinimized()));
    connect(m_topWidget, SIGNAL(closeWidget()), this, SLOT(closeWidget()));
    connect(m_topWidget, SIGNAL(showSkin()), this, SLOT(showSkin()));
    connect(m_upGroup, SIGNAL(finished()), this, SLOT(upAnimFinished()));
}

void MainWindow::initAnim()
{
//    QPropertyAnimation *m_upMainAnimation = new QPropertyAnimation(m_topWidget, "pos");
//    m_upMainAnimation->setDuration(200);
//    m_upMainAnimation->setStartValue(QPoint(0, 0));
//    m_upMainAnimation->setEndValue(QPoint(0, -200));

    QPropertyAnimation *m_downMainAnimation = new QPropertyAnimation(m_bottomWidget, "pos");
    m_downMainAnimation->setDuration(200);
    m_downMainAnimation->setStartValue(QPoint(0, 200));
    m_downMainAnimation->setEndValue(QPoint(0, 600));

    QPropertyAnimation  *m_toTrans = new QPropertyAnimation(m_grayWidget, "opacity");
    m_toTrans->setDuration(200);
    m_toTrans->setStartValue(1);
    m_toTrans->setEndValue(0);

    m_upGroup = new QParallelAnimationGroup;
//    m_upGroup->addAnimation(m_upMainAnimation);
    m_upGroup->addAnimation(m_downMainAnimation);
    m_upGroup->addAnimation(m_toTrans);

//    QPropertyAnimation *m_upGarAnimation = new QPropertyAnimation(m_topWidget, "pos");
//    m_upGarAnimation->setDuration(200);
//    m_upGarAnimation->setStartValue(QPoint(0, -200));
//    m_upGarAnimation->setEndValue(QPoint(0, 0));

    QPropertyAnimation *m_downGarAnimation = new QPropertyAnimation(m_bottomWidget, "pos");
    m_downGarAnimation->setDuration(200);
    m_downGarAnimation->setStartValue(QPoint(0, 600));
    m_downGarAnimation->setEndValue(QPoint(0, 200));

    QPropertyAnimation  *m_toGray = new QPropertyAnimation(m_grayWidget, "opacity");
    m_toGray->setDuration(200);
    m_toGray->setStartValue(0);
    m_toGray->setEndValue(1);

    m_downGroup = new QParallelAnimationGroup;
//    m_downGroup->addAnimation(m_upGarAnimation);
    m_downGroup->addAnimation(m_downGarAnimation);
    m_downGroup->addAnimation(m_toGray);
}

void MainWindow::upAnimFinished()
{
    m_grayWidget->hide();
}


void MainWindow::showMenu()
{

}

void MainWindow::goToMain()
{
    m_grayWidget->show();
    m_downGroup->start();
}

void MainWindow::goToSafe()
{
    m_stackWidget->setCurrentIndex(0);
//    m_upGroup->start();
}

void MainWindow::goToClean()
{
    m_stackWidget->setCurrentIndex(1);
    m_upGroup->start();
    m_cleanWidget->startFirst();
}

void MainWindow::goToYouhua()
{
    m_stackWidget->setCurrentIndex(2);
    m_upGroup->start();
}

void MainWindow::showSkin()
{
    QFile qss(":/qss/skin");
    qss.open(QFile::ReadOnly);
    qApp->setStyleSheet(qss.readAll());
    qss.close();
    update();
}

void MainWindow::closeWidget()
{
    qApp->quit();
}

void MainWindow::showMin()
{

}
