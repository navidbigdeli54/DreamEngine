#include "Math/Vector2D.h"
#include "Math/Vector3D.h"

const Vector2D Vector2D::Zero = Vector2D();
const Vector2D Vector2D::One = Vector2D(1);
const Vector2D Vector2D::Up = Vector2D(0, 1);
const Vector2D Vector2D::Right = Vector2D(1, 0);

const Vector3D Vector3D::Zero = Vector3D();
const Vector3D Vector3D::One = Vector3D(1);
const Vector3D Vector3D::Up = Vector3D(0, 1, 0);
const Vector3D Vector3D::Forward = Vector3D(0, 0, 1);
const Vector3D Vector3D::Right = Vector3D(1, 0, 0);