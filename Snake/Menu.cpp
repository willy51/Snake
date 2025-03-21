#include "Menu.h"

Menu::Menu(RenderWindow& window, int score) : window(window), lastScore(score)
{
}

void Menu::menuWindow() {

	Texture texture;
	if (!texture.loadFromFile("res/Logo.jpg")) {
		cout << "Logo not found" << endl;
	}
	Sprite sprite(texture);
	sprite.setScale({ 0.3,0.3 });
	sprite.setOrigin({ sprite.getLocalBounds().size.x / 2,sprite.getLocalBounds().size.y / 2 });
	Input input;
	TextFont TextFont;
	Font font = TextFont.getFont();
	Text ExitText(font);
	Text PlayText(font);
	Text ScoreText(font);
	TextFont.SetText(PlayText, "PLAY");
	TextFont.SetText(ExitText, "EXIT");
	ScoreText.setString("Last score : " + std::to_string(lastScore));


	FloatRect playBounds = PlayText.getLocalBounds();
	PlayText.setOrigin({ playBounds.size.x / 2.f, playBounds.size.y / 2.f });

	FloatRect exitBounds = ExitText.getLocalBounds();
	ExitText.setOrigin({ exitBounds.size.x / 2.f, exitBounds.size.y / 2.f });

	FloatRect scoreBounds = ScoreText.getLocalBounds();
	ScoreText.setOrigin({ scoreBounds.size.x / 2.f, scoreBounds.size.y / 2.f });

	ExitText.setPosition({ WIN_WIDTH / 2.f, WIN_HEIGHT / 2.f + 150.f });
	PlayText.setPosition({ WIN_WIDTH / 2.f, WIN_HEIGHT / 2.f +100.f });
	ScoreText.setPosition({ WIN_WIDTH / 2.f, WIN_HEIGHT / 2.f +50 });
	sprite.setPosition({ WIN_WIDTH / 2.f, WIN_HEIGHT / 2.f - 150.f });

	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(FRAME_RATE);

	int selectedIndex = 0;
	bool keyPressed = false;

	while (window.isOpen()) {
		while (const std::optional<sf::Event> event = window.pollEvent()) {
			input.InputHandler(event, window);

			if (event->is<Event::Closed>()) {
				window.close();
			}

			if (event->is<Event::KeyPressed>() && !keyPressed) {
				keyPressed = true;
				auto key = event->getIf<Event::KeyPressed>()->code;
				if (key == Keyboard::Key::Down || key == Keyboard::Key::Up) {
					selectedIndex = (selectedIndex + 1) % 2;
				}
				if (key == Keyboard::Key::Enter || key == Keyboard::Key::Space ) {
					if (selectedIndex == 0) {
						launchGame();
						return;
					}
					else if (selectedIndex == 1) {
						window.close();
					}
				}

			}

			if (event->is<Event::KeyReleased>()) {
				keyPressed = false;
			}
		}

		int lastIndex = -1;

		if (selectedIndex != lastIndex) {
			lastIndex = selectedIndex;

			if (selectedIndex == 0) {
				PlayText.setFillColor(sf::Color::Red);
				PlayText.setStyle(sf::Text::Bold);
				PlayText.setString("<PLAY>");

				ExitText.setFillColor(sf::Color::White);
				ExitText.setStyle(sf::Text::Regular);
				ExitText.setString("EXIT");
			}
			else {
				PlayText.setFillColor(sf::Color::White);
				PlayText.setStyle(sf::Text::Regular);
				PlayText.setString("PLAY");

				ExitText.setFillColor(sf::Color::Red);
				ExitText.setStyle(sf::Text::Bold);
				ExitText.setString("<EXIT>");
			}

			FloatRect playBounds = PlayText.getLocalBounds();
			PlayText.setOrigin({ playBounds.size.x / 2.f, playBounds.size.y / 2.f });

			FloatRect exitBounds = ExitText.getLocalBounds();
			ExitText.setOrigin({ exitBounds.size.x / 2.f, exitBounds.size.y / 2.f });

		}

		Color color(49, 22, 45);
		window.clear(color);
		window.draw(PlayText);
		window.draw(ExitText);
		window.draw(ScoreText);
		window.draw(sprite);
		window.display();
	}
}


void Menu::launchGame()
{
	Snake snake;
	Game game(window,snake);
	game.start();
}


