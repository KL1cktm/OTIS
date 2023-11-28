#include "graph.h"
#include <iostream>
using namespace std;

void Graph::setName(string name)
{
	this->name = name;
}

void Graph::createVertex(string vertexname)
{
	for (int i = 0; i < vert.size(); i++)
	{
		if (vert[i].vertexName == vertexname)
		{
			cout << "A vertex with the same name already exists" << endl;
			cout << "Enter another vertex name: ";
			cin >> vertexname;
			i = -1;
		}
	}
	bufVert.setVertexName(vertexname);
	bufVert.setData("unknown");
}

void Graph::vertexData(string data) //проверка ссылки
{

	bufVert.setData(data);
}

void Graph::checkCommits()
{
	for (int i = 0; i < stack.size(); i++)
	{
		cout << i+1 << ") " << "Commit: " << stack[i].comment << "\t\t" << stack[i].name << endl;
	}
}

void Graph::deleteVertex()
{
	for (int i = 0; i < vert.size(); i++)
	{
		cout << i + 1 << "\t";
		vert[i].Printdata();
	}
	cout << "Choose number of vertex which you want to delete: ";
	int index;
	cin >> index;
	index = index - 1;
	vert.erase(vert.begin() + index);
	// удаление дуг добавить
	vector<Arc> arcs;
	for (int i = 0; i < arc.size(); i++)
	{
		if (arc[i].indexStart == index || arc[i].indexEnd == index)
		{	
		}
		else
		{
			arcs.push_back(arc[i]);
		}
	}
	arc = arcs;
	for (int i = 0; i < arc.size(); i++)
	{
		if (arc[i].indexEnd >= index)
		{
			arc[i].indexEnd = arc[i].indexEnd - 1;
		}
		if (arc[i].indexStart >= index)
		{
			arc[i].indexStart = arc[i].indexStart - 1;
		}
	}
}

void Graph::commitChanges()
{
	cout << "Write changes: ";
	string com;
	cin.ignore();
	getline(cin, com);
	comment = com;
	Graph bufgraph;
	bufgraph.comment = comment;
	bufgraph.vert = vert;
	bufgraph.name = name;
	bufgraph.arc = arc;
	stack.push_back(bufgraph);
}


void Graph::vertexInGraph()
{
	vert.push_back(bufVert);
}

void Graph::rewriteVertex()
{
	for (int i = 0; i < vert.size(); i++)
	{
		cout << i + 1 << "\t";
		vert[i].Printdata();
	}
	cout << "Enter the number of vertex which needs to be changed: ";
	int index;
	cin >> index;
	index = index - 1;
	cout << "Enter new vertex name: ";
	string nameVert;
	cin >> nameVert;
	for (int i = 0; i < vert.size(); i++)
	{
		if (vert[i].vertexName == nameVert)
		{
			cout << "A vertex with the same name already exists" << endl;
			cout << "Enter another vertex name: ";
			cin >> nameVert;
			i = -1;
		}
	}
	vert[index].setVertexName(nameVert);
	cout << "if you want to change the vertex data, enter - 1, else enter - 2" << endl;
	int choose;
	cin >> choose;
	if (choose == 1)
	{
		cout << "Enterr new vertex data: ";
		cin >> nameVert;
		vert[index].setData(nameVert);
	}
}

void Graph::Print()
{
	bufVert.Print();
}

void Graph::printVertexs()
{
	for (int i = 0; i < vert.size(); i++)
	{
		vert[i].Print();
	}
}

void Graph::createArc()
{
	int choose;
	cout << "Choose arc" << endl;
	cout << "1 - Oriented\t 2 - Unoriented" << endl;
	cin >> choose;
	for (int i = 0; i < vert.size(); i++)
	{
		cout << i + 1 << "\t";
		vert[i].Printdata();
	}
	cout << "Enter the index of the vertex that will be the start of the arc: ";
	cin >> ar.indexStart;
	ar.indexStart = ar.indexStart - 1;
	cout << "Enter the index of the vertex that will be the end of the arc: ";
	cin >> ar.indexEnd;
	ar.indexEnd = ar.indexEnd - 1;
	if (choose == 1)
	{
		ar.oriented = true;
	}
	else
	{
		ar.oriented = false;
	}
	if (checkEqual())
	{
		arc.push_back(ar);
	}
	else
	{
		cout << "The graph contains such an arc" << endl;
	}
}

