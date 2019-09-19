#ifndef UPDATE_WAIT_H
#define UPDATE_WAIT_H

#include<QDialog>

class update_wait : public QDialog
{
    Q_OBJECT

public:
    explicit update_wait(QWidget *parent=0);
    ~update_wait();
    void translateLanguage();

private:
    QRect location;
    QPushButton *unable_button;
    QPushButton *refuse_button;
    QPushButton *accept_button;
};

#endif // UPDATE_WAIT_H
