#pragma once

#include <list>
#include <string>
#include <deque>
#include <vector>
#include <algorithm>
#include "Pokemon.h"
#include "EvolvedPokemon.h"

using namespace std;

class Pokedex
{
private:
	vector<Pokemon*> itemCollection;
public:
	Pokedex();
	//Constructor

	~Pokedex();
	//Desctructor

	vector<Pokemon*>* getItemCollection();
	//Function to get the ItemCollection deque
	//Post Condition: The itemCollection is returned.
};

