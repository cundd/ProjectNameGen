//
//  NameGenerator.h
//  ProjectNameGen
//
//  Created by Daniel Corn on 14.05.15.
//  Copyright (c) 2015 cundd. All rights reserved.
//

#ifndef __ProjectNameGen__NameGenerator__
#define __ProjectNameGen__NameGenerator__

#include <stdio.h>
#include <vector>
#include <sstream>
#include <iostream>
#include <time.h>
#include <random>

using namespace std;

class NameGenerator {
public:
	std::string generate(std::vector<std::string> words, int numberOfWords, bool capitalize = true) {
		stringstream generatedName;
		size_t wordListCount = words.size();
		
		while (numberOfWords-- > 0) {
			long randomIndex = getRandom(wordListCount);
			string randomWord = words[randomIndex];

			if (capitalize) {
				randomWord[0] = toupper(randomWord[0]);
			}
			generatedName << randomWord;			
		}
		return generatedName.str();
	}
	
	long getRandom(size_t max) {
//		static bool didInitialize = false;
//		
//		if (!didInitialize) {
//			srand((uint)time(NULL));
//			didInitialize = true;
//		}
//		return rand() % max;
		
		std::random_device rd;     // only used once to initialise (seed) engine
		std::mt19937 randomNumberGenerator(rd());    // random-number engine used (Mersenne-Twister in this case)
		std::uniform_int_distribution<long> uni(0, max); // guaranteed unbiased
		
		return uni(randomNumberGenerator);
	}
};

#endif /* defined(__ProjectNameGen__NameGenerator__) */
