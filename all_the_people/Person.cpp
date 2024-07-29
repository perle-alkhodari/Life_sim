#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "UI.cpp"

using namespace std;

class Person
{
	int age;
	int height;
	int weight;
	string gender;
	string name;

	int energy;
	int social;
	int rest;
	int fun;

	enum food {
		Apple,
		FruitSalad,
		GardenSalad,
		GrilledCheeseSandwich,
		Pasta,
		ChickenRice,
		KebbahBelLaban
	};

	enum socialInteraction {
		TextFriend,
		CallFriend,
		PlayGamesOnline,
		MeetUpWithFriend,
		Gathering
	};

	enum resting {
		CloseEyes,
		Nap,
		Sleep,
		Hybernate
	};

	enum play {
		PlayChess,
		WatchTV,
		PlayVideoGames
	};

	enum choices {
		MeetPlayer,
		EatSomething,
		eSocialise,
		eRest,
		ePlay
	};
	
public:
	// Default constructor.
	Person()
	{
		vector<string> femaleNames = { "Angela", "Perle", "Jenna", "Kari" };
		vector <string> maleNames = { "David", "Austin", "Aaron" };

		srand(time(NULL));
		int randomNum = 1 + rand() % 2;
		int randomBinary = randomNum - 1;
		int randomFemaleName = (1 + rand() % (femaleNames.size())) - 1;
		int randomMaleName = (1 + rand() % (maleNames.size())) - 1;

		age = 30;
		height = 175;
		weight = 80;
		gender = randomBinary ? "Female" : "Male";
		name = randomBinary ? femaleNames.at(randomFemaleName) : maleNames.at(randomMaleName);

		energy = 20;
		social = 20;
		rest = 20;
		fun = 20;
	}

	// Constructor.
	Person(int _age, int _height, int _weight, string _gender, string _name)
	{
		age = _age;
		height = _height;
		weight = _weight;
		gender = _gender;
		name = _name;

		energy = 20;
		social = 20;
		rest = 20;
		fun = 20;
	}

	// Accessors.
	int GetAge()
	{
		return age;
	}

	int GetHeight()
	{
		return height;
	}

	int GetWeight()
	{
		return weight;
	}

	int GetEnergy()
	{
		return energy;
	}

	int GetSocial()
	{
		return social;
	}

	int GetRest()
	{
		return rest;
	}

	int GetFun()
	{
		return fun;
	}

	string GetName()
	{
		return name;
	}

	string GetGender()
	{
		return gender;
	}

	// Modifiers.
	void SetAge(int _age)
	{
		age = _age;
	}

	void Setheight(int _height)
	{
		height = _height;
	}

	void SetWeight(int _weight)
	{
		weight = _weight;
	}

	void SetGender(int _gender)
	{
		gender = _gender;
	}

	void SetName(int _name)
	{
		name = _name;
	}

	void CapEnergy()
	{
		energy = 30;
	}

	void CapRest()
	{
		rest = 30;
	}

	void CapFun()
	{
		fun = 30;
	}

	void CapSocial()
	{
		social = 30;
	}

	// Methods.
	void Birthday()
	{
		age++;
		cout << "Yay it's my birthday! I'm " << age << " years old now." << endl;
	}

	void Eat(int choice)
	{
		switch (choice)
		{
		case Apple:
		case FruitSalad:
		case GardenSalad:
			energy += 5;
			rest -= 2;
			fun -= 1;
			break;
		case GrilledCheeseSandwich:
			energy += 7;
			break;
		case Pasta:
		case ChickenRice:
			energy += 15;
			rest -= 5;
			break;
		case KebbahBelLaban:
			energy += 20;
			rest -= 5;
			fun += 3;
			break;
		}
	}

	void Rest(int choice)
	{
		switch (choice)
		{
		case CloseEyes:
			rest += 1;
			fun -= 5;
			break;
		case Nap:
			rest += 10;
			fun -= 3;
			break;
		case Sleep:
			rest += 20;
			fun -= 2;
			break;
		case Hybernate:
			rest += 30;
			fun -= 10;
			energy -= 15;
			break;
		}
	}

	void Fun(int choice)
	{
		switch (choice)
		{
		case PlayChess:
			fun += 5;
			social -= 5;
			energy -= 7;
			break;
		case WatchTV:
			fun += 10;
			social -= 3;
			break;
		case PlayVideoGames:
			fun += 15;
			energy -= 5;
			rest -= 3;
			break;
		}
	}

