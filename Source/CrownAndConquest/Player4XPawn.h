// Player4XPawn.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InputAction.h"
#include "InputMappingContext.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Player4XPawn.generated.h"

UCLASS()
class CROWNANDCONQUEST_API APlayer4XPawn : public APawn
{
    GENERATED_BODY()

public:
    
	/**
	 * @brief Handle setting up the UActorComponents for the pawn
	 * @param none
	 * @return APlayer4XPawn
	 */
    APlayer4XPawn();

    
    virtual void Tick(float DeltaTime) override;

    /**
	 * @brief Bind the Input Actions to the EnhancedInputComponent
	 * @param UInputComponent* PlayerInputComponent the input component for 
	 * the player
	 * @return void
	 */
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/**
	 * @brief Handle moving the pawn and changing the flipbook source to the
	 * jog animation
	 * @param FInputActionValue& Value a reference to the FInputActionValue for this
	 * InputAction
	 * @return void
	 */
	void MoveTriggered(const FInputActionValue& Value);

	/**
	 * @brief Handle stopping the pawn and changing the flipbook source to the
	 * idle animation
	 * @param FInputActionValue& Value a refernce to the FInputActionValue for this
	 * InputAction
	 * @return void
	 */
	void MoveCompleted(const FInputActionValue& Value);

		/**
	 * @brief Check if the player is in the horizontal bounds of the map
	 * @param float XPostion the x position of the character
	 * @return bool
	 */
	bool IsInMapBoundsHorizontal(float XPosition);

	/**
	 * @brief Check if the player is in the vertical bounds of the map
	 * @param float ZPosition the z position of the character
	 * @return bool
	 */
	bool IsInMapBoundsVertical(float YPosition);

    // Hold the UInputMappingContext for the input actions
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UInputMappingContext* InputMappingContext;

    // Hold the UInputAction for moving
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UInputAction* MoveAction;

    // Hold the USpringArmComponent for positioning the camera
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    USpringArmComponent* SpringArmComponent;

    // Hold the UCameraComponent for the viewing the game 
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UCameraComponent* CameraComponent;

	// Hold the movement direction for moving
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector2D MovementDirection;

	// Hold the FVector2D that holds the values of the horizontal limits
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector2D HorizontalLimits;

	// Hold the FVector2D that holds the values of the vertical limits
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector2D VerticalLimits;

	// Hold the movement speed for the character
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MovementSpeed = 100.0f;


protected:
    
	/**
	 * @brief Configure BeginPlay to add the UInputMappingContext to the 
	 * player controller's EnhancedInputLocalPlayerSubsystem
	 * @param none
	 * @return void
	 */
    virtual void BeginPlay() override;
};