void Graph::printInfo()
{
	cout << "Info about a graph: " << name << endl;
	cout << "Graph stored " << vert.size() << " vertexs" << endl;
	cout << "Graph stored " << arc.size() << " arcs" << endl;
	for (int i = 0; i < vert.size(); i++)
	{
		int degree = 0;
		cout << "Vertex "; vert[i].PrintName(); cout << " has a degree: ";
		for (int j = 0; j < arc.size(); j++)
		{
			if (arc[j].indexEnd == i || arc[j].indexStart == i)
			{
				degree++;
			}
		}
		cout << degree << endl;
	}
}

bool Graph::checkEqual()
{
	for (int i = 0; i < arc.size(); i++)
	{
		if ((arc[i].indexEnd == ar.indexEnd && arc[i].indexStart == ar.indexStart) || (arc[i].indexEnd == ar.indexStart && arc[i].indexStart == ar.indexEnd))
		{
			return false;
		}
	}
	return true;
}

void Graph::printDegreeVertex()
{
	cout << "Choose vertex: " << endl;
	int choose;
	for (int i = 0; i < vert.size(); i++)
	{
		cout << i + 1 << "\t";
		vert[i].Printdata();
	}
	cin >> choose;
	choose = choose - 1;
	int degree = 0;
	cout << "Vertex "; vert[choose].PrintName(); cout << " has a degree: ";
	for (int j = 0; j < arc.size(); j++)
	{
		if (arc[j].indexEnd == choose || arc[j].indexStart == choose)
		{
			degree++;
		}
	}
	cout << degree << endl;
}

int Graph::DegreeVertex(int choose)
{
	int degree = 0;
	for (int j = 0; j < arc.size(); j++)
	{
		if (arc[j].indexEnd == choose || arc[j].indexStart == choose)
		{
			degree++;
		}
	}
	return degree;
}

void Graph::changeVertex()
{
	int num1, num2;
	for (int i = 0; i < vert.size(); i++)
	{
		cout << i + 1 << "  -  " << vert[i].vertexName << endl;
	}
	cout << "Select the vertexs you want to swap places" << endl;
	cout << "First vertex - "; cin >> num1;
	cout << "Second vertex - "; cin >> num2;
	num1 = num1 - 1;
	num2 = num2 - 1;
	Vertex buferVertex;
	buferVertex = vert[num1];
	vert[num1] = vert[num2];
	vert[num2] = buferVertex;
	Arc buferArc;
	vector<Arc> buferArcs;
	for (int i = 0; i < arc.size(); i++)
	{
		buferArc = arc[i];
		if (arc[i].indexEnd == num1)
		{
			buferArc.indexEnd = num2;
		}
		if (arc[i].indexStart == num1)
		{
			buferArc.indexStart = num2;
		}
		if (arc[i].indexEnd == num2)
		{
			buferArc.indexEnd = num1;
		}
		if (arc[i].indexStart == num2)
		{
			buferArc.indexStart = num1;
		}
		buferArcs.push_back(buferArc);
	}
	arc = buferArcs;
}

vector<Vertex> Graph::getVertexs()
{
	return vert;
}

vector<Arc> Graph::getArcs()
{
	return arc;
}

void Graph::deleteArc()
{
	cout << "Select the vertexs of the arc between which you want to delete: " << endl;
	for (int i = 0; i < vert.size(); i++)
	{
		cout << i + 1 << "\t";
		vert[i].Printdata();
	}
	cout << "First vertex: "; cin >> ar.indexStart;
	ar.indexStart = ar.indexStart - 1;
	cout << "Second vertex: "; cin >> ar.indexEnd;
	ar.indexEnd = ar.indexEnd - 1;
	for (int i = 0; i < arc.size(); i++)
	{
		if ((arc[i].indexEnd == ar.indexEnd && arc[i].indexStart == ar.indexStart) || (arc[i].indexEnd == ar.indexStart && arc[i].indexStart == ar.indexEnd))
		{
			arc.erase(arc.begin() + i);
			return;
		}
	}
}

