// CS170 Project1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>
#include "Node.cpp"
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


int main()
{
    //int* p;
    //p = shitfunction();
    //shit p;
    Node s;
    for (int i = 0; i < 9; i++) {
        cout << "enter  number" << endl;
        cin >> s.puzzle[i];
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
    cout << MisplacedTile(s.puzzle) << endl;
    /*
    for (int i = 0; i < 3; i++) {
       cout << s.data[i] << " ";
    }
    
    //shit p;
    //p.parent = s;
    //p.data = 1;
    priority_queue <pair<int, shit> > q;
    q.push(make_pair(0, s));
    vector <pair<int, shit>> v;
    //q.push(make_pair(1, p));
    unsigned int i = 0;
    while ( i < 8) {
        pair<int, shit> poop = q.top();
        q.pop();
        v.push_back(poop);
        shit p;
        for (int j = 0; j < 3; j++) {
            s.data[j] = j;
        }
        //p.parent = &poop;
        q.push(make_pair(i, p));
        i++;
    }
    shit u;
   // u.data = (v.at(0)).first;
    //cout << u << endl;
    u.data[0] = (v.at(0)).second.data[0];
    u.data[1] = (v.at(0)).second.data[1];
    u.data[2] = (v.at(0)).second.data[2];
    cout << u.data[0] << " ";
    cout << u.data[1] << " ";
    cout << u.data[2] << " ";
    
    for (unsigned int k = 0; k < v.size(); k++) {
        for (unsigned int l = 0; l < 3; l++) {
            shit u = get<2>(v.at(k));
            cout << u.data[i]<< " ";
        }
        cout << endl;
    }
    */
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
