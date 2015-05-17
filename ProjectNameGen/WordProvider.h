//
//  WordProvider.h
//  ProjectNameGen
//
//  Created by Daniel Corn on 14.05.15.
//  Copyright (c) 2015 cundd. All rights reserved.
//

#ifndef __ProjectNameGen__WordProvider__
#define __ProjectNameGen__WordProvider__

#include <stdio.h>
#include <vector>
#include "LibraryReader.h"
#include "WordList.h"

class WordProvider {
	LibraryReader *reader = nullptr;
	
public:
//	WordProvider() {
//	}
//	
//	WordProvider(const char *libraryFilePath) {
//		reader = new LibraryReader(libraryFilePath);
//	}
	
	~WordProvider() {
		delete reader;
	}
	
	void openLibrary(const char *libraryFilePath) {
		reader = new LibraryReader(libraryFilePath);
	}
	
	const std::vector<std::string> &getWords() {
		if (reader != nullptr) {
			return reader->getWords();
		}
		return cundd::words;
	}
};

#endif /* defined(__ProjectNameGen__WordProvider__) */
