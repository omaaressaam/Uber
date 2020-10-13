#include <SFML/Graphics.hpp>

#include "Customer.h"
#include "Driver.h"
#include "Graph.h"
#include "Node.h"

#include <list>
#include <set>
#include <unordered_map>
#include <string>

#include <vector>
#include <algorithm>

#include <iostream>
#include <fstream>
#include <sstream>

#define PI 3.14159265

Graph g;



int position = 0;
char type;
int active = 0;
int who_open;
string admin_pass = "121212";
int admin_id = 100;
int ay = 0;
bool have_r = false;

vector< pair<int, vector<string> > >assigned_customer;
int estimate;
string tran;
int drive;

sf::Font font;
sf::Text text[100];
sf::RectangleShape choice[100];
sf::RenderWindow window(sf::VideoMode(1200, 800), "U B E R");
sf::RectangleShape phot(sf::Vector2f(1200.0f, 800.0f));
sf::RectangleShape photo(sf::Vector2f(1200.0f, 800.0f));

using namespace std;
using namespace sf;

void wl() {

	sf::Clock clock;
	sf::Time elapsed = clock.getElapsedTime();

	window.draw(phot);
	window.display();
	while (true)
	{

		sf::Time elapsed = clock.getElapsedTime();
		if (elapsed.asSeconds() > 2)
			break;
	}
	position = 1;
}

void wlpage() {


	text[0].setFont(font);
	text[0].setString(" Customer ");
	text[0].setCharacterSize(40);
	text[0].setFillColor(sf::Color::White);
	text[0].setPosition(480, 470);
	text[0].setStyle(sf::Text::Bold);

	text[1].setFont(font);
	text[1].setString(" Driver ");
	text[1].setCharacterSize(40);
	text[1].setFillColor(sf::Color::White);
	text[1].setPosition(840, 470);
	text[1].setStyle(sf::Text::Bold);

	text[2].setFont(font);
	text[2].setString(" Admin ");
	text[2].setCharacterSize(40);
	text[2].setFillColor(sf::Color::White);
	text[2].setPosition(180, 470);
	text[2].setStyle(sf::Text::Bold);

	text[3].setFont(font);
	text[3].setString(" Exit ");
	text[3].setCharacterSize(40);
	text[3].setFillColor(sf::Color::White);
	text[3].setPosition(1050, 50);
	text[3].setStyle(sf::Text::Bold);

	choice[0].setSize(sf::Vector2f(200.0f, 85.0f));
	choice[0].setPosition(sf::Vector2f(150, 450));
	choice[0].setFillColor(sf::Color::Transparent);
	choice[0].setOutlineThickness(3);
	choice[0].setOutlineColor(sf::Color::White);

	choice[1].setSize(sf::Vector2f(200.0f, 85.0f));
	choice[1].setPosition(sf::Vector2f(480, 450));
	choice[1].setFillColor(sf::Color::Transparent);
	choice[1].setOutlineThickness(3);
	choice[1].setOutlineColor(sf::Color::White);

	choice[2].setSize(sf::Vector2f(200.0f, 85.0f));
	choice[2].setPosition(sf::Vector2f(810, 450));
	choice[2].setFillColor(sf::Color::Transparent);
	choice[2].setOutlineThickness(3);
	choice[2].setOutlineColor(sf::Color::White);

	choice[3].setSize(sf::Vector2f(120.0f, 65.0f));
	choice[3].setPosition(sf::Vector2f(1040, 40));
	choice[3].setFillColor(sf::Color::Transparent);
	choice[3].setOutlineThickness(3);
	choice[3].setOutlineColor(sf::Color::White);

	window.clear();
	window.draw(photo);
	for (int i = 0; i < 4; i++) {
		window.draw(choice[i]);
		window.draw(text[i]);
	}
	window.display();

	sf::Event event;
	while (window.waitEvent(event))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

			sf::Vector2i local_position = sf::Mouse::getPosition(window);
			if (local_position.x >= 146 && local_position.x <= 352 && local_position.y >= 445 && local_position.y <= 535) {
				cout << "admin " << endl;
				position = 11;
				type = 'a';
				break;
			}
			else if (local_position.x >= 477 && local_position.x <= 681 && local_position.y >= 445 && local_position.y <= 535)
			{
				cout << "cutomer " << endl;
				position = 12;
				type = 'c';
				break;
			}
			else if (local_position.x >= 808 && local_position.x <= 1012 && local_position.y >= 445 && local_position.y <= 535)
			{
				cout << "driver" << endl;
				position = 13;
				type = 'd';
				break;
			}
			else if (local_position.x >= 1036 && local_position.x <= 1160 && local_position.y >= 37 && local_position.y <= 106)
			{
				g.save();
				window.close();
			}
		}
	}
}

void choicee() {

	text[1].setFont(font);
	text[1].setString("  Login ");
	text[1].setCharacterSize(40);
	text[1].setFillColor(sf::Color::White);
	text[1].setPosition(500, 270);
	text[1].setStyle(sf::Text::Bold);

	text[2].setFont(font);
	text[2].setString(" Register ");
	text[2].setCharacterSize(40);
	text[2].setFillColor(sf::Color::White);
	text[2].setPosition(490, 470);
	text[2].setStyle(sf::Text::Bold);

	text[0].setFont(font);
	text[0].setString(" Back ");
	text[0].setCharacterSize(40);
	text[0].setFillColor(sf::Color::White);
	text[0].setPosition(1050, 50);
	text[0].setStyle(sf::Text::Bold);

	choice[0].setSize(sf::Vector2f(200.0f, 85.0f));
	choice[0].setPosition(sf::Vector2f(480, 250));
	choice[0].setFillColor(sf::Color::Transparent);
	choice[0].setOutlineThickness(3);
	choice[0].setOutlineColor(sf::Color::White);

	choice[2].setSize(sf::Vector2f(200.0f, 85.0f));
	choice[2].setPosition(sf::Vector2f(480, 450));
	choice[2].setFillColor(sf::Color::Transparent);
	choice[2].setOutlineThickness(3);
	choice[2].setOutlineColor(sf::Color::White);

	choice[1].setSize(sf::Vector2f(120.0f, 65.0f));
	choice[1].setPosition(sf::Vector2f(1040, 40));
	choice[1].setFillColor(sf::Color::Transparent);
	choice[1].setOutlineThickness(3);
	choice[1].setOutlineColor(sf::Color::White);

	window.clear();
	window.draw(photo);
	for (int i = 0; i < 2; i++) {
		window.draw(choice[i]);
		window.draw(text[i]);
	}
	if (type != 'a')
	{
		window.draw(choice[2]);
		window.draw(text[2]);
	}
	window.display();

	sf::Event event;
	while (window.waitEvent(event))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			sf::Vector2i local_position = sf::Mouse::getPosition(window);
			if (local_position.x >= 477 && local_position.x <= 682 && local_position.y >= 246 && local_position.y <= 337)
			{
				position = 15;
				break;
			}
			else if (type != 'a' && local_position.x >= 477 && local_position.x <= 682 && local_position.y >= 446 && local_position.y <= 536)
			{
				position = 16;
				break;
			}
			else if (local_position.x >= 1036 && local_position.x <= 1160 && local_position.y >= 37 && local_position.y <= 106)
			{
				position = 1;
				break;
			}
		}
	}
}

void regdriver() {

	text[0].setFont(font);
	text[0].setString(" Back ");
	text[0].setCharacterSize(40);
	text[0].setFillColor(sf::Color::White);
	text[0].setPosition(1050, 50);
	text[0].setStyle(sf::Text::Bold);

	text[1].setFont(font);
	text[1].setString(" NAME                  : ");
	text[1].setCharacterSize(40);
	text[1].setFillColor(sf::Color::White);
	text[1].setPosition(53, 40);
	text[1].setStyle(sf::Text::Bold);

	text[2].setFont(font);
	text[2].setString(" PASSWORD           : ");
	text[2].setCharacterSize(40);
	text[2].setFillColor(sf::Color::White);
	text[2].setPosition(50, 120);
	text[2].setStyle(sf::Text::Bold);

	text[3].setFont(font);
	text[3].setString(" PHONE NUM          :  ");
	text[3].setCharacterSize(40);
	text[3].setFillColor(sf::Color::White);
	text[3].setPosition(50, 200);
	text[3].setStyle(sf::Text::Bold);

	text[4].setFont(font);
	text[4].setString(" CAR NUM             : ");
	text[4].setCharacterSize(40);
	text[4].setFillColor(sf::Color::White);
	text[4].setPosition(52, 280);
	text[4].setStyle(sf::Text::Bold);

	text[5].setFont(font);
	text[5].setString(" LOCATION             :");
	text[5].setCharacterSize(40);
	text[5].setFillColor(sf::Color::White);
	text[5].setPosition(50, 360);
	text[5].setStyle(sf::Text::Bold);

	text[6].setFont(font);
	text[6].setString(" CAR NAME             :");
	text[6].setCharacterSize(40);
	text[6].setFillColor(sf::Color::White);
	text[6].setPosition(50, 440);

	text[7].setFont(font);
	text[7].setString(" CAR COLOR           :");
	text[7].setCharacterSize(40);
	text[7].setFillColor(sf::Color::White);
	text[7].setPosition(50, 520);
	text[7].setStyle(sf::Text::Bold);
	text[7].setStyle(sf::Text::Bold);

	text[8].setFont(font);
	text[8].setString(" CAR MODEL          :");
	text[8].setCharacterSize(40);
	text[8].setFillColor(sf::Color::White);
	text[8].setPosition(50, 600);
	text[8].setStyle(sf::Text::Bold);
	text[8].setStyle(sf::Text::Bold);

	text[9].setFont(font);
	text[9].setString(" PREFERED SCOPE  :");
	text[9].setCharacterSize(40);
	text[9].setFillColor(sf::Color::White);
	text[9].setPosition(50, 680);
	text[9].setStyle(sf::Text::Bold);
	text[9].setStyle(sf::Text::Bold);

	text[10].setFont(font);
	text[10].setString(" ADD ");
	text[10].setCharacterSize(20);
	text[10].setFillColor(sf::Color::White);
	text[10].setPosition(770, 700);
	text[10].setStyle(sf::Text::Bold);

	text[11].setFont(font);
	text[11].setString(" REGISTER ");
	text[11].setCharacterSize(30);
	text[11].setFillColor(sf::Color::White);
	text[11].setPosition(1005, 710);
	text[11].setStyle(sf::Text::Bold);

	text[12].setFont(font);
	text[12].setString("Please, Fill The Spaces. ");
	text[12].setCharacterSize(40);
	text[12].setFillColor(sf::Color::White);
	text[12].setPosition(380, 740);
	text[12].setStyle(sf::Text::Bold);

	choice[0].setSize(sf::Vector2f(120.0f, 65.0f));
	choice[0].setPosition(sf::Vector2f(1040, 40));
	choice[0].setFillColor(sf::Color::Transparent);
	choice[0].setOutlineThickness(3);
	choice[0].setOutlineColor(sf::Color::White);

	choice[5].setSize(sf::Vector2f(150.0f, 60.0f));
	choice[5].setPosition(sf::Vector2f(1000., 700));
	choice[5].setFillColor(sf::Color::Transparent);
	choice[5].setOutlineThickness(3);
	choice[5].setOutlineColor(sf::Color::White);

	choice[11].setSize(sf::Vector2f(100.0f, 40.0f));
	choice[11].setPosition(sf::Vector2f(750., 690));
	choice[11].setFillColor(sf::Color::Transparent);
	choice[11].setOutlineThickness(3);
	choice[11].setOutlineColor(sf::Color::White);

	choice[3].setSize(sf::Vector2f(280.0f, 50.0f));
	choice[3].setPosition(sf::Vector2f(450, 40));
	choice[3].setFillColor(sf::Color::White);
	choice[3].setOutlineColor(sf::Color::Black);
	choice[3].setOutlineThickness(7);

	choice[4].setSize(sf::Vector2f(280.0f, 50.0f));
	choice[4].setPosition(sf::Vector2f(450, 125));
	choice[4].setFillColor(sf::Color::White);
	choice[4].setOutlineColor(sf::Color::Black);
	choice[4].setOutlineThickness(7);

	choice[6].setSize(sf::Vector2f(280.0f, 50.0f));
	choice[6].setPosition(sf::Vector2f(450, 200));
	choice[6].setFillColor(sf::Color::White);
	choice[6].setOutlineColor(sf::Color::Black);
	choice[6].setOutlineThickness(7);

	choice[7].setSize(sf::Vector2f(280.0f, 50.0f));
	choice[7].setPosition(sf::Vector2f(450, 280));
	choice[7].setFillColor(sf::Color::White);
	choice[7].setOutlineColor(sf::Color::Black);
	choice[7].setOutlineThickness(7);

	choice[8].setSize(sf::Vector2f(280.0f, 50.0f));
	choice[8].setPosition(sf::Vector2f(450, 360));
	choice[8].setFillColor(sf::Color::White);
	choice[8].setOutlineColor(sf::Color::Black);
	choice[8].setOutlineThickness(7);

	choice[9].setSize(sf::Vector2f(280.0f, 50.0f));
	choice[9].setPosition(sf::Vector2f(450, 440));
	choice[9].setFillColor(sf::Color::White);
	choice[9].setOutlineColor(sf::Color::Black);
	choice[9].setOutlineThickness(7);

	choice[10].setSize(sf::Vector2f(280.0f, 50.0f));
	choice[10].setPosition(sf::Vector2f(450, 520));
	choice[10].setFillColor(sf::Color::White);
	choice[10].setOutlineColor(sf::Color::Black);
	choice[10].setOutlineThickness(7);

	choice[1].setSize(sf::Vector2f(280.0f, 50.0f));
	choice[1].setPosition(sf::Vector2f(450, 600));
	choice[1].setFillColor(sf::Color::White);
	choice[1].setOutlineColor(sf::Color::Black);
	choice[1].setOutlineThickness(7);

	choice[2].setSize(sf::Vector2f(280.0f, 50.0f));
	choice[2].setPosition(sf::Vector2f(450, 680));
	choice[2].setFillColor(sf::Color::White);
	choice[2].setOutlineColor(sf::Color::Black);
	choice[2].setOutlineThickness(7);

	sf::String name;
	sf::Text tname(name, font, 40);
	tname.setFillColor(sf::Color::Black);
	tname.setPosition(455, 40);

	sf::String pass;
	sf::String password;
	sf::Text tpassword(password, font, 40);
	tpassword.setFillColor(sf::Color::Black);
	tpassword.setPosition(455, 136);

	sf::String phone;
	sf::Text tphone(phone, font, 40);
	tphone.setFillColor(sf::Color::Black);
	tphone.setPosition(455, 200);

	sf::String car_num;
	sf::Text tcar_num(car_num, font, 40);
	tcar_num.setFillColor(sf::Color::Black);
	tcar_num.setPosition(455, 280);

	sf::String location;
	sf::Text tlocation(location, font, 40);
	tlocation.setFillColor(sf::Color::Black);
	tlocation.setPosition(455, 360);

	sf::String car_name;
	sf::Text tcar_name(car_name, font, 40);
	tcar_name.setFillColor(sf::Color::Black);
	tcar_name.setPosition(455, 440);

	sf::String car_color;
	sf::Text tcar_color(car_color, font, 40);
	tcar_color.setFillColor(sf::Color::Black);
	tcar_color.setPosition(455, 520);

	sf::String car_model;
	sf::Text tcar_model(name, font, 40);
	tcar_model.setFillColor(sf::Color::Black);
	tcar_model.setPosition(455, 600);

	sf::String preferd;
	sf::Text tpreferd(preferd, font, 40);
	tpreferd.setFillColor(sf::Color::Black);
	tpreferd.setPosition(455, 680);

	window.draw(photo);
	for (int i = 0; i <= 11; i++) {

		window.draw(choice[i]);
		if (i < 12)
			window.draw(text[i]);
	}
	window.draw(tname);
	window.draw(tpassword);
	window.draw(tcar_color);
	window.draw(tcar_model);
	window.draw(tcar_num);
	window.draw(tcar_name);
	window.draw(tlocation);
	window.draw(tpreferd);
	window.draw(tphone);
	window.display();
	bool space = false;
	int i = 0;
	vector <string> j;
	sf::Event event;
	while (window.waitEvent(event))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			sf::Vector2i local_position = sf::Mouse::getPosition(window);
			if (local_position.x >= 448 && local_position.x <= 730 && local_position.y >= 36 && local_position.y <= 92)
			{
				cout << "name" << endl;
				active = 2;
			}
			else if (local_position.x >= 448 && local_position.x <= 732 && local_position.y >= 123 && local_position.y <= 175)
			{
				cout << "pasword " << endl;
				active = 3;
			}
			else if (local_position.x >= 448 && local_position.x <= 732 && local_position.y >= 196 && local_position.y <= 253)
			{
				cout << "phone num " << endl;
				active = 4;
			}
			else if (local_position.x >= 448 && local_position.x <= 732 && local_position.y >= 276 && local_position.y <= 332)
			{
				cout << "car num" << endl;
				active = 5;
			}
			else if (local_position.x >= 448 && local_position.x <= 732 && local_position.y >= 354 && local_position.y <= 411)
			{
				cout << "location " << endl;
				active = 6;
			}
			else if (local_position.x >= 448 && local_position.x <= 732 && local_position.y >= 438 && local_position.y <= 493)
			{
				cout << "car name" << endl;
				active = 7;
			}

			else if (local_position.x >= 448 && local_position.x <= 732 && local_position.y >= 515 && local_position.y <= 571)
			{
				cout << "car color" << endl;
				active = 8;
			}
			else if (local_position.x >= 448 && local_position.x <= 732 && local_position.y >= 596 && local_position.y <= 652)
			{
				cout << "car model " << endl;
				active = 9;
			}
			else if (local_position.x >= 448 && local_position.x <= 732 && local_position.y >= 675 && local_position.y <= 730)
			{
				cout << "preferd scope" << endl;
				active = 10;
			}
			else if (local_position.x >= 1036 && local_position.x <= 1160 && local_position.y >= 37 && local_position.y <= 106)
			{
				cout << "back" << endl;
				ay = 0;
				position = 1;
				break;
			}
			else if (local_position.x >= 747 && local_position.x <= 851 && local_position.y >= 687 && local_position.y <= 731)
			{
				cout << "add more" << endl;
				if (preferd.getSize() > 0) {
					j.push_back(preferd);
					while (preferd.getSize() != 0)
					{
						preferd.erase(preferd.getSize() - 1, preferd.getSize());
					}
					tpreferd.setString(preferd);
					i++;
				}
			}
			else if (local_position.x >= 997 && local_position.x <= 1152 && local_position.y >= 697 && local_position.y <= 763)
			{
				if (name.getSize() > 0 && pass.getSize() > 0 && phone.getSize() > 0 && car_num.getSize() > 0 && location.getSize() > 0 && car_name.getSize() > 0 && car_color.getSize() > 0 && car_model.getSize() > 0 && i > 0) {
					g.add_driver(j, name, pass, phone, car_num, location, car_name, car_color, car_model, i);
					ay = 1;
					break;
				}
				else
				{
					space = true;
				}
			}
		}
		if (event.type == sf::Event::TextEntered) {

			if (active == 2 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
				name += event.text.unicode;
				tname.setString(name);
			}
			else if (active == 2 && event.text.unicode == 8 && name.getSize() > 0)
			{
				name.erase(name.getSize() - 1, name.getSize());
				tname.setString(name);
			}
			if (active == 3 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
				pass += event.text.unicode;
				password += "*";
				tpassword.setString(password);
			}
			else if (active == 3 && event.text.unicode == 8 && pass.getSize() > 0) {
				pass.erase(pass.getSize() - 1, pass.getSize());
				password.erase(password.getSize() - 1, password.getSize());
				tpassword.setString(password);
			}
			if (active == 4 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
				phone += event.text.unicode;
				tphone.setString(phone);
			}
			else if (active == 4 && event.text.unicode == 8 && phone.getSize() > 0)
			{
				phone.erase(phone.getSize() - 1, phone.getSize());
				tphone.setString(phone);
			}
			if (active == 5 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
				car_num += event.text.unicode;
				tcar_num.setString(car_num);
			}
			else if (active == 5 && event.text.unicode == 8 && car_num.getSize() > 0)
			{
				car_num.erase(car_num.getSize() - 1, car_num.getSize());
				tcar_num.setString(car_num);
			}
			if (active == 6 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
				location += event.text.unicode;
				tlocation.setString(location);
			}
			else if (active == 6 && event.text.unicode == 8 && location.getSize() > 0)
			{
				location.erase(location.getSize() - 1, location.getSize());
				tlocation.setString(location);
			}
			if (active == 7 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
				car_name += event.text.unicode;
				tcar_name.setString(car_name);
			}
			else if (active == 7 && event.text.unicode == 8 && car_name.getSize() > 0)
			{
				car_name.erase(car_name.getSize() - 1, car_name.getSize());
				tcar_name.setString(car_name);
			}
			if (active == 8 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
				car_color += event.text.unicode;
				tcar_color.setString(car_color);
			}
			else if (active == 8 && event.text.unicode == 8 && car_color.getSize() > 0)
			{
				car_color.erase(car_color.getSize() - 1, car_color.getSize());
				tcar_color.setString(car_color);
			}
			if (active == 9 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
				car_model += event.text.unicode;
				tcar_model.setString(car_model);
			}
			else if (active == 9 && event.text.unicode == 8 && car_model.getSize() > 0)
			{
				car_model.erase(car_model.getSize() - 1, car_model.getSize());
				tcar_model.setString(car_model);
			}
			if (active == 10 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
				preferd += event.text.unicode;
				tpreferd.setString(preferd);
			}
			else if (active == 10 && event.text.unicode == 8 && preferd.getSize() > 0)
			{
				preferd.erase(preferd.getSize() - 1, preferd.getSize());
				tpreferd.setString(preferd);
			}
		}
		window.draw(photo);
		for (int i = 0; i <= 11; i++) {

			window.draw(choice[i]);
			if (i < 12)
				window.draw(text[i]);
		}
		if (space)
			window.draw(text[12]);
		window.draw(tname);
		window.draw(tpassword);
		window.draw(tcar_color);
		window.draw(tcar_model);
		window.draw(tcar_num);
		window.draw(tlocation);
		window.draw(tcar_name);
		window.draw(tpreferd);
		window.draw(tphone);
		window.display();
	}
}

