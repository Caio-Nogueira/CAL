/*
 * Sudoku.cpp
 *
 */

#include "Sudoku.h"

/** Inicia um Sudoku vazio.
 */
Sudoku::Sudoku()
{
	this->initialize();
}

/**
 * Inicia um Sudoku com um conteúdo inicial.
 * Lança excepção IllegalArgumentException se os valores
 * estiverem fora da gama de 1 a 9 ou se existirem números repetidos
 * por linha, coluna ou bloc 3x3.
 *
 * @param nums matriz com os valores iniciais (0 significa por preencher)
 */
Sudoku::Sudoku(int nums[9][9])
{
	this->initialize();

	countFilled = 0;

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (nums[i][j] != 0)
			{
				int n = nums[i][j];
				numbers[i][j] = n;
				lineHasNumber[i][n] = true;
				columnHasNumber[j][n] = true;
				block3x3HasNumber[i / 3][j / 3][n] = true;
				countFilled++;
			}
		}
	}
}

void Sudoku::initialize()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			for (int n = 0; n < 10; n++)
			{
				numbers[i][j] = 0;
				lineHasNumber[i][n] = false;
				columnHasNumber[j][n] = false;
				block3x3HasNumber[i / 3][j / 3][n] = false;
			}
		}
	}

	this->countFilled = 0;
}

/**
 * Obtem o conteúdo actual (só para leitura!).
 */
int** Sudoku::getNumbers()
{
	int** ret = new int*[9];

	for (int i = 0; i < 9; i++)
	{
		ret[i] = new int[9];

		for (int a = 0; a < 9; a++)
			ret[i][a] = numbers[i][a];
	}

	return ret;
}

/**
 * Verifica se o Sudoku já está completamente resolvido
 */
bool Sudoku::isComplete()
{
	return countFilled == 9 * 9;
    //return findEmpty().first == 10 && findEmpty().second == 10;
}



/**
 * Resolve o Sudoku.
 * Retorna indicação de sucesso ou insucesso (sudoku impossível).
 */
bool Sudoku::solve()
{


	if (isComplete()) return true;

	pair <int, int> pos = findEmpty();

	for (int i = 1; i < 10; i++){
	    if (this->isValid(i, pos.first, pos.second)){
	        numbers[pos.first][pos.second] = i;
	        countFilled++;
	        lineHasNumber[pos.first][i] = true;
	        columnHasNumber[pos.second][i] = true;
	        block3x3HasNumber[pos.first/3][pos.second/3][i] = true;

	        if (solve()) return true;

            //number previously filled doesnt lead to the correct solution -> backtrack

            numbers[pos.first][pos.second] = 0;
            lineHasNumber[pos.first][i] = false;
            columnHasNumber[pos.second][i] = false;
            block3x3HasNumber[pos.first/3][pos.second/3][i] = false;
            countFilled--;
	    }
	}
	return false;

}



/**
 * Imprime o Sudoku.
 */
void Sudoku::print()
{
	for (int i = 0; i < 9; i++)
	{
		for (int a = 0; a < 9; a++)
			cout << this->numbers[i][a] << " ";

		cout << endl;
	}

}

bool Sudoku::isValid(int number, int row, int col) {
    if (lineHasNumber[row][number]) return false;

    if (columnHasNumber[col][number]) return false;

    if (block3x3HasNumber[row/3][col/3][number]) return false;

    return true;
}


pair<int, int> Sudoku::findEmpty() {
    pair<int, int> result;

    for (int row = 0; row < 9; row++){
        for (int col = 0; col < 9; col++){
            if (numbers[row][col] == 0){
                result.first = row;
                result.second = col;
                return result;
            }
        }
    }
    result = {10, 10};
    return result;
}