void Graph::imageNode()
{
	cout << "Select the vertex for which you want to set the node image: " << endl;
	int image;
	for (int i = 0; i < vert.size(); i++)
	{
		cout << i + 1 << "\t";
		vert[i].Printdata();
	}
	cin >> image; 
	image = image - 1;
	vector<Arc> bufarc;
	for (int i = 0; i < arc.size(); i++)
	{
		if (arc[i].indexEnd == image || arc[i].indexStart == image)
		{
		}
		else
		{
			bufarc.push_back(arc[i]);
		}
	}
	arc = bufarc;
	cout << "Enter the number of vertex links (Max links " << vert.size() - 1 << "): ";
	int num;
	cin >> num;
	for (int i = 0; i < vert.size(); i++)
	{
		if (i != image)
		{
			cout << i + 1 << "\t";
			vert[i].Printdata();
		}		
	}
	vector<int> id;
	int index;
	for (int i = 0; i < num; i++)
	{
		cout << "Select vertexs without repeating them: ";
		cin >> index;
		index = index - 1;
		id.push_back(index);
	}
	for (int i = 0; i < id.size(); i++)
	{
		int choose;
		cout << "Choose the type of arc\n1 - Oriented\t2 - Unoriented" << endl;
		cin >> choose;
		if (choose == 1)
		{
			ar.oriented = true;
			cout << "1   -   " << vert[image].vertexName << endl;
			cout << "2   -   " << vert[id[i]].vertexName << endl;
			cout << "Choose start vertex: " << endl;
			int number; cin >> number;
			if (number == 1)
			{
				ar.indexStart = image;
				ar.indexEnd = id[i];
			}
			else
			{
				ar.indexStart = id[i];
				ar.indexEnd = image;
			}
		}
		else
		{
			ar.oriented = false;
			ar.indexStart = image;
			ar.indexEnd = id[i];
		}
		if (checkEqual())
		{
			arc.push_back(ar);
		}
		else
		{
			cout << "The graph contains such an arc" << endl;
		}
	}
}

void Graph::detailedInfo(Graph graph)
{
	cout << "Detailed info: " << endl;
	cout << "Graph name: " << graph.name << endl;
	graph.printInfo();
}

void Graph::printArcs()
{
	for (int i = 0; i < arc.size(); i++)
	{
		cout << "Arc connecting vertexs: \"" << vert[arc[i].indexStart].vertexName << "\" and \"" << vert[arc[i].indexEnd].vertexName << "\" have color: ";
		arc[i].PrintColor();
	}
}

void Graph::createMatrix()
{
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			matrix[i][j] = 0;
		}
	}
	for (int i = 0; i < arc.size(); i++)
	{
		for (int j = 0; j < vert.size(); j++)
		{
			matrix[i][j] = 0;
		}
		if (arc[i].oriented)
		{
			matrix[i][arc[i].indexStart] = -1;
			matrix[i][arc[i].indexEnd] = 1;
		}
		else
		{
			matrix[i][arc[i].indexStart] = 1;
			matrix[i][arc[i].indexEnd] = 1;
		}
	}
}

void Graph::printMatrix()
{
	for (int i = 0; i < vert.size(); i++)
	{
		switch (vert[i].numColor())
		{
		case 1:
			cout << "\033[31m";
			break;
		case 2:
			cout << "\033[32m";
			break;
		case 3:
			cout << "\033[33m";
			break;
		case 4:
			cout << "\033[34m";
			break;
		default:
			cout << "\033[0m";
			break;
		}
		cout << "v" << i + 1;
		cout << "\033[0m"; 
		cout << "\t";
	}
	cout << endl;
	for (int i = 0; i < arc.size(); i++)
	{
		for (int j = 0; j < vert.size(); j++)
		{
			switch (arc[i].numColor())
			{
			case 1:
				cout << "\033[31m";
				break;
			case 2:
				cout << "\033[32m";
				break;
			case 3:
				cout << "\033[33m";
				break;
			case 4:
				cout << "\033[34m";
				break;
			default:
				cout << "\033[0m";
				break;
			}
			cout << matrix[i][j] << "\t";
		}
		cout << "\033[0m";
		cout << endl;
	}
}

