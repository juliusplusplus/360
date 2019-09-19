#include "sysbuttongroup.h"
#include "staticbutton.h"

#include <QHBoxLayout>

SysButtonGroup::SysButtonGroup(QWidget *parent)
    : QWidget(parent)
{
    QHBoxLayout *hLayout = new QHBoxLayout;

    StaticButton *skinButton = new StaticButton(":/main/skin");
    connect(skinButton, SIGNAL(buttonClicked()), this, SIGNAL(showSkin()));

    StaticButton *menuButton = new StaticButton(":/main/menu");
    connect(menuButton, SIGNAL(buttonClicked()), this, SIGNAL(showMenu()));

    StaticButton *minButton = new StaticButton(":/main/sys_min");
    connect(minButton, SIGNAL(buttonClicked()), this, SIGNAL(showMin()));

    StaticButton *closeButton = new StaticButton(":/main/sys_close");
    connect(closeButton, SIGNAL(buttonClicked()), this, SIGNAL(closeWidget()));

    hLayout->addWidget(skinButton);
    hLayout->addWidget(menuButton);
    hLayout->addWidget(minButton);
    hLayout->addWidget(closeButton);
    hLayout->setContentsMargins(5, 0, 5, 0);
    hLayout->setSpacing(0);

    this->setLayout(hLayout);
}
