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
		itemCollection.push_front(aPokemon);
		return true;
	}
	catch (exception e) {
		return false;
	}
}

deque<Pokemon> Pokedex::getItemCollection()
{
	return itemCollection;
}
