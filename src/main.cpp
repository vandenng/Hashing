#include "my_hash.h"
#include "Superhero.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

/********************************************************************************************
* This main method will read the database.csv file, and seperate each line as a Superhero.
* Then each superhero is stored using a hashing function, and the number of collisions is
* recorded. The the number of collisions is printed out, and written to a RESULTS.md file.
*
* Using an sstream to get data form the file was found on StackOverflow.
********************************************************************************************/
int main(int argc, char** argv){
	std::string input[13];
	std::string line;
	int count = 0;

	Hash hash;
	
	std::ifstream myFile;
	myFile.open("database.csv");

	if(!myFile){
		std::cout << "ERROR" << std::endl;
		exit(1);
	}

	while( std::getline(myFile, line )){
		std::stringstream linestream(line);
		for(int i = 0; i < 13; i++){
			std::getline(linestream, input[i], ',');
		}

		Superhero s(input);
		if(hash.insert(s))
			++count;
	}

	std::cout << count << std::endl;
	myFile.close();

	std::ofstream results;
	results.open("RESULTS.md");
	results << "There where " << count << " colissions!" << std::endl;
	results.close();
	
	return EXIT_SUCCESS;
}
