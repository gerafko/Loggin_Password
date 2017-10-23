#ifndef STRUCT_H
#define STRUCT_H

#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <cstring>
#include <fstream>
#include <QString>
#include <QFile>

class Struct
{
    QString name;
    int password_lenght;
    QString password_value;
    bool block = 0;
public:
    Struct();
};

#endif // STRUCT_H
