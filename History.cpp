#include "History.h"
#include <iostream>
using namespace std;

void clearScreen();
char nth_letter(int n);

History::History(int nRows, int nCols) : m_nHRow(nRows), m_nHColumn(nCols)
{
	for (int i = 0; i < nRows; i++)
		for (int j = 0; j < nCols; j++)
			m_nKill[i][j] = 0;
}

bool History::record(int r, int c)
{
	if (r <= 0 || c <= 0 || r > m_nHRow || c > m_nHColumn)
		return false;
	else
	{
		m_nKill[r-1][c-1]++;
		return true;
	}
}


void History::display() const
{
	char grid[MAXROWS][MAXCOLS];
	int dr, dc;

	// Fill the grid
	for (dr = 0; dr < m_nHRow; dr++)
	{
		for (dc = 0; dc < m_nHColumn; dc++)
		{
			int dk = m_nKill[dr][dc];
			if (dk == 0)
				grid[dr][dc] = '.';

			// Mark the required point
			else
				grid[dr][dc] = nth_letter(dk);
		}
	}

	// Draw the grid
	clearScreen();
	for (dr = 0; dr < m_nHRow; dr++)
	{
		for (dc = 0; dc < m_nHColumn; dc++)
			cout << grid[dr][dc];
		cout << endl;
	}

	cout << endl;
}