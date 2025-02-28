#pragma once
namespace Player
{
	class PlayerModel;
	class PlayerView;
	enum class PlayerState;

	class PlayerController
	{
	private:
		PlayerModel *playerModel;
		PlayerView *playerView;
		EventService *event_service;

		void Destory();

		void readInput();
		void Move(MovementDirection direction);
		void jump(MovementDirection direction);
		bool IsPositionInBound(int targetPosition);

	public:
		PlayerController();
		~PlayerController();

		void Initialize();
		void Update();
		void Render();

		PlayerState GetPlayerState();
		void SetPlayerState(PlayerState newPlayerState);

		BlockType getCurrentBoxValue(int currentPosition);
		void takeDamage();
	};
}