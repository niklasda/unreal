// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
#include "HiddenWordList.h"

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
		ProcessGuess(Input);


		if (Lives <= 0)
		{
			EndGame();
		}

		/*if (Input == HiddenWord)
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
		}*/
	}
}

void UBullCowCartridge::SetupGame()
{
	//	Words[2];

	const TArray<FString> MyWords = GetValidWords(Words);

//	PrintLine(TEXT("%d"), FMath::RandRange(0, MyWords.Num()));

	HiddenWord = MyWords[FMath::RandRange(0, MyWords.Num()-1)];

	//HiddenWord = TEXT("isogram");
	Lives = HiddenWord.Len();
	bGameOver = false;

	ClearScreen();

	PrintLine(TEXT("The Hidden word is: %s"), *HiddenWord);
	PrintLine(TEXT("The word is %i characters long"), HiddenWord.Len());
	PrintLine(TEXT("The word list is %i words long"), MyWords.Num());


	PrintLine(TEXT("Moh There! (Tab to focus)"));
	PrintLine(TEXT("Welcome to Bull Cows"));
	PrintLine(TEXT("Please type a guess to play!"));

	PrintLine(TEXT("And then press enter"));

	const TCHAR HW[] = TEXT("cakes");
	const TCHAR HW2[] = { TEXT('c'),TEXT('a'),TEXT('k'),TEXT('e'),TEXT('s'), TEXT('\0') };
	PrintLine(TEXT("Character 1 of array is: %c"), HW[0]);
	PrintLine(TEXT("Character 1 of array is: %c"), HW2[0]);
}

void UBullCowCartridge::EndGame()
{
	//ClearScreen();

	bGameOver = true;
	PrintLine(TEXT("Game Over, press enter to play again"));

}

void UBullCowCartridge::ProcessGuess(const FString& Guess)
{
	if (Guess == HiddenWord)
	{
		PrintLine(TEXT("Correct"));
		EndGame();
		return;
	}
	int32 Bulls, Cows;
	GetBullCows(Guess, Bulls, Cows);
	PrintLine(TEXT("Your have %d bulls and %d cows"), Bulls, Cows);

	
	if (IsIsogram(Guess))
	{
		Lives--;

		PrintLine(TEXT("Isogram, Wrong word, %i lives remaing"), Lives);
		return;

	}
	if (HiddenWord.Len() == Guess.Len())
	{
		Lives--;
		PrintLine(TEXT("Correct Length, Wrong word, %i lives remaing"), Lives);
		return;
	}

	
	
	//else //if (HiddenWord.Len() != Input.Len())
	//{
	Lives--;
	PrintLine(TEXT("Wrong Word, %i lives remaing"), Lives);
	//return;
//}

}


bool UBullCowCartridge::IsIsogram(const FString& Word) const
{
	for (int32 i = 0; i < Word.Len() - 1; i++)
	{
		const TCHAR c = Word[i];

		for (int32 ii = i + 1; ii < Word.Len(); ii++)
		{
			if (c == Word[ii])
			{
				return false;
			}
		}
	}

	return true;
}

TArray<FString> UBullCowCartridge::GetValidWords(TArray<FString>& InWords) const
{
	InWords.Emplace("cones");
	InWords.Emplace("wayTooLong");
	InWords.Remove("wayTooLong");
	//int a = 3;
	//int b = 3;
	//int& ra = a;

	//ra = b;


	for (const FString LoopWord : InWords)
	{
		bool isIt = IsIsogram(LoopWord);

	}

	for (int32 i = 0; i < InWords.Num(); i++)
	{
		//PrintLine(InWords[i]);
		bool isIt = IsIsogram(InWords[i]);
	}

	return InWords;
}

void UBullCowCartridge::GetBullCows(const FString& Guess, int32& BullCount, int32& CowCount) const
{
	BullCount = 0, CowCount = 0;

	
	for(int32 GuessIndex = 0; GuessIndex < Guess.Len() ; GuessIndex++)
	{
		if(Guess[GuessIndex] == HiddenWord[GuessIndex])
		{
			BullCount++;
			continue;
		}

		for (int32 HiddenIndex = 0; HiddenIndex < HiddenWord.Len(); HiddenIndex++)
		{
			if (Guess[GuessIndex] == HiddenWord[HiddenIndex])
			{
				CowCount++;
				//continue;
			}

		}
	}
}