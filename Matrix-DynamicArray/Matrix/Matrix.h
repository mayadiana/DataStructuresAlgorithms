#pragma once

//DO NOT CHANGE THIS PART
typedef int TElem;
#define NULL_TELEM 0

class Matrix {

private:
	int nrL, nrC;
	int capacity; //Capacitatea valorilor + lineIndex
	int size; //Nr actual de elemente != 0
	TElem* values; //Aici retinem elementele != 0
	int* lineIndex; //Vector de retinut inidicii liniilor cu valori != 0
	int* columnPointer; //Vector pt indicii la coloane

	//cand capacitatea e full => facem resize la volori + lineIndex
	void resize();

	
	
public:
	//constructor
	Matrix(int nrLines, int nrCols);

	//destructor
	~Matrix();

	//returns the number of lines
	int nrLines() const;

	//returns the number of columns
	int nrColumns() const;

	//returns the element from line i and column j (indexing starts from 0)
	//throws exception if (i,j) is not a valid position in the Matrix
	TElem element(int i, int j) const;

	//modifies the value from line i and column j
	//returns the previous value from the position
	//throws exception if (i,j) is not a valid position in the Matrix
	TElem modify(int i, int j, TElem e);

	void transpose();
};
