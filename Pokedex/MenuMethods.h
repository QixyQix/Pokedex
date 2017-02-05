#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include <fstream>

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
	//Function that displays the options to search
	//Post Condition: Lets the user to select if they want to search using keyword or height

	void createPokemon();
	//Function that runs the create pokemon wizard
	//Post Condition: A new Pokemon is created and added to the itemCollection deque

	void editPokemon(Pokemon *selectedPokemon);
	//Function that runs the edit Pokemon wizard
	//Post Condition: The pokemon is edited

	void searchPokemon();
	//Function that runs the search Pokemon wizard
	//Pre Condition: The pokedex must have been created and populated with Pokemon or EvolvedPokemon objects
	//Post Condition: All the pokemon that match the user's search terms are displayed

	void searchPokemon(double const lightest, double const heaviest);
	//Function that search for pokemons inbwetteen lightest and heaviest

	
	void displayPokemon(Pokemon *selectedPokemon);
	//Function that displays the pokemon
	//Pre Condition: The user must have selected a pokemon and the *selectedPokemon pointer is valid
	//Post Condition: The pokemon's details are displayed

	void deletePokemon(Pokemon *selectedPokemon);
	//Function that deletes the pokemon
	//Pre Condition: The user must have selected a pokemon and the *selectedPokemon pointer is valid
	//Post Condition: The selected pokemon is removed from pokedex itemcollection

	void sortPokedex();
	//Function that sorts the pokedex vector
	//Pre Condition: The pokedex must have been created and populated with Pokemon or EvolvedPokemon objects
	//Post Condtion: The pokedex is sorted in alphabetical order according to the pokemon name

	void writeDataFile();
	//Function that write the pokedex item collection to the txt file
	//Pre Condition: The pokedex must have been created and populated with Pokemon or EvolvedPokemon objects
	//Post Condition: The PokemonData.txt file is overwritten with the pokemon detais from the itemcollection

	string getEvolution(Pokemon const *selectedPokemon);

	~MenuMethods();
	//Default Destructor
};

