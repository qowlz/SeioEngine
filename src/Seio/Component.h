#pragma once

namespace Seio
{
    class Component
    {
        public:
            virtual ~Component() = default;
            virtual void OnDrawImGui() {}

            virtual void Update(float dt) {}
    };
}