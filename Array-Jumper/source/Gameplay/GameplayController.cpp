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
        if (isEndBlock(value))
            processEndBlock();
    }
    bool GameplayController::isEndBlock(Level::BlockType value)
    {
        if (value == BlockType::TARGET)
            return true;
        return false;
    }
    void GameplayController::processEndBlock()
    {
        ServiceLocator::getInstance()->getPlayerService()->levelComplete();
        ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::LEVEL_COMPLETE);
        if (isLastLevel())
        {
            gameWon();
            return;
        }

        loadNextLevel();
    }
    void GameplayController::gameOver()
    {
        GameService::setGameState(GameState::CREDITS);
        ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::DEATH);
    }
    void GameplayController::onDeath()
    {
        gameOver();
    }
    void GameplayController::gameWon()
    {
        GameService::setGameState(GameState::CREDITS);
        ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::GAME_WON);
    }
    void GameplayController::loadNextLevel()
    {
        ServiceLocator::getInstance()->getLevelService()->loadNextLevel();
    }
    bool GameplayController::isLastLevel()
    {
        return ServiceLocator::getInstance()->getLevelService()->isLastLevel();
    }
    void GameplayController::startGame()
    {
        GameService::setGameState(GameState::GAMEPLAY);
        return ServiceLocator::getInstance()->getLevelService()->resetLevels();
        return ServiceLocator::getInstance()->getPlayerService()->resetPlayer();
    }
}
