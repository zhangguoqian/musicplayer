#ifndef SETTING_H
#define SETTING_H

#include <QSettings>
#include <QPoint>

class Setting : public QObject
{
    Q_OBJECT
public:
    explicit Setting(QObject *parent = nullptr);
    ~Setting();

    QPoint getAppLocation();
    void setAppLocation(const QPoint &getAppLocation);

    bool getShowWord();
    void setShowWord(bool getShowWord);

    QStringList getPathMedia();
    void setPathMedia(const QStringList &getPathMedia);

    int getVolume();
    void setVolume(int getVolume);

    int getPlayMode();
    void setPlayMode(int getPlayMode);

    int getPlayIndex();
    void setPlayIndex(int PlayIndex);

    bool getTransparentMouse();
    void setTransparentMouse(bool TransparentMouse);

    bool getActionMain();
    void setActionMain(bool ActionMain);

private:
    QPoint m_AppLocation; //软件位置
    bool m_ShowWord;       //歌词展示
    int m_Volume;          //音量
    QStringList m_PathMediaList; // 初始路径
    int m_PlayMode;     //播放方式
    int m_PlayIndex;    //播放第几首歌
    bool m_ActionMain;  //右键"显示主界面"
    bool m_TransparentMouse;  //右键"鼠标穿透"

    QSettings *mp_Setting;
};

#endif // SETTING_H
