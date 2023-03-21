#include <stdio.h>
#include <iostream>
#include <time.h>
#include <Windows.h>
#include "Enemy.h"

using namespace std;



Enemy::Enemy()
    :xcoord(4),ycoord(3),saveX(0),saveY(0),saveField(' ') { }

/*Enemy::Enemy(int x, int y)
{
    this->xcoord=x;
    this->ycoord=y;
    this->saveField=' ';
}*/

void Enemy::moveIsi(Field field)
{
    int leave=0;
    this->saveY=this->ycoord;
    this->saveX=this->xcoord;
    // srand (time(NULL));
    int dir = rand() % 2 ;
    int len =field.length;
    if (dir == 0)
    {
        dir = rand() % 2 ;
        while (leave!=1) //going north or south
        {
            if (dir ==0 &&this->xcoord!=0)
            {
                len = rand () % len+1; //north
                this->xcoord=this->xcoord-len;
                if (this->xcoord<0)
                    this->xcoord=0;
                leave =1;
            }
            else if(dir ==1 && this->xcoord!=field.length-1)
            {
                len = rand () % len+1; //south
                this->xcoord=this->xcoord+len;
                if (this->xcoord>field.length-1)
                    this->xcoord=field.length-1;
                leave =1;
            }
            else if (dir==1) dir=0;
            else if (dir ==0)dir =1;
        }
    }
    else
    {
        srand (time(NULL));
        dir = rand() % 2 ;
        while (leave!=1) //going north or south
        {
            if (dir ==0 &&this->ycoord!=0)
            {
                len = rand () % len+1; //west
                this->ycoord=this->ycoord-len;
                if (this->ycoord<0)
                    this->ycoord=0;

                leave =1;
            }
            else if (dir ==1 && this->ycoord!=field.length-1)
            {
                len = rand () % len+1; //east
                this->ycoord=this->ycoord+len;
                if (this->ycoord>field.length-1)
                    this->ycoord=field.length-1;

                leave =1;
            }
            else if (dir==1) dir=0;
            else if (dir ==0)dir =1;
        }
    }

};



void Enemy::printInfo()
{

    cout<<"x: "<<this->xcoord<<endl;
    cout<<"y: "<<this->ycoord<<endl;
    cout<<"x-alt: "<<this->saveX<<endl;
    cout<<"y-alt: "<<this->saveY<<endl;
}


int Enemy::checkCollision(Person& player)
{
    int isi=0;
    //exact same location after player and isi move
    if (this->xcoord== player.xcoord&&this->ycoord==player.ycoord)
        isi=1;
    //exact same location before player move (player moving onto isi field)
    else if (this->saveX== player.xcoord&&this->saveY==player.ycoord)
        isi=1;
    //same x-axis
    else if (this->saveX == this->xcoord && this->xcoord == player.xcoord &&this->saveX != player.saveX )
    {
        if (min(this->ycoord,this->saveY)< player.ycoord && player.ycoord < max(this->ycoord,this->saveY))
            isi=1;
    }
    else if (this->saveY == this->ycoord && this->ycoord == player.ycoord && this->saveY != player.saveY )  //same y-axis
    {
        if (min(this->xcoord,this->saveX)< player.xcoord && player.xcoord < max(this->xcoord,this->saveX))
            isi=1;
    }

    if (isi==1)
    {
        player.hp =player.hp-(player.diff+2);
        player.hpLost+=(player.diff+2);
        if (player.hp<=0)
            player.leave=1;
    }
    return isi;
}
Enemy::~Enemy()
{
    //dtor
}
