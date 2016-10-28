#pragma once
#ifndef pokemon_H
#define pokemon_H

#include<list>
#include<string>

using namespace std;
class Pokemon
{
private:
	int height;
	int weight;
	string name;
	string description;
	int category;
	list<Pokemon> evolution;
public:
	Pokemon();
	//Constructor

	~Pokemon();
	//Desctructor

	bool operator==(Pokemon& aPokemon);
	//Returns true or false if pokemon is identical to the pokemon

	bool operator!=(Pokemon& aPokemon);
	//Returns true or false if pokemon is !identical to the pokemon

	friend ostream& operator << (ostream&,const Pokemon &);
	//Prints the Pokemon's info.
	//Usage: cout << Pokemon << endl;


};

#endif // !