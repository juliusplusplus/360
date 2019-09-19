#include "maintopwidget.h"
#include "bottom/userwidget.h"
#include "bottom/topbottomwidget.h"
#include "bottom/mainscorewidget.h"
#include "../common/wenliwidget.h"
#include "../common/staticbutton.h"
#include "../common/sysbuttongroup.h"

#include <QLabel>
#include <QPainter>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStackedWidget>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>

MainTopWidget::MainTopWidget(QWidget *parent)
    : BaseStyleWidget(parent)
{
    this->initUI();
    this->initAnimations();
    this->initConnect();
}

void MainTopWidget::initAnimations()
{
    QRect mainRect(0, 0, width(), 240);
    QRect origRect = rect();
    QPoint origPoint = m_scoreWidget->pos();
    QPoint toPoint(0, m_userWidget->height() + 10);
//    QPoint toPoint(0, m_titleWidget->height() + 10);

    QPropertyAnimation *mainExamineAnim = new QPropertyAnimation(this, "geometry");
    mainExamineAnim->setDuration(200);
    mainExamineAnim->setStartValue(origRect);
    mainExamineAnim->setEndValue(mainRect);

    QPropertyAnimation *scoreExamineAnim = new QPropertyAnimation(m_scoreWidget, "pos");
    scoreExamineAnim->setDuration(200);
    scoreExamineAnim->setStartValue(origPoint);
    scoreExamineAnim->setEndValue(toPoint);

    m_examineGroupAnimation = new QParallelAnimationGroup(this);
    m_examineGroupAnimation->addAnimation(mainExamineAnim);
    m_examineGroupAnimation->addAnimation(scoreExamineAnim);

    QPropertyAnimation *mainReturnAnim = new QPropertyAnimation(this, "geometry");
    mainReturnAnim->setDuration(200);
    mainReturnAnim->setStartValue(mainRect);
    mainReturnAnim->setEndValue(origRect);

    QPropertyAnimation *scoreReturnAnim = new QPropertyAnimation(m_scoreWidget, "pos");
    scoreReturnAnim->setDuration(200);
    scoreReturnAnim->setStartValue(toPoint);
    scoreReturnAnim->setEndValue(origPoint);

    m_returnGroupAnimation = new QParallelAnimationGroup(this);
    m_returnGroupAnimation->addAnimation(mainReturnAnim);
    m_returnGroupAnimation->addAnimation(scoreReturnAnim);
}


void MainTopWidget::initUI()
{
    //this->setFixedSize(m_wenliPix.size());
    this->setGeometry(0, 200, MAIN_TOP_WIDTH, MAIN_TOP_HEIGHT);
//    this->setGeometry(0, 0, MAIN_TOP_WIDTH, MAIN_TOP_HEIGHT);
    m_backgroundWidget = new WenliWidget(this);
    m_backgroundWidget->setGeometry(rect());
    m_backgroundWidget->lower();
//    this->initTopTitleWidget();

    m_userWidget = new  UserWidget(this);
    m_userWidget->setFixedWidth(width());

    m_scoreWidget = new MainScoreWidget(this);
    m_scoreWidget->setButtonStatus(SCORE_NO_BUTTON);
    m_scoreWidget->setScoreStatus(SCORE_QUESTION);
    m_scoreWidget->setTextInfo(QStringLiteral("建议体检"), QStringLiteral("建议每天进行体检"));
    m_scoreWidget->setFixedWidth(width());

    m_bottomWidget = new TopBottomWidget(this);
    m_bottomWidget->setFixedWidth(width());
    updateSizeAndPos();
}

void MainTopWidget::initConnect()
{
    connect(m_bottomWidget, SIGNAL(examineClicked()), this, SLOT(examineClicked()));
    connect(m_bottomWidget, SIGNAL(viewClicked()), this, SLOT(viewClicked()));
    connect(m_returnGroupAnimation, SIGNAL(finished()), this, SLOT(returnAnimationFinished()));
}

void MainTopWidget::setNums(int num)
{
    m_backgroundWidget->setNums(num);
}

void MainTopWidget::updateSizeAndPos()
{
//    m_userWidget->move(0, m_titleWidget->y() + m_titleWidget->height() + 10);
    m_scoreWidget->move(0, m_userWidget->y() + m_userWidget->height() + 10);
    m_bottomWidget->move(0, m_scoreWidget->y() + m_scoreWidget->height() + 10);
}

void MainTopWidget::returnAnimationFinished()
{
    m_userWidget->show();
    m_bottomWidget->show();
}

void MainTopWidget::returnMain()
{
    m_titleStacked->setCurrentIndex(0);
    m_bottomWidget->setStackedButton(0);
    m_scoreWidget->setButtonStatus(SCORE_NO_BUTTON);
    m_returnGroupAnimation->start();
    emit goMain();
}

void MainTopWidget::examineClicked()
{
    m_titleStacked->setCurrentIndex(1);
    m_userWidget->hide();
    m_bottomWidget->hide();
    m_scoreWidget->setButtonStatus(SCORE_FIX_BUTTON);
    m_scoreWidget->setNums(85);
    this->setNums(85);
    m_examineGroupAnimation->start();
    emit goExamine();
}

void MainTopWidget::viewClicked()
{
    m_titleStacked->setCurrentIndex(1);
    m_userWidget->hide();
    m_bottomWidget->hide();
    m_examineGroupAnimation->start();
    emit goExamine();
}


void MainTopWidget::resizeEvent(QResizeEvent *)
{
    //updateSizeAndPos();
}

