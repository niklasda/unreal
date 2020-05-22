// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

#include <iostream>

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

	UBullCowCartridge::HiddenWord = TEXT("isogram");

	PrintLine(TEXT("Moh There! (Tab to focus)"));
	PrintLine(TEXT("Welcome to Bull Cows"));
	PrintLine(TEXT("Please type a guess to play!"));
	//PrintLine(HiddenWord.Len());
	PrintLine(TEXT("And then press enter"));
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
	ClearScreen();

	// std::cout << HiddenWord;;

	if(Input == HiddenWord)
	{
		PrintLine(TEXT("Correct"));
		PrintLine(Input);

	}
	else
	{
		PrintLine(TEXT("Wröng"));
		PrintLine(Input);

//		Lifes--
	}
	
}