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
