//Patrick Whetsel
//CSCI 2421 Fall 2013
//hw4.cpp
//This program accesses a file passed 
//as a command line argument and stores 5 space 
//delimited nouns from the first line of the file 
//and 5 space delimited verbs from the second 
//line.  The program then displays five sentences 
//constructed randomly using these nouns and verbs.


#include "hw4functions.h"

int main(int argc, char* argv[])
{
	//Display greeting
	hw4functions::greeting();

	//Check for valid number of command line arguments
	hw4functions::confirm_cmdline_args(argc);

	//Open file stream
	std::ifstream input;
	hw4functions::open_file(input, argv[1]);

	//Store nouns and verbs in respective bags
	bag<std::string> nouns;
	bag<std::string> verbs;
	hw4functions::fill_bags(input,nouns,verbs);

	//Write out sentences with random nouns and verbs
	hw4functions::write_sentences(nouns, verbs);

	return EXIT_SUCCESS;
}