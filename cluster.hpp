//*****************************************************************
// Cluster.hpp
// 
//
// Created by Ping Wang on July 10, 2015.
//
// This header file contains the cluster table class declaration.
// 
//*****************************************************************
 

 

 
//*****************************************************************
// 
//*****************************************************************
class ClusterTable
{

public:
// Constructs the empty Table object.


table_dim (uint64_t table_d, uint64_t table_len);

// Adds an item to the cluster Table.

void insertItem( Item * newItem );







};
 
//#endif
 
//*****************************************************************
// End of File
//***************************************************************** 
