#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initMainWindow("MusicPlayer");
    initPlayListWidget();
    m_isTransparentForMouse = true;
    setIsTransparentMouse(false);
    m_IsPlay = false;
    initPlayEnd(m_IsPlay);//播放设置
    m_IsMute = false;
    setMute(m_IsMute);
    m_IsWord = m_Set.getShowWord();
    setWordShow(m_IsWord);
    m_PlayMode =m_Set.getPlayMode();
    setPlayMode(m_PlayMode);
    ininTrayMenu();                   //初始化菜单
    initTrayIcon(":/image/icon.png"); //设置图标
}

MainWindow::~MainWindow()
{
    m_Set.setPlayIndex(m_MediaPlayList->currentIndex()<0?0:m_MediaPlayList->currentIndex());
    m_Set.setShowWord(!m_IsWord);
    m_Set.setAppLocation(QPoint(geometry().x(),geometry().y()));
    m_Set.setPlayMode(m_PlayMode%5);
    m_Set.setVolume(ui->horizontalSlider_Sound->value());
    m_Set.setActionMain(m_ShowMainWindow);
    m_Set.setTransparentMouse(m_isTransparentForMouse);
    delete mp_TrayIcon;
    delete mp_Traymenu;
    delete ui;
    qDebug()<< "app exit right.";
}


void MainWindow::on_pushButton_Play_clicked()
{
    qDebug()<<"on_pushButton_Play_clicked().";
    initPlayEnd(0);
}

void MainWindow::on_pushButton_End_clicked()
{
    qDebug()<<"on_pushButton_End_clicked().";
    initPlayEnd(1);
}


void MainWindow::setTransparentForMouse(bool isOk)
{
    ui->centralwidget->setAttribute(Qt::WA_TransparentForMouseEvents,isOk);
    mp_PlayListWidget->setAttribute(Qt::WA_TransparentForMouseEvents,isOk);
}

void MainWindow::initMainWindow(const QString &title)
{
    setWindowTitle(title);
    QIcon icon(":/image/icon.png");
    setWindowIcon(icon);
    setAttribute(Qt::WA_TranslucentBackground);
    setWindowFlags(Qt::FramelessWindowHint);
    move(m_Set.getAppLocation());
    ui->pushButton_End->setGeometry(ui->pushButton_Play->geometry());
    mp_Timer = new QTimer(this);
    connect(mp_Timer,SIGNAL(timeout()),this,SLOT(slotLabelWordSetText()));
    mp_Timer_Name = new QTimer(this);
    connect(mp_Timer_Name,SIGNAL(timeout()),this,SLOT(slotLabelName()));
}

void MainWindow::initPlayEnd(bool isOk)   //播放设置
{
    if(mp_PlayListWidget->count()==0)
    {
        ui->pushButton_Play->setVisible(0);
        ui->pushButton_End->setVisible(1);
        return;
    }
    ui->pushButton_Play->setVisible(isOk);
    ui->pushButton_End->setVisible(!isOk);

    m_IsPlay = isOk;

    if(isOk)
    {

        m_MediaPlayer->play();
        //mp_Timer_Name->start(200);
    }
    else
    {
        m_MediaPlayer->pause();
        if(mp_Timer_Name->isActive())
        {
            mp_Timer_Name->stop();
        }
    }
    qDebug() << "isplay is"<<isOk<<".";
}

void MainWindow::setMute(const bool isMute)
{
    if(isMute)
    {
        ui->pushButton_Sound->setStyleSheet("QPushButton{border-image: url(:/image/mute.png);}"
                                            "QPushButton:hover{border-image: url(:/image/mute_hover.png);}"
                                            "QPushButton:pressed{border-image: url(:/image/mute_pressed.png);}");
    }
    else
    {
        ui->pushButton_Sound->setStyleSheet("QPushButton{border-image: url(:/image/sound.png);}"
                                            "QPushButton:hover{border-image: url(:/image/sound_hover.png);}"
                                            "QPushButton:pressed{border-image: url(:/image/sound_pressed.png);}");
    }
    m_MediaPlayer->setMuted(m_IsMute);
    m_IsMute = !isMute;
}

