//
//  main.cpp
//  ProjectNameGen
//
//  Created by Daniel Corn on 14.05.15.
//  Copyright (c) 2015 cundd. All rights reserved.
//

#include <iostream>
#include <unistd.h>    /* for getopt */
//#include <getopt.h> /* for getopt_long */

#include "WordProvider.h"
#include "NameGenerator.h"

int main(int argc, const char * argv[]) {
	bool dumpLibrary = false;
	int option;
	int numberOfWords = 2;
	char *libraryFilePath = nullptr;
	
	while ( (option = getopt(argc, (char **)argv, "dn:hf:")) != -1) {
		switch (option) {
			case 'n':
				numberOfWords = atoi(optarg);
				//cout << "option n with value " << numberOfWords << endl;
				break;
				
			case 'f':
				//cout << "option f with value " << optarg << endl;
				libraryFilePath = optarg;
				break;
				
			case 'd':
				dumpLibrary = true;
				break;
				
			case '?':
			case 'h':
				default:
				cout << "Usage: ProjectNameGen [-f library-file] [-n num] [-d]" << endl;
				break;
		}
	}
//	if (optind < argc) {
//		printf ("non-option ARGV-elements: ");
//		while (optind < argc)
//			printf ("%s ", argv[optind++]);
//		printf ("\n");
//	}
	
	
	std::vector<string> words;
	
	if (libraryFilePath) {
		WordProvider wordProvider(libraryFilePath);
		words = wordProvider.getWords();
	} else {
		WordProvider wordProvider;
		words = wordProvider.getWords();
	}
	
	if (dumpLibrary) {
		for (auto word : words) {
			cout << word << endl;
		}
		
		return 0;
	}
	
	
	NameGenerator generator;
	cout << generator.generate(words, numberOfWords) << endl;
	
    return 0;
}
