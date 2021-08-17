/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_Play;
    QPushButton *pushButton_Right;
    QPushButton *pushButton_Left;
    QPushButton *pushButton_heart;
    QSlider *horizontalSlider_Music;
    QLabel *label_Start;
    QLabel *label_End;
    QPushButton *pushButton_End;
    QPushButton *pushButton_PlayMode;
    QPushButton *pushButton_Sound;
    QSlider *horizontalSlider_Sound;
    QLabel *label_Name;
    QPushButton *pushButton_Word;
    QLabel *label_Word;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(608, 482);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton_Play = new QPushButton(centralwidget);
        pushButton_Play->setObjectName(QString::fromUtf8("pushButton_Play"));
        pushButton_Play->setGeometry(QRect(140, 140, 30, 30));
        pushButton_Play->setMinimumSize(QSize(30, 30));
        pushButton_Play->setMaximumSize(QSize(30, 30));
        pushButton_Play->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-image: url(:/image/play.png);\n"
"	border:none;\n"
"	color:rgb(255, 255, 255);\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"border-image: url(:/image/play_hover.png);\n"
";border:none;\n"
"color:rgb(255, 255, 255);\n"
"}\n"
"QPushButton:pressed{\n"
"border-image: url(:/image/play_pressed.png);\n"
"border:none;\n"
"color:rgb(255, 255, 255);\n"
"}\n"
""));
        pushButton_Right = new QPushButton(centralwidget);
        pushButton_Right->setObjectName(QString::fromUtf8("pushButton_Right"));
        pushButton_Right->setGeometry(QRect(170, 140, 30, 30));
        pushButton_Right->setMinimumSize(QSize(30, 30));
        pushButton_Right->setMaximumSize(QSize(30, 30));
        pushButton_Right->setSizeIncrement(QSize(0, 0));
        pushButton_Right->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-image: url(:/image/left.png);\n"
"border:none;\n"
"color:rgb(255, 255, 255);\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"border-image: url(:/image/left_hover.png);\n"
";border:none;\n"
"color:rgb(255, 255, 255);\n"
"}\n"
"QPushButton:pressed{\n"
"border-image: url(:/image/left_pressed.png);\n"
"border:none;\n"
"color:rgb(255, 255, 255);\n"
"}\n"
""));
        pushButton_Left = new QPushButton(centralwidget);
        pushButton_Left->setObjectName(QString::fromUtf8("pushButton_Left"));
        pushButton_Left->setGeometry(QRect(110, 140, 30, 30));
        pushButton_Left->setMinimumSize(QSize(30, 30));
        pushButton_Left->setMaximumSize(QSize(30, 30));
        pushButton_Left->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-image: url(:/image/right.png);\n"
"border:none;\n"
"color:rgb(255, 255, 255);\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"border-image: url(:/image/right_hover.png);\n"
";border:none;\n"
"color:rgb(255, 255, 255);\n"
"}\n"
"QPushButton:pressed{\n"
"border-image: url(:/image/right_pressed.png);\n"
"border:none;\n"
"color:rgb(255, 255, 255);\n"
"}\n"
""));
        pushButton_heart = new QPushButton(centralwidget);
        pushButton_heart->setObjectName(QString::fromUtf8("pushButton_heart"));
        pushButton_heart->setGeometry(QRect(80, 141, 30, 30));
        pushButton_heart->setMinimumSize(QSize(30, 30));
        pushButton_heart->setMaximumSize(QSize(30, 30));
        pushButton_heart->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-image: url(:/image/heart.png);\n"
"border:none;\n"
"color:rgb(255, 255, 255);\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"border-image: url(:/image/heart_hover.png);\n"
";border:none;\n"
"color:rgb(255, 255, 255);\n"
"}\n"
"QPushButton:pressed{\n"
"border-image: url(:/image/heart_pressed.png);\n"
"border:none;\n"
"color:rgb(255, 255, 255);\n"
"}\n"
""));
        horizontalSlider_Music = new QSlider(centralwidget);
        horizontalSlider_Music->setObjectName(QString::fromUtf8("horizontalSlider_Music"));
        horizontalSlider_Music->setGeometry(QRect(279, 140, 201, 29));
        horizontalSlider_Music->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"\n"
