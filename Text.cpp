#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include "Text.h"
using namespace std;

//--------------------------------------------------------------------
Text::Text(const char* charSeq)
{
	bufferSize = strlen(charSeq) + 1; //accounts for null
	try {
		buffer = new char[bufferSize];	//memory allocator
	}
	catch (bad_alloc & e) {
		cerr << "Text::Text(const char): bad_alloc: buffer == 0\n";
		throw bad_alloc();
	}

	strcpy(buffer, charSeq); //string copier
}

//--------------------------------------------------------------------
Text::Text(const Text& other)
{
	bufferSize = other.bufferSize;
	buffer = new char[bufferSize];
	strcpy(buffer, other.buffer);
}

//--------------------------------------------------------------------
void Text::operator = (const Text& other)
{
	int len = other.bufferSize;
	if (len > bufferSize)
	{
		delete[] buffer;
		bufferSize = other.bufferSize;
		buffer = new char[bufferSize];
	}
	strcpy(buffer, other.buffer);
}

//--------------------------------------------------------------------
Text::~Text()
{
	delete[] buffer;
}

//--------------------------------------------------------------------
int Text::getLength() const
{
	return strlen(buffer);
}

//--------------------------------------------------------------------
char Text::operator [] (int n) const
{
	// check if n is out of range first
	if (n >= 0 && n < getLength()) {
		return buffer[n];
	}
	return 0;
}

//--------------------------------------------------------------------
void Text::clear()
{
	buffer[0] = '\0';
}

//--------------------------------------------------------------------
void Text::showStructure() const
// Outputs the characters in a string. This operation is intended for
// testing/debugging purposes only.
{
	int j; // Loop counter
	for (j = 0; j < bufferSize; j++)
		cout << j << "\t";
	cout << endl;
	for (j = 0; buffer[j] != '\0'; j++)
		cout << buffer[j] << "\t";
	cout << "\\0" << endl;
}