void Graph::graphComparisonVertex(vector<Vertex> check, vector<Arc> rca, bool* flag)
{
	if ((check[0].vertexName == check[check.size() - 1].vertexName) && (rca.size() == arc.size()))
	{
		cout << "The graph is Eulerian" << endl;
		*flag = true;
	}
}

void Graph::graphEulerVert(Vertex v, int cols, vector<Vertex> bvertex, vector<Arc> rca,bool* flag)
{
	bvertex.push_back(v);
	if (bvertex.size() > 1)
	{
		graphComparisonVertex(bvertex, rca, flag);
	}
	for (int i = 0; i < arc.size(); i++)
	{
		if (*flag)
		{
			return;
		}
		if (matrix[i][cols] == 1)
		{
			if (!arc[i].oriented)
			{
				if (!checkVectorOfArc(rca, arc[i]))
				{
					rca.push_back(arc[i]);
					if (arc[i].indexStart == cols)
					{
						bufVert = vert[arc[i].indexEnd];
						graphEulerVert(bufVert, arc[i].indexEnd, bvertex, rca, flag);
						//переход к следующей вершине
					}
					if (arc[i].indexEnd == cols)
					{
						bufVert = vert[arc[i].indexStart];
						graphEulerVert(bufVert, arc[i].indexStart, bvertex, rca, flag);
						//переход к следующей вершине
					}
					rca.pop_back();
				}
			}
		}
		if (matrix[i][cols] == -1)
		{
			if (!checkVectorOfArc(rca, arc[i]))
			{
				rca.push_back(arc[i]);
				bufVert = vert[arc[i].indexEnd];
				graphEulerVert(bufVert, arc[i].indexEnd, bvertex, rca, flag);
				//переход к следующей вершине
			}
		}
	}
}

void Graph::graphEuler()
{
		vector<Vertex> bvertex;
		vector<Arc> rc;
		rc.clear();
		bvertex.clear();
		bool flag = false;
		graphEulerVert(vert[0], 0, bvertex, rc, &flag);
		if (!flag)
		{
			cout << "Graph is not Eulerian" << endl;
		}
}

bool Graph::checkVectorOfArc(vector<Arc> ar, Arc arca)
{
	bool flag = false;
	for (int i = 0; i < ar.size(); i++)
	{
		if (ar[i].indexEnd == arca.indexEnd && ar[i].indexStart == arca.indexStart)
		{
			flag = true;
		}
	}
	return flag;
}

void Graph::comparisonVertex(vector<Vertex> check)
{
	if (check[0].vertexName == check[check.size()-1].vertexName)
	{
		cout << "The Eulerian cycle is found: " << endl;
		cout << check[0].vertexName;
		for (int i = 1; i < check.size(); i++)
		{
			cout << "  ->  " << check[i].vertexName;
		}
		cout << endl;
	}
}

void Graph::eulerVert(Vertex v,int cols, vector<Vertex> bvertex, vector<Arc> rca)
{
	bvertex.push_back(v);
	if (bvertex.size() > 1)
	{
		comparisonVertex(bvertex);
	}
	for (int i = 0; i < arc.size(); i++)
	{
		if (matrix[i][cols] == 1)
		{
			if (!arc[i].oriented)
			{
				if (!checkVectorOfArc(rca, arc[i]))
				{
					rca.push_back(arc[i]);
					if (arc[i].indexStart == cols)
					{
						bufVert = vert[arc[i].indexEnd];
						eulerVert(bufVert, arc[i].indexEnd, bvertex, rca);
						//переход к следующей вершине
					}
					if (arc[i].indexEnd == cols)
					{
						bufVert = vert[arc[i].indexStart];
						eulerVert(bufVert, arc[i].indexStart, bvertex, rca);
						//переход к следующей вершине
					}
					rca.pop_back();
				}
			}
		}
		if (matrix[i][cols] == -1)
		{
			if (!checkVectorOfArc(rca, arc[i]))
			{
				rca.push_back(arc[i]);
				bufVert = vert[arc[i].indexEnd];
				eulerVert(bufVert, arc[i].indexEnd, bvertex, rca);
				//переход к следующей вершине
			}
		}
	}
}

