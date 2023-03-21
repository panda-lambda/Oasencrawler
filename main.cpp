#include <iostream>
#include <stdlib.h>
#include <array>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <Person.h>
#include <Field.h>
#include <Enemy.h>
#include <cmath>
class Enemy;




void resetLvl(Field &field,Person &player, Enemy &enemy1)
{
    int save = field.length;
    cout<<"Alle Relikte in diesem Level gefunden"<<endl;
    system("PAUSE");
    system("CLS");
    cout <<"********STATISTIK*********"<<endl;
    player.printStats();
    system("PAUSE");
    system("CLS");
    player.diff+=2;
    player.hp+=player.diff/2+2;
    cout<<endl<<endl<<"NEUES LEVEL!"<<endl<<"Proben sind nun um ";
    cout <<player.diff/2<<" erschwert, Sie verlieren "<<player.diff/2+1<<" Leben bei fehlgeschlagenen Proben und Isidiosa macht nun ";
    cout <<player.diff+2<<" Schaden."<<endl<<endl;
    cout << "Ihr Leben wurde um "<< player.diff/2+2<<" erhoeht. ";
    cout <<"Sie erhalten "<<player.diff/2<<" Attributspunkte, damit ";
    cout <<"werden Attribute gesteigert."<<endl;
    system("PAUSE");
    player.hpGain=0;
    player.hpLost=0;
    field= Field();
    field.length= save+1;
    field.initField();
    player.moves=0;
    player.xcoord=0;
    player.ycoord=0;
    player.saveX=0;
    player.saveY=0;
    player.relics=0;
    enemy1.saveX=field.length-1;
    enemy1.xcoord=field.length-1;
    enemy1.saveY=field.length-2;
    enemy1.ycoord=field.length-2;
    system("CLS");
    cout <<"********STEIGERUNG********"<<endl;
    player.setAttri(player.diff/2);
    system("PAUSE");
    system("CLS");

}
using namespace std;

int main()
{
    int lvlCount = 11;
    Person player;
    Field field;
    field.initField();
    Enemy enemy1;
    field.printGameInfo();
    string input;

    int isi=0; //check if isi got player
    while(1)
    {
        field.printField(player,enemy1);
        //isi= enemy1.checkCollision(player);
        player.printInfo();
        player.handleEvent(field);
        if (field.unfound==0&&(field.length -4)<lvlCount)
        {
            resetLvl(field,player,enemy1);
            isi=0;
        }
        else if (field.unfound>0 && player.hp >0 )
        {
            input= player.getInput(isi);
            enemy1.moveIsi(field);
            player.movePlayer(input, field);
            isi= enemy1.checkCollision(player);
        }
        if ((field.unfound==0&&(field.length -4)==lvlCount) || player.leave ==1|| player.hp <=0 || input[0] =='x'|| input[0] =='X' )
        {
            field.printField(player,enemy1);
            cout <<" Das Spiel ist beendet!"<<endl;
            if (isi==1)
                cout<<"Isi hat Sie erledigt!"<<endl;
            system("PAUSE");
            break;
        }
    }
    system("CLS");
    player.printStats();
    if (input[0] =='x'|| input[0] =='X')
        cout << "Sie haben das Spiel fruehzeitig beendet!";
    else
    {
        if (player.unfound==0 && (field.length -4)==lvlCount)
            cout << endl<<"****Juhu, Sie haben GEWONNEN!***"<<endl;
        else
            cout<<endl<<"Sie haben leider kein Leben mehr und haben das Spiel verloren."<<endl;
    }
    return 0;
}
