//#include "graph.h"
//using namespace std;
//
//void Tree::CreateTree(Graph g)
//{
//	vert = g.getVertexs();
//	arc = g.getArcs();
//	for (int i = 0; i < vert.size(); i++)
//	{
//		if (DegreeVertex(i) == 0)
//		{
//			cout << "It is impossible to create a tree" << endl;
//			return;
//		}
//	}
//	createMatrix();
//	node = vert[0];
//	pushDataInTree(0);
//}
//
//int Tree::DegreeVertex(int choose)
//{
//	int degree = 0;
//	for (int j = 0; j < arc.size(); j++)
//	{
//		if (arc[j].indexEnd == choose || arc[j].indexStart == choose)
//		{
//			degree++;
//		}
//	}
//	return degree;
//}
//
//void Tree::createMatrix()
//{
//	for (int i = 0; i < arc.size(); i++)
//	{
//		for (int j = 0; j < vert.size(); j++)
//		{
//			matrix[i][j] = 0;
//		}
//		if (arc[i].oriented)
//		{
//			matrix[i][arc[i].indexStart] = -1;
//			matrix[i][arc[i].indexEnd] = 1;
//		}
//		else
//		{
//			matrix[i][arc[i].indexStart] = 1;
//			matrix[i][arc[i].indexEnd] = 1;
//		}
//	}
//}
//
//void Tree::pushDataInTree(int indexVert)
//{
//	createMatrix();
//	for (int i = 0; i < arc.size(); i++)
//	{
//		if (matrix[i][indexVert] == 1)
//		{
//			if (arc[i].oriented)
//			{
//				if (&checkBufArc)
//				{
//					bufArc.push_back(arc[i]);
//					Tree* children = new Tree;
//					children->node = vert[arc[i].indexStart];
//					children->arc = arc;
//					children->bufArc = bufArc;
//					if (child[0] == nullptr)
//					{
//						child.pop_back();
//						child.push_back(children);
//					}
//					else
//					{
//						child.push_back(children);
//					}
//				}
//			}
//			else
//			{
//				if (&checkBufArc)
//				{
//					bufArc.push_back(arc[i]);
//					Tree* children = new Tree;
//					if (i == arc[i].indexStart)
//					{
//						children->node = vert[arc[i].indexEnd];
//					}
//					if (i == arc[i].indexEnd)
//					{
//						children->node = vert[arc[i].indexStart];
//					}
//					if (child[0] == nullptr)
//					{
//						child.pop_back();
//						child.push_back(children);
//					}
//					else
//					{
//						child.push_back(children);
//					}
//				}
//			}
//
//		}
//		if (matrix[i][indexVert] == -1)
//		{
//			if (&checkBufArc)
//			{
//				bufArc.push_back(arc[i]);
//				Tree* children = new Tree;
//				children->node = vert[arc[i].indexEnd];
//				if (child[0] == nullptr)
//				{
//					child.pop_back();
//					child.push_back(children);
//				}
//				else
//				{
//					child.push_back(children);
//				}
//			}
//		}
//	}
//	for (int i = 0; i < child.size(); i++)
//	{
//
//	}
//}
//
//bool Tree::checkBufArc(int indexArc)
//{
//	for (int i = 0; i < bufArc.size(); i++)
//	{
//		if ((bufArc[i].indexEnd == arc[indexArc].indexEnd) && (bufArc[i].indexStart == arc[indexArc].indexStart))
//		{
//			return false;
//		}
//	}
//	return true;
//}
