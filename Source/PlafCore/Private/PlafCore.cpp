#include "PlafCore.h"
#include "Modules/ModuleManager.h"

#include "Log.h"

void FPlafCore::StartupModule()
{
	UE_LOG(LogPlafCore, Log, TEXT("PlafCore module starting up"));
}

void FPlafCore::ShutdownModule()
{
	UE_LOG(LogPlafCore, Log, TEXT("PlafCore module shutting down"));
}

IMPLEMENT_PRIMARY_GAME_MODULE(FPlafCore, PlafCore, "PlafCore");
