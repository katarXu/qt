#include <QtGui>
#include <Windows.h>
#include <mmsystem.h>
#include <string>
//#pragma comment(lib,"winmm.lib")
#include "musicDialog.h"

MusicDialog::MusicDialog(QWidget *parent)
    :QDialog(parent), isPause(false){
    setupUi(this);
}

void MusicDialog::on_lineEdit_textChanged(){
    playButton->setEnabled(!lineEdit->text().isEmpty());
}

void MusicDialog::on_playButton_clicked(){
    name = lineEdit->text() + ".mp3";
    wname = name.toStdWString();
    std::wstring openCmd = L"open " + wname;
    std::wstring playCmd = L"play " + wname;
    mciSendString(openCmd.c_str(), NULL, 0, NULL);
    mciSendString(playCmd.c_str(), NULL, 0, NULL);
    this->setWindowTitle(name + " is playing");
}

void MusicDialog::on_pauseButton_clicked(){
    if(isPause){
        std::wstring pauseCmd = L"pause " + wname;
        mciSendString(pauseCmd.c_str(), NULL, 0, NULL);
        this->setWindowTitle(name + " is pause");
        pauseButton->setText("Resume");
    }
    else{
        std::wstring resumeCmd = L"resume " + wname;
        mciSendString(resumeCmd.c_str(), NULL, 0, NULL);
        this->setWindowTitle(name + " is playing");
        pauseButton->setText("Pause");
    }
    isPause = !isPause;
}

void MusicDialog::on_closeButton_clicked(){
    std::wstring stopCmd = L"stop " + wname;
    std::wstring closeCmd = L"close " + wname;
    mciSendString(stopCmd.c_str(), NULL, 0, NULL);
    mciSendString(closeCmd.c_str(), NULL, 0, NULL);
    this->setWindowTitle("Music Player");
}
