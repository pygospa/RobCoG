#pragma once
#include "RobCoG.h"
#include "RUtils.generated.h"


#define Log(text) UE_LOG(LogTemp, Warning, text);
#define Print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::White,text)
#define PrintRed(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Red,text)
#define PrintGreen(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green,text)
#define PrintDur(text, duration) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, duration, FColor::White,text)

/** Enum indicating the hand type */
UENUM(BlueprintType)
enum class ERHandType : uint8
{
	Left		UMETA(DisplayName = "Left"),
	Right		UMETA(DisplayName = "Right"),
};

/** Enum indicating the finger type */
UENUM(BlueprintType)
enum class ERFingerType : uint8
{
	Thumb		UMETA(DisplayName = "Thumb"),
	Index		UMETA(DisplayName = "Index"),
	Middle		UMETA(DisplayName = "Middle"),
	Ring		UMETA(DisplayName = "Ring"),
	Pinky		UMETA(DisplayName = "Pinky"),
};


/** Enum indicating the finger type */
UENUM(BlueprintType)
enum class ERHandLimb : uint8
{
	Thumb		UMETA(DisplayName = "Thumb"),
	Index		UMETA(DisplayName = "Index"),
	Middle		UMETA(DisplayName = "Middle"),
	Ring		UMETA(DisplayName = "Ring"),
	Pinky		UMETA(DisplayName = "Pinky"),
	Palm		UMETA(DisplayName = "Palm")
};

/** Enum indicating the grasp state */
UENUM(BlueprintType)
enum class ERGraspState : uint8
{
	Opened		UMETA(DisplayName = "Opened"),
	Opening		UMETA(DisplayName = "Opening"),
	Closed		UMETA(DisplayName = "Closed"),
	Closing		UMETA(DisplayName = "Closing"),
	Free		UMETA(DisplayName = "Free"),
	Blocked		UMETA(DisplayName = "Blocked"),
	Attached	UMETA(DisplayName = "Attached"),
};


/** Utils */
USTRUCT()
struct FRUtils
{
GENERATED_USTRUCT_BODY()

	// Default constructor	
	FRUtils()
	{
	};

	// Destructor
	~FRUtils()
	{
	};

	// TODO UTIL, get the enum value to string
	// https://wiki.unrealengine.com/Enums_For_Both_C%2B%2B_and_BP#Get_Name_of_Enum_as_String
	template<typename TEnum>
	static FORCEINLINE FString GetEnumValueToString(const FString& Name, TEnum Value)
	{
		const UEnum* EnumPtr = FindObject<UEnum>(ANY_PACKAGE, *Name, true);
		if (!EnumPtr)
		{
			return FString("Invalid");
		}

		return EnumPtr->GetEnumName((int32)Value);
	};
};