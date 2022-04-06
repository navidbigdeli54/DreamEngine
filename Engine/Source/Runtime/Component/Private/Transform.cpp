#include "Transform.h"

Transform::Transform() : parent(nullptr), position(Vector3D::Zero), rotation(Vector3D::Zero), scale(Vector3D::One)
{
}

Transform::Transform(Transform *parent) : parent(parent), position(Vector3D::Zero), rotation(Vector3D::Zero), scale(Vector3D::One)
{
}

Transform::Transform(Vector3D position, Vector3D rotation, Vector3D scale) : parent(nullptr), position(position), rotation(rotation), scale(scale)
{
}

Transform::Transform(Transform *parent, Vector3D position, Vector3D rotation, Vector3D scale) : parent(parent), position(position), rotation(rotation), scale(scale)
{
}

Transform *Transform::GetParent()
{
    return parent;
}

void Transform::SetParent(Transform *parent)
{
    this->parent = parent;
}

Vector3D Transform::GetPosition()
{
    return position;
}

void Transform::SetPosition(Vector3D position)
{
    this->position = position;
}

Vector3D Transform::GetRotation()
{
    return rotation;
}

void Transform::SetRotation(Vector3D rotation)
{
    this->rotation = rotation;
}

Vector3D Transform::GetScale()
{
    return scale;
}

void Transform::SetScale(Vector3D scale)
{
    this->scale = scale;
}