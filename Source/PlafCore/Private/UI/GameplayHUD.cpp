#include "UI/GameplayHUD.h"

#include "UI/AttributesWidget.h"
#include "Log.h"

void AGameplayHUD::Init()
{
	AttributeWidget = CreateWidget<UAttributesWidget>(GetOwningPlayerController(), AttributeWidgetClass);
	AttributeWidget->BindToAttributes();
	AttributeWidget->AddToViewport();
}