#include "board.h"
DungeonBoard::DungeonBoard(int _size=10):maxTreasures(_size/2),maxMobs(_size) {
	srand(time(0));
	size = _size;
	c.makeParty();
	//allocate a new board
	boardState = new char*[size];
	for(int i = 0; i < size; i++) {
		boardState[i] = new char[size];
		for(int j = 0; j < size; j++) {
			if(i == 0 || i == size-1) {
				boardState[i][j]= '-';
				continue;
			} else if (j == 0 || j == size-1) {
				boardState[i][j] = '|';
				continue;
			}
			boardState[i][j] = ' ';
		}
	}
	
	//set the entrance
	setupEntrance();
	//set the treasures
	setupTreasure();
	//set the mobs
	setupMobs();
}

DungeonBoard::~DungeonBoard() {
	cout << "Destroying game board state..." << endl;
	for(int i = 0; i < size; i++) {
		delete [] boardState[i];
	}
	delete [] boardState;
	
	cout << "Destroying mob state..." << endl;
	// for(int i = 0; i < numMobs; i++) {
	// 	cout << "Destroying mob " << i << endl;

	// }
	cout << "Destroying mob list..." << endl;
	delete [] mobs;
	
	cout << "Destroying treasure state..." << endl;
	for(int i = 0; i < numTreasures; i++) {
		cout << "Destroying treasure " << i << endl;
		delete [] treasures[i];
	}
	delete [] treasures;
}

ostream& operator<<(ostream& s, const DungeonBoard& db) {
	for(int i = 0; i < db.size; i++) {
		for(int j = 0; j < db.size; j++) {
			s << db.boardState[i][j] << "\t";
		}
		s << endl<<endl;
	}
	
	return s;
}

void DungeonBoard::setupEntrance() {
	//find the entry
	//pick a number 0-3 to figure out what wall the entrance will be on
	int wall = rand()%4;
	//pick a number 1-8 to figure out what position on that wall the entrance will be at (this keeps the door from being in a corner)
	int pos = rand()%(size-2) + 1;
	switch(wall) {
		case 0:
			boardState[pos][0] = 'X';
			c.setX(0);
			c.setY(pos);
			boardState[pos-1][0] = '-';
			boardState[pos+1][0] = '-';
			break;
		case 1:
			boardState[0][pos] = 'X';
			c.setX(pos);
			c.setY(0);
			boardState[0][pos-1] = '|';
			boardState[0][pos+1] = '|';
			break;
		case 2:
			boardState[pos][size-1] = 'X';
			c.setX(size-1);
			c.setY(pos);
			boardState[pos-1][size-1] = '-';
			boardState[pos+1][size-1] = '-';
			break;
		case 3:
			boardState[size-1][pos] = 'X';
			c.setX(pos);
			c.setY(size - 1);
			boardState[size-1][pos-1] = '|';
			boardState[size-1][pos+1] = '|';
			break;
	}
}

void DungeonBoard::setupTreasure() {
	numTreasures = rand() % maxTreasures + 1;
	treasures = new int*[numTreasures];
	//int count = rand() % size + 1;
	for(int i = 0; i < numTreasures; i++) {
		//get row
		int count = rand() % 10 + 1;

		int row = rand()%(size-2) + 1;
		//get column
		int column = rand()%(size-2) + 1;
		//place treasures
		boardState[row][column] = 'T';

		treasures[i] = new int[3];
		treasures[i][0] = row;
		treasures[i][1] = column;
		treasures[i][2] = count;

		//treasures[i][2] = count;
		cout << "Allocated treasure " << i << endl; 
	}
}

