#include "../../header/Player/PlayerService.h"
#include "../../header/Player/PlayerController.h"

namespace Player
{
	PlayerService::PlayerService()
	{
		playerController = new PlayerController();
	}
	PlayerService::~PlayerService()
	{
		Destory();
	}
	void PlayerService::Initialize()
	{
		playerController->Initialize();
	}
	void PlayerService::Update()
	{
		playerController->Update();
	}
	void PlayerService::Render()
	{
		playerController->Render();
	}
	void PlayerService::Destory()
	{
		delete (playerController);
	}
	void PlayerService::takeDamage()
	{
		player_controller->takeDamage();
	}
	void PlayerService::levelComplete()
	{
		player_controller->resetPlayer();
	}
}