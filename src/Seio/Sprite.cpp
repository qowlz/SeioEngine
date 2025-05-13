#include "Sprite.h"

#include <memory>


#include "SpriteRenderer.h"

namespace Seio
{
    Sprite::Sprite(std::string texturePath)
    {
        renderer = std::make_unique<SpriteRenderer>(texturePath); // TODO: texturePath를 전파하는 방식말고 더 나은 방법이 없을까? 생성자가 종속되는 느낌이다.
        AddComponent(renderer.get());
    }
}