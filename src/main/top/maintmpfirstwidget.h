#ifndef MainTmpFirstWidget_H
#define MainTmpFirstWidget_H

#include "../../common/basestylewidget.h"

#include <QWidget>

class StaticButton;
//class BackgroundButton;

class MainTmpFirstWidget : public BaseStyleWidget
{
    Q_OBJECT
public:
    explicit MainTmpFirstWidget(QWidget *parent = 0);

signals:
    void safeClicked();
    void cleanClicked();
    void youhuaClicked();
//    void advtoolMoreClicked();

private:
    void initUI();
    void initConnect();

private:
    StaticButton *m_safeButton;
    StaticButton *m_cleanButton;
    StaticButton *m_youhuaButton;
    StaticButton *m_webButton;
    StaticButton *m_advtoolMore;
};

#endif // MainTmpFirstWidget_H
