#pragma once
#include "SFML/Graphics.hpp"
#include "../../header/UI/UIElement/ImageView.h"
#include "../../header/Player/PlayerController.h"

namespace Player
{

	class PlayerView
	{
	private:
		Player::PlayerController *playerController;

		sf::RenderWindow *gameWindow;
		UI::UIElement::ImageView *playerImage;

		float playerWeight;
		float playerHeight;

		BoxDimentions current_box_dimensions;

		void InitializePlayerImage();
		void DrawPlayer();
		void LoadPlayer();
		void CalculatePlayerDimensions();
		void UpdatePlayerPosition();
		sf::Vector2f CalulcatePlayerPosition();

	public:
		PlayerView(Player::PlayerController *newplayerController);
		~PlayerView();

		void Initialize();
		void Update();
		void Render();
	};
}