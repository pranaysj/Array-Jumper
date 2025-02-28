#include "../../header/Player/PlayerView.h"
#include "../../header/Global/Config.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Player/PlayerModel.h"

namespace Player
{
	PlayerView::PlayerView(Player::PlayerController *newplayerController)
	{
		playerController = newplayerController;
		gameWindow = nullptr;
		playerImage = new UI::UIElement::ImageView();
	}
	PlayerView::~PlayerView()
	{
	}
	void PlayerView::Initialize()
	{
		gameWindow = Global::ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		LoadPlayer();
	}
	void PlayerView::Update()
	{
	}
	void PlayerView::Render()
	{
		switch (playerController->GetPlayerState())
		{
		case Player::PlayerState::ALIVE:
			DrawPlayer();

		default:
			break;
		}
	}
	void PlayerView::InitializePlayerImage()
	{
		playerImage->initialize(Global::Config::character_texture_path, playerWeight, playerHeight, sf::Vector2f(0, 0));
	}
	void PlayerView::DrawPlayer()
	{
		playerImage->render();
	}
	void PlayerView::LoadPlayer()
	{
		CalculatePlayerDimensions();
		InitializePlayerImage();
	}
	void PlayerView::CalculatePlayerDimensions()
	{
		current_box_dimensions = ServiceLocator::getInstance()->getLevelService()->getBoxDimensions();
		player_height = current_box_dimensions.box_height;
		player_width = current_box_dimensions.box_width;
	}
	void PlayerView::UpdatePlayerPosition()
	{
		playerImage->setPosition(CalulcatePlayerPosition());
	}
	sf::Vector2f PlayerView::calulcatePlayerPosition()
	{
		float xPosition = current_box_dimensions.box_spacing + static_cast<float>(player_controller->getCurrentPosition()) * (current_box_dimensions.box_width + current_box_dimensions.box_spacing);
		float yPosition = static_cast<float>(game_window->getSize().y) - current_box_dimensions.box_height - current_box_dimensions.bottom_offset - player_height;
		return sf::Vector2f(xPosition, yPosition);
	}
}