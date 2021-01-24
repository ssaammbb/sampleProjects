#include "translate_search.h"
#include "ui_translate_search.h"

translate_search::translate_search(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::translate_search)
{
    ui->setupUi(this);
}

translate_search::~translate_search()
{
    delete ui;
}

void translate_search::on_pushButton_clicked()
{
	QString text = ui->textEdit->toPlainText();
	std::string s = text.toUtf8().constData();
	Dictionary d;
	d.read();
	std::string w;
	WordItem *wo = new WordItem;
	wo = d.search(s);
	if (wo != nullptr)
		w = wo->englishTranslation;
	else
		QMessageBox::information(this, "Error", "Cannot find given word");
	text = QString::fromStdString(w);
	ui->textEdit_O->setText(text);
	
}

void translate_search::on_pushButton_2_clicked()
{
	QString text = ui->textEdit_2->toPlainText();
	std::string s = text.toUtf8().constData();
	Dictionary d;
	d.read();
	std::string w;
	WordItem *wo = new WordItem;
	wo = d.searchE(s);
	if (wo != nullptr)
		w = wo->word;
	if (!d.isLast() && wo->word == "zona") {
		QMessageBox::information(this, "Error", "Cannot find given word");
	}
	else {
		text = QString::fromStdString(w);
		ui->textEdit_O_2->setText(text);
	}
}
