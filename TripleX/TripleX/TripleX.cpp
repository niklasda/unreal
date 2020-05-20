// TripleX.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    std::cout << "You are a secret agent trying to break into a secure server room..." ;
	std::cout << std::endl;
	std::cout << "Enter the correct code to continue..."; 
	std::cout << std::endl;
		
	const int a = 4;
    const auto b = 3;
    const int c = 2;

	int sum = a + b + c;
	int product = a * b *c;
	
	

	std::cout << sum << std::endl;
	std::cout << product << std::endl;

	return 0;
}