void regcutomer() {

	text[0].setFont(font);
	text[0].setString(" Back ");
	text[0].setCharacterSize(40);
	text[0].setFillColor(sf::Color::White);
	text[0].setPosition(1050, 50);
	text[0].setStyle(sf::Text::Bold);

	text[1].setFont(font);
	text[1].setString(" NAME                  : ");
	text[1].setCharacterSize(40);
	text[1].setFillColor(sf::Color::White);
	text[1].setPosition(53, 40);
	text[1].setStyle(sf::Text::Bold);

	text[2].setFont(font);
	text[2].setString(" PASSWORD           : ");
	text[2].setCharacterSize(40);
	text[2].setFillColor(sf::Color::White);
	text[2].setPosition(50, 120);
	text[2].setStyle(sf::Text::Bold);

	text[3].setFont(font);
	text[3].setString(" PHONE NUM          :  ");
	text[3].setCharacterSize(40);
	text[3].setFillColor(sf::Color::White);
	text[3].setPosition(50, 200);
	text[3].setStyle(sf::Text::Bold);

	text[4].setFont(font);
	text[4].setString(" REGISTER ");
	text[4].setCharacterSize(30);
	text[4].setFillColor(sf::Color::White);
	text[4].setPosition(1005, 710);
	text[4].setStyle(sf::Text::Bold);

	text[5].setFont(font);
	text[5].setString("Please, Fill The Spaces. ");
	text[5].setCharacterSize(40);
	text[5].setFillColor(sf::Color::White);
	text[5].setPosition(380, 740);
	text[5].setStyle(sf::Text::Bold);

	choice[0].setSize(sf::Vector2f(120.0f, 65.0f));
	choice[0].setPosition(sf::Vector2f(1040, 40));
	choice[0].setFillColor(sf::Color::Transparent);
	choice[0].setOutlineThickness(3);
	choice[0].setOutlineColor(sf::Color::White);

	choice[2].setSize(sf::Vector2f(150.0f, 60.0f));
	choice[2].setPosition(sf::Vector2f(1000., 700));
	choice[2].setFillColor(sf::Color::Transparent);
	choice[2].setOutlineThickness(3);
	choice[2].setOutlineColor(sf::Color::White);

	choice[3].setSize(sf::Vector2f(280.0f, 50.0f));
	choice[3].setPosition(sf::Vector2f(450, 40));
	choice[3].setFillColor(sf::Color::White);
	choice[3].setOutlineColor(sf::Color::Black);
	choice[3].setOutlineThickness(7);

	choice[4].setSize(sf::Vector2f(280.0f, 50.0f));
	choice[4].setPosition(sf::Vector2f(450, 125));
	choice[4].setFillColor(sf::Color::White);
	choice[4].setOutlineColor(sf::Color::Black);
	choice[4].setOutlineThickness(7);

	choice[5].setSize(sf::Vector2f(280.0f, 50.0f));
	choice[5].setPosition(sf::Vector2f(450, 200));
	choice[5].setFillColor(sf::Color::White);
	choice[5].setOutlineColor(sf::Color::Black);
	choice[5].setOutlineThickness(7);

	sf::String name;
	sf::Text tname(name, font, 40);
	tname.setFillColor(sf::Color::Black);
	tname.setPosition(455, 40);

	sf::String pass;
	sf::String password;
	sf::Text tpassword(password, font, 40);
	tpassword.setFillColor(sf::Color::Black);
	tpassword.setPosition(455, 136);

	sf::String phone;
	sf::Text tphone(phone, font, 40);
	tphone.setFillColor(sf::Color::Black);
	tphone.setPosition(455, 200);

	window.draw(photo);
	for (int i = 0; i <= 5; i++) {

		window.draw(choice[i]);
		if (i < 5)
			window.draw(text[i]);
	}
	window.draw(tname);
	window.draw(tpassword);
	window.draw(tphone);
	window.display();

	bool space = false;

	sf::Event event;
	while (window.waitEvent(event))
	{

		if (event.type == sf::Event::Closed)
			window.close();
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			sf::Vector2i local_position = sf::Mouse::getPosition(window);
			if (local_position.x >= 448 && local_position.x <= 730 && local_position.y >= 36 && local_position.y <= 92)
			{
				cout << "name" << endl;
				active = 2;
			}
			else if (local_position.x >= 448 && local_position.x <= 732 && local_position.y >= 123 && local_position.y <= 175)
			{
				cout << "pasword " << endl;
				active = 3;
			}
			else if (local_position.x >= 448 && local_position.x <= 732 && local_position.y >= 196 && local_position.y <= 253)
			{
				cout << "phone num " << endl;
				active = 4;
			}
			else if (local_position.x >= 1036 && local_position.x <= 1160 && local_position.y >= 37 && local_position.y <= 106)
			{
				cout << "back" << endl;
				ay = 0;
				position = 1;
				break;
			}
			else if (local_position.x >= 997 && local_position.x <= 1152 && local_position.y >= 697 && local_position.y <= 763)
			{
				if (name.getSize() > 0 && pass.getSize() > 0 && phone.getSize() > 0) {
					g.insert_customer(name, pass, phone);
					ay = 1;
					who_open = g.costumer_num - 1;
					position = 19;
					break;
				}
				else
				{
					space = true;
				}
			}
		}
		if (event.type == sf::Event::TextEntered) {

			if (active == 2 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
				name += event.text.unicode;
				tname.setString(name);
			}
			else if (active == 2 && event.text.unicode == 8 && name.getSize() > 0)
			{
				name.erase(name.getSize() - 1, name.getSize());
				tname.setString(name);
			}
			if (active == 3 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
				pass += event.text.unicode;
				password += "*";
				tpassword.setString(password);
			}
			else if (active == 3 && event.text.unicode == 8 && pass.getSize() > 0) {
				pass.erase(pass.getSize() - 1, pass.getSize());
				password.erase(password.getSize() - 1, password.getSize());
				tpassword.setString(password);
			}
			if (active == 4 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
				phone += event.text.unicode;
				tphone.setString(phone);
			}
			else if (active == 4 && event.text.unicode == 8 && phone.getSize() > 0)
			{
				phone.erase(phone.getSize() - 1, phone.getSize());
				tphone.setString(phone);
			}
		}
		window.draw(photo);
		for (int i = 0; i <= 5; i++) {

			window.draw(choice[i]);
			if (i < 5)
				window.draw(text[i]);
		}
		if (space)
			window.draw(text[5]);
		window.draw(tname);
		window.draw(tpassword);
		window.draw(tphone);
		window.display();
	}
}

bool find(char m, string  pass, int id) {

	if (m == 'd') {

		if (id <= g.D.size() && g.D[id - 1].pass == pass) {
			who_open = id - 1;
			return true;
		}
		else { return false; }
	}
	if (m == 'c') {
		if (id <= g.C.size() && g.C[id - 1].pass == pass)
		{
			who_open = id - 1;
			return true;
		}
		else { return false; }
	}
	if (m == 'a') {
		if (id == admin_id && admin_pass == pass)
		{
			who_open = id;
			return true;
		}
		else { return false; }
	}
	return 0;
}

void login() {

	text[0].setFont(font);
	text[0].setString(" Back ");
	text[0].setCharacterSize(40);
	text[0].setFillColor(sf::Color::White);
	text[0].setPosition(1050, 50);
	text[0].setStyle(sf::Text::Bold);

	text[1].setFont(font);
	text[1].setString(" ID           : ");
	text[1].setCharacterSize(40);
	text[1].setFillColor(sf::Color::White);
	text[1].setPosition(220, 220);
	text[1].setStyle(sf::Text::Bold);

	text[2].setFont(font);
	text[2].setString(" PASSWORD    : ");
	text[2].setCharacterSize(40);
	text[2].setFillColor(sf::Color::White);
	text[2].setPosition(150, 470);
	text[2].setStyle(sf::Text::Bold);

	text[3].setFont(font);
	text[3].setString(" Login ");
	text[3].setCharacterSize(40);
	text[3].setFillColor(sf::Color::White);
	text[3].setPosition(1012, 652);
	text[3].setStyle(sf::Text::Bold);

	text[4].setFont(font);
	text[4].setString("Incorect Password Or Id. ");
	text[4].setCharacterSize(40);
	text[4].setFillColor(sf::Color::White);
	text[4].setPosition(380, 610);
	text[4].setStyle(sf::Text::Bold);

	text[5].setFont(font);
	text[5].setString("Please, Fill The Spaces. ");
	text[5].setCharacterSize(40);
	text[5].setFillColor(sf::Color::White);
	text[5].setPosition(380, 610);
	text[5].setStyle(sf::Text::Bold);

	choice[0].setSize(sf::Vector2f(120.0f, 65.0f));
	choice[0].setPosition(sf::Vector2f(1040, 40));
	choice[0].setFillColor(sf::Color::Transparent);
	choice[0].setOutlineThickness(3);
	choice[0].setOutlineColor(sf::Color::White);

	choice[3].setSize(sf::Vector2f(280.0f, 60.0f));
	choice[3].setPosition(sf::Vector2f(450, 210));
	choice[3].setFillColor(sf::Color::White);
	choice[3].setOutlineColor(sf::Color::Black);
	choice[3].setOutlineThickness(7);

	choice[1].setSize(sf::Vector2f(280.0f, 60.0f));
	choice[1].setPosition(sf::Vector2f(450, 465));
	choice[1].setFillColor(sf::Color::White);
	choice[1].setOutlineColor(sf::Color::Black);
	choice[1].setOutlineThickness(7);

	choice[2].setSize(sf::Vector2f(150.0f, 60.0f));
	choice[2].setPosition(sf::Vector2f(1000., 650));
	choice[2].setFillColor(sf::Color::Transparent);
	choice[2].setOutlineThickness(3);
	choice[2].setOutlineColor(sf::Color::White);

	sf::String id;
	sf::Text textid(id, font, 40);
	textid.setFillColor(sf::Color::Black);
	textid.setPosition(460, 213);

	sf::String pass;

	sf::String password;
	sf::Text textpassword(password, font, 40);
	textpassword.setFillColor(sf::Color::Black);
	textpassword.setPosition(460, 480);

	window.draw(photo);
	for (int i = 0; i < 4; i++) {
		window.draw(choice[i]);
		window.draw(text[i]);
	}

	window.display();

	bool check = false, space = false;

	sf::Event event;
	while (window.waitEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			sf::Vector2i local_position = sf::Mouse::getPosition(window);
			if (local_position.x >= 450 && local_position.x <= 729 && local_position.y >= 208 && local_position.y <= 267)
			{
				cout << "id" << endl;
				active = 1;
			}
			else if (local_position.x >= 448 && local_position.x <= 732 && local_position.y >= 461 && local_position.y <= 525)
			{
				cout << "pasword " << endl;
				active = 2;
			}
			else if (local_position.x >= 996 && local_position.x <= 1150 && local_position.y >= 645 && local_position.y <= 709)
			{
				if (id.getSize() > 0 && pass.getSize() > 0) {

					int x;
					stringstream geek(id);
					geek >> x;

					if (x > 0 && find(type, pass, x)) {
						if (type == 'a')
							position = 18;
						else if (type == 'd')
						{
							position = 17;
						}
						else
						{
							position = 19;
						}
						break;
					}
					else
					{
						check = true;
						space = false;
					}
				}
				else
				{
					check = false;
					space = true;
				}
			}
			else if (local_position.x >= 1036 && local_position.x <= 1160 && local_position.y >= 37 && local_position.y <= 106)
			{
				cout << "back" << endl;
				position = 1;
				break;
			}

		}
		if (event.type == sf::Event::TextEntered) {

			if (active == 1 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
				id += event.text.unicode;
				textid.setString(id);
			}
			else if (active == 1 && event.text.unicode == 8 && id.getSize() > 0)
			{
				id.erase(id.getSize() - 1, id.getSize());
				textid.setString(id);
			}
			if (active == 2 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
				pass += event.text.unicode;
				password += "*";
				textpassword.setString(password);
			}
			else if (active == 2 && event.text.unicode == 8 && pass.getSize() > 0) {
				pass.erase(pass.getSize() - 1, pass.getSize());
				password.erase(password.getSize() - 1, password.getSize());
				textpassword.setString(password);
			}
		}
		window.clear();
		window.draw(photo);
		for (int i = 0; i < 4; i++) {
			window.draw(choice[i]);
			if (i < 4)
				window.draw(text[i]);
		}
		if (space)
			window.draw(text[5]);
		if (check)
			window.draw(text[4]);
		window.draw(textpassword);
		window.draw(textid);
		window.display();
	}
}


