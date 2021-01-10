#include <iostream>
#include<sfml/Graphics.hpp>
using namespace std;
using namespace sf;

// Main Menu Boolians
bool Menu = true;

void Play_Part_1(RenderWindow& window, bool Circle_Visability[][3]);
void Play_Part_2(RenderWindow& window, bool O_Mark[][3], bool X_Mark[][3], bool& First_Player, bool& Second_Player);
void Check(RenderWindow& window, bool O_Mark[][3], bool X_Mark[][3],bool&Play_Botton,bool&Menu,bool&O_Winner,bool&X_Winner);
void Bottons(RenderWindow& window, bool& Play_Botton, bool& Game_Discription_Botton, bool& Exit_Botton, bool& Menu, bool& O_Winner, bool& X_Winner);
void Discription_Page(RenderWindow& window, bool& Menu, bool& Game_Discription_Botton);
void Display_Winner(RenderWindow& window, bool& O_Winner, bool& X_Winner);

int main()
{
	
		RenderWindow window(VideoMode(900, 900), "Tic-Tac-Toe Game", Style::Close | Style::Default);
		
			// THE boolian that tells the user where is the empty places where he can put his mark
			bool Circle_Visability[3][3] = { true,true ,true ,true ,true ,true ,true ,true ,true };

			// THE boolians that is responsible for drawing the O-Mark in the place that the user chooses
			bool O_Mark[3][3] = { false,false ,false ,false ,false ,false ,false ,false ,false };

			// THE boolians that is responsible for drawing the X-Mark in the place that the user chooses
			bool X_Mark[3][3] = { false,false ,false ,false ,false ,false ,false ,false ,false };

			// TWO boolians to check whose turn is to play 
			bool First_Player = true;
			bool Second_Player = false;

			// Two Boolians Two Tell us Who is the Winner
			bool O_Winner = false;
			bool X_Winner = false;

			// Boolians TO SWITCH BETWEEN PAGES (play ,Game Discription , Exit)
			bool Play_Botton = false;
			bool Game_Discription_Botton = false;
			bool Exit_Botton = false;

			while (window.isOpen())
			{
				Event WindowEvent;

				while (window.pollEvent(WindowEvent))
				{
					if (WindowEvent.type == Event::Closed || WindowEvent.key.code == Keyboard::Escape)
					{
						window.close();
					}
				}
				window.clear(Color::Yellow);
				if (Menu == true)
				{
					Bottons(window, Play_Botton, Game_Discription_Botton, Exit_Botton, Menu, O_Winner, X_Winner);
				}
				if (Play_Botton == true && Game_Discription_Botton == false && Exit_Botton == false && Menu == false)
				{
					Play_Part_1(window, Circle_Visability);
					Play_Part_2(window, O_Mark, X_Mark, First_Player, Second_Player);
					Check(window, O_Mark, X_Mark, Play_Botton, Menu, O_Winner, X_Winner);
					Display_Winner(window, O_Winner, X_Winner);

				}
				else if (Play_Botton == false && Game_Discription_Botton == true && Exit_Botton == false && Menu == false)
				{
					Discription_Page(window, Menu, Game_Discription_Botton);
				}
				else if (Play_Botton == false && Game_Discription_Botton == false && Exit_Botton == true)
				{
					window.close();
				}
				if (O_Winner == true || X_Winner == true)
				{
					if (Mouse::isButtonPressed(Mouse::Right))break;
				}
				window.display();
			}
		return 0;
}


//////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////


