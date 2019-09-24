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


    m_payinsureButton = new StaticButton(":/main/payinsure_safe", true);
    m_securityButton = new StaticButton(":/main/security_safe", true);
    QLabel *line = new QLabel;
    QPixmap pix(":/main/guardline");
    line->setPixmap(pix);
    line->setFixedSize(pix.size());
    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->addWidget(m_payinsureButton);
    hLayout->addWidget(line);
    hLayout->addSpacing(15);
    hLayout->addWidget(m_securityButton);
    hLayout->addStretch();
    hLayout->setSpacing(5);
    hLayout->setContentsMargins(15, 10, 10, 30);


    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(safeLayout);
    mainLayout->addLayout(hLayout);
    this->setLayout(mainLayout);
}

void TopBottomWidget::initConnect()
{
    connect(m_examineButton, SIGNAL(buttonClicked()), this, SIGNAL(examineClicked()));
    connect(m_viewButton, SIGNAL(buttonClicked()), this, SIGNAL(viewClicked()));
    connect(m_payinsureButton, SIGNAL(buttonClicked()), this, SIGNAL(payinsureClicked()));
    connect(m_securityButton, SIGNAL(buttonClicked()), this, SIGNAL(securityClicked()));
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
    QPoint oPoint = switch_button->mapToGlobal(QPoint(-quick_button->width(), switch_button->height()));
    m_switchwidget->move(oPoint);
    m_switchwidget->show();
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
