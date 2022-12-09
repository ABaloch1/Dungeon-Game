#include<iostream>
#include <ctime>
#include <cstdlib>
#include "party.h"

using namespace std;
class DungeonBoard {
    friend ostream& operator<<(ostream& s, const DungeonBoard& db);
    public:
        DungeonBoard(int _size);
        ~DungeonBoard();

        bool combat(int pos);
        void move(char shift);

/*creating attack functionality
want probabtility calculator
need character attack monster
need monster attacking character
house under combat
need looping funcitonality
end game status
*/
    
    private:
    //data
        const int maxTreasures;
        int numTreasures;
        const int maxMobs;
        int numMobs;
        int size;
        char** boardState;
        int** treasures;
        //fix this .
        monstParty* mobs;
        charParty c;
        
    //entrance
        int x_enter;
        int y_enter;
    //exit
        int x_exit;
        int y_exit;
    //functionality
        void setupEntrance();
        void setupTreasure();
        void setupMobs();
};