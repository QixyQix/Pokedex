#pragma once

#include <list>
#include <string>
#include "Pokemon.h"

class EvolvedPokemon : public Pokemon
{
private:
	string evolvedFrom;
public:
	EvolvedPokemon();
	EvolvedPokemon(int h, int w, string n, string d, int c, string e);
	~EvolvedPokemon();
};

