#ifndef PLAYLISTWIDGET_H
#define PLAYLISTWIDGET_H

#include <QListWidget>
#include <QMediaPlaylist>
#include <QDir>
#include <QDebug>
#include <QTimer>
#include <QWidget>
#include <QFileDialog>
#include "setting/setting.h"



class PlayListWidget : public QListWidget
{
    Q_OBJECT
public:
    explicit PlayListWidget(QWidget *parent = nullptr);
    ~PlayListWidget();
    QStringList m_PathList;
    QStringList m_filePaths;
    QStringList m_file;
    QList<QMediaContent> m_mediaList;
private:
    QStringList m_PlayFileList;
    Setting m_Set;
    QStringList listIsRepeat(QStringList list);
    void initWidget();
private slots:
    void slotRecIncreas(QString str);
    void slotUpdateList(bool isOk);
signals:
    void signalUpdatePlayerList();

};

#endif // PLAYLISTWIDGET_H
