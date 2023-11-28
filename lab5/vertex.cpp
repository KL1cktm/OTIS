#include "graph.h"
using namespace std;

Vertex::Vertex()
{
	vertexName = "Unknown";
	string data = "***";
	string color = "undefined";
}

void Vertex::setVertexName(string vertexname)
{
	this->vertexName = vertexname;
}

void Vertex::setData(string data)
{
	this->data = data;
}

void Vertex::Print()
{
	cout << "Vertex name: " << vertexName << endl;
	cout << "Stored data: " << data << endl;
	cout << "Color: " << color << endl;
}

void Vertex::Printdata()
{
	cout << "Название вершины: " << vertexName << " Данные: " << data << endl;
}

void Vertex::Rewrite()
{
	cout << "Enter vertex name: ";
	getline(cin, vertexName);
}

void Vertex::SetColor()
{
	cout << "1 - Red\n2 - Green\n3 - Yellow\n4 - Blue\n";
	cout << "Enter color of vertex: ";
	cin >> color;
}

void Vertex::PrintName()
{
	cout << vertexName;
}

int Vertex::numColor()
{
	return color;
}

string Vertex::getData()
{
	return data;
}

