#include <QtGui>
#include <QCompleter>
#include "xFunc.h"
#include "musicDialog.h"

struct MusicDialog::Impl{
    bool isPlay = false;
    bool isPause = false;
    bool hasPoint = false;
    QString path = ".";
    QString curName;
    QString curMusic;
    QVector<QString> musicArray;
};

MusicDialog::MusicDialog(QWidget *parent)
    :QDialog(parent), pImpl(new Impl){
    setupUi(this);

    this->setWindowTitle("Music Player");
    setMusicList();
    setLineEdit();
}

void MusicDialog::setLineEdit(){
    lineEdit->setPlaceholderText("music name");
    QCompleter *completer = new QCompleter(pImpl->musicArray);
    lineEdit->setCompleter(completer);
}

void MusicDialog::setMusicList(){
    listWidget->clear();
    getFileList(pImpl->musicArray, pImpl->path);

    for(QString &str : pImpl->musicArray){
        listWidget->addItem(str);
    }
}

void MusicDialog::on_lineEdit_textChanged(){
    playButton->setEnabled(!lineEdit->text().isEmpty());
    playButton->setDefault(true);

    pImpl->hasPoint = lineEdit->text().indexOf(".") != -1;
    typeBox->setEnabled(!pImpl->hasPoint);
}


void MusicDialog::on_playButton_clicked(){
    pImpl->curName = lineEdit->text() + (pImpl->hasPoint ? "" : typeBox->currentText());
    if(playMusic()){
        playButton->setDefault(false);
    }
}

void MusicDialog::on_pauseButton_clicked(){
    if(pImpl->isPlay){
        pImpl->isPause = !pImpl->isPause;

        quickMSS(pImpl->curMusic, pImpl->isPause ? MODE::PAUSE : MODE::RESUME);
        this->setWindowTitle(pImpl->curMusic + (pImpl->isPause ? " is pause" : " is playing"));
        pauseButton->setText(pImpl->isPause ? "Resume" : "Pause");
    }
}

void MusicDialog::on_closeButton_clicked(){
    if(pImpl->isPlay){
        quickMSS(pImpl->curMusic, MODE::STOP);
        quickMSS(pImpl->curMusic, MODE::CLOSE);
        this->setWindowTitle("Music Player");
        pImpl->isPlay = false;
        pImpl->curMusic = "";
    }
}

void MusicDialog::on_freshButton_clicked(){
    setMusicList();
}


void MusicDialog::on_listWidget_itemDoubleClicked(QListWidgetItem *item){
    pImpl->curName = item->text();
    if(!playMusic()){
        listWidget->removeItemWidget(item);
        delete item;
    }
}

bool MusicDialog::playMusic(){
    if(pImpl->isPlay){
        on_closeButton_clicked();
        pImpl->isPlay = false;
    }
    if(0 != quickMSS(pImpl->curName, MODE::OPEN)){
        this->setWindowTitle(pImpl->curName + " can't play");
        return false;
    }
    pImpl->curMusic = pImpl->curName;
    quickMSS(pImpl->curMusic, MODE::PLAY);
    pImpl->isPlay = true;
    this->setWindowTitle(pImpl->curMusic + " is playing");
    return true;
}

MusicDialog::~MusicDialog(){
    delete pImpl;
}
