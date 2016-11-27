#include <iostream>
#include "Pokemon.h"
#include "Pokedex.h"
#include "MenuMethods.h"
using namespace std;

void main() {
	MenuMethods methods; //MenuMethods object
	string input; //String for user input
	int inputConvert = 0; //Int for input converted
	bool error = false; //Boolean for error
	bool noExit = true; //Boolean for exit

	do { //Start do...while for menu

		//Prompt user
		cout << "Welcome to the Pokedex! What would you like to do" << endl;
		cout << "1. Search Pokemon" << endl;
		cout << "2. Create a new Pokemon" << endl;
		cout << "3. Exit Program" << endl;
		do { //Start do...while for user input
			cout << "Enter the corresponding number: ";
			error = false; //Initialize error as false
			cin >> input; //Get the user input

			try {
				inputConvert = stoi(input); //Try to convert the number
			}
			catch (exception e) {
				cout << "Error: Please enter a valid number" << endl;
				error = true; //Set to true so it will loop
			}

			//Check if witin range
			if (inputConvert < 1 || inputConvert > 3) {
				cout << "Error: Number is out of scope." << endl;
				error = true; //Set to true so it will loop
			}
		} while (error); //End do...while for user input

		switch (inputConvert)
		{
		case 1: //Search for pokemon program
			methods.searchPokemon();
			break;
		case 2: //Create new pokemon program
			methods.createPokemon();
			break;
		case 3: //Exit program
			noExit = false; //Set noExit to false so program exits
			break;
		}
	} while (noExit); //End do...while for menu
}