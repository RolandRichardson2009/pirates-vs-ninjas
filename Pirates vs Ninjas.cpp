#include <iostream>//This allows for using cout and cin
using namespace std;//This allows for using cout and cin and string

////////////////////////////////////////////////////////////////////////////
//BEGIN CLASSES
////////////////////////////////////////////////////////////////////////////

//This is a base class that is never instantiated.
class GameStructure
{
public:
	virtual void Help() {}
};

//This is a base class that is never instantiated.
class Character : public GameStructure
{
private:
	int Health;//private variable for health
public:
	string Name;
	virtual void Help() {}//Empty Help Function
	virtual void Talk(string stuffToSay)//talk function taking 1 argument
	{
		cout << Name + ": " + stuffToSay << endl;
	}
	virtual void Talk(string name, string stuffToSay)//talk function taking 2 argument
	{
		cout << name + ": " + stuffToSay << endl;
	}

	virtual int attack()//attack function
	{
		return 10;
	}

	//get function to return private variable
	virtual int getHealth()
	{
		return Health;
	}
	
	//set function to set private variable
	virtual void setHealth(int healthVar)
	{
		if (healthVar <= 0)//check if character has died and set health to 0
		{
			Health = 0;
			cout << "Character has Expired..." << endl;
		}
		else //Update health
		{
			Health = healthVar;
		}
	}
};
//This class is for the enemys
class Ninja :public Character
{
public:
	//Constructor
	Ninja(string nameVar, int healthVar)
	{
		Name = nameVar;
		setHealth(healthVar);
	}
	void Help()
	{
		cout << "Ninja's are really cool, can you can use them to throw stars!" << endl;
	}
	int attack()
	{
		return 25;
	}
	int ThrowStars()
	{
		cout << "I am throwing stars!" << endl;
		return attack();
	}
};
//This class is for the player
class Pirate :public Character
{
public:
	//Constructor
	Pirate(string nameVar, int healthVar)
	{
		Name = nameVar;
		setHealth(healthVar);
	}
	Pirate()
	{
		setHealth(100);
	}
	void Help()
	{
		cout << "Pirate's are really cool, can you can use them to swing swords!" << endl;
	}
	//Function for the pirate attack
	int attack()
	{
		return 25;
	}
	int UseSword()
	{
		cout << "I am Swooshing my Sword!" << endl;
		return attack();
	}
};

////////////////////////////////////////////////////////////////////////////
//END CLASSES
////////////////////////////////////////////////////////////////////////////

int main()
{

	//variables listed for later use
	Pirate playerVar(" ", 100);
	Ninja newEnemyAppearsVar(" ", 100);
	int playerHealthVar = -1;
	int enemyHealthVar = -1;
	int* playerHealthVarPtr = &playerHealthVar;
	int* enemyHealthVarPtr = &enemyHealthVar;
	Pirate* playerVarPtr = &playerVar;
	Ninja* newEnemyAppearsVarPtr = &newEnemyAppearsVar;
	
	cout << "Are you ready for an intense game about pirates and ninjas? Get ready for an intense battle!" << endl;
	system("pause");//system pause asking user to press any key to continue.

	char userInputVar = ' ';//Place this variable outside of main loop so it can be used as an exit condition for the loop
	//The reason we are using a char instead of an int is to 
	//prevent exceptions being thrown for the user entering 
	//something other than an int.

	do//Begin main game loop
	{
		system("cls");//clears console for a clean view to prepare for current section.

		//Display menu to user
		cout << "1. Create a character." << endl;
		cout << "2. Display your stats." << endl;
		cout << "3. Attack." << endl;
		cout << "4. Exit game." << endl;

		cin >> userInputVar;//Get User Input for menu
		string playerNameVar = " ";
		Ninja* newEnemyAppearsVarPtr = new Ninja("Tina", 75);
		switch (userInputVar)//Process user's choice and display respective menu.
		{
		case '1':
			cout << "Please enter your name:" << endl;
			
			cin >> playerNameVar;
			playerVarPtr = new Pirate(playerNameVar, 100);
			playerVarPtr->Talk("Stand back you fool!!!");
			system("pause");
			break;//Break out of case and back to main game loop
		case '2':
			cout << playerVarPtr->getHealth() << endl;
			system("pause");
			break;//Break out of case and back to main game loop
		case '3':
			enemyHealthVar = newEnemyAppearsVarPtr->getHealth();
			
			do 
			{
				system("cls");
				cout << "Player attacks Ninja: " << endl;
				newEnemyAppearsVarPtr->setHealth(enemyHealthVar -= playerVarPtr->UseSword());
				if (newEnemyAppearsVarPtr->getHealth() < 1)
				{
					break;
				}
				system("pause");
				cout << "Ninja attacks Player: " << endl;
				*playerHealthVarPtr = playerVarPtr->getHealth();
				playerVarPtr->setHealth(*playerHealthVarPtr -= newEnemyAppearsVarPtr->ThrowStars());
				if (playerVarPtr->getHealth() < 1)
				{
					break;
				}
				system("pause");
			} while (newEnemyAppearsVarPtr->getHealth() > 0 || playerVarPtr->getHealth() > 0);
			cout << "battle is finished." << endl;

			system("pause");
			break;//Break out of case and back to main game loop
		case '4':
			system("cls");//clears console for a clean view to prepare for current section.
			cout << "Thanks for playing Pirates vs Ninjas!" << endl;
			break;//Break out of case and back to main game loop
		default:
			system("cls");//clears console for a clean view to prepare for current section.
			cout << "That is not a valid choice. Please try again." << endl;
			system("pause");//system pause asking user to press any key to continue.
			break;//Break out of case and back to main game loop
		}
	} while (userInputVar != '4');//Exit game loop when user enters the character 4.
	return 0;
}