void MainWindow::ininTrayMenu()
{
    mp_Traymenu = new TrayMenu(this);
    connect(mp_Traymenu,SIGNAL(signalIsShowMainWindow(bool)),this,SLOT(setIsShowMainWindow(bool)));
    connect(mp_Traymenu,SIGNAL(signalIsTransparentMouse(bool)),this,SLOT(setIsTransparentMouse(bool)));
    connect(mp_Traymenu,SIGNAL(signalIsIncrease(QString)),this,SLOT(setIncrease(QString)));
    connect(mp_Traymenu,SIGNAL(signalUpdate(bool)),mp_PlayListWidget,SLOT(slotUpdateList(bool)));
    connect(mp_Traymenu,SIGNAL(signalIsQuit()),this,SLOT(close()));
    mp_Traymenu->actionClickShow(m_Set.getActionMain());
    this->setVisible(m_Set.getActionMain());
    mp_Traymenu->actionClickTransparentMouse(m_Set.getTransparentMouse());
}

void MainWindow::initTrayIcon(const QString &iconname)
{
    mp_TrayIcon = new QSystemTrayIcon();
    QIcon icon = QIcon(iconname);
    //将icon设到QSystemTrayIcon对象中
    mp_TrayIcon->setIcon(icon);
    //当鼠标移动到托盘上的图标时，会显示此处设置的内容
    mp_TrayIcon->setToolTip("My MusicPlayer");
    //在系统托盘显示此对象
    mp_TrayIcon->show();
    //设置托盘右键
    mp_TrayIcon->setContextMenu(mp_Traymenu);
    //给QSystemTrayIcon添加槽函数
    connect(mp_TrayIcon,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,SLOT(on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason)));
}

void MainWindow::setPlayMode(const int mode)
{
    switch (mode)
    {
    case 0:qDebug()<<"playmode is 播放单曲:"<<mode;
        ui->pushButton_PlayMode->setStyleSheet("QPushButton{border-image: url(:/image/one.png);}"
                                               "QPushButton:hover{border-image: url(:/image/one_hover.png);}"
                                               "QPushButton:pressed{border-image: url(:/image/one_pressed.png);}");
        m_MediaPlayList->setPlaybackMode(QMediaPlaylist::CurrentItemOnce);
        break;
    case 1:qDebug()<<"playmode is 单曲循环:"<<mode<<".";
        ui->pushButton_PlayMode->setStyleSheet("QPushButton{border-image: url(:/image/currentIteminloop.png);}"
                                               "QPushButton:hover{border-image: url(:/image/currentIteminloop_hover.png);}"
                                               "QPushButton:pressed{border-image: url(:/image/currentIteminloop_pressed.png);}");
        m_MediaPlayList->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
        break;
    case 2:qDebug()<<"playmode is 顺序播放:"<<mode;
        ui->pushButton_PlayMode->setStyleSheet("QPushButton{border-image: url(:/image/sequential.png);}"
                                               "QPushButton:hover{border-image: url(:/image/sequential_hover.png);}"
                                               "QPushButton:pressed{border-image: url(:/image/sequential_pressed.png);}");
        m_MediaPlayList->setPlaybackMode(QMediaPlaylist::Sequential);
        break;
    case 3:qDebug()<<"playmode is 列表循环:"<<mode;
        ui->pushButton_PlayMode->setStyleSheet("QPushButton{border-image: url(:/image/loop.png);}"
                                               "QPushButton:hover{border-image: url(:/image/loop_hover.png);}"
                                               "QPushButton:pressed{border-image: url(:/image/loop_pressed.png);}");
        m_MediaPlayList->setPlaybackMode(QMediaPlaylist::Loop);
        break;
    case 4:qDebug()<<"playmode is 随机播放:"<<mode;
        ui->pushButton_PlayMode->setStyleSheet("QPushButton{border-image: url(:/image/rand.png);}"
                                               "QPushButton:hover{border-image: url(:/image/rand_hover.png);}"
                                               "QPushButton:pressed{border-image: url(:/image/rand_pressed.png);}");
        m_MediaPlayList->setPlaybackMode(QMediaPlaylist::Random);
        break;
    }

}

void MainWindow::setWordShow(const bool isWord)
{
    if(isWord)
    {
        ui->pushButton_Word->setStyleSheet("QPushButton{border-image: url(:/image/word.png);}"
                                           "QPushButton:hover{border-image: url(:/image/word_hover.png);}"
                                           "QPushButton:pressed{border-image: url(:/image/word_pressed.png);}");

        mp_Timer->start(1000);
    }
    else
    {
        ui->pushButton_Word->setStyleSheet("QPushButton{border-image: url(:/image/wordno.png);}"
                                           "QPushButton:hover{border-image: url(:/image/wordno_hover.png);}"
                                           "QPushButton:pressed{border-image: url(:/image/wordno_pressed.png);}");
        mp_Timer->stop();
    }
    ui->label_Word->setVisible(m_IsWord);

    m_IsWord = !isWord;
}

