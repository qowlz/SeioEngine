#include "GameObject.h"

namespace Seio
{
    GameObject::GameObject()
        : transform { std::make_unique<Transform>() }
    {
    }
}



