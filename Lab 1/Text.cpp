#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include "Text.h"
#include "Config.h"
using namespace std;

//--------------------------------------------------------------------
Text::Text(const char* charSeq)
{
	bufferSize = strlen(charSeq) + 1;
	buffer = new char[bufferSize];
	strcpy(buffer, charSeq);
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
/*
//--------------------------------------------------------------------
Text Text::toUpper() const
{
	// (In-lab 2)  Returns a Text object containing an upper-case copy of Text object.
	{   
	
	}
	Text upper;
	// Option 1: Correct. Create correctly initialized object, and return object reference by   
	// dereferencing new object's address.   
	//return Text( tempBuf );   
	// Option 2: Also correct. Wordier, but perhaps easier for students to follow.   
	return upper;
}

//--------------------------------------------------------------------
Text Text::toLower() const
{
	// (In-lab 2)  Returns a Text object containing a lower-case copy of Text object.
	{   
	
	}   
	Text lower(temp);
	return lower;
}

//--------------------------------------------------------------------
bool Text::operator == (const Text& other) const
{
	// (In-lab 3)  Equality relational operator. Returns true if leftText is equal to
	// other. Otherwise returns false.
	{
		return (strcmp(buffer, other.buffer) == 0);
	}
}

//--------------------------------------------------------------------
bool Text::operator < (const Text& other) const
{
	// (In-lab 3)  Equality relational operator. Returns true if leftText is equal to
	// other. Otherwise returns false.
	{
		return (strcmp(buffer, other.buffer) < 0);
	}
}

//--------------------------------------------------------------------
bool Text::operator > (const Text& other) const
{
	// (In-lab 3)  "Greater than" relational operator. Returns true if leftText is
	// greater than other. Otherwise returns false.
	{
		return (strcmp(buffer, other.buffer) > 0);
	}
}
*/
//--------------------------------------------------------------------
istream& operator >> (istream& input, Text& inputText)
// Text input function. Extracts a string from istream input and
// returns it in inputText. Returns the state of the input stream.
{
	const int textBufferSize = 256; // Large (but finite)
	char textBuffer[textBufferSize]; // text buffer
	// Read a string into textBuffer, setw is used to prevent buffer
	// overflow.
	input >> setw(textBufferSize) >> textBuffer;
	// Apply the Text(char*) constructor to convert textBuffer to
	// a string. Assign the resulting string to inputText using the
	// assignment operator.
	inputText = textBuffer;
	// Return the state of the input stream.
	return input;
}
//--------------------------------------------------------------------
ostream& operator << (ostream& output, const Text& outputText)
// Text output function. Inserts outputText in ostream output.
// Returns the state of the output stream.
{
	output << outputText.buffer;
	return output;
}
