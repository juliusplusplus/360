#ifndef SYSUPDATE_H
#define SYSUPDATE_H

#include <QWidget>
class QLabel;
class QPushButton;

class SysUpdate : public QWidget
{
    Q_OBJECT
public:
    SysUpdate(QWidget *parent=0);
    void translateLanguage();
//protected:
//    void mousePressEvent(QMouseEvent *event);
//    void mouseReleaseEvent(QMouseEvent *event);
//    void mouseMoveEvent(QMouseEvent *event);
//    void paintEvent(QPaintEvent *event);
//    bool eventFilter(QObject *watched, QEvent *event);

public slots:
    void wait_clicked();

private:
    QPoint move_point;        //移动的距离
    bool mouse_press;         //按下鼠标左键
    QLabel *icon_label;       //图标
    QLabel *info_label; //正在获取服务器升级信息
    QLabel *version_label;    //主程序版本
    QLabel *virus_label;       //杀木马、防盗号、电脑加速
    QLabel *mummy_label;      //备用木马库
    QPushButton *wait_button;   //等待按钮

//    WaitDialog *wait_dialog;    //等待界面

};

#endif // SYSUPDATE_H
