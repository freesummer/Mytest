///////////////////////////////////// 

// File Name : cluster-based packet classification

// Purpose : optimize packet classification

// Creation Date : 07-09-2015

// Last Modified : <modified_date>

// Created By : Ping Wang 

//////////////////////////////////////
#include <string>
#include <vector>
#include <iostream>
#include <bitset>
#include <fstream>
#include <string>


/////////// Description ///////////////////////////////////////////////////////////////////////////////////////////////
// Program uses a clustering algorithm to divide the multidimention fields into separate subsets
// and then do bitmap intersection lookup between these tables
// the function includes: insert rules, update rules, and matching
// implement arbitrary pattern matching
// performance evaluation: memory space, search time and update time
// tradeoff between memory and time 

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////// Input File Format ////////////////////////////////////////////////////////////////////////////////////////////
// Format:
// <NUMBER OF INSERTIONS(RULES)> <NUMBER OF SEARCHES>
// <ARBITRARY_PATTERN(8 bit stream)> <ACTION>
// ....
// ....
// <8 bit stream for arbitrary match>
// ...
// ...
// Example:
// 5 2

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
void parseWildmask(char ** ruleArray, char * wildMask)
{
        /* Go through each character in the string line and map each char into mask format */
        
        for(int i = 0; i < ruleCount; ++i){
		for(int j = 0; ruleArray[i][j] != '\n'; ++j){
                        if (ruleArray[i][j] == '*') 
                                wildMask[i] = '0'; 
                        else 
                                wildMask[i] = '1';
                }
        }
}


/* Parse the rules into bitmask  */
void parse_bmasks(char ** ruleArray, char * bitMask) 
{
        /* Go through each character in the rules and map each bit into bitset the
         * corresponding bit in the b_mask array to 0 or 1  */
        for(int i = 0; i < ruleCount; ++i){
                for(int j = 0; ruleArray[i][j] != '\n'; ++j){
                        if (ruleArray[i][j] == '0' || ruleArray[i][j]=='*') 
                                        bitMask[i] = '0';
                        if (ruleArray[i][j] == '1')
                                        bitMask[i] = '1';
                }
        }
}


struct ClusterTable
{
	int wildMask[5];
	int bitMask[5];
	int MatchCount;
	ClusterTable(int wildMask, int bitMask, int count)
	{
		
		count = MatchCount;
	}
};


/* Read the rules from an input file  */

int main(int argc, char* argv[])
{
	std::string line;
	std::ifstream policy ("test.txt", std::ifstream::in);
	if (policy.is_open())
	{
		while (policy.good())
		{
			getline(policy,line);
			std::cout << line << std::endl;
		}
		policy.close();
	}
	else
	{
		std::cout << "Unable to open file" << std::endl << std::endl;
	}
	
	
	
	
	
	
	
	
	
}

   







        








