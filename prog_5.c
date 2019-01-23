// header files
#include <stdio.h>
#include "stringUtils.h"

/*
Function name: main
Algorithm: driver to test getStringlength function
Preconditoin: none
Postcondition: return zero on success
Exceptions: none
Note: demonstraits development and use of a string length function
*/

int main()
{

// init functions/varaibles
	// create test string
	char testStr[] = "Every Good Boy Does Fine";
	// declare other vars
	int strLen;

	char destStr[ STD_STR_LEN ];

	int compareResult = 0;
//display title
	// function: printf()
	printf( "\n String Length Test Program\n" );
	printf( "===========================\n\n" );
// conduct string length test
	// function: getStringLength()
	strLen = getStringLength( testStr );
// displsy result to user
	// function: printf()
	printf( "The length of the string \'%s\' is %d\n\n", testStr, strLen );
	
// test copyString
	copyString( destStr, testStr );

	printf( "\nThe string \'%s\' was correctly copied\n", destStr );
// test concationateString
	concatenateString( destStr, " In Major Keys" );

	printf( "\nThe string \'%s\' was correctly concatenated\n\n", destStr );

//test compareString
	compareResult = compareString( "Susan", "Bill" );

	printf( "The difference between Susan and Bill is %d\n\n", compareResult );

	compareResult = compareString( "Anya", "Meghan" );

	printf( "The difference between Anya and Meghan is %d\n\n",
			compareResult );

	compareResult = compareString( "Will", "William" );

	printf( "The difference between Will and William is %d\n\n",
			compareResult );

// test getSubString
	getSubString( destStr, destStr, 20, 32 );

	printf( "The substring \'%s\' was generated\n\n", destStr );

// test findSubString
	int subStrIndex = findSubString( destStr, "ne In Ma" );

// test 
// shut down
	// return success

    return 0;
}
