//#include "Node.h"
#include <iostream>
using namespace std;
class Node {
public:
	Node* parent = 0;		//parent node
	Node* root = 0;
	/*int* up;
	int* down;
	* right;
	Node* left;
	*/
	int puzzle[9] = {};		//8 puzzle
	int depth = 0;				//depth in tree
	int h = 0;					//heuristic
	int index = 0;				//where the blank is
	int id;
	/*
	Node::Node(int puzz[])
	{
	}
	*/
	void makePuzzle(int puzz[])
	{
		for (int i = 0; i < 9; i++) {
			puzzle[i] = puzz[i];
		}
	}

	int findIndex(int puzz[]) {						//works
		for (int i = 0; i < 9; i++) {				//finds the index of the array where the 0 is
			if (puzz[i] == 0) {
				return i;
			}
		}
		return 0;
	}
	bool testGoal(int puzz[])
	{
		for (int i = 0; i < 8; i++) {
			if (puzz[i] != (i + 1) ) {
				return false;
			}
		}

		return true;
	}


	//check to see if index holding 0 is in any row of the rightmost columns
	Node moveRight(int puzz[], int index)			//works
	{
		Node newpuzz;
		if ((index % 3) < 2) {
			newpuzz.copyPuzzle(newpuzz.puzzle, puzz);
			int temp = newpuzz.puzzle[index + 1];
			newpuzz.puzzle[index + 1] = newpuzz.puzzle[index];
			newpuzz.puzzle[index] = temp;
		}
		return newpuzz;
	}



	// check to see if index holding 0 is in any row of the leftmost column
	Node moveLeft(int puzz[], int index)		//works
	{
		Node newpuzz;
		if ((index % 3) > 0) {
			newpuzz.copyPuzzle(newpuzz.puzzle, puzz);
			int temp = newpuzz.puzzle[index - 1];
			newpuzz.puzzle[index - 1] = newpuzz.puzzle[index];
			newpuzz.puzzle[index] = temp;
		}
		return newpuzz;
	}


	//check to see if index holding 0 is in any column of the top most row
	Node moveUp(int puzz[], int index)			//works
	{
		Node newpuzz;
		if ((index - 3) >= 0) {
			newpuzz.copyPuzzle(newpuzz.puzzle, puzz);
			int temp = newpuzz.puzzle[index - 3];
			newpuzz.puzzle[index - 3] = newpuzz.puzzle[index];
			newpuzz.puzzle[index] = temp;
		}
		return newpuzz;
	}

	//check to see if index holding 0 is in any column of the bottpm most row
	Node moveDown(int puzz[], int index)				//works
	{
		Node newpuzz;
		if ((index + 3) < 9) {
			newpuzz.copyPuzzle(newpuzz.puzzle, puzz);
			int temp = newpuzz.puzzle[index + 3];
			newpuzz.puzzle[index + 3] = newpuzz.puzzle[index];
			newpuzz.puzzle[index] = temp;
		}
		return newpuzz;
	}

	void copyPuzzle(int puzz[], int puzz2[])			//works
	{
		for (int i = 0; i < 9; i++) {
			puzz[i] = puzz2[i];
		}
	}

	void printPuzzle(int puzz[])						//works
	{
		for (int i = 0; i < 9; i++) {
			cout << puzz[i] << " ";
			if ((i % 3) == 2) {						//columns
				cout << endl;
			}

		}
	}
};