//Patrick Whetsel
//CSCI 2421 Fall 2013
//hw4functions.h
//declaration of global functions
//to be included with hw4functions.cpp

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <cassert>
#include "bag.h"

#ifndef _hw4functions_h
#define _hw4functions_h

namespace hw4functions
{
	//Pre:None
	//Post:Displays program gretting
	void greeting();
	//Pre:Argument count passed as int
	//Post:Displays error message and returns exit_failure if not enough commandline args
	void confirm_cmdline_args(int);
	//Pre:File name passed in argv[1]
	//Post:File is opened with ifstream
	void open_file(std::ifstream&,char*);
	//Pre:File opened successfully in ifstream, 1 line of 5 verbs and 1 line of 5 nouns
	//Post:Verbs and nouns are inserted into respective bags
	void fill_bags(std::ifstream&,bag<std::string>&,bag<std::string>&);
	//Pre: Requires a non-empty bag
	//Post: Returns a random element of the bag
	std::string return_rdm (bag<std::string>&);
	//Pre:Two bags, one containing verbs and the other nouns
	//Post:Five sentences are written to the display substituting random nouns and verbs where appropriate
	void write_sentences(bag<std::string>&,bag<std::string>&);
};

#endif