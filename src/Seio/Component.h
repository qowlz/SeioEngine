#pragma once

namespace Seio
{
    class Component
    {
        public:
            virtual ~Component() = default;
            virtual void OnDrawImGui() = 0;

            virtual void Update(float dt) = 0;
    };
}