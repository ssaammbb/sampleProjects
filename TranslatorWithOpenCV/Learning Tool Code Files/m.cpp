#include "m.h"
#include "ui_m.h"
#include <iostream>



M::M(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::M)
{


    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timeF));
    ui->setupUi(this);
}

void M::endGame() {
	if (over == 5) {
		QString q = "Finished in: " + QString::number(tries) + " tries";
		QMessageBox::information(this, "Game Complete", q);
		this->close();
    }
}

void M::timeF()
{

}

M::~M()
{
    delete ui;
}

void M:: stateArr(bool *a){
    a[0] = s1;
    a[1] = s2;
    a[2] = s3;
    a[3] = s4;
    a[4] = s5;
}

void M:: stateChange(int i){

    stateArr(states);
    for(int n = 0; n < 5; n++){
        if(n != i)
            states[n] = false;
    }
    states[i] = true;
}

void M::on_checkBox_stateChanged(int arg1)
{
    stateChange(0);
    if(ui->checkBox->isChecked()){
        ui->checkBox_2->setChecked(false);
        ui->checkBox_3->setChecked(false);
        ui->checkBox_4->setChecked(false);
        ui->checkBox_5->setChecked(false);
    }

}

void M::on_checkBox_2_stateChanged(int arg1)
{
    stateChange(1);
    if(ui->checkBox_2->isChecked()){
        ui->checkBox->setChecked(false);
        ui->checkBox_3->setChecked(false);
        ui->checkBox_4->setChecked(false);
        ui->checkBox_5->setChecked(false);
     }
}

void M::on_checkBox_3_stateChanged(int arg1)
{
    stateChange(2);
    if(ui->checkBox_3->isChecked()){
        ui->checkBox_2->setChecked(false);
        ui->checkBox->setChecked(false);
        ui->checkBox_4->setChecked(false);
        ui->checkBox_5->setChecked(false);
     }
}

void M::on_checkBox_4_stateChanged(int arg1)
{
    stateChange(3);
    if(ui->checkBox_4->isChecked()){
        ui->checkBox_2->setChecked(false);
        ui->checkBox->setChecked(false);
        ui->checkBox_3->setChecked(false);
        ui->checkBox_5->setChecked(false);
     }
}

void M::on_checkBox_5_stateChanged(int arg1)
{
    stateChange(4);
    if(ui->checkBox_5->isChecked()){
        ui->checkBox_2->setChecked(false);
        ui->checkBox_3->setChecked(false);
        ui->checkBox_4->setChecked(false);
        ui->checkBox->setChecked(false);
     }
}

void M::on_pushButton_clicked()
{
	tries++;
    if(ui->checkBox->isChecked() && garr[0].uno == 0){
        QMessageBox:: information(this, "Answer", "Correct!");
		over++;
	}
	else if (ui->checkBox_2->isChecked() && garr[0].uno == 1) {
		QMessageBox::information(this, "Answer", "Correct!");
		over++;
	}
	else if (ui->checkBox_3->isChecked() && garr[0].uno == 2) {
		QMessageBox::information(this, "Answer", "Correct!");
		over++;
	}
	else if (ui->checkBox_4->isChecked() && garr[0].uno == 3) {
		QMessageBox::information(this, "Answer", "Correct!");
		over++;
	}
	else if (ui->checkBox_5->isChecked() && garr[0].uno == 4) {
		QMessageBox::information(this, "Answer", "Correct!");
		over++;
	}else QMessageBox::information(this, "Answer", "Incorrect");
	endGame();
}

void M::on_pushButton_2_clicked()
{
	tries++;
	if (ui->checkBox->isChecked() && garr[1].uno == 0) {
		QMessageBox::information(this, "Answer", "Correct!");
		over++;
	}
	else if (ui->checkBox_2->isChecked() && garr[1].uno == 1) {
		QMessageBox::information(this, "Answer", "Correct!");
		over++;
	}
	else if (ui->checkBox_3->isChecked() && garr[1].uno == 2) {
		QMessageBox::information(this, "Answer", "Correct!");
		over++;
	}
	else if (ui->checkBox_4->isChecked() && garr[1].uno == 3) {
		QMessageBox::information(this, "Answer", "Correct!");
		over++;
	}
	else if (ui->checkBox_5->isChecked() && garr[1].uno == 4) {
		QMessageBox::information(this, "Answer", "Correct!");
		over++;
	}
	else QMessageBox::information(this, "Answer", "Incorrect");
	endGame();
}

