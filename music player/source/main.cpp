#include <QtWidgets>

#include "musicDialog.h"

int main(int argc, char *argv[]){
    QApplication app(argc, argv);
    MusicDialog *dialog = new MusicDialog;
    dialog->show();
    return app.exec();
}
