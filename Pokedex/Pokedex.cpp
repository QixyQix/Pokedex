#include "Pokedex.h"


Pokedex::Pokedex()
{
}


Pokedex::~Pokedex()
{
}

vector<Pokemon*>* Pokedex::getItemCollection()
{
	return &itemCollection;
}