void adminpage() {


	text[1].setFont(font);
	text[1].setString("  View Map ");
	text[1].setCharacterSize(40);
	text[1].setFillColor(sf::Color::Cyan);
	text[1].setPosition(490, 140);
	text[1].setStyle(sf::Text::Bold);

	text[2].setFont(font);
	text[2].setString("   Add Edge ");
	text[2].setCharacterSize(40);
	text[2].setFillColor(sf::Color::Cyan);
	text[2].setPosition(490, 250);
	text[2].setStyle(sf::Text::Bold);

	text[5].setFont(font);
	text[5].setString(" Delete map ");
	text[5].setCharacterSize(40);
	text[5].setFillColor(sf::Color::Cyan);
	text[5].setPosition(490, 360);
	text[5].setStyle(sf::Text::Bold);

	text[6].setFont(font);
	text[6].setString(" Delete Node ");
	text[6].setCharacterSize(40);
	text[6].setFillColor(sf::Color::Cyan);
	text[6].setPosition(490, 690);
	text[6].setStyle(sf::Text::Bold);

	text[0].setFont(font);
	text[0].setString("  Add Node ");
	text[0].setCharacterSize(40);
	text[0].setFillColor(sf::Color::Cyan);
	text[0].setPosition(490, 470);
	text[0].setStyle(sf::Text::Bold);

	text[3].setFont(font);
	text[3].setString(" Add Service ");
	text[3].setCharacterSize(40);
	text[3].setFillColor(sf::Color::Cyan);
	text[3].setPosition(490, 580);
	text[3].setStyle(sf::Text::Bold);

	text[4].setFont(font);
	text[4].setString(" Log-out ");
	text[4].setCharacterSize(25);
	text[4].setFillColor(sf::Color::Cyan);
	text[4].setPosition(1047, 56);
	text[4].setStyle(sf::Text::Bold);

	choice[0].setSize(sf::Vector2f(250.0f, 80.0f));
	choice[0].setPosition(sf::Vector2f(480, 234));
	choice[0].setFillColor(sf::Color::Transparent);
	choice[0].setOutlineThickness(3);
	choice[0].setOutlineColor(sf::Color::Cyan);

	choice[2].setSize(sf::Vector2f(250.0f, 80.0f));
	choice[2].setPosition(sf::Vector2f(480, 455));
	choice[2].setFillColor(sf::Color::Transparent);
	choice[2].setOutlineThickness(3);
	choice[2].setOutlineColor(sf::Color::Cyan);

	choice[3].setSize(sf::Vector2f(250.0f, 80.0f));
	choice[3].setPosition(sf::Vector2f(480, 123));
	choice[3].setFillColor(sf::Color::Transparent);
	choice[3].setOutlineThickness(3);
	choice[3].setOutlineColor(sf::Color::Cyan);

	choice[4].setSize(sf::Vector2f(250.0f, 80.0f));
	choice[4].setPosition(sf::Vector2f(480, 346));
	choice[4].setFillColor(sf::Color::Transparent);
	choice[4].setOutlineThickness(3);
	choice[4].setOutlineColor(sf::Color::Cyan);

	choice[5].setSize(sf::Vector2f(250.0f, 80.0f));
	choice[5].setPosition(sf::Vector2f(480, 562));
	choice[5].setFillColor(sf::Color::Transparent);
	choice[5].setOutlineThickness(3);
	choice[5].setOutlineColor(sf::Color::Cyan);

	choice[6].setSize(sf::Vector2f(250.0f, 80.0f));
	choice[6].setPosition(sf::Vector2f(480, 669));
	choice[6].setFillColor(sf::Color::Transparent);
	choice[6].setOutlineThickness(3);
	choice[6].setOutlineColor(sf::Color::Cyan);

	choice[1].setSize(sf::Vector2f(120.0f, 68.0f));
	choice[1].setPosition(sf::Vector2f(1040, 40));
	choice[1].setFillColor(sf::Color::Transparent);
	choice[1].setOutlineThickness(3);
	choice[1].setOutlineColor(sf::Color::Cyan);

	window.clear();
	window.draw(photo);
	for (int i = 0; i < 7; i++)
	{
		window.draw(choice[i]);
		window.draw(text[i]);
	}
	window.display();

	sf::Event event;
	while (window.waitEvent(event))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			sf::Vector2i local_position = sf::Mouse::getPosition(window);
			if (local_position.x >= 477 && local_position.x <= 732 && local_position.y >= 118 && local_position.y <= 203)
			{
				position = 20;
				cout << "view map" << endl;
				break;

			}
			else if (local_position.x >= 477 && local_position.x <= 732 && local_position.y >= 666 && local_position.y <= 750)
			{
				cout << "delete node" << endl;
				position = 100;
				break;
			}
			else if (local_position.x >= 477 && local_position.x <= 732 && local_position.y >= 229 && local_position.y <= 313)
			{
				cout << "add edge" << endl;
				position = 21;
				break;
			}
			else if (local_position.x >= 477 && local_position.x <= 732 && local_position.y >= 343 && local_position.y <= 427)
			{
				position = 22;
				cout << "delete map" << endl;
				break;
			}
			else if (local_position.x >= 477 && local_position.x <= 732 && local_position.y >= 450 && local_position.y <= 534)
			{
				position = 23;
				cout << "add node" << endl;
				break;
			}
			else if (local_position.x >= 477 && local_position.x <= 732 && local_position.y >= 559 && local_position.y <= 642)
			{
				position = 24;
				cout << "add service" << endl;
				break;
			}
			else if (local_position.x >= 1036 && local_position.x <= 1160 && local_position.y >= 37 && local_position.y <= 106)
			{

				position = 1;
				break;
			}
		}
	}
}

void addnode() {

	text[0].setFont(font);
	text[0].setString(" Back ");
	text[0].setCharacterSize(40);
	text[0].setFillColor(sf::Color::White);
	text[0].setPosition(1050, 50);
	text[0].setStyle(sf::Text::Bold);

	text[1].setFont(font);
	text[1].setString(" NAME           : ");
	text[1].setCharacterSize(40);
	text[1].setFillColor(sf::Color::White);
	text[1].setPosition(220, 220);
	text[1].setStyle(sf::Text::Bold);

	text[2].setFont(font);
	text[2].setString(" CORDINATES ");
	text[2].setCharacterSize(40);
	text[2].setFillColor(sf::Color::White);
	text[2].setPosition(450, 370);
	text[2].setStyle(sf::Text::Bold);

	text[4].setFont(font);
	text[4].setString(" Y    : ");
	text[4].setCharacterSize(40);
	text[4].setFillColor(sf::Color::White);
	text[4].setPosition(640, 470);
	text[4].setStyle(sf::Text::Bold);

	text[5].setFont(font);
	text[5].setString(" X   : ");
	text[5].setCharacterSize(40);
	text[5].setFillColor(sf::Color::White);
	text[5].setPosition(140, 470);
	text[5].setStyle(sf::Text::Bold);

	text[3].setFont(font);
	text[3].setString("  ADD ");
	text[3].setCharacterSize(40);
	text[3].setFillColor(sf::Color::White);
	text[3].setPosition(1012, 652);
	text[3].setStyle(sf::Text::Bold);

	text[6].setFont(font);
	text[6].setString(" Please, Fill the spaces. ");
	text[6].setCharacterSize(35);
	text[6].setFillColor(sf::Color::White);
	text[6].setPosition(370, 570);
	text[6].setStyle(sf::Text::Bold);

	text[7].setFont(font);
	text[7].setString("Incorrect place on the graph. ");
	text[7].setCharacterSize(35);
	text[7].setFillColor(sf::Color::White);
	text[7].setPosition(350, 570);
	text[7].setStyle(sf::Text::Bold);

	text[8].setFont(font);
	text[8].setString("X bound from (100 - to - 1100)");
	text[8].setCharacterSize(35);
	text[8].setFillColor(sf::Color::White);
	text[8].setPosition(348, 610);
	text[8].setStyle(sf::Text::Bold);

	text[9].setFont(font);
	text[9].setString("Y bound from (50 - to - 750)");
	text[9].setCharacterSize(35);
	text[9].setFillColor(sf::Color::White);
	text[9].setPosition(348, 650);
	text[9].setStyle(sf::Text::Bold);

	choice[0].setSize(sf::Vector2f(120.0f, 65.0f));
	choice[0].setPosition(sf::Vector2f(1040, 40));
	choice[0].setFillColor(sf::Color::Transparent);
	choice[0].setOutlineThickness(3);
	choice[0].setOutlineColor(sf::Color::White);


	choice[3].setSize(sf::Vector2f(280.0f, 60.0f));
	choice[3].setPosition(sf::Vector2f(450, 210));
	choice[3].setFillColor(sf::Color::White);
	choice[3].setOutlineColor(sf::Color::Black);
	choice[3].setOutlineThickness(7);

	choice[1].setSize(sf::Vector2f(100.0f, 60.0f));
	choice[1].setPosition(sf::Vector2f(750, 465));
	choice[1].setFillColor(sf::Color::White);
	choice[1].setOutlineColor(sf::Color::Black);
	choice[1].setOutlineThickness(7);

	choice[4].setSize(sf::Vector2f(100.0f, 60.0f));
	choice[4].setPosition(sf::Vector2f(250, 465));
	choice[4].setFillColor(sf::Color::White);
	choice[4].setOutlineColor(sf::Color::Black);
	choice[4].setOutlineThickness(7);

	choice[2].setSize(sf::Vector2f(150.0f, 60.0f));
	choice[2].setPosition(sf::Vector2f(1000., 650));
	choice[2].setFillColor(sf::Color::Transparent);
	choice[2].setOutlineThickness(3);
	choice[2].setOutlineColor(sf::Color::White);

	sf::String name;
	sf::Text tname(name, font, 40);
	tname.setFillColor(sf::Color::Black);
	tname.setPosition(460, 213);

	sf::String x;
	sf::Text tx(x, font, 40);
	tx.setFillColor(sf::Color::Black);
	tx.setPosition(257, 470);

	sf::String y;
	sf::Text ty(y, font, 40);
	ty.setFillColor(sf::Color::Black);
	ty.setPosition(763, 470);

	bool spaces = false, bound = false;

	window.draw(photo);
	for (int i = 0; i < 6; i++) {
		if (i < 5)
			window.draw(choice[i]);
		window.draw(text[i]);
	}
	window.display();


	sf::Event event;
	while (window.waitEvent(event))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			sf::Vector2i local_position = sf::Mouse::getPosition(window);
			if (local_position.x >= 450 && local_position.x <= 729 && local_position.y >= 208 && local_position.y <= 267)
			{
				cout << "name" << endl;
				active = 1;
			}
			else if (local_position.x >= 248 && local_position.x <= 351 && local_position.y >= 461 && local_position.y <= 524)
			{

				cout << "x " << endl;
				active = 2;
			}
			else if (local_position.x >= 746 && local_position.x <= 853 && local_position.y >= 462 && local_position.y <= 525)
			{
				cout << "y " << endl;
				active = 3;
			}
			else if (local_position.x >= 996 && local_position.x <= 1150 && local_position.y >= 645 && local_position.y <= 709)
			{
				if (name.getSize() > 0 && y.getSize() > 0 && x.getSize() > 0) {
					stringstream geeky(y);
					int y;
					geeky >> y;
					stringstream geekx(x);
					int x;
					geekx >> x;
					if (x <= 1100 && x >= 100 && y >= 50 && y <= 750) {
						transform(name.begin(), name.end(), name.begin(), ::tolower);
						g.addNode(name, x, y);
						position = 18;
						break;
					}
					else
					{
						bound = true;
						spaces = false;
					}

				}
				else
				{
					bound = false;
					spaces = true;
				}
			}
			else if (local_position.x >= 1036 && local_position.x <= 1160 && local_position.y >= 37 && local_position.y <= 106)
			{
				cout << "back" << endl;
				position = 18;
				break;
			}
		}
		if (event.type == sf::Event::TextEntered) {

			if (active == 1 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
				name += event.text.unicode;
				tname.setString(name);
			}
			else if (active == 1 && event.text.unicode == 8 && name.getSize() > 0)
			{
				name.erase(name.getSize() - 1, name.getSize());
				tname.setString(name);
			}
			if (active == 2 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
				x += event.text.unicode;
				tx.setString(x);
			}
			else if (active == 2 && event.text.unicode == 8 && x.getSize() > 0) {
				x.erase(x.getSize() - 1, x.getSize());
				tx.setString(x);
			}
			if (active == 3 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
				y += event.text.unicode;
				ty.setString(y);
			}
			else if (active == 3 && event.text.unicode == 8 && y.getSize() > 0) {
				y.erase(y.getSize() - 1, y.getSize());
				ty.setString(y);
			}
		}
		window.clear();
		window.draw(photo);
		for (int i = 0; i < 6; i++) {
			if (i < 5)
				window.draw(choice[i]);
			window.draw(text[i]);
		}
		if (spaces)
			window.draw(text[6]);
		if (bound) {
			window.draw(text[7]);
			window.draw(text[8]);
			window.draw(text[9]);
		}
		window.draw(tx);
		window.draw(ty);
		window.draw(tname);
		window.display();
	}
}

void addedge() {

	text[0].setFont(font);
	text[0].setString(" Back ");
	text[0].setCharacterSize(40);
	text[0].setFillColor(sf::Color::White);
	text[0].setPosition(1050, 50);
	text[0].setStyle(sf::Text::Bold);

	text[1].setFont(font);
	text[1].setString(" FIRST NAME         : ");
	text[1].setCharacterSize(40);
	text[1].setFillColor(sf::Color::White);
	text[1].setPosition(100, 40);
	text[1].setStyle(sf::Text::Bold);

	text[2].setFont(font);
	text[2].setString(" SECOND NAME      : ");
	text[2].setCharacterSize(40);
	text[2].setFillColor(sf::Color::White);
	text[2].setPosition(100, 120);
	text[2].setStyle(sf::Text::Bold);

	text[3].setFont(font);
	text[3].setString(" DISTANCE             :  ");
	text[3].setCharacterSize(40);
	text[3].setFillColor(sf::Color::White);
	text[3].setPosition(100, 200);
	text[3].setStyle(sf::Text::Bold);

	text[4].setFont(font);
	text[4].setString(" TRANSPORTAION METHOUD  ");
	text[4].setCharacterSize(40);
	text[4].setFillColor(sf::Color::White);
	text[4].setPosition(330, 330);
	text[4].setStyle(sf::Text::Bold);

	text[6].setFont(font);
	text[6].setString(" Uber Car ");
	text[6].setCharacterSize(35);
	text[6].setFillColor(sf::Color::White);
	text[6].setPosition(170, 470);
	text[6].setStyle(sf::Text::Bold);

	text[7].setFont(font);
	text[7].setString(" Uber Bus ");
	text[7].setCharacterSize(35);
	text[7].setFillColor(sf::Color::White);
	text[7].setPosition(470, 470);
	text[7].setStyle(sf::Text::Bold);

	text[8].setFont(font);
	text[8].setString(" Uber Metro ");
	text[8].setCharacterSize(35);
	text[8].setFillColor(sf::Color::White);
	text[8].setPosition(750, 470);
	text[8].setStyle(sf::Text::Bold);

	text[5].setFont(font);
	text[5].setString("  ADD ");
	text[5].setCharacterSize(40);
	text[5].setFillColor(sf::Color::White);
	text[5].setPosition(1012, 652);
	text[5].setStyle(sf::Text::Bold);

	text[9].setFont(font);
	text[9].setString(" Please, Fill the spaces. ");
	text[9].setCharacterSize(35);
	text[9].setFillColor(sf::Color::White);
	text[9].setPosition(370, 570);
	text[9].setStyle(sf::Text::Bold);

	text[10].setFont(font);
	text[10].setString("This Node Is Not Represented On Graph. ");
	text[10].setCharacterSize(35);
	text[10].setFillColor(sf::Color::White);
	text[10].setPosition(350, 570);
	text[10].setStyle(sf::Text::Bold);

	choice[0].setSize(sf::Vector2f(120.0f, 65.0f));
	choice[0].setPosition(sf::Vector2f(1040, 40));
	choice[0].setFillColor(sf::Color::Transparent);
	choice[0].setOutlineThickness(3);
	choice[0].setOutlineColor(sf::Color::White);

	choice[3].setSize(sf::Vector2f(280.0f, 50.0f));
	choice[3].setPosition(sf::Vector2f(450, 40));
	choice[3].setFillColor(sf::Color::White);
	choice[3].setOutlineColor(sf::Color::Black);
	choice[3].setOutlineThickness(7);

	choice[4].setSize(sf::Vector2f(280.0f, 50.0f));
	choice[4].setPosition(sf::Vector2f(450, 125));
	choice[4].setFillColor(sf::Color::White);
	choice[4].setOutlineColor(sf::Color::Black);
	choice[4].setOutlineThickness(7);

	choice[1].setSize(sf::Vector2f(280.0f, 50.0f));
	choice[1].setPosition(sf::Vector2f(450, 200));
	choice[1].setFillColor(sf::Color::White);
	choice[1].setOutlineColor(sf::Color::Black);
	choice[1].setOutlineThickness(7);

	choice[5].setSize(sf::Vector2f(200.0f, 80.0f));
	choice[5].setPosition(sf::Vector2f(150, 450));
	choice[5].setFillColor(sf::Color::Transparent);
	choice[5].setOutlineColor(sf::Color::White);
	choice[5].setOutlineThickness(3);

	choice[6].setSize(sf::Vector2f(200.0f, 80.0f));
	choice[6].setPosition(sf::Vector2f(450, 450));
	choice[6].setFillColor(sf::Color::Transparent);
	choice[6].setOutlineColor(sf::Color::White);
	choice[6].setOutlineThickness(3);

	choice[7].setSize(sf::Vector2f(200.0f, 80.0f));
	choice[7].setPosition(sf::Vector2f(750, 450));
	choice[7].setFillColor(sf::Color::Transparent);
	choice[7].setOutlineColor(sf::Color::White);
	choice[7].setOutlineThickness(3);

	choice[2].setSize(sf::Vector2f(150.0f, 60.0f));
	choice[2].setPosition(sf::Vector2f(1000., 650));
	choice[2].setFillColor(sf::Color::Transparent);
	choice[2].setOutlineThickness(3);
	choice[2].setOutlineColor(sf::Color::White);

	sf::String namef;
	sf::Text tnamef(namef, font, 40);
	tnamef.setFillColor(sf::Color::Black);
	tnamef.setPosition(460, 40);

	sf::String names;
	sf::Text tnames(names, font, 40);
	tnames.setFillColor(sf::Color::Black);
	tnames.setPosition(460, 125);

	sf::String d;
	sf::Text td(d, font, 40);
	td.setFillColor(sf::Color::Black);
	td.setPosition(460, 200);


	window.draw(photo);
	for (int i = 0; i <= 8; i++) {

		if (i < 8)
			window.draw(choice[i]);
		window.draw(text[i]);
	}

	window.display();

	string t;
	int o = 0;
	bool spaces = false, no = false;
	sf::Event event;
	while (window.waitEvent(event))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			sf::Vector2i local_position = sf::Mouse::getPosition(window);
			if (local_position.x >= 448 && local_position.x <= 730 && local_position.y >= 36 && local_position.y <= 92)
			{
				cout << "first name" << endl;
				active = 2;
			}
			else if (local_position.x >= 448 && local_position.x <= 732 && local_position.y >= 123 && local_position.y <= 175)
			{
				cout << "second name " << endl;
				active = 3;
			}
			else if (local_position.x >= 448 && local_position.x <= 732 && local_position.y >= 196 && local_position.y <= 253)
			{
				cout << "distance" << endl;
				active = 4;
			}
			else if (local_position.x >= 146 && local_position.x <= 351 && local_position.y >= 447 && local_position.y <= 530)
			{
				cout << "CAR" << endl;
				choice[5].setOutlineColor(sf::Color::Magenta);  text[6].setFillColor(sf::Color::Magenta);
				choice[6].setOutlineColor(sf::Color::White);    text[7].setFillColor(sf::Color::White);
				choice[7].setOutlineColor(sf::Color::White);    text[8].setFillColor(sf::Color::White);
				t = "Uber";
				o = 1;
				active = 5;
			}
			else if (local_position.x >= 447 && local_position.x <= 653 && local_position.y >= 447 && local_position.y <= 530)
			{
				cout << "BUS" << endl;
				choice[5].setOutlineColor(sf::Color::White);  text[6].setFillColor(sf::Color::White);
				choice[6].setOutlineColor(sf::Color::Magenta);    text[7].setFillColor(sf::Color::Magenta);
				choice[7].setOutlineColor(sf::Color::White);    text[8].setFillColor(sf::Color::White);
				t = "Bus";
				o = 1;
				active = 5;
			}
			else if (local_position.x >= 746 && local_position.x <= 951 && local_position.y >= 447 && local_position.y <= 530)
			{
				cout << "METRO" << endl;
				choice[5].setOutlineColor(sf::Color::White);  text[6].setFillColor(sf::Color::White);
				choice[6].setOutlineColor(sf::Color::White);    text[7].setFillColor(sf::Color::White);
				choice[7].setOutlineColor(sf::Color::Magenta);    text[8].setFillColor(sf::Color::Magenta);
				t = "Metro";
				o = 1;
				active = 5;
			}
			else if (local_position.x >= 996 && local_position.x <= 1150 && local_position.y >= 645 && local_position.y <= 709)
			{
				if (names.getSize() > 0 && namef.getSize() > 0 && d.getSize() > 0 && o == 1) {
					transform(names.begin(), names.end(), names.begin(), ::tolower);
					transform(namef.begin(), namef.end(), namef.begin(), ::tolower);
					if (g.getIdx[names] != 0 && g.getIdx[namef] != 0) {
						stringstream geek(d);
						int x;
						geek >> x;
						g.addEdge(namef, names, t, x);

						position = 18;
						break;
					}
					else {
						no = true;
						spaces = false;
					}

				}
				else
				{
					no = false;
					spaces = true;
				}
			}
			else if (local_position.x >= 1036 && local_position.x <= 1160 && local_position.y >= 37 && local_position.y <= 106)
			{
				cout << "back" << endl;
				position = 18;
				break;
			}

		}
		if (event.type == sf::Event::TextEntered) {
			if (active == 2 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
				namef += event.text.unicode;
				tnamef.setString(namef);
			}
			else if (active == 2 && event.text.unicode == 8 && namef.getSize() > 0)
			{
				namef.erase(namef.getSize() - 1, namef.getSize());
				tnamef.setString(namef);
			}
			if (active == 3 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
				names += event.text.unicode;
				tnames.setString(names);
			}
			else if (active == 3 && event.text.unicode == 8 && names.getSize() > 0) {
				names.erase(names.getSize() - 1, names.getSize());
				tnames.setString(names);
			}
			if (active == 4 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
				d += event.text.unicode;
				td.setString(d);
			}
			else if (active == 4 && event.text.unicode == 8 && d.getSize() > 0)
			{
				d.erase(d.getSize() - 1, d.getSize());
				td.setString(d);
			}
		}
		window.draw(photo);
		for (int i = 0; i <= 8; i++) {

			if (i < 8)
				window.draw(choice[i]);
			window.draw(text[i]);
		}
		if (spaces)
			window.draw(text[9]);
		if (no)
			window.draw(text[10]);
		window.draw(tnamef);
		window.draw(tnames);
		window.draw(td);
		window.display();
	}

}

