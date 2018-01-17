//#include <SFML\Graphics.hpp>
//#include <time.h>
//
////void SFMLTest() {
////	using namespace sf;
////	RenderWindow window(VideoMode(200, 200), "SFML test", Style::Close);
////	CircleShape shape(100.f);
////	shape.setFillColor(Color::Green);
////
////	while (window.isOpen())
////	{
////		Event event;
////		while (window.pollEvent(event))
////		{
////			if (event.type == Event::Closed)
////				window.close();
////		}
////		window.clear();
////		window.draw(shape);
////		window.display();
////	}
////
////}
//using namespace sf;
//const int M = 20;
//const int N = 10;
//int field[M][N] = { 0 };
//
//struct Point
//{int x, y;} a[4], b[4];
//
//int figures[7][4] =
//{
//
//	1,3,5,7, // I
//	2,4,5,7, // Z
//	3,5,4,6, // S
//	3,5,4,7, // T
//	2,3,5,7, // L
//	3,5,7,6, // J
//	2,3,4,5, // O
//
//};
//bool check()
//{
//	for (int i = 0; i < 4; i++)
//	
//		if (a[i].x<0 || a[i].x>N || a[i].y >= M) return 0;
//		else if (field[a[i].y][a[i].x]) return 0;
//	
//		return 1;
//}
//
//int main() {
//
//	srand(time(0));
//
//	RenderWindow window(VideoMode(320, 480), "The Game!");
//
//	Texture t;
//	t.loadFromFile("C:/SFML_App/Teste/image/wall.png");
//	
//	Sprite s(t);
//	s.setTextureRect(IntRect(0, 0, 18, 18));
//
//	int dx = 0; bool rotate = 0; int colorNum = 1;
//	float timer = 0, delay = 0.3;
//
//
//	Clock clock;
//
//	while (window.isOpen()) {
//
//		float time = clock.getElapsedTime().asSeconds();
//		clock.restart();
//		timer += time;
//
//		Event e;
//		while (window.pollEvent(e)) {
//			if (e.type == Event::Closed)
//				window.close();
//			if (e.type == Event::KeyPressed)
//				if (e.key.code == Keyboard::Up) rotate = true;
//				else if (e.key.code == Keyboard::Left) dx = -1;
//				else if (e.key.code == Keyboard::Right) dx = 1;
//			
//		}
//
//		/////////<- Move ->//////////
//
//		for (int i = 0; i < 4; i++)
//		{
//			b[i] = a[i];
//			a[i].x += dx;
//		}
//			if (!check()) for (int  i = 0; i < 4; i++)
//			{
//				b[i] = a[i];
//			}
//		
//
//
//		////////////////Rotate///////////////////////
//		if (rotate) {
//			Point p = a[1];
//			for (int i = 0; i < 4; i++)
//			{
//				int x = a[i].y - p.y;
//				int y = a[i].x - p.x;
//				a[i].x = p.x - x;
//				a[i].y = p.y + y;
//			}
//			if (!check()) for (int i = 0; i < 4; i++)
//			{
//				a[i] = b[i];
//			}
//		}
//
//
//		///////////Tick//////////
//		if (time > delay)
//		{
//			for (int i = 0; i < 4; i++) { b[i] = a[i]; a[i].y += 1; }
//
//			if (!check()) {
//				for (int i = 0; i < 4; i++)field[b[i].y][b[i].x] = colorNum;
//				colorNum = 1 + rand() % 7;
//				int n = rand() % 7;
//				for (int i = 0; i < 4; i++)
//				{
//					a[i].x = figures[n][i] % 2;
//					a[i].y = figures[n][i] / 2;
//				}
//			}
//
//			timer = 0;
//		}
//
//		////////////draw///////////
//		
//		window.clear(Color::White);
//
//		for(int i=0; i<M;i++)
//			for (int j = 0; j < 4; j++)
//			{
//				if (field[i][j] = 0) continue;
//				s.setPosition(j * 18, i * 18);
//				window.draw(s);
//			}
//
//
//		dx = 0; rotate = 0;
//
//
//
//		window.clear(Color::White);
//		for (int i = 0; i < 4; i++)
//		{
//			s.setPosition(a[i].x*18, a[i].y*18);
//			window.draw(s);
//		}
//	
//		window.display();
//	}
//
//	return 0;
//}