#ifndef ENEMY_H
#define ENEMY_H
#include <Person.h>
#include <Field.h>

class Enemy
{
public:
    int xcoord, ycoord,saveX,saveY;
    char saveField;
    Enemy();
    //Enemy(int x, int y);
    int checkCollision(Person& player);
    void printInfo();
    void moveIsi(Field field);
    virtual ~Enemy();

protected:

private:
};

#endif // ENEMY_H
