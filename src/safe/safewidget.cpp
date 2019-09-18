#include "safewidget.h"
#include "common/safescanbottom.h"
#include "../common/wenlibackwidget.h"
#include "../common/stackstatuswidget.h"

#include <QVBoxLayout>
#include <QDebug>
#include <QFileDialog>

SafeWidget::SafeWidget(QWidget *parent)
    : QWidget(parent)
{
    this->initUI();
    this->initConnect();
}

void SafeWidget::initUI()
{
    m_customScan = new CustomScan;

    m_topBackWidget = new WenliBackWidget;
    m_stackStatusWidget = new StackStatusWidget;
    m_topBackWidget->insertWidget(m_stackStatusWidget);
    m_topBackWidget->setButtonInfo(":/safe/return");
    m_stackStatusWidget->setStaticIcon(":/safe/logo_normal");
    m_stackStatusWidget->setNormalButton(":/safe/start");
//    m_stackStatusWidget->setTextInfo("what information");
    m_topBackWidget->setFixedHeight(150);
    m_scanBottomWidget = new SafeScanBottom;

    QVBoxLayout *vLayout = new QVBoxLayout;
    vLayout->addWidget(m_topBackWidget);
    vLayout->addWidget(m_scanBottomWidget);
    vLayout->setSpacing(0);
    vLayout->setContentsMargins(0,0,0,0);

    this->setLayout(vLayout);

}

void SafeWidget::initConnect()
{
    connect(m_topBackWidget, SIGNAL(buttonClicked()), this, SIGNAL(goToMain()));
    connect(m_scanBottomWidget,SIGNAL(quickClicked()),this,SLOT(quick_scan()));
    connect(m_scanBottomWidget,SIGNAL(customClicked()),this,SLOT(custom_scan()));
}

void SafeWidget::quick_scan()
{
    qDebug()<<"quick ! ";
}

void SafeWidget::custom_scan()
{
    qDebug()<<"custom !";
    //Windows可通过此函数调用文件
//    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
//                                                      "/",
//                                                      tr("Images (*.png *.xpm *.jpg)"));
    m_customScan->exec();

}