void addservice() {

	text[0].setFont(font);
	text[0].setString(" Back ");
	text[0].setCharacterSize(40);
	text[0].setFillColor(sf::Color::White);
	text[0].setPosition(1050, 50);
	text[0].setStyle(sf::Text::Bold);

	text[1].setFont(font);
	text[1].setString(" NAME            : ");
	text[1].setCharacterSize(40);
	text[1].setFillColor(sf::Color::White);
	text[1].setPosition(100, 40);
	text[1].setStyle(sf::Text::Bold);

	text[2].setFont(font);
	text[2].setString(" PLACE           : ");
	text[2].setCharacterSize(40);
	text[2].setFillColor(sf::Color::White);
	text[2].setPosition(100, 120);
	text[2].setStyle(sf::Text::Bold);

	text[3].setFont(font);
	text[3].setString(" SUPER-MARKET   ");
	text[3].setCharacterSize(27);
	text[3].setFillColor(sf::Color::White);
	text[3].setPosition(750, 325);
	text[3].setStyle(sf::Text::Bold);

	text[4].setFont(font);
	text[4].setString(" HOSPITAL  ");
	text[4].setCharacterSize(35);
	text[4].setFillColor(sf::Color::White);
	text[4].setPosition(170, 320);
	text[4].setStyle(sf::Text::Bold);

	text[6].setFont(font);
	text[6].setString("   VET ");
	text[6].setCharacterSize(35);
	text[6].setFillColor(sf::Color::White);
	text[6].setPosition(190, 470);
	text[6].setStyle(sf::Text::Bold);

	text[7].setFont(font);
	text[7].setString("  BANK ");
	text[7].setCharacterSize(35);
	text[7].setFillColor(sf::Color::White);
	text[7].setPosition(490, 470);
	text[7].setStyle(sf::Text::Bold);

	text[8].setFont(font);
	text[8].setString(" HOTEL ");
	text[8].setCharacterSize(35);
	text[8].setFillColor(sf::Color::White);
	text[8].setPosition(495, 320);
	text[8].setStyle(sf::Text::Bold);

	text[9].setFont(font);
	text[9].setString("    SCHOOL ");
	text[9].setCharacterSize(35);
	text[9].setFillColor(sf::Color::White);
	text[9].setPosition(750, 470);
	text[9].setStyle(sf::Text::Bold);

	text[5].setFont(font);
	text[5].setString("  ADD ");
	text[5].setCharacterSize(40);
	text[5].setFillColor(sf::Color::White);
	text[5].setPosition(1012, 652);
	text[5].setStyle(sf::Text::Bold);

	text[10].setFont(font);
	text[10].setString(" Please, Fill the spaces. ");
	text[10].setCharacterSize(35);
	text[10].setFillColor(sf::Color::White);
	text[10].setPosition(370, 570);
	text[10].setStyle(sf::Text::Bold);

	text[11].setFont(font);
	text[11].setString("This Node Is Not Represented On Graph. ");
	text[11].setCharacterSize(35);
	text[11].setFillColor(sf::Color::White);
	text[11].setPosition(350, 570);
	text[11].setStyle(sf::Text::Bold);

	choice[0].setSize(sf::Vector2f(120.0f, 65.0f));
	choice[0].setPosition(sf::Vector2f(1040, 40));
	choice[0].setFillColor(sf::Color::Transparent);
	choice[0].setOutlineThickness(3);
	choice[0].setOutlineColor(sf::Color::White);

	choice[3].setSize(sf::Vector2f(280.0f, 50.0f));
	choice[3].setPosition(sf::Vector2f(450, 40));
	choice[3].setFillColor(sf::Color::White);
	choice[3].setOutlineColor(sf::Color::Black);
	choice[3].setOutlineThickness(7);

	choice[4].setSize(sf::Vector2f(280.0f, 50.0f));
	choice[4].setPosition(sf::Vector2f(450, 125));
	choice[4].setFillColor(sf::Color::White);
	choice[4].setOutlineColor(sf::Color::Black);
	choice[4].setOutlineThickness(7);

	choice[5].setSize(sf::Vector2f(200.0f, 80.0f));
	choice[5].setPosition(sf::Vector2f(150, 450));
	choice[5].setFillColor(sf::Color::Transparent);
	choice[5].setOutlineColor(sf::Color::White);
	choice[5].setOutlineThickness(3);

	choice[6].setSize(sf::Vector2f(200.0f, 80.0f));
	choice[6].setPosition(sf::Vector2f(450, 450));
	choice[6].setFillColor(sf::Color::Transparent);
	choice[6].setOutlineColor(sf::Color::White);
	choice[6].setOutlineThickness(3);

	choice[7].setSize(sf::Vector2f(200.0f, 80.0f));
	choice[7].setPosition(sf::Vector2f(750, 450));
	choice[7].setFillColor(sf::Color::Transparent);
	choice[7].setOutlineColor(sf::Color::White);
	choice[7].setOutlineThickness(3);

	choice[2].setSize(sf::Vector2f(150.0f, 60.0f));
	choice[2].setPosition(sf::Vector2f(1000., 650));
	choice[2].setFillColor(sf::Color::Transparent);
	choice[2].setOutlineThickness(3);
	choice[2].setOutlineColor(sf::Color::White);

	choice[8].setSize(sf::Vector2f(200.0f, 80.0f));
	choice[8].setPosition(sf::Vector2f(150, 300));
	choice[8].setFillColor(sf::Color::Transparent);
	choice[8].setOutlineColor(sf::Color::White);
	choice[8].setOutlineThickness(3);

	choice[9].setSize(sf::Vector2f(200.0f, 80.0f));
	choice[9].setPosition(sf::Vector2f(450, 300));
	choice[9].setFillColor(sf::Color::Transparent);
	choice[9].setOutlineColor(sf::Color::White);
	choice[9].setOutlineThickness(3);

	choice[1].setSize(sf::Vector2f(200.0f, 80.0f));
	choice[1].setPosition(sf::Vector2f(750, 300));
	choice[1].setFillColor(sf::Color::Transparent);
	choice[1].setOutlineColor(sf::Color::White);
	choice[1].setOutlineThickness(3);

	sf::String name;
	sf::Text tname(name, font, 40);
	tname.setFillColor(sf::Color::Black);
	tname.setPosition(460, 40);

	sf::String place;
	sf::Text tplace(place, font, 40);
	tplace.setFillColor(sf::Color::Black);
	tplace.setPosition(460, 125);

	window.draw(photo);
	for (int i = 0; i <= 9; i++) {
		window.draw(choice[i]);
		window.draw(text[i]);
	}

	window.display();

	int t = 0;
	bool spaces = false;
	bool noo = false;
	sf::Event event;
	while (window.waitEvent(event))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			sf::Vector2i local_position = sf::Mouse::getPosition(window);
			if (local_position.x >= 448 && local_position.x <= 730 && local_position.y >= 36 && local_position.y <= 92)
			{
				cout << "place" << endl;
				active = 2;
			}
			else if (local_position.x >= 448 && local_position.x <= 732 && local_position.y >= 123 && local_position.y <= 175)
			{
				cout << "name " << endl;
				active = 3;
			}
			else if (local_position.x >= 146 && local_position.x <= 351 && local_position.y >= 296 && local_position.y <= 378)
			{
				cout << "HOSPITAL" << endl;
				choice[8].setOutlineColor(sf::Color::Magenta);  text[4].setFillColor(sf::Color::Magenta);
				choice[9].setOutlineColor(sf::Color::White);  text[8].setFillColor(sf::Color::White);
				choice[1].setOutlineColor(sf::Color::White);  text[3].setFillColor(sf::Color::White);
				choice[5].setOutlineColor(sf::Color::White);     text[6].setFillColor(sf::Color::White);
				choice[6].setOutlineColor(sf::Color::White);      text[7].setFillColor(sf::Color::White);
				choice[7].setOutlineColor(sf::Color::White);    text[9].setFillColor(sf::Color::White);
				t = 0;
			}
			else if (local_position.x >= 448 && local_position.x <= 653 && local_position.y >= 296 && local_position.y <= 378)
			{
				cout << "HOTEL" << endl;
				choice[8].setOutlineColor(sf::Color::White);  text[4].setFillColor(sf::Color::White);
				choice[9].setOutlineColor(sf::Color::Magenta);  text[8].setFillColor(sf::Color::Magenta);
				choice[1].setOutlineColor(sf::Color::White);  text[3].setFillColor(sf::Color::White);
				choice[5].setOutlineColor(sf::Color::White);     text[6].setFillColor(sf::Color::White);
				choice[6].setOutlineColor(sf::Color::White);      text[7].setFillColor(sf::Color::White);
				choice[7].setOutlineColor(sf::Color::White);    text[9].setFillColor(sf::Color::White);
				t = 4;
			}
			else if (local_position.x >= 748 && local_position.x <= 952 && local_position.y >= 296 && local_position.y <= 378)
			{
				cout << "SUPER-MARKET" << endl;
				choice[8].setOutlineColor(sf::Color::White);  text[4].setFillColor(sf::Color::White);
				choice[9].setOutlineColor(sf::Color::White);  text[8].setFillColor(sf::Color::White);
				choice[1].setOutlineColor(sf::Color::Magenta);  text[3].setFillColor(sf::Color::Magenta);
				choice[5].setOutlineColor(sf::Color::White);     text[6].setFillColor(sf::Color::White);
				choice[6].setOutlineColor(sf::Color::White);      text[7].setFillColor(sf::Color::White);
				choice[7].setOutlineColor(sf::Color::White);    text[9].setFillColor(sf::Color::White);
				t = 3;
			}
			else if (local_position.x >= 146 && local_position.x <= 351 && local_position.y >= 447 && local_position.y <= 530)
			{
				cout << "VET" << endl;
				choice[8].setOutlineColor(sf::Color::White);  text[4].setFillColor(sf::Color::White);
				choice[9].setOutlineColor(sf::Color::White);  text[8].setFillColor(sf::Color::White);
				choice[1].setOutlineColor(sf::Color::White);  text[3].setFillColor(sf::Color::White);
				choice[5].setOutlineColor(sf::Color::Magenta);     text[6].setFillColor(sf::Color::Magenta);
				choice[6].setOutlineColor(sf::Color::White);      text[7].setFillColor(sf::Color::White);
				choice[7].setOutlineColor(sf::Color::White);    text[9].setFillColor(sf::Color::White);
				t = 1;
			}
			else if (local_position.x >= 447 && local_position.x <= 653 && local_position.y >= 447 && local_position.y <= 530)
			{
				cout << "BANK" << endl;
				choice[8].setOutlineColor(sf::Color::White);  text[4].setFillColor(sf::Color::White);
				choice[9].setOutlineColor(sf::Color::White);  text[8].setFillColor(sf::Color::White);
				choice[1].setOutlineColor(sf::Color::White);  text[3].setFillColor(sf::Color::White);
				choice[5].setOutlineColor(sf::Color::White);     text[6].setFillColor(sf::Color::White);
				choice[6].setOutlineColor(sf::Color::Magenta);      text[7].setFillColor(sf::Color::Magenta);
				choice[7].setOutlineColor(sf::Color::White);    text[9].setFillColor(sf::Color::White);
				t = 2;
			}
			else if (local_position.x >= 746 && local_position.x <= 951 && local_position.y >= 447 && local_position.y <= 530)
			{
				cout << "SCHOOL" << endl;
				choice[8].setOutlineColor(sf::Color::White);  text[4].setFillColor(sf::Color::White);
				choice[9].setOutlineColor(sf::Color::White);  text[8].setFillColor(sf::Color::White);
				choice[1].setOutlineColor(sf::Color::White);  text[3].setFillColor(sf::Color::White);
				choice[5].setOutlineColor(sf::Color::White);     text[6].setFillColor(sf::Color::White);
				choice[6].setOutlineColor(sf::Color::White);      text[7].setFillColor(sf::Color::White);
				choice[7].setOutlineColor(sf::Color::Magenta);    text[9].setFillColor(sf::Color::Magenta);
				t = 5;
			}

			else if (local_position.x >= 996 && local_position.x <= 1150 && local_position.y >= 645 && local_position.y <= 709)
			{
				if (name.getSize() > 0 && place.getSize() > 0 && t != 0) {
					transform(place.begin(), place.end(), place.begin(), ::tolower);
					if (g.getIdx[place] != 0) {
						g.add_place(place, name, t);
						position = 18;
						break;
					}
					else
					{
						noo = true;
						spaces = false;
					}
				}
				else
				{
					noo = false;
					spaces = true;
				}
			}
			else if (local_position.x >= 1036 && local_position.x <= 1160 && local_position.y >= 37 && local_position.y <= 106)
			{
				cout << "back" << endl;
				position = 18;
				break;
			}

		}
		if (event.type == sf::Event::TextEntered) {

			if (active == 2 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
				name += event.text.unicode;
				tname.setString(name);
			}
			else if (active == 2 && event.text.unicode == 8 && name.getSize() > 0)
			{
				name.erase(name.getSize() - 1, name.getSize());
				tname.setString(name);
			}
			if (active == 3 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
				place += event.text.unicode;
				tplace.setString(place);
			}
			else if (active == 3 && event.text.unicode == 8 && place.getSize() > 0) {
				place.erase(place.getSize() - 1, place.getSize());
				tplace.setString(place);
			}

		}
		window.draw(photo);
		for (int i = 0; i <= 9; i++) {
			window.draw(choice[i]);
			window.draw(text[i]);
		}
		if (spaces)
			window.draw(text[10]);
		if (noo) {
			window.draw(text[11]);
		}
		window.draw(tname);
		window.draw(tplace);
		window.display();
	}
}

void deletemap() {

	text[0].setFont(font);
	text[0].setString("DO YOU WANT TO DELETE GRAPH DATA  ?? ");
	text[0].setCharacterSize(60);
	text[0].setFillColor(sf::Color::White);
	text[0].setPosition(100, 270);
	text[0].setStyle(sf::Text::Bold);

	text[1].setFont(font);
	text[1].setString("  YES ");
	text[1].setCharacterSize(50);
	text[1].setFillColor(sf::Color::White);
	text[1].setPosition(350, 570);
	text[1].setStyle(sf::Text::Bold);

	text[1].setFont(font);
	text[2].setString(" NO ");
	text[2].setCharacterSize(50);
	text[2].setFillColor(sf::Color::White);
	text[2].setPosition(755, 570);
	text[2].setStyle(sf::Text::Bold);

	choice[0].setSize(sf::Vector2f(200.0f, 85.0f));
	choice[0].setPosition(sf::Vector2f(320, 560));
	choice[0].setFillColor(sf::Color::Transparent);
	choice[0].setOutlineThickness(3);
	choice[0].setOutlineColor(sf::Color::White);

	choice[1].setSize(sf::Vector2f(200.0f, 85.0f));
	choice[1].setPosition(sf::Vector2f(700, 560));
	choice[1].setFillColor(sf::Color::Transparent);
	choice[1].setOutlineThickness(3);
	choice[1].setOutlineColor(sf::Color::White);

	window.clear();
	window.draw(photo);
	for (int i = 0; i <= 2; i++) {
		if (i < 2)
			window.draw(choice[i]);
		window.draw(text[i]);
	}
	window.display();

	sf::Event event;
	while (window.waitEvent(event))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			sf::Vector2i local_position = sf::Mouse::getPosition(window);
			if (local_position.x >= 317 && local_position.x <= 522 && local_position.y >= 556 && local_position.y <= 646)
			{
				g.deleteGraph();
				position = 18;
				break;
			}
			else if (local_position.x >= 697 && local_position.x <= 903 && local_position.y >= 556 && local_position.y <= 646)
			{
				position = 18;
				break;
			}
		}
	}
}

