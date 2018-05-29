#include <iostream>
#include <cstring>
#include "server.h"
#include "filedao.h"
#include "oracledao.h"
#include "swidget.h"
#include "data.h"
#include <QApplication>
#include <QTextCodec>
using namespace std;

int main(int argc, char *argv[])
{

    /*QTextCodec *codec = QTextCodec::codecForName("UTF-8");//情况2
    QTextCodec::setCodecForTr(codec);
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);*/
    QApplication a(argc, argv);
    swidget w;
    w.show();
    return a.exec();

}

