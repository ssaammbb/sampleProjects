#ifndef M_H
#define M_H

#include <QWidget>
#include <QMessageBox>
#include <QTimer>
#include "Dictionary.hpp"

struct gameItem {
	std::string english;
	int uno;
};

namespace Ui {
class M;
}

class M : public QWidget
{
    Q_OBJECT

public:
    explicit M(QWidget *parent = nullptr);
    ~M();
    void stateChange(int i);
    void stateArr(bool a[]);
	void run(std::string* s);
	gameItem garr[5];
	int over = 0;
	int tries = 0;
	void endGame();
    QMessageBox msgBox;

public slots:
    void timeF();

	

private slots:
    void on_checkBox_stateChanged(int arg1);

    void on_checkBox_2_stateChanged(int arg1);

    void on_checkBox_3_stateChanged(int arg1);

    void on_checkBox_4_stateChanged(int arg1);

    void on_checkBox_5_stateChanged(int arg1);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::M *ui;
    bool s1,s2,s3,s4,s5,b1,b2,b3,b4,b5;
    bool states[5];
    QTimer *timer;
};

#endif // M_H
