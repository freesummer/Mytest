///////////////////////////////////// 

// File Name : wildcard matching

//////////////////////////////////////
#include <string>
#include <vector>
#include <iostream>
#include <bitset>
#include <fstream>
#include <string>
#include <iterator>
#include <algorithm>


using namespace std;

/////////// Description ///////////////////////////////////////////////////////////////////////////////////////////////
// Program maps the arbitrary wildcard rules (includes '0', '1', and '*') into two different parts: bitMask, and wildMask.
// bitMask: parse the '*' and '0' into '0', the '1' into '1'.
// wildMask: parse the '*' into '0', the '0' and '1' into '1'.
// ruleMatch: Bool (Incoming packet && wildMask == bitMask), if true, then match, if false, don't match
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////// Input File Format ////////////////////////////////////////////////////////////////////////////////////////////
/* Rules  */
// *11*0110 drop
// **1010** port1
// 0011*110 port2
// 0011010* port3
// 10101100 port4

/* Incoming packets  */
// 01110110
// 10001010

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 

#define ruleCount 5



struct rules
{
	int n;		/* number of rules */
	int b;		/* width of rule pattern */

};



/* Parse the rules into wildmask   */
void parseWildmask(char** ruleArray, char** wildMask)
{
        /* Go through each character in the string line and map each char into wildmask */
        
        for(int i = 0; i < ruleCount; ++i){
		for(int j = 0; ruleArray[i][j] != '\n'; ++j){
                        if (ruleArray[i][j] == '*') 
                                wildMask[i][j] = '0'; 
                        else 
                                wildMask[i][j] = '1';
                }
        }
}


/* Parse the rules into bitmask  */
void parseBitmasks(char** ruleArray, char** bitMask) 
{
        /* Go through each character in the rules and map each bit into bitmask*/
        for(int i = 0; i < ruleCount; ++i){
                for(int j = 0; ruleArray[i][j] != '\n'; ++j){
                        if (ruleArray[i][j] == '0' || ruleArray[i][j]=='*') 
                                        bitMask[i][j] = '0';
                        if (ruleArray[i][j] == '1')
                                        bitMask[i][j] = '1';
                }
        }
}

/*   */


int main(int argc, char* argv[])
{

/* Read the rules from an input file  */
	string line;
	ifstream file ("test.txt");
	
	string ruleArray[5];

	int i = 0;
 	if(file.is_open()) {
	
      	while(!file.eof()) {
			getline(file, line);  /*  Read lines as long as the file is */
			ruleArray[i] = line;
			i++;
		}

	}

	file.close();

	for(int j = 0; ruleArray[j] != "\0"; j++) {
		cout << ruleArray[j] << endl;  /* get the ruleArray information */
	}

	int row = 5;        // number of rules
	int length = 50;    // the length of each rule
	char **wildMask = new char* [row];
	for(int i = 0; i < row; ++i) 
			wildMask[i] = new char[50];


	void parseWildmask(char** ruleArray, char** wildMask);

	cout << wildMask[i] << endl;

	char **bitMask = new char* [row];
	for(int i = 0; i < row; ++i) 
			bitMask[i] = new char[50];
	
	void parseBitmasks(char** ruleArray, char** bitMask);

	cout << bitMask[i] << endl;


	

	return 0;	
}

   







        








