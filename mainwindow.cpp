
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "files.h"
#include <sstream>
#include <QPainter>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Setup Push buttons
    ui->dodgerButton->setFixedSize(80, 55);
    ui->angelsButton->setFixedSize(80, 55);
    ui->sanDiegoButton->setFixedSize(80, 55);
    ui->oaklandAButton->setFixedSize(80, 55);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::gotoPage(int pg)
{
    ui->stackedWidget->setCurrentIndex(pg);
}

void MainWindow::on_customerPushButtonMenu_clicked()
{
    gotoPage(1);
}

void MainWindow::on_adminPushButtonMain_clicked()
{
    gotoPage(5);
}
void MainWindow::on_customerDoneButton_clicked()
{
    gotoPage(0);
}
void MainWindow::on_mapPgDoneButton_clicked()
{
    gotoPage(6);
}
void MainWindow::on_adminPgDoneButton_clicked()
{
    ui->textBrowser_2->clear();
    gotoPage(0);
}

void MainWindow::on_souvenirsDoneButton_clicked()
{
    gotoPage(6);
}
void MainWindow::setStadiumTextBrowser(string stadiumTemp)
{
    gotoPage(2);
    stadium temp;
    temp = g.getStadiumInfo(stadiumTemp);
    string info = temp.getAllInfo();
    QString a;
    a = QString::fromStdString(info);
    ui->stadiumInfoTextBrowser->setText(a);
}
void MainWindow::on_stadiumInfoDoneButton_clicked()
{
    gotoPage(1);
}
void MainWindow::on_exitMainButton_clicked()
{


}
void MainWindow::on_minnesotaButton_clicked()
{
    planTeamButtons("Target Field");
}

void MainWindow::on_texasRangersButton_clicked()
{
    planTeamButtons("Globe Life Park in Arlington");
}

void MainWindow::on_houstonButton_clicked()
{
    planTeamButtons("Minute Maid Park");
}

void MainWindow::on_milwaukeeButton_clicked()
{
    planTeamButtons("Miller Park");
}

void MainWindow::on_chicagoButton_clicked()
{
    planTeamButtons("Wrigley Field");
}

void MainWindow::on_chicagoWhiteSoxButton_clicked()
{
    planTeamButtons("US Cellular Field");
}

void MainWindow::on_cincinattiButton_clicked()
{
    planTeamButtons("Great America Ball Park");
}

void MainWindow::on_atlantaButton_clicked()
{
    planTeamButtons("Turner Field");
}

void MainWindow::on_clevelandButton_clicked()
{
    planTeamButtons("Progressive Field");
}

void MainWindow::on_tampaBayButton_clicked()
{
    planTeamButtons("Tropicana Field");
}

void MainWindow::on_floridaButton_clicked()
{
    planTeamButtons("Marlins Park");
}

void MainWindow::on_pittsburghButton_clicked()
{
    planTeamButtons("PNC Park");
}

void MainWindow::on_washingtonButton_clicked()
{
    planTeamButtons("Nationals Park");
}

void MainWindow::on_torontoButton_clicked()
{
    planTeamButtons("Rogers Centre");
}

void MainWindow::on_detroitButton_2_clicked()
{
    planTeamButtons("Comerica Park");
}

void MainWindow::on_bostonButton_clicked()
{
    planTeamButtons("Fenway Park");
}

void MainWindow::on_baltimoreButton_clicked()
{
    planTeamButtons("Oriole Park at Camden Yards");
}

void MainWindow::on_phillyButton_clicked()
{
    planTeamButtons("Citizens Bank Park");
}

void MainWindow::on_nyYankeesButton_clicked()
{
    planTeamButtons("Yankee Stadium");
}

void MainWindow::on_dodgerButton_clicked()
{
    planTeamButtons("Dodger Stadium");
}

void MainWindow::on_angelsButton_clicked()
{
    planTeamButtons("Angels Stadium of Anaheim");
}

void MainWindow::on_kansasCityButton_clicked()
{
    planTeamButtons("Kauffman Stadium");
}

void MainWindow::on_stLouisButton_clicked()
{
    planTeamButtons("Busch Stadium");
}

void MainWindow::on_nyMetsButton_clicked()
{
    planTeamButtons("Citi Field");
}

