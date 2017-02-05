#include "Pokemon.h"
#include <iostream>
#include <string>


Pokemon::Pokemon(double h, double w, string n, string d, int c)
{
	//Set height
	height = h;
	//Set weight
	weight = w;
	//Set name
	name = n;
	//Set description
	description = d;
	//Category
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

string Pokemon::getName() const
{
	return name;
}

void Pokemon::setName(string & nm)
{
	name = nm;
}

string Pokemon::getDescription() const
{
	return description;
}

void Pokemon::setDescription(string & desc)
{
	description = desc;
}

double Pokemon::getWeight() const
{
	return weight;
}

void Pokemon::setWeight(double & w)
{
	weight = w;
}

double Pokemon::getheight() const
{
	return height;
}

void Pokemon::setheight(double & h)
{
	height = h;
}

int Pokemon::getCategory() const
{
	return category;
}

void Pokemon::setCategory(int & cat)
{
	category = cat;
}

string Pokemon::getEvolvedFrom() const
{
	return "";
}

void Pokemon::setEvolvedFrom(string &pokemonName)
{
}

void Pokemon::edit(double & h, double & w, string & n, string & d, int& c, string &e)
{
	height = h; //Set height
	weight = w; //Set weight
	name = n; //Set name
	description = d; //Set description
	category = c; //Set category
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

	return osObject;
}
