#include <SFML/Graphics.hpp>
#include "map.h"
#include<sstream>

using namespace sf;


float offsetX = 0, offsetY = 0;





class PLAYER {

public:

	float dx, dy;
	FloatRect rect;
	bool onGround;
	Sprite sprite;
	float currentFrame;
	int coins;
	int positionX;
	int positionY;

	PLAYER(Texture &image)
	{
		sprite.setTexture(image);
		rect = FloatRect(1 * 32, 1 * 32, 40, 50);
		coins = 0;
		dx = dy = 0.1;
		currentFrame = 0;
	}


	void update(float time)
	{

		rect.left += dx * time;
		Collision(0);
		Collision1(0);

		if (!onGround) dy = dy + 0.0005*time;
		rect.top += dy*time;
		onGround = false;
		Collision(1);
		Collision1(1);


		currentFrame += 0.005*time;
		if (currentFrame > 6) currentFrame -= 6;

		if (dx > 0)sprite.setTextureRect(IntRect(40 * int(currentFrame), 0, 40, 50));
		if (dx < 0)sprite.setTextureRect(IntRect(40 * int(currentFrame) + 40, 0, -40, 50));

		sprite.setPosition(rect.left - offsetX, rect.top - offsetY);

		dx = 0;
	}


	void Collision1(int dir)
	{
		for (int i = rect.top / 32; i < (rect.top + rect.height) / 32; i++)
			for (int j = rect.left / 32; j < (rect.left + rect.width) / 32; j++)
			{
				if (TileMap1[i][j] == 'B')
				{
					if ((dx > 0) && (dir == 0)) rect.left = j * 32 - rect.width;
					if ((dx < 0) && (dir == 0)) rect.left = j * 32 + 32;
					if ((dy > 0) && (dir == 1)) { rect.top = i * 32 - rect.height;  dy = 0;   onGround = true; }
					if ((dy < 0) && (dir == 1)) { rect.top = i * 32 + 32;   dy = 0; }
				}

				if (TileMap1[i][j] == '0')
				{
				
					TileMap1[i][j] = ' ';


				}

			}
	}


	void Collision(int dir)
	{
		for (int i = rect.top / 32; i < (rect.top + rect.height) / 32; i++)
			for (int j = rect.left / 32; j < (rect.left + rect.width) / 32; j++)
			{
				if (TileMap[i][j] == 'B')
				{
					if ((dx > 0) && (dir == 0)) rect.left = j * 32 - rect.width;
					if ((dx < 0) && (dir == 0)) rect.left = j * 32 + 32;
					if ((dy > 0) && (dir == 1)) { rect.top = i * 32 - rect.height;  dy = 0;   onGround = true; }
					if ((dy < 0) && (dir == 1)) { rect.top = i * 32 + 32;   dy = 0; }
				}

				if (TileMap[i][j] == '0')
				{
					
					TileMap[i][j] = ' ';
					++coins;

					
				}

			}
		
	}
	

	void PLAYER_WALK() {
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			dx = -0.1;

		}

		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			dx = 0.1;
		}

		if (Keyboard::isKeyPressed(Keyboard::Space))
		{
			if (onGround) { dy = -0.35; onGround = false; }
		}
	}

};





void Game() {
	RenderWindow window(VideoMode(600, 400), "Test!");
	Font font;
	font.loadFromFile("CyrilicOld.ttf");
	Text text("", font, 20);
	Text text1("", font, 20);
	text.setStyle(Text::Bold);
	text1.setStyle(Text::Bold);
	Texture t;
	t.loadFromFile("C:/SFML_App/Teste/image/GG1.png");


	Image map_image;
	map_image.loadFromFile("C:/SFML_App/Teste/image/texture.png");
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);

	float currentFrame = 0;

	PLAYER p(t);


	Clock clock;

	RectangleShape rectangle(Vector2f(32, 32));
	while (window.isOpen())
	{
		if (p.coins >= 10) {
			for (int i = 0; i < 12; ++i) {
				TileMap[i] = TileMap1[i];
			}
		}
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();

		time = time / 700;

		if (time > 20) time = 20;

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		p.PLAYER_WALK();

		p.update(time);

		if (p.rect.left > 300) offsetX = p.rect.left - 300;
		offsetY = p.rect.top - 200;


		window.clear(Color::Black);
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++)
			{
				if (TileMap[i][j] == 'B') s_map.setTextureRect(IntRect(0, 0, 32, 32));

				if (TileMap[i][j] == '0')  s_map.setTextureRect(IntRect(60, 0, 32, 32));

				if (TileMap[i][j] == ' ') continue;

				s_map.setPosition(j * 32 - offsetX, i * 32 - offsetY);
				window.draw(s_map);
			}
		}

		for (int i = 0; i < H; i++)
				for (int j = 0; j < W; j++)
				{
					if (TileMap1[i][j] == 'B') s_map.setTextureRect(IntRect(0, 0, 32, 32));

					if (TileMap1[i][j] == '0')  s_map.setTextureRect(IntRect(60, 0, 32, 32));

					if (TileMap1[i][j] == ' ') continue;

					s_map.setPosition(j * 32 - offsetX, i * 32 - offsetY);
					
				}

		if(p.coins > 20)
		{
			window.clear(Color::Black);
			text1.setString("All Coins are collected");
			text1.setPosition(200, 30);
			window.draw(text1);
			
		

		}

	
		
				std::ostringstream playerScoreString;
				playerScoreString << p.coins;

				text.setString("Coins :  " + playerScoreString.str());
				text.setPosition(30, 30);

				window.draw(text);
				window.draw(p.sprite);
				window.display();
			
			}
	
	}

	



int main()
{
	Game();


	return 0;
}
