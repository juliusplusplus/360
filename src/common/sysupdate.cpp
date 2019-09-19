#include "sysupdate.h"
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

SysUpdate::SysUpdate(QWidget *parent)
    : QWidget(parent)
{
    this->setFixedSize(340, 420);
    this->setWindowTitle(tr("安恒主机卫士"));
    this->setWindowIcon(QIcon(":/main/AboutLogo"));

    m_update_wait = new update_wait();
    icon_label = new QLabel();
    info_label = new QLabel();
    version_label = new QLabel();
    virus_label = new QLabel();
    mummy_label = new QLabel();
    wait_button = new QPushButton();

    QPixmap pixmap(":/main/AboutLogo");
    icon_label->setPixmap(pixmap);
    icon_label->setFixedSize(pixmap.size());

    wait_button->setStyleSheet("border-radius:3px; border:1px solid rgb(180, 190, 200); color:white；background:blue;");
    wait_button->setFixedSize(200, 50);

    QVBoxLayout *v_layout = new QVBoxLayout();
    v_layout->addWidget(icon_label);
    v_layout->addWidget(info_label);
    v_layout->addStretch();
    v_layout->setSpacing(0);
    v_layout->setContentsMargins(0, 0, 0, 0);
//    info_label->setContentsMargins(0, 0, 0, 40);

    QVBoxLayout *version_layout = new QVBoxLayout();
    version_layout->addWidget(version_label);
    version_layout->addWidget(virus_label);
    version_layout->addWidget(mummy_label);
    version_layout->addStretch();
    version_layout->setSpacing(0);
    version_layout->setContentsMargins(0, 20, 0, 20);

    QVBoxLayout *bottom_layout = new QVBoxLayout();
    bottom_layout->addStretch();
    bottom_layout->addLayout(v_layout);
    bottom_layout->addLayout(version_layout);
    bottom_layout->addWidget(wait_button);
    bottom_layout->setSpacing(0);
    bottom_layout->setContentsMargins(80, 10, 0, 10);

//    QHBoxLayout *h_layout = new QHBoxLayout();
//    h_layout->addLayout(v_layout);
//    h_layout->addWidget(icon_label);
//    h_layout->setSpacing(0);
//    h_layout->setContentsMargins(40, 0, 20, 10);

    QVBoxLayout *main_layout = new QVBoxLayout();
    main_layout->addStretch();

    main_layout->addLayout(bottom_layout);
    main_layout->setSpacing(0);
    main_layout->setContentsMargins(0, 0, 0, 0);

    setLayout(main_layout);

    info_label->setStyleSheet("color:orange;");

    connect(wait_button,SIGNAL(clicked(bool)),this,SLOT(wait_clicked()));

    this->translateLanguage();


}

void SysUpdate::translateLanguage()
{
    info_label->setText(tr("正在获取服务器升级信息"));
    version_label->setText(tr("当前版本：4.0.6.6"));
    virus_label->setText(tr("当前病毒库：2018-06-01 15：27"));
    mummy_label ->setText(tr("当前网马库：2018-06-01 15：27"));
    wait_button->setText(tr("请稍等"));
}

//void SysUpdate::mousePressEvent( QMouseEvent * event )
//{
//    //只能是鼠标左键移动和改变大小
//    if(event->button() == Qt::LeftButton)
//    {
//        mouse_press = true;
//    }

//    //窗口移动距离
//    move_point = event->globalPos() - pos();
//}

//void SysUpdate::mouseReleaseEvent(QMouseEvent *)
//{
//    mouse_press = false;
//}

//void SysUpdate::mouseMoveEvent(QMouseEvent *event)
//{
//    //移动窗口
//    if(mouse_press)
//    {
//        QPoint move_pos = event->globalPos();
//        move(move_pos - move_point);
//    }
//}

void SysUpdate::wait_clicked()
{
    //设置菜单出现的位置
//    QPoint q = this->rect().topRight();
//    q.setX(q.x() + 150);
//    q.setY(q.y() + 22);
//    move(this->mapFromGlobal(q));
//    QPoint wait_pos = event->globalPos();
//    move(wait_pos);
    m_update_wait->exec();
}
