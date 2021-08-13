#ifndef TRAYMENU_H
#define TRAYMENU_H

#include <QWidget>
#include <QDebug>
#include <QMenu>
#include <QFileDialog>
#include "setting/setting.h"


class TrayMenu : public QMenu
{
    Q_OBJECT
public:
    explicit TrayMenu(QWidget *parent = nullptr);

signals:
    void signalIsShowMainWindow(bool isOk);
    void signalIsTransparentMouse(bool isOk);
    void signalIsQuit();
    void signalIsIncrease(QString str);
    void signalUpdate(bool isOk);

public slots:
    void actionClickShow(bool isOk);
    void actionClickTransparentMouse(bool isOk);
    void actionClickPlayList(bool isOk);
    void actionClickUpdate(bool isOk);
    void actionClickUpdateApp(bool isOk);
    void actionClickQuit();
private:
    QAction* mp_Show;
    QAction* mp_TransparentMouse;
    QAction* mp_Quit;
    QAction* mp_PlayList;
    QAction* mp_UpdateMusic;
    QAction* mp_UpdateApp;
    Setting m_Set;
    QString m_strIncrease;


};

#endif // TRAYMENU_H
