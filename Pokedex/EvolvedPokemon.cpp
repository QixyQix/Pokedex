#include "EvolvedPokemon.h"

EvolvedPokemon::EvolvedPokemon()
{
}

EvolvedPokemon::EvolvedPokemon(int h, int w, string n, string d, int c, string e) : Pokemon(h, w, n, d, c)
{
	//Set evolvedFrom = e
	evolvedFrom = e;
}


EvolvedPokemon::~EvolvedPokemon()
{
}

void EvolvedPokemon::edit(double & h, double & w, string & n, string & d, int & c, string & e)
{
	//Set height
	setheight(h);
	//Set weight
	setWeight(w);
	//Set Name
	setName(n);
	//Set Description
	setDescription(d);
	//Set Category
	setCategory(c);
	//Set evolved From
	evolvedFrom = e;
}

string EvolvedPokemon::getEvolvedFrom() const
{
	return evolvedFrom;
}

void EvolvedPokemon::setEvolvedFrom(string & e)
{
	evolvedFrom = e;
}

ostream & operator<<(ostream & osObject, const EvolvedPokemon & aPokemon)
{
	//Print out the name
	osObject << "=== " << aPokemon.getName() << " ===" << endl;
	//Print out the description
	osObject << "Description: " << endl << aPokemon.getDescription() << endl;
	//Print out the category
	osObject << "Category: " << aPokemon.getCategory() << endl;
	//Print out the Height
	osObject << "Height: " << aPokemon.getheight() << endl;
	//Print out the Weight
	osObject << "Weight: " << aPokemon.getWeight() << endl;
	//Print out the evolution
	osObject << "Evolved from: " << aPokemon.getEvolvedFrom() << endl;

	return osObject;
}
