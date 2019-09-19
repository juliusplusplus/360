#include "maintmpfirstWidget.h"
#include "../common/buttonlabel.h"
#include "../../common/staticbutton.h"
#include "../common/backgroundbutton.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>

MainTmpFirstWidget::MainTmpFirstWidget(QWidget *parent)
    : BaseStyleWidget(parent)
{
    this->setStyleSheet("QWidget#firstWidget{background:white;}");
    this->setObjectName("firstWidget");
    this->initUI();
    this->initConnect();
}

void MainTmpFirstWidget::initUI()
{
    m_safeButton = new StaticButton(":/main/safe_check");
    QLabel *safeLabel = new QLabel(QStringLiteral("病毒查杀"));
    safeLabel->setObjectName("mainTmpLabel");
    QVBoxLayout *safeLayout = new QVBoxLayout();
    safeLayout->addWidget(m_safeButton, 0, Qt::AlignCenter);
    safeLayout->addWidget(safeLabel, 0, Qt::AlignCenter);

    m_cleanButton = new StaticButton(":/main/clean");
    QLabel *cleanLabel = new QLabel(QStringLiteral("漏洞管理"));
    cleanLabel->setObjectName("mainTmpLabel");
    QVBoxLayout *cleanLayout = new QVBoxLayout();
    cleanLayout->addWidget(m_cleanButton, 0, Qt::AlignCenter);
    cleanLayout->addWidget(cleanLabel, 0, Qt::AlignCenter);

    m_youhuaButton = new StaticButton(":/main/youhua");
    QLabel *youhuaLabel = new QLabel(QStringLiteral("网马查杀"));
    youhuaLabel->setObjectName("mainTmpLabel");
    QVBoxLayout *youhuaLayout = new QVBoxLayout();
    youhuaLayout->addWidget(m_youhuaButton, 0, Qt::AlignCenter);
    youhuaLayout->addWidget(youhuaLabel, 0, Qt::AlignCenter);

    m_webButton = new StaticButton(":/main/youhua");
    QLabel *webLabel = new QLabel(QStringLiteral("Web防护"));
    webLabel->setObjectName("mainTmpLabel");
    QVBoxLayout *webLayout = new QVBoxLayout();
    webLayout->addWidget(m_webButton, 0, Qt::AlignCenter);
    webLayout->addWidget(webLabel, 0, Qt::AlignCenter);
    QHBoxLayout *staticLayout = new QHBoxLayout();
    staticLayout->addLayout(safeLayout);
    staticLayout->addStretch();
    staticLayout->addLayout(cleanLayout);
    staticLayout->addStretch();
    staticLayout->addLayout(youhuaLayout);
    staticLayout->addStretch();
    staticLayout->addLayout(webLayout);
    staticLayout->addStretch();
//    staticLayout->setContentsMargins(10, 20, 10, 10);

    QLabel *routerTitle = new QLabel(QStringLiteral("EDR客户端"));
    QFont font = routerTitle->font();
    font.setBold(true);
    font.setPixelSize(15);
    routerTitle->setFont(font);

    QLabel *routerDes = new QLabel(QStringLiteral("已连接管理系统"));
    QVBoxLayout *routerTextLayout = new QVBoxLayout();
    routerTextLayout->addWidget(routerTitle, 0, Qt::AlignRight);
    routerTextLayout->addWidget(routerDes, 0, Qt::AlignRight);
    routerTextLayout->setContentsMargins(10, 20, 10, 10);

//    StaticButton *routerButton = new StaticButton(":/main/routerdefender");
//    QHBoxLayout *routerLayout = new QHBoxLayout;
//    routerLayout->addLayout(routerTextLayout);
//    routerLayout->addWidget(routerButton)
    QHBoxLayout *mainLayout = new QHBoxLayout();
    mainLayout->addLayout(staticLayout);
    mainLayout->addStretch();
    mainLayout->addLayout(routerTextLayout);

    this->setLayout(mainLayout);
}

void MainTmpFirstWidget::initConnect()
{
    connect(m_safeButton, SIGNAL(buttonClicked()), this, SIGNAL(safeClicked()));
    connect(m_cleanButton, SIGNAL(buttonClicked()), this, SIGNAL(cleanClicked()));
    connect(m_youhuaButton, SIGNAL(buttonClicked()), this, SIGNAL(youhuaClicked()));
//    connect(m_advtoolMore, SIGNAL(buttonClicked()), this, SIGNAL(advtoolMoreClicked()));
}

