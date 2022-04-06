#include "Component.h"
#include "Math/Vector3D.h"

class Transform : public Component
{
public:
    Transform();

    Transform(Transform *parent);

    Transform(Vector3D position, Vector3D rotation, Vector3D scale);

    Transform(Transform *parent, Vector3D position, Vector3D rotation, Vector3D scale);

public:
    Transform *GetParent();

    void SetParent(Transform *parent);

    Vector3D GetPosition();

    void SetPosition(Vector3D position);

    Vector3D GetRotation();

    void SetRotation(Vector3D rotation);

    Vector3D GetScale();

    void SetScale(Vector3D scale);

private:
    Transform *parent;

    Vector3D position;

    Vector3D rotation;

    Vector3D scale;
};