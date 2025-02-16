#include"../../header/Player/PlayerModel.h"

namespace Player {
	PlayerModel::PlayerModel()
	{
	}
	PlayerModel::~PlayerModel()
	{
	}
	void PlayerModel::SetPlayerState(PlayerState newPlayerState)
	{
		playerState = newPlayerState;
	}
	PlayerState PlayerModel::GetPlayerState()
	{
		return playerState;
	}
	void PlayerModel::SetCurrentPosition(int newPositon)
	{
		currentPosition = newPositon;
	}
	int PlayerModel::GetCurrentPosition()
	{
		return currentPosition;
	}
}