" \n"
"border-image: url(:/image/zbutton.png);\n"
"border: -10px solid #bbb;\n"
"\n"
" \n"
"}\n"
" \n"
"QSlider::sub-page:horizontal {\n"
" \n"
"background: rgb(255,255,255);\n"
"\n"
"margin-left:5px;\n"
"\n"
"margin-right:5px;\n"
"\n"
"margin-top:12px;\n"
" \n"
"margin-bottom:13px;\n"
" \n"
"}\n"
" \n"
"QSlider::add-page:horizontal {\n"
" \n"
"background: rgb(0,0, 0);\n"
" \n"
"border: 0px solid #777;\n"
"\n"
"margin-left:5px;\n"
"\n"
"margin-right:5px;\n"
" \n"
"border-radius: 2px;\n"
"\n"
"margin-top:12px;\n"
" \n"
"margin-bottom:13px;\n"
" \n"
"}\n"
" \n"
"QSlider::handle:horizontal {\n"
"border-image: url(:/image/music.png);\n"
"width:15px;\n"
"\n"
"margin-left:10px;\n"
"margin-right:10px;\n"
"\n"
"margin-top:10px;\n"
" \n"
"margin-bottom:10px;\n"
" \n"
"}\n"
" \n"
"QSlider::handle:horizontal:hover {\n"
" \n"
"border-image: url(:/image/music_hover.png);\n"
"width:15px;\n"
"\n"
"\n"
"margin-left:10px;\n"
"margin-right:10px;\n"
"\n"
" \n"
"margin-top:10px;\n"
" \n"
"marg"
                        "in-bottom:10px;\n"
"}\n"
" \n"
"QSlider::sub-page:horizontal:disabled {\n"
" \n"
"background: #bbb;\n"
" \n"
"border-color: #999;\n"
" \n"
"}\n"
" \n"
"QSlider::add-page:horizontal:disabled {\n"
" \n"
"background: #eee;\n"
" \n"
"border-color: #999;\n"
" \n"
"}\n"
" \n"
"QSlider::handle:horizontal:disabled {\n"
" \n"
"background: #eee;\n"
" \n"
"border: 1px solid #aaa;\n"
" \n"
"border-radius: 7px;\n"
" \n"
"}\n"
" "));
        horizontalSlider_Music->setValue(0);
        horizontalSlider_Music->setOrientation(Qt::Horizontal);
        label_Start = new QLabel(centralwidget);
        label_Start->setObjectName(QString::fromUtf8("label_Start"));
        label_Start->setGeometry(QRect(239, 140, 40, 29));
        label_Start->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QLabel{\n"
"font: 25 8pt ;\n"
"border-image: url(:/image/zbutton.png);\n"
"border:none;\n"
"color:rgb(0, 0,0);\n"
"}\n"
"\n"
"QLabel:hover{\n"
"font: 25 8pt ;\n"
"border:none;\n"
"color:rgb(255, 255, 255);\n"
"}\n"
"\n"
""));
        label_Start->setAlignment(Qt::AlignCenter);
        label_End = new QLabel(centralwidget);
        label_End->setObjectName(QString::fromUtf8("label_End"));
        label_End->setGeometry(QRect(480, 140, 40, 29));
        label_End->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QLabel{\n"
"font: 25 8pt ;\n"
"border-image: url(:/image/zbutton.png);\n"
"border:none;\n"
"color:rgb(0, 0,0);\n"
"}\n"
"\n"
"QLabel:hover{\n"
"font: 25 8pt ;\n"
"\n"
";border:none;\n"
"color:rgb(255, 255, 255);\n"
"}\n"
""));
        label_End->setAlignment(Qt::AlignCenter);
        pushButton_End = new QPushButton(centralwidget);
        pushButton_End->setObjectName(QString::fromUtf8("pushButton_End"));
        pushButton_End->setGeometry(QRect(140, 140, 30, 30));
        pushButton_End->setMinimumSize(QSize(30, 30));
        pushButton_End->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-image: url(:/image/end.png);\n"
