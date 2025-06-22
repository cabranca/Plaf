#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleInterface.h"

class FPlafCore : public IModuleInterface
{
public:
	static inline FPlafCore& Get()
	{
		return FModuleManager::LoadModuleChecked<FPlafCore>("PlafCore");
	}

	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded("PlafCore");
	}

	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
