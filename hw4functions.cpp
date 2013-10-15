//Patrick Whetsel
//CSCI 2421 Spring 2013
//hw4fuctions.cpp
//definitions of global functions

#include "hw4functions.h"

void hw4functions::greeting()
{
	std::cout << "Welcome.  This program accesses a file passed \n";
	std::cout << "as a command line argument and stores 5 space \n";
	std::cout << "delimited nouns from the first line of the file \n";
	std::cout << "and 5 space delimited verbs from the second \n";
	std::cout << "line.  The program then displays five sentences\n";
	std::cout << "constructed randomly using these nouns and verbs.\n";
	std::cout << "\nPlease press any key followed by ENTER to continue.\n";

	//hold for user input
	int x;
	std::cin >> x;
	std::cout << '\n';
	std::cin.ignore(255, '\n');
}

void hw4functions::confirm_cmdline_args(int count)
{
	if (count != 2)
	{
		std::cerr << "\nUsage: a.out filename_in";
		return exit(-1);
	}
}

void hw4functions::open_file(std::ifstream& in,char* file)
{
	in.open(file);
	if (!in.is_open())
	{
		std::cerr << "\nFile could not be opened";
		return exit(-1);
	}
}

void hw4functions::fill_bags(std::ifstream& in, bag<std::string>& nouns_bag, bag<std::string>& verbs_bag)
{
	//move to beginning of file
	in.clear();
	in.seekg(0, in.beg);

	const int WORDS_PER_LINE = 5;
	std::string line;
	std::string word;
	std::stringstream ss;

	//get first line of file
	std::getline(in, line);
	ss << line;

	//store first line as nouns
	for (int i = 0; i < WORDS_PER_LINE; ++i)
	{
		ss >> word;
		nouns_bag.insert(word);
	}

	//Get second line and store as verbs
	std::getline(in, line);
	ss << line;
	for (int j = 0; j < WORDS_PER_LINE; ++j)
	{
		ss >> word;
		verbs_bag.insert(word);
	}
}

std::string hw4functions::return_rdm (bag<std::string>& bag_in)
{
	return bag_in.grab();
}

void hw4functions::write_sentences( bag<std::string>& nouns, bag<std::string>& verbs)
{
	std::string noun;
	std::string verb;
	//Sentence 1
	noun = hw4functions::return_rdm(nouns);
	verb = hw4functions::return_rdm(verbs);
	std::cout <<"\n" << noun << ", please " << verb <<" me the remote.";
	//Sentence 2
	noun = hw4functions::return_rdm(nouns);
	verb = hw4functions::return_rdm(verbs);
	std::cout << "\nThe " << noun << " " << verb << " quickly.";
	//Sentence 3
	noun = hw4functions::return_rdm(nouns);
	verb = hw4functions::return_rdm(verbs);
	std::cout << "\n" << noun << " always finishes first in " << verb << ".";
	//Sentence 4
	noun = hw4functions::return_rdm(nouns);
	verb = hw4functions::return_rdm(verbs);
	std::cout << "\nThe " << noun << " often " << verb << " slowly.";
	//Sentence 5
	noun = hw4functions::return_rdm(nouns);
	verb = hw4functions::return_rdm(verbs);
	std::cout << "\nI " << verb << " the " << noun << " in the morning.";
}