void Check(RenderWindow&window, bool O_Mark[][3],bool X_Mark[][3],bool&Play_Botton,bool&Menu,bool&O_Winner,bool&X_Winner)
{
	if ((O_Mark[0][0] == true && O_Mark[0][1] == true && O_Mark[0][2] == true) ||
		(O_Mark[1][0] == true && O_Mark[1][1] == true && O_Mark[1][2] == true) ||
		(O_Mark[2][0] == true && O_Mark[2][1] == true && O_Mark[2][2] == true) ||
		(O_Mark[0][0] == true && O_Mark[1][0] == true && O_Mark[2][0] == true) ||
		(O_Mark[0][1] == true && O_Mark[1][1] == true && O_Mark[2][1] == true) ||
		(O_Mark[0][2] == true && O_Mark[1][2] == true && O_Mark[2][2] == true) ||
		(O_Mark[0][0] == true && O_Mark[1][1] == true && O_Mark[2][2] == true) ||
		(O_Mark[0][2] == true && O_Mark[1][1] == true && O_Mark[2][0] == true))
	{
		O_Winner = true;
	}
	else if ((X_Mark[0][0] == true && X_Mark[0][1] == true && X_Mark[0][2] == true) ||
		(X_Mark[1][0] == true && X_Mark[1][1] == true && X_Mark[1][2] == true) ||
		(X_Mark[2][0] == true && X_Mark[2][1] == true && X_Mark[2][2] == true) ||
		(X_Mark[0][0] == true && X_Mark[1][0] == true && X_Mark[2][0] == true) ||
		(X_Mark[0][1] == true && X_Mark[1][1] == true && X_Mark[2][1] == true) ||
		(X_Mark[0][2] == true && X_Mark[1][2] == true && X_Mark[2][2] == true) ||
		(X_Mark[0][0] == true && X_Mark[1][1] == true && X_Mark[2][2] == true) ||
		(X_Mark[0][2] == true && X_Mark[1][1] == true && X_Mark[2][0] == true))
	{
		X_Winner = true;
	}
	
}

void Bottons(RenderWindow& window, bool& Play_Botton, bool& Game_Discription_Botton, bool& Exit_Botton, bool& Menu,bool&O_Winner,bool&X_Winner)
{
	// Play Botton
	Texture Play_Botton_Texture;
	Play_Botton_Texture.loadFromFile("Play Botton.png");
	Sprite Play_Botton_Sprite;
	Play_Botton_Sprite.setTexture(Play_Botton_Texture);
	Play_Botton_Sprite.setOrigin(Vector2f(50, 25));
	Play_Botton_Sprite.setPosition(450, 150);
	Play_Botton_Sprite.setScale(Vector2f(2.5, 2.5));


	// Game Discription Botton
	Texture Game_Discription_Botton_Texture;
	Game_Discription_Botton_Texture.loadFromFile("Game Discription Botton.png");
	Sprite Game_Discription_Botton_Sprite;
	Game_Discription_Botton_Sprite.setTexture(Game_Discription_Botton_Texture);
	Game_Discription_Botton_Sprite.setOrigin(Vector2f(100, 50));
	Game_Discription_Botton_Sprite.setPosition(450, 400);
	Game_Discription_Botton_Sprite.setScale(Vector2f(2.5, 2.5));


	// Exit Botton
	Texture Exit_Botton_Texture;
	Exit_Botton_Texture.loadFromFile("Exit Botton.png");
	Sprite Exit_Botton_Sprite;
	Exit_Botton_Sprite.setTexture(Exit_Botton_Texture);
	Exit_Botton_Sprite.setPosition(Vector2f(300, 650));
	Exit_Botton_Sprite.setScale(Vector2f(2.5, 2.5));
	if (Mouse::getPosition(window).x > 400 && Mouse::getPosition(window).x < 500 &&
		Mouse::getPosition(window).y>100 && Mouse::getPosition(window).y < 150)
	{
		Play_Botton_Sprite.setColor(Color::Blue);
		Play_Botton_Sprite.setScale(Vector2f(3.5, 3.5));
		if (Mouse::isButtonPressed(Mouse::Right))
		{
			Play_Botton = true;
			Game_Discription_Botton = false;
			Exit_Botton = false;
			Menu = false;
		}
	}
	else if (Mouse::getPosition(window).x > 350 && Mouse::getPosition(window).x < 500 &&
		Mouse::getPosition(window).y>350 && Mouse::getPosition(window).y < 500)
	{
		Game_Discription_Botton_Sprite.setColor(Color::Blue);
		Game_Discription_Botton_Sprite.setScale(Vector2f(3.5, 3.5));
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			Play_Botton = false;
			Game_Discription_Botton = true;
			Exit_Botton = false;
			Menu = false;
		}
	}
	else if (Mouse::getPosition(window).x > 400 && Mouse::getPosition(window).x < 500 &&
		Mouse::getPosition(window).y>650 && Mouse::getPosition(window).y < 750)
	{
		Exit_Botton_Sprite.setColor(Color::Red);
		Exit_Botton_Sprite.setScale(Vector2f(3.5, 3.5));
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			Play_Botton = false;
			Game_Discription_Botton = false;
			Exit_Botton = true;
			Menu = false;
		}
	}
	
	window.draw(Play_Botton_Sprite);
	window.draw(Game_Discription_Botton_Sprite);
	window.draw(Exit_Botton_Sprite);

}
void Display_Winner(RenderWindow&window,bool&O_Winner,bool&X_Winner)
{
	if (O_Winner == true && X_Winner == false)
	{
		Texture Winner_O_Texture;
		Winner_O_Texture.loadFromFile("Winner O.png");
		Sprite Winner_O_Sprite;
		Winner_O_Sprite.setTexture(Winner_O_Texture);
		Winner_O_Sprite.setPosition(Vector2f(450, 0));
		window.draw(Winner_O_Sprite);
	
	}
	else if (O_Winner == false && X_Winner == true)
	{
		Texture Winner_X_Texture;
		Winner_X_Texture.loadFromFile("Winner X.png");
		Sprite Winner_X_Sprite;
		Winner_X_Sprite.setTexture(Winner_X_Texture);
		Winner_X_Sprite.setPosition(Vector2f(450, 0));
		window.draw(Winner_X_Sprite);
	}
}
void Discription_Page(RenderWindow& window, bool& Menu, bool& Game_Discription_Botton)
{
	Texture Game_Discription_Texture;
	Game_Discription_Texture.loadFromFile("Game Discription.png");
	Sprite Game_Discription_Sprite;
	Game_Discription_Sprite.setTexture(Game_Discription_Texture);

	Texture Back_Botton_Texture;
	Back_Botton_Texture.loadFromFile("Back Botton.png");
	Sprite Back_Botton_Sprite;
	Back_Botton_Sprite.setTexture(Back_Botton_Texture);
	Back_Botton_Sprite.setPosition(5, 770);
	Back_Botton_Sprite.setScale(Vector2f(2, 2));
	Back_Botton_Sprite.setColor(Color::Black);

	if (Mouse::getPosition(window).x > 0 && Mouse::getPosition(window).x < 200 &&
		Mouse::getPosition(window).y>700 && Mouse::getPosition(window).y < 900)
	{
		Back_Botton_Sprite.setColor(Color::Blue);
		Back_Botton_Sprite.setScale(Vector2f(3.5, 3.5));
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			Menu = true;
			Game_Discription_Botton = false;
		}
	}
	window.draw(Back_Botton_Sprite);
	window.draw(Game_Discription_Sprite);
	
}

