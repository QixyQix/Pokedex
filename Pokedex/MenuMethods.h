#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <utility>

#include "Pokemon.h"
#include "EvolvedPokemon.h"
#include "Pokedex.h"

using namespace std;

class MenuMethods
{
private:
	Pokedex pokedex; //Variable to store the pokedex object
public:
	MenuMethods();
	//Default Constructor
	
	double dataEntry(string const question);
	//Function for that prints the queston and validates the user input
	//Post Condition: The user's input is returned as a double

	int dataEntryInt(string const question);
	//Function for that prints the queston and validates the user input
	//Post Condition: The user's input is returned as a int
	
	string dataEntryStr(string const question);
	//Function for that prints the queston and validates the user input
	//Post Condition: The user's input is returned as a string

	bool ifExists(string const pokemonName);
	//Function for that checks if the pokemon exists in the Pokedex itemCollection
	//Post Condition: Returns true if the pokemon exists in the pokedex

	void searchMenu();

	void createPokemon();
	//Function that runs the create pokemon wizard
	//Post Condition: A new Pokemon is created and added to the itemCollection deque

	void editPokemon(Pokemon *selectedPokemon);
	//Function that runs the edit Pokemon wizard
	//Post Condition: The pokemon is edited

	void searchPokemon();
	//Function that runs the search Pokemon wizard
	//Post Condition: All the pokemon that match the user's search terms are displayed
	
	void displayPokemon(Pokemon *selectedPokemon);
	//Function that displays the pokemon
	//Post Condition: The pokemon's details are displayed

	void deletePokemon(Pokemon *selectedPokemon);
	//Function that deletes the pokemon
	//Post Condition: The selected pokemon is removed from pokedex itemcollection

	~MenuMethods();
	//Default Destructor
};

