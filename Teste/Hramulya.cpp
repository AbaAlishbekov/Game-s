//#include <SFML\Graphics.hpp>
//
//
//using namespace sf;
//
//int ground = 400;
//
//
//const int H = 12;
//const int W = 48;
//
//String TileMap[H] = {
//
//	"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
//	"B                                        B     B",
//	"B                                        B     B",
//	"B                                        B     B",
//	"B                                        B     B",
//	"B                                   BBBBBB     B",
//	"B               00                       B     B",
//	"B               BB                       BB    B",
//	"B               BB        000000               B",
//	"B               BB                             B",
//	"B               BB                             B",
//	"BBBBBBBB    BBBBBBBBBB    BBBBBBBBBBBBBBBBBBBBBBB",
//	
//
//
//};
//
//
//
//
//
//class Player {
//public:
//	float dx, dy;
//	FloatRect rect;
//	bool onGround;
//	Sprite sprite;
//	float currentFrame;
//
//	
//
//
//
//	Player(Texture &image)
//	{
//		sprite.setTexture(image);
//		rect = FloatRect(1*32, 1*32, 40, 50);
//
//		dx = dy = 0.1;
//		currentFrame = 0;
//	}
//
//	void update(float time)
//	{
//		rect.left += dx*time;
//		if (!onGround) dy = dy + 0.0005*time;
//		rect.top += dy*time;
//		onGround = false;
//		if (rect.top > ground) 
//		{
//			rect.top = ground;
//			dy = 0;
//			onGround = true;
//		}
//		currentFrame += 0.005 *time;
//		if (currentFrame > 5) currentFrame -= 5;
//		{
//			if (dx>0)sprite.setTextureRect(IntRect(40 * int(currentFrame), 0, 40, 50));
//			if (dx<0)sprite.setTextureRect(IntRect(40 * int(currentFrame) + 40, 0, -40, 50));
//		}
//
//
//
//		sprite.setPosition(rect.left, rect.top);
//		
//		dx = 0;
//	}
//
//};
//
//
//int main() {
//
//	RenderWindow window(VideoMode(600, 450), "Platphorm");
//
//	
//
//	Texture t;
//	t.loadFromFile("C:/SFML_App/Teste/image/GG1.png");
//
//	float currentFrame = 0;
//
//	Player p(t);
//
//	Clock clock;
//
//	RectangleShape rectangle;
//
//	while (window.isOpen())
//	{
//		float time = clock.getElapsedTime().asMicroseconds();
//		clock.restart();
//
//		time = time / 800;
//
//		Event event;
//		while (window.pollEvent(event))
//		{
//			if (event.type == Event::Closed)
//				window.close();
//		}
//		if (Keyboard::isKeyPressed(Keyboard::Left))
//		{
//			p.dx = -0.1;
//			
//		}
//		if (Keyboard::isKeyPressed(Keyboard::Right))
//		{
//			p.dx = 0.1;
//		}
//		if (Keyboard::isKeyPressed(Keyboard::Up))
//		{
//			if (p.onGround) { p.dy = -0.4; p.onGround = false; }
//		}
//		
//		p.update(time);
//
//		window.clear(Color::White);
//
//		for (int i = 0; i < H; i++)
//			for (int j = 0; j < W; j++)
//			{
//				if (TileMap[i][j] == 'B') rectangle.setFillColor(Color::Black);
//				if (TileMap[i][j] == '0') rectangle.setFillColor(Color::Green);
//				if (TileMap[i][j] == ' ') continue;
//				rectangle.setPosition(j * 32, i * 32);
//				window.draw(rectangle);
//			}
//
//		window.draw(p.sprite);
//		window.display();
//
//	}
//	return 0;
//
//}
