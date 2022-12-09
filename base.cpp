#include "base.h"


character::character(){
    health = 80 + (rand() % 21);
    power = 4 + (rand() % 7);
    deathstatus = false;
}


monster::monster(){
    health = 15 + (rand() % 21);
    power = 1 + (rand() % 6);
    reward = 15 + (rand() % 21);
    deathstatus = false;
}

/////////////////warning testing inheritance shit

//void base:: stats

//////////



void character::stats(){
    cout<<endl;
    cout<<"Health "<< health<<endl;
    cout<<"Power: "<< power<<endl;
}


// ostream& operator<<(ostream& o,character& c ){
//     o<<"Health "<< c.health<<endl;
//     o<<"Power: "<< c.power<<endl;

//     return o;
// }

void monster:: stats(){
    cout<<"monster health: "<< health<<endl;
    cout<<"monster power: "<< power<<endl;
    cout<<"monster possible reward: "<< reward<<endl;
}


//setter
void character::setPower(int p){
    power = p;
}
void character::setHealth(int h){
    health = h;
}

//getters
int character:: getPower(){
    return power;
}
int character::getHealth(){
    return health;
}

void monster::setReward(int r){
    reward = r;
}

int monster::getReward(){
    return reward;
}