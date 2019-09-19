#include "update_wait.h"
#include <QPushButton>
#include <QVBoxLayout>

update_wait::update_wait(QWidget *parent)
    :QDialog (parent)
{
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog );

    unable_button = new QPushButton;
    refuse_button = new QPushButton;
    accept_button = new QPushButton;

    unable_button->setStyleSheet("border-radius:3px; border:1px solid rgb(180,190,200); color:red;background:transparent;");
    unable_button->setFixedSize(100,20);
    refuse_button->setStyleSheet("border-radius:3px; border:1px solid rgb(180,190,200); color:red;background:transparent;");
    refuse_button->setFixedSize(100,20);
    accept_button->setStyleSheet("border-radius:3px; border:1px solid rgb(180,190,200); color:red;background:transparent;");
    accept_button->setFixedSize(100,20);

    QVBoxLayout *main_layout = new QVBoxLayout();
    main_layout->addWidget(unable_button,0,Qt::AlignLeft);
    main_layout->addWidget(refuse_button,0,Qt::AlignLeft);
    main_layout->addWidget(accept_button,0,Qt::AlignLeft);
    main_layout->setSpacing(0);
    main_layout->setContentsMargins(5,3,3,5);

    this->setLayout(main_layout);

    connect(unable_button,SIGNAL(clicked(bool)),this,SLOT(close()));
    connect(refuse_button,SIGNAL(clicked(bool)),this,SLOT(close()));
    connect(accept_button,SIGNAL(clicked(bool)),this,SLOT(close()));

    this->translateLanguage();
}

void update_wait::translateLanguage()
{
    unable_button->setText(tr("无法获取更新信息"));
    refuse_button->setText(tr("无需升级"));
    accept_button->setText(tr("需要升级"));
}

update_wait::~update_wait()
{

}
