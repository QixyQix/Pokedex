#include "MenuMethods.h"

MenuMethods::MenuMethods()
{
	//Declare the in file
	ifstream inFile;
	//Open the file
	inFile.open("PokemonData.txt");
	//while it is not the end of file
	while (!inFile.eof()) {
		//Declare variables needed
		string line;
		string name;
		string desc;
		string heightStr;
		string weightStr;
		double height;
		double weight;
		string categoryStr;
		int category;
		string evolvedFrom;

		//get the line
		getline(inFile, name);
		//check if it marks the end of the file
		if (name.compare("END") != 0) {
			getline(inFile, desc); //Get the description
			getline(inFile, heightStr); //Get the height
			getline(inFile, weightStr); //Get the weight
			getline(inFile, categoryStr); //Get the category
			getline(inFile, evolvedFrom); //Get the evolved from

			//Convert to the types
			height = stod(heightStr);
			weight = stod(weightStr);
			category = stoi(categoryStr);

			if (evolvedFrom.compare("==") == 0) {
				pokedex.add(Pokemon(height, weight, name, desc, category));
			}
			else {
				pokedex.add(EvolvedPokemon(height, weight, name, desc, category, evolvedFrom));
				getline(inFile, line);
			}
		}
		else {
			break;
		}
	}
	inFile.close();
	sortPokedex();
}

void MenuMethods::searchMenu()
{
	int request = dataEntryInt("Search pokemon by: \n 1. Name \n 2. Weight");
	switch (request) {
	case 1:
		searchPokemon();
		break;
	case 2:
		cout << "Search pokemon between 2 weights" << endl;
		double lightest = dataEntry("Enter the lightest");
		double heaviest = dataEntry("Enter the heaviest");
		searchPokemon(lightest, heaviest);
		break;
	}
}

void MenuMethods::createPokemon()
{
	bool back; //Boolean - set to true if need to repeat, false if can proceed to next step
	string name; //New Pokemon's name
	string description; //New Pokemon's description
	double height; //New Pokemon's height
	double weight; //New Pokemon's weight
	int category; //New Pokemon's category
	string evolvedFrom; //New Pokemon's evolvedFrom

	do { //Start do pokemon wizard
		cout << "Welcome to the create new pokemon wizard!" << endl;
		dataEntryStr("");
		do { //Start do ask pokemon name
			//Initialize the back to allow next step by default
			back = false;
			//Get the name of the pokemon
			name = dataEntryStr("Enter the name of the Pokemon: ");
			//Check if the pokemon already exists by name
			if (ifExists(name)) {
				cout << "This pokemon already exists!" << endl;
				back = true;
			}
		} while (back); //End do ask pokemon name

		//Get new pokemon description from user
		description = dataEntryStr("Enter a description for the Pokemon: ");
		//Get new pokemon height from user
		height = dataEntry("Enter the height of the pokemon (in meters): ");
		//Get new pokemon weight from user
		weight = dataEntry("Enter the weight of the pokemon (in kg): ");
		//Get new pokemon category from user
		category = dataEntryInt("Enter the number of the category: ");
		
		do {//Start do evolved from
			back = false; //Initialize back to false to allow next step
			//Get new pokemon evolvedFrom from user
			evolvedFrom = dataEntryStr("Enter the Pokemon it evolved from (hit enter if none): ");
			//Check if evolvedFrom pokemon exists in pokedex
			if (!evolvedFrom.compare("") == 0) {
				if (!ifExists(evolvedFrom)) {
					back = true; //Set repeat to true
					cout << "Pokemon does not exist. Please try again." << endl;
				}
			}
		} while (back); //End do ask Pokemon name

		//Summarize the new Pokemon's details
		cout << "Create Pokemon :" << name << endl
			<< "Description :" << description << endl
			<< "Height: " << height << "m     Weight: " << weight << "kg" << endl
			<< "Evolved From: " << evolvedFrom << endl;

			//Prompt user if correct/wrong
			string confirm = dataEntryStr("Enter \"Y\" is this is correct. Enter any other key if it is incorrect.");
			if (confirm.compare("Y") == 0) {
				back = false; //Allow escape do while loop if user says Y
			}
			else {
				back = true; //Else set repeat to true
			}
	} while (back);//End do pokemon wizard

	//Check if the evolved from is blank to create appropriate class for new pokemon
	if (evolvedFrom.compare("") == 0) {
		//Create New Pokemon
		Pokemon newPokemon = Pokemon(height, weight, name, description, category);
		//Add to pokedex
		pokedex.add(newPokemon);
		cout << "Pokemon " << name << " created successfully." << endl;
	}
	else {
		//Create new EvolvedPokemon
		EvolvedPokemon newPokemon = EvolvedPokemon(height, weight, name, description, category, evolvedFrom);
		//Add to pokedex
		pokedex.add(newPokemon);
		cout << "Pokemon " << name << " created successfully." << endl;
	}
	
	sortPokedex();

}