void Graph::eulerCycles()
{
	for (int i = 0; i < vert.size(); i++)
	{
		vector<Vertex> bvertex;
		vector<Arc> rc;
		rc.clear();
		bvertex.clear();
		eulerVert(vert[i], i, bvertex, rc);
	}
}

void Graph::restoreGraph()
{
	checkCommits();
	cout << "Choose the number of commit which you want to restore: ";
	int index; cin >> index;
	index = index - 1;
	detailedInfo(stack[index]);
	Graph bufgraph;
	comment = "Point of restore";
	bufgraph.comment = comment;
	bufgraph.vert = vert;
	bufgraph.name = name;
	bufgraph.arc = arc;
	stack.push_back(bufgraph);
	name = stack[index].name;
	vert = stack[index].vert;
	arc = stack[index].arc;
}

void Graph::setVertexColor()
{
	cout << "Select the vertex for which you want to set the color: " << endl;
	int choose;
	for (int i = 0; i < vert.size(); i++)
	{
		cout << i + 1 << "\t";
		vert[i].Printdata();
	}
	cin >> choose;
	choose = choose - 1;
	vert[choose].SetColor();
}

void Graph::setArcColor()
{
	cout << "Enter the start vertex: ";
	cin >> ar.indexStart;
	ar.indexStart = ar.indexStart - 1;
	cout << "Enter the end vertex: ";
	cin >> ar.indexEnd;
	ar.indexEnd = ar.indexEnd - 1;
	for (int i = 0; i < arc.size(); i++)
	{
		if ((arc[i].indexEnd == ar.indexEnd && arc[i].indexStart == ar.indexStart) || (arc[i].indexEnd == ar.indexStart && arc[i].indexStart == ar.indexEnd))
		{
			arc[i].SetColor();
		}
	}
}

void Graph::findRoad()
{
	int num1, num2;
	for (int i = 0; i < vert.size(); i++)
	{
		cout << i + 1 << "  -  " << vert[i].vertexName << endl;
	}
	cout << "Enter start vertex: "; cin >> num1;
	cout << "Enter end vertex: "; cin >> num2;
	num1 = num1 - 1;
	num2 = num2 - 1;
	road = true;
	createMatrix();
	bufarc.clear();
	bufvert.clear();
	bufvert.push_back(vert[num1]);
	Road(num1, num2);
	if (road)
	{
		cout << "Route not found" << endl;
	}
}

void Graph::findShortRoad()
{
	int num1, num2;
	for (int i = 0; i < vert.size(); i++)
	{
		cout << i + 1 << "  -  " << vert[i].vertexName << endl;
	}
	cout << "Enter start vertex: "; cin >> num1;
	cout << "Enter end vertex: "; cin >> num2;
	num1 = num1 - 1;
	num2 = num2 - 1;
	road = true;
	createMatrix();
	bufarc.clear();
	bufvert.clear();
	bufvert.push_back(vert[num1]);
	shortRoad(num1, num2);
	if (road)
	{
		cout << "Route not found" << endl;
	}
	else
	{
		cout << "Short road" << endl;
	}
	shortRoad();
	vertex.clear();
}

