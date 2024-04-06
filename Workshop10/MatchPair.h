/***********************************************************************
// OOP244 Workshop 10 p1: Book module header file
//
// File: MatchPair.h
// Version 1.0
// Date: April 06, 2024
// Author: Pattarawan Saravaneeyawong
// Description:
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SENECA_MATCHPAIR_H
#define SENECA_MATCHPAIR_H

template <typename type1, typename type2>
struct Pair {
	type1 first{};
	type2 second{};
};

template<typename T, typename U>
void addDynamicPairElement(Pair<T, U>*& pArray, const T& first, const U& second, int& size) {
	Pair<T, U>* temp = new Pair<T, U>[size + 1];
	for (int k = 0; pArray && k < size; k++) {
		temp[k] = pArray[k];
	}
	temp[size].first = first;
	temp[size].second = second;
	delete[] pArray;
	pArray = temp;
	size++;
}

template<typename type1, typename type2>
Pair<type1, type2>* matches(type1 arr1[], type2 arr2[], int size1, int size2, int& size3)
{
	Pair<type1, type2>* pt = nullptr;
	int i, j;

	size3 = 0;

	pt = new Pair<type1, type2>[size3];

	for (i = 0; i < size1; i++) {
		for (j = 0; j < size2; ++j) {
			if (arr1[i] == arr2[j]) {
				addDynamicPairElement(pt, arr1[i], arr2[j], size3);
			}
		
		}
	}

	return pt;
}

template <typename type1>
void releaseMem (type1* arr) {
	delete[] arr;
}

#endif // !SENECA_MATCHPAIR_H
