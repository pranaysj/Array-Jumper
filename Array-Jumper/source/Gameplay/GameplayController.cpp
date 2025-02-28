#include "../../header/Gameplay/GameplayController.h"

namespace Gameplay
{
    GameplayController::GameplayController()
    {
    }
    GameplayController::~GameplayController()
    {
    }
    GameplayController::initialize()
    {
    }
    GameplayController::update()
    {
    }
    GameplayController::render()
    {
    }
    void GameplayController::processObstacle()
    {
        ServiceLocator::getInstance()->getPlayerService()->takeDamage();
        ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::DEATH);
    }
    bool GameplayController::isObstacle(Level::BlockType value)
    {
        if (value == BlockType::OBSTACLE_ONE || value == BlockType::OBSTACLE_TWO)
            return true;
        return false;
    }
    void GameplayController::onPositionChanged(int position)
    {
        BlockType value = ServiceLocator::getInstance()->getLevelService()->getCurrentBoxValue(position);

        if (isObstacle(value))
            processObstacle();
    }
}
