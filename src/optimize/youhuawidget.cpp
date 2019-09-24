#include "youhuawidget.h"
#include "common/youhuascanbottom.h"
#include "../common/wenlibackwidget.h"
#include "../common/stackstatuswidget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QGraphicsWidget>

YouhuaWidget::YouhuaWidget(QWidget *parent) :
    QWidget(parent)
{
    this->setAutoFillBackground(true);
    QPalette p=this->palette();
    p.setColor(QPalette::Window,QColor("blue"));
    this->setPalette(p);
    this->initUI();
}

void YouhuaWidget::initUI()
{
//    m_topBackWidget = new WenliBackWidget;
//    m_stackStatusWidget = new StackStatusWidget;
//    m_topBackWidget->insertWidget(m_stackStatusWidget);
//    m_topBackWidget->setButtonInfo(":/safe/return");
//    m_stackStatusWidget->setStaticIcon(":/youhua/logo");
//    m_stackStatusWidget->setNormalButton(":/youhua/start");
//    m_stackStatusWidget->setTextInfo("一键优化，让电脑快如闪电", \
//                                         "全面提升电脑开机速度、系统速度、上网速度、硬盘速度");
//    m_topBackWidget->setFixedHeight(150);
//    connect(m_topBackWidget, SIGNAL(buttonClicked()), this, SIGNAL(goToMain()));
//    m_scanBottomWidget = new YouhuaScanBottom;

//    QVBoxLayout *vLayout = new QVBoxLayout;
//    vLayout->addWidget(m_topBackWidget);
//    vLayout->addWidget(m_scanBottomWidget);
//    vLayout->setSpacing(0);
//    vLayout->setContentsMargins(0,0,0,0);

//    this->setLayout(vLayout);
    QPushButton *button1 = new QPushButton(tr("hello"));
//    button1->setObjectName("buttontest");
    QPushButton *button2 = new QPushButton(tr("Bro"));
//    button2->setObjectName("buttontest");
    QGraphicsWidget *stack = new QGraphicsWidget;
    stack->setAutoFillBackground(true);;
    QPalette p=stack->palette();
    p.setColor(QPalette::Window,QColor("blue"));
    stack->setPalette(p);
    QHBoxLayout *mainlayout = new QHBoxLayout;
    mainlayout->addWidget(button1);
    mainlayout->addWidget(button2);
//    mainlayout->addLayout(stack);
    mainlayout->setContentsMargins(0,0,0,0);
    mainlayout->setSpacing(0);

    this->setLayout(mainlayout);
}
