#include "Sprite.h"

#include <memory>


#include "SpriteRenderer.h"

namespace Seio
{
    Sprite::Sprite(const std::string& textureName)
    {
        AddComponent(new SpriteRenderer { textureName });
    }
}