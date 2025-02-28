#include "../../header/Gameplay/GameplayService.h"

namespace Gameplay
{
    GameplayController::GameplayService()
    {
        gameplay_controller = new GameplayController();
    }
    GameplayController::~GameplayService()
    {
    }
    void GameplayController::initialize()
    {
        gameplay_controller->initialize();
    }
    void GameplayController::update()
    {
        gameplay_controller->update();
    }
    void GameplayController::render()
    {
        gameplay_controller->render();
    }
    void onPositionChanged(int position)
    {
        gameplay_controller->onPosiitonChanged(position);
    }
}
