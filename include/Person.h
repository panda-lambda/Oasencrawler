#ifndef PERSON_H
#define PERSON_H
#include <Field.h>

using namespace std;

class Person
{
public:
    int hp,relics,xcoord,ycoord,unfound,leave,intel,strength,charisma,hpLost;
    int hpGain,moves,saveX,saveY,diff;
    char saveField;
    Person();

    string getInput (int isi);
    void setAttri(int points);
    void printInfo();
    void movePlayer(string input, Field field);
    void handleEvent( Field &playfield);
    void printStats();

    virtual ~Person();

protected:

private:
};

#endif // PERSON_H