void Play_Part_1(RenderWindow& window, bool Circle_Visability[][3])
{
	//Lines Part
	RectangleShape Lines[4];
	Lines[0].setSize(Vector2f(5, 900));
	Lines[0].setFillColor(Color::Black);
	Lines[0].setPosition(Vector2f(300, 0));
	Lines[1].setSize(Vector2f(5, 900));
	Lines[1].setFillColor(Color::Black);
	Lines[1].setPosition(Vector2f(600, 0));
	Lines[2].setSize(Vector2f(900, 5));
	Lines[2].setFillColor(Color::Black);
	Lines[2].setPosition(Vector2f(0, 300));
	Lines[3].setSize(Vector2f(900, 5));
	Lines[3].setFillColor(Color::Black);
	Lines[3].setPosition(Vector2f(0, 600));
	window.draw(Lines[0]);
	window.draw(Lines[1]);
	window.draw(Lines[2]);
	window.draw(Lines[3]);
	//Circles Visability  (avalible places for choose from)
	CircleShape Circle[3][3];
	for (int i = 0;i < 3;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			Circle[i][j].setRadius(60.f);
			Circle[i][j].setOrigin(Vector2f(60, 60));
			Circle[i][j].setFillColor(Color::Green);
			Circle[i][j].setPosition(Vector2f(150 + j * 300, 150 + i * 300));
			if (Circle_Visability[i][j] == true)
				window.draw(Circle[i][j]);
		}
	}
	// First Row ,First Column
	if (Mouse::isButtonPressed(Mouse::Left) &&
		Mouse::getPosition(window).x > 0 && Mouse::getPosition(window).x < 300 &&
		Mouse::getPosition(window).y > 0 && Mouse::getPosition(window).y < 300)
	{
		Circle_Visability[0][0] = false;
	}
	// First Row , SECOND Column
	if (Mouse::isButtonPressed(Mouse::Left) &&
		Mouse::getPosition(window).x > 300 && Mouse::getPosition(window).x < 600 &&
		Mouse::getPosition(window).y > 0 && Mouse::getPosition(window).y < 300)
	{
		Circle_Visability[0][1] = false;
	}
	//First Row , THIRD Column
	if (Mouse::isButtonPressed(Mouse::Left) &&
		Mouse::getPosition(window).x > 600 && Mouse::getPosition(window).x < 900 &&
		Mouse::getPosition(window).y > 0 && Mouse::getPosition(window).y < 300)
	{
		Circle_Visability[0][2] = false;
	}
	//Second Row , First Column
	if (Mouse::isButtonPressed(Mouse::Left) &&
		Mouse::getPosition(window).x > 0 && Mouse::getPosition(window).x < 300 &&
		Mouse::getPosition(window).y > 300 && Mouse::getPosition(window).y < 600)
	{
		Circle_Visability[1][0] = false;
	}
	//Second Row , second Column
	if (Mouse::isButtonPressed(Mouse::Left) &&
		Mouse::getPosition(window).x > 300 && Mouse::getPosition(window).x < 600 &&
		Mouse::getPosition(window).y > 300 && Mouse::getPosition(window).y < 600)
	{
		Circle_Visability[1][1] = false;
	}
	//Second Row ,  THIRD Column
	if (Mouse::isButtonPressed(Mouse::Left) &&
		Mouse::getPosition(window).x > 600 && Mouse::getPosition(window).x < 900 &&
		Mouse::getPosition(window).y > 300 && Mouse::getPosition(window).y < 600)
	{
		Circle_Visability[1][2] = false;
	}
	//third Row , First Column
	if (Mouse::isButtonPressed(Mouse::Left) &&
		Mouse::getPosition(window).x > 0 && Mouse::getPosition(window).x < 300 &&
		Mouse::getPosition(window).y > 600 && Mouse::getPosition(window).y < 900)
	{
		Circle_Visability[2][0] = false;
	}
	//third Row , second Column
	if (Mouse::isButtonPressed(Mouse::Left) &&
		Mouse::getPosition(window).x > 300 && Mouse::getPosition(window).x < 600 &&
		Mouse::getPosition(window).y > 600 && Mouse::getPosition(window).y < 900)
	{
		Circle_Visability[2][1] = false;
	}
	//third Row , THIRD Column
	if (Mouse::isButtonPressed(Mouse::Left) &&
		Mouse::getPosition(window).x > 600 && Mouse::getPosition(window).x < 900 &&
		Mouse::getPosition(window).y > 600 && Mouse::getPosition(window).y < 900)
	{
		Circle_Visability[2][2] = false;
	}

}

