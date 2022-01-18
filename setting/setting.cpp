#include "setting.h"

Setting::Setting(QObject *parent) : QObject(parent)
{
    mp_Setting = new QSettings("./setting/setting.ini",QSettings::IniFormat);
}

Setting::~Setting()
{
    delete mp_Setting;
}

QPoint Setting::getAppLocation()
{
    int x =0;
    int y =0;
    mp_Setting->beginGroup("CONFIG");
    x = mp_Setting->value("LocationX").toInt();
    y = mp_Setting->value("LocationY").toInt();
    mp_Setting->endGroup();
    m_AppLocation = QPoint(x,y);
    return m_AppLocation;
}

void Setting::setAppLocation(const QPoint &AppLocation)
{
    mp_Setting->setValue("CONFIG/LocationX",AppLocation.x());
    mp_Setting->setValue("CONFIG/LocationY",AppLocation.y());
    m_AppLocation = AppLocation;
}

bool Setting::getShowWord()
{
    bool x =0;
    mp_Setting->beginGroup("CONFIG");
    x = mp_Setting->value("Word").toBool();
    mp_Setting->endGroup();
    m_ShowWord = x;
    return m_ShowWord;
}

void Setting::setShowWord(bool ShowWord)
{
    mp_Setting->setValue("CONFIG/Word",ShowWord);
    m_ShowWord = ShowWord;
}

QStringList Setting::getPathMedia()
{
    QStringList x;
    mp_Setting->beginGroup("CONFIG");
    x = mp_Setting->value("PathMediaList").toStringList();
    mp_Setting->endGroup();
    m_PathMediaList = x;
    return m_PathMediaList;
}

void Setting::setPathMedia(const QStringList &PathMedia)
{
    mp_Setting->setValue("CONFIG/PathMediaList",PathMedia);
    m_PathMediaList = PathMedia;
}

int Setting::getVolume()
{
    int x;
    mp_Setting->beginGroup("CONFIG");
    x = mp_Setting->value("Volume").toInt();
    mp_Setting->endGroup();
    m_Volume = x;
    return m_Volume;
}

void Setting::setVolume(int Volume)
{
    mp_Setting->setValue("CONFIG/Volume",Volume);
    m_Volume = Volume;
}

int Setting::getPlayMode()
{
    int x;
    mp_Setting->beginGroup("CONFIG");
    x = mp_Setting->value("PlayMode").toInt();
    mp_Setting->endGroup();
    m_PlayMode = x;
    return m_PlayMode;
}

void Setting::setPlayMode(int PlayMode)
{
    mp_Setting->setValue("CONFIG/PlayMode",PlayMode);
    m_PlayMode = PlayMode;
}

int Setting::getPlayIndex()
{
    int x;
    mp_Setting->beginGroup("CONFIG");
    x = mp_Setting->value("PlayIndex").toInt();
    mp_Setting->endGroup();
    m_PlayMode = x;
    return m_PlayMode;
}

void Setting::setPlayIndex(int PlayIndex)
{
    mp_Setting->setValue("CONFIG/PlayIndex",PlayIndex);
    m_PlayIndex = PlayIndex;
}

bool Setting::getTransparentMouse()
{
    bool x;
    mp_Setting->beginGroup("CONFIG");
    x = mp_Setting->value("TransparentMouse").toBool();
    mp_Setting->endGroup();
    m_TransparentMouse = x;
    return m_TransparentMouse;
}

void Setting::setTransparentMouse(bool TransparentMouse)
{
    mp_Setting->setValue("CONFIG/TransparentMouse",TransparentMouse);
    m_TransparentMouse = TransparentMouse;
}

bool Setting::getActionMain()
{
    bool x;
    mp_Setting->beginGroup("CONFIG");
    x = mp_Setting->value("ActionMain").toBool();
    mp_Setting->endGroup();
    m_ActionMain = x;
    return m_ActionMain;
}

void Setting::setActionMain(bool ActionMain)
{
    mp_Setting->setValue("CONFIG/ActionMain",ActionMain);
    m_ActionMain = ActionMain;
}
