#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "graph.h"
#include "souvenir.h"
#include <QMainWindow>
#include <QMessageBox>
#include <vector>
#include <string>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

struct userInfo
{
    List<stadiumNode> plannedTrips;     //ATT - all trips
    souvenirs souvenirList;             //ATT - assoc. souvenirs
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    void gotoPage(int pg);      //IN - page to switch to

private slots:

    void on_exitMainButton_clicked();

    void on_customerPushButtonMenu_clicked();

    void on_customerDoneButton_clicked();

    void on_mapPgDoneButton_clicked();

    void on_adminPgDoneButton_clicked();

    void on_adminPushButtonMain_clicked();

    void on_souvenirsDoneButton_clicked();

    void on_stadiumInfoDoneButton_clicked();


    void setStadiumTextBrowser(string stadiumTemp); //IN - stadium to add

    void on_stadiumsByNamButton_clicked();

    void on_stadiumTableInfo_clicked();


    void on_GrassSurface_currentIndexChanged();



    void on_planTripButton_clicked();


    void on_pushButton_31_clicked();

    void on_allStadiumsButton_clicked();

    void on_pushButton_38_clicked();

    void on_pushButton_39_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_modAddNewButton_clicked();

    void on_modSDoneButton_clicked();

    void on_modSAddNewButton_clicked();

    void on_modDoneButton_clicked();

    void on_gobacktomainpage_clicked();


    void on_stadiumTable_clicked();

    void planTeamButtons(string stadiumName);

    void on_stadiumInfoCheckBox_stateChanged(int arg1); //IN - *placehold*

    void on_sanDiegoButton_clicked();

    void on_dodgerButton_clicked();

    void on_kansasCityButton_clicked();

    void on_stLouisButton_clicked();

    void on_nyMetsButton_clicked();

    void on_sanFranciscoButton_clicked();

    void on_oaklandAButton_clicked();

    void on_seattleButton_clicked();

    void on_coloradoButton_clicked();

    void on_angelsButton_clicked();

    void on_arizonaButton_clicked();

    void on_minnesotaButton_clicked();

    void on_texasRangersButton_clicked();

    void on_houstonButton_clicked();

    void on_milwaukeeButton_clicked();

    void on_chicagoButton_clicked();

    void on_chicagoWhiteSoxButton_clicked();

    void on_cincinattiButton_clicked();

    void on_atlantaButton_clicked();

    void on_clevelandButton_clicked();

    void on_tampaBayButton_clicked();

    void on_floridaButton_clicked();

    void on_pittsburghButton_clicked();

    void on_washingtonButton_clicked();

    void on_torontoButton_clicked();

    void on_detroitButton_2_clicked();

    void on_bostonButton_clicked();

    void on_baltimoreButton_clicked();

    void on_phillyButton_clicked();

    void on_nyYankeesButton_clicked();


    void on_restartDreamList_clicked();

    void on_allNLStadiumsButton_clicked();


    void on_allALStadiumsButton_clicked();


    void on_backtoMain_clicked();


    void on_showMapButton_clicked();


    void plannedTripTable();

    List<stadium> modify_newStadiumAddedByUser(List<stadium> list);

    bool isNewStadium(stadium);

    void on_pushButton_5_clicked();

    void on_CancelButtonTrackSouvenir_clicked();

    void on_AddbuttonTrackSouvenir_clicked();

    void on_showMapButtonMainPage_clicked();

    void on_DoneButton2_clicked();

private:
    Ui::MainWindow *ui;     // ATT - main ui window


    QString getDreamStrArray();
    QString stadiumPathText = "";   // ATT - text to display path
    QString arrow = " --> \n";      // ATT - arrow for output
    string strArrow = " --> \n";    // ATT - arrow for output

    vector<string> dreamList;       // ATT - list of stadiums in trip

    void clearDreamList();
    bool alreadyInDreamList(string stadiumName);    //IN - stadium name to chck

    void deleteDreamStadium(string stadiumName);    //IN - stadium to del

    graph g;

    souvenirs s;


    userInfo client;

    List<stadium> newStadiumaAddedbyUser;
    List<stadium> getStadiumListALL();





};
#endif // MAINWINDOW_H
