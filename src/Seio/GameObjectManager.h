#pragma once

#include <string>
#include <vector>
#include <memory>

#include "Singleton.h"
#include "Sprite.h"

namespace Seio
{
    class GameObjectManager : public Singleton<GameObjectManager>
    {
        friend class Singleton<GameObjectManager>;

        public:
            void CreateSprite(std::string texturePath)
            {
                objects.push_back(std::make_unique<Sprite>(texturePath));
            }

            const std::vector<std::unique_ptr<GameObject>>& GetAllObjects() const
            {
                return objects;
            }

        private:
            std::vector<std::unique_ptr<GameObject>> objects;
    };
}