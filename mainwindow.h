//name:zheaven QQ:1151828901
//version:1.0
//datetime:2020-03-20

//1.modifybugTime:2020-03-20,<完成>鼠标穿透会在第一次使用时出现移动问题的bug
//2.modifybugTime:2020-03-20,<完成>鼠标穿透对listwidget无效的bug
//3.modifybugTime:2020-03-20,<完成>播放与进度条的间隔差改为大于1000的bug
//4.modifybugTime:2020-03-23,<完成>修复更新列表后串行的bug
//5.modifybugTime:2020-03-25,<完成>添加单例启动功能
//version:1.1

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QMainWindow>
#include <QDebug>
#include <QSystemTrayIcon>
#include <QPushButton>
#include <QCloseEvent>
#include <QMediaPlaylist>
#include <QMediaPlayer>
#include <QLabel>
#include <QScreen>
#include <QPixmap>
#include <QApplication>
#include <QDesktopWidget>
#include <QDateTime>
#include <QVideoWidget>
#include <QBoxLayout>
#include "setting/setting.h"
#include "traymenu/traymenu.h"
#include "playlistwidget/playlistwidget.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void mouseReleaseEvent(QMouseEvent *);
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    bool isDrag;
    QPoint m_position;

signals:
    void signalSendIncreas(QString str);

private slots:
    void on_pushButton_Play_clicked();
    void on_pushButton_Right_clicked();
    void on_pushButton_Left_clicked();
    void setIsShowMainWindow(bool isOk);
    void setIsTransparentMouse(bool isOk);
    void on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason reason);
    void on_pushButton_End_clicked();
    void on_pushButton_PlayMode_clicked();
    void on_pushButton_Sound_clicked();
    void on_pushButton_Word_clicked();
    void on_pushButton_heart_clicked();
    void slotItemClicked(const QModelIndex &index);
    void slotItemDoubleClicked(const QModelIndex &);
    void on_horizontalSlider_Sound_valueChanged(int value);
    void slotMediaPosition(qint64 value);
    void on_horizontalSlider_Music_valueChanged(int value);
    void slotSetMediaState(QMediaPlayer::State state);
    void slotCurrentMedia(int position);
    void slotLabelWordSetText();
    void slotMediaError(QMediaPlayer::Error error);
    void setIncrease(QString str);
    void slotLabelName();

    void slotUpdatePlayerList();
private:
    Ui::MainWindow *ui;
    QTimer *mp_Timer;
    QTimer *mp_Timer_Name;
    QSystemTrayIcon *mp_TrayIcon;
    TrayMenu *mp_Traymenu;
    PlayListWidget *mp_PlayListWidget;
    void  initPlayListWidget();
    QMediaPlaylist *m_MediaPlayList;
    void initMediaPlaylist();
    QMediaPlayer *m_MediaPlayer;
    void initMediaPlayer();
    bool m_isTransparentForMouse;
    void setTransparentForMouse(bool isOk);
    void initMainWindow(const QString &title); //初始化主界面
    void ininTrayMenu();                       //初始化托盘菜单
    void initTrayIcon(const QString &iconname); //初始化托盘图标
    bool m_IsPlay;
    void initPlayEnd(bool isOk);
    bool m_IsMute;
    void setMute(const bool isMute);
    int m_PlayMode;
    void setPlayMode(const int mode);
    bool m_IsWord;
    void setWordShow(const bool isWord);
    bool getLabelFontColor(const QLabel *label);
    void setLabelColor();
    QString formatTime(qint64 timeMilliSeconds);
    Setting m_Set;
    QString m_scrollCaptionStr;

    QVideoWidget *m_VideoWidget;
    QGridLayout* layoput;
    void initVideoWidget();


};
#endif // MAINWINDOW_H
