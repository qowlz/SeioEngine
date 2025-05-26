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
        // FIXME: 현재 SpriteRenderer와 Transform이 unique_ptr로 잡혀있기 때문에 여기서 메모리를 해제해주면, seg fault가 남.
        // FIXME: GetComponent 기능을 만들고 난뒤에 주석을 풀어주기
        // for (auto comp : components)
        //     delete comp;
    }
}



