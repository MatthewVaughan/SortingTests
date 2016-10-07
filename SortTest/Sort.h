// CS2420 Programming Project #04
// Copyright 2014, Utah Valley University
//Author: Matthew Vaughan
// Date last modified: Oct 2016
// Header file for main - constants and function prologues
// =================================================

/*I Matthew Vaughan have not used any code other than my own(or that in the textbook)
for this project.I also have not used any function or data - structure from
the Standard - Template Library.I understand that any violation of this
disclaimer will result in a 0 for the project.*/
#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

#pragma once
class Sort
{
private:
	int* data;
	int size;

public:
	Sort(int sizeArray);
	~Sort();
	void set_seed(int seed);
	void init_array();
	void selectionSort();
	void insertionSort();
	

	friend ostream& operator<< (ostream& out, const Sort& s)
	{
		for (int i = 0; i < s.size; i++)
		{
			out << s.data[i] << "\t";
		}
		return out;
	}
};

