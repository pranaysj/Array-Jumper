#pragma once

namespace Gameplay
{
    class GameplayController
    {
    private:
        void processObstacle();
        bool isObstacle(BlockType value);

    public:
        GameplayController();
        ~GameplayController();

        void initialize();
        void update();
        void render();

        void onPositionChanged(int position);
    }
}