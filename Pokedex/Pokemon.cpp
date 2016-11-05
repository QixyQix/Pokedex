#include "Pokemon.h"
#include <iostream>
#include <string>


Pokemon::Pokemon(double h, double w, string n, string d, int c)
{
	height = h;
	weight = w;
	name = n;
	description = d;
	category = c;
}

Pokemon::~Pokemon()
{
}


bool Pokemon::operator==(Pokemon& aPokemon)
{
	return(height == aPokemon.height &&
		weight == aPokemon.weight &&
		category == aPokemon.category &&
		(name.compare(aPokemon.name) == 0) &&
		(description.compare(aPokemon.description) == 0));

	//Not entirely sure if aPokemon.evolution == can or not LOL
	//pretty surprised no squiggly lines.
}

bool Pokemon::operator!=(Pokemon & aPokemon)
{
	return !(height == aPokemon.height &&
		weight == aPokemon.weight &&
		category == aPokemon.category &&
		(name.compare(aPokemon.name) == 0) &&
		(description.compare(aPokemon.description) == 0));
}

string Pokemon::getName()
{
	return name;
}

ostream & operator<<(ostream & osObject, const Pokemon & aPokemon)
{
	//Print out the name
	osObject << "=== " << aPokemon.name << " ===" << endl;
	//Print out the description
	osObject << "Description: " << endl << aPokemon.description << endl;
	//Print out the category
	osObject << "Category: " << aPokemon.category << endl;
	//Print out the Height
	osObject << "Height: " << aPokemon.height << endl;
	//Print out the Weight
	osObject << "Weight: " << aPokemon.weight << endl;
	//TODO: EVOLUTION

	return osObject;
}