void DungeonBoard:: move(char shift){

	/*
	0 1 2 3 4
	1
	2
	3
	4
	
	*/
cout<<c;
	if(shift == 'w' || shift == 'W'){

		//if = wall loop for reentry
		if(boardState[c.getY()-1][c.getX()] == '|' || boardState[c.getY()-1][c.getX()] == '-'){
			cout<<"You have hit a wall"<<endl;
			
			boardState[c.getY()][c.getX()] = ' ';
			c.setY(c.getY()-1);
			boardState[c.getY()][c.getX()] = 'X';
				return;
			

		}
		//if = t add treasure
		if(boardState[c.getY()-1][c.getX()] == 'T'){
			//treasure
			numTreasures--;
			c.Tcounter();
			boardState[c.getY()][c.getX()] = ' ';
			c.setY(c.getY()-1);
			boardState[c.getY()][c.getX()] = 'X';

			// for(int i=0;i<numTreasures;i++)
			// {
			// 	if(treasures[i][0]==c.getY()-1)
			// 		if(treasures[i][1]=c.getX())
			// 		{
			// 			//counterTresure+=treasures[i][2]
			// 		}
			// }
		}
/*
		//if = m  combat with monster
		if(boardState[c.getY()-1][c.getX()] == 'M'){
			//combat
			for(int i=0;i<numMobs;i++)
			{
				if(mobs[i][0].getY()==c.getY()-1)
					if(mobs[i].getX()=c.getX())
					{
						//if(!comact(i))
						//	return;
					}
			}
		}
*/
		//else this
		else{
			boardState[c.getY()][c.getX()] = ' ';
			c.setY(c.getY()-1);
			boardState[c.getY()][c.getX()] = 'X';
		}
	}
		/*
		//initiate check
		if(boardState[c.getX()][c.getY()+1] == 'M'){
			for (int i = 0; i < numMobs; i++){
				if(c.getX()== mobs[i].getX() && c.getY()+1 == mobs[i].getY()){
					index = i;
					break;
				}
			}
		}
	*/
	

	else if(shift == 'd' ||shift == 'D' ){
		//wall
		
		
		//if = t add treasure
		if(boardState[c.getY()][c.getX()+1] == 'T'){
			numTreasures--;
			c.Tcounter();
			boardState[c.getY()][c.getX()] = ' ';
			c.setX(c.getX()+1);
			boardState[c.getY()][c.getX()] = 'X';
		}
		//if = m  combat with monster


		//else this
		else{
		boardState[c.getY()][c.getX()] = ' ';
		c.setX(c.getX()+1);
		boardState[c.getY()][c.getX()] = 'X';
		}
	}

	else if(shift == 's' ||shift == 'S' ){
		//if = wall loop for reentry
		
		//if = t add treasure
		if(boardState[c.getY()+1][c.getX()] == 'T'){
			numTreasures--;
			c.Tcounter();
			boardState[c.getY()][c.getX()] = ' ';
			c.setY(c.getY()+1);
			boardState[c.getY()][c.getX()] = 'X';
		}



		//if = m  combat with monster



		//else this
		else{
		boardState[c.getY()][c.getX()] = ' ';
		c.setY(c.getY()+1);
		boardState[c.getY()][c.getX()] = 'X';

		}
	}

	else if(shift == 'a' || shift == 'A' ){
		//if = wall 
		
		//if = t add treasure
		if(boardState[c.getY()][c.getX()-1] == 'T'){
			numTreasures--;
			c.Tcounter();
			boardState[c.getY()][c.getX()] = ' ';
			c.setX(c.getX()-1);
			boardState[c.getY()][c.getX()] = 'X';
		}


		//if = m  combat with monster

		//else this
		else{
		boardState[c.getY()][c.getX()] = ' ';
		c.setX(c.getX()-1);
		boardState[c.getY()][c.getX()] = 'X';
		}
	}

	else{
		cout<<"invalid movement"<<endl;
	}

}


void DungeonBoard::setupMobs() {
	numMobs = rand() % maxMobs + 1;
	mobs = new monstParty[numMobs];
	for(int i = 0; i < numMobs; i++) {
		//get row
		int row = rand()%(size-2) + 1;
		//get column
		int column = rand()%(size-2) + 1;
		//place treasures
		boardState[row][column] = 'M';
		mobs[i].setY(row); //=new int[2];
		mobs[i].setX(column);
		mobs[i][0] = row;
		mobs[i][1] = column;
		cout << "Allocated mob " << i << endl;
	}
}/////////////////////////

//fix wtf he just did
/*
bool DungeonBoard::combact(int pos)
{
	int monsterChoice=0, charChoice;
	while(mons[pos].mons[monsterChoice].getHealth()>0 && 
	c.player[charChoice].getHealth()>0)
	{	cout<<"Run Away or Attack?";
		cin>>choice;

		if(choice==1)
			return false'
		int percent=rand()%100+1;
		int monsterPercent=rand()%100+1;


		if(percent>15)
		{
			mons[pos].mons[monsterChoice].setHealth(mons[pos].mons[monsterChoice].getHealth()-
			c.player[charChoice].getPower());
		}

		if(monsterPercent>50)
		{
			c.player[charChoice].setHealth(c.player[charChoice].getHealth()-
			mobs[pos].mob[monsterChoice].getPower());

		}

		if(mobs[pos].mob[monsterChoice].getHealth()<=0 && mobs[pos].getSize()>0)
		{
			monsterChoice++;
			mobs[pos].setSize(mobs[pos].getSize()-1);
		}
		if(mobs[pos].getSize()==0)
			return true;

		

		if(c.player[charChoice].getHealth()<=0 && c.player[charChoice].getSize()>0)
		{
			charChoice++;
			c.player[charChoice].setSize(c.player[charChoice].getSize()-1)
		}

		if( c.player[charChoice].getSize()==0)
			return false;


	}
}
*/