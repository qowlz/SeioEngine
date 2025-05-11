#pragma once

namespace Seio
{
    class GameObject;

    class Component
    {
        public:
            virtual ~Component() = default;
            virtual void OnDrawImGui() {}

            virtual void Update(float dt) {}

            void SetOwner(const GameObject* owner)
            {
                this->owner = owner;
            }

        protected:
            const GameObject* owner;
    };
}