bool MainWindow::getLabelFontColor(const QLabel *label)
{
    QScreen *screen = QGuiApplication::primaryScreen();
    QPixmap p = screen->grabWindow(QApplication::desktop()->winId(),label->x()+pos().x(),label->y()+pos().y(),label->width(),label->height());
    QImage image = p.toImage();
    uchar *mat_data = image.bits();
    int sum =0;
    double ave =0;
    int size =p.size().width()*p.size().height();
    for (int i(0);i<size;++i)
    {
        sum+=*(mat_data+i);
    }
    ave = sum/(size);
//    qDebug()<<ave;
    if(ave>=130)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}



void MainWindow::on_pushButton_Right_clicked()
{
    qDebug()<<"on_pushButton_Right_clicked().";
    QMediaPlaylist::PlaybackMode mode = m_MediaPlayList->playbackMode();
    m_MediaPlayList->setPlaybackMode(QMediaPlaylist::PlaybackMode::Loop);
    m_MediaPlayList->next();
    m_MediaPlayList->setPlaybackMode(mode);

}

void MainWindow::on_pushButton_Left_clicked()
{
    qDebug()<<"on_pushButton_Left_clicked().";
    QMediaPlaylist::PlaybackMode mode = m_MediaPlayList->playbackMode();
    m_MediaPlayList->setPlaybackMode(QMediaPlaylist::PlaybackMode::Loop);
    m_MediaPlayList->previous();
    m_MediaPlayList->setPlaybackMode(mode);
}

void MainWindow::setIsShowMainWindow(bool isOk)
{
    m_ShowMainWindow = isOk;
    if(isOk)
    {
        show();
    }
    else
    {
        hide();
    }
    qDebug()<<"isShowMainWindow Complete:"<<isOk<<".";
}

void MainWindow::setIsTransparentMouse(bool isOk)
{
    isDrag = false;
    setTransparentForMouse(isOk);
    m_isTransparentForMouse = isOk;
    qDebug()<<"isTransparentMouse Complete:"<<isOk<<".";
}

void MainWindow::on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason reason)
{
    switch(reason)
    {
    case QSystemTrayIcon::Context:  //右键
        qDebug()<<reason<<":QSystemTrayIcon::Context.";
        mp_Traymenu->show();
        break;

    case QSystemTrayIcon::Trigger: //左键
        qDebug()<<reason<<":QSystemTrayIcon:Trigge.";
        break;
    default:
        break;
    }
}



void MainWindow::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton&&!m_isTransparentForMouse)
    {
        isDrag = true;
        m_position = e->globalPos() - this->pos();
        e->accept();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    if(isDrag && (e->buttons()))
    {
        move(e->globalPos() - m_position);
        e->accept();
    }
    //qDebug()<<"label location:"<<e->globalPos()-ui->label_Start->pos();
}

void MainWindow::mouseReleaseEvent(QMouseEvent *)
{
    isDrag = false;
    setLabelColor();
}



void MainWindow::on_pushButton_PlayMode_clicked()
{
    setPlayMode(++m_PlayMode%5);
}

void MainWindow::on_pushButton_Sound_clicked()
{
    setMute(m_IsMute);
}

void MainWindow::on_pushButton_Word_clicked()
{
    setWordShow(m_IsWord);
}


