#pragma once

#include "GameObject.h"

namespace Seio
{
    class Sprite : public GameObject
    {
        public:
            Sprite() = delete;

            Sprite(const std::string& textureName);
    };
}