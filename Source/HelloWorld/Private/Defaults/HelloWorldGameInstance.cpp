// PG26 2024


#include "Defaults/HelloWorldGameInstance.h"
#include "Engine.h"
#include "Logging/StructuredLog.h"

DEFINE_LOG_CATEGORY(HelloWorldLog)

void UHelloWorldGameInstance::Init()
{
	Super::Init();

	if (IsValid(GEngine))
	{
		// Printing On Screen
		GEngine->AddOnScreenDebugMessage(INDEX_NONE, 10.0f, DebugColor, *DebugMessage);

		// Loggin In Output Log
		UE_LOGFMT(HelloWorldLog, Display, "Hello {Name}'s World",("Name","Rohit"));
	}
}
