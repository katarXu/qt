/********************************************************************************
** Form generated from reading UI file 'musicDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MUSICDIALOG_H
#define UI_MUSICDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MusicDialog
{
public:
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QComboBox *typeBox;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *playButton;
    QPushButton *pauseButton;
    QPushButton *closeButton;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *freshButton;

    void setupUi(QDialog *MusicDialog)
    {
        if (MusicDialog->objectName().isEmpty())
            MusicDialog->setObjectName(QString::fromUtf8("MusicDialog"));
        MusicDialog->resize(325, 324);
        gridLayout_2 = new QGridLayout(MusicDialog);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(MusicDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(MusicDialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        typeBox = new QComboBox(MusicDialog);
        typeBox->addItem(QString());
        typeBox->addItem(QString());
        typeBox->setObjectName(QString::fromUtf8("typeBox"));

        horizontalLayout->addWidget(typeBox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        playButton = new QPushButton(MusicDialog);
        playButton->setObjectName(QString::fromUtf8("playButton"));
        playButton->setEnabled(false);

        horizontalLayout_2->addWidget(playButton);

        pauseButton = new QPushButton(MusicDialog);
        pauseButton->setObjectName(QString::fromUtf8("pauseButton"));

        horizontalLayout_2->addWidget(pauseButton);

        closeButton = new QPushButton(MusicDialog);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));

        horizontalLayout_2->addWidget(closeButton);


        verticalLayout->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        listWidget = new QListWidget(MusicDialog);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        gridLayout->addWidget(listWidget, 1, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        freshButton = new QPushButton(MusicDialog);
        freshButton->setObjectName(QString::fromUtf8("freshButton"));

        horizontalLayout_3->addWidget(freshButton);


        verticalLayout_2->addLayout(horizontalLayout_3);


        gridLayout_2->addLayout(verticalLayout_2, 0, 0, 1, 1);


        retranslateUi(MusicDialog);

        playButton->setDefault(true);


        QMetaObject::connectSlotsByName(MusicDialog);
    } // setupUi

    void retranslateUi(QDialog *MusicDialog)
    {
        MusicDialog->setWindowTitle(QCoreApplication::translate("MusicDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("MusicDialog", "Music:", nullptr));
        typeBox->setItemText(0, QCoreApplication::translate("MusicDialog", ".mp3", nullptr));
        typeBox->setItemText(1, QCoreApplication::translate("MusicDialog", ".wav", nullptr));

        playButton->setText(QCoreApplication::translate("MusicDialog", "Play", nullptr));
        pauseButton->setText(QCoreApplication::translate("MusicDialog", "Pause", nullptr));
        closeButton->setText(QCoreApplication::translate("MusicDialog", "Close", nullptr));
        freshButton->setText(QCoreApplication::translate("MusicDialog", "f", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MusicDialog: public Ui_MusicDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MUSICDIALOG_H
