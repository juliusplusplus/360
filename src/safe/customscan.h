#ifndef CUSTOMSCAN_H
#define CUSTOMSCAN_H
#include <QDialog>

class QCheckBox;
class QLabel;
class QLineEdit;
class QPushButton;

class CustomScan : public QDialog
{
    Q_OBJECT
public:
    CustomScan(QWidget *parent = 0);

signals:
    void Find();

private slots:
    void findClicked();
    void enableFindBtn(const QString &);

private:
    void initUI();
    void initConnect();
private:
    QLabel      *label;
    QLineEdit   *lineEdit;
    QCheckBox   *backwardCheckBox;
    QPushButton *findButton;
    QPushButton *closeButton;
};

#endif // CUSTOMSCAN_H
