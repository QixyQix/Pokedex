#pragma once

#include <list>
#include <string>
#include <deque>
#include <algorithm>
#include "Pokemon.h"

using namespace std;

class Pokedex
{
private:
	deque<Pokemon> itemCollection;
public:
	Pokedex();
	//Constructor

	~Pokedex();
	//Desctructor

	bool add(Pokemon& const aPokemon);
	//Function that adds a pokemon into the itemcollection collection.
	//Returns a true/false
	//True: Pokemon added successfully
	//False: Error occured while adding pokemon

	deque<Pokemon> getItemCollection();
	//Function to get the ItemCollection deque
	//Post Condition: The itemCollection is returned.
};

