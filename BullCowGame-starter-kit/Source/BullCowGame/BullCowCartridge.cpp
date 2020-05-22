// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

#include <iostream>

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

	PrintLine(TEXT("Moh There! (Tab to focus)"));
	PrintLine(TEXT("Please type text to play!"));
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
	ClearScreen();

	FString HiddenWord = TEXT("isogram");
	// std::cout << HiddenWord;;

	
}