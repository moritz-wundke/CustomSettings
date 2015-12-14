// Copyright 2015 Moritz Wundke. All Rights Reserved.
// Released under MIT, see LICENSE for detailed information.

#pragma once

#include "CustomGameSettings.generated.h"

/**
 * Setting object used to hold both config settings and editable ones in one place
 * To ensure the settings are saved to the specified config file make sure to add
 * props using the globalconfig or config meta.
 */
UCLASS(config = Game, defaultconfig)
class UCustomGameSettings : public UObject
{
	GENERATED_BODY()

public:
	UCustomGameSettings(const FObjectInitializer& ObjectInitializer);

	/** Sample bool property */
	UPROPERTY(EditAnywhere, config, Category = Custom)
	bool bSampleBool;

	/** Sample float property that requires a restart */
	UPROPERTY(EditAnywhere, config, Category = Custom, meta = (ConfigRestartRequired = true))
	float SampleFloatRequireRestart;

	/** Sample string list */
	UPROPERTY(config, EditAnywhere, Category = Custom)
	TArray<FString> SampleStringList;

	/** Or add min, max or clamp values to the settings */
	UPROPERTY(config, EditAnywhere, Category = Custom, meta = (UIMin = 1, ClampMin = 1))
	int32 ClampedIntSetting;

	/** We can even use asset references */
	UPROPERTY(config, EditAnywhere, Category = Materials, meta = (AllowedClasses = "MaterialInterface"))
	FStringAssetReference StringMaterialAssetReference;

};
