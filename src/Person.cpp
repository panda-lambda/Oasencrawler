#include <stdio.h>
#include <iostream>
#include <string.h>
#include <Person.h>

using namespace std;


Person::Person()
//constructor
    :hp(15),relics(0),xcoord(0),ycoord(0),unfound(0),leave(0),intel(10),
     strength(10),charisma(10),hpLost(0),hpGain(0),moves(0),saveX(0),saveY(0),diff(0),saveField(' ') {} //initializer list


string Person::getInput (int isi)
{
    string input = "kk";

    if (isi ==1)
    {
        cout<<endl<<"  Isidiosa hat Sie erwischt, Sie verlieren "<<this->diff+2<<" Leben und haben jetzt noch "<<this->hp<<" Leben!"<<endl<<endl;
        system("PAUSE");
    }

    cout<<"  [WASD: Bewegung | x: Verlassen | Bestaetigung mit Enter]"<<endl<<endl;
    cout<<"  Eingabe: ";
    while (1)
    {
        cin>> input;
        //cout<< input.size()<<"groesse"<<endl;
        if (input.size() >1)
        {
            cout<<"  Bitte geben Sie nur einen Buchstaben(W,A,S,D) ein!"<<endl;
            cout<<"  Eingabe: ";
            continue;
        }
        if(input[0]!='w'&& input[0]!='W'&& input[0]!='a'&&input[0]!='A'&&input[0]!='s'&&input[0]!='S'&&input[0]!='d'&&input[0]!='D'&&input[0]!='x'&&input[0]!='X' )
        {
            cout<<"  Bitte geben Sie nur einen Buchstaben(W,A,S,D) ein!"<<endl;
            cout<<"  Eingabe: ";
            continue;
        }
        break;
    }
    return input;
}

void Person::setAttri(int points)
{
    this->printInfo();
    string input;
    cout<<" Bitte waehlen Sie eines der Attribute:"<<endl;
    cout << "Eingabe  | Attribut | Steigerung | Kosten"<<endl<<" mit '0' Leben            +1      (1 Punkt)"<<endl;
    cout<<" mit '1' Intelligenz      +1      (2 Punkte)"<<endl;
    cout <<" mit '2' Charisma         +1      (2 Punkte)"<<endl<<" mit '3' Konstitution     +1      (2 Punkte)"<<endl<<endl;
    while (points>0)
    {
        cout <<  " noch "<<points<<" Punkte, Zahl(0-3) Eingabe:";

        cin>> input;
        if (input[0]!='0' &&input[0]!='1' &&input[0]!='2' &&input[0]!='3' )
        {
            cout<<"Bitte eine Zahl zwischen 0 und 3 eingeben!";

        }
        else if (input[0]=='0')
        {
            this->hp++;
            cout<<endl<<" Sie haben nun " <<this->hp<<" Leben."<<endl<<endl;
            points--;
        }
        else if(points<2)
        {
            cout<<endl<<"  Sie haben nicht genug Punkte "<<endl;
        }
        else
        {
            if (input[0]=='1')
            {
                this->intel++;
                cout<<endl<<" Sie haben nun " <<this->intel<<" Intelligenz."<<endl<<endl;
            }
            if (input[0]=='2')
            {
                this->charisma++;
                cout<<endl<<" Sie haben nun " <<this->charisma<<" Charisma."<<endl<<endl;
            }
            if (input[0]=='3')
            {
                this->strength++;
                cout<<endl<<" Sie haben nun " <<this->strength<<" Konstitution."<<endl<<endl;
            }

            points-=2;
        }
    }

}

void Person::printInfo()
{
    cout <<"**************************";
    cout << endl<<"*  Lebenspunkte: "<<this->hp<<"       *"<<endl;
    cout << "*  Intelligenz: "<<this->intel<<"       *"<<endl;
    cout << "*  Charisma: "<<this->charisma<<"          *"<<endl;
    cout << "*  Konstitution: "<<this->strength<<"      *"<<endl;
    cout << "*  Gefundene Relikte: "<<this->relics<<"  *"<<endl;
    cout <<"**************************"<<endl;
    /*cout <<this->unfound<<"-unfound"<<endl;
    cout <<this->xcoord<<"-x"<<endl;
    cout <<this->ycoord<<"-y"<<endl;
    cout <<this->leave<<"-exit"<<endl;*/
}

