#ifndef MUSICDIALOG_H
#define MUSICDIALOG_H

#include "ui_musicDialog.h"

#include <QDialog>
#include <string>


class MusicDialog : public QDialog, public Ui::Dialog{
    Q_OBJECT

public:
    MusicDialog(QWidget *parent = nullptr);

private slots:
    void on_lineEdit_textChanged();
    void on_playButton_clicked();
    void on_pauseButton_clicked();
    void on_closeButton_clicked();

private:
    bool isPause;
    QString name;
    std::wstring wname;
};

#endif // MUSICDIALOG_H
