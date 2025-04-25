#pragma once

#include<iostream>
using namespace std;

class Stack
{
	char*arr;
	int maxSize;
	int currSize;

public:
	Stack(const int = 0);

	void push(const char);
	char pop();

	bool full() const;
	bool empty() const;

	~Stack();
};