void MenuMethods::editPokemon(Pokemon *selectedPokemon)
{
	bool repeat; //Boolean for do..while

	do {
		//Print out the name of the selected pokemon
		cout << "Current name: " << selectedPokemon->getName() << endl;
		//Prompt user for new name
		string newName = dataEntryStr("Enter new name (Leave blank to skip):");
		if (newName.compare("") == 0) {
			newName = selectedPokemon->getName();
		}
		//Print out the description of the selected pokemon
		cout << "Current description: " << selectedPokemon->getDescription() << endl;
		//Prompt user for new description
		string newDescription = dataEntryStr("Enter new description (Leave blank to skip):");
		if (newDescription.compare("") == 0) {
			newDescription = selectedPokemon->getDescription();
		}
		//Print out the weight of the selected pokemon
		cout << "Current weight: " << selectedPokemon->getWeight() << endl;
		double newWeight; //Double for new weight
		double newHeight; //Double for new height
		int newCategory; //Int for new Category
		//Weight
		do { //Start do..while for the weight
			repeat = false; //Initialize the repeat as false
			//Prompt user for new weight
			string newWeightStr = dataEntryStr("Enter new weight in kg (Leave blank to skip)");
			//Check if left blank
			if (newWeightStr.compare("") == 0)
			{
				newWeight = selectedPokemon->getWeight();  //Set the new weight to the original weight
				repeat = false; //change repeat to false
			}
			else
			{
				try { //Start try catch
					newWeight = stod(newWeightStr); //Convert user input to double
				}
				catch (exception e) {
					repeat = true; //Set repet to true
					cout << "Invalid double input" << endl;
				} //End try catch
			}
		} while (repeat); //End do..while for weight

		//Height
		cout << "Current height: " << selectedPokemon->getheight() << endl;
		do { //Start do...while for height
			repeat = false; //initialize repeat as false
			//Prompt user for new height
			string newHeightStr = dataEntryStr("Enter new height in m (Leave blank to skip)");
			//Check if left blank
			if (newHeightStr.compare("") == 0)
			{
				newHeight = selectedPokemon->getheight(); //set new height to current height
				repeat = false; //set repeat to false
			}
			else
			{
				try {
					newHeight = stod(newHeightStr); //Try to convert the user input to  double
				}
				catch (exception e) {
					repeat = true; //Set the repeat to true
					cout << "Invalid double input" << endl;
				}
			}
		} while (repeat); //end do..while for Height

		//Category
		cout << "Current category: " << selectedPokemon->getCategory() << endl;
		do { //start do...wile for category
			repeat = false; //initialize repeat as false
			//Prompt user for new category
			string newCategoryStr = dataEntryStr("Enter new category (Leave blank to skip)");
			//Check if empty
			if (newCategoryStr.compare("") == 0)
			{
				newCategory = selectedPokemon->getCategory(); //Set new category to current category
				repeat = false;
			}
			else
			{
				try {
					newCategory = stoi(newCategoryStr); //Try convert to int
				}
				catch (exception e) {
					repeat = true; //Set repeat to true
					cout << "Invalid integer input" << endl;
				}
			}
		} while (repeat); //End do...while for category

		//evolvedFrom
		string newEvolvedFrom;
		cout << "Current evolvedFrom: " << selectedPokemon->getEvolvedFrom() << endl;
		bool exists;
		do {
			newEvolvedFrom = dataEntryStr("Enter new evolvedFrom (Leave blank to remove):");
			exists = ifExists(newEvolvedFrom);
			if (!exists)
				cout << "Pokemon does not exist" << endl;
		} while (!exists);

		//Summarize edits made
		cout << "Confirm edit" << endl
			<< "Name: " << selectedPokemon->getName() << " -> " << newName << endl
			<< "Description: " << selectedPokemon->getDescription() << " -> " << newDescription << endl
			<< "Height: " << selectedPokemon->getheight() << "m -> " << newHeight << "m" << endl
			<< "Weight: " << selectedPokemon->getWeight() << "kg -> " << newWeight << "kg" << endl
			<< "Category: " << selectedPokemon->getCategory() << " -> " << newCategory << endl
			<< "Evolved From: " << selectedPokemon->getEvolvedFrom() << " -> " << newEvolvedFrom << endl;

		repeat = false; //Reset the repeat
		//Ask to confirm edits
		int confirm = dataEntryInt("Is this correct? \n1. Yes\n2. No");
		switch (confirm) {
		case 1:
			//Commit the edits
			//If it is a pokemon object and theres no changes to evolvedfrom
			if (selectedPokemon->getEvolvedFrom().compare("") == 0 && newEvolvedFrom.compare("") == 0) {
				selectedPokemon->edit(newHeight, newWeight, newName, newDescription, newCategory,string());
			}
			//if it is a evolvdpokemon object and there are changes to evolvedfrom
			else if (selectedPokemon->getEvolvedFrom().compare("") != 0 && newEvolvedFrom.compare("") != 0) {
				selectedPokemon->edit(newHeight, newWeight, newName, newDescription, newCategory, newEvolvedFrom);
			}
			//if it is a pokemon object and there evolvedfrom is added
			else if (selectedPokemon->getEvolvedFrom().compare("") == 0 && newEvolvedFrom.compare("") != 0) {
				deletePokemon(selectedPokemon);
				pokedex.add(EvolvedPokemon(newHeight, newWeight, newName, newDescription, newCategory, newEvolvedFrom));
			}
			//if it is a pokemon object and there is an added evolvedfrom (change to evolvedpokemon)
			else if (selectedPokemon->getEvolvedFrom().compare("") != 0 && newEvolvedFrom.compare("") == 0) {
				deletePokemon(selectedPokemon);
				pokedex.add(Pokemon(newHeight, newWeight, newName, newDescription, newCategory));
			}
			break;
		case 2:
			repeat = false;
			break;
		}
	} while (repeat);
	sortPokedex();
}

