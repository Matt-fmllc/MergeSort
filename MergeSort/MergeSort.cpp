// MergeSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>


void Merge(char* _pString, char* _pOutString, int _iStart, int _iMiddle, int _iEnd)
{
	int i, j, k;
	i = _iStart;
	k = 0;
	j = _iMiddle + 1;

	// Merge the two parts into outputstring
	// go through each one and compare 
	while (i <= _iMiddle && j <= _iEnd){
		if (_pString[i] < _pString[j]){
			_pOutString[k] = _pString[i];
			k++;
			i++;
		} else {
			_pOutString[k] = _pString[j];
			k++;
			j++;
		}
	}
	// Insert all the remaining values from i to mid into outputstring
	for (int x = i; x <= _iMiddle; x++) {
		_pOutString[k++] = _pString[x];
	}
	for (int x = j; x <= _iEnd; x++) {
		_pOutString[k++] = _pString[x];
	}
	// Copy back into array
	for (i = _iStart; i <= _iEnd; i++){
		_pString[i] = _pOutString[i - _iStart];
	}
}

void Sort(char* _pString, char* _pOutString, int _iStart, int _iEnd)
{
	int iMiddle = 0;
	if (_iStart < _iEnd) {
		iMiddle = (_iStart + _iEnd) / 2;
		Sort(_pString, _pOutString, _iStart, iMiddle);
		Sort(_pString, _pOutString, iMiddle + 1, _iEnd);
		Merge(_pString, _pOutString, _iStart, iMiddle, _iEnd);
	}
}

bool MergeSort(char* _pInputString, char* _pOutputString, int _iCount)
{
	printf("\nInput Array = \"%s\"", _pInputString);
	printf("\nOutput Array = \"%s\"", _pOutputString);
	printf("\nSorting...");

	Sort(_pInputString, _pOutputString, 0, _iCount -1 );

	printf("\nInput Array = \"%s\"", _pInputString);
	printf("\nOutput Array = \"%s\"", _pOutputString);

	return true;
}

void MergeV2_int(int pInput[], int pOutput[], int iStart, int iMiddle, int iEnd)
{
	int x = iStart;
	int y = 0;
	int z = iMiddle + 1;

	while (x <= iMiddle && z <= iEnd) {
		if (pInput[x] < pInput[z]) {
			pOutput[y++] = pInput[x++];
		}
		else {
			pOutput[y++] = pInput[z++];
		}
	}
	for (int i = x; i <= iMiddle; i++) {
		pOutput[y++] = pInput[i];
	}
	for (int i = z; i <= iEnd; i++) {
		pOutput[y++] = pInput[i];
	}
	for (int i = iStart; i <= iEnd; i++) {
		pInput[i] = pOutput[i - iStart];
	}
}

void SortV2_int(int pInput[], int pOutput[], int iStart, int iEnd)
{
	int iMiddle = 0;
	if (iStart < iEnd) {
		iMiddle = (iStart + iEnd) / 2;
		SortV2_int(pInput, pOutput, iStart, iMiddle);
		SortV2_int(pInput, pOutput, iMiddle + 1, iEnd);
		MergeV2_int(pInput, pOutput, iStart, iMiddle, iEnd);
	}

}

bool MergeSort_int(int pInput[], int pOutput[], int iCount)
{
	// output the arrays
	printf("\nInput array: ");
	for (int x = 0; x < iCount; x++) {
		printf("%d, ", pInput[x]);
	}
	printf("\nSorting...");

	SortV2_int(pInput, pOutput, 0, iCount-1);

	printf("\nSorted Array: ");
	for (int x = 0; x < iCount; x++) {
		printf("%d, ", pInput[x]);
	}

	return true;
}


int main()
{
	char InputArray[] = "This is the string to sort";
//	char InputArray[] = "dbca";
	char OutputArray[sizeof(InputArray) / sizeof(char)] = { 0 };
	int nNumChars = sizeof(InputArray) / sizeof(char);

	printf("\nNum of Chars = %d", nNumChars);

	bool bRetVal = MergeSort(InputArray, OutputArray, nNumChars-1);

	int iInput[] = { 1, 5, 3, 4, 2, 7, 6 };
	int iOutput[sizeof(iInput) / sizeof(int)] = { 0 };
	int iCount = sizeof(iInput) / sizeof(int);

	bRetVal = MergeSort_int(iInput, iOutput, iCount); 

	return 1;
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
