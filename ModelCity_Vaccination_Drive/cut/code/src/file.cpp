/**********************************************************************************
  *  FILENAME     : file.c
  *  
  *  DESCRIPTION : The file.cpp contains all list to file and file to list
  *                  function and perform all designated tasks.
  *
  *  REVISION HISTORY
  *
  *  DATE             NAME          REASON
  *
  * -----------------------------------------------------
  *
  *  22/09/22        Group-5       Perform File Related Operations
  *
  * ********************************************************************************/
#include "header.hpp" // Required header file
using namespace std;

int reg_list_to_file()		//For inserting records in Registered file from list
{
	fl.open("Registered_file",ios::out | ios::binary);	//opening the file in binary mode
	for (list<user> :: iterator t = l1.begin();t!=l1.end();t++)
	{
		fl.write((char *) &t, sizeof(user));	//Writing in file
	}
	fl.close();	//Closing the file
	return 0;
}
int reg_file_to_list()	//Inserting records from file to list
{
{
	user u;
	fl2.open("Registered_file",ios::in | ios::binary);	//Opening a binary file for reading
	if(!fl2)
	{
		cout<<"File can't open"<<endl;
		return EXIT_FAILURE;
	}
	else
	{
		int temp = sizeof(u);
		fl2.read((char *) &u, temp);	//reading file
		while(!fl2.eof())	
		{
			l1.push_back(u);	//after reading data from file , inserting into the linked list
			fl2.read((char *) &u, temp);	//reading file
		}
		fl2.close();	//closing the file
	}
	return EXIT_SUCCESS;
}
int vaccine_list_to_file()
{
	fl.open("Vaccine_file",ios::out | ios::binary);	//opening the file in binary mode
	for (list<admin> :: iterator t = l2.begin();t!=l2.end();t++)
	{
		fl.write((char *) &t, sizeof(admin));	//Writing in file
	}
	fl.close();	//closing the file
	return 0;
}
int vaccine_file_to_list()	//Inserting records from Vaccine file to list
{
	admin ad;	
	fl2.open("Vaccine_file",ios::in | ios::binary);	
	if(!fl2)
	{
		cout<<"File can't open"<<endl;
		return EXIT_FAILURE;
	}
	else
	{
		int temp = sizeof(ad);
		fl2.read((char *) &ad, temp);	//reading file
		while(!fl2.eof())
		{
			l2.push_back(ad);	//after reading data from file , inserting into the linked list
			fl2.read((char *) &ad, temp);	//reading file
		}
		fl2.close();	//closing the file
	}
	return EXIT_SUCCESS;
}
