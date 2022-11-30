#include "Menu.h"

Menu::Menu()
{

}
Menu::~Menu()
{

}

void Menu::callMenu(sf::RenderWindow &window)//����� ������ ����
{
	
	menuTexture1.loadFromFile("F:/������/BallPhysX/images/1.png"); //�������� �������
	menuTexture2.loadFromFile("F:/������/BallPhysX/images/2.png");
	menuTexture3.loadFromFile("F:/������/BallPhysX/images/3.png");
	menuTexture4.loadFromFile("F:/������/BallPhysX/images/4.png");
	menuBackground.loadFromFile("F:/������/BallPhysX/images/background.jpg");
	
	sf::Sprite menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3), menu4(menuTexture4), menuBG(menuBackground);
	bool isMenu = 1;
	menu1.setPosition(100, 200); //��������� �������
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
		menu1.setColor(sf::Color::White);//���������� ������������� ����� ��������
		menu2.setColor(sf::Color::White);
		menu3.setColor(sf::Color::White);
		menu4.setColor(sf::Color::White);
		menuNum = 0;
		window.clear(sf::Color(129, 181, 221));//������ ����� ���� �� ������ ���

		if (sf::IntRect(105, 207, 90, 30).contains(sf::Mouse::getPosition(window))) { menu1.setColor(sf::Color::Blue); menuNum = 1; }//���� ��������� �� �������� , �� ��� ������ ���� �� �����
		if (sf::IntRect(108, 309, 80, 27).contains(sf::Mouse::getPosition(window)))  { menu2.setColor(sf::Color::Blue); menuNum = 2; }
		if (sf::IntRect(108, 410, 80, 23).contains(sf::Mouse::getPosition(window))) { menu3.setColor(sf::Color::Blue); menuNum = 3; }
		if (sf::IntRect(108, 500, 91, 47).contains(sf::Mouse::getPosition(window))) { menu4.setColor(sf::Color::Blue); menuNum = 4; }
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (menuNum == 1)//1 �������
			{
				MenuInProgress(window, menuNum);
			}
			if (menuNum == 2)//2 �������
			{
				MenuInProgress(window, menuNum);
			}
			if (menuNum == 3)//3 �������
			{
				MenuInProgress(window, menuNum);
			}
			if (menuNum == 4) 
			{ 
				window.close(); isMenu = false;
			}//4 ����� 
		}

		window.draw(menuBG);//���������
		window.draw(menu1);
		window.draw(menu2);
		window.draw(menu3);
		window.draw(menu4);
		window.display();
	}
}




void Menu::MenuInProgress(sf::RenderWindow& window,int menuNum)
{
	
	if (menuNum == 1)//���� �����
	{
		background.loadFromFile("F:/������/BallPhysX/images/bg1.jpg");
	}
	else if (menuNum == 2)//����
	{
		background.loadFromFile("F:/������/BallPhysX/images/bg2.jpg");
	}
	else//����
	{
		background.loadFromFile("F:/������/BallPhysX/images/bg3.jpg");
	}
	sf::Sprite background(background);
	background.setPosition(0,0);//��������� ����������
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))//���� ������ esc ������ � ����
		{
			return;
		}
		
		window.clear(sf::Color(129, 181, 221));//������� ������
		window.draw(background);//���������
		window.display();//
	}

}


