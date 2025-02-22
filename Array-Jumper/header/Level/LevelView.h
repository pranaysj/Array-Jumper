#pragma once
#include "../../header/Level/LevelController.h"
#include "../../header/UI/UIElement/ImageView.h"

namespace Level
{
	class LevelView
	{
	private:
		sf::RenderWindow *game_window;
		Level::LevelController *level_controller;

		UI::UIElement::ImageView *background_image;
		const float background_alpha = 110.f;

		UI::UIElement::ImageView *box_image;

		UI::UIElement::ImageView *target_overlay_image;
		UI::UIElement::ImageView *letter_one_overlay_image;
		UI::UIElement::ImageView *letter_two_overlay_image;
		UI::UIElement::ImageView *letter_three_overlay_image;
		UI::UIElement::ImageView *obstacle_one_overlay_image;
		UI::UIElement::ImageView *obstacle_two_overlay_image;

		BoxDimensions box_dimensions;
		void CalculateBoxDimensions();
		UI::UIElement::ImageView *GetBoxOverlayImage(BlockType block_type);
		void CalculateBoxWidthHeight();
		void CalculateBoxSpacing();
		sf::Vector2f CalculateBoxPosition(int index);
		BoxDimensions GetBoxDimensions();

		void createImages();
		void initializeImages();
		void updateImages();
		void drawLevel();
		void drawBox(sf::Vector2f position);
		void drawBoxValue(sf::Vector2f position, BlockType box_value);
		void deleteImages();

	public:
		LevelView(LevelController *controller);
		~LevelView();

		void initialize();
		void update();
		void render();
	};
}
