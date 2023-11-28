#include "graph.h"
using namespace std;


void Arc::SetColor()
{
	cout << "1 - Red\n2 - Green\n3 - Yellow\n4 - Blue\n";
	cout << "Enter color of arc: ";
	cin >> color;
}

Arc::Arc()
{
	string color = "undefined";
	input = false;
}

void Arc::PrintColor()
{
	cout << color << endl;
}

int Arc::numColor()
{
	return color;
}

void Arc::setInput()
{
	input = true;
}

bool Arc::getInput()
{
	return input;
}
