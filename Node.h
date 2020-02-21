#pragma once
#include <list>
class Node
{
public:
	//list <Node> children; // list of all children of current node
	int* parent;		//parent node
	int* up;
	int* down;
	int* right;
	int* left;
	int puzzle[9] = {};		//8 puzzle

	//void Node(int puzz[]);	//node constructor
	void makePuzzle(int puzz[]); // set the puzzle by passing in user defined puzzle and size
	bool testGoal(); // test to see if the current node is the goal state
	
	//Expanding the nodes:
	/*int* moveRight(int puzz[], int index);
	int* moveLeft(int puzz[], int index);
	int* moveUp(int puzz[], int index);
	int* moveDown(int puzz[], int index); */
	void copyPuzzle(int puzz[], int puzz2[]);
	void printPuzzle(int puzz[]);
};

