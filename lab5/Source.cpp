#include <iostream>
#include <string>
#include "graph.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	vector<Graph> graph;
	int numgraph;
	cout << "select the number of graphs" << endl;
	cout << "1 - 1 Graph\t2 - 2 Graph" << endl;
	cin >> numgraph;
	int index = 0;
	if (numgraph == 1)
	{
		Graph g;
		graph.push_back(g);
	}
	else
	{
		Graph g;
		graph.push_back(g);
		graph.push_back(g);
	}

	
	bool flag = true;
	do
	{
		int choose = 0;
		cout << "Select operation" << endl;
		cout << "1 - Set the name of the graph" << endl;
		cout << "2 - Create a graph vertex" << endl; //Название + данные вершины + добавить в граф
		cout << "3 - Rewrite vertex" << endl;
		cout << "4 - Delete vertex" << endl;
		cout << "5 - Move vertexs" << endl;
		cout << "6 - Create an arc" << endl;
		cout << "7 - Delete an arc" << endl;
		cout << "8 - Set arc color" << endl;
		cout << "9 - Set vertex color" << endl;
		cout << "10 - Set the image vertex" << endl;
		cout << "11 - Display information about the graph" << endl;
		cout << "12 - Print the degree of a vertex" << endl;
		cout << "13 - Testing a graph for Eulers" << endl;
		cout << "14 - Output of all Euler cycles" << endl;
		cout << "15 - Converting a graph to a binary tree" << endl;
		cout << "16 - Converting a graph to a tree" << endl;
		cout << "17 - Finding all paths between vertexs" << endl;
		cout << "18 - Finding short path between vertexs" << endl;
		cout << "19 - Search for a vertex using given data" << endl;
		cout << "20 - Output the graph as an incidence matrix" << endl;
		cout << "21 - Change graph" << endl;
		cout << "22 - Save graph changes" << endl;
		cout << "23 - View saves" << endl;
		cout << "24 - Restore graph from saves" << endl;
		cout << "25 - Completing the program" << endl;
		cin >> choose;
		string name;
		switch (choose)
		{
		case 1:
			cout << "Enter the graph name:";
			
			cin.ignore();
			getline(cin, name);
			graph[index].setName(name);
			break;
		case 2:
			cout << "Enter the vertex name:";
			cin.ignore();
			getline(cin, name);
			graph[index].createVertex(name);
			cout << "Enter the data:";
			getline(cin, name);
			graph[index].vertexData(name);
			graph[index].vertexInGraph();
			break;
		case 3:
			graph[index].rewriteVertex();
			break;
		case 4:
			graph[index].deleteVertex();
			break;
		case 5:
			graph[index].changeVertex();
			break;
		case 6:
			graph[index].createArc();
			break;
		case 7:
			graph[index].deleteArc();
			break;
		case 8:
			graph[index].setArcColor();
			break;
		case 9:
			graph[index].setVertexColor();
			break;
		case 10:
			graph[index].imageNode();
			break;
		case 11:
			graph[index].printInfo();
			break;
		case 12:
			graph[index].printDegreeVertex();
			break;
		case 13:
			graph[index].graphEuler();
			break;
		case 14:
			graph[index].eulerCycles();
			break;
		case 15:
			graph[index].createBinaryTree();
			break;
		case 16:
			graph[index].createTree();
			break;
		case 17:
			graph[index].findRoad();
			break;
		case 18:
			graph[index].findShortRoad();
			break;
		case 19:
			graph[index].searchInfo();
			break;
		case 20:
			graph[index].createMatrix();
			graph[index].printMatrix();
			break;
		case 21:
			if (numgraph == 2)
			{
				if (index == 0)
				{
					index = 1;
				}
				else
				{
					index = 0;
				}
			}
			else
			{
				cout << "You have chosen to work with one graph" << endl;
			}
			break;
		case 22:
			graph[index].commitChanges();
			break;
		case 23:
			graph[index].checkCommits();
			break;
		case 24:
			graph[index].restoreGraph();
			break;
		case 25:
			flag = false;
			break;
		}
	} while (flag);

	//g.getName("MyGraph");
	//g.createVertex("pervaya");
	//g.vertexData("abcde dsdsd");
	//g.vertexInGraph();
	//g.createVertex("vtoraya");
	//g.vertexData("tmfsr");
	//g.vertexInGraph();
	//g.createVertex("tretya");
	//g.vertexData("kmb");
	//g.vertexInGraph();
	//g.createVertex("chetvyortaya");
	//g.vertexData("ostis");
	//g.vertexInGraph();
	////g.commitChanges();
	////g.printVertexs();
	////g.printVertexs();
	//g.createArc();
	//g.createArc();
	//g.createArc();
	//g.createArc();
	////g.checkCommits();
	////g.commitChanges();
	////g.checkCommits();
	////g.restoreGraph();
	//g.printInfo();
	////g.rewriteVertex();
	////g.printVertexs();
	////g.setVertexColor();
	////g.setVertexColor();
	////g.setArcColor();
	////g.setArcColor();
	////g.printVertexs();
	//g.printArcs();
	//g.createMatrix();
	//g.printMatrix();
	////g.printDegreeVertex();
	////g.deleteArc();
	////g.printInfo();
	////g.imageNode();
	////g.printInfo();
	////g.deleteVertex();
	////g.printInfo();
	////g.eulerCycles();
	////g.graphEuler();
	////g.createTree();
	////g.createBinaryTree();
	////g.findRoad();
	////g.findShortRoad();
	//g.searchInfo();
}