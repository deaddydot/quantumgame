#include <iostream>
#include <math.h>
#include <string>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <ctime>
#include <array>
#include <vector>
#include <algorithm>
using namespace std;
char answer;
int attack;
int block;
int treasure, treasureTotal;
int health = 30;
bool debug = false;

void story()
{
	cout << "You woke up... And found yourself in a quantum chamber. It seems like you are an experimental object for some kind of... who knows!\n";
	string name;
	cout << "What is your name?\n";
	cin >> name;
	if (name == "debug")
	{
		debug = true;
	}
	
}

char askyesno()
{
	cout << "Do you want to play? (y/n)\n";	
	cin >> answer;
	return answer;
	while(answer != 'y' && answer != 'n')
	{
	cout << "Do you want to play? (y/n)\n";	
	cin >> answer;
	return answer;
	}
}

int rolldie()
{
	int sides = 6;
	attack = rand() % sides + 1;
	block = rand() % sides + 1;
	treasure = rand() % 10 + 1;
	return attack, block;
}

void ending()
{
	if(health > 0)
	{
		cout << "You win the game with " << treasureTotal << " treasure with " << health << " remaining helath!";
	}
}

void adventure()
{
	cout << "You have 30 Health. Congratulation, your fate is now rely on some sort of RNG dice-rolling mechanic....\n";
	cout << "You can see holograms around you. One writes: \n" << "Do you want to play?\n" << "As of right now, I'm pretty sure I should answer wheter yes or no...\n";
	srand(time(NULL));
}

int main() 
{
  story();
  adventure();
  askyesno();
  treasure = 0;
  while(answer == 'y' && health > 0)
  {
	cout << "\nYou start your adventure!\n";
	rolldie();
	if(debug = true)
	{
		cout << "Attack: " << attack << endl;
		cout << "Block: " << block << endl;

	}
	if(attack <= block)
	{
		cout << "You blocked the attack!\n";
		treasureTotal += treasure;
		cout << "You have " << health << " health left.\n";
		cout << "You have " << treasureTotal << " treasure.\n\n";
	}
	else if(attack > block)
	{
		cout << "You can't block the attack! You take " << attack << " damage!\n";
		health -= attack;
		cout << "You have " << health << " health left...\n";
		cout << "You have " << treasureTotal << " treasure.\n\n";
	}
	askyesno();
  }
  ending();
}