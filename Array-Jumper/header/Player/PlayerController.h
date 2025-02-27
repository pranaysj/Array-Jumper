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

	public:
		PlayerController();
		~PlayerController();

		void Initialize();
		void Update();
		void Render();

		PlayerState GetPlayerState();
		void SetPlayerState(PlayerState newPlayerState);

		void Move(MovementDirection direction);
		bool IsPositionInBound(int targetPosition)
	};
}