void viewmap() {

	Font font;
	font.loadFromFile("Roboto-MediumItalic.ttf");

	text[0].setFont(font);
	text[0].setString(" BACK ");
	text[0].setCharacterSize(20);
	text[0].setFillColor(sf::Color::White);
	text[0].setPosition(1130, 103);
	text[0].setStyle(sf::Text::Bold);

	choice[0].setSize(sf::Vector2f(70.0f, 30.0f));
	choice[0].setPosition(sf::Vector2f(1123., 100));
	choice[0].setFillColor(sf::Color::Transparent);
	choice[0].setOutlineThickness(3);
	choice[0].setOutlineColor(sf::Color::White);

	//////////////////   circle  ///////////////////////////
	CircleShape circ2(10.0f);
	vector<CircleShape>circles;
	circ2.setOrigin(10.0f, 10.0f);
	circ2.setFillColor(Color::Cyan);
	circ2.setOutlineThickness(10.0f);
	circ2.setOutlineColor(Color::Blue);
	vector<Text>node_name;
	String name;
	Text textname(name, font, 25);
	textname.setFillColor(sf::Color::Magenta);
	textname.setPosition(460, 480);
	for (int i = 1; i < g.nodes.size(); i++)
	{
		circ2.setPosition(g.nodes[i].Coordinates.first, g.nodes[i].Coordinates.second);
		circles.push_back(circ2);
		textname.setString(g.nodes[i].name);
		textname.setPosition(g.nodes[i].Coordinates.first - 35, g.nodes[i].Coordinates.second - 50);
		node_name.push_back(textname);
	}
	////////////////// rectangle ///////////////////////////
	vector<RectangleShape>rectangles;
	float x, y, a, b;
	for (int i = 0; i < g.edges.size(); i++)
	{
		x = g.nodes[g.edges[i].firstNode].Coordinates.first;
		y = g.nodes[g.edges[i].firstNode].Coordinates.second;
		a = g.nodes[g.edges[i].secondNode].Coordinates.first;
		b = g.nodes[g.edges[i].secondNode].Coordinates.second;
		float distance = sqrt((b - y)*(b - y) + (a - x)*(a - x));
		float angle;
		float px, py;
		px = a - x;
		py = b - y;
		angle = atan2(py, px) * 180 / PI;

		RectangleShape rec(Vector2f(200.0f, 5.0f));
		rec.setOrigin(0.0f, 2.5f);
		rec.setFillColor(Color::Cyan);
		rec.setPosition(x, y);
		rec.setRotation(angle);
		cout << rec.getRotation() << endl;
		rec.setSize(Vector2f(distance, 5.0f));
		rectangles.push_back(rec);
	}

	Event evnt;
	sf::Vector2i local_position = sf::Mouse::getPosition(window);
	while (window.waitEvent(evnt))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			sf::Vector2i local_position = sf::Mouse::getPosition(window);
			if (local_position.x >= 1120 && local_position.x <= 1196 && local_position.y >= 96 && local_position.y <= 130)
			{
				cout << "Back" << endl;
				if (type == 'a')
					position = 18;
				else if (type == 'd')
					position = 17;
				else
					position = 19;
				break;
			}
		}
		window.clear();
		window.draw(photo);
		window.draw(text[0]);
		window.draw(choice[0]);
		for (int i = 0; i < circles.size(); i++)
		{
			window.draw(circles[i]);
		}
		for (int i = 0; i < rectangles.size(); i++)
		{
			window.draw(rectangles[i]);
		}
		for (int i = 0; i < node_name.size(); i++)
		{
			window.draw(node_name[i]);
		}
		window.display();
	}
}

void display_route()
{
	text[0].setFont(font);
	text[0].setString(" BACK ");
	text[0].setCharacterSize(20);
	text[0].setFillColor(sf::Color::White);
	text[0].setPosition(1130, 103);
	text[0].setStyle(sf::Text::Bold);

	choice[0].setSize(sf::Vector2f(70.0f, 30.0f));
	choice[0].setPosition(sf::Vector2f(1123., 100));
	choice[0].setFillColor(sf::Color::Transparent);
	choice[0].setOutlineThickness(3);
	choice[0].setOutlineColor(sf::Color::White);

	for (int i = 0; i < g.nodes.size(); i++)
	{
		g.nodes[i].is_in_route = false;
	}
	for (int i = 0; i < g.child.size(); i++)
	{
		g.nodes[g.getIdx[g.child[i]]].is_in_route = true;
	}
	Font font;

	font.loadFromFile("Roboto-MediumItalic.ttf");
	//////////////////   circle  ///////////////////////////
	CircleShape circ2(10.0f);
	vector<CircleShape>circles;
	circ2.setOrigin(10.0f, 10.0f);
	circ2.setFillColor(Color::Cyan);
	circ2.setOutlineThickness(10.0f);
	circ2.setOutlineColor(Color::Cyan);
	vector<Text>node_name;
	String name;
	Text textname(name, font, 25);
	textname.setFillColor(sf::Color::Magenta);
	textname.setPosition(460, 480);
	for (int i = 1; i < g.nodes.size(); i++)
	{
		circ2.setPosition(g.nodes[i].Coordinates.first, g.nodes[i].Coordinates.second);
		circles.push_back(circ2);
		if (g.nodes[i].is_in_route == true)
			circles[circles.size() - 1].setFillColor(Color::Blue);
		textname.setString(g.nodes[i].name);
		textname.setPosition(g.nodes[i].Coordinates.first - 30, g.nodes[i].Coordinates.second - 50);
		node_name.push_back(textname);
	}

	////////////////// rectangle ///////////////////////////

	vector<RectangleShape>rectangles;
	float x, y, a, b;
	for (int i = 0; i < g.edges.size(); i++)
	{
		x = g.nodes[g.edges[i].firstNode].Coordinates.first;
		y = g.nodes[g.edges[i].firstNode].Coordinates.second;
		a = g.nodes[g.edges[i].secondNode].Coordinates.first;
		b = g.nodes[g.edges[i].secondNode].Coordinates.second;
		float distance = sqrt((b - y)*(b - y) + (a - x)*(a - x));
		float angle;
		float px, py;
		px = a - x;
		py = b - y;
		angle = atan2(py, px) * 180 / PI;

		RectangleShape rec(Vector2f(200.0f, 5.0f));
		rec.setOrigin(0.0f, 2.5f);
		rec.setFillColor(Color::Cyan);
		rec.setPosition(x, y);
		rec.setRotation(angle);
		cout << rec.getRotation() << endl;
		rec.setSize(Vector2f(distance, 5.0f));
		rectangles.push_back(rec);
		if (g.nodes[g.edges[i].firstNode].is_in_route && g.nodes[g.edges[i].secondNode].is_in_route)
		{
			rectangles[rectangles.size() - 1].setFillColor(Color::Blue);
		}
	}

	Event evnt;
	while (window.waitEvent(evnt))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			sf::Vector2i local_position = sf::Mouse::getPosition(window);
			if (local_position.x >= 1120 && local_position.x <= 1196 && local_position.y >= 96 && local_position.y <= 130)
			{
				cout << "Back" << endl;
				position = 25;
				break;
			}
		}
		window.clear();
		window.draw(photo);
		window.draw(text[0]);
		window.draw(choice[0]);
		for (int i = 0; i < circles.size(); i++)
		{
			window.draw(circles[i]);
		}
		for (int i = 0; i < rectangles.size(); i++)
		{
			window.draw(rectangles[i]);
		}
		for (int i = 0; i < circles.size(); i++)
		{
			if (circles[i].getFillColor() == Color::Blue)
				window.draw(circles[i]);
		}
		for (int i = 0; i < rectangles.size(); i++)
		{
			if (rectangles[i].getFillColor() == Color::Blue)
				window.draw(rectangles[i]);
		}
		for (int i = 0; i < node_name.size(); i++)
		{
			window.draw(node_name[i]);
		}
		window.display();
	}
}

void deletenode() {

	text[0].setFont(font);
	text[0].setString("DO YOU WANT TO DELETE THIS NODE  ?? ");
	text[0].setCharacterSize(40);
	text[0].setFillColor(sf::Color::White);
	text[0].setPosition(270, 400);
	text[0].setStyle(sf::Text::Bold);

	text[1].setFont(font);
	text[1].setString("  YES ");
	text[1].setCharacterSize(50);
	text[1].setFillColor(sf::Color::White);
	text[1].setPosition(350, 570);
	text[1].setStyle(sf::Text::Bold);

	text[1].setFont(font);
	text[2].setString(" NO ");
	text[2].setCharacterSize(50);
	text[2].setFillColor(sf::Color::White);
	text[2].setPosition(755, 570);
	text[2].setStyle(sf::Text::Bold);

	text[3].setFont(font);
	text[3].setString(" NAME           : ");
	text[3].setCharacterSize(40);
	text[3].setFillColor(sf::Color::White);
	text[3].setPosition(220, 220);
	text[3].setStyle(sf::Text::Bold);

	text[4].setFont(font);
	text[4].setString(" Please, Fill the spaces. ");
	text[4].setCharacterSize(35);
	text[4].setFillColor(sf::Color::White);
	text[4].setPosition(390, 300);
	text[4].setStyle(sf::Text::Bold);

	text[5].setFont(font);
	text[5].setString("   INVALID NODE NAME ");
	text[5].setCharacterSize(35);
	text[5].setFillColor(sf::Color::White);
	text[5].setPosition(390, 300);
	text[5].setStyle(sf::Text::Bold);

	choice[0].setSize(sf::Vector2f(200.0f, 85.0f));
	choice[0].setPosition(sf::Vector2f(320, 560));
	choice[0].setFillColor(sf::Color::Transparent);
	choice[0].setOutlineThickness(3);
	choice[0].setOutlineColor(sf::Color::White);

	choice[1].setSize(sf::Vector2f(200.0f, 85.0f));
	choice[1].setPosition(sf::Vector2f(700, 560));
	choice[1].setFillColor(sf::Color::Transparent);
	choice[1].setOutlineThickness(3);
	choice[1].setOutlineColor(sf::Color::White);

	choice[2].setSize(sf::Vector2f(280.0f, 60.0f));
	choice[2].setPosition(sf::Vector2f(450, 210));
	choice[2].setFillColor(sf::Color::White);
	choice[2].setOutlineColor(sf::Color::Black);
	choice[2].setOutlineThickness(7);

	sf::String name;
	sf::Text tname(name, font, 40);
	tname.setFillColor(sf::Color::Black);
	tname.setPosition(460, 213);

	bool e = false, n = false;

	window.clear();
	window.draw(photo);
	for (int i = 0; i <= 3; i++) {
		if (i < 3)
			window.draw(choice[i]);
		window.draw(text[i]);
	}
	window.display();

	sf::Event event;
	while (window.waitEvent(event))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			sf::Vector2i local_position = sf::Mouse::getPosition(window);
			if (local_position.x >= 450 && local_position.x <= 729 && local_position.y >= 208 && local_position.y <= 267)
			{
				cout << "name" << endl;
				active = 1;
			}
			else if (local_position.x >= 317 && local_position.x <= 522 && local_position.y >= 556 && local_position.y <= 646)
			{
				if (name.getSize() > 0) {
					transform(name.begin(), name.end(), name.begin(), ::tolower);
					if (g.getIdx[name]) {
						g.delete_node(name);
						position = 18;
						break;
					}
					else
					{
						n = false;
						e = true;
					}
				}
				else
				{
					e = false;
					n = true;
				}
			}
			else if (local_position.x >= 697 && local_position.x <= 903 && local_position.y >= 556 && local_position.y <= 646)
			{
				position = 18;
				break;
			}
		}
		if (event.type == sf::Event::TextEntered) {

			if (active == 1 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
				name += event.text.unicode;
				tname.setString(name);
			}
			else if (active == 1 && event.text.unicode == 8 && name.getSize() > 0)
			{
				name.erase(name.getSize() - 1, name.getSize());
				tname.setString(name);
			}
		}
		window.clear();
		window.draw(photo);
		for (int i = 0; i <= 3; i++) {
			if (i < 3)
				window.draw(choice[i]);
			window.draw(text[i]);
		}
		if (n)
			window.draw(text[4]);
		if (e)
			window.draw(text[5]);
		window.draw(tname);
		window.display();
	}
}


void customerpage() {

	text[0].setFont(font);
	text[0].setString(" Order Trip ");
	text[0].setCharacterSize(40);
	text[0].setFillColor(sf::Color::Cyan);
	text[0].setPosition(490, 360);
	text[0].setStyle(sf::Text::Bold);

	text[1].setFont(font);
	text[1].setString("  View Map ");
	text[1].setCharacterSize(40);
	text[1].setFillColor(sf::Color::Cyan);
	text[1].setPosition(490, 580);
	text[1].setStyle(sf::Text::Bold);

	text[2].setFont(font);
	text[2].setString(" Log-out ");
	text[2].setCharacterSize(25);
	text[2].setFillColor(sf::Color::Cyan);
	text[2].setPosition(1047, 56);
	text[2].setStyle(sf::Text::Bold);

	choice[2].setSize(sf::Vector2f(250.0f, 80.0f));
	choice[2].setPosition(sf::Vector2f(480, 346));
	choice[2].setFillColor(sf::Color::Transparent);
	choice[2].setOutlineThickness(3);
	choice[2].setOutlineColor(sf::Color::Cyan);

	choice[0].setSize(sf::Vector2f(250.0f, 80.0f));
	choice[0].setPosition(sf::Vector2f(480, 562));
	choice[0].setFillColor(sf::Color::Transparent);
	choice[0].setOutlineThickness(3);
	choice[0].setOutlineColor(sf::Color::Cyan);

	choice[1].setSize(sf::Vector2f(120.0f, 68.0f));
	choice[1].setPosition(sf::Vector2f(1040, 40));
	choice[1].setFillColor(sf::Color::Transparent);
	choice[1].setOutlineThickness(3);
	choice[1].setOutlineColor(sf::Color::Cyan);

	window.clear();
	window.draw(photo);
	for (int i = 0; i < 3; i++)
	{
		window.draw(choice[i]);
		window.draw(text[i]);
	}
	window.display();

	sf::Event event;
	while (window.waitEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			sf::Vector2i local_position = sf::Mouse::getPosition(window);
			if (local_position.x >= 477 && local_position.x <= 732 && local_position.y >= 343 && local_position.y <= 427)
			{

				cout << "order trip" << endl;
				position = 40;
				break;

			}
			else if (local_position.x >= 477 && local_position.x <= 732 && local_position.y >= 559 && local_position.y <= 642)
			{

				cout << "view map" << endl;
				position = 20;
				break;
			}
			else if (local_position.x >= 1036 && local_position.x <= 1160 && local_position.y >= 37 && local_position.y <= 106)
			{
				position = 1;
				break;
			}
		}
	}
}

