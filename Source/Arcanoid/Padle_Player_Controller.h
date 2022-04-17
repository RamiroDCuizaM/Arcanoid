// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Padle_Player_Controller.generated.h"

//class ABall

UCLASS()
class ARCANOID_API APadle_Player_Controller : public APlayerController
{
	GENERATED_BODY()
		APadle_Player_Controller();

	UFUNCTION()
		virtual void SetupInputComponent() override;

protected:

	virtual void BeginPlay() override;

	void MoveHorizontal(float _AxisValue);
	
	//ball references
};
