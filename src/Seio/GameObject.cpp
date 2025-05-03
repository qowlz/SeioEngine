#include "GameObject.h"

namespace Seio
{
    GameObject::GameObject()
        : transform { std::make_unique<Transform>() }
    {
        AddComponent(this->transform.get());
    }

    void GameObject::Update(float dt)
    {
        for (auto& comp : components)
        {
            comp->Update(dt);
        }
    }

    GameObject::~GameObject()
    {
        for (auto comp : components)
            delete comp;

        components.clear();
    }
}



