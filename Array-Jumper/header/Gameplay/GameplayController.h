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

        bool isLastLevel();
        void loadNextLevel();
        void gameWon();
        void gameOver();

    public:
        GameplayController();
        ~GameplayController();

        void initialize();
        void update();
        void render();

        void startGame();
        void onPositionChanged(int position);
        void onDeath();
    }
}