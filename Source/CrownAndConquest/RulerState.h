// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "Engine/Texture2D.h"
#include "RulerState.generated.h"

/**
 * 
 */
UCLASS()
class CROWNANDCONQUEST_API ARulerState : public APlayerState
{
	GENERATED_BODY()

public:

	/**
	 * @brief Handle the construction of the ruler's state
	 * @param none
	 * @return ARulerState
	 */
	ARulerState();

	// Hold the ruler name
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName Ruler;

	// Hold the ruler texture
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture2D* RulerTexture;

	// Hold the explore resource
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Maps = 0;

	// Hold the expand resource
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Livestock = 0;

	// Hold the exploit resource
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Tools = 0;

	// Hold the exterminate resource
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Weapons = 0;

	// Hold the explore resource incrementer
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Explorers = 0;

	// Hold the exploit resource incrementer
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Ranchers = 0;

	// Hold the exploit resource incrementer
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int  Craftsmen  = 0;

	// Hold the exterminate resource incrementer
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Blacksmiths = 0;

	// Hold the explore resource incrementer
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Culture = 0;

	// Hold the exploit resource incrementer
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Prestige = 0;

	// Hold the exploit resource incrementer
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Science = 0;

	// Hold the exterminate resource incrementer
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Innovation = 0;
};
