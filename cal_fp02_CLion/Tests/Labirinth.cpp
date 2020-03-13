/*
 * labirinth.cpp
 */

#include "Labirinth.h"

#include <iostream>
using namespace std;



Labirinth::Labirinth(int values[10][10])
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			labirinth[i][j] = values[i][j];
}


void Labirinth::initializeVisited()
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			visited[i][j] = false;
}




void  Labirinth::printLabirinth()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			cout << labirinth[i][j] << " ";

		cout << endl;
	}
}


bool Labirinth::findGoal(int x, int y)
{
    solved = false;
    initializeVisited();
    search(x,y);
    return solved;
}


void Labirinth::search(int x, int y) {
    if (solved) return;

    if (visited[x][y]) return;
    else visited[x][y] = true;


    if (x >=10 || x < 0 || y >= 10 || y < 0) return; //out of bounds

    if (labirinth[x][y] == 0) return;

    if (labirinth[x][y] == 2) {
        solved = true;
        return;
    }


    search(x+1, y);
    search(x-1,y);
    search(x,y+1);
    search(x,y-1);
}

//A eficiencia temporal do algoritmo será O(n^2)