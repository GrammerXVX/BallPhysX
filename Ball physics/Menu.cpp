#include "Menu.h"
#include <iostream>
Menu::Menu()
{
	
}
Menu::~Menu()
{

}

void Menu::callMenu(sf::RenderWindow &window)//вызов метода меню
{
	bool isMenu = 1;

	menuTexture1.loadFromFile("images/1.png");
	menuTexture2.loadFromFile("images/2.png");
	menuTexture3.loadFromFile("images/3.png");
	menuTexture4.loadFromFile("images/4.png"); 
	menuBackground.loadFromFile("images/background.jpg");
	sf::Sprite menu1(menuTexture1),menu2(menuTexture2),menu3(menuTexture3),menu4(menuTexture4), menuBG(menuBackground);
	menu1.setPosition(100, 200);
	menu2.setPosition(100, 300);
	menu3.setPosition(100, 400);
	menu4.setPosition(100, 500);
	menuBG.setPosition(0, 0);


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		menu1.setColor(sf::Color::White);
		menu2.setColor(sf::Color::White);
		menu3.setColor(sf::Color::White);
		menu4.setColor(sf::Color::White);
		menuNum = 0;
		window.clear(sf::Color(129, 181, 221));//ставим синий цвет на задний фон

		if (sf::IntRect(105, 207, 90, 30).contains(sf::Mouse::getPosition(window))) { menu1.setColor(sf::Color::Blue); menuNum = 1; }//если наводимся на текстуру , то она меняет цвет на синий
		if (sf::IntRect(108, 309, 80, 27).contains(sf::Mouse::getPosition(window)))  { menu2.setColor(sf::Color::Blue); menuNum = 2; }
		if (sf::IntRect(108, 410, 80, 23).contains(sf::Mouse::getPosition(window))) { menu3.setColor(sf::Color::Blue); menuNum = 3; }
		if (sf::IntRect(108, 500, 91, 47).contains(sf::Mouse::getPosition(window))) { menu4.setColor(sf::Color::Blue); menuNum = 4; }
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (menuNum == 1)//1 уровень
			{
				MenuInProgress(window, menuNum);
			}
			if (menuNum == 2)//2 уровень
			{
				MenuInProgress(window, menuNum);
			}
			if (menuNum == 3)//3 уровень
			{
				MenuInProgress(window, menuNum);
			}
			if (menuNum == 4) 
			{ 
				window.close(); isMenu = false;
			}//4 выход 
		}
		window.draw(menuBG);//отрисовка
		window.draw(menu1);
		window.draw(menu2);
		window.draw(menu3);
		window.draw(menu4);
		window.display();
	}
}




void Menu::MenuInProgress(sf::RenderWindow& window, int menuNum)
{
	int counter = 0;
	if (menuNum == 1)//если земля
	{
		background.loadFromFile("images/bg1.jpg");
	}
	else if (menuNum == 2)//марс
	{
		background.loadFromFile("images/bg2.jpg");
	}
	else//луна
	{
		background.loadFromFile("images/bg3.jpg");
	}
	menuChoose1.loadFromFile("images/1.png");
	menuChoose2.loadFromFile("images/2.png");
	sf::Sprite background(background), Choose1(menuChoose1),Choose2(menuChoose2);
	sf::Color col1 = sf::Color(255, 0, 255);
	sf::Color col2 = sf::Color(255, 255, 0);
	int i = 0;
	std::vector<Ball> Objects = { Ball(window.getSize().x / 4.f, window.getSize().y / 2.f, 50.f, col1),
								  Ball(window.getSize().x / 4.f, window.getSize().y / 2.f, 50.f, col1),
								  Ball(window.getSize().x / 4.f, window.getSize().y / 2.f, 50.f, col1),
								};
	Physics a = Physics(Objects);
	Choose1.setPosition(100, 200);
	Choose2.setPosition(100, 300);
	background.setPosition(0,0);//установка бекграунда
	while (window.isOpen())
	{
		if (counter > 0 )
		{
			counter--;
		}
		int choose = 0;
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))//если нажать esc выйдет в меню
		{
			return;
		}
		Choose1.setColor(sf::Color::White);
		Choose2.setColor(sf::Color::White);
		if (sf::IntRect(105, 207, 90, 30).contains(sf::Mouse::getPosition(window))) { Choose1.setColor(sf::Color::Blue); choose = 1; }
		if (sf::IntRect(108, 309, 80, 27).contains(sf::Mouse::getPosition(window))) { Choose2.setColor(sf::Color::Blue); choose = 2; }
		if (counter == 0 )
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (choose == 1)
				{
					push(a, window, col2);
					counter = 20;
				}
				if (choose == 2)
				{
					pop(a);
					counter = 20;
				}
			}
		}
		
		window.clear(sf::Color(129, 181, 221));//очистка экрана
		window.draw(background);//отрисовка
		a.PreProcessing(window);
		window.draw(Choose1);
		window.draw(Choose2);
		window.display();//
		std::cout << counter<<std::endl;
	}

}



void Menu::push(Physics &a,sf::RenderWindow &window, sf::Color col2)
{
	
	a.AddObject(Ball(window.getSize().x / 4.f, window.getSize().y / 2.f, 50.f, col2));

	return;
}
void Menu::pop(Physics& a)
{
	a.PopObject();
}

