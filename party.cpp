#include "party.h"

charParty::charParty(){
    xcoord = 0;
    ycoord = 0;
    tcounter=0;
    ccounter = 0;
    size = 5;
    player = new character[size];
}

monstParty:: monstParty(){
    deadmonstsize = 0;
    size = (rand()%5) +1;
    mob = new monster[size];
}

charParty::~charParty(){
    delete [] player;
}

monstParty::~monstParty(){
    delete [] mob;
}

void charParty:: operator=(const charParty& c){
    delete [] player;
    xcoord = c.xcoord;
    ycoord = c.ycoord;
    tcounter = c.tcounter;
    ccounter = c.ccounter;
    size = c.size;
    player = new character[size];
    for (int i = 0; i < ccounter; i++){
        player[i] = c.player[i];
    }
}

void charParty::makeParty(){
    for(int i = 0; i < size; i++){
        player[i] = character();
        ccounter++;
        cout<<"Player "<< i <<" has spawned in your party"<<endl;
    }
}


ostream& operator<<(ostream& o, const charParty& c){
    for (int i = 0; i < c.size; i++){
        cout<<"Player " << i << ": ";
        c.player[i].stats();
    }
    if (c.tcounter > 0){
        cout<<"treasure collected: "<< c.tcounter <<endl;
    }
    cout<<endl;

    return o;
}



ostream& operator<<(ostream& o,const monstParty& m){
    for (int i = 0; i< m.size; i++){
        o<<"Monster "<< i << ": ";
        m.mob[i].stats();
    }
    o<<endl;

    return o;
}


void charParty::Death(){
    character temp;
    for (int i = 0;i < size; i++){
        if (player[i].getHealth() <= 0){
            temp = player[i];
            for (int j = i; j < size; j++){
                player[j] = player[j+1];
            }
            player[size - 1] = temp;
            size--;
        }
    }
}

void charParty:: Tcounter(){
    //adding current treasure count with new treasure
    int num = (rand()%10) +1;
    setTcounter(num + getTcounter());
}

void charParty:: setX(int x){
    xcoord = x;
}

void charParty:: setY(int y){
    ycoord = y;
}

void charParty::setTcounter(int t){
    tcounter = t;
}

int charParty::getX(){
    return xcoord;
}

int charParty::getY(){
    return ycoord;
}
int charParty::getTcounter(){
    return tcounter;
}


void monstParty:: setX(int x){
    xcoord = x;
}

void monstParty:: setY(int y){
    ycoord = y;
}

int monstParty::getX(){
    return xcoord;
}

int monstParty::getY(){
    return ycoord;
}