void MenuMethods::searchPokemon()
{
	//Vector/List to store the found pokemon
	vector<Pokemon*> foundPokemon;
	//vector<Pokemon> foundPokemon;

	int noFound = 0;

	//Get user input for search string
	string keyword = dataEntryStr("Enter a keyword: ");

	//Iterate through the pokedex
		vector<Pokemon>::iterator start = pokedex.getItemCollection()->begin();
		vector<Pokemon>::iterator end = pokedex.getItemCollection()->end();

		for (start; start != end; ++start) {
			string name = (string)start->getName();
			//Check if the name of the pokemon satisfys the keyword condition
			if (name.find(keyword) != string::npos) {
				//Assign a temporary ptr to the current iterator
				Pokemon* theFound = &(*start);
				//Push back into the found pokemon vector
				foundPokemon.push_back(theFound);
			}
		}

	//If there are found pokemons
	if (foundPokemon.size() > 0) {
		int noFound = 0;
		for each (Pokemon* aPokemon in foundPokemon)
		{
			cout << noFound+1 << ". " << aPokemon->getName() << endl;
			noFound++;
		}

		bool loop; //Boolean for looping
		do { //start do...while for option
			loop = false; //initialize as false
						  //Prompt user for pokemon index no
			int intSelected = dataEntryInt("Enter the number of the pokemon you would like to view: ");
			try {
				Pokemon *selectedPokemon = foundPokemon.at(intSelected - 1);
				displayPokemon(selectedPokemon); //Display the pokemon
			}
			catch (exception e) {
				loop = true; //loop true
				cout << "Invalid selection. Please try again." << endl;
			}
		} while (loop); //End do...while for option
	}else{
		cout << "No such pokemon found." << endl;
	}	
}

