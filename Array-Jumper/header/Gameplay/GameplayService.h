#pragma once

namespace Gameplay
{
    class GameplayService
    {
    private:
        GameplayController *gameplay_controller;

        void onPositionChanged(int position);

    public:
        GameplayService();
        ~GameplayService();

        void initialize();
        void update();
        void render();
    }
}