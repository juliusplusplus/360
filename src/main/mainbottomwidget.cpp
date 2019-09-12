#include "mainbottomwidget.h"
#include "bottom/mainexaminewidget.h"
#include "bottom/mainbottomfirstwidget.h"

#include "../common/staticbutton.h"
#include "../common/sysbuttongroup.h"

#include <QPainter>
#include <QVBoxLayout>
#include <QStackedLayout>
#include <QPropertyAnimation>

#include <QLabel>
#include <QStackedWidget>

MainBottomWidget::MainBottomWidget(QWidget *parent)
    : BaseStyleWidget(parent)
{
    this->initUI();
    this->initAnimation();
    this->initConnect();
}

void MainBottomWidget::initUI()
{
    this->setGeometry(0, 0, 900, 160);
//    this->setGeometry(0, 440, 900, 160);
    m_stackedWidget = new QStackedLayout;
    m_firstWidget = new MainBottomFirstWidget;

//    QVBoxLayout *t_layout = new QVBoxLayout;
//    t_layout->addWidget(m_firstWidget);

    BaseStyleWidget *whiteWidget = new BaseStyleWidget;
    whiteWidget->setStyleSheet("background:white;");
    m_examineWidget = new MainExamineWidget;

    m_stackedWidget->addWidget(m_firstWidget);
    m_stackedWidget->addWidget(whiteWidget);
    m_stackedWidget->addWidget(m_examineWidget);

    this->initTopTitleWidget();
    this->setLayout(m_stackedWidget);
}

void MainBottomWidget::initAnimation()
{
    QRect mainRect(0, 240, 900, 360);
    QRect origRect(0, 440, 900, 160);
    m_examineAnimation = new QPropertyAnimation(this, "geometry");
    m_examineAnimation->setDuration(200);
    m_examineAnimation->setStartValue(origRect);
    m_examineAnimation->setEndValue(mainRect);


    m_returnAnimation = new QPropertyAnimation(this, "geometry");
    m_returnAnimation->setDuration(200);
    m_returnAnimation->setStartValue(mainRect);
    m_returnAnimation->setEndValue(origRect);

}

void MainBottomWidget::initConnect()
{
    connect(m_examineAnimation, SIGNAL(finished()), this, SLOT(goExamineFinished()));
    connect(m_returnAnimation, SIGNAL(finished()), this, SLOT(goMainFinished()));
    connect(m_firstWidget, SIGNAL(safeClicked()), this, SIGNAL(safeClicked()));
    connect(m_firstWidget, SIGNAL(cleanClicked()), this, SIGNAL(cleanClicked()));
    connect(m_firstWidget, SIGNAL(youhuaClicked()), this, SIGNAL(youhuaClicked()));
    connect(m_firstWidget, SIGNAL(advtoolMoreClicked()), this, SIGNAL(advtoolMoreClicked()));
}

void MainBottomWidget::initTopTitleWidget()
{
    m_titleWidget = new QWidget(this);
    m_titleWidget->setAttribute(Qt::WA_TranslucentBackground);
    m_titleWidget->setFixedWidth(width());
    m_titleWidget->move(0, 0);

    QLabel *logoLabel = new QLabel;
    logoLabel->setPixmap(QPixmap(":/main/logo"));
    QLabel *textLabel = new QLabel;
    textLabel->setText(QStringLiteral("360安全卫士 10.0 Beta"));
    textLabel->adjustSize();
    StaticButton *updateButton = new StaticButton(":/main/update_btn");
    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->addWidget(logoLabel);
    hLayout->addWidget(textLabel);
    hLayout->addWidget(updateButton);

    QWidget *title = new QWidget;
    title->setAttribute(Qt::WA_TranslucentBackground);
    title->setLayout(hLayout);

    StaticButton *returnButton = new StaticButton(":/main/return");
    connect(returnButton, SIGNAL(buttonClicked()), this, SLOT(goMainFinished()));

    m_titleStacked = new QStackedWidget;
    m_titleStacked->addWidget(title);
    m_titleStacked->addWidget(returnButton);
    m_titleStacked->setFixedHeight(returnButton->height());

    SysButtonGroup *buttonGroup = new SysButtonGroup;
    connect(buttonGroup, SIGNAL(playVideo()), this, SIGNAL(playVideo()));
    connect(buttonGroup, SIGNAL(showSkin()), this, SIGNAL(showSkin()));
    connect(buttonGroup, SIGNAL(showMenu()), this, SIGNAL(showMenu()));
    connect(buttonGroup, SIGNAL(showMin()), this, SIGNAL(showMin()));
    connect(buttonGroup, SIGNAL(closeWidget()), this, SIGNAL(closeWidget()));

    QHBoxLayout *titleLayout = new QHBoxLayout;
    titleLayout->addWidget(m_titleStacked, 0, Qt::AlignLeft | Qt::AlignTop);
    titleLayout->addStretch();
    titleLayout->addWidget(buttonGroup, 0, Qt::AlignRight | Qt::AlignTop);
    titleLayout->setContentsMargins(0, 0, 0, 0);

    m_titleWidget->setLayout(titleLayout);

}


void MainBottomWidget::goExamine()
{
    m_examineAnimation->start();
    m_stackedWidget->setCurrentIndex(1);
}

void MainBottomWidget::goMain()
{
    m_returnAnimation->start();
    m_stackedWidget->setCurrentIndex(1);
}

void MainBottomWidget::goExamineFinished()
{
    m_stackedWidget->setCurrentIndex(2);
}

void MainBottomWidget::goMainFinished()
{
    m_stackedWidget->setCurrentIndex(0);
}
