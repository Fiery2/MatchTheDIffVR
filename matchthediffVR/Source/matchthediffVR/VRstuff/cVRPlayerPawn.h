// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "cPlayerHandAnimBP.h"
#include "Engine.h"
#include "GameFramework/Pawn.h"
#include "HeadMountedDisplay.h"
#include "SteamVRChaperoneComponent.h"
#include "MotionControllerComponent.h"
#include "XRMotionControllerBase.h"
#include "matchthediffVR/Interactables.h"

#include "cVRPlayerPawn.generated.h"

UCLASS()
class MATCHTHEDIFFVR_API AcVRPlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AcVRPlayerPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
private:
	
	bool IsHighlighting = false;
	AInteractables* CurHighlighted;
	void CacheHandAnimInstances();
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USkeletalMeshComponent* m_meshLeftHand;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USkeletalMeshComponent* m_meshRightHand;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UcPlayerHandAnimBP* m_refLeftHandAnimBP;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UcPlayerHandAnimBP* m_refRightHandAnimBP;
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	void CreateComponents();

	void CreateHandController(USceneComponent* a_compParent, FName a_strDisplayName, FName a_nameHandType);

	
	USkeletalMeshComponent* CreateHandMesh(UMotionControllerComponent* a_compParent, FName a_strDisplayName,FName a_nameHandType);

	void SetHandAnimationBlueprint(USkeletalMeshComponent* a_refHand);

	UFUNCTION (BlueprintNativeEvent, Category = "Input")
	void GripLeftHand_Pressed();
	UFUNCTION(BlueprintNativeEvent, Category = "Input")
	void GripRightHand_Pressed();
	UFUNCTION (BlueprintNativeEvent, Category = "Input")
	void GripLeftHand_Released();
	UFUNCTION(BlueprintNativeEvent, Category = "Input")
	void GripRightHand_Released();
	UFUNCTION(BlueprintNativeEvent, Category = "Input")
	void ForwardMove(float Value);
	UFUNCTION(BlueprintNativeEvent, Category = "Input")
	void RightMove(float Value);
};
