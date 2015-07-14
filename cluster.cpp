///////////////////////////////////// 

// File Name : wildcard matching

//////////////////////////////////////
#include <string>
#include <vector>
#include <iostream>
#include <bitset>
#include <fstream>
#include <string>

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
                                wildMask[i][i] = '0'; 
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


/* Read the rules from an input file  */

int main(int argc, char* argv[])
{
	std::string line;
	std::ifstream policy ("test.txt", std::ifstream::in);
	vector<string> lines;    // a vector container
	if (policy.is_open())
	{
		while (policy.good())
		{
			getline(policy,line);
			std::cout << line << std::endl;
			lines.push_back(line);
		}
		policy.close();
	}
	else
	{
		std::cout << "Unable to open file" << std::endl << std::endl;
	}
	
/* pass the data from input file to the original rule table.  */	

	int row = 5;        // number of rules
	int length = 50;    // the length of each rule
	char** ruleArray = new char* [row];
	for(int i = 0; i < row; ++i) 
			ruleArray[i] = new char[50];
	

	for(int j = 0; j < row; ++j) 
		for(int i = 0; lines[j][i] != '\n'; ++i) 
			ruleArray[j][i] = lines[j][i];
			
	

	
}

   







        








