#include "mainwindow.h"
#include <QTextCodec>
#include <QApplication>
#include <QMessageBox>
#include <QSystemSemaphore>
#include <QSharedMemory>
#include <QTextCodec>

int main(int argc, char *argv[])
{
//    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-16"));
    QApplication a(argc, argv);
    //QTextCodec::setCodecForLocale("UTF-8");
    //    MainWindow w;
    //    w.show();
    //    return a.exec();
    QSystemSemaphore semaphore("SingleAppTest2Semaphore", 1);
    // 启用信号量，禁止其他实例通过共享内存一起工作
    semaphore.acquire();

#ifndef Q_OS_WIN32
    // 在linux / unix 程序异常结束共享内存不会回收
    // 在这里需要提供释放内存的接口，就是在程序运行的时候如果有这段内存 先清除掉
    QSharedMemory nix_fix_shared_memory("SingleAppTest2");
    if (nix_fix_shared_memory.attach())
    {
        nix_fix_shared_memory.detach();
    }
#endif
    // 创建一个共享内存  “SingleAppTest2”表示一段内存的标识key 可作为唯一程序的标识
    QSharedMemory sharedMemory("MainWindow");
    // 测试是否已经运行
    bool isRunning = false;
    // 试图将共享内存的副本附加到现有的段中。
    if (sharedMemory.attach())
    {
        // 如果成功，则确定已经存在运行实例
        isRunning = true;
    }
    else
    {
        // 否则申请一字节内存
        sharedMemory.create(1);
        // 确定不存在运行实例
        isRunning = false;
    }
    semaphore.release();

    // 如果您已经运行了应用程序的一个实例，那么我们将通知用户。
    if (isRunning)
    {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setText("The application is already running.\n"
                       "Allowed to run only one instance of the application.");
        msgBox.exec();
        return 1;
    }

    MainWindow w;
    //w.show();
    return a.exec();
}
