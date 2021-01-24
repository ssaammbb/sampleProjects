#ifndef TRANSLATE_SEARCH_H
#define TRANSLATE_SEARCH_H
#include "m.h"

#include <QWidget>

namespace Ui {
class translate_search;
}

class translate_search : public QWidget
{
    Q_OBJECT

public:
    explicit translate_search(QWidget *parent = nullptr);
    ~translate_search();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::translate_search *ui;
};

#endif // TRANSLATE_SEARCH_H
