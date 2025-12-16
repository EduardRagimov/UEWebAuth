// Fill free to use it without any credits.

#pragma once

#include "CoreMinimal.h"

#include "Json.h"
#include "JsonObjectConverter.h"
#include "Runtime/Online/HTTP/Public/Http.h"

/**
 * JSON String Helper
 */
static class JsonHelper
{
public:
	template <typename StructType>
	static void StructToJSON(StructType FilledStruct, FString& StringOutput);

	template <typename StructType>
	static void StructFromJSON(FHttpResponsePtr Response, StructType& StructOutput);
};
