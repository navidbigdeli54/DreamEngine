#include "Object.h"
#include "Collection/List.h"
#include "Component/Component.h"

class Actor : public Object
{
public:
    Actor();

private:
    List<Component *> components;
};