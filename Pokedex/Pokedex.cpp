#include "Pokedex.h"


Pokedex::Pokedex()
{
}


Pokedex::~Pokedex()
{
}

bool Pokedex::add(Pokemon& const aPokemon)
{
	try {
		//Add the item to the list
		itemCollection.push_back(aPokemon);
		return true;
	}
	catch (exception e) {
		return false;
	}
}

vector<Pokemon> Pokedex::getItemCollection()
{
	return itemCollection;
}
