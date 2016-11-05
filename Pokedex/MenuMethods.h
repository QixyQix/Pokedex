#pragma once
#include <string>
#include <iostream>
#include <vector>

#include "Pokemon.h"
#include "EvolvedPokemon.h"
#include "Pokedex.h"

using namespace std;

class MenuMethods
{
private:
	Pokedex pokedex;
public:
	MenuMethods();
	
	double dataEntry(string const question);

	int dataEntryInt(string const question);
	
	string dataEntryStr(string const question);

	void createPokemon();

	void searchPokemon();

	~MenuMethods();
};

