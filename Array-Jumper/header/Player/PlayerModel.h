#pragma once
namespace Player {
	enum class PlayerState {
		ALIVE,
		DEATH
	};
	
	class PlayerModel {
	private :
		int currentPosition;
		PlayerState playerState;
	public:
		PlayerModel();
		~PlayerModel();

		void Initialize();

		void SetPlayerState(PlayerState newPlayerState);
		PlayerState GetPlayerState();

		void SetCurrentPosition(int newPositon);
		int GetCurrentPosition();
	};
}