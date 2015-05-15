//
//  LibraryReader.h
//  ProjectNameGen
//
//  Created by Daniel Corn on 14.05.15.
//  Copyright (c) 2015 cundd. All rights reserved.
//

#ifndef __ProjectNameGen__LibraryReader__
#define __ProjectNameGen__LibraryReader__

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class LibraryReader {
	std::string libraryFilePath;
	std::vector<std::string>words;
	
public:
	LibraryReader(const char* libraryFilePath) : libraryFilePath(libraryFilePath) {
	}
	
	std::vector<std::string> const &getWords() {
		if (words.size() == 0) {
			std::ifstream libraryFile(this->libraryFilePath);
			libraryFile.exceptions ( ifstream::failbit | ifstream::badbit );
			while (libraryFile.good()) {
				string word;
				libraryFile >> word;
				words.push_back(word);
				
				// Ignore the rest of the line
				libraryFile.ignore(1024, '\n');
			}
			
//			for (string word : words) {
//				cout << word << endl;
//			}
//			
//			cout << "Got " << words.size() << " words" << endl;
		}
		return words;
	}
};

#endif /* defined(__ProjectNameGen__LibraryReader__) */