	void Socialise(int choice)
	{
		switch (choice)
		{
		case TextFriend:
			social += 1;
			break;
		case CallFriend:
			social += 3;
			break;
		case PlayGamesOnline:
			social += 5;
			break;
		case MeetUpWithFriend:
			social += 10;
			energy -= 10;
			break;
		case Gathering:
			social += 20;
			break;
		}
	}

	// Display Methods.
	void DisplayIntroduction(Person person)
	{
		cout << "Meet " << person.GetName() << "!\n" << endl;
		person.DisplayPerson(person);
		cout << "\nPress any key to continue..." << endl;
		cin.get();
		UI::ClearScreen();
	}

	void DisplayDialogue(string dialogue)
	{
		cout << dialogue << endl;
	}

	void DisplayPerson(Person person)
	{
		cout << "Name:    " << person.GetName() << endl;
		cout << "Age:     " << person.GetAge() << "yrs" << endl;
		cout << "Gender:  " << person.GetGender() << endl;
		cout << "Height:  " << person.GetHeight() << "cm" << endl;
		cout << "Weight:  " << person.GetWeight() << "kg" << endl;
	}

	int DisplayChoices(Person person, vector<string> choices)
	{
		string userChoice;
		int choice = 0;
		bool invalidInput = true;

		do
		{
			UI::ClearScreen();
			cout << "What will " << person.GetName() << " do now?\n" << endl;

			for (int i = 0; i < choices.size(); i++)
			{
				cout << "[" << i+1 << "]" << " " << choices.at(i) << endl;
			}

			cout << endl;

			DisplayStats(person);
			cout << "\nChoice: ";
			cin >> userChoice;
			try
			{
				choice = stoi(userChoice);
				invalidInput = false;
			}
			catch (...)
			{
				choice = 0;
			};

			if (choice == 0 || choice >= (choices.size() + 1))
			{
				invalidInput = true;
			}
			else
			{
				invalidInput = false;
			}

		} while (invalidInput);
	
		return (choice - 1);
	}

	void DisplayStats(Person person)
	{
		cout << person.GetName() << "'s MoodBar:\n" << endl;

		// Energy
		cout << " Energy" << endl;
		cout << "|";
		for (int i = 0; i < 30; i++)
		{
			if (i < person.GetEnergy())
			{
				cout << "-";
			}
			else
			{
				cout << " ";
			}
		}
		cout << "|" << endl;

		// Rest
		cout << " Rest" << endl;
		cout << "|";
		for (int i = 0; i < 30; i++)
		{
			if (i < person.GetRest())
			{
				cout << "-";
			}
			else
			{
				cout << " ";
			}
		}
		cout << "|" << endl;

		// Social
		cout << " Social" << endl;
		cout << "|";
		for (int i = 0; i < 30; i++)
		{
			if (i < person.GetSocial())
			{
				cout << "-";
			}
			else
			{
				cout << " ";
			}
		}
		cout << "|" << endl;

		// Fun
		cout << " Fun" << endl;
		cout << "|";
		for (int i = 0; i < 30; i++)
		{
			if (i < person.GetFun())
			{
				cout << "-";
			}
			else
			{
				cout << " ";
			}
		}
		cout << "|" << endl;
	}

	// Events
	void Event(Person person, vector<string> things, vector<string> feedback, int choice)
	{

		int choiceOfThing;
		int randomChoice = (1 + rand() % feedback.size()) - 1;

		choiceOfThing = person.DisplayChoices(person, things);
		switch (choice)
		{
		case EatSomething:
			Eat(choiceOfThing);
			break;
		case eSocialise:
			Socialise(choiceOfThing);
			break;
		case eRest:
			Rest(choiceOfThing);
			break;
		case ePlay:
			Fun(choiceOfThing);
			break;
		}
		
		UI::ClearScreen();
		cout << feedback.at(randomChoice) << endl;
		cin.get();
	}

	bool CheckStatus(Person person)
	{
		bool isAlive = true;

		if (person.GetRest() > 30)
		{
			person.CapRest();
		}
		else if (person.GetEnergy() > 30)
		{
			person.CapEnergy();
		}
		else if (person.GetFun() > 30)
		{
			person.CapFun();
		}
		else if (person.GetSocial() > 30)
		{
			person.CapSocial();
		}

		if (person.GetEnergy() < 0 || person.GetRest() < 0)
		{
			UI::ClearScreen();
			cout << "You lose. " + person.GetName() << " has died due to a lack of energy/rest.";
			isAlive = false;
		}

		return isAlive;
	}
};