void MainWindow::setLabelColor()
{
    if(getLabelFontColor(ui->label_Name))
    {
        ui->label_Name->setStyleSheet("QLabel{background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0.744318 rgba(0, 0, 0,0),stop:1 rgba(238, 241, 241, 255));font: 15pt \"\346\245\267\344\275\223\";border-radius:5px;color:rgb(0, 0,0);}"
                                      "QLabel:hover{font: 15pt \"\346\245\267\344\275\223\";border-radius:5px;color:rgb(255, 255, 255);}");
    }
    else
    {
        ui->label_Name->setStyleSheet("QLabel{background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0.744318 rgba(0, 0, 0,0),stop:1 rgba(238, 241, 241, 255));font: 15pt \"\346\245\267\344\275\223\";border-radius:5px;color:rgb(255, 255,255);}"
                                      "QLabel:hover{font: 15pt \"\346\245\267\344\275\223\";border-radius:5px;color:rgb(0, 0, 0);}");
    }

    if(getLabelFontColor(ui->label_Start))
    {
        ui->label_Start->setStyleSheet("QLabel{font: 25 8pt ;border-image: url(:/image/zbutton.png);border:none;color:rgb(0, 0,0);}"
                                       "QLabel:hover{font: 25 8pt ;border:none;color:rgb(255, 255, 255);}");
    }
    else
    {
        ui->label_Start->setStyleSheet("QLabel{font: 25 8pt ;border-image: url(:/image/zbutton.png);border:none;color:rgb(255, 255, 255);}"
                                       "QLabel:hover{font: 25 8pt ;border:none;color:rgb(0, 0,0);}");
    }

    if(getLabelFontColor(ui->label_End))
    {
        ui->label_End->setStyleSheet("QLabel{font: 25 8pt ;border-image: url(:/image/zbutton.png);border:none;color:rgb(0, 0,0);}"
                                     "QLabel:hover{font: 25 8pt ;border:none;color:rgb(255, 255, 255);}");
    }
    else
    {
        ui->label_End->setStyleSheet("QLabel{font: 25 8pt ;border-image: url(:/image/zbutton.png);border:none;color:rgb(255, 255, 255);}"
                                     "QLabel:hover{font: 25 8pt ;border:none;color:rgb(0, 0,0);}");

    }
    if(getLabelFontColor(ui->label_Word))
    {
        ui->label_Word->setStyleSheet("QLabel{font: 25 17pt ;color:rgb(0, 0,0);}"
                                      "QLabel:hover{font: 25 8pt ;color:rgb(255, 255, 255);}");
    }
    else
    {
        ui->label_Word->setStyleSheet("QLabel{font: 25 17pt ;color:rgb(255, 255, 255);}"
                                      "QLabel:hover{font: 25 8pt ;color:rgb(0, 0,0);}");

    }
}

void MainWindow::initPlayListWidget()
{
    mp_PlayListWidget = new PlayListWidget(this);
    mp_PlayListWidget->setGeometry(ui->pushButton_heart->x(),
                                   ui->pushButton_heart->y()+50,
                                   300,200);
    mp_PlayListWidget->hide();
    connect(this,SIGNAL(signalSendIncreas(QString)),mp_PlayListWidget,SLOT(slotRecIncreas(QString)));

    //mp_PlayListWidget->m_PathList=m_Set.getPathMedia();
    initMediaPlaylist();
}

void MainWindow::initMediaPlaylist()
{
    m_MediaPlayList = new QMediaPlaylist(this);

    initMediaPlayer();
}

void MainWindow::initMediaPlayer()
{
    m_MediaPlayer = new QMediaPlayer(this);
    m_MediaPlayList->addMedia(mp_PlayListWidget->m_mediaList);
    m_MediaPlayer->setPlaylist(m_MediaPlayList);
    connect(m_MediaPlayList,SIGNAL(currentIndexChanged(int)),this,SLOT(slotCurrentMedia(int)));
    connect(mp_PlayListWidget,SIGNAL(clicked(const QModelIndex &)),this,SLOT(slotItemClicked(const QModelIndex &)));
    connect(mp_PlayListWidget,SIGNAL(doubleClicked(const QModelIndex &)),this,SLOT(slotItemDoubleClicked(const QModelIndex &)));
    connect(mp_PlayListWidget,SIGNAL(signalUpdatePlayerList()),this,SLOT(slotUpdatePlayerList()));
    //connect(m_MediaPlayer,SIGNAL(QOverload<QMediaPlayer::Error>::of(&QMediaPlayer::error)),this,SLOT(slotMediaError(QMediaPlayer::Error)));
    connect(m_MediaPlayer, QOverload<QMediaPlayer::Error>::of(&QMediaPlayer::error),this, &MainWindow::slotMediaError);
    connect(m_MediaPlayer,SIGNAL(volumeChanged(int)),ui->horizontalSlider_Sound,SLOT(setValue(int)));
    connect(m_MediaPlayer,SIGNAL(positionChanged(qint64)),this,SLOT(slotMediaPosition(qint64)));
    connect(m_MediaPlayer,SIGNAL(stateChanged(QMediaPlayer::State)),this,SLOT(slotSetMediaState(QMediaPlayer::State)));

    //set.ini
    //设置初始音乐
    //初始音量对勾
    //初始播放方式对勾
    //初始列表对勾
    //初始展示歌词对勾
    //位置对勾
    m_MediaPlayList->setCurrentIndex(m_Set.getPlayIndex()>mp_PlayListWidget->m_mediaList.size()?0:m_Set.getPlayIndex());
    m_MediaPlayer->setVolume(m_Set.getVolume());
}

