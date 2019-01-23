#include "stringUtils.h"

const int MAX_STR_LEN = 200;
const char NULL_CHAR = '\0';
const int STD_STR_LEN = 80;
/*
Function name: getStringLength
Algorithm: find length of input string up to the nul char
Precondition: given C-style string with null char at end
Postcondition: return num of chars from begining to null char
Exceptions: none
Note: limit test loop to max chars for safety
*/
int getStringLength( char *testStr )
{
	int index = 0;
	// init functions and vars
	while( index < MAX_STR_LEN && testStr[ index ] != NULL_CHAR )
	{
		index++;
	}	
	// loop to null char or limit

		// incriment counter index
	
	// end loop

	// return index value	
	return index;
}

/*
Function name: copyString
Algorithm: copies contents of one string into another
Precondition: given a C-style string with a null char at the end
			a destination string is passed in as a paramater with
			enough memory to accept the source string
Postcondition: destination string contains an exact copy of the source
			string
Exceptions: none
Note: limit test loop to max chars for safety
*/
void copyString( char *destination, char *source )
{
	int destIndex = 0;

	int srcIndex = 0;

	while( srcIndex < MAX_STR_LEN && source[ srcIndex ] != NULL_CHAR )
	{
		destination[ destIndex ] = source[ srcIndex ];
	
		srcIndex++, destIndex++;

		destination[ destIndex ] = NULL_CHAR; 
	}
	
}

/*
Function name: concationateString
Algorithm: concatenates or appends contents of one string into the end
		another
Precondition: given a C-style string with a null char at the end, a
			destination string is passed in with enough memory to 
			accept the source string
Postcondition: destination string contains its original string with the
			source string appended or concationated to the end
Exceptions: none
Note: limit test loop to max chars for safety
*/
void concatenateString( char *destination, char *source )
{
	int destIndex = getStringLength( destination );

	int srcIndex = 0;

	while( srcIndex < MAX_STR_LEN && source[ srcIndex ] != NULL_CHAR )
	{
		destination[ destIndex ] = source[ srcIndex ];

		destIndex++, srcIndex++;

		destination[ destIndex ] = NULL_CHAR;
	}
}
/*
Function name: compareString 
Algorithm: compares two stings alphabetically such that:
		if oneStr < otherStr, the function returns a value < 0
		if oneStr > otherStr, the function returns a value > 0
		if oneStr == otherStr, the function returns a 0
		if the two strings are identical up to the point that one is 
		longer the difference in length will be returned
Precondition: given two C-style strings with a null char at the end
Postcondition: integet value is returned as specified
Exceptions: none
Note: limit test loop to max chars for safety
*/
int compareString( char *oneStr, char *otherStr )
{
	int compareResult = 0;
	
	int inStrIndex = 0;

	int oneStrLength = getStringLength( oneStr );

	int otherStrLength = getStringLength( otherStr );

	if( oneStrLength > otherStrLength )
	{
		compareResult = oneStrLength - otherStrLength;
	}

	else if( oneStrLength < otherStrLength )
	{
		compareResult = otherStrLength - oneStrLength;
	}

	while( inStrIndex < oneStrLength && inStrIndex < otherStrLength &&
			compareResult == 0 )
	{
		compareResult = oneStr[ inStrIndex ] - otherStr[ inStrIndex ];

		if( compareResult != 0 )
		{
			inStrIndex = MAX_STR_LEN;
		}

	}

	return compareResult;

}

/*
Function name: getSubString
Algorithm: captures sub string within a larger srting between two
		inclusive indices
Precondition: given C-style string with null char at end and another string
			with enough memory to hold the resulting substring and two
			integers to represent indices
Postcondition: substring is returned as a paramater
Exceptions: empty string is returned if any index paramaters are out
			of range
Note: copy of source string is made internally to protect from alaising
*/
void getSubString( char *destStr, char *sourceStr,
								int startIndex, int endIndex )
{
	char internalCopy[MAX_STR_LEN];
	
	int copyIter = 0;

	int destPosition = 0;

	copyString( internalCopy, sourceStr );

	for( copyIter = startIndex; copyIter <= endIndex; copyIter++ )
	{
		destStr[ destPosition ] = internalCopy[ copyIter ];

		destPosition++;
	}

}

/*
Function name: findSubString
Algorithm: linear search for given substring within test string
Precondition: given C-style string with null char at end
Postcondition: index of substring location returned or
			SUBSTRING_NOT_FOUND
Exceptions: none
Note: 
*/
int findSubString( char *testStr, char *searchStr )
{
	char foundSubString[ MAX_STR_LEN ];

	int shiftIter = 0;

	int endIndex = getStringLength( searchStr );

	while( testStr[ endIndex ] != '\0' )
	{
		getSubString( foundSubString, testStr, shiftIter, endIndex );

		if( compareString( foundSubString, searchStr ) == 1 )
		{
			return 1;
		}
		else
		{
			shiftIter += 1;

			endIndex += 1;
		}
	}
	return 0;
}

/*
Function name: setStrToLowerCase
Algorithm: iterates through string, set all upper case letters to
		lower case without changing any other chars
Precondition: given C-style string with null char at end and
			a destinaton string paramater with enough memory to 
			hold the lower case string
Postcondition: all upper case letters in given string are set to
			lower case; no change to any other chars
Exceptions: Limit on string loop in case incorrect string format
Note: copy of string is made internally to protect from alaising
*/
void setStrToLowerCase( char *destStr, char *sourceStr )
{

}
