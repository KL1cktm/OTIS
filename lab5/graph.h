#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Vertex
{
public:
	Vertex();	
	// friend class Graph;
	void setVertexName(string vertexname);
	void setData(string data);
	void Print();
	void Printdata();
	void Rewrite();
	void SetColor();
	void PrintName();
	string vertexName;
	int numColor();
	string getData();
private:
	string data;
	int index;
	int color;
};

class Arc
{
public:
	Arc();
	int indexStart;
	int indexEnd;
	void SetColor();
	bool oriented;
	void PrintColor();
	int numColor();
	void setInput();
	bool getInput();
private:
	int color;
	bool input;
};

class Euler
{
public:
	vector<Vertex> vert;
	//vector<Arc> rc;
};

struct Tree
{
	string name;
	vector<Tree*> child;
};

struct BinaryTree
{
	string name;
	string data;
	BinaryTree* left;
	BinaryTree* right;
	string lastname;
	char orien;
};

class Graph : private Vertex, protected Arc,public Euler
{
public:
	void createVertex(string vertexname);
	void vertexData(string data);
	void vertexInGraph();
	void printVertexs();
	void deleteVertex();
	void setName(string name);
	void changeVertex();
	void Print();
	void commitChanges();
	void checkCommits();
	void rewriteVertex();
	void createArc();
	void printInfo();
	void printDegreeVertex();
	int DegreeVertex(int choose); // enter index vert     mb nenado
	void deleteArc(); //Сдвинуть дуги
	void imageNode();
	void restoreGraph();
	void setVertexColor();
	void setArcColor();
	void printArcs();
	void createMatrix();
	void printMatrix();
	void eulerCycles();
	void graphEuler();
	void createTree();
	void createBinaryTree();
	void findRoad();
	void findShortRoad();
	void searchInfo();
	vector<Vertex> getVertexs();
	vector<Arc> getArcs();
private:
	void Road(int indexStart, int indexEnd);
	void shortRoad(int indexStart, int indexEnd);
	void printRoad();
	void printShortRoad();
	void shortRoad();
	BinaryTree* fuelBinaryNode(BinaryTree* node);
	Tree* fuelTree(Tree* headRoot);
	void fuelNodeTree(Tree* root);
	void pushBinaryNode(BinaryTree* node);
	void printBinaryTree(BinaryTree* node);
	void deleteBinaryTree(BinaryTree* node);
	void printTree();
	void deleteTree(Tree* headRoot);
	void printTree(Tree* root);
	bool bufTree(Arc ar);
	void graphEulerVert(Vertex v, int cols, vector<Vertex> bvertex, vector<Arc> rca, bool* flag);
	void eulerVert(Vertex v,int cols, vector<Vertex> bvertex, vector<Arc> rca);
	bool checkEqual();
	void detailedInfo(Graph graph);
	bool checkVectorOfArc(vector<Arc> ar, Arc arca);
	void comparisonVertex(vector<Vertex> check);
	void graphComparisonVertex(vector<Vertex> check, vector<Arc> rca, bool* flag);
	string name;
	vector<Vertex> vert;
	vector<Vertex> bufvert;
	Arc ar;
	vector<Arc> arc;
	Vertex bufVert;
	vector<Graph> stack;
	string comment;
	vector<Euler> euler;
	Euler eul;
	vector<Arc> bufarc;
	vector<vector<Vertex>> vertex;
	int matrix[100][100];
	Tree* headRoot;
	BinaryTree* Root;
	bool road;
};


//class Tree
//{
//public:
//	Tree() { child.push_back(nullptr); };
//	void CreateTree(Graph g);
//private:
//	void createMatrix();
//	void pushDataInTree(int indexVert);
//	int DegreeVertex(int choose);
//	bool checkBufArc(int indexArc);
//	Vertex node;
//	vector<Tree*> child;
//	vector<Vertex> vert;
//	vector<Arc> arc;
//	vector<Arc> bufArc;
//	int matrix[100][100];
//};