void MainWindow::on_pushButton_heart_clicked()
{
    if(mp_PlayListWidget->isVisible())
    {
        mp_PlayListWidget->hide();
    }
    else
    {
        mp_PlayListWidget->show();
    }
}

void MainWindow::slotItemClicked(const QModelIndex &index)
{
    m_MediaPlayList->setCurrentIndex(index.row());
    m_MediaPlayer->play();
    //qDebug()<<m_MediaPlayer->mediaStatus();
}

void MainWindow::slotItemDoubleClicked(const QModelIndex &)
{
    mp_PlayListWidget->hide();
}


void MainWindow::on_horizontalSlider_Sound_valueChanged(int value)
{
    m_MediaPlayer->setVolume(value);
}

void MainWindow::slotMediaPosition(qint64 value)
{
    ui->horizontalSlider_Music->setMaximum(int(m_MediaPlayer->duration()/1000));
    ui->horizontalSlider_Music->setValue(int(value/1000));
    ui->label_Start->setText(formatTime(value));
    ui->label_End->setText(formatTime(m_MediaPlayer->duration()));
}

QString MainWindow::formatTime(qint64 timeMilliSeconds)
{
    qint64 seconds = timeMilliSeconds / 1000;
    const qint64 minutes = seconds / 60;
    seconds -= minutes * 60;
    return QStringLiteral("%1:%2")
            .arg(minutes, 2, 10, QLatin1Char('0'))
            .arg(seconds, 2, 10, QLatin1Char('0'));
}

void MainWindow::initVideoWidget()
{
    m_VideoWidget = new QVideoWidget();
    layoput = new QGridLayout();
    m_MediaPlayer->setVideoOutput(m_VideoWidget);
    layoput->addWidget(m_VideoWidget);
    //ui->widget->setLayout(layoput);
}


void MainWindow::on_horizontalSlider_Music_valueChanged(int value)
{
    if (qAbs(m_MediaPlayer->position() - value*1000) > 1000)
    {
        m_MediaPlayer->setPosition(value*1000);
        //qDebug() << qAbs(m_MediaPlayer->position() - value*1000);
    }
    else
    {
        //qDebug() << qAbs(m_MediaPlayer->position() - value*1000);
    }
}

void MainWindow::slotSetMediaState(QMediaPlayer::State state)
{
    switch (state)
    {
    case QMediaPlayer::StoppedState:initPlayEnd(0);
        break;
    case QMediaPlayer::PlayingState:initPlayEnd(1);
        break;
    case QMediaPlayer::PausedState:initPlayEnd(0);
        break;
    }
}

void MainWindow::slotCurrentMedia(int postion)
{
    if(postion>=0)
    {
        ui->label_Name->setText(mp_PlayListWidget->m_file[postion]);
        m_scrollCaptionStr = mp_PlayListWidget->m_file[postion];
    }

}

void MainWindow::slotLabelWordSetText()
{
    if(mp_Timer->isActive())
    {
        ui->label_Word->setText(QString::fromLocal8Bit("衣带渐宽终不悔，为伊消得人憔悴！"));
    }
}

void MainWindow::slotMediaError(QMediaPlayer::Error error)
{
    QMediaPlaylist::PlaybackMode mode = m_MediaPlayList->playbackMode();
    m_MediaPlayList->setPlaybackMode(QMediaPlaylist::PlaybackMode::Loop);
    qDebug()<<"error:"<<error;
    m_MediaPlayer->stop();
    m_MediaPlayList->setPlaybackMode(mode);
}

void MainWindow::setIncrease(QString str)
{
    emit signalSendIncreas(str);
}

void MainWindow::slotLabelName()
{
    static int nPos = 0;
    QString chr = " ";
    int presize;
    if(m_scrollCaptionStr.length()<11)
    {
        presize = (11-m_scrollCaptionStr.length());
        for (int i(0);i<=presize;i++)
        {
            m_scrollCaptionStr+=chr;
            m_scrollCaptionStr= chr+m_scrollCaptionStr;
        }
    }

    if (nPos > m_scrollCaptionStr.length())
    {
        nPos = 0;
    }

    ui->label_Name->setText(m_scrollCaptionStr.mid(nPos));
    nPos++;
}

void MainWindow::slotUpdatePlayerList()
{
    qDebug()<<"列表更新";
    m_MediaPlayList->clear();
    m_MediaPlayList->addMedia(mp_PlayListWidget->m_mediaList);
    m_MediaPlayer->setMedia(m_MediaPlayList);
}




