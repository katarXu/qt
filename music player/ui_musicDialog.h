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
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *playButton;
    QPushButton *pauseButton;
    QPushButton *closeButton;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(260, 76);
        widget = new QWidget(Dialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 241, 56));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        playButton = new QPushButton(widget);
        playButton->setObjectName(QString::fromUtf8("playButton"));
        playButton->setEnabled(false);

        horizontalLayout_2->addWidget(playButton);

        pauseButton = new QPushButton(widget);
        pauseButton->setObjectName(QString::fromUtf8("pauseButton"));

        horizontalLayout_2->addWidget(pauseButton);

        closeButton = new QPushButton(widget);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));

        horizontalLayout_2->addWidget(closeButton);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(Dialog);

        playButton->setDefault(true);


        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Music Player", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "Music:", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog", ".mp3", nullptr));
        playButton->setText(QCoreApplication::translate("Dialog", "Play", nullptr));
        pauseButton->setText(QCoreApplication::translate("Dialog", "Pause", nullptr));
        closeButton->setText(QCoreApplication::translate("Dialog", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MUSICDIALOG_H
