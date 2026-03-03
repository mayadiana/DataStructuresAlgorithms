#include "Matrix.h"
#include <exception>
using namespace std;
#include <iostream>


Matrix::Matrix(int nrLines, int nrCols) {
	nrL = nrLines;
	nrC = nrCols;
	capacity = 10; //setez o capacitate initiala pt values si lineIndex
	size = 0; //initial => consideram ca nu avem elemente = 0
	values = new TElem[capacity]; //initializam vectorul pe baza capacitatii initiale
	lineIndex = new int[capacity]; //la fel ca mai sus
	columnPointer = new int[nrC + 1](); //aloc memorie pt columnPointer cu nrColoane + 1, initializate cu 0
}
//BC = Theta(1)
//WC = Theta(nrCols)
//TC = O(nrCols)

Matrix::~Matrix() {
	delete[] values;
	delete[] lineIndex;
	delete[] columnPointer;
}
//BC = WC = TC = Theta(1)

int Matrix::nrLines() const {
	return nrL;
}
//BC = WC = TC = Theta(1)

int Matrix::nrColumns() const {
	return nrC;
}
//BC = WC = TC = Theta(1)

TElem Matrix::element(int i, int j) const {
	if (i < 0 || i >= nrL || j < 0 || j >= nrC)
		throw exception();
	//Traversam vectorul de valori cu ajutorul vectorului columnPointer
	for (int k = columnPointer[j]; k < columnPointer[j + 1]; k++) 
	{
		//daca lineIndex-ul e acelasi cu i => am gasit elementul si il returnam
		if (lineIndex[k] == i)
			return values[k];
	}
	return NULL_TELEM;
}
//BC = Theta(1)
//WC = Theta(non-zero elemente din coloana j)
//TC = O(non-zero elemente din coloana j)

void Matrix::resize() 
{
	capacity *= 2;
	//Aloc noi vectori cu capacitatea noua (dublata)
	TElem* newValues = new TElem[capacity];
	int* newLineIndex = new int[capacity];
	//Copiez elementele existente in vectorii noi
	for (int i = 0; i < size; i++)
	{
		newValues[i] = values[i];
		newLineIndex[i] = lineIndex[i];
	}
	//Sterg vectorii folositi initiali si ii reinitializez cu noile valori
	delete[] values;
	delete[] lineIndex;
	values = newValues;
	lineIndex = newLineIndex;
}
//BC = Theta(1)
//WC = Theta(size)
//TC = O(size)

TElem Matrix::modify(int i, int j, TElem e) {
	if (i < 0 || i >= nrL || j < 0 || j >= nrC)
		throw exception();

	//Traversam vectorul de valori cu ajutorul vectorului columnPointer
	for (int k = columnPointer[j]; k < columnPointer[j + 1]; k++) 
	{
		//Daca dam de elementul cautat:
		if (lineIndex[k] == i) 
		{
			TElem oldValue = values[k];
			//Si valoarea cu care vrem sa il inlocuim e 0 => ii dam remove
			if (e == 0) 
			{
				for (int l = k; l < size - 1; l++) 
				{
					values[l] = values[l + 1];
					lineIndex[l] = lineIndex[l + 1];
				}
				size--;
				for (int l = j + 1; l <= nrC; l++)
					columnPointer[l]--;
			}
			//Daca e diferita de 0 => ii facem update la valoare
			else 
				values[k] = e;
			return oldValue;
		}
	}

	if (e != 0) 
	{
		//Daca noua valoare e diferita de 0 => inseram in vector
		if (size == capacity)
			resize();
		int pos = columnPointer[j + 1];
		for (int k = size; k > pos; k--) 
		{
			values[k] = values[k - 1];
			lineIndex[k] = lineIndex[k - 1];
		}
		values[pos] = e;
		lineIndex[pos] = i;
		size++;
		for (int l = j + 1; l <= nrC; ++l)
			columnPointer[l]++;
	}

	return NULL_TELEM;
}
//BC = Theta(1)
//WC = Theta(size) 
//TC = O(size)


void Matrix::transpose()
{
	Matrix matrix(4, 4);

	//Adaug elementele din matricea originala in noua matrice, le transpun
	for (int j = 0; j < nrC; j++)
	{
		for (int k = columnPointer[j]; k < columnPointer[j + 1]; k++) 
		{
			int i = lineIndex[k];
			matrix.modify(j, i, values[k]);
		}
	}

	//Afisez matricea noua
	for (int i = 0; i < nrC; i++) 
	{
		for (int j = 0; j < nrL; j++) 
			cout << matrix.element(i,j) << " ";
		cout << endl;
	}
}
//BC = Theta(1)
//WC = Theta(non-zero elemente din coloana j)
//TC = O(non-zero elemente din coloana j)


