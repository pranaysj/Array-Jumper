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
		current_position = newPositon;
	}
	int PlayerModel::GetCurrentPosition()
	{
		return current_position;
	}
	void PlayerModel::resetPlayer()
	{
		current_position = 0;
		player_state = PlayerState::ALIVE;
		current_lives = max_lives;
	}
	int PLayModel::getCurrentLives()
	{
		return current_lives;
	}
	void PlayerModel::decrementLife()
	{
		current_lives--;
	}
	void PlayModel::resetPosition()
	{
		current_position = 0;
	}
}