void viewdriverdata(int h) {

	text[0].setFont(font);
	text[0].setString(" Back ");
	text[0].setCharacterSize(40);
	text[0].setFillColor(sf::Color::White);
	text[0].setPosition(1050, 50);
	text[0].setStyle(sf::Text::Bold);

	text[19].setFont(font);
	text[19].setString(" RATE  ");
	text[19].setCharacterSize(35);
	text[19].setFillColor(sf::Color::White);
	text[19].setPosition(1025, 710);
	text[19].setStyle(sf::Text::Bold);

	text[1].setFont(font);
	text[1].setString("ID                     : ");
	text[1].setCharacterSize(40);
	text[1].setFillColor(sf::Color::White);
	text[1].setPosition(150, 120);
	text[1].setStyle(sf::Text::Bold);

	text[2].setFont(font);
	text[2].setString("Name                : ");
	text[2].setCharacterSize(40);
	text[2].setFillColor(sf::Color::White);
	text[2].setPosition(150, 190);
	text[2].setStyle(sf::Text::Bold);

	text[3].setFont(font);
	text[3].setString("Phone Number   :");
	text[3].setCharacterSize(40);
	text[3].setFillColor(sf::Color::White);
	text[3].setPosition(150, 260);
	text[3].setStyle(sf::Text::Bold);

	text[4].setFont(font);
	text[4].setString("Car Name          :");
	text[4].setCharacterSize(40);
	text[4].setFillColor(sf::Color::White);
	text[4].setPosition(150, 330);
	text[4].setStyle(sf::Text::Bold);

	text[5].setFont(font);
	text[5].setString("Car Model         : ");
	text[5].setCharacterSize(40);
	text[5].setFillColor(sf::Color::White);
	text[5].setPosition(150, 400);
	text[5].setStyle(sf::Text::Bold);

	text[6].setFont(font);
	text[6].setString("Color                 : ");
	text[6].setCharacterSize(40);
	text[6].setFillColor(sf::Color::White);
	text[6].setPosition(150, 470);
	text[6].setStyle(sf::Text::Bold);

	text[7].setFont(font);
	text[7].setString("Car Number       : ");
	text[7].setCharacterSize(40);
	text[7].setFillColor(sf::Color::White);
	text[7].setPosition(150, 540);
	text[7].setStyle(sf::Text::Bold);

	text[8].setFont(font);
	text[8].setString("Location            : ");
	text[8].setCharacterSize(40);
	text[8].setFillColor(sf::Color::White);
	text[8].setPosition(150, 610);
	text[8].setStyle(sf::Text::Bold);

	text[18].setFont(font);
	text[18].setString("Rate                : ");
	text[18].setCharacterSize(40);
	text[18].setFillColor(sf::Color::White);
	text[18].setPosition(150, 680);
	text[18].setStyle(sf::Text::Bold);

	int k = g.D[h].ID + 1;
	stringstream ss;
	ss << k;
	string s;
	ss >> s;

	int r = static_cast<int>(g.D[h].rate);
	stringstream sss;
	sss << r;
	string w;
	sss >> w;

	text[9].setString(s);
	text[9].setFillColor(sf::Color::Magenta);

	text[10].setString(g.D[h].name);
	text[10].setFillColor(sf::Color::Magenta);

	text[11].setString(g.D[h].phone_num);
	text[11].setFillColor(sf::Color::Magenta);

	text[12].setString(g.D[h].car_name);
	text[12].setFillColor(sf::Color::Magenta);

	text[13].setString(g.D[h].car_model);
	text[13].setFillColor(sf::Color::Magenta);

	text[14].setString(g.D[h].color);
	text[14].setFillColor(sf::Color::Magenta);

	text[15].setString(g.D[h].car_num);
	text[15].setFillColor(sf::Color::Magenta);

	text[16].setString(g.D[h].location);
	text[16].setFillColor(sf::Color::Magenta);

	text[17].setString(w);
	text[17].setFillColor(sf::Color::Magenta);

	choice[0].setSize(sf::Vector2f(120.0f, 65.0f));
	choice[0].setPosition(sf::Vector2f(1040, 40));
	choice[0].setFillColor(sf::Color::Transparent);
	choice[0].setOutlineThickness(3);
	choice[0].setOutlineColor(sf::Color::White);


	choice[1].setSize(sf::Vector2f(150.0f, 60.0f));
	choice[1].setPosition(sf::Vector2f(1000., 700));
	choice[1].setFillColor(sf::Color::Transparent);
	choice[1].setOutlineThickness(3);
	choice[1].setOutlineColor(sf::Color::White);

	float l = 120;
	for (int i = 9; i <= 17; i++) {

		text[i].setPosition(500, l);
		l += 70;
	}
	window.clear();
	window.draw(photo);
	for (int i = 0; i <= 19; i++) {
		window.draw(text[i]);
	}
	window.draw(choice[0]);
	window.draw(choice[1]);
	window.display();

	sf::Event event;
	while (window.waitEvent(event))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			sf::Vector2i local_position = sf::Mouse::getPosition(window);
			if (local_position.x >= 1036 && local_position.x <= 1160 && local_position.y >= 37 && local_position.y <= 106)
			{
				cout << "back" << endl;
				position = 25;
				break;
			}
			else if (local_position.x >= 997 && local_position.x <= 1152 && local_position.y >= 695 && local_position.y <= 761)
			{
				cout << "rate" << endl;
				position = 27;
				break;
			}

		}

	}
}

void ratedriver() {

	choice[0].setSize(sf::Vector2f(120.0f, 65.0f));
	choice[0].setPosition(sf::Vector2f(1040, 40));
	choice[0].setFillColor(sf::Color::Transparent);
	choice[0].setOutlineThickness(3);
	choice[0].setOutlineColor(sf::Color::White);

	choice[1].setSize(sf::Vector2f(150.0f, 60.0f));
	choice[1].setPosition(sf::Vector2f(1000., 650));
	choice[1].setFillColor(sf::Color::Transparent);
	choice[1].setOutlineThickness(3);
	choice[1].setOutlineColor(sf::Color::White);

	text[0].setFont(font);
	text[0].setString(" Rate Your Driver : ");
	text[0].setCharacterSize(38);
	text[0].setFillColor(sf::Color::White);
	text[0].setPosition(15, 220);
	text[0].setStyle(sf::Text::Bold);

	text[6].setFont(font);
	text[6].setString("THANKS FOR BELIEVING IN US. ");
	text[6].setCharacterSize(35);
	text[6].setFillColor(sf::Color::White);
	text[6].setPosition(370, 570);
	text[6].setStyle(sf::Text::Bold);

	text[2].setFont(font);
	text[2].setString(" Back ");
	text[2].setCharacterSize(40);
	text[2].setFillColor(sf::Color::White);
	text[2].setPosition(1045, 50);
	text[2].setStyle(sf::Text::Bold);

	text[1].setFont(font);
	text[1].setString(" FINISH ");
	text[1].setCharacterSize(40);
	text[1].setFillColor(sf::Color::White);
	text[1].setPosition(1010, 658);
	text[1].setStyle(sf::Text::Bold);

	sf::ConvexShape star(11);
	star.setOutlineColor(sf::Color::Black);
	star.setFillColor(sf::Color(225, 247, 164));
	star.setPoint(0, sf::Vector2f(100, 0));
	star.setPoint(1, sf::Vector2f(77, 68));
	star.setPoint(2, sf::Vector2f(5, 69));
	star.setPoint(3, sf::Vector2f(63, 112));
	star.setPoint(4, sf::Vector2f(42, 180));
	star.setPoint(5, sf::Vector2f(100, 139));
	star.setPoint(6, sf::Vector2f(158, 180));
	star.setPoint(7, sf::Vector2f(137, 112));
	star.setPoint(8, sf::Vector2f(194, 69));
	star.setPoint(9, sf::Vector2f(123, 68));
	star.setPoint(10, sf::Vector2f(100, 0));
	star.setPosition(340, 200);
	star.setScale(0.4, 0.4);
	star.setFillColor(sf::Color(255, 255, 255));

	sf::ConvexShape star2(11);
	star2.setOutlineColor(sf::Color::Black);
	star2.setFillColor(sf::Color(225, 247, 164));
	star2.setPoint(0, sf::Vector2f(100, 0));
	star2.setPoint(1, sf::Vector2f(77, 68));
	star2.setPoint(2, sf::Vector2f(5, 69));
	star2.setPoint(3, sf::Vector2f(63, 112));
	star2.setPoint(4, sf::Vector2f(42, 180));
	star2.setPoint(5, sf::Vector2f(100, 139));
	star2.setPoint(6, sf::Vector2f(158, 180));
	star2.setPoint(7, sf::Vector2f(137, 112));
	star2.setPoint(8, sf::Vector2f(194, 69));
	star2.setPoint(9, sf::Vector2f(123, 68));
	star2.setPoint(10, sf::Vector2f(100, 0));
	star2.setPosition(430, 200);
	star2.setScale(0.4, 0.4);
	star2.setFillColor(sf::Color(255, 255, 255));

	sf::ConvexShape star3(11);
	star3.setOutlineColor(sf::Color::Black);
	star3.setFillColor(sf::Color(225, 247, 164));
	star3.setPoint(0, sf::Vector2f(100, 0));
	star3.setPoint(1, sf::Vector2f(77, 68));
	star3.setPoint(2, sf::Vector2f(5, 69));
	star3.setPoint(3, sf::Vector2f(63, 112));
	star3.setPoint(4, sf::Vector2f(42, 180));
	star3.setPoint(5, sf::Vector2f(100, 139));
	star3.setPoint(6, sf::Vector2f(158, 180));
	star3.setPoint(7, sf::Vector2f(137, 112));
	star3.setPoint(8, sf::Vector2f(194, 69));
	star3.setPoint(9, sf::Vector2f(123, 68));
	star3.setPoint(10, sf::Vector2f(100, 0));
	star3.setPosition(520, 200);
	star3.setScale(0.4, 0.4);
	star3.setFillColor(sf::Color(255, 255, 255));

	sf::ConvexShape star4(11);
	star4.setOutlineColor(sf::Color::Black);
	star4.setFillColor(sf::Color(225, 247, 164));
	star4.setPoint(0, sf::Vector2f(100, 0));
	star4.setPoint(1, sf::Vector2f(77, 68));
	star4.setPoint(2, sf::Vector2f(5, 69));
	star4.setPoint(3, sf::Vector2f(63, 112));
	star4.setPoint(4, sf::Vector2f(42, 180));
	star4.setPoint(5, sf::Vector2f(100, 139));
	star4.setPoint(6, sf::Vector2f(158, 180));
	star4.setPoint(7, sf::Vector2f(137, 112));
	star4.setPoint(8, sf::Vector2f(194, 69));
	star4.setPoint(9, sf::Vector2f(123, 68));
	star4.setPoint(10, sf::Vector2f(100, 0));
	star4.setPosition(610, 200);
	star4.setScale(0.4, 0.4);
	star4.setFillColor(sf::Color(255, 255, 255));

	sf::ConvexShape star5(11);
	star5.setOutlineColor(sf::Color::Black);
	star5.setFillColor(sf::Color(225, 247, 164));
	star5.setPoint(0, sf::Vector2f(100, 0));
	star5.setPoint(1, sf::Vector2f(77, 68));
	star5.setPoint(2, sf::Vector2f(5, 69));
	star5.setPoint(3, sf::Vector2f(63, 112));
	star5.setPoint(4, sf::Vector2f(42, 180));
	star5.setPoint(5, sf::Vector2f(100, 139));
	star5.setPoint(6, sf::Vector2f(158, 180));
	star5.setPoint(7, sf::Vector2f(137, 112));
	star5.setPoint(8, sf::Vector2f(194, 69));
	star5.setPoint(9, sf::Vector2f(123, 68));
	star5.setPoint(10, sf::Vector2f(100, 0));
	star5.setPosition(700, 200);
	star5.setScale(0.4, 0.4);
	star5.setFillColor(sf::Color(255, 255, 255));

	int active = 0, rating = 0;

	window.draw(photo);
	for (int i = 0; i < 3; i++) {
		window.draw(text[i]);
		if (i < 2)
			window.draw(choice[i]);
	}
	window.draw(star);
	window.draw(star2);
	window.draw(star3);
	window.draw(star4);
	window.draw(star5);
	window.display();

	sf::Event event;
	while (window.waitEvent(event))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

			sf::Vector2i local_position = sf::Mouse::getPosition(window);
			if (local_position.x >= 997 && local_position.x <= 1152 && local_position.y >= 645 && local_position.y <= 710)
			{
				cout << "finsh" << endl;
				g.rate(drive, rating);
				assigned_customer[drive].first = who_open;
				assigned_customer[drive].second = g.child;
				g.child.clear();
				position = 19;
				break;
			}
			else if (local_position.x >= 1036 && local_position.x <= 1160 && local_position.y >= 37 && local_position.y <= 106)
			{
				cout << "back" << endl;
				position = 25;
				break;
			}
			else if (local_position.x >= 356 && local_position.x <= 402 && local_position.y >= 201 && local_position.y <= 270) {
				active = 1;
				cout << "star 1" << endl;
				rating = 1;
			}
			else if (local_position.x >= 447 && local_position.x <= 490 && local_position.y >= 201 && local_position.y <= 270) {
				active = 2;
				cout << "star 2" << endl;
				rating = 2;
			}
			else if (local_position.x >= 538 && local_position.x <= 582 && local_position.y >= 201 && local_position.y <= 270) {
				active = 3;
				cout << "star 3" << endl;
				rating = 3;
			}
			else if (local_position.x >= 625 && local_position.x <= 672 && local_position.y >= 201 && local_position.y <= 270) {
				active = 4;
				cout << "star 4" << endl;
				rating = 4;
			}
			else if (local_position.x >= 716 && local_position.x <= 763 && local_position.y >= 201 && local_position.y <= 270) {
				active = 5;
				cout << "star 5" << endl;
				rating = 5;
			}

			if (active == 1)
			{
				star.setFillColor(sf::Color(255, 255, 0));
				star2.setFillColor(sf::Color(255, 255, 255));
				star3.setFillColor(sf::Color(255, 255, 255));
				star4.setFillColor(sf::Color(255, 255, 255));
				star5.setFillColor(sf::Color(255, 255, 255));
			}
			else if (active == 2)
			{
				star.setFillColor(sf::Color(255, 255, 0));
				star2.setFillColor(sf::Color(255, 255, 0));
				star3.setFillColor(sf::Color(255, 255, 255));
				star4.setFillColor(sf::Color(255, 255, 255));
				star5.setFillColor(sf::Color(255, 255, 255));
			}
			else if (active == 3)
			{
				star.setFillColor(sf::Color(255, 255, 0));
				star2.setFillColor(sf::Color(255, 255, 0));
				star3.setFillColor(sf::Color(255, 255, 0));
				star4.setFillColor(sf::Color(255, 255, 255));
				star5.setFillColor(sf::Color(255, 255, 255));
			}
			else if (active == 4)
			{
				star.setFillColor(sf::Color(255, 255, 0));
				star2.setFillColor(sf::Color(255, 255, 0));
				star3.setFillColor(sf::Color(255, 255, 0));
				star4.setFillColor(sf::Color(255, 255, 0));
				star5.setFillColor(sf::Color(255, 255, 255));
			}
			else if (active == 5)
			{
				star.setFillColor(sf::Color(255, 255, 0));
				star2.setFillColor(sf::Color(255, 255, 0));
				star3.setFillColor(sf::Color(255, 255, 0));
				star4.setFillColor(sf::Color(255, 255, 0));
				star5.setFillColor(sf::Color(255, 255, 0));
			}

			window.draw(photo);
			for (int i = 0; i < 3; i++) {
				window.draw(text[i]);

				window.draw(choice[i]);
			}
			window.draw(choice[0]);
			window.draw(choice[1]);
			window.draw(star);
			window.draw(star2);
			window.draw(star3);
			window.draw(star4);
			window.draw(star5);
			window.display();
		}
	}

}

void estimation(int t, string tran) {

	text[0].setFont(font);
	if (tran == "Uber")
		text[0].setString(" View driver");
	else
	{
		text[0].setString("  Finish ");
	}
	text[0].setCharacterSize(37);
	text[0].setFillColor(sf::Color::White);
	if (tran == "Uber")
		text[0].setPosition(595, 605);
	else
	{
		text[0].setPosition(620, 605);
	}

	text[0].setStyle(sf::Text::Bold);

	text[2].setFont(font);
	text[2].setString("Estimated price       : ");
	text[2].setCharacterSize(40);
	text[2].setFillColor(sf::Color::White);
	text[2].setPosition(150, 190);
	text[2].setStyle(sf::Text::Bold);

	text[1].setFont(font);
	text[1].setString(" Estimated Time       :");
	text[1].setCharacterSize(40);
	text[1].setFillColor(sf::Color::White);
	text[1].setPosition(150, 300);
	text[1].setStyle(sf::Text::Bold);

	text[3].setFont(font);
	text[3].setString(" Estimated Distance :");
	text[3].setCharacterSize(40);
	text[3].setFillColor(sf::Color::White);
	text[3].setPosition(150, 410);
	text[3].setStyle(sf::Text::Bold);

	text[10].setFont(font);
	text[10].setString("View Route ");
	text[10].setCharacterSize(40);
	text[10].setFillColor(sf::Color::White);
	text[10].setPosition(300, 605);
	text[10].setStyle(sf::Text::Bold);

	text[9].setFont(font);
	text[9].setString("$. ");
	text[9].setCharacterSize(30);
	text[9].setFillColor(sf::Color::Magenta);
	text[9].setPosition(700, 195);
	text[9].setStyle(sf::Text::Bold);

	text[7].setFont(font);
	text[7].setString("MIN.");
	text[7].setCharacterSize(30);
	text[7].setFillColor(sf::Color::Magenta);
	text[7].setPosition(700, 305);
	text[7].setStyle(sf::Text::Bold);

	text[8].setFont(font);
	text[8].setString("M.");
	text[8].setCharacterSize(30);
	text[8].setFillColor(sf::Color::Magenta);
	text[8].setPosition(700, 415);
	text[8].setStyle(sf::Text::Bold);

	choice[0].setSize(sf::Vector2f(200.0f, 60.0f));
	choice[0].setPosition(sf::Vector2f(300, 600));
	choice[0].setFillColor(sf::Color::Transparent);
	choice[0].setOutlineThickness(3);
	choice[0].setOutlineColor(sf::Color::White);

	choice[1].setSize(sf::Vector2f(200.0f, 60.0f));
	choice[1].setPosition(sf::Vector2f(600, 600));
	choice[1].setFillColor(sf::Color::Transparent);
	choice[1].setOutlineThickness(3);
	choice[1].setOutlineColor(sf::Color::White);


	sf::Event event;
	while (window.waitEvent(event))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			sf::Vector2i local_position = sf::Mouse::getPosition(window);
			if (local_position.x >= 296 && local_position.x <= 503 && local_position.y >= 596 && local_position.y <= 660)
			{
				cout << "view route" << endl;
				position = 50;
				break;
			}
			else if (local_position.x >= 596 && local_position.x <= 801 && local_position.y >= 596 && local_position.y <= 660)
			{
				if (tran == "Uber") {
					cout << "view driver data" << endl;
					position = 26;
					break;
				}
				else
				{
					cout << "finish" << endl;
					g.child.clear();
					position = 19;
					break;
				}
			}
		}

		float y = 195;
		int ty[8];
		if (tran == "Uber") {
			ty[4] = 6;
			ty[5] = 4;
			ty[6] = 1;
		}
		else if (tran == "Bus") {
			ty[4] = 3;
			ty[5] = 2;
			ty[6] = 1;
		}
		else {
			ty[4] = 2;
			ty[5] = 1;
			ty[6] = 1;
		}
		for (int i = 4; i < 7; i++) {

			int k = t * ty[i];
			stringstream ss;
			ss << k;
			string s;
			ss >> s;

			text[i].setString(s);
			text[i].setFillColor(sf::Color::Magenta);
			text[i].setPosition(570, y);
			y += 110;
		}

		window.clear();
		window.draw(photo);

		for (int i = 0; i <= 10; i++) {
			window.draw(text[i]);
		}
		window.draw(choice[0]);
		window.draw(choice[1]);
		window.display();
	}
}