void MainWindow::on_stadiumsByNamButton_clicked()
{
    gotoPage(2);

}
void MainWindow::on_stadiumTableInfo_clicked()
{
    gotoPage(7);
}
void MainWindow::on_gobacktomainpage_clicked()

{
    gotoPage(0);
}
void MainWindow::on_GrassSurface_currentIndexChanged()
{
    on_stadiumTableInfo_clicked();
}
void MainWindow::on_planTripButton_clicked()
{
        gotoPage(6);
}
void MainWindow::plannedTripTable()
{

}
void MainWindow::on_pushButton_31_clicked()
{

    gotoPage(1);
}

void MainWindow::on_allStadiumsButton_clicked()
{
}

void MainWindow::on_pushButton_38_clicked()
{

    gotoPage(4);
}
void MainWindow::on_pushButton_39_clicked()
{
    gotoPage(3);
}

void MainWindow::on_pushButton_clicked()
{
    gotoPage(8);

}

void MainWindow::on_modAddNewButton_clicked()
{
    ui->modificationTable->insertRow(ui->modificationTable->rowCount());
    ui->modificationTable->scrollToBottom();

}

void MainWindow::on_modDoneButton_clicked()
{

}

void MainWindow::on_pushButton_3_clicked()
{
    gotoPage(9);

}

void MainWindow::on_modSDoneButton_clicked()
{

}
void MainWindow::on_modSAddNewButton_clicked()
{
    ui->modSouvenirTable->insertRow(ui->modSouvenirTable->rowCount());
    ui->modSouvenirTable->scrollToBottom();
}
void MainWindow::on_stadiumTable_clicked()
{
    gotoPage(7);

}
void MainWindow::on_stadiumInfoCheckBox_stateChanged(int arg1)
{
    if(ui->stadiumInfoCheckBox->isChecked())
    {
        ui->stadiumCheckBoxBrowser->setText("Select a stadium to see their info!");
    }
    else
    {
        ui->stadiumCheckBoxBrowser->setText("Check to select a stadiums' info.");
    }
}
void MainWindow::on_sanDiegoButton_clicked()
{
    planTeamButtons("Petco Park");
}

void MainWindow::on_sanFranciscoButton_clicked()
{
    planTeamButtons("AT&T Park");
}

void MainWindow::on_oaklandAButton_clicked()
{
    planTeamButtons("O.co Coliseum");
}

void MainWindow::on_seattleButton_clicked()
{
    planTeamButtons("SafeCo Field");
}

void MainWindow::on_coloradoButton_clicked()
{
    planTeamButtons("Coors Field");
}

void MainWindow::on_arizonaButton_clicked()
{
    planTeamButtons("Chase Field");
}

void MainWindow::planTeamButtons(string stadiumName)
{

}
void MainWindow::on_restartDreamList_clicked()
{


}

void MainWindow::clearDreamList()
{

}
bool MainWindow::alreadyInDreamList(string stadiumName)
{

}
void MainWindow::deleteDreamStadium(string stadiumName)
{
    for(unsigned int i = 0; i < dreamList.size(); i++)
    {

        if(dreamList[i] == stadiumName)
        {
            dreamList.erase(dreamList.begin()+i);
            return;
        }
    }
}
QString MainWindow::getDreamStrArray()
{

}

void MainWindow::on_allNLStadiumsButton_clicked()
{

}
void MainWindow::on_allALStadiumsButton_clicked()
{


}
void MainWindow::on_backtoMain_clicked()
{
    gotoPage(0);
}
void MainWindow::on_showMapButton_clicked()
{


}

List<stadium> MainWindow::modify_newStadiumAddedByUser(List<stadium> list){

}

List<stadium> MainWindow::getStadiumListALL(){

}

bool MainWindow::isNewStadium(stadium toCheck){

}

void MainWindow::on_pushButton_5_clicked()
{
    gotoPage(10);



}

void MainWindow::on_CancelButtonTrackSouvenir_clicked()
{
    gotoPage(4);
}

void MainWindow::on_AddbuttonTrackSouvenir_clicked()
{


}

void MainWindow::on_showMapButtonMainPage_clicked()
{

}

void MainWindow::on_DoneButton2_clicked()
{
    gotoPage(1);
}
