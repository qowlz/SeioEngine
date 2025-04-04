#pragma once

#include "GameObject.h"

namespace Seio
{
    class Sprite : public GameObject
    {
        public:
            Sprite() = delete;

            Sprite(std::string texturePath);
    };
}