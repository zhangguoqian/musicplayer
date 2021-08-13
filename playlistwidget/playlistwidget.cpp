#include "playlistwidget.h"

PlayListWidget::PlayListWidget(QWidget *parent) : QListWidget(parent)
{
    this->setWindowFlags(Qt::FramelessWindowHint);//设置窗体无边框
    setStyleSheet("QListWidget{background-image: url(:/image/list.png);font: 15pt \"\346\245\267\344\275\223\";}");
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_PathList = m_Set.getPathMedia();
    m_PathList = listIsRepeat(m_PathList);
    initWidget();
}

PlayListWidget::~PlayListWidget()
{
    m_PathList = listIsRepeat(m_PathList);
    m_Set.setPathMedia(m_PathList);
}

void PlayListWidget::initWidget()
{
    QDir dir;
    QStringList nameFilters;
    for(QString path:m_PathList)
    {
        qDebug()<<"音乐路径"<<path;
        dir.setPath(path);
        nameFilters<<"*.mp3"<<"*.wav";

        m_PlayFileList = dir.entryList(nameFilters, QDir::Files|QDir::Readable, QDir::Name);
        if(m_PlayFileList.isEmpty())
        {
            qDebug()<<path<<"isEmpty.";
            m_PathList.removeOne(path);
            continue;
        }
        for (auto name:m_PlayFileList)
        {
            m_filePaths << dir.path()+"/"+name;
            m_file << name.left(name.length()-4);
            m_mediaList << QMediaContent(QUrl(QUrl::fromLocalFile(dir.path()+"/"+name)));
            QListWidgetItem *add_item = new QListWidgetItem(name,this);
            add_item->setSizeHint(QSize(25,25));
            addItem(add_item);
        }
    }
}

QStringList PlayListWidget::listIsRepeat(QStringList list)
{
//    QSet<QString> set=QSet<QString>(list.begin(),list.end());

    return list.toSet().toList();
}

void PlayListWidget::slotRecIncreas(QString str)
{
    m_PathList << str;
    qDebug()<<"添加："<<m_PathList;
    m_PathList = listIsRepeat(m_PathList);
    qDebug()<<m_PathList;
    slotUpdateList(1);
}

void PlayListWidget::slotUpdateList(bool isOk)
{
    if(!isOk)
    {
        m_PathList=m_Set.getPathMedia();
    }
    qDebug()<<"ini读取为:"<<m_PathList;
    QDir dir;
    QStringList nameFilters;
    clear();
    m_file.clear();
    m_mediaList.clear();
    for(QString path:m_PathList)
    {
        dir.setPath(path);
        nameFilters<<"*.mp3"<<"*.wav";
        m_PlayFileList = dir.entryList(nameFilters, QDir::Files|QDir::Readable, QDir::Name);
        if(m_PlayFileList.isEmpty())
        {
            m_PathList.removeOne(path);
            continue;
        }
        for (auto name:m_PlayFileList)
        {
            m_filePaths << dir.path()+"/"+name;
            m_file << name.left(name.length()-4);
            m_mediaList << QMediaContent(QUrl(QUrl::fromLocalFile(dir.path()+"/"+name)));
            QListWidgetItem *add_item = new QListWidgetItem(name,this);
            add_item->setSizeHint(QSize(200,25));
            addItem(add_item);
        }
    }
    m_Set.setPathMedia(m_PathList);
    qDebug()<<"ini设置为:"<<m_PathList;
    emit signalUpdatePlayerList();
}




