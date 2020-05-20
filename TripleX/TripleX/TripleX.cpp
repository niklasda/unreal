// TripleX.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


void PrintIntroduction(int Difficulty)
{
	std::cout << "\n\nYou are a secret agent trying to break into a level " << Difficulty;

	std::cout << " secure server room...\n";

	std::cout << "Enter the correct code to continue...\n\n";
}

bool PlayGame(int Difficulty)
{
	PrintIntroduction(Difficulty);
	
	const int CodeA = 4, CodeB = 3, CodeC = 2;
	int CodeSum = CodeA + CodeB + CodeC;
	int CodeProduct = CodeA * CodeB * CodeC;

	// exiting stuff

	/*
	not hard
	*/

	std::cout << "+ There are 3 numbers in the code " ;
	std::cout << "\n+ The codes add-up to " << CodeSum ;
	std::cout << "\n+ The codes multiply to give " << CodeProduct << std::endl;

	int GuessA, GuessB, GuessC;

	std::cin >> GuessA >> GuessB >> GuessC;
	
	// std::cout << "You entered: " << GuessA << GuessB << GuessC << std::endl;

	int GuessSum = GuessA + GuessB + GuessC;
	int GuessProduct = GuessA * GuessB * GuessC;

	if(CodeSum == GuessSum && CodeProduct == GuessProduct)
	{
		std::cout << "The code is correct, proceed!\n";
		return true;
	}
	else
	{
		std::cout << "The code is wrong, you die!\n";
		return false;
	}
}

int main()
{

	int LevelDifficulty = 1;
	while (LevelDifficulty < 5)
	{
		bool bLevelComplete = PlayGame(LevelDifficulty) ;

		std::cin.clear();
		std::cin.ignore();

		if (bLevelComplete)
		{
			++LevelDifficulty;
		}
	}
	
	return 0;
}