void Person::printStats()
{
    cout <<"**************************"<<endl;
    cout << " * Erreichtes Level: "<< this->diff/2+1<<"  *"<<endl;
    cout<<  " *                      *"<<endl;

    cout << " * Statistik Level "<<this->diff/2+1<<":   " <<endl;
    cout << " * Anzahl der Zuege: "<< this->moves<<endl;
    cout << " * Relikte              *"<<endl;
    cout << " *   "<<this->relics<< "   gefunden       *"<<endl;
    // cout << " *   "<<this->unfound<< "   verpasst       *"<<endl;
    cout<<  " *                      *"<<endl;
    cout << " * Leben                *"<<endl;
    cout << " *   "<<this->hpLost<<"   verloren       *"<<endl;
    cout << " *   "<<this->hpGain<< "   bekommen       *"<<endl;
    cout <<"**************************"<<endl;

}

void Person::movePlayer(string input, Field field)
{
    switch (input[0])
    {
    case 'w':
    case 'W':
        if (this->ycoord<1)
        {
            cout<<"  Sie koennen nicht weiter nach oben gehen."<<endl;
            system ("PAUSE");
        }
        else
        {
            this->moves++;
            this->ycoord--;
        }
        break;
    case 's':
    case 'S':
        if (this->ycoord>field.length-2)
        {
            cout<<"  Sie koennen nicht weiter nach unten gehen."<<endl;
            system ("PAUSE");
        }
        else
        {
            this->moves++;
            this->ycoord++;
        }
        break;
    case 'd':
    case 'D':
        if (this->xcoord>field.length-2)
        {
            cout<<"  Sie koennen nicht weiter nach rechts gehen."<<endl;
            system ("PAUSE");
        }
        else
        {
            this->moves++;
            this->xcoord++;
        }
        break;
    case 'a':
    case 'A':
        if (this->xcoord<1)
        {
            cout<<"  Sie koennen nicht weiter nach links gehen."<<endl;
            system ("PAUSE");
        }
        else
        {
            this->moves++;
            this->xcoord--;
        }
    }
}




