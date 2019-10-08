#include "switchwidget.h"
#include <QPushButton>
#include <QVBoxLayout>

SwitchWidget::SwitchWidget(QWidget *parent)
    :QDialog (parent)
{
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog );
    full_scan = new QPushButton;
    custom_scan = new QPushButton;
    full_scan->setObjectName("buttontest");
    custom_scan->setObjectName("buttontest");
//    full_scan->setStyleSheet("border-radius:3px; border:1px solid rgb(180,190,200); ");
    full_scan->setFixedSize(150,40);
//    custom_scan->setStyleSheet("border-radius:3px; border:1px solid rgb(180,190,200);");
    custom_scan->setFixedSize(150,40);

    QVBoxLayout *main_layout = new QVBoxLayout();
    main_layout->addWidget(full_scan,0,Qt::AlignLeft);
    main_layout->addWidget(custom_scan,0,Qt::AlignLeft);
    main_layout->setSpacing(0);
    main_layout->setContentsMargins(0,0,0,0);

    this->setLayout(main_layout);
    this->translateLanguage();
    this->initConnect();

}

void SwitchWidget::translateLanguage()
{
    full_scan->setText(tr("全盘扫描"));
    custom_scan->setText(tr("指定目录扫描"));
}

void SwitchWidget::initConnect()
{
    connect(full_scan, SIGNAL(clicked()), this, SIGNAL(fullClicked()));
    connect(custom_scan, SIGNAL(clicked()), this, SIGNAL(customClicked()));
}
