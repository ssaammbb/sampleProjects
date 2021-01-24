#include "mainwindow.h"
#include "ui_mainwindow.h"



std::string choice;
std::string ImageName;
std::string unprocessedString;
std::string pngExtension = ".jpg";





MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_imgC_clicked()
{
    /*
    getline(cin, ImageName);
    ImageName += pngExtension;
    imageProcessor.read(ImageName);
    unprocessedString = imageProcessor.getString();

    WordNode = StringProcessor.translate(unprocessedString);
    if (WordNode != NULL)
    {
        cout << "Word: " << WordNode->word << endl;
        cout << "Translation: " << WordNode->englishTranslation;
        cout << endl;
    }
    else
    {
        charCorrector.setUnprocessed(unprocessedString);
        string *StringArray = charCorrector.stringCorrector();
        for (int i = 0; i < 3; i++)
        {
            WordNode = StringProcessor.translate(StringArray[i]);
            if (WordNode != NULL)
            {
                cout << "Word: " << WordNode->word << endl;
                cout << "Translation: " << WordNode->englishTranslation;
                cout << endl;
                break;
            }
        }
        charCorrector.~StringCorrector();
    }
    namedWindow("Processed Image", WINDOW_NORMAL);
    resizeWindow("Processed Image", 400, 400);
    imshow("Processed Image", imageProcessor.getThresh());
    waitKey(0);
    destroyWindow("Processed Image");
    imageProcessor.~ProcessImage();

    system("pause");
    cout << endl;
    */

}

std::string* MainWindow::on_pushButton_clicked()
{
    std::srand(std::time(NULL));
    bool gOn = true;
    M *game = new M;
    std::string s[5];
    std::string s2[5];
    QString qs;
    Dictionary d;
    WordItem *start;



    for (int n = 0; n < 5; n++) {
        start = d.randWord();

        s[n] = start->word;


    }

    qs = QString::fromStdString(s[0]);



    game->run(s);
    game->move(925, 280);
    game->resize(400, 450);
    game->show();
    return s;
}

void MainWindow::on_searchB_clicked()
{
    translate_search *ts = new translate_search;

    ts->resize(330, 275);
    ts->move(575, 450);
    ts->show();


}
