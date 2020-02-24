// CS170 Project1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>
#include "Node.cpp"
#include <set>
#include <ctime>
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
           // cout << i + 1 << " is out of place" << endl;
            //cout << " i = " << i << endl;
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
          //  cout << " j = " << j << endl;
           // cout << "count is " << count << endl;
            total += count;
           // cout << "total is " << total << endl;
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
bool isSame(int puzz1[], int puzz2[]) {     //checks to see if two puzzles are the same
    for (int i = 0; i < 9; i++) {
        if (puzz1[i] != puzz2[i]) {
            return false;
        }
    }
    return true;
}
int getHeuristic(int user, int puzz[]) {
    int h = 0;
    if (user == 1) {            //if user choice is uniform cost
        h = 0;
    }
    if (user == 2) {        //if user choice is A* with misplaced tile heuristic
        h = MisplacedTile(puzz);
    }
    if (user == 3) {        //if user choice is A* with Manhatten dist heuristic
        h = ManhattenDist(puzz);
    }
    return h;
}

bool operator<(const Node& n1, const Node& n2)          //overloaded < operator to compare Node types, returns the lesser value
{
    return (n1.h + n1.depth) > (n2.h + n2.depth);
}
/*
bool operator== (const Node& n1, const Node& n2)
{
    return (n1.m_make == c2.m_make &&
        c1.m_model == c2.m_model);
}
*/
void findPath(Node obj) {
    if (obj.root == 0) {
        findPath(*(obj.parent));
        obj.parent->printPuzzle(obj.puzzle);
    }   
    else {
        obj.parent->printPuzzle(obj.puzzle);
    }
}
void findPath(vector<Node> v) {
    for (int i = v.size() - 1; i >= 0; i--) {
        cout << v.at(i).h << endl;
    }
}
int main()
{
    //static int idcnt = 0;
    Node s;
    s.root = &s;
    int user = 0;           //user choice of which search they want
   // Node p;
    cout << "Enter Numbers for s" << endl;
    for (int i = 0; i < 9; i++) {
        cin >> s.puzzle[i];
       // cout << s.puzzle[i];
    }
    cout << endl;
    s.printPuzzle(s.puzzle);
    cout << "Enter your choice of Algorithm:" << endl;
    cout << "1. Uniform Cost Search" << endl;
    cout << "2. A* with Misplaced Tile heuristic" << endl;
    cout << "3. A* with Manhattan Distance heuristic" << endl;
    cin >> user;
   /*
    cout << "Enter Numbers for p" << endl;
    for (int i = 0; i < 9; i++) {
        cin >> p.puzzle[i];
        // cout << s.puzzle[i];
    } 
    //p.id = ++idcnt;
    //s.id = ++idcnt;
    cout << endl << "P Id: " << p.id << endl;
    cout << endl << "S Id: " << s.id << endl;
    //p.id = ++idcnt;
    cout << endl;
    
    if (isSame(p.puzzle,s.puzzle)) {
        cout << "same puzzle" << endl;
    }
    else {
        cout << "not same puzzle" << endl;
    }
    s.depth = 6;
    s.h = 4;
    p.depth = 6;
    p.h = 3;*/
    priority_queue <Node> q;
    vector<Node> visited;

    //q.push(p);
    q.push(s);
    //visited.push_back(s);
    
    std::clock_t start;
    double duration;

    start = std::clock();
 while (q.size() > 0)
    {
     //cout << "Queue size: " << q.size() << endl;
        Node top = q.top();
        q.pop();
        if (top.root != 0) {
            cout << "Expanding State" << endl;
        }
        else {
            cout << "The best state to expand with a g(n) = " << top.depth << " and h(n) = " << top.h << " is... " << endl;
        }
        top.printPuzzle(top.puzzle);
        
        //cout << " Popping node, depth:" << top.depth << " , h: " << top.h << endl;
        if (top.testGoal(top.puzzle)) {
           cout << "Goal found!" << endl;
           duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
           cout << "Total time taken to complete Search " << duration << " seconds" << endl;
            return 0;
        }
       visited.push_back(top);
       //cout << "Visited list size: " << visited.size() << endl;
        top.index = top.findIndex(top.puzzle);
       // cout << "top index: " << top.index << endl;
        Node r = top.moveRight(top.puzzle, top.index);
       // cout << "R table: " << endl;
        //r.printPuzzle(r.puzzle);
        Node l = top.moveLeft(top.puzzle, top.index);
       // cout << "L table: " << endl;
        //l.printPuzzle(l.puzzle);
        Node u = top.moveUp(top.puzzle, top.index);
        Node d = top.moveDown(top.puzzle, top.index);
        r.depth = top.depth + 1;                                          //increase depth as nodes expand
        //cout << endl <<"node r depth: " << r.depth << endl;
        l.depth = top.depth + 1;
        //cout << "node l depth: " << l.depth << endl;
        u.depth = top.depth + 1;
        //cout << "node u depth: " << u.depth << endl;
        d.depth = top.depth + 1;
        //cout << "node d depth: " << d.depth << endl;
        r.h = getHeuristic(user, r.puzzle);
        //cout << "node r h val: " << r.h << endl;
        l.h = getHeuristic(user, l.puzzle);
        //cout << "node l h val: " << l.h << endl;
        u.h = getHeuristic(user, u.puzzle);
        //cout << "node u h val: " << u.h << endl;
        d.h = getHeuristic(user, d.puzzle);
        //cout << "node d h val: " << d.h << endl;
        r.parent = &top;
        l.parent = &top;
        u.parent = &top;
        d.parent = &top;
       /* cout << endl << "Top puzzle" << endl;
        top.printPuzzle(top.puzzle);

        cout << endl << "R.parent puzzle:" << endl;
        r.printPuzzle(r.parent->puzzle);
        */
        
        if (isNotZeros(r.puzzle) == true) {
           //cout << " R is not zero " << endl;
           int rcount = 0;
           
           for (unsigned int i = 0; i < visited.size(); i++) {
                if (isSame(visited.at(i).puzzle, r.puzzle) == true) {
                    int rh = r.depth + r.h;
                    //cout << "R h+g = " << rh << endl;
                    int currh =  visited.at(i).depth + visited.at(i).h;
                    //cout << "curr h+g = " << currh << endl;
                    if (rh < currh) {
                        //cout << "pushing in r to queue" << endl;
                        q.push(r);
                        //cout << " Pushing in node, depth:" << r.depth << " , h: " << r.h << endl;
                        break;
                    }
                }
                else {
                    rcount++;
                }
                
            }
           //cout << "Rcount = " << rcount << endl;
           if (rcount == visited.size()) {
               q.push(r);
             //  cout << " Pushing in node, depth:" << r.depth << " , h: " << r.h << endl;
           } 
        } 
       
        
        if (isNotZeros(l.puzzle) == true) {
           //q.push(l);
           
          // cout << " L is not zero " << endl;
           int lcount = 0;
           //q.push(l);
           //cout << "Q size after pushing in l" << endl;
           
           for (unsigned int i = 0; i < visited.size(); i++) {
            //   cout << "Visited Puzzle(s): " << endl;
              // visited.at(i).printPuzzle(visited.at(i).puzzle);
               //cout << endl;
               
               if (isSame(visited.at(i).puzzle, l.puzzle) == true) {
                   int lh = l.depth + l.h;
                //   cout << "L h+g = " << lh << endl;
                   int currh = visited.at(i).depth + visited.at(i).h;
                //   cout << "curr h+g = " << currh << endl;
                   if (lh < currh) {
                       q.push(l);
                   //    cout << " Pushing in node, depth:" << l.depth << " , h: " << l.h << endl;
                       break;
                   }
               }
               else {
                   lcount++;
               }
               
           }
          // cout << "Lcount = " << lcount << endl;
           if (lcount == visited.size()) {
               q.push(l);
            //   cout << " Pushing in node, depth:" << l.depth << " , h: " << l.h << endl;
           }  
        }
       if (isNotZeros(u.puzzle) == true) {
           int ucount = 0;
           for (unsigned int i = 0; i < visited.size(); i++) {
               if (isSame(visited.at(i).puzzle, u.puzzle) == true) {
                   int uh = u.depth + u.h;
                   int currh = visited.at(i).depth + visited.at(i).h;
                   if (uh < currh) {
                       q.push(u);
                      // cout << " Pushing in node, depth:" << u.depth << " , h: " << u.h << endl;
                       break;
                   }
               }
               else {
                   ucount++;
               }

           }
           if (ucount == visited.size()) {
               q.push(u);
              // cout << " Pushing in node, depth:" << u.depth << " , h: " << u.h << endl;
           }
       }
       if (isNotZeros(d.puzzle) == true) {
           int dcount = 0;
           for (unsigned int i = 0; i < visited.size(); i++) {
               if (isSame(visited.at(i).puzzle, d.puzzle) == true) {
                   int dh = d.depth + d.h;
                   int currh = visited.at(i).depth + visited.at(i).h;
                   if (dh < currh) {
                       q.push(d);
                    //   cout << " Pushing in node, depth:" << d.depth << " , h: " << d.h << endl;
                       break;
                   }
               }
               else {
                   dcount++;
               }

           }
           if (dcount == visited.size()) {
               q.push(d);
              // cout << " Pushing in node, depth:" << u.depth << " , h: " << u.h << endl;
           }
       }
       
       
 }
 //cout << "Exiting loop" << endl;
     return 0; 
}
