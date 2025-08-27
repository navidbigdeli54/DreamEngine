#pragma once

#include "Math/Matrix4D.h"
#include "Math/Vector3D.h"
#include "Math/Point3D.h"

struct FTransform4D : public FMatrix4D
{

public:

	FTransform4D() = default;

	FTransform4D(float M00, float M01, float M02, float M03, float M10, float M11, float M12, float M13, float M20, float M21, float M22, float M23);

	FTransform4D(const FVector3D& First, const FVector3D& Second, const FVector3D& Third, const FPoint3D& Point);

public:

	FVector3D& operator[](int Column);

	const FVector3D& operator[](int Column) const;

public:

	const FPoint3D& GetTranslation() const;

	void SetTranslation(const FPoint3D& Point);

	FTransform4D Inverse() const;
};