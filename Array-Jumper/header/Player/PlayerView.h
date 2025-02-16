#pragma once
#include"SFML/Graphics.hpp"
#include"../../header/UI/UIElement/ImageView.h"

namespace Player{
	class PlayerView {
	private:
		sf::RenderWindow* gameWindow;
		UI::UIElement::ImageView* playerImage;

		float playerWeight;
		float playerHeight;
		
		void InitializePlayerImage(); 
		void DrawPlayer(); 
		void LoadPlayer(); 
		void CalculatePlayerDimensions();
		void UpdatePlayerPosition(); 
		sf::Vector2f CalulcatePlayerPosition();

	public:
		PlayerView();
		~PlayerView();

		void Initialize();
		void Update();
		void Render();
	};
}