void ordertrip() {

	text[0].setFont(font);
	text[0].setString(" Back ");
	text[0].setCharacterSize(40);
	text[0].setFillColor(sf::Color::White);
	text[0].setPosition(1050, 50);
	text[0].setStyle(sf::Text::Bold);

	text[1].setFont(font);
	text[1].setString("ENTER YOUR LOCATION    : ");
	text[1].setCharacterSize(40);
	text[1].setFillColor(sf::Color::White);
	text[1].setPosition(10, 40);
	text[1].setStyle(sf::Text::Bold);

	text[2].setFont(font);
	text[2].setString("ENTER YOUR DESTINATION: ");
	text[2].setCharacterSize(40);
	text[2].setFillColor(sf::Color::White);
	text[2].setPosition(10, 200);
	text[2].setStyle(sf::Text::Bold);

	text[4].setFont(font);
	text[4].setString(" CHOOSE TRANSPORTAION METHOUD  ");
	text[4].setCharacterSize(40);
	text[4].setFillColor(sf::Color::White);
	text[4].setPosition(300, 330);
	text[4].setStyle(sf::Text::Bold);

	text[6].setFont(font);
	text[6].setString(" Uber Car ");
	text[6].setCharacterSize(35);
	text[6].setFillColor(sf::Color::White);
	text[6].setPosition(170, 470);
	text[6].setStyle(sf::Text::Bold);

	text[7].setFont(font);
	text[7].setString(" Uber Bus ");
	text[7].setCharacterSize(35);
	text[7].setFillColor(sf::Color::White);
	text[7].setPosition(470, 470);
	text[7].setStyle(sf::Text::Bold);

	text[8].setFont(font);
	text[8].setString(" Uber Metro ");
	text[8].setCharacterSize(35);
	text[8].setFillColor(sf::Color::White);
	text[8].setPosition(750, 470);
	text[8].setStyle(sf::Text::Bold);

	text[5].setFont(font);
	text[5].setString("  ORDER ");
	text[5].setCharacterSize(40);
	text[5].setFillColor(sf::Color::White);
	text[5].setPosition(1000, 655);
	text[5].setStyle(sf::Text::Bold);

	text[3].setFont(font);
	text[3].setString(" Please, Fill the spaces. ");
	text[3].setCharacterSize(35);
	text[3].setFillColor(sf::Color::White);
	text[3].setPosition(370, 570);
	text[3].setStyle(sf::Text::Bold);

	text[10].setFont(font);
	text[10].setString("This Node Is Not Represented On Graph. ");
	text[10].setCharacterSize(35);
	text[10].setFillColor(sf::Color::White);
	text[10].setPosition(260, 570);
	text[10].setStyle(sf::Text::Bold);

	text[12].setFont(font);
	text[12].setString("Sorry, there is no driver available at this area. ");
	text[12].setCharacterSize(35);
	text[12].setFillColor(sf::Color::White);
	text[12].setPosition(220, 570);
	text[12].setStyle(sf::Text::Bold);

	text[11].setFont(font);
	text[11].setString("Your destination is not reachable using this method. ");
	text[11].setCharacterSize(35);
	text[11].setFillColor(sf::Color::White);
	text[11].setPosition(200, 570);
	text[11].setStyle(sf::Text::Bold);


	choice[0].setSize(sf::Vector2f(120.0f, 65.0f));
	choice[0].setPosition(sf::Vector2f(1040, 40));
	choice[0].setFillColor(sf::Color::Transparent);
	choice[0].setOutlineThickness(3);
	choice[0].setOutlineColor(sf::Color::White);

	choice[3].setSize(sf::Vector2f(280.0f, 50.0f));
	choice[3].setPosition(sf::Vector2f(450, 40));
	choice[3].setFillColor(sf::Color::White);
	choice[3].setOutlineColor(sf::Color::Black);
	choice[3].setOutlineThickness(7);

	choice[1].setSize(sf::Vector2f(280.0f, 50.0f));
	choice[1].setPosition(sf::Vector2f(450, 200));
	choice[1].setFillColor(sf::Color::White);
	choice[1].setOutlineColor(sf::Color::Black);
	choice[1].setOutlineThickness(7);

	choice[5].setSize(sf::Vector2f(200.0f, 80.0f));
	choice[5].setPosition(sf::Vector2f(150, 450));
	choice[5].setFillColor(sf::Color::Transparent);
	choice[5].setOutlineColor(sf::Color::White);
	choice[5].setOutlineThickness(3);

	choice[6].setSize(sf::Vector2f(200.0f, 80.0f));
	choice[6].setPosition(sf::Vector2f(450, 450));
	choice[6].setFillColor(sf::Color::Transparent);
	choice[6].setOutlineColor(sf::Color::White);
	choice[6].setOutlineThickness(3);

	choice[4].setSize(sf::Vector2f(200.0f, 80.0f));
	choice[4].setPosition(sf::Vector2f(750, 450));
	choice[4].setFillColor(sf::Color::Transparent);
	choice[4].setOutlineColor(sf::Color::White);
	choice[4].setOutlineThickness(3);

	choice[2].setSize(sf::Vector2f(150.0f, 60.0f));
	choice[2].setPosition(sf::Vector2f(1000., 650));
	choice[2].setFillColor(sf::Color::Transparent);
	choice[2].setOutlineThickness(3);
	choice[2].setOutlineColor(sf::Color::White);

	sf::String namef;
	sf::Text tnamef(namef, font, 40);
	tnamef.setFillColor(sf::Color::Black);
	tnamef.setPosition(460, 40);

	sf::String names;
	sf::Text tnames(names, font, 40);
	tnames.setFillColor(sf::Color::Black);
	tnames.setPosition(460, 200);


	window.draw(photo);
	for (int i = 0; i <= 8; i++) {
		if (i != 3)
			window.draw(text[i]);
		if (i < 7)
			window.draw(choice[i]);

	}

	window.display();

	string t = "n";

	bool spaces = false, no_nodes = false, reached = false, d_found = false;
	sf::Event event;
	while (window.waitEvent(event))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			sf::Vector2i local_position = sf::Mouse::getPosition(window);
			if (local_position.x >= 448 && local_position.x <= 730 && local_position.y >= 36 && local_position.y <= 92)
			{
				cout << "locatin" << endl;
				active = 1;
			}
			else if (local_position.x >= 448 && local_position.x <= 732 && local_position.y >= 196 && local_position.y <= 253)
			{
				cout << "destination" << endl;
				active = 2;
			}
			else if (local_position.x >= 146 && local_position.x <= 351 && local_position.y >= 447 && local_position.y <= 530)
			{
				cout << "CAR" << endl;
				choice[5].setOutlineColor(sf::Color::Magenta);  text[6].setFillColor(sf::Color::Magenta);
				choice[6].setOutlineColor(sf::Color::White);    text[7].setFillColor(sf::Color::White);
				choice[4].setOutlineColor(sf::Color::White);    text[8].setFillColor(sf::Color::White);
				t = "Uber";
				active = 5;
			}
			else if (local_position.x >= 447 && local_position.x <= 653 && local_position.y >= 447 && local_position.y <= 530)
			{
				cout << "BUS" << endl;
				choice[5].setOutlineColor(sf::Color::White);  text[6].setFillColor(sf::Color::White);
				choice[6].setOutlineColor(sf::Color::Magenta);    text[7].setFillColor(sf::Color::Magenta);
				choice[4].setOutlineColor(sf::Color::White);    text[8].setFillColor(sf::Color::White);
				t = "Bus";
				active = 5;
			}
			else if (local_position.x >= 746 && local_position.x <= 951 && local_position.y >= 447 && local_position.y <= 530)
			{
				cout << "METRO" << endl;
				choice[5].setOutlineColor(sf::Color::White);  text[6].setFillColor(sf::Color::White);
				choice[6].setOutlineColor(sf::Color::White);    text[7].setFillColor(sf::Color::White);
				choice[4].setOutlineColor(sf::Color::Magenta);    text[8].setFillColor(sf::Color::Magenta);
				t = "Metro";
				active = 5;
			}
			else if (local_position.x >= 996 && local_position.x <= 1150 && local_position.y >= 645 && local_position.y <= 709)
			{
				if (names.getSize() > 0 && namef.getSize() > 0 && t != 'n') {
					if (g.getIdx[names] && g.getIdx[namef]) {
						int x = g.Dijkstra(g.getIdx[namef], g.getIdx[names], t, 1);
						if (x != INT_MAX) {
							if (t == "Uber") {
								int p = g.Dijkstra(g.getIdx[namef], g.getIdx[names], t, 0);
								if (g.find_captain() != -1) {
									estimate = p;
									drive = g.find_captain();
									position = 25;
									tran = t;
									break;
								}
								else {
									g.child.clear();
									d_found = true;
									reached = false;
									no_nodes = false;
									spaces = false;
								}
							}
							else
							{
								estimate = g.Dijkstra(g.getIdx[namef], g.getIdx[names], t, 0);
								position = 25;
								tran = t;
								break;
							}
						}
						else
						{
							d_found = false;
							reached = true;
							no_nodes = false;
							spaces = false;
						}
					}
					else
					{
						d_found = false;
						reached = false;
						no_nodes = true;
						spaces = false;
					}
				}
				else
				{
					d_found = false;
					reached = false;
					no_nodes = false;
					spaces = true;
				}
			}
			else if (local_position.x >= 1036 && local_position.x <= 1160 && local_position.y >= 37 && local_position.y <= 106)
			{
				cout << "back" << endl;
				position = 40;
				break;
			}
		}
		if (event.type == sf::Event::TextEntered) {
			if (active == 1 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
				namef += event.text.unicode;
				tnamef.setString(namef);
			}
			else if (active == 1 && event.text.unicode == 8 && namef.getSize() > 0)
			{
				namef.erase(namef.getSize() - 1, namef.getSize());
				tnamef.setString(namef);
			}
			if (active == 2 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
				names += event.text.unicode;
				tnames.setString(names);
			}
			else if (active == 2 && event.text.unicode == 8 && names.getSize() > 0) {
				names.erase(names.getSize() - 1, names.getSize());
				tnames.setString(names);
			}
		}
		window.draw(photo);
		for (int i = 0; i <= 8; i++) {
			if (i != 3)
				window.draw(text[i]);
			if (i < 7)
				window.draw(choice[i]);
		}
		if (spaces)
			window.draw(text[3]);
		if (no_nodes)
			window.draw(text[10]);
		if (reached)
			window.draw(text[11]);
		if (d_found)
			window.draw(text[12]);
		window.draw(tnamef);
		window.draw(tnames);
		window.display();
	}
}

void orderservice() {

	text[0].setFont(font);
	text[0].setString(" Back ");
	text[0].setCharacterSize(40);
	text[0].setFillColor(sf::Color::White);
	text[0].setPosition(1050, 50);
	text[0].setStyle(sf::Text::Bold);

	text[1].setFont(font);
	text[1].setString("ENTER YOUR LOCATION    : ");
	text[1].setCharacterSize(40);
	text[1].setFillColor(sf::Color::White);
	text[1].setPosition(10, 40);
	text[1].setStyle(sf::Text::Bold);

	text[2].setFont(font);
	text[2].setString("ENTER SERVICE NAME     : ");
	text[2].setCharacterSize(40);
	text[2].setFillColor(sf::Color::White);
	text[2].setPosition(10, 200);
	text[2].setStyle(sf::Text::Bold);

	text[4].setFont(font);
	text[4].setString(" CHOOSE TRANSPORTAION METHOUD  ");
	text[4].setCharacterSize(40);
	text[4].setFillColor(sf::Color::White);
	text[4].setPosition(300, 330);
	text[4].setStyle(sf::Text::Bold);

	text[6].setFont(font);
	text[6].setString(" Uber Car ");
	text[6].setCharacterSize(35);
	text[6].setFillColor(sf::Color::White);
	text[6].setPosition(170, 470);
	text[6].setStyle(sf::Text::Bold);

	text[7].setFont(font);
	text[7].setString(" Uber Bus ");
	text[7].setCharacterSize(35);
	text[7].setFillColor(sf::Color::White);
	text[7].setPosition(470, 470);
	text[7].setStyle(sf::Text::Bold);

	text[8].setFont(font);
	text[8].setString(" Uber Metro ");
	text[8].setCharacterSize(35);
	text[8].setFillColor(sf::Color::White);
	text[8].setPosition(750, 470);
	text[8].setStyle(sf::Text::Bold);

	text[5].setFont(font);
	text[5].setString("  ORDER ");
	text[5].setCharacterSize(40);
	text[5].setFillColor(sf::Color::White);
	text[5].setPosition(1000, 655);
	text[5].setStyle(sf::Text::Bold);

	text[3].setFont(font);
	text[3].setString(" Please, Fill the spaces. ");
	text[3].setCharacterSize(35);
	text[3].setFillColor(sf::Color::White);
	text[3].setPosition(370, 570);
	text[3].setStyle(sf::Text::Bold);

	text[9].setFont(font);
	text[9].setString(" Please, Fill the spaces. ");
	text[9].setCharacterSize(35);
	text[9].setFillColor(sf::Color::White);
	text[9].setPosition(370, 570);
	text[9].setStyle(sf::Text::Bold);

	text[10].setFont(font);
	text[10].setString("This Node Is Not Represented On Graph. ");
	text[10].setCharacterSize(35);
	text[10].setFillColor(sf::Color::White);
	text[10].setPosition(260, 570);
	text[10].setStyle(sf::Text::Bold);

	text[12].setFont(font);
	text[12].setString("Sorry, there is no driver available at this area. ");
	text[12].setCharacterSize(35);
	text[12].setFillColor(sf::Color::White);
	text[12].setPosition(220, 570);
	text[12].setStyle(sf::Text::Bold);

	text[11].setFont(font);
	text[11].setString("Sorry, There Is No Facility With This Name. ");
	text[11].setCharacterSize(35);
	text[11].setFillColor(sf::Color::White);
	text[11].setPosition(200, 570);
	text[11].setStyle(sf::Text::Bold);

	text[13].setFont(font);
	text[13].setString("Your destination is not reachable using this method. ");
	text[13].setCharacterSize(35);
	text[13].setFillColor(sf::Color::White);
	text[13].setPosition(200, 570);
	text[13].setStyle(sf::Text::Bold);

	text[14].setFont(font);
	text[14].setString("You are at the same place. ");
	text[14].setCharacterSize(35);
	text[14].setFillColor(sf::Color::White);
	text[14].setPosition(370, 570);
	text[14].setStyle(sf::Text::Bold);

	choice[0].setSize(sf::Vector2f(120.0f, 65.0f));
	choice[0].setPosition(sf::Vector2f(1040, 40));
	choice[0].setFillColor(sf::Color::Transparent);
	choice[0].setOutlineThickness(3);
	choice[0].setOutlineColor(sf::Color::White);

	choice[3].setSize(sf::Vector2f(280.0f, 50.0f));
	choice[3].setPosition(sf::Vector2f(450, 40));
	choice[3].setFillColor(sf::Color::White);
	choice[3].setOutlineColor(sf::Color::Black);
	choice[3].setOutlineThickness(7);

	choice[1].setSize(sf::Vector2f(280.0f, 50.0f));
	choice[1].setPosition(sf::Vector2f(450, 200));
	choice[1].setFillColor(sf::Color::White);
	choice[1].setOutlineColor(sf::Color::Black);
	choice[1].setOutlineThickness(7);

	choice[5].setSize(sf::Vector2f(200.0f, 80.0f));
	choice[5].setPosition(sf::Vector2f(150, 450));
	choice[5].setFillColor(sf::Color::Transparent);
	choice[5].setOutlineColor(sf::Color::White);
	choice[5].setOutlineThickness(3);

	choice[6].setSize(sf::Vector2f(200.0f, 80.0f));
	choice[6].setPosition(sf::Vector2f(450, 450));
	choice[6].setFillColor(sf::Color::Transparent);
	choice[6].setOutlineColor(sf::Color::White);
	choice[6].setOutlineThickness(3);

	choice[4].setSize(sf::Vector2f(200.0f, 80.0f));
	choice[4].setPosition(sf::Vector2f(750, 450));
	choice[4].setFillColor(sf::Color::Transparent);
	choice[4].setOutlineColor(sf::Color::White);
	choice[4].setOutlineThickness(3);

	choice[2].setSize(sf::Vector2f(150.0f, 60.0f));
	choice[2].setPosition(sf::Vector2f(1000., 650));
	choice[2].setFillColor(sf::Color::Transparent);
	choice[2].setOutlineThickness(3);
	choice[2].setOutlineColor(sf::Color::White);

	sf::String namef;
	sf::Text tnamef(namef, font, 40);
	tnamef.setFillColor(sf::Color::Black);
	tnamef.setPosition(460, 40);

	sf::String names;
	sf::Text tnames(names, font, 40);
	tnames.setFillColor(sf::Color::Black);
	tnames.setPosition(460, 200);

	window.draw(photo);
	for (int i = 0; i <= 8; i++) {
		if (i != 3)
			window.draw(text[i]);
		if (i < 7)
			window.draw(choice[i]);

	}

	window.display();

	bool spaces = false, nod = false, trans = false, d = false, hanroh = false, same = false;

	string t = "n";
	sf::Event event;
	while (window.waitEvent(event))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			sf::Vector2i local_position = sf::Mouse::getPosition(window);
			if (local_position.x >= 448 && local_position.x <= 730 && local_position.y >= 36 && local_position.y <= 92)
			{
				cout << "locatin" << endl;
				active = 1;
			}
			else if (local_position.x >= 448 && local_position.x <= 732 && local_position.y >= 196 && local_position.y <= 253)
			{
				cout << "destination" << endl;
				active = 2;
			}
			else if (local_position.x >= 146 && local_position.x <= 351 && local_position.y >= 447 && local_position.y <= 530)
			{
				cout << "CAR" << endl;
				choice[5].setOutlineColor(sf::Color::Magenta);  text[6].setFillColor(sf::Color::Magenta);
				choice[6].setOutlineColor(sf::Color::White);    text[7].setFillColor(sf::Color::White);
				choice[4].setOutlineColor(sf::Color::White);    text[8].setFillColor(sf::Color::White);
				t = "Uber";
				active = 5;
			}
			else if (local_position.x >= 447 && local_position.x <= 653 && local_position.y >= 447 && local_position.y <= 530)
			{
				cout << "BUS" << endl;
				choice[5].setOutlineColor(sf::Color::White);  text[6].setFillColor(sf::Color::White);
				choice[6].setOutlineColor(sf::Color::Magenta);    text[7].setFillColor(sf::Color::Magenta);
				choice[4].setOutlineColor(sf::Color::White);    text[8].setFillColor(sf::Color::White);
				t = "Bus";
				active = 5;
			}
			else if (local_position.x >= 746 && local_position.x <= 951 && local_position.y >= 447 && local_position.y <= 530)
			{
				cout << "METRO" << endl;
				choice[5].setOutlineColor(sf::Color::White);  text[6].setFillColor(sf::Color::White);
				choice[6].setOutlineColor(sf::Color::White);    text[7].setFillColor(sf::Color::White);
				choice[4].setOutlineColor(sf::Color::Magenta);    text[8].setFillColor(sf::Color::Magenta);
				t = "Metro";
				active = 5;
			}
			else if (local_position.x >= 996 && local_position.x <= 1150 && local_position.y >= 645 && local_position.y <= 709)
			{
				if (names.getSize() > 0 && namef.getSize() > 0 && t != "n") {
					if (g.getIdx[namef]) {
						int c = g.search_by_facility_and_name(namef, names);
						if (c != -1) {
							if (g.getIdx[namef] != c) {
								int l = g.Dijkstra(g.getIdx[namef], c, t, 0);
								if (l != INT_MAX) {
									if (t == "Uber") {
										if (g.find_captain() != -1) {

											estimate = l;
											drive = g.find_captain();
											tran = t;
											position = 25;
											break;
										}
										else
										{
											g.child.clear();
											trans = true;
											nod = false;
											spaces = false;
											d = false;
											hanroh = false;
											same = false;
										}
									}
									else
									{
										estimate = l;
										tran = t;
										position = 25;
										break;
									}
								}
								else
								{
									g.child.clear();
									hanroh = true;
									nod = false;
									spaces = false;
									d = false;
									trans = false;
									same = false;
								}
							}
							else
							{
								same = true;
								hanroh = false;
								nod = false;
								spaces = false;
								d = false;
								trans = false;
							}
						}
						else
						{
							nod = true;
							spaces = false;
							d = false;
							trans = false;
							hanroh = false;
							same = false;
						}
					}
					else
					{
						d = true;
						nod = false;
						spaces = false;
						trans = false;
						hanroh = false;
						same = false;
					}
				}
				else
				{
					d = false;
					nod = false;
					spaces = true;
					trans = false;
					hanroh = false;
					same = false;
				}
			}
			else if (local_position.x >= 1036 && local_position.x <= 1160 && local_position.y >= 37 && local_position.y <= 106)
			{
				cout << "back" << endl;
				position = 40;
				break;
			}

		}
		if (event.type == sf::Event::TextEntered) {
			if (active == 1 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
				namef += event.text.unicode;
				tnamef.setString(namef);
			}
			else if (active == 1 && event.text.unicode == 8 && namef.getSize() > 0)
			{
				namef.erase(namef.getSize() - 1, namef.getSize());
				tnamef.setString(namef);
			}
			if (active == 2 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
				names += event.text.unicode;
				tnames.setString(names);
			}
			else if (active == 2 && event.text.unicode == 8 && names.getSize() > 0) {
				names.erase(names.getSize() - 1, names.getSize());
				tnames.setString(names);
			}
		}
		window.draw(photo);
		for (int i = 0; i <= 8; i++) {
			if (i != 3)
				window.draw(text[i]);
			if (i < 7)
				window.draw(choice[i]);

		}
		if (spaces)
			window.draw(text[3]);
		if (d)
			window.draw(text[10]);
		if (nod)
			window.draw(text[11]);
		if (trans)
			window.draw(text[12]);
		if (hanroh)
			window.draw(text[13]);
		if (same)
			window.draw(text[14]);
		window.draw(tnamef);
		window.draw(tnames);
		window.display();
	}

}

