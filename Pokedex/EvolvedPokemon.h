#pragma once

#ifndef H_EvolvedPokemon
#define H_EvolvedPokemon

#include <list>
#include <string>
#include "Pokemon.h"

class EvolvedPokemon : public Pokemon
{
private:
	string evolvedFrom;
public:
	EvolvedPokemon();
	//Default Constructor

	EvolvedPokemon(int h, int w, string n, string d, int c, string e);
	//Constructor
	//Post Condition: Height = h, weight = w, name = n, description = d, category = c, evolvedFrom = e
	
	~EvolvedPokemon();
	//Default Destructor

	void edit(double &h, double &w, string &n, string &d, int &c, string &e);
	//Function to edit the pokemon
	//Post Condition: height = h, weight = w, name = n, description = d, category = c, evolvedFrom = e

	string getEvolvedFrom() const;
	//Function to get the pokemon's evolvedFrom
	//Post Condition: The Pokemon's evolvedFrom is returned

	void setEvolvedFrom(string & e);
	//Function to set the Pokemon's evolvedFrom
	//Post Condition: evolvedFrom = e
};

#endif // !H_EvolvedPokemon