"	border:none;\n"
"	color:rgb(255, 255, 255);\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"border-image: url(:/image/end_hover.png);\n"
";border:none;\n"
"color:rgb(255, 255, 255);\n"
"}\n"
"QPushButton:pressed{\n"
"border-image: url(:/image/end_pressed.png);\n"
"border:none;\n"
"color:rgb(255, 255, 255);\n"
"}\n"
""));
        pushButton_PlayMode = new QPushButton(centralwidget);
        pushButton_PlayMode->setObjectName(QString::fromUtf8("pushButton_PlayMode"));
        pushButton_PlayMode->setGeometry(QRect(200, 140, 30, 30));
        pushButton_PlayMode->setMinimumSize(QSize(30, 30));
        pushButton_PlayMode->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-image: url(:/image/loop.png);\n"
"border:none;\n"
"color:rgb(255, 255, 255);\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"border-image: url(:/image/loop_hover.png);\n"
"border:none;\n"
"color:rgb(255, 255, 255);\n"
"}\n"
"QPushButton:pressed{\n"
"border-image: url(:/image/loop_pressed.png);\n"
"border:none;\n"
"color:rgb(255, 255, 255);\n"
"}\n"
""));
        pushButton_Sound = new QPushButton(centralwidget);
        pushButton_Sound->setObjectName(QString::fromUtf8("pushButton_Sound"));
        pushButton_Sound->setGeometry(QRect(380, 100, 30, 30));
        pushButton_Sound->setMinimumSize(QSize(30, 30));
        pushButton_Sound->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-image: url(:/image/mute.png);\n"
"border:none;\n"
"color:rgb(255, 255, 255);\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"border-image: url(:/image/mute_hover.png);\n"
"border:none;\n"
"color:rgb(255, 255, 255);\n"
"}\n"
"QPushButton:pressed{\n"
"border-image: url(:/image/mute_pressed.png);\n"
"border:none;\n"
"color:rgb(255, 255, 255);\n"
"}\n"
""));
        horizontalSlider_Sound = new QSlider(centralwidget);
        horizontalSlider_Sound->setObjectName(QString::fromUtf8("horizontalSlider_Sound"));
        horizontalSlider_Sound->setGeometry(QRect(410, 100, 111, 29));
        horizontalSlider_Sound->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"\n"
" \n"
"border-image: url(:/image/zbutton.png);\n"
"border: -10px solid #bbb;\n"
"\n"
" \n"
"}\n"
" \n"
"QSlider::sub-page:horizontal {\n"
" \n"
"background: rgb(255,255,255);\n"
"\n"
"margin-left:5px;\n"
"\n"
"margin-right:5px;\n"
"\n"
"margin-top:12px;\n"
" \n"
"margin-bottom:13px;\n"
" \n"
"}\n"
" \n"
"QSlider::add-page:horizontal {\n"
" \n"
"background: rgb(0,0, 0);\n"
" \n"
"border: 0px solid #777;\n"
"\n"
"margin-left:5px;\n"
"\n"
"margin-right:5px;\n"
" \n"
"border-radius: 2px;\n"
"\n"
"margin-top:12px;\n"
" \n"
"margin-bottom:13px;\n"
" \n"
"}\n"
" \n"
"QSlider::handle:horizontal {\n"
"border-image: url(:/image/music.png);\n"
"width:15px;\n"
"\n"
"margin-left:10px;\n"
"margin-right:10px;\n"
"\n"
"margin-top:10px;\n"
" \n"
"margin-bottom:10px;\n"
" \n"
"}\n"
" \n"
"QSlider::handle:horizontal:hover {\n"
" \n"
"border-image: url(:/image/music_hover.png);\n"
"width:15px;\n"
"\n"
"\n"
"margin-left:10px;\n"
"margin-right:10px;\n"
"\n"
" \n"
"margin-top:10px;\n"
" \n"
"marg"
                        "in-bottom:10px;\n"
