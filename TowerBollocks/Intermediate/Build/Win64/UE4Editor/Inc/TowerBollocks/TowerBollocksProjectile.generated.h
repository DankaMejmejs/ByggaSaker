// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectBase.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UPrimitiveComponent;
struct FVector;
struct FHitResult;
#ifdef TOWERBOLLOCKS_TowerBollocksProjectile_generated_h
#error "TowerBollocksProjectile.generated.h already included, missing '#pragma once' in TowerBollocksProjectile.h"
#endif
#define TOWERBOLLOCKS_TowerBollocksProjectile_generated_h

#define TowerBollocks_Source_TowerBollocks_TowerBollocksProjectile_h_9_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnHit) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_STRUCT(FVector,Z_Param_NormalImpulse); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_Hit); \
		P_FINISH; \
		this->OnHit(Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_NormalImpulse,Z_Param_Out_Hit); \
	}


#define TowerBollocks_Source_TowerBollocks_TowerBollocksProjectile_h_9_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnHit) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_STRUCT(FVector,Z_Param_NormalImpulse); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_Hit); \
		P_FINISH; \
		this->OnHit(Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_NormalImpulse,Z_Param_Out_Hit); \
	}


#define TowerBollocks_Source_TowerBollocks_TowerBollocksProjectile_h_9_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesATowerBollocksProjectile(); \
	friend TOWERBOLLOCKS_API class UClass* Z_Construct_UClass_ATowerBollocksProjectile(); \
	public: \
	DECLARE_CLASS(ATowerBollocksProjectile, AActor, COMPILED_IN_FLAGS(0), 0, TowerBollocks, NO_API) \
	DECLARE_SERIALIZER(ATowerBollocksProjectile) \
	/** Indicates whether the class is compiled into the engine */    enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \
 \
	virtual UObject* _getUObject() const override { return const_cast<ATowerBollocksProjectile*>(this); }


#define TowerBollocks_Source_TowerBollocks_TowerBollocksProjectile_h_9_INCLASS \
	private: \
	static void StaticRegisterNativesATowerBollocksProjectile(); \
	friend TOWERBOLLOCKS_API class UClass* Z_Construct_UClass_ATowerBollocksProjectile(); \
	public: \
	DECLARE_CLASS(ATowerBollocksProjectile, AActor, COMPILED_IN_FLAGS(0), 0, TowerBollocks, NO_API) \
	DECLARE_SERIALIZER(ATowerBollocksProjectile) \
	/** Indicates whether the class is compiled into the engine */    enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \
 \
	virtual UObject* _getUObject() const override { return const_cast<ATowerBollocksProjectile*>(this); }


#define TowerBollocks_Source_TowerBollocks_TowerBollocksProjectile_h_9_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ATowerBollocksProjectile(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ATowerBollocksProjectile) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATowerBollocksProjectile); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATowerBollocksProjectile); \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API ATowerBollocksProjectile(const ATowerBollocksProjectile& InCopy); \
public:


#define TowerBollocks_Source_TowerBollocks_TowerBollocksProjectile_h_9_ENHANCED_CONSTRUCTORS \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API ATowerBollocksProjectile(const ATowerBollocksProjectile& InCopy); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATowerBollocksProjectile); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATowerBollocksProjectile); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ATowerBollocksProjectile)


#define TowerBollocks_Source_TowerBollocks_TowerBollocksProjectile_h_6_PROLOG
#define TowerBollocks_Source_TowerBollocks_TowerBollocksProjectile_h_9_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TowerBollocks_Source_TowerBollocks_TowerBollocksProjectile_h_9_RPC_WRAPPERS \
	TowerBollocks_Source_TowerBollocks_TowerBollocksProjectile_h_9_INCLASS \
	TowerBollocks_Source_TowerBollocks_TowerBollocksProjectile_h_9_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TowerBollocks_Source_TowerBollocks_TowerBollocksProjectile_h_9_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TowerBollocks_Source_TowerBollocks_TowerBollocksProjectile_h_9_RPC_WRAPPERS_NO_PURE_DECLS \
	TowerBollocks_Source_TowerBollocks_TowerBollocksProjectile_h_9_INCLASS_NO_PURE_DECLS \
	TowerBollocks_Source_TowerBollocks_TowerBollocksProjectile_h_9_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TowerBollocks_Source_TowerBollocks_TowerBollocksProjectile_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
