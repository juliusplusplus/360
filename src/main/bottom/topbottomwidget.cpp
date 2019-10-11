#include "topbottomwidget.h"
#include "../../common/staticbutton.h"
#include <QStackedWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDebug>

TopBottomWidget::TopBottomWidget(QWidget *parent) :
    QWidget(parent)
{
    this->initUI();
    this->initConnect();
}

void TopBottomWidget::initUI()
{
    m_switchwidget = new SwitchWidget;
    m_scan = new CustomScan;
//    颜色先忽略处理
//    QWidget *m_safewidget = new QWidget;
//    m_safewidget->setAutoFillBackground(true);
//    QPalette p=m_safewidget->palette();
//    p.setColor(QPalette::Window,QColor("blue"));
//    m_safewidget->setPalette(p);
    QHBoxLayout *safeLayout = new QHBoxLayout;
    quick_button = new QPushButton(tr("快速扫描"));
    quick_button->setFixedSize(150,40);
    QIcon button_ico(":/main/default_theme/MainFrame/Image/arrow.png");
    switch_button = new QPushButton(button_ico,"");
    quick_button->setObjectName("buttontest");
    switch_button->setObjectName("buttontest");
    safeLayout->addStretch();
    safeLayout->addWidget(quick_button);
    safeLayout->addWidget(switch_button, 0 , Qt::AlignLeft);
    safeLayout->addStretch();
    safeLayout->setSpacing(0);
//    safeLayout->addWidget(m_safewidget);

    m_stacked = new QStackedWidget;
    m_examineButton = new StaticButton(":/main/btn_examine_now");
    m_stacked->addWidget(m_examineButton);
    m_viewButton = new StaticButton(":/main/btn_view_detail");
    m_stacked->addWidget(m_viewButton);

    //TODO 具体时间没加
    m_virustime = new QLabel(tr("病毒库时间："));
    x_virustime = new QLabel(tr("09/26/2018"));
    m_isolateButton = new QPushButton("隔离区");
    m_isolateButton->setObjectName("buttontest");
    m_trustButton= new QPushButton(tr("信任区"));
    m_trustButton->setObjectName("buttontest");

    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->addWidget(m_virustime);
    hLayout->addWidget(x_virustime);
    hLayout->addStretch();
    hLayout->addWidget(m_isolateButton);
    hLayout->addWidget(m_trustButton);
//    hLayout->setSpacing(5);
//    hLayout->setContentsMargins(15, 10, 10, 30);


    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(safeLayout);
//    mainLayout->setStretchFactor(safeLayout,5);
    mainLayout->addStretch();
    mainLayout->addLayout(hLayout);
//    mainLayout->setStretchFactor(hLayout,1);
    this->setLayout(mainLayout);
}

void TopBottomWidget::initConnect()
{
    connect(m_examineButton, SIGNAL(buttonClicked()), this, SIGNAL(examineClicked()));
    connect(m_viewButton, SIGNAL(buttonClicked()), this, SIGNAL(viewClicked()));
//    connect(m_payinsureButton, SIGNAL(buttonClicked()), this, SIGNAL(payinsureClicked()));
//    connect(m_securityButton, SIGNAL(buttonClicked()), this, SIGNAL(securityClicked()));
    connect(switch_button,SIGNAL(clicked(bool)),this,SLOT(showSwitch()));
    connect(quick_button,SIGNAL(clicked(bool)),this,SLOT(quickClicked()));
    connect(m_switchwidget,SIGNAL(fullClicked()),this,SLOT(fullClicked()));
    connect(m_switchwidget,SIGNAL(customClicked()),this,SLOT(customClicked()));
}

void TopBottomWidget::setStackedButton(int index)
{
    m_stacked->setCurrentIndex(index);
}

void TopBottomWidget::showSwitch()
{
    if(m_switchwidget->isHidden()){
        qDebug()<<"sss";
        QPoint oPoint = switch_button->mapToGlobal(QPoint(-quick_button->width(), switch_button->height()));
        m_switchwidget->move(oPoint);
        //TODO 現在用的是非模式对话框，但是这样主界面可触碰，没法阻塞了，用其他模式的话没法再次点击按钮关闭
        m_switchwidget->setModal(false);
        m_switchwidget->setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
        m_switchwidget->show();
    }else {
        qDebug()<<"ttt ";
        m_switchwidget->close();
    }
}

void TopBottomWidget::quickClicked()
{
    qDebug()<<"quick !";
}

void TopBottomWidget::fullClicked()
{
    qDebug()<<"full ! ";
}

void TopBottomWidget::customClicked()
{
    qDebug()<<"custom !";
    //Windows可通过此函数调用文件
//    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
//                                                      "/",
//                                                      tr("Images (*.png *.xpm *.jpg)"));
    m_scan->exec();
}

