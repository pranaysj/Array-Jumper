#include"../../header/Player/PlayerView.h"
#include"../../header/Global/Config.h"
#include"../../header/Global/ServiceLocator.h"

namespace Player {
	PlayerView::PlayerView()
	{
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
	}
	void PlayerView::InitializePlayerImage()
	{
		playerImage->initialize(Global::Config::array_jumper_bg_texture_path, playerWeight, playerHeight, sf::Vector2f(0,0));
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
		playerWeight = 1000.0f;
		playerHeight = 1000.0f;
	}
	void PlayerView::UpdatePlayerPosition()
	{
		playerImage->setPosition(CalulcatePlayerPosition());
	}
	sf::Vector2f PlayerView::CalulcatePlayerPosition()
	{
		return sf::Vector2f(0,0);
	}
}