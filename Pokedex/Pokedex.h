#pragma once

#include <list>
#include <string>
#include "Pokemon.h"

using namespace std;

class Pokedex
{
private:
	list<Pokemon> itemCollection;
public:
	Pokedex();
	//Constructor

	~Pokedex();
	//Desctructor

	bool add(Pokemon& aPokemon);
	//Adds a pokemon into the itemcollection collection.
	//Returns a true/false
	//True: Pokemon added successfully
	//False: Error occured while adding pokemon

	bool edit(Pokemon& aPokemon);
	//Edits a pokemon
	//Returns a true/false

	void display(int start, int end) const;
};

