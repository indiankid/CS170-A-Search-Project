// CS170 Project1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>
#include "Node.cpp"
#include <set>
using namespace std;

//finds the number of misplaced tiles       ---works
int MisplacedTile(int puzz[]) {
    int count = 0;
    for (int i = 0; i < 8; i++) {
        if (puzz[i] != (i + 1)) {
            count++;
        }
    }
    return count;
}

int ManhattenDist(int puzz[]) {
    int total = 0;

    for (int i = 0; i < 8; i++) {
        if (puzz[i] != (i + 1)) {
            int count = 0;
            cout << i + 1 << " is out of place" << endl;
            cout << " i = " << i << endl;
            int j;
            for (j = 0; j < 9 ; j++) {
                if (puzz[j] == i + 1) {
                    if ((abs(i - j) == 3)) {        //if i or j are directly above each other/ below each other
                        count = 1;
                    }




                    else if ((i % 3 == 1) || (j % 3 == 1)) {    //if one is middle
                        if ((i % 3 == 1) && (j % 3 == 1)) {
                            if ((abs(i - j) == 6)) {
                                count = 2;
                            }
                        }
                        else if (i % 3 == 1) {       //if i is mid
                            if (j % 3 == 2) {       //if j is right
                                if ((j == 2) && i == 4) {
                                    count = 2;
                                }
                                else if ((j == 5) && i == 7) {
                                    count = 2;
                                }
                                else if ((j == 8) && i == 1) {
                                    count = 3;
                                }
                                else {
                                    count = (abs(i - j) / 2) + (abs(i - j) % 2);
                                }
                            }

                            else if (j % 3 == 0) {       //if j is left
                                if ((j == 3) && i == 1) {
                                    count = 2;
                                }
                                else if ((j == 6) && i == 4) {
                                    count = 2;
                                }
                                else if ((j == 0) && i == 7) {
                                    count = 3;
                                }
                                else {
                                    count = (abs(i - j) / 2) + (abs(i - j) % 2);
                                }
                            }
                        }
                        if (j % 3 == 1) {       //if j is mid
                            if (i % 3 == 2) {       //if j is right
                                if ((i == 2) && j == 4) {
                                    count = 2;
                                }
                                else if ((i == 5) && j == 7) {
                                    count = 2;
                                }
                                else if ((i == 8) && j == 1) {
                                    count = 3;
                                }
                                else {
                                    count = (abs(i - j) / 2) + (abs(i - j) % 2);
                                }
                            }

                            else if (i % 3 == 0) {       //if i is left
                                if ((i == 3) && j == 1) {
                                    count = 2;
                                }
                                else if ((i == 6) && j == 4) {
                                    count = 2;
                                }
                                else if ((i == 0) && j == 7) {
                                    count = 3;
                                }
                                else {
                                    count = (abs(i - j) / 2) + (abs(i - j) % 2);
                                }
                            }
                        }
                    }


                    else {
                        if (i == 6 && j == 2) {
                            count = 4;
                        }
                        else if (i == 8 && j == 0) {
                            count = 4;
                        }
                        else if (j == 6 && i == 2) {
                            count = 4;
                        }
                        else if ((abs(j - i)) % 2 == 0) {
                            count = 2;
                        }
                        
                        else if ((j + 1 == i) || (j - 1 == i)) {
                            count = 3;
                        }
                        
                        else {
                            count = (abs(i - j) / 2) + (abs(i - j) % 2);
                        }
                    }
                    break;
                }
                
            }
            cout << " j = " << j << endl;
            cout << "count is " << count << endl;
            total += count;
            cout << "total is " << total << endl;
        }
    }
    return total;
}
bool isNotZeros(int puzz[]) {           //check to see if the puzzle is all zeros
    bool notzero = true;
    int count = 0;
    for (int i = 0; i < 2; i++) {
        if (puzz[i] == 0) {
            count++;
        }
    }
    if (count > 1) {
        notzero = false;
    }
    return notzero;
}
bool operator<(const Node& n1, const Node& n2)
{
    return (n1.h + n1.depth) > (n2.h + n2.depth);
}
int main()
{
    //int* p;
    //p = shitfunction();
    //shit p;
    Node s;
    cout << "Enter Numbers" << endl;
    for (int i = 0; i < 9; i++) {
        cin >> s.puzzle[i];
       // cout << s.puzzle[i];
    }
    cout << endl;
    s.printPuzzle(s.puzzle);
    cout << s.findIndex(s.puzzle) << endl;
    Node p;
    cout << endl;
    p = s.moveRight(s.puzzle, s.findIndex(s.puzzle));
    p.printPuzzle(p.puzzle);
    cout << endl;
    p = s.moveLeft(s.puzzle, s.findIndex(s.puzzle));
    p.printPuzzle(p.puzzle);
    cout << endl;
    p = s.moveUp(s.puzzle, s.findIndex(s.puzzle));
    p.printPuzzle(p.puzzle);
    cout << endl;
    p = s.moveDown(s.puzzle, s.findIndex(s.puzzle));
    p.printPuzzle(p.puzzle);
    cout << endl;
    cout << "Misplaced " << MisplacedTile(s.puzzle) << endl;
    cout << "Manhatten " << ManhattenDist(s.puzzle) << endl;
    
    if (p.testGoal(p.puzzle) == true) {
        cout << " hey its the same" << endl;
    }
    else {
        cout << "nope not the same" << endl;
    }
    p.depth = 0;
    p.h = 3;
    priority_queue <Node> q;
    vector<Node> visited;
    //set<Node>::iterator it;
        //pair <int, int*> q_top = make_pair(0, p.puzzle);
    q.push(p);
    visited.push_back(p);
   //if (visited.at(0).h == p.h ){
    //   cout << visited.at(0).h << endl;
     //  cout << p.h << endl;
   //}
   //cout << &p << endl;
    //cout << " pushed " << endl;
     //q.pop();
    //cout << "popped" << endl;
    /*
 while (q.size() > 0)
    {
        Node top = q.top();
        q.pop();
        if (top.testGoal(top.puzzle)) {
            //q.pop();
            //TODO 
            cout << " find the path " << endl;
        }
        visited.insert(top);
        top.index = top.findIndex(top.puzzle);
        Node r = top.moveRight(top.puzzle, top.index);
        Node l = top.moveLeft(top.puzzle, top.index);
        Node u = top.moveUp(top.puzzle, top.index);
        Node d = top.moveDown(top.puzzle, top.index);

        if (isNotZeros(r.puzzle) == true) {
            if (visited.find ) {

            }
        }


    }   */
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
