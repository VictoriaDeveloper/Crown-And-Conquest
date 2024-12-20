// Fill out your copyright notice in the Description page of Project Settings.


#include "Player4XPawn.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/Controller.h"
#include "InputActionValue.h"



APlayer4XPawn::APlayer4XPawn()
{

 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Hold anc create the spring arm component
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));

	// Attach the spring arm component to the root component
	SpringArmComponent->SetupAttachment(RootComponent);

	// Hold anc create the camera component
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));

	// Attach the camera component to the spring arm component
    CameraComponent->SetupAttachment(SpringArmComponent); 
}


void APlayer4XPawn::BeginPlay()
{

	// Call the parent class' BeginPlay() function
	Super::BeginPlay();
	
	// Hold the characters APlayerController
	APlayerController* PlayerController = Cast<APlayerController>(Controller);

	// Set the controller to show the mouse cursor
	PlayerController->SetShowMouseCursor(true);

	// Check if the APlayerController is not null
	if(PlayerController != nullptr)
	{

		// Hold the APlayerController's UEnhancedInputLocalPlayerSubsystem
		UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());
	
		// Check if the UEnhancedInputLocalPlayerSubsystem is not nullif(Subsystem != nullptr)
		{

			// Add the UInputMapping context to the APlayerController's 
			// UEnhacnedInputLocalPlayerSubsystem
			Subsystem->AddMappingContext(InputMappingContext, 0);
		}
	}
}


void APlayer4XPawn::Tick(float DeltaTime)
{
	// Call the parent class' Tick() function
	Super::Tick(DeltaTime);

	// Check if there is movement 
	if(MovementDirection.Length() > 0.0f)
	{

		// Check if the movement is diagonal
		if(MovementDirection.Length() > 1.0f)
		{

			// Normalize the movement direction
			MovementDirection.Normalize();
		}

		// Hold the distance to move
		FVector2D DistanceToMove = MovementDirection * MovementSpeed * DeltaTime;

		// Hold the current location of the player
		FVector CurrentLocation = GetActorLocation();

		// Set the new horizontal location for the player
		FVector NewLocation = CurrentLocation + FVector(DistanceToMove.X, 0.0f, 0.0f);

		// Check if the new location is in the horizontal map bounds
		if(!IsInMapBoundsHorizontal(NewLocation.X))
		{

			// Set the new location with the movement subtracted
			NewLocation -=  FVector(DistanceToMove.X, 0.0f, 0.0f);
		}

		// Set the new vertical location for the player
		NewLocation += FVector(0.0f, DistanceToMove.Y, 0.0f);

		// Check if the new location is in the vertical map bounds
		if(!IsInMapBoundsVertical(NewLocation.Y))
		{

			// Set the new location with the movement subtracted
			NewLocation -= FVector(0.0f, DistanceToMove.Y, 0.0f);
		}

		// Set the new location for the player
		SetActorLocation(NewLocation); 
	}
}


void APlayer4XPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{

	// Call the parent class' SetupPlayerInputComponent
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	// Hold the UEnhancedInputComponent to bind the input actions
	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	
	// Check if the UEnchancedInputComponent is not nullptr
	if(EnhancedInputComponent != nullptr)
	{

		// Bind the MoveAction & MoveTriggered to the triggered trigger event
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APlayer4XPawn::MoveTriggered);
		
		// Bind the MoveAction & MovementCompleted to the completed trigger event
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Completed, this, &APlayer4XPawn::MoveCompleted);
		
		// Bind the MoveAction & MovementCompleted to the canceled trigger event
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Canceled, this, &APlayer4XPawn::MoveCompleted);
	}
}

void APlayer4XPawn::MoveTriggered(const FInputActionValue &Value)
{
	
	// Hold the move action value from the UInputAction
	FVector2D MoveActionValue = Value.Get<FVector2D>();

	// Set the movement direction using the move action value
	MovementDirection = MoveActionValue;
}

void APlayer4XPawn::MoveCompleted(const FInputActionValue &Value)
{

	// Zero out the movement direction
	MovementDirection = FVector2D(0.0f, 0.0f);
}

bool APlayer4XPawn::IsInMapBoundsHorizontal(float XPosition)
{

    // Hold the result boolean
    bool Result = true;

	// Set the result
	Result = XPosition > HorizontalLimits.X && XPosition < HorizontalLimits.Y;

	// Return the result
	return Result;
}

bool APlayer4XPawn::IsInMapBoundsVertical(float YPosition)
{

    // Hold the result boolean
    bool Result = true;

	// Set the result
	Result = YPosition > VerticalLimits.X && YPosition < VerticalLimits.Y;

	// Return the result
	return Result;
}
