#include <iostream>
#include "Pokemon.h"
#include "Pokedex.h"
#include "MenuMethods.h"
using namespace std;

void main() {
	MenuMethods methods;
	string input;
	int inputConvert = 0;
	bool error = false;

	cout << "Welcome to the Pokedex! What would you like to do" << endl;
	cout << "1. Search Pokemon" << endl;
	cout << "2. Create a new Pokemon" << endl;
	cout << "3. Exit Program" << endl;
	do {
		cout << "Enter the corresponding number: ";	
		error = false;
		cin >> input;

		try {
			inputConvert = stoi(input);
		}
		catch (exception e) {
			cout << "Error: Please enter a valid number" << endl;
			error = true;
		}

		if (inputConvert < 1 || inputConvert > 2) {
			cout << "Error: Number is out of scope." << endl;
			error = true;
		}
	} while (error);

	switch (inputConvert)
	{
	case 1: //Search for pokemon program
		methods.searchPokemon();
		break;
	case 2: //Create new pokemon program
		methods.createPokemon();
		break;
	default:
		break;
	}
}