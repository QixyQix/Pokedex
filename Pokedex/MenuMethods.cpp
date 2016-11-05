#include "MenuMethods.h"

MenuMethods::MenuMethods()
{
	Pokemon newPokemon1 = Pokemon(1.0, 1.0, "Alphy", "Test Pokemon Alpha", 1);
	Pokemon newPokemon2 = Pokemon(2.0, 2.0, "Bety", "Test Pokemon Bety", 2);
	Pokemon newPokemon3 = Pokemon(3.0, 3.0, "Charlie", "Test Pokemon Charlie", 3);
	Pokemon newPokemon4 = Pokemon(4.0, 4.0, "Delta", "Test Pokemon Delta", 3);

	EvolvedPokemon newEvolvedPokemon1 = EvolvedPokemon(1.1, 1.1, "Ace", "Test evolved pokemon alpha",1,"Alphy");
	EvolvedPokemon newEvolvedPokemon2 = EvolvedPokemon(2.2,2.2, "Betsy", "Test evolved pokemon alpha", 1, "Bety");
	EvolvedPokemon newEvolvedPokemon3 = EvolvedPokemon(3.3,3.3, "Charred Charlie", "Test evolved pokemon Charlie", 1, "Charlie");
	EvolvedPokemon newEvolvedPokemon4 = EvolvedPokemon(1.1, 1.1, "Darling", "Test evolved pokemon Delta", 1, "Delta");

	pokedex.add(newPokemon1);
	pokedex.add(newPokemon2);
	pokedex.add(newPokemon3);
	pokedex.add(newPokemon4);

	pokedex.add(newEvolvedPokemon1);
	pokedex.add(newEvolvedPokemon2);
	pokedex.add(newEvolvedPokemon3);
	pokedex.add(newEvolvedPokemon4);

}

void MenuMethods::createPokemon()
{
	cout << "Welcome to the create new pokemon wizard!" << endl;
	dataEntryStr("");
	string name = dataEntryStr("Enter the name of the Pokemon: ");
	string description = dataEntryStr("Enter a description for the Pokemon: ");
	double height = dataEntry("Enter the height of the pokemon (in meters): ");
	double weight = dataEntry("Enter the weight of the pokemon (in kg): ");
	int category = dataEntryInt("Enter the number of the category: ");
	string evolvedFrom = dataEntryStr("Enter the Pokemon it evolved from (hit enter if none): ");
	if (evolvedFrom == "") {
		Pokemon newPokemon = Pokemon(height, weight, name, description, category);
		pokedex.add(newPokemon);
	}
	else {
		EvolvedPokemon newPokemon = EvolvedPokemon(height, weight, name, description, category, evolvedFrom);
		pokedex.add(newPokemon);
	}
	
	
}

void MenuMethods::searchPokemon()
{
	vector<Pokemon> foundPokemon = vector<Pokemon>();
	int noFound = 0;
	dataEntryStr("");
	string keyword = dataEntryStr("Enter a keyword: ");

	for each (Pokemon aPokemon in pokedex.getItemCollection())
	{
		if (aPokemon.getName().find(keyword) != string::npos) {
			//foundPokemon.push_front(aPokemon);
			foundPokemon.push_back(aPokemon);
			noFound++;
			cout << aPokemon.getName()<< endl;
		}
	}
	string test;
	cin >> test;
	
}

double MenuMethods::dataEntry(string const question)
{
	bool error;
	string reply;
	double replyconverted;
	do {
		error = false;

		try {
			cout << question << endl;
			//cin >> reply;
			getline(cin, reply);
			cout << endl;
			replyconverted = stod(reply);
		}
		catch (exception e) {
			cout << "Error: Please enter a valid double value." << endl;
			error = true;
		}

	} while (error);
	return replyconverted;
}

int MenuMethods::dataEntryInt(string const question)
{
	bool error;
	string reply;
	int replyconverted;
	do {
		error = false;

		try {
			cout << question << endl;
			//cin >> reply;
			getline(cin, reply);
			cout << endl;
			replyconverted = stoi(reply);
		}
		catch (exception e) {
			cout << "Error: Please enter a valid double value." << endl;
			error = true;
		}

	} while (error);
	return replyconverted;
}

string MenuMethods::dataEntryStr(string const question)
{
	string reply;
	bool error;

	do {
		error = false;
		try {
			cout << question << endl;
			//cin >> reply;
			getline(cin, reply);
			cout << endl;
		}
		catch (exception e) {
			cout << "Error: Illegal characters." << endl;
			error = true;
		}
	} while (error);
	return reply;
}

MenuMethods::~MenuMethods()
{
}
