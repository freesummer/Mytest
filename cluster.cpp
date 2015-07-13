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
// *11*0110 drop
// **1010** port1
// 0011*110 port2
// 0011010* port3
// 10101100 port4
// 01110110
// 10001010

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
#define rule_count 5

struct RuleTable
{
	int q_maskrules[5];
	int b_maskrules[5];
	int MatchCount;
	RuleTable(int q_mask, int b_mask, int count)
	{
		q_mask = q_maskrules[5];
                b_mask = b_maskrules[5];
		count = MatchCount;
	}
};

struct rule
{
	int n;		/* number of rules */
	int b;		/* width of rule pattern */

};



/* Parse the rules into maskrules   */
void parse_qmasks(char ** rule_array, char * q_masks)
{
        /* Go through each character in the string line and map each char into mask format */
        
        for(int i = 0; i < rule_count; ++i){
		for(int j = 0; rule_array[i][j] != '\n'; ++j){
                        if (rule_array[i][j] == '*') 
                                q_masks[i] = '0'; 
                        else 
                                q_masks[i] = '1';
                }
        }
}


/* Parse the rules into bitrules  */
void parse_bmasks(char ** rule_array, char * b_masks) 
{
        /* Go through each character in the rules and map each bit into bitset the
         * corresponding bit in the b_mask array to 0 or 1  */
        for(int i = 0; i < rule_count; ++i){
                for(int j = 0; rule_array[i][j] != '\n'; ++j){
                        if (rule_array[i][j] == '0' || rule_array[i][j]=='*') 
                                        b_masks[i] = '0';
                        if (rule_array[i][j] == '1')
                                        b_masks[i] = '1';
                }
        }
}





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

char ** rule_array = char * line[10];

/* Convert the * to 0 / 1  */
	char * t1 = new char[8];
        //parse_qmasks(* rule_array, t1);
	char * t2 = new char[8];
	//parse_bmasks(** rule_array, t2);


	
/* convert the string rules to bit rules  */       


       
      		
}







        








