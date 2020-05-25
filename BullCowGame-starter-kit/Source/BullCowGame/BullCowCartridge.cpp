// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

#include <iostream>

void UBullCowCartridge::BeginPlay() // When the game starts
{
	Super::BeginPlay();

	SetupGame();
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
	/*int32 a = 1;
	PrintLine(TEXT("%i"), a);
	*/

	if (bGameOver)
	{
		SetupGame();
		
	}
	else
	{
		if (Input == HiddenWord)
		{
			PrintLine(TEXT("Correct"));
			EndGame();
		}
		else if (HiddenWord.Len() == Input.Len())
		{
			Lives--;

			PrintLine(TEXT("Correct Length, Wrong word, %i lives remaingin"), Lives);

		}
		else //if (HiddenWord.Len() != Input.Len())
		{
			Lives--;
			PrintLine(TEXT("Wrong Word, %i lives remaingin"), Lives);

		}

		if(Lives<= 0)
		{
			EndGame();
		}
	}
}

void UBullCowCartridge::SetupGame()
{
	HiddenWord = TEXT("isogram");
	Lives = HiddenWord.Len();
	bGameOver = false;

	ClearScreen();

	PrintLine(TEXT("The Hidden word is: %s"), *HiddenWord);
	PrintLine(TEXT("The word is %i characters long"), HiddenWord.Len());

	PrintLine(TEXT("Moh There! (Tab to focus)"));
	PrintLine(TEXT("Welcome to Bull Cows"));
	PrintLine(TEXT("Please type a guess to play!"));

	PrintLine(TEXT("And then press enter"));
}

void UBullCowCartridge::EndGame()
{
	//ClearScreen();

	bGameOver = true;
	PrintLine(TEXT("Game Over, press enter to play again"));

}