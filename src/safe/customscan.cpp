#include "customscan.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDebug>

CustomScan::CustomScan(QWidget *parent)
    :QDialog (parent)
{
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->initUI();
    this->initConnect();

}

void CustomScan::initUI()
{
    label= new QLabel(tr("选择查杀目录"));
    lineEdit = new QLineEdit;
    label->setBuddy(lineEdit);

    findButton = new QPushButton(tr("确定"));
    findButton->setDefault(true);
    findButton->setEnabled(false);

    closeButton = new QPushButton(tr("取消"));

    QVBoxLayout *topLayout = new QVBoxLayout;
    topLayout->addWidget(label);
    topLayout->addWidget(lineEdit);

    QHBoxLayout *bottomLayout = new QHBoxLayout;
    bottomLayout->addWidget(findButton);
    bottomLayout->addWidget(closeButton);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(topLayout);
    mainLayout->addStretch();
    mainLayout->addLayout(bottomLayout);

    this->setLayout(mainLayout);
}

void CustomScan::initConnect()
{
    connect(findButton,SIGNAL(clicked()),this,SLOT(findClicked()));
    connect(closeButton,SIGNAL(clicked()),this,SLOT(close()));
}

void CustomScan::findClicked()
{
    qDebug()<<"find Clicked! ";
}
