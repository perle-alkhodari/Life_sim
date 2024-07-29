#include <iostream>
#include <string>
#include "Person.cpp"

using namespace std;

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
	Socialise,
	Rest,
	Play
};

int main()
{
	int choice;
	int choiceEat;
	int choiceSocialise;
	int choiceRest;
	int choicePlay;
	bool isOn = true;

	Person defaultPerson;
	defaultPerson.DisplayIntroduction(defaultPerson);

	vector<string> food = {
						"Apple",
						"Fruit Salad",
						"Garden Salad",
						"Grilled Cheese Sandwich",
						"Pasta",
						"Chicken Rice",
						"Kebba Bel Laban"
	};

	vector<string> foodFeedback = {
		"Yummy! (It appears that " + defaultPerson.GetName() + " enjoyed their meal!",
		"Nam nam nam! (" + defaultPerson.GetName() + " is namming away...)",
		"mmmmmmmhhh... (" + defaultPerson.GetName() + " is too busy eating their food...)",
		"STELLAR! (That was really satisfying for " + defaultPerson.GetName() + "!)"
	};

	vector<string> social = {
		"Text Friend",
		"Call Friend",
		"Play Games Online",
		"Meet Up With Friend",
		"Gathering"
	};

	vector<string> socialFeedback = {
		"Worth it!",
		"I feel more connected to the outside world now...",
		"My friends are awesome..."
	};

	vector<string> rest = {
		"Close Eyes",
		"Nap",
		"Sleep",
		"Hibernate"
	};

	vector<string> restFeedback = {
		"I feel amazing...",
		"Holy shit, I needed that...",
		"uuuuuuuuuuuuuuuuuuuuhhhhhhmmmmmmmm...."
	};

	vector<string> play = {
		"Play Chess",
		"Watch TV",
		"Play Video Games"
	};

	vector<string> playFeedback = {
		"That was fun!",
		"WOOOH nice!"
	};

	while (isOn)
	{
		// Choices
		vector<string> choices = { "Meet " + defaultPerson.GetName(), "Eat something", "Socialise", "Rest", "Play" };
		choice = defaultPerson.DisplayChoices(defaultPerson, choices);
		cout << choice;

		switch (choice)
		{
		case MeetPlayer:
			cout << "no Idea what's going on here but ok..." << endl;
			break;
		case EatSomething:
			defaultPerson.Event(defaultPerson, food, foodFeedback, choice);
			break;
		case Socialise:
			defaultPerson.Event(defaultPerson, social, socialFeedback, choice);
			break;
		case Rest:
			defaultPerson.Event(defaultPerson, rest, restFeedback, choice);
			break;
		case Play:
			defaultPerson.Event(defaultPerson, play, playFeedback, choice);
			break;
		}
		
		isOn = defaultPerson.CheckStatus(defaultPerson);
	}
	//defaultPerson.DisplayIntroduction(defaultPerson);
}