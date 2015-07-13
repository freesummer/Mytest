//*****************************************************************
// Cluster.hpp
// 
//
// Created by Ping Wang on July 10, 2015.
//
// This header file contains the cluster table class declaration.
// 
//*****************************************************************
 

#ifndef CLUSTER_H_
#define CLUSTER_H_

 
//*****************************************************************
// 
//*****************************************************************
class ruleMapping

{
public:

	void parseBitmask();
	void parseWildmask();
}

class clusterTable
{

public:

	void insertBitmask();
	void insertWildmask();
	void updateRule();

};

void matchRule();




 
#endif
 
//*****************************************************************
// End of File
//***************************************************************** 
