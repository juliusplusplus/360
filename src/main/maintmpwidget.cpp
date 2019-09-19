#include "maintmpWidget.h"
#include "top/mainexaminewidget.h"
#include "top/maintmpfirstwidget.h"

#include "../common/staticbutton.h"
#include "../common/sysbuttongroup.h"

#include <QPainter>
#include <QVBoxLayout>
#include <QStackedLayout>
#include <QPropertyAnimation>

#include <QLabel>
#include <QStackedWidget>
#include <QEvent>
#include <QtDebug>

MaintmpWidget::MaintmpWidget(QWidget *parent)
    : BaseStyleWidget(parent)
{

    this->setStyleSheet("QWidget#mainWidget{background:blue;}");
    this->setObjectName("mainWidget");
    this->initUI();
    this->initAnimation();
    this->initConnect();
}

void MaintmpWidget::initUI()
{
    m_sysUpdate = new SysUpdate;

    this->setGeometry(0, 0, 900, 200);
//    this->setGeometry(0, 440, 900, 160);

    //标题
    QLabel *logoLabel = new QLabel;
    logoLabel->setPixmap(QPixmap(":/main/logo"));
    QLabel *textLabel = new QLabel;
    textLabel->setText(QStringLiteral("360安全卫士 10.0 Beta"));
    textLabel->adjustSize();
    updateButton = new StaticButton(":/main/update_btn");
    updateButton->installEventFilter(this);

    suspendLabel = new QLabel();
    QImage *img = new QImage;
    img->load(":/main/logo");
    suspendLabel->setPixmap(QPixmap::fromImage(*img));
    suspendLabel->installEventFilter(this);


    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->addWidget(logoLabel);
    hLayout->addWidget(textLabel);
    hLayout->addWidget(updateButton);

    QWidget *title = new QWidget;
//    title->setAttribute(Qt::WA_TranslucentBackground);
    title->setLayout(hLayout);

    StaticButton *returnButton = new StaticButton(":/main/return");
    connect(updateButton,SIGNAL(buttonClicked()),this,SLOT(goupdate()));
    connect(returnButton, SIGNAL(buttonClicked()), this, SLOT(goMainFinished()));

    m_titleStacked = new QStackedWidget;
    m_titleStacked->addWidget(title);
    m_titleStacked->addWidget(returnButton);
    m_titleStacked->setFixedHeight(returnButton->height());

    SysButtonGroup *buttonGroup = new SysButtonGroup;
    connect(buttonGroup, SIGNAL(showSkin()), this, SIGNAL(showSkin()));
    connect(buttonGroup, SIGNAL(showMenu()), this, SIGNAL(showMenu()));
    connect(buttonGroup, SIGNAL(showMin()), this, SIGNAL(showMin()));
    connect(buttonGroup, SIGNAL(closeWidget()), this, SIGNAL(closeWidget()));

    QHBoxLayout *titleLayout = new QHBoxLayout;
    titleLayout->addWidget(m_titleStacked, 0, Qt::AlignLeft | Qt::AlignTop);
    titleLayout->addStretch();
    titleLayout->addWidget(buttonGroup, 0, Qt::AlignRight | Qt::AlignTop);
    titleLayout->setContentsMargins(0, 0, 0, 0);

    //切换
    m_stackedWidget = new QStackedLayout;
    m_firstWidget = new MainTmpFirstWidget;
    BaseStyleWidget *whiteWidget = new BaseStyleWidget;
    whiteWidget->setStyleSheet("background:white;");
    m_examineWidget = new MainExamineWidget;

    m_stackedWidget->addWidget(m_firstWidget);
    m_stackedWidget->addWidget(whiteWidget);
    m_stackedWidget->addWidget(m_examineWidget);

    QVBoxLayout *t_layout = new QVBoxLayout;
    t_layout->addLayout(titleLayout);
    t_layout->setContentsMargins(0, 0, 0, 0);
    t_layout->addLayout(m_stackedWidget);
    this->setLayout(t_layout);
}

void MaintmpWidget::initAnimation()
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

void MaintmpWidget::initConnect()
{
    connect(m_examineAnimation, SIGNAL(finished()), this, SLOT(goExamineFinished()));
    connect(m_returnAnimation, SIGNAL(finished()), this, SLOT(goMainFinished()));
    connect(m_firstWidget, SIGNAL(safeClicked()), this, SIGNAL(safeClicked()));
    connect(m_firstWidget, SIGNAL(cleanClicked()), this, SIGNAL(cleanClicked()));
    connect(m_firstWidget, SIGNAL(youhuaClicked()), this, SIGNAL(youhuaClicked()));
//    connect(m_firstWidget, SIGNAL(advtoolMoreClicked()), this, SIGNAL(advtoolMoreClicked()));
}


void MaintmpWidget::goExamine()
{
    m_examineAnimation->start();
    m_stackedWidget->setCurrentIndex(1);
}

void MaintmpWidget::goMain()
{
    m_returnAnimation->start();
    m_stackedWidget->setCurrentIndex(1);
}

void MaintmpWidget::goExamineFinished()
{
    m_stackedWidget->setCurrentIndex(2);
}

void MaintmpWidget::goMainFinished()
{
    m_stackedWidget->setCurrentIndex(0);
}

void MaintmpWidget::goupdate()
{
    m_sysUpdate->show();
}

bool MaintmpWidget::eventFilter(QObject *watched, QEvent *event)
{
//    this->setWindowFlags(this->windowFlags() | Qt::FramelessWindowHint);
    if(updateButton == watched || suspendLabel == watched)
    {
        if(QEvent::Enter == event->type() )
        {
            if(suspendLabel->isHidden())
            {
                qDebug()<<"enter ";
                suspendLabel->setWindowFlags(updateButton->windowFlags() | Qt::FramelessWindowHint);
                suspendLabel->show();
                QPoint oPoint = updateButton->mapToGlobal(QPoint(20, updateButton->height()));
                suspendLabel->move(oPoint);
                suspendLabel->raise();
                return true;
            }
        }
        else if (QEvent::Leave == event->type()) {
            if(!suspendLabel->isHidden())
            {
                //这里原是判断鼠标是否在控件上但似乎判断不合适，干脆去掉，目前没发现问题。
//                if(!updateButton->geometry().contains(this->mapFromGlobal(QCursor::pos()))
//                        &&suspendLabel->geometry().contains(this->mapFromGlobal(QCursor::pos())) )
//                {
                    qDebug()<<"leave ";
                    suspendLabel->hide();
                    return true;
//                }
            }
        }
    }
    return QWidget::eventFilter(watched,event);
}

