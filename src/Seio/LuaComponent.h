#pragma once

#include "Component.h"

namespace Seio
{
    class LuaComponent : public Component
    {
        void Update(float dt) override;
    };
}