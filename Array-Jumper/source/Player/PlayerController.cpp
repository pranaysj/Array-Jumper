#include "../../header/Player/PlayerController.h"
#include "../../header/Player/PlayerModel.h"
#include "../../header/Player/PlayerView.h"

namespace Player
{
	PlayerController::PlayerController()
	{
		playerModel = new PlayerModel();
		playerView = new PlayerView(this);
	}
	PlayerController::~PlayerController()
	{
		Destory();
	}
	void PlayerController::Initialize()
	{
		playerView->Initialize();
		playerModel->Initialize();

		event_service = ServiceLocator::getInstance()->getEventService();
	}
	void PlayerController::Update()
	{
		playerView->Update();
	}
	void PlayerController::Render()
	{
		playerView->Render();
	}
	void PlayerController::Destory()
	{
		delete (playerModel);
		delete (playerView);
	}
	PlayerState PlayerController::GetPlayerState()
	{
		return playerModel->GetPlayerState();
	}
	void PlayerController::SetPlayerState(PlayerState newPlayerState)
	{
		playerModel->SetPlayerState(newPlayerState);
	}

	bool PlayerController::isPositionInBound(int targetPosition)
	{
		if (targetPosition >= 0 && targetPosition < LevelData::NUMBER_OF_BOXES)
			return true;
		return false;
	}
	void PlayerController::Move(MovementDirection direction)
	{
		int steps, targetPosition;
		switch (direction)
		{
		case MovementDirection::FORWARD:
			steps = 1;
			break;
		case MovementDirection::BACKWARD:
			steps = -1;
			break;
		default:
			steps = 0;
			break;
		}

		targetPosition = player_model->GetCurrentPosition() + steps;

		if (!isPositionInBound(targetPosition))
			return;

		player_model->SetCurrentPosition(targetPosition);
		ServiceLocator::GetInstance()->getSoundService()->playSound(SoundType::MOVE);
	}
	void PlayerController::readInput()
	{
		if (event_service->pressedRightArrowKey() || event_service->pressedDKey())
		{
			Move(MovementDirection::FORWARD);
		}
		if (event_service->pressedLeftArrowKey() || event_service->pressedAKey())
		{
			Move(MovementDirection::BACKWARD);
		}
	}
}