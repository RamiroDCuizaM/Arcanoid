// Fill out your copyright notice in the Description page of Project Settings.


#include "Padle_Player_Controller.h"

#include "Kismet/GameplayStatics.h"
#include "Camera/CameraActor.h"
#include <Arcanoid/Padle.h>

//#include "Ball.h"
APadle_Player_Controller::APadle_Player_Controller()
{
}

void APadle_Player_Controller::BeginPlay()
{
	TArray<AActor*> CameraActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACameraActor::StaticClass(), CameraActors);

	FViewTargetTransitionParams Params;
	SetViewTarget(CameraActors[0], Params);
}

void APadle_Player_Controller::SetupInputComponent()
{
	Super::SetupInputComponent();
	EnableInput(this);

	InputComponent->BindAxis("MoveHorizontal", this, &APadle_Player_Controller::MoveHorizontal);

}

void APadle_Player_Controller::MoveHorizontal(float _AxisValue)
{
	auto MyPawn = Cast<APadle>(GetPawn());

	if (MyPawn) {
		MyPawn->MoveHorizontal(_AxisValue);
	}
}