void Play_Part_2(RenderWindow& window, bool O_Mark[][3], bool X_Mark[][3], bool& First_Player, bool& Second_Player)
{
	// O-Player (First Player)
	Texture O_Texture;
	O_Texture.loadFromFile("O-Letter.png");
	Sprite O_Sprite[3][3];
	for (int i = 0;i < 3;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			O_Sprite[i][j].setTexture(O_Texture);
			O_Sprite[i][j].setPosition(Vector2f(j * 300, i * 300));
		}
	}
	// X-Player (Second Player )
	Texture X_Texture;
	X_Texture.loadFromFile("X-Letter.png");
	Sprite X_Sprite[3][3];
	for (int i = 0;i < 3;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			X_Sprite[i][j].setTexture(X_Texture);
			X_Sprite[i][j].setPosition(Vector2f(j * 300, i * 300));
		}
	}
	///////////////////////////////////////////////////////////
	// Places of Both X & O 
	/////////////////////////////////////////////////////////
	// First Row ,First Column

	if (Mouse::isButtonPressed(Mouse::Left) && First_Player == true && Second_Player == false &&
		Mouse::getPosition(window).x > 0 && Mouse::getPosition(window).x < 300 && X_Mark[0][0] == false &&
		Mouse::getPosition(window).y > 0 && Mouse::getPosition(window).y < 300)
	{
		O_Mark[0][0] = true;
		First_Player = false;
		Second_Player = true;
	}
	else if (Mouse::isButtonPressed(Mouse::Left) && First_Player == false && Second_Player == true &&
		Mouse::getPosition(window).x > 0 && Mouse::getPosition(window).x < 300 && O_Mark[0][0] == false &&
		Mouse::getPosition(window).y > 0 && Mouse::getPosition(window).y < 300)
	{
		X_Mark[0][0] = true;
		First_Player = true;
		Second_Player = false;
	}
	// First Row , SECOND Column
	if (Mouse::isButtonPressed(Mouse::Left) && First_Player == true && Second_Player == false && Menu == false &&
		Mouse::getPosition(window).x > 300 && Mouse::getPosition(window).x < 600 && X_Mark[0][1] == false &&
		Mouse::getPosition(window).y > 0 && Mouse::getPosition(window).y < 300)
	{
		O_Mark[0][1] = true;
		First_Player = false;
		Second_Player = true;
	}
	else if (Mouse::isButtonPressed(Mouse::Left) && First_Player == false && Second_Player == true &&
		Mouse::getPosition(window).x > 300 && Mouse::getPosition(window).x < 600 && O_Mark[0][1] == false &&
		Mouse::getPosition(window).y > 0 && Mouse::getPosition(window).y < 300)
	{
		X_Mark[0][1] = true;
		First_Player = true;
		Second_Player = false;
	}
	//First Row , THIRD Column
	if (Mouse::isButtonPressed(Mouse::Left) && First_Player == true && Second_Player == false &&
		Mouse::getPosition(window).x > 600 && Mouse::getPosition(window).x < 900 && X_Mark[0][2] == false &&
		Mouse::getPosition(window).y > 0 && Mouse::getPosition(window).y < 300)
	{
		O_Mark[0][2] = true;
		First_Player = false;
		Second_Player = true;
	}
	else if (Mouse::isButtonPressed(Mouse::Left) && First_Player == false && Second_Player == true &&
		Mouse::getPosition(window).x > 600 && Mouse::getPosition(window).x < 900 && O_Mark[0][2] == false &&
		Mouse::getPosition(window).y > 0 && Mouse::getPosition(window).y < 300)
	{
		X_Mark[0][2] = true;
		First_Player = true;
		Second_Player = false;
	}
	//Second Row , First Column
	if (Mouse::isButtonPressed(Mouse::Left) && First_Player == true && Second_Player == false &&
		Mouse::getPosition(window).x > 0 && Mouse::getPosition(window).x < 300 && X_Mark[1][0] == false &&
		Mouse::getPosition(window).y > 300 && Mouse::getPosition(window).y < 600)
	{
		O_Mark[1][0] = true;
		First_Player = false;
		Second_Player = true;
	}
	else if (Mouse::isButtonPressed(Mouse::Left) && First_Player == false && Second_Player == true &&
		Mouse::getPosition(window).x > 0 && Mouse::getPosition(window).x < 300 && O_Mark[1][0] == false &&
		Mouse::getPosition(window).y > 300 && Mouse::getPosition(window).y < 600)
	{
		X_Mark[1][0] = true;
		First_Player = true;
		Second_Player = false;
	}
	//Second Row , second Column
	if (Mouse::isButtonPressed(Mouse::Left) && First_Player == true && Second_Player == false &&
		Mouse::getPosition(window).x > 300 && Mouse::getPosition(window).x < 600 && X_Mark[1][1] == false &&
		Mouse::getPosition(window).y > 300 && Mouse::getPosition(window).y < 600)
	{
		O_Mark[1][1] = true;
		First_Player = false;
		Second_Player = true;
	}
	else if (Mouse::isButtonPressed(Mouse::Left) && First_Player == false && Second_Player == true &&
		Mouse::getPosition(window).x > 300 && Mouse::getPosition(window).x < 600 && O_Mark[1][1] == false &&
		Mouse::getPosition(window).y > 300 && Mouse::getPosition(window).y < 600)
	{
		X_Mark[1][1] = true;
		First_Player = true;
		Second_Player = false;
	}
	//Second Row ,  THIRD Column
	if (Mouse::isButtonPressed(Mouse::Left) && First_Player == true && Second_Player == false &&
		Mouse::getPosition(window).x > 600 && Mouse::getPosition(window).x < 900 && X_Mark[1][2] == false &&
		Mouse::getPosition(window).y > 300 && Mouse::getPosition(window).y < 600)
	{
		O_Mark[1][2] = true;
		First_Player = false;
		Second_Player = true;
	}
	else if (Mouse::isButtonPressed(Mouse::Left) && First_Player == false && Second_Player == true &&
		Mouse::getPosition(window).x > 600 && Mouse::getPosition(window).x < 900 && O_Mark[1][2] == false &&
		Mouse::getPosition(window).y > 300 && Mouse::getPosition(window).y < 600)
	{
		X_Mark[1][2] = true;
		First_Player = true;
		Second_Player = false;
	}
	//third Row , First Column
	if (Mouse::isButtonPressed(Mouse::Left) && First_Player == true && Second_Player == false &&
		Mouse::getPosition(window).x > 0 && Mouse::getPosition(window).x < 300 && X_Mark[2][0] == false &&
		Mouse::getPosition(window).y > 600 && Mouse::getPosition(window).y < 900)
	{
		O_Mark[2][0] = true;
		First_Player = false;
		Second_Player = true;
	}
	else if (Mouse::isButtonPressed(Mouse::Left) && First_Player == false && Second_Player == true &&
		Mouse::getPosition(window).x > 0 && Mouse::getPosition(window).x < 300 && O_Mark[2][0] == false &&
		Mouse::getPosition(window).y > 600 && Mouse::getPosition(window).y < 900)
	{
		X_Mark[2][0] = true;
		First_Player = true;
		Second_Player = false;
	}
	//third Row , second Column
	if (Mouse::isButtonPressed(Mouse::Left) && First_Player == true && Second_Player == false &&
		Mouse::getPosition(window).x > 300 && Mouse::getPosition(window).x < 600 && X_Mark[2][1] == false &&
		Mouse::getPosition(window).y > 600 && Mouse::getPosition(window).y < 900)
	{
		O_Mark[2][1] = true;
		First_Player = false;
		Second_Player = true;
	}
	else if (Mouse::isButtonPressed(Mouse::Left) && First_Player == false && Second_Player == true &&
		Mouse::getPosition(window).x > 300 && Mouse::getPosition(window).x < 600 && O_Mark[2][1] == false &&
		Mouse::getPosition(window).y > 600 && Mouse::getPosition(window).y < 900)
	{
		X_Mark[2][1] = true;
		First_Player = true;
		Second_Player = false;
	}
	//third Row , THIRD Column
	if (Mouse::isButtonPressed(Mouse::Left) && First_Player == true && Second_Player == false &&
		Mouse::getPosition(window).x > 600 && Mouse::getPosition(window).x < 900 && X_Mark[2][2] == false &&
		Mouse::getPosition(window).y > 600 && Mouse::getPosition(window).y < 900)
	{
		O_Mark[2][2] = true;
		First_Player = false;
		Second_Player = true;
	}
	else if (Mouse::isButtonPressed(Mouse::Left) && First_Player == false && Second_Player == true &&
		Mouse::getPosition(window).x > 600 && Mouse::getPosition(window).x < 900 && O_Mark[2][2] == false &&
		Mouse::getPosition(window).y > 600 && Mouse::getPosition(window).y < 900)
	{
		X_Mark[2][2] = true;
		First_Player = true;
		Second_Player = false;
	}
	for (int i = 0;i < 3;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			if (X_Mark[i][j] == true)
				window.draw(X_Sprite[i][j]);
			if (O_Mark[i][j] == true)
				window.draw(O_Sprite[i][j]);
		}
	}
}