#ifndef MUSICDIALOG_H
#define MUSICDIALOG_H

#include "ui_musicDialog.h"

#include <QDialog>

class MusicDialog : public QDialog, public Ui::MusicDialog{
    Q_OBJECT

public:
    MusicDialog(QWidget *parent = nullptr);
    ~MusicDialog();

private slots:
    void on_lineEdit_textChanged();
    void on_playButton_clicked();
    void on_pauseButton_clicked();
    void on_closeButton_clicked();
    void on_freshButton_clicked();
    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

private:
    struct Impl;
    Impl *pImpl;

    bool playMusic();
    void setLineEdit();
    void setMusicList();
};

#endif // MUSICDIALOG_H
