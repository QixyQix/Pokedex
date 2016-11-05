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
		//Use push_front to add into the list.
		//push front adds it behind the latest item.
		//push back adds it infront the oldest item.
		//Use pop to remove the item.
		//same thine with popfront and back
		itemCollection.push_front(aPokemon);
		return true;
	}
	catch (exception e) {
		return false;
	}
}

bool Pokedex::edit(Pokemon & aPokemon)
{
	return false;
}

void Pokedex::display(int start, int end) const
{
	
}

list<Pokemon> Pokedex::getItemCollection()
{
	return itemCollection;
}
