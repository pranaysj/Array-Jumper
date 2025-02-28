#pragma once

namespace Gameplay
{
    class GameplayController
    {
    private:
        void processObstacle();
        bool isObstacle(BlockType value);

        void processEndBlock();
        bool isEndBlock(BlockType value);
        void gameOver();

    public:
        GameplayController();
        ~GameplayController();

        void initialize();
        void update();
        void render();

        void onPositionChanged(int position);
        void onDeath();
    }
}