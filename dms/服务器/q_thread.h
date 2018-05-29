#ifndef Q_THREAD_H
#define Q_THREAD_H

#include <QThread>

class q_thread : public QThread
{
    Q_OBJECT
public:
    explicit q_thread(QObject *parent = 0);
    void run();
signals:
    
public slots:
     //void send_text(QString);
};

#endif // Q_THREAD_H
