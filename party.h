#include "base.h"

class party{
    public:
//setters

    void setX(int x);
    void setY(int y);

//getters
    int getX();
    int getY(); 

    void showStats();
    void stats();

    int size;
    protected:
    //party** group;

    int xcoord;
    int ycoord;
    int current;

};


class charParty : public party{
friend ostream& operator<<(ostream& o, const charParty& c);
    public:
    charParty();
    ~charParty();

    //assigment overload
    void operator=(const charParty&);
    //deep copy
    charParty(const charParty& selectedcharparty);

    void show();
    
    void Death();
    


    void makeParty();
    void Tcounter();


    void setX(int x);
    void setY(int y);
    void setTcounter(int t);


    int getTcounter();
    int getY();
    int getX();
    character* player;
    
    private:
    int xcoord;
    int ycoord;
    int tcounter;
    int ccounter;
    int charsize;
   

};

class monstParty : public party{
    public:

    monstParty();
    ~monstParty();

    void showMob();
    

    void setX(int x);
    void setY(int y);


    int getY();
    int getX();
    
    monster* mob;
    private:
    int deadmonstsize;
    int monstsize;


};