#pragma once

#include <memory>

#include "Transform.h"
#include "Renderer.h"
#include "Component.h"

namespace Seio
{
    class GameObject
    {
        public:
            GameObject();

            virtual ~GameObject();

            void Update(float dt);

            void AddComponent(Component* comp)
            {
                comp->SetOwner(this);
                components.push_back(comp);
            }

            Transform* GetTransform() const
            {
                return transform.get();
            }

            Renderer* GetRenderer() const
            {
                return renderer.get();
            }

            const std::vector<Component*>& GetComponents() const
            {
                return components;
            }

        protected:
            std::unique_ptr<Transform> transform;

            std::unique_ptr<Renderer> renderer;

            std::vector<Component*> components;
    };
}