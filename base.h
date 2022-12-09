#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

class piece{
    
    public:
    //make purely
    void stats();
        
    //setters
    void setPower(int);
    void setHealth(int);

    //getters
    int getPower();
    int getHealth();

    protected:
    int health;
    int power;

    bool deathstatus;
    //
};

class character: public piece{
friend ostream& operator<<(ostream&,const character&);
    public:
    character();

    void stats();

    //setter
    void setPower(int);
    void setHealth(int);

    //getters
    int getPower();
    int getHealth();
    
};

class monster: public piece{
    friend ostream& operator<<(ostream&,const monster&);
    public:
    monster();

    
    void stats();

    //setter
    void setPower(int);
    void setHealth(int);
    void setReward(int);

    //getters
    int getPower();
    int getHealth();
    int getReward();
    private:
    int reward;
};