void MenuMethods::searchPokemon(double const lightest, double const heaviest)
{
	//Vector/List to store the found pokemon
	vector<Pokemon*> foundPokemon;

	int noFound = 0;

	//Iterate through the pokedex
	vector<Pokemon>::iterator start = pokedex.getItemCollection()->begin();
	vector<Pokemon>::iterator end = pokedex.getItemCollection()->end();

	for (start; start != end; ++start) {
		if (start->getWeight() > lightest && start->getWeight() < heaviest) {
			//Assign a temporary ptr to the current iterator
			Pokemon* theFound = &(*start);
			//Push back into the found pokemon vector
			foundPokemon.push_back(theFound);
		}
	}

	//If there are found pokemons
	if (foundPokemon.size() > 0) {
		int noFound = 0;
		for each (Pokemon* aPokemon in foundPokemon)
		{
			cout << noFound + 1 << ". " << aPokemon->getName() << endl;
			noFound++;
		}

		bool loop; //Boolean for looping
		do { //start do...while for option
			loop = false; //initialize as false
						  //Prompt user for pokemon index no
			int intSelected = dataEntryInt("Enter the number of the pokemon you would like to view: ");
			try {
				Pokemon *selectedPokemon = foundPokemon.at(intSelected - 1);
				displayPokemon(selectedPokemon); //Display the pokemon
			}
			catch (exception e) {
				loop = true; //loop true
				cout << "Invalid selection. Please try again." << endl;
			}
		} while (loop); //End do...while for option
	}
	else {
		cout << "No such pokemon found." << endl;
	}
}

void MenuMethods::displayPokemon(Pokemon *selectedPokemon)
{
	cout << *selectedPokemon << endl;
	//TODO EVOLUTION
	
	int selection; //Int for the action the user wants to take
	bool repeat; //Repeat boolean
	do {
		repeat = false; //initialize the repeat to false
		selection = 0; //initialize selecton int

		//Prompt user for selection
		selection = dataEntryInt("Enter 1 to Edit this pokemon, 2 to delete this pokemon, 3 to go back to main menu");
		
		if (selection < 1 || selection > 3) { //Check if within range
			cout << "Please enter a number from 1 to 3 only." << endl;
			repeat = true;
		}

	} while (repeat);


	//Switch for selection
	switch (selection)
	{
	case 1: //Edit
		editPokemon(selectedPokemon);
		break;
	case 2: //Delete
		deletePokemon(selectedPokemon);
		break;
	case 3: //Back to main Menu
		//Nothing happens here.
		break;
	}
}

void MenuMethods::deletePokemon(Pokemon *selectedPokemon)
{
	vector<Pokemon>::iterator begin = pokedex.getItemCollection()->begin();
	vector<Pokemon>::iterator end = pokedex.getItemCollection()->end();

	for (begin; begin != end; ++begin) {
		if (begin->getName().compare(selectedPokemon->getName()) == 0) {
			pokedex.getItemCollection()->erase(begin);
			sortPokedex();
			break;
		}
	}
}

double MenuMethods::dataEntry(string const question)
{
	bool error; //Boolean for error
	string reply; //string for User reply
	double replyconverted; //double for Converted reply
	do {
		error = false; //Initialize it as true

		try {
			//Print the question
			cout << question << endl;
			//Get the user reply
			getline(cin, reply);
			//End the line
			cout << endl;
			//Try to convert to double
			replyconverted = stod(reply);
		}
		catch (exception e) {
			cout << "Error: Please enter a valid double value." << endl;
			error = true;
		}

	} while (error);
	return replyconverted; //Return the converted reply
}

