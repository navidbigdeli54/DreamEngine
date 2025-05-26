//#include <catch2/catch_test_macros.hpp>
//#include "Component/Transform.h"
//
//TEST_CASE("Transform::Transform", "Tranform")
//{
//    Transform transform;
//
//    REQUIRE(transform.GetParent() == nullptr);
//    REQUIRE(transform.GetPosition() == Vector3D::Zero);
//    REQUIRE(transform.GetRotation() == Vector3D::Zero);
//    REQUIRE(transform.GetScale() == Vector3D::One);
//}
//
//TEST_CASE("Transform::Transform(Transform*)", "Tranform")
//{
//    Transform *parent = new Transform();
//    Transform child(parent);
//
//    REQUIRE(child.GetParent() == parent);
//    REQUIRE(child.GetPosition() == Vector3D::Zero);
//    REQUIRE(child.GetRotation() == Vector3D::Zero);
//    REQUIRE(child.GetScale() == Vector3D::One);
//
//    delete (parent);
//}
//
//TEST_CASE("Transform::Transform(Transform*, Vector3D, Vector3D, Vector3D)", "Tranform")
//{
//    Transform *parent = new Transform();
//    Transform child(parent, Vector3D::Up, Vector3D::Forward, Vector3D::Right);
//
//    REQUIRE(child.GetParent() == parent);
//    REQUIRE(child.GetPosition() == Vector3D::Up);
//    REQUIRE(child.GetRotation() == Vector3D::Forward);
//    REQUIRE(child.GetScale() == Vector3D::Right);
//
//    delete (parent);
//}
//
//TEST_CASE("Transform::Transform(Vector3D, Vector3D, Vector3D)", "Tranform")
//{
//    Transform child(Vector3D::Up, Vector3D::Forward, Vector3D::Right);
//
//    REQUIRE(child.GetParent() == nullptr);
//    REQUIRE(child.GetPosition() == Vector3D::Up);
//    REQUIRE(child.GetRotation() == Vector3D::Forward);
//    REQUIRE(child.GetScale() == Vector3D::Right);
//}
//
//TEST_CASE("Transform::GetParent", "Transform")
//{
//    Transform *parent = new Transform();
//    Transform child(parent);
//
//    REQUIRE(child.GetParent() == parent);
//
//    delete (parent);
//}
//
//TEST_CASE("Transform::SetParent", "Transform")
//{
//    Transform *parent = new Transform();
//    Transform child;
//    child.SetParent(parent);
//
//    REQUIRE(child.GetParent() == parent);
//
//    delete (parent);
//}
//
//TEST_CASE("Transform::GetPosition", "Tranform")
//{
//    Transform transform(Vector3D::One, Vector3D::Zero, Vector3D::Zero);
//
//    REQUIRE(transform.GetPosition() == Vector3D::One);
//}
//
//TEST_CASE("Transform::SetPosition", "Tranform")
//{
//    Transform transform;
//    transform.SetPosition(Vector3D::One);
//    REQUIRE(transform.GetPosition() == Vector3D::One);
//}
//
//TEST_CASE("Transform::GetRotation", "Tranform")
//{
//    Transform transform(Vector3D::Zero, Vector3D::One, Vector3D::Zero);
//
//    REQUIRE(transform.GetRotation() == Vector3D::One);
//}
//
//TEST_CASE("Transform::SetRotation", "Tranform")
//{
//    Transform transform;
//    transform.SetRotation(Vector3D::One);
//    REQUIRE(transform.GetRotation() == Vector3D::One);
//}
//
//TEST_CASE("Transform::GetScale", "Tranform")
//{
//    Transform transform(Vector3D::Zero, Vector3D::Zero, Vector3D::One);
//
//    REQUIRE(transform.GetScale() == Vector3D::One);
//}
//
//TEST_CASE("Transform::SetScale", "Tranform")
//{
//    Transform transform;
//    transform.SetScale(Vector3D::One);
//    REQUIRE(transform.GetScale() == Vector3D::One);
//}