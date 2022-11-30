#include "Menu.h"

Menu::Menu()
{

}
Menu::~Menu()
{

}

void Menu::callMenu(sf::RenderWindow &window)
{
	
	menuTexture1.loadFromFile("C:/Users/olegs/OneDrive/Документы/GitHub/BallPhysX/images/1.png"); //указать полный путь тк чисто папку не видит
	menuTexture2.loadFromFile("C:/Users/olegs/OneDrive/Документы/GitHub/BallPhysX/images/2.png");//и меню уебанское у меня почему кружок постоянно крутится и я не ебу почему завтра буду фиксит
	menuTexture3.loadFromFile("C:/Users/olegs/OneDrive/Документы/GitHub/BallPhysX/images/3.png");//и подгонять размеры ,но хоть чето сделал
	menuTexture4.loadFromFile("C:/Users/olegs/OneDrive/Документы/GitHub/BallPhysX/images/4.png");
	menuBackground.loadFromFile("C:/Users/olegs/OneDrive/Документы/GitHub/BallPhysX/images/5.png");
	sf::Sprite menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3), menu4(menuTexture4), menuBG(menuBackground);
	bool isMenu = 1;
	int menuNum = 0;
	menu1.setPosition(100, 30);
	menu2.setPosition(100, 90);
	menu3.setPosition(100, 150);
	menu4.setPosition(100, 200);
	menuBG.setPosition(0, 0);


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}
		menu1.setColor(sf::Color::White);
		menu2.setColor(sf::Color::White);
		menu3.setColor(sf::Color::White);
		menu4.setColor(sf::Color::White);
		menuNum = 0;
		window.clear(sf::Color(129, 181, 221));

		if (sf::IntRect(100, 30, 50, 17).contains(sf::Mouse::getPosition(window))) { menu1.setColor(sf::Color::Blue); menuNum = 1; }
		/*if (sf::IntRect(100, 90, 300, 50).contains(sf::Mouse::getPosition(window))) { menu2.setColor(sf::Color::Blue); menuNum = 2; }
		if (sf::IntRect(100, 150, 300, 50).contains(sf::Mouse::getPosition(window))) { menu3.setColor(sf::Color::Blue); menuNum = 3; }
		if (sf::IntRect(100, 200, 300, 50).contains(sf::Mouse::getPosition(window))) { menu4.setColor(sf::Color::Blue); menuNum = 4; }*/
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (menuNum == 1) isMenu = false;//если нажали первую кнопку, то выходим из меню 
			if (menuNum == 2) isMenu = false; 
			if (menuNum == 3) isMenu = false;
			if (menuNum == 4) { window.close(); isMenu = false; }
		}

		window.draw(menuBG);
		window.draw(menu1);
		window.draw(menu2);
		window.draw(menu3);
		window.draw(menu4);
		window.display();
	}
}
