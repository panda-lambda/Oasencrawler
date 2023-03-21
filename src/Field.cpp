#include <stdio.h>
#include "Field.h"
#include <time.h>
#include <Windows.h>
#include <Enemy.h>




using namespace std;

Field::Field()
{

    found = 0;
    unfound=0;
    length=5;


}


Field::~Field()
{
    //dtor
}

void Field::initField()
{
    int temp;
    srand (time(NULL));
    for (int i = 0; i<this->length; i++)
    {
        for (int j = 0; j<this->length; j++)
        {
            temp= rand() % 10 ;
            switch(temp)
            {
            case 0:
            case 1:
            case 2:
            case 3:
                this->field[j][i]='.';
                break;
            case 4:
            case 5:
            case 6:
            case 7:
                this->field[j][i]='?';
                break;
            case 8:
                this->field[j][i]='O';
                break;
            case 9:
                if ((i!=0&& j!=0)&&((i!=(this->length-1) )&&j!=(this->length-2)))
                {
                    this->field[j][i]='R';
                    this->unfound++;
                }
                else
                {
                    this->field[j][i]='.';
                }
            }
        }
    }
    if (this->unfound==0)
    {
        this->field[this->length -1][this->length -1]='R';
        this->unfound++;
    }
};

void Field::printField(Person &player, Enemy &enemy1)
{
    int lvl=this->length -4;
    system("CLS");
    if (player.moves!=0)
    {
        //altes feld mit save überschreiben
        this->field[player.saveX][player.saveY]='.';
        this->field[enemy1.saveX][enemy1.saveY]=enemy1.saveField ;
        //neues spielerposition speichern
        player.saveField = this->field[player.xcoord][player.ycoord];
        enemy1.saveField = this->field[enemy1.xcoord][enemy1.ycoord];
        player.saveX= player.xcoord;
        player.saveY= player.ycoord;

        //neue position des felds mit spieler ersetzen, player muss als zweites, sonst weg bei doppelter Belegung
        this->field[enemy1.xcoord][enemy1.ycoord]='M';
        this->field[player.xcoord][player.ycoord]='@';
    }
    else
    {
        player.saveField = this->field[0][0];
        enemy1.saveField = this->field[this->length-1][this->length-2];
        player.saveX= 0;
        player.saveY= 0;
        enemy1.saveX=this->length-1;
        enemy1.saveY=this->length-2;
        this->field[this->length-1][this->length-2]='M';
        this->field[0][0]='@';
    }
    cout<<endl<<"********** [LVL "<<lvl<<" ]  Finden Sie alle Relikte!  **********"<<endl<<endl<<endl;
    for (int i = 0; i< this->length; i++)
    {
        cout<<"       ";
        for (int j = 0; j<this->length; j++)
        {
            cout<<this->field[j][i]<<"      ";
        }
        cout<<endl<<endl<<endl;
    }
};



//arry [x+y *5] https://www.youtube.com/watch?v=gNgUMA_Ur0U

void Field::printGameInfo()
{
    cout << "***************************************************************************"<<endl;
    cout << "  -----------------------------------------------------------------------"<<endl;
    cout<<"       ___                                               _           "<<endl;
    cout<<"      / _ \\  __ _ ___  ___ _ __   ___ _ __ __ ___      _| | ___ _ __ "<<endl;
    cout<<"     | | | |/ _` / __|/ _ \\ '_ \\ / __| '__/ _` \\ \\ /\\ / / |/ _ \\ '__|"<<endl;
    cout<<"     | |_| | (_| \\__ \\  __/ | | | (__| | | (_| |\\ V  V /| |  __/ |   "<<endl;
    cout<<"      \\___/ \\__,_|___/\\___|_| |_|\\___|_|  \\__,_| \\_/\\_/ |_|\\___|_|   "<<endl <<endl;
    cout << "  ------------------------------------------------------------------------"<<endl;
    cout << "****************************************************************************"<<endl<<endl<<endl;
    cout << "Willkommen beim OASENCRAWLER, ein Spielprojekt von Benjamin Storck."<<endl <<endl<<flush;
    system ("PAUSE");
    system("CLS");
    cout << "******************************************************************"<<endl;
    cout<<"       ___ ___ ___ ___ _    ___ ___ ___ ___ _    _  _ "<<endl;
    cout<<"      / __| _ \\_ _| __| |  | _ \\ __/ __| __| |  | \\| |"<<endl;
    cout<<"      \\__ \\  _/| || _|| |__|   / _| (_ | _|| |__| .` |"<<endl;
    cout<<"      |___/_| |___|___|____|_|_\\___\\___|___|____|_|\\_|"<<endl<<endl;
    cout << "******************************************************************"<<endl<<endl;
    cout << " Als Drachenjaegerin muessen Sie alle versteckten Relikte in 10 Leveln finden, um den Prinzen von Azrael zu befreien."<<endl;
    cout << " Ihr ehemaliger Kampfgenosse Isidiosa versucht ebenso, die Relikt(e) zu finden. Achtung,  "<<endl;
    cout<<" falls er Sie erwischt, wird Ihnen  Leben abgezogen! Sie beginnen mit 5 Lebenspunkten."<<endl;
    cout <<" Sie haben die drei Attribute Intelligenz, Charisma und Konstitution, die Sie nach jedem Level steigern koennen."<<endl<<endl;
    cout << "****SPIELFELD****"<<endl;
    cout << "'@' = Ihre Spielfigur"<<endl;
    cout<< "'?' = Gefahrenfeld"<<endl;
    cout <<"'.' = leeres Feld"<<endl;
    cout <<"'O' = Lebensbrunnen (+1 Leben)"<<endl;
    cout <<"'M' = Isidiosa, bewegt sich wie die Figur 'Turm' in Schach."<<endl<<endl;
    cout << " Bei Betreten eines Gefahrenfeldes, muessen Sie eine Probe auf eines Ihrer Attribute machen. "<<endl;
    cout <<" Probe: Es wird ein 20-seitiger Wuerfel geworfen, wenn der Wuerfelwert kleiner als"<<endl;
    cout<<" Ihr Attributswert (und Modifier) ist, ist die Probe bestanden!"<<endl;
    cout << " Bestehen Sie die Probe nicht, verlieren Sie Leben!"<<endl;
    cout<<" Bereits betretene Feld werden zu leeren Feldern  (dargestellt durch '.')" <<endl<<endl;
    cout <<"****SPIELENDE****"<<endl;
    cout<<"'Gewonnen' = Sie finden alle Relikte aller 10 Level. "<<endl;
    cout<<"'Verloren' = Sie besitzen kein Leben mehr. "<<endl;
    cout<<"             [Das Spiel endet dann automatisch.]"<<endl<<endl<<flush;
    system ("PAUSE");
    system("CLS");
};

