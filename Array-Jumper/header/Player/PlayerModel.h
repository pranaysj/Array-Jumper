#pragma once
namespace Player
{
	enum class PlayerState
	{
		ALIVE,
		DEATH
	};

	class PlayerModel
	{
	private:
		int current_position;
		PlayerState playerState;

		const int max_lives = 3;
		int current_lives;

	public:
		PlayerModel();
		~PlayerModel();

		void Initialize();

		void SetPlayerState(PlayerState newPlayerState);
		PlayerState GetPlayerState();

		void SetCurrentPosition(int newPositon);
		int GetCurrentPosition();

		void resetPlayer();
		int getCurrentLives();

		void decrementLife();
		void resetPosition();
	};
}