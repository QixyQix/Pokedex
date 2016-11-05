#pragma once
#include<list>
#include<string>

using namespace std;
class Pokemon
{
private:
	double height;
	double weight;
	string name;
	string description;
	int category;
public:
	Pokemon(double h = 0, double w = 0, string n = "unnamed", string d = "No Description", int c = 0);

	~Pokemon();
	//Desctructor

	bool operator==(Pokemon& const aPokemon);
	//Returns true or false if pokemon is identical to the pokemon

	bool operator!=(Pokemon& const aPokemon);
	//Returns true or false if pokemon is !identical to the pokemon

	friend ostream& operator << (ostream&,const Pokemon &);
	//Prints the Pokemon's info.
	//Usage: cout << Pokemon << endl;

	string getName();

};