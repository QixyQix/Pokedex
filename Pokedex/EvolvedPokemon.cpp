#include "EvolvedPokemon.h"



EvolvedPokemon::EvolvedPokemon()
{
}

EvolvedPokemon::EvolvedPokemon(int h, int w, string n, string d, int c, string e) : Pokemon(h, w, n, d, c)
{
	evolvedFrom = e;
}


EvolvedPokemon::~EvolvedPokemon()
{
}
