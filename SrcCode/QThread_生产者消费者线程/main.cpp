#include <QCoreApplication>
#include <QWaitCondition>
#include <QThread>
#include <QMutex>
#include <stdio.h>

const int DataSize=1000;
const int BufferSize=80;
int buffer[BufferSize];

QWaitCondition bufferEmpty;
QWaitCondition bufferFull;

QMutex mutex;//互斥锁
int numUsableBytes=0;
int rIndex=0;//指示当前所读取的缓存区位置

class Producer:public QThread
{
public:
    Producer() {}
    void run();
};
void Producer::run()
{
    for(int i=0;i<DataSize;++i)
    {
        mutex.lock();

        if(numUsableBytes==BufferSize)
            bufferEmpty.wait(&mutex);//如果缓存区满，阻塞进程到缓存区有空闲

        buffer[i%BufferSize]=numUsableBytes;//写入数据
        ++numUsableBytes;//增加可用字节
        bufferFull.wakeAll();//唤醒所有等待缓存区有数据的消费者

        mutex.unlock();
    }
}

class Consumer:public QThread
{
public:
    Consumer(){}
    void run();
};
void Consumer::run()
{
    forever
    {
        mutex.lock();

        if(numUsableBytes==0)
            bufferFull.wait(&mutex);//如果缓存区空，等待生产者写入数据

        printf("%u::[%d]=%d\n",currentThreadId(),rIndex,buffer[rIndex]);//输出
        ++rIndex;//下一字节
        rIndex=rIndex%BufferSize;//防止超界
        bufferEmpty.wakeAll();

        mutex.unlock();
    }
    printf("finshed\n");
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Producer producer;
    Consumer consumerA;
    Consumer consumerB;
    Consumer consumerC;
    Consumer consumerD;

    producer.start();
    consumerA.start();
    consumerB.start();
    consumerC.start();
    consumerD.start();

    producer.wait();
    consumerA.wait();
    consumerB.wait();
    consumerC.wait();
    consumerD.wait();

    return a.exec();
}