int MenuMethods::dataEntryInt(string const question)
{
	bool error; //Boolean for error
	string reply; //string for user reply
	int replyconverted; //int for user reply converted
	do {
		error = false; //Initialize the error as false

		try {
			//Print the question
			cout << question << endl;
			//Get the user reply
			getline(cin, reply);
			//End line
			cout << endl;
			//Try to convert to int
			replyconverted = stoi(reply);
		}
		catch (exception e) {
			cout << "Error: Please enter a valid double value." << endl;
			error = true;
		}

	} while (error);
	return replyconverted; //Return the converted reply (int)
}

string MenuMethods::dataEntryStr(string const question)
{
	string reply; //String for user reply
	bool error; //boolean for error

	do {
		error = false; //Initialize the error as false
		try {
			//Print out the queston
			cout << question << endl;
			//Get user reply
			getline(cin, reply);
			//End line
			cout << endl;
		}
		catch (exception e) {
			cout << "Error: Illegal characters." << endl;
			error = true;
		}
	} while (error);
	return reply; //Return the user reply
}

bool MenuMethods::ifExists(string const pokemonName)
{
	for (vector<Pokemon>::iterator it = pokedex.getItemCollection()->begin(); it != pokedex.getItemCollection()->end(); ++it) {
		//	//Return true if the name equal
			if (it->getName().compare(pokemonName) == 0)
				return true;
	}
	////For each pokemon in the pokedex
	//for each (Pokemon aPokemon in pokedex.getItemCollection())
	//{
	//	//Return true if the name equal
	//	if (aPokemon.getName().compare(pokemonName) == 0)

	//		return true;
	//}
	return false; //return false if does not exist
}

bool sortByName(const Pokemon &lhs, const Pokemon &rhs)
{
	return lhs.getName() < rhs.getName();
}

void MenuMethods::sortPokedex()
{
	sort(pokedex.getItemCollection()->begin(), pokedex.getItemCollection()->end(), sortByName);
	writeDataFile();
}

void MenuMethods::writeDataFile()
{
	ofstream outFile;
	outFile.open("PokemonData.txt");
	
	vector<Pokemon>::iterator it = pokedex.getItemCollection()->begin();
	vector<Pokemon>::iterator end = pokedex.getItemCollection()->end();

	for (it; it != end; ++it) 
	{
		outFile << it->getName() << endl;
		outFile << it->getDescription() << endl;
		outFile << it->getheight() << endl;
		outFile << it->getWeight() << endl;
		outFile << it->getCategory() << endl;

		string evolvedFrom = it->getEvolvedFrom();
		if (evolvedFrom.compare("") == 0) {
			outFile << "==" << endl;
		}
		else {
			outFile << evolvedFrom << endl;
			outFile << "==" << endl;
		}
	}
	outFile << "END" << endl;
}

string MenuMethods::getEvolution(Pokemon const * selectedPokemon)
{
	string first;
	string second;
	string third;

	vector<string> seconds;

	vector<Pokemon>::iterator it = pokedex.getItemCollection()->begin();
	vector<Pokemon>::iterator end = pokedex.getItemCollection()->end();
	//If there is no evoution, we can assume it is the first in the evolution string.
	if (selectedPokemon->getEvolvedFrom().compare("") == 0) {
		first = selectedPokemon->getName();
		for (it; it != end; ++it) {
			if (it->getEvolvedFrom().compare(first) == 0) {
				second = it->getName();
				break;
			}
		}
		for (it = pokedex.getItemCollection()->begin(); it != end; ++it) {
			if (it->getEvolvedFrom().compare(second) == 0) {
				third = it->getName();
				break;
			}
		}
	}
	else {
		
	}
	return string();
}

MenuMethods::~MenuMethods()
{
}