void Graph::shortRoad(int indexStart, int indexEnd)
{
	for (int i = 0; i < bufvert.size() - 1; i++)
	{
		if (bufvert[bufvert.size() - 1].vertexName == bufvert[i].vertexName)
		{
			return;
		}
	}
	if (bufvert[bufvert.size() - 1].vertexName == vert[indexEnd].vertexName)
	{
		printShortRoad();
	}
	for (int i = 0; i < arc.size(); i++)
	{
		if (bufTree(arc[i]))
		{
			if (matrix[i][indexStart] == 1)
			{
				if (!arc[i].oriented)
				{
					bufarc.push_back(arc[i]);
					if (arc[i].indexStart == indexStart)
					{
						bufvert.push_back(vert[arc[i].indexEnd]);
						shortRoad(arc[i].indexEnd, indexEnd);
						bufvert.pop_back();
						bufarc.pop_back();
					}
					if (arc[i].indexEnd == indexStart)
					{
						bufvert.push_back(vert[arc[i].indexStart]);
						shortRoad(arc[i].indexStart, indexEnd);
						bufvert.pop_back();
						bufarc.pop_back();
					}
				}
			}
			if (matrix[i][indexStart] == -1)
			{
				bufarc.push_back(arc[i]);
				bufvert.push_back(vert[arc[i].indexEnd]);
				shortRoad(arc[i].indexEnd, indexEnd);
				bufvert.pop_back();
				bufarc.pop_back();
			}
		}
	}
}

void Graph::printShortRoad()
{
	road = false;
	vertex.push_back(bufvert);
}

void Graph::shortRoad()
{
	int size;
	int index = 0;
	size = vertex[0].size();
	for (int i = 0; i < vertex.size(); i++)
	{
		if (size > vertex[i].size())
		{
			size = vertex[i].size();
			index = i;
		}
	}
	for (int i = 0; i < vertex[index].size(); i++)
	{
		if (i < vertex[index].size() - 1)
		{
			cout << vertex[index][i].vertexName << "  ->  ";
		}
		else
		{
			cout << vertex[index][i].vertexName << endl;
		}
	}
	if (vertex[index].size() - 1 > 1)
	{
		cout << "The shortest route consists of " << vertex[index].size() - 1 << " arcs" << endl;
	}
	else
	{
		cout << "The shortest route consists of " << vertex[index].size() - 1 << " arc" << endl;
	}
}

void Graph::Road(int indexStart, int indexEnd)
{
	for (int i = 0; i < bufvert.size()-1; i++)
	{
		if (bufvert[bufvert.size()-1].vertexName == bufvert[i].vertexName)
		{
			return;
		}
	}
	if (bufvert[bufvert.size()-1].vertexName == vert[indexEnd].vertexName)
	{
		printRoad();
	}
	for (int i = 0; i < arc.size(); i++)
	{
		if (bufTree(arc[i]))
		{
			if (matrix[i][indexStart] == 1)
			{
				if (!arc[i].oriented)
				{
					bufarc.push_back(arc[i]);
					if (arc[i].indexStart == indexStart)
					{
						bufvert.push_back(vert[arc[i].indexEnd]);
						Road(arc[i].indexEnd, indexEnd);
						bufvert.pop_back();
						bufarc.pop_back();
					}
					if (arc[i].indexEnd == indexStart)
					{
						bufvert.push_back(vert[arc[i].indexStart]);
						Road(arc[i].indexStart, indexEnd);
						bufvert.pop_back();
						bufarc.pop_back();
					}
				}
			}
			if (matrix[i][indexStart] == -1)
			{
				bufarc.push_back(arc[i]);
				bufvert.push_back(vert[arc[i].indexEnd]);
				Road(arc[i].indexEnd, indexEnd);
				bufvert.pop_back();
				bufarc.pop_back();
			}
		}
	}
}

void Graph::printRoad()
{
	for (int i = 0; i < bufvert.size(); i++)
	{
		road = false;
		if (i < bufvert.size() - 1)
		{
			cout << bufvert[i].vertexName << "  ->  ";
		}
		else
		{
			cout << bufvert[i].vertexName;
		}
	}
	cout << endl;
}

void Graph::searchInfo()
{
	string writedata;
	cout << "Enter vertex data: ";
	cin.ignore();
	getline(cin, writedata);
	bool index = true;
	for (int i = 0; i < vert.size(); i++)
	{
		if (writedata == vert[i].getData())
		{
			cout << "Vertex \"" << vert[i].vertexName << "\" contains data: " << vert[i].getData() << endl;
			index = false;
		}
	}
	if (index)
	{
		cout << "A vertex with the specified data was not found" << endl;
	}
}
