#include "MenuMethods.h"

MenuMethods::MenuMethods()
{
	//Create test data

	Pokemon newPokemon1 = Pokemon(1.0, 1.0, "Alphy", "Test Pokemon Alpha", 1);
	Pokemon newPokemon2 = Pokemon(2.0, 2.0, "Bety", "Test Pokemon Bety", 2);
	Pokemon newPokemon3 = Pokemon(3.0, 3.0, "Charlie", "Test Pokemon Charlie", 3);
	Pokemon newPokemon4 = Pokemon(4.0, 4.0, "Delta", "Test Pokemon Delta", 3);

	EvolvedPokemon newEvolvedPokemon1 = EvolvedPokemon(1.1, 1.1, "Ace", "Test evolved pokemon alpha",1,"Alphy");
	EvolvedPokemon newEvolvedPokemon2 = EvolvedPokemon(2.2,2.2, "Betsy", "Test evolvedS pokemon alpha", 1, "Bety");
	EvolvedPokemon newEvolvedPokemon3 = EvolvedPokemon(3.3,3.3, "Charred Charlie", "Test evolved pokemon Charlie", 1, "Charlie");
	EvolvedPokemon newEvolvedPokemon4 = EvolvedPokemon(1.1, 1.1, "Darling", "Test evolved pokemon Delta", 1, "Delta");

	//Add the test data into the pokedex
	pokedex.add(newPokemon1);
	pokedex.add(newPokemon2);
	pokedex.add(newPokemon3);
	pokedex.add(newPokemon4);

	pokedex.add(newEvolvedPokemon1);
	pokedex.add(newEvolvedPokemon2);
	pokedex.add(newEvolvedPokemon3);
	pokedex.add(newEvolvedPokemon4);
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
	

}

void MenuMethods::editPokemon()
{
	//Print out the name of the selected pokemon
	cout << "Current name: " << selectedPokemon->getName() << endl;
	//Prompt user for new name
	string newName = dataEntryStr("Enter new name (Leave blank to skip):");
	//Print out the description of the selected pokemon
	cout << "Current description: " << selectedPokemon->getDescription() << endl;
	//Prompt user for new description
	string newDescription = dataEntryStr("Enter new description (Leave blank to skip):");
	//Print out the weight of the selected pokemon
	cout << "Current weight: " << selectedPokemon->getWeight() << endl;
	double newWeight; //Double for new weight
	double newHeight; //Double for new height
	int newCategory; //Int for new Category

	bool repeat; //Boolean for do..while
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

	//Summarize edits made
	cout << "Confirm edit" << endl
		<< "Name: " << selectedPokemon->getName() << " -> " << newName << endl
		<< "Description: " << selectedPokemon->getDescription() << " -> " << newDescription << endl
		<< "Height: " << selectedPokemon->getheight() << "m -> " << newHeight << "m" << endl
		<< "Weight: " << selectedPokemon->getWeight() << "kg -> " << newWeight << "kg" << endl
		<< "Category: " << selectedPokemon->getCategory() << " -> " << newCategory << endl;
	

}

void MenuMethods::searchPokemon()
{
	//Vector/List to store the found pokemon
	vector<Pokemon> foundPokemon = vector<Pokemon>();
	//Number to track the number of pokemon found
	int noFound = 0;
	//Temporary to prevent the thing form skipping this
	dataEntryStr("");
	//Get user input for search string
	string keyword = dataEntryStr("Enter a keyword: ");

	//Loop through the entire pokedex
	for each (Pokemon aPokemon in pokedex.getItemCollection())
	{
		//Check if the name contains the keyword
		if (aPokemon.getName().find(keyword) != string::npos) {
			//Add the pokemon to the list
			foundPokemon.push_back(aPokemon);
			//Update the number of pokemon found
			noFound++;
			//Print out the pokemon.
			cout << noFound <<". " << aPokemon.getName()<< endl;
		}
	}

	//Check if theres any pokemon found
	if (noFound > 0) {
		bool loop; //Boolean for looping
		do { //start do...while for option
			loop = false; //initialize as false
			//Prompt user for pokemon index no
			int intSelected = dataEntryInt("Enter the number of the pokemon you would like to view: ");
			try {
				Pokemon selectedPokemonObj = foundPokemon.at(intSelected - 1); //Get the pokemon from the index
				selectedPokemon = &selectedPokemonObj; //Set the pointer to it
				displayPokemon(); //Display the pokemon
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

Pokemon MenuMethods::searchQuickPokemon(string search)
{
	auto findPokemonFunction = [search](Pokemon pokemon) {
		return pokemon.getName().compare(search)==0;
	};

	vector<Pokemon> *itemcollection;

	itemcollection = &pokedex.getItemCollection();

	Pokemon foundPokemon = find_if(begin(pokedex.getItemCollection()), end(pokedex.getItemCollection()), findPokemonFunction);

	Pokemon foundPokemon = find_if(pokedex.getItemCollection().begin(), pokedex.getItemCollection().end(), findPokemonFunction);
	
	return foundPokemon;
}

void MenuMethods::displayPokemon()
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
		editPokemon();
		break;
	case 2: //Delete
		break;
	case 3: //Back to main Menu
		//Nothing happens here.
		break;
	}
}

void MenuMethods::deletePokemon()
{
	//TODO: Delete Pokemon
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
	//For each pokemon in the pokedex
	for each (Pokemon aPokemon in pokedex.getItemCollection())
	{
		//Return true if the name equal
		if (aPokemon.getName().compare(pokemonName) == 0)

			return true;
	}
	return false; //return false if does not exist
}

MenuMethods::~MenuMethods()
{
}