void M::on_pushButton_3_clicked()
{
	tries++;
	if (ui->checkBox->isChecked() && garr[2].uno == 0) {
		QMessageBox::information(this, "Answer", "Correct!");
		over++;
	}
	else if (ui->checkBox_2->isChecked() && garr[2].uno == 1) {
		QMessageBox::information(this, "Answer", "Correct!");
		over++;
	}
	else if (ui->checkBox_3->isChecked() && garr[2].uno == 2) {
		QMessageBox::information(this, "Answer", "Correct!");
		over++;
	}
	else if (ui->checkBox_4->isChecked() && garr[2].uno == 3) {
		QMessageBox::information(this, "Answer", "Correct!");
		over++;
	}
	else if (ui->checkBox_5->isChecked() && garr[2].uno == 4) {
		QMessageBox::information(this, "Answer", "Correct!");
		over++;
	}
	else QMessageBox::information(this, "Answer", "Incorrect");
	endGame();
}

void M::on_pushButton_4_clicked()
{
	tries++;
	if (ui->checkBox->isChecked() && garr[3].uno == 0) {
		QMessageBox::information(this, "Answer", "Correct!");
		over++;
	}
	else if (ui->checkBox_2->isChecked() && garr[3].uno == 1) {
		QMessageBox::information(this, "Answer", "Correct!");
		over++;
	}
	else if (ui->checkBox_3->isChecked() && garr[3].uno == 2) {
		QMessageBox::information(this, "Answer", "Correct!");
		over++;
	}
	else if (ui->checkBox_4->isChecked() && garr[3].uno == 3) {
		QMessageBox::information(this, "Answer", "Correct!");
		over++;
	}
	else if (ui->checkBox_5->isChecked() && garr[3].uno == 4) {
		QMessageBox::information(this, "Answer", "Correct!");
		over++;
	}
	else QMessageBox::information(this, "Answer", "Incorrect");
	endGame();
}

void M::on_pushButton_5_clicked()
{
	tries++;
	if (ui->checkBox->isChecked() && garr[4].uno == 0) {
		QMessageBox::information(this, "Answer", "Correct!");
		over++;
	}
	else if (ui->checkBox_2->isChecked() && garr[4].uno == 1) {
		QMessageBox::information(this, "Answer", "Correct!");
		over++;
	}
	else if (ui->checkBox_3->isChecked() && garr[4].uno == 2) {
		QMessageBox::information(this, "Answer", "Correct!");
		over++;
	}
	else if (ui->checkBox_4->isChecked() && garr[4].uno == 3) {
		QMessageBox::information(this, "Answer", "Correct!");
		over++;
	}
	else if (ui->checkBox_5->isChecked() && garr[4].uno == 4) {
		QMessageBox::information(this, "Answer", "Correct!");
		over++;
	}
	else QMessageBox::information(this, "Answer", "Incorrect");
	endGame();
}

void M::run(std::string* s) {
	ui->checkBox->setText(QString::fromStdString(s[0]));
	ui->checkBox_2->setText(QString::fromStdString(s[1]));
	ui->checkBox_3->setText(QString::fromStdString(s[2]));
	ui->checkBox_4->setText(QString::fromStdString(s[3]));
	ui->checkBox_5->setText(QString::fromStdString(s[4]));

	Dictionary d;
	WordItem *start;
	
	int c = 0;
	int num = 0;
	std::srand(std::time(NULL));

	while (c < 5) {
		num = rand() % 5;
		if (garr[num].english == "") {
			garr[num].english = s[c];
			garr[num].uno = c;
			c++;
		}
		num = 0;
	}

	for (int n = 0; n < 5; n++) {
		start = d.search(garr[n].english);
		garr[n].english = start->englishTranslation;
		
	}

	ui->pushButton->setText(QString::fromStdString(garr[0].english));
	ui->pushButton_2->setText(QString::fromStdString(garr[1].english));
	ui->pushButton_3->setText(QString::fromStdString(garr[2].english));
	ui->pushButton_4->setText(QString::fromStdString(garr[3].english));
	ui->pushButton_5->setText(QString::fromStdString(garr[4].english));

}
