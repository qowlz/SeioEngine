#pragma once

#include <memory>

#include "Transform.h"
#include "Renderer.h"

namespace Seio
{
    class GameObject
    {
        public:
            GameObject();

            Transform* GetTransform() const
            {
                return transform.get();
            }

            Renderer* GetRenderer() const
            {
                return renderer.get();
            }

        protected:
            std::unique_ptr<Transform> transform;

            std::unique_ptr<Renderer> renderer;
    };
}