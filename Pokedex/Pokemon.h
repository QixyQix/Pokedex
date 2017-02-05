#pragma once

#ifndef H_Pokemon
#define H_Pokemon

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
	//Function to check if 2 Pokemon are the same or not
	//Post Condition: Returns true if height, weight, category, name and description are equal

	bool operator!=(Pokemon& const aPokemon);
	//Function to check if 2 Pokemon are the same or not
	//Post Condition: Returns true if height, weight, category, name and description are !equal

	friend ostream& operator << (ostream&,const Pokemon &);
	//Function to print the Pokemon's info.
	//Usage: cout << Pokemon << endl;

	string getName() const;
	//Function to get the Pokemon's name
	//Post Condition: Pokemon's name is returned

	void setName(string& nm);
	//Function to set the Pokemon's name
	//Post Condition: name = nm

	string getDescription() const;
	//Function to get the Pokemon's description
	//Post Condition: The Pokemon's description is returned
	
	void setDescription(string& desc);
	//Function to set the Pokemon's description
	//Post Condition: description = desc

	double getWeight() const;
	//Function to get the Pokemon's weight
	//Post Condition: The Pokemon's weight is returned

	void setWeight(double& w);
	//Function to set the Pokemon's weight
	//Post Condition: weight = w

	double getheight() const;
	//Function to get the Pokemon's height
	//Post Condition: The Pokemon's height is returned

	void setheight(double& h);
	//Function to set the Pokemon's height
	//Post Condition: height = h

	int getCategory() const;
	//Function to get the Pokemon's category
	//Post Condition: The Pokemon's height is returned

	void setCategory(int& cat);
	//Function to set the Pokemon's Category
	//Post Condition: category = cat

	virtual string getEvolvedFrom() const;
	//Function to get the Pokemon's evolvedFrom
	//Post Condition: Returns ""

	virtual void setEvolvedFrom(string& pokemonName);
	//Function to set the Pokemon's evolvedFrom
	//Pre condition: pokemonName cannot be null
	//Post Condition: Nothing happens.

	virtual void edit(double &h, double &w,string &n, string &d, int& c, string& e);
	//Function to edit the pokemon
	//Post Condition: height = h, weight = w, name = n, description = d, category = c


};

#endif // !H_Pokemon