void orderchoice()
{
	text[1].setFont(font);
	text[1].setString("Order For Destination");
	text[1].setCharacterSize(39);
	text[1].setFillColor(sf::Color::White);
	text[1].setPosition(385, 270);
	text[1].setStyle(sf::Text::Bold);

	text[2].setFont(font);
	text[2].setString("Order For Service ");
	text[2].setCharacterSize(40);
	text[2].setFillColor(sf::Color::White);
	text[2].setPosition(410, 470);
	text[2].setStyle(sf::Text::Bold);

	text[0].setFont(font);
	text[0].setString(" Back ");
	text[0].setCharacterSize(40);
	text[0].setFillColor(sf::Color::White);
	text[0].setPosition(1050, 50);
	text[0].setStyle(sf::Text::Bold);

	choice[0].setSize(sf::Vector2f(400.0f, 85.0f));
	choice[0].setPosition(sf::Vector2f(380, 250));
	choice[0].setFillColor(sf::Color::Transparent);
	choice[0].setOutlineThickness(3);
	choice[0].setOutlineColor(sf::Color::White);

	choice[2].setSize(sf::Vector2f(400.0f, 85.0f));
	choice[2].setPosition(sf::Vector2f(380, 450));
	choice[2].setFillColor(sf::Color::Transparent);
	choice[2].setOutlineThickness(3);
	choice[2].setOutlineColor(sf::Color::White);

	choice[1].setSize(sf::Vector2f(120.0f, 65.0f));
	choice[1].setPosition(sf::Vector2f(1040, 40));
	choice[1].setFillColor(sf::Color::Transparent);
	choice[1].setOutlineThickness(3);
	choice[1].setOutlineColor(sf::Color::White);

	window.clear();
	window.draw(photo);
	for (int i = 0; i < 3; i++) {
		window.draw(choice[i]);
		window.draw(text[i]);
	}
	if (type != 'a')
	{
		window.draw(choice[2]);
		window.draw(text[2]);
	}
	window.display();

	sf::Event event;
	while (window.waitEvent(event))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

			sf::Vector2i local_position = sf::Mouse::getPosition(window);
			if (local_position.x >= 378 && local_position.x <= 782 && local_position.y >= 446 && local_position.y <= 534)
			{
				cout << "order for service" << endl;
				position = 42;
				break;
			}
			else if (local_position.x >= 376 && local_position.x <= 782 && local_position.y >= 247 && local_position.y <= 337)
			{
				cout << "order for destiantion" << endl;
				position = 41;
				break;
			}
			else if (local_position.x >= 1036 && local_position.x <= 1160 && local_position.y >= 37 && local_position.y <= 106)
			{
				position = 19;
				break;
			}
		}
	}
}

void driverpage() {

	text[0].setFont(font);
	text[0].setString("View My Trip ");
	text[0].setCharacterSize(40);
	text[0].setFillColor(sf::Color::Cyan);
	text[0].setPosition(490, 360);
	text[0].setStyle(sf::Text::Bold);

	text[1].setFont(font);
	text[1].setString("  View Map ");
	text[1].setCharacterSize(40);
	text[1].setFillColor(sf::Color::Cyan);
	text[1].setPosition(490, 580);
	text[1].setStyle(sf::Text::Bold);

	text[2].setFont(font);
	text[2].setString(" Log-out ");
	text[2].setCharacterSize(25);
	text[2].setFillColor(sf::Color::Cyan);
	text[2].setPosition(1047, 56);
	text[2].setStyle(sf::Text::Bold);

	choice[2].setSize(sf::Vector2f(250.0f, 80.0f));
	choice[2].setPosition(sf::Vector2f(480, 346));
	choice[2].setFillColor(sf::Color::Transparent);
	choice[2].setOutlineThickness(3);
	choice[2].setOutlineColor(sf::Color::Cyan);

	choice[0].setSize(sf::Vector2f(250.0f, 80.0f));
	choice[0].setPosition(sf::Vector2f(480, 562));
	choice[0].setFillColor(sf::Color::Transparent);
	choice[0].setOutlineThickness(3);
	choice[0].setOutlineColor(sf::Color::Cyan);

	choice[1].setSize(sf::Vector2f(120.0f, 68.0f));
	choice[1].setPosition(sf::Vector2f(1040, 40));
	choice[1].setFillColor(sf::Color::Transparent);
	choice[1].setOutlineThickness(3);
	choice[1].setOutlineColor(sf::Color::Cyan);

	window.clear();
	window.draw(photo);
	for (int i = 0; i < 3; i++)
	{
		window.draw(choice[i]);
		window.draw(text[i]);
	}
	window.display();

	sf::Event event;
	while (window.waitEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			sf::Vector2i local_position = sf::Mouse::getPosition(window);
			cout << '(' << local_position.x << ',' << local_position.y << ')' << endl;
			if (local_position.x >= 477 && local_position.x <= 732 && local_position.y >= 343 && local_position.y <= 427)
			{

				cout << "view trip" << endl;
				position = 60;
				break;
			}
			else if (local_position.x >= 477 && local_position.x <= 732 && local_position.y >= 559 && local_position.y <= 642)
			{

				cout << "view map" << endl;
				position = 20;
				break;
			}
			else if (local_position.x >= 1036 && local_position.x <= 1160 && local_position.y >= 37 && local_position.y <= 106)
			{
				cout << "logout" << endl;
				position = 1;
				have_r = false;
				break;
			}
		}
	}
}

void viewcutomerdata(int h) {

	text[0].setFont(font);
	text[0].setString(" Back ");
	text[0].setCharacterSize(40);
	text[0].setFillColor(sf::Color::White);
	text[0].setPosition(1050, 50);
	text[0].setStyle(sf::Text::Bold);

	text[2].setFont(font);
	text[2].setString("Name                : ");
	text[2].setCharacterSize(40);
	text[2].setFillColor(sf::Color::White);
	text[2].setPosition(150, 190);
	text[2].setStyle(sf::Text::Bold);

	text[6].setFont(font);
	text[6].setString(" ROUTE ");
	text[6].setCharacterSize(40);
	text[6].setFillColor(sf::Color::White);
	text[6].setPosition(1012, 652);
	text[6].setStyle(sf::Text::Bold);

	text[5].setFont(font);
	text[5].setString("You Are Not Assigned To Cutomer. ");
	text[5].setCharacterSize(40);
	text[5].setFillColor(sf::Color::White);
	text[5].setPosition(250, 190);
	text[5].setStyle(sf::Text::Bold);

	text[1].setFont(font);
	text[1].setString("Phone Number   :");
	text[1].setCharacterSize(40);
	text[1].setFillColor(sf::Color::White);
	text[1].setPosition(150, 300);
	text[1].setStyle(sf::Text::Bold);


	choice[0].setSize(sf::Vector2f(120.0f, 65.0f));
	choice[0].setPosition(sf::Vector2f(1040, 40));
	choice[0].setFillColor(sf::Color::Transparent);
	choice[0].setOutlineThickness(3);
	choice[0].setOutlineColor(sf::Color::White);

	choice[1].setSize(sf::Vector2f(150.0f, 60.0f));
	choice[1].setPosition(sf::Vector2f(1000., 650));
	choice[1].setFillColor(sf::Color::Transparent);
	choice[1].setOutlineThickness(3);
	choice[1].setOutlineColor(sf::Color::White);


	sf::Event event;
	while (window.waitEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			sf::Vector2i local_position = sf::Mouse::getPosition(window);
			cout << '(' << local_position.x << ',' << local_position.y << ')' << endl;
			if (local_position.x >= 1036 && local_position.x <= 1160 && local_position.y >= 37 && local_position.y <= 106)
			{
				cout << "back" << endl;
				position = 17;
				break;
			}
			else if (h != -1 && local_position.x >= 996 && local_position.x <= 1150 && local_position.y >= 645 && local_position.y <= 709)
			{
				cout << "route" << endl;
				position = 70;
				break;
			}

		}

		if (h != -1) {

			have_r = true;

			text[3].setString(g.C[h].name);
			text[3].setFillColor(sf::Color::Magenta);
			text[3].setPosition(500, 195);

			text[4].setString(g.C[h].phone_num);
			text[4].setFillColor(sf::Color::Magenta);
			text[4].setPosition(500, 305);
		}
		window.clear();
		window.draw(photo);
		if (h != -1) {
			for (int i = 1; i < 5; i++) {
				window.draw(text[i]);
			}
			window.draw(text[6]);
			window.draw(choice[1]);
		}
		else
		{
			window.draw(text[5]);
		}
		window.draw(text[0]);
		window.draw(choice[0]);
		window.display();
	}

}

void display_route_driver()
{
	text[0].setFont(font);
	text[0].setString(" BACK ");
	text[0].setCharacterSize(20);
	text[0].setFillColor(sf::Color::White);
	text[0].setPosition(1130, 103);
	text[0].setStyle(sf::Text::Bold);

	choice[0].setSize(sf::Vector2f(70.0f, 30.0f));
	choice[0].setPosition(sf::Vector2f(1123., 100));
	choice[0].setFillColor(sf::Color::Transparent);
	choice[0].setOutlineThickness(3);
	choice[0].setOutlineColor(sf::Color::White);

	for (int i = 0; i < g.nodes.size(); i++)
	{
		g.nodes[i].is_in_route = false;
	}
	for (int i = 0; i < assigned_customer[who_open].second.size(); i++)
	{
		g.nodes[g.getIdx[assigned_customer[who_open].second[i]]].is_in_route = true;
	}
	Font font;

	font.loadFromFile("Roboto-MediumItalic.ttf");

	//////////////////   circle  ///////////////////////////
	CircleShape circ2(10.0f);
	vector<CircleShape>circles;
	circ2.setOrigin(10.0f, 10.0f);
	circ2.setFillColor(Color::Cyan);
	circ2.setOutlineThickness(10.0f);
	circ2.setOutlineColor(Color::Cyan);
	vector<Text>node_name;
	String name;
	Text textname(name, font, 25);
	textname.setFillColor(sf::Color::Magenta);
	textname.setPosition(460, 480);
	for (int i = 1; i < g.nodes.size(); i++)
	{
		circ2.setPosition(g.nodes[i].Coordinates.first, g.nodes[i].Coordinates.second);
		circles.push_back(circ2);
		if (g.nodes[i].is_in_route == true)
			circles[circles.size() - 1].setFillColor(Color::Blue);
		textname.setString(g.nodes[i].name);
		textname.setPosition(g.nodes[i].Coordinates.first - 30, g.nodes[i].Coordinates.second - 50);
		node_name.push_back(textname);
	}

	////////////////// rectangle ///////////////////////////

	vector<RectangleShape>rectangles;
	float x, y, a, b;
	for (int i = 0; i < g.edges.size(); i++)
	{
		x = g.nodes[g.edges[i].firstNode].Coordinates.first;
		y = g.nodes[g.edges[i].firstNode].Coordinates.second;
		a = g.nodes[g.edges[i].secondNode].Coordinates.first;
		b = g.nodes[g.edges[i].secondNode].Coordinates.second;
		float distance = sqrt((b - y)*(b - y) + (a - x)*(a - x));
		float angle;
		float px, py;
		px = a - x;
		py = b - y;
		angle = atan2(py, px) * 180 / PI;

		RectangleShape rec(Vector2f(200.0f, 5.0f));
		rec.setOrigin(0.0f, 2.5f);
		rec.setFillColor(Color::Cyan);
		rec.setPosition(x, y);
		rec.setRotation(angle);
		cout << rec.getRotation() << endl;
		rec.setSize(Vector2f(distance, 5.0f));
		rectangles.push_back(rec);
		if (g.nodes[g.edges[i].firstNode].is_in_route && g.nodes[g.edges[i].secondNode].is_in_route)
		{
			rectangles[rectangles.size() - 1].setFillColor(Color::Blue);
		}
	}

	Event evnt;
	while (window.waitEvent(evnt))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			sf::Vector2i local_position = sf::Mouse::getPosition(window);
			if (local_position.x >= 1120 && local_position.x <= 1196 && local_position.y >= 96 && local_position.y <= 130)
			{
				cout << "Back" << endl;
				position = 60;
				break;
			}
		}
		window.clear();
		window.draw(photo);
		window.draw(text[0]);
		window.draw(choice[0]);
		for (int i = 0; i < circles.size(); i++)
		{
			window.draw(circles[i]);
		}
		for (int i = 0; i < rectangles.size(); i++)
		{
			window.draw(rectangles[i]);
		}
		for (int i = 0; i < circles.size(); i++)
		{
			if (circles[i].getFillColor() == Color::Blue)
				window.draw(circles[i]);
		}
		for (int i = 0; i < rectangles.size(); i++)
		{
			if (rectangles[i].getFillColor() == Color::Blue)
				window.draw(rectangles[i]);
		}
		for (int i = 0; i < node_name.size(); i++)
		{
			window.draw(node_name[i]);
		}
		window.display();
	}
}

int main()
{
	font.loadFromFile("Roboto-MediumItalic.ttf");
	assigned_customer.resize(10);
	for (int i = 0; i < 100; i++)
		text[i].setFont(font);
	for (int i = 0; i < 10; i++)
		assigned_customer[i].first = -1;

	phot.setPosition(0, 0);
	sf::Texture wall;
	wall.loadFromFile("a.jpg");
	phot.setTexture(&wall);

	photo.setPosition(0, 0);
	sf::Texture walll;
	walll.loadFromFile("Uber_MarketMap_April92015_.jpg");
	photo.setTexture(&walll);
	g.read();

	while (window.isOpen())
	{

		if (position == 0) { wl(); }
		if (position == 1) { wlpage(); }
		if (position == 11 || position == 12 || position == 13) { choicee(); }
		if (position == 15) { login(); }
		if (position == 16 && type == 'd')
		{
			regdriver();
			if (ay == 1)
				driverpage();
		}
		if (position == 16 && type == 'c')
		{
			regcutomer();
			if (ay == 1)
				customerpage();
		}
		if (position == 17 && type == 'd') { driverpage(); }
		if (position == 18 && type == 'a') { adminpage(); }
		if (position == 19 && type == 'c') { customerpage(); }
		if (position == 20) { viewmap(); }
		if (position == 21) { addedge(); }
		if (position == 22) { deletemap(); }
		if (position == 23) { addnode(); }
		if (position == 24) { addservice(); }
		if (position == 40) { orderchoice(); }
		if (position == 50) { display_route(); }
		if (position == 41) { ordertrip(); }
		if (position == 42) { orderservice(); }
		if (position == 25) { estimation(estimate, tran); }
		if (position == 26) { viewdriverdata(drive); }
		if (position == 27) { ratedriver(); }
		if (position == 60) { viewcutomerdata(assigned_customer[who_open].first); }
		if (position == 100) { deletenode(); }
		if (position == 70) { display_route_driver(); }

		window.clear();
		window.display();
	}

	return 0;
}