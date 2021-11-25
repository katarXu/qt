#ifndef XFUNC_H
#define XFUNC_H

#include <dirent.h>
#include <direct.h>
#include <Windows.h>
#include <mmsystem.h>
#include <QString>
#include <QVector>
#include <QByteArray>
#include <string>
#include <QMessageBox>
#include <QStringList>
#include <algorithm>

//#pragma comment(lib,"winmm.lib")


inline void myErr(const QString &err){
    QMessageBox::question(
                nullptr,
                "warning",
                err,
                QMessageBox::Ok);
}
inline bool isMusicType(const QString &suffix){
    return suffix == "mp3" || suffix == "wav";
}


bool getFileList(QVector<QString> &arr, const QString &path){
    const char* cPath = path.toUtf8().constData();

    DIR *dir = opendir(cPath);
    if(nullptr == dir){
        myErr("failed to open" + path);
        return false;
    }
    dirent *pdir = nullptr;
    pdir = readdir(dir);
    while(nullptr != (pdir = readdir(dir))){
        QString curName = QString::fromLocal8Bit(pdir->d_name);
        int postion = curName.lastIndexOf(".");
        if(postion == -1 || postion + 1 == curName.size()){
            continue;
        }
        QString curType = curName.mid(postion + 1);
        if(isMusicType(curType)){
            auto it = std::lower_bound(arr.begin(), arr.end(), curName);
            if(it == arr.end() || *it != curName){
                arr.insert(it, curName);
            }
        }
    }

    return true;
}



int myMciSendString(const QString &cmd){
    return mciSendString(reinterpret_cast<const wchar_t*>(cmd.utf16()), NULL, 0, NULL);
}


enum class MODE{ OPEN, PLAY, PAUSE, RESUME, STOP, CLOSE };

int quickMSS(const QString &music, MODE mode){
    QString cmd;
    switch(mode){
    case MODE::OPEN: cmd = "open \"" + music + "\" alias music"; break;
    case MODE::PLAY: cmd = "play music"; break;
    case MODE::PAUSE: cmd = "pause music"; break;
    case MODE::RESUME: cmd = "resume music"; break;
    case MODE::STOP: cmd = "stop music"; break;
    case MODE::CLOSE: cmd = "close music"; break;
    default: myErr(""); return -1;
    }
    return myMciSendString(cmd);
}
#endif // XFUNC_H
