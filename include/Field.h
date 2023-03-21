#include <iostream>
#include <Person.h>
#include <Enemy.h>

#ifndef FIELD_H
#define FIELD_H

class Person;
class Enemy;

using namespace std;

class Field
{
public:
    char field [22][22];
    int found,unfound,length;
    Field();
    virtual ~Field();
    void initField();
    void printField(Person &player, Enemy &enemy1);
    void printGameInfo();


protected:

private:
};

#endif // FIELD_H
