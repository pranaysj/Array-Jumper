#include "../../header/Player/PlayerModel.h"

namespace Player
{
	PlayerModel::PlayerModel()
	{
	}
	PlayerModel::~PlayerModel()
	{
	}
	void PlayerModel::Initialize()
	{
		playerState = PlayerState::ALIVE;
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
	void PlayerModel::resetPlayer()
	{
		current_position = 0;
		player_state = PlayerState::ALIVE;
	}
}