void Person::handleEvent( Field &playfield)
{
    if (this->moves!=0)
    {
        int attriChoice=rand() % 3 ;
        int getTalisman= rand() %6;
        char event = this->saveField;
        int dmg=this->diff/2+1;
        if (event =='?')
        {
            cout<<"  Sie haben ein Gefahrenfeld betreten!"<<endl<<endl;
            cout<<"  Es folgt eine Probe auf ";

            int modifier = rand() % 8-4; //check modifier
            int  check=(-1)*(this->diff/2 + modifier);
            int dice= rand ()%20+1;
            switch(attriChoice)
            {
            case 0:
                cout<<" Intelligenz, um die Schwierigkeit "<< check  << " modifiziert"<<endl;
                cout<< "  Ihr Intelligenzwert liegt bei "<<this->intel<<"." <<endl<<endl<<"  Um zu wuerfeln,";

                system("PAUSE");
                cout<<endl<<endl<<"  Die Probe auf "<< this->intel +check<<" Intelligenz war";
                if (this->intel+ check > dice )
                {
                    cout<<" erfolgreich mit "<< dice<<endl<<endl;
                    if (this->intel>109)
                    {
                        this->intel-=100;
                        cout<<"  Sie haben einen Talisman der Schlauheit verbraucht!";
                    }
                }
                else
                {
                    cout<<" nicht erfolgreich mit "<< dice<<endl;
                    this->hp-=dmg;
                    this->hpLost+=dmg;
                    cout <<"  Sie verlieren "<<dmg<<" Leben und haben jetzt noch " <<this->hp<<" Leben."<<endl<<endl;
                }
                break;
            case 1:
                cout<<" Charisma, um die Schwierigkeit "<<check  << " modifiziert"<<endl;
                cout<< "  Ihr Charismawert liegt bei "<<this->charisma<<"." <<endl<<endl<<"  Um zu wuerfeln,";

                system("PAUSE");
                cout<<endl<<endl<<"  Die Probe auf "<< this->charisma +check<<" Charisma war";
                if ((this->charisma + check) > dice )
                {
                    cout<<" erfolgreich mit "<< dice<<endl<<endl;
                    if (this->charisma>109)
                    {
                        this->charisma-=100;
                        cout<<"  Sie haben einen Talisman der Geselligkeit verbraucht!";
                    }
                }
                else
                {
                    cout<<" nicht erfolgreich mit "<< dice;
                    this->hp-=dmg;
                    this->hpLost+=dmg;
                    cout <<"  Sie verlieren " <<dmg<<" Leben und haben jetzt noch " <<this->hp<<" Leben."<<endl<<endl;
                }
                break;
            case 2:
                cout<<" Konstitution, um die Schwierigkeit "<<check  << " modifiziert"<<endl;
                cout<< "  Ihr Konstitutionswert liegt bei "<<this->strength<<"." <<endl<<endl<<"  Um zu wuerfeln,";

                system("PAUSE");
                cout<<endl<<endl<<"  Die Probe auf "<< this->strength +check<<" Konstitution war";
                if (this->strength + check > dice )
                {
                    cout<<" erfolgreich mit "<< dice<<endl<<endl;
                    if (this->strength>109)
                    {
                        this->strength-=100;
                        cout<<"  Sie haben einen Talisman der Staerke verbraucht!";
                    }
                }
                else
                {
                    cout<<" nicht erfolgreich mit "<< dice<<endl;
                    this->hp-=dmg;
                    this->hpLost+=dmg;
                    cout <<"  Sie verlieren "<<dmg<<" Leben und haben jetzt noch " <<this->hp<<" Leben."<<endl<<endl;
                }
                break;
            }
        }
        else if (event=='O')
        {
            this->hp++;
            this->hpGain++;
            cout<<"  Ein Lebensbrunnen! Sie haben einen Lebenspunkt bekommen und besitzen jetzt "<<this->hp<<" Lebenspunkte."<<endl;
            if (getTalisman<2)
            {
                switch(attriChoice)
                {
                case 0:
                    this->intel= this->intel+100;
                    cout<<"  Sie haben einen Talisman der Schlauheit (eine Probe +100) gefunden. Ihr Intelligenzwert liegt jetzt bei "<<this->intel<<"."<<endl<<endl;
                    break;
                case 2:
                    this->charisma= this->charisma+100;
                    cout<<"  Sie haben einen Talisman der Geselligkeit (eine Probe +100) gefunden. Ihr Charismawert liegt jetzt bei "<<this->charisma<<"."<<endl<<endl;
                    break;
                case 3:
                    this->strength= this->strength+100;
                    cout<<"  Sie haben einen Talisman der Staerke (eine Probe +100) gefunden. Ihr Konstitutionswert liegt jetzt bei "<<this->strength<<"."<<endl<<endl;
                }
            }
        }
        else if (event=='R')
        {
            playfield.unfound--;
            this->relics++;
            if (playfield.unfound>0)
            {
                cout << "  Gratulation! Sie haben ein Relikt gefunden!"<<endl;
            }
            if (getTalisman<2)
            {
                switch(attriChoice)
                {
                case 0:
                    this->intel= this->intel+1;
                    cout<<"  Sie haben ein verzaubertes Amulett der Schlauheit (permanent +1) gefunden. Ihr Intelligenzwert liegt jetzt bei "<<this->intel<<"."<<endl<<endl;
                    break;
                case 1:
                    this->charisma= this->charisma+1;
                    cout<<"  Sie haben ein verzaubertes Amulett der Geselligkeit (permanent +1) gefunden. Ihr Charismawert liegt jetzt bei "<<this->charisma<<"."<<endl<<endl;
                    break;
                case 3:
                    this->strength= this->strength+1;
                    cout<<"  Sie haben ein verzaubertes Amulett der Staerke (permanent +1) gefunden. Ihr Konstitutionswert liegt jetzt bei "<<this->strength<<"."<<endl<<endl;
                }
            }
        }
    }
}

Person::~Person()
{
    //dtor
}
