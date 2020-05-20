// TripleX.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
	std::cout << "You are a secret agent trying to break into a secure server room...";
	std::cout << std::endl;
	std::cout << "Enter the correct code to continue...";
	std::cout << std::endl;

	const int CodeA = 4;
	const auto CodeB = 3;
	const int CodeC = 2;

	int CodeSum = CodeA + CodeB + CodeC;
	int CodeProduct = CodeA * CodeB * CodeC;

	// exiting stuff

	/*
		not hard
	*/

	std::cout << std::endl;
	std::cout << "+ There are 3 numbers in the code " << std::endl;
	std::cout << "+ The codes add-up to " << CodeSum << std::endl;
	std::cout << "+ The codes multiply to give " << CodeProduct << std::endl;

	int GuessA, GuessB, GuessC;

	std::cin >> GuessA;
	std::cin >> GuessB;
	std::cin >> GuessC;
	// std::cout << "You entered: " << GuessA << GuessB << GuessC << std::endl;

	int GuessSum = GuessA + GuessB + GuessC;
	int GuessProduct = GuessA * GuessB * GuessC;

	return 0;
}
