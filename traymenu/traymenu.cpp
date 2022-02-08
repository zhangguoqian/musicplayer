#include "traymenu.h"

TrayMenu::TrayMenu(QWidget *parent) : QMenu(parent)
{
    mp_Show = new QAction(QString::fromLocal8Bit("显示主界面"),this);
    mp_Show->setCheckable(true);
    mp_Show->setChecked(1);
    connect(mp_Show,SIGNAL(triggered(bool)),this,SLOT(actionClickShow(bool)));

    mp_TransparentMouse =new QAction(QString::fromLocal8Bit("鼠标穿透"),this);
    mp_TransparentMouse->setCheckable(1);
    connect(mp_TransparentMouse,SIGNAL(triggered(bool)),this,SLOT(actionClickTransparentMouse(bool)));

    mp_PlayList = new QAction(QString::fromLocal8Bit("添加音乐库"),this);
    connect(mp_PlayList,SIGNAL(triggered(bool)),this,SLOT(actionClickPlayList(bool)));

    mp_UpdateMusic = new QAction(QString::fromLocal8Bit("更新音乐库"),this);
    connect(mp_UpdateMusic ,SIGNAL(triggered(bool)),this,SLOT(actionClickUpdate(bool)));

    mp_UpdateApp = new QAction(QString::fromLocal8Bit("检查更新"),this);
    connect(mp_UpdateApp ,SIGNAL(triggered(bool)),this,SLOT(actionClickUpdateApp(bool)));

    mp_DownLoad = new QAction(QString::fromLocal8Bit("下载音乐"),this);
    //mp_UpLoad = new QAction(QString::fromLocal8Bit("上传音乐"),this);

    mp_Quit = new QAction(QString::fromLocal8Bit("退出"),this);
    connect(mp_Quit,SIGNAL(triggered()),this,SLOT(actionClickQuit()));

    addAction(mp_Show);
    addAction(mp_TransparentMouse);
    addAction(mp_PlayList);
    addAction(mp_UpdateMusic);
    addAction(mp_UpdateApp);
    addAction(mp_DownLoad);

    addAction(mp_Quit);

}

void TrayMenu::actionClickShow(bool isOk)
{
    qDebug()<<"actionClickShow():"<<isOk<<".";
    emit signalIsShowMainWindow(isOk);
    mp_Show->setChecked(isOk);
}

void TrayMenu::actionClickTransparentMouse(bool isOk)
{
    qDebug()<<"actionClickTransparentMouse():"<<isOk<<".";
    emit signalIsTransparentMouse(isOk);
    mp_TransparentMouse->setChecked(isOk);
}

void TrayMenu::actionClickPlayList(bool isOk)
{
    qDebug()<<"actionClickPlayList()"<<isOk<<".";
    m_strIncrease =QFileDialog::getExistingDirectory(this,QString::fromLocal8Bit("选择添加的音乐库music"),"E:/");
    qDebug()<<"添加目录为:"<<m_strIncrease;
    if(!m_strIncrease.isNull())
    {
        emit signalIsIncrease(m_strIncrease);
    }
}

void TrayMenu::actionClickUpdate(bool isOk)
{
    qDebug()<<"actionClickUpdate()"<<isOk<<".";
    emit signalUpdate(isOk);
}

void TrayMenu::actionClickUpdateApp(bool isOk)
{
    qDebug()<<"actionClickUpdateApp()"<<isOk<<".";
}

void TrayMenu::actionClickQuit()
{
    qDebug()<<"actionClickQuit().";
    emit signalIsQuit(); //实现完成
}