"}\n"
" \n"
"QSlider::sub-page:horizontal:disabled {\n"
" \n"
"background: #bbb;\n"
" \n"
"border-color: #999;\n"
" \n"
"}\n"
" \n"
"QSlider::add-page:horizontal:disabled {\n"
" \n"
"background: #eee;\n"
" \n"
"border-color: #999;\n"
" \n"
"}\n"
" \n"
"QSlider::handle:horizontal:disabled {\n"
" \n"
"background: #eee;\n"
" \n"
"border: 1px solid #aaa;\n"
" \n"
"border-radius: 7px;\n"
" \n"
"}\n"
" "));
        horizontalSlider_Sound->setValue(0);
        horizontalSlider_Sound->setOrientation(Qt::Horizontal);
        label_Name = new QLabel(centralwidget);
        label_Name->setObjectName(QString::fromUtf8("label_Name"));
        label_Name->setGeometry(QRect(120, 95, 251, 31));
        label_Name->setStyleSheet(QString::fromUtf8("\n"
"QLabel{background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0.744318 rgba(0, 0, 0,0),stop:1 rgba(238, 241, 241, 255));font: 15pt \"\346\245\267\344\275\223\";border-radius:5px;color:rgb(0, 0,0);}\n"
"\n"
"QLabel:hover{font: 15pt \"\346\245\267\344\275\223\";border-radius:5px;color:rgb(255, 255, 255);}\n"
"\n"
""));
        label_Name->setTextFormat(Qt::AutoText);
        label_Name->setScaledContents(false);
        label_Name->setAlignment(Qt::AlignCenter);
        pushButton_Word = new QPushButton(centralwidget);
        pushButton_Word->setObjectName(QString::fromUtf8("pushButton_Word"));
        pushButton_Word->setGeometry(QRect(85, 100, 30, 30));
        pushButton_Word->setMinimumSize(QSize(30, 30));
        pushButton_Word->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-image: url(:/image/word.png);\n"
"border:none;\n"
"color:rgb(255, 255, 255);\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"border-image: url(:/image/word_hover.png);\n"
"border:none;\n"
"color:rgb(255, 255, 255);\n"
"}\n"
"QPushButton:pressed{\n"
"border-image: url(:/image/word_pressed.png);\n"
"border:none;\n"
"color:rgb(255, 255, 255);\n"
"}\n"
""));
        label_Word = new QLabel(centralwidget);
        label_Word->setObjectName(QString::fromUtf8("label_Word"));
        label_Word->setGeometry(QRect(10, 0, 591, 91));
        label_Word->setStyleSheet(QString::fromUtf8("font: 18pt \":/fonts/font/\347\246\271\345\215\253\344\271\246\346\263\225\350\241\214\344\271\246\347\256\200\344\275\223.ttf\";"));
        label_Word->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_Play->setText(QString());
        pushButton_Right->setText(QString());
        pushButton_Left->setText(QString());
        pushButton_heart->setText(QString());
        label_Start->setText(QCoreApplication::translate("MainWindow", "88:88", nullptr));
        label_End->setText(QCoreApplication::translate("MainWindow", "88:88", nullptr));
        pushButton_End->setText(QString());
        pushButton_PlayMode->setText(QString());
        pushButton_Sound->setText(QString());
        label_Name->setText(QCoreApplication::translate("MainWindow", "\350\277\231\351\207\214\347\224\250\346\235\245\345\276\252\347\216\257\346\230\276\347\244\272\346\255\214\345\220\215", nullptr));
        pushButton_Word->setText(QString());
        label_Word->setText(QCoreApplication::translate("MainWindow", "\347\250\213\345\272\217\345\221\230\345\276\210\346\207\222\357\274\214\350\277\230\346\262\241\346\234\211\345\206\231\350\277\231\351\203\250\345\210\206\347\232\204\345\212\237\350\203\275\357\274\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
