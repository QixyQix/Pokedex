#include "MenuMethods.h"

MenuMethods::MenuMethods()
{
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
	//vector<Pokemon> foundPokemon = vector<Pokemon>();
	//int noFound = 0;
	//string keyword = dataEntryStr("Enter a keyword: ");

	//for each (Pokemon aPokemon in pokedex.getItemCollection)
	//{
	//	if (aPokemon.getName().find(keyword) != string::npos) {
	//		//foundPokemon.push_front(aPokemon);
	//		foundPokemon.push_back(aPokemon);
	//		noFound++;
	//		cout << aPokemon.getName()<< endl;
	//	}
	//}
	
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
