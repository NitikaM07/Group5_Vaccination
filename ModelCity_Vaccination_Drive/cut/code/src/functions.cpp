/**********************************************************************************
  *  FILENAME     : functions.cpp
  *  
  *  DESCRIPTION : This file contains all the functions and perform all
  *                designated task.
  *  REVISION HISTORY
  *
  *  DATE             NAME          REASON
  *
  * -----------------------------------------------------
  *
  *  22/09/22         Group-5      Perform Operations
  *
  * ********************************************************************************/
#ifndef FUNC1
#define FUNC1

#include "validation.cpp"	// Include required header files
#include "header.hpp"
#include "file.cpp"
#include <unistd.h>

using namespace std;
string temp,input;	//Global variables declaration
mutex accum_mutex;	//mutex variable declaration


int user :: create_account()
{
	string n2,a4;
	while(1)
	{
		cout<<endl<<"Enter Aadhar Number : ";
		cin>>input;	
		if(aadhar_len(input)==false)	//Function call to aadhar_len function
			continue;

		int flag = 0;

		for(list<user>::iterator it=l1.begin();it!=l1.end();it++)
		{
			if(it->aadhar_no == input)	//check if aadhar number already exists or not
			{
				flag=1;
				break;
			}
		}
		if(flag == 1)
		{
			cout<<"Account with this already exists"<<endl<<"Registration not completed"<<endl;
			return 0;
		}
		else
		{
			u1.aadhar_no=input;
			break;
		}
	}

	while(1)
	{
		cout<<endl<<"Enter your Age : ";
		cin>>input;
		if(age_validation(input)==false)	//Function call to age_validation function
			return 0;
		else
		{
			u1.age=stoi(input);
			break; //should terminate the program.
		}

	}
	while(1)
	{
		cout<<endl<<"Enter your name : ";
		cin>>input;
		if(name_validation(input)==false)	//Function call to name_validation function
			continue;
		else
		{
			u1.name=input;
			break; 
		}
	}
	n2=u1.name.substr(0,2);	//extracting first two characters from string name
	a4=u1.aadhar_no.substr(0,4);	//extracting first 4 characters from aadhar number
	u1.registration_id=n2+a4;	//Generating the Registration ID
	cout<<endl<<"Your Registeration ID is : "<<u1.registration_id<<endl;
	while(1)
	{
		cout<<endl<<"Enter Gender (F/M/O) : ";
		cin>>input;	
		if(gender_validation(input)==false)	//Function call to gender_validation function
			continue;
		else
		{
			u1.gender=input;
			break;
		}
	}
	l1.push_back(u1);	//pushing the user class object into the list

	system("clear");
	return 0;
}


int user :: view_user()	//Function to display Beneficiary details
{
	cout<<aadhar_no<<"\t"<<name<<"\t"<<age<<"\t"<<gender<<"\t"<<shots<<endl;
	return EXIT_SUCCESS;
}


int user :: view_registered_user()	//Function to display Beneficiary details
{
	cout<<aadhar_no<<"\t"<<name<<"\t"<<age<<"\t"<<gender<<"\t"<<centre<<"\t\t"<<time_s<<"\t\t"<<shots<<endl;
	return EXIT_SUCCESS;
}


int user :: view_details()	//Function to display Beneficiary details
{
	string m_aadhar_no;
	if(l1.empty())	//Checks if file is empty or not
	{
		cout<<"Empty File "<<endl;
		return EXIT_FAILURE;
	}
	cout<<"Enter your Aadhar number to view your details: ";
	cin>>m_aadhar_no;	//Accept aadhar number from user
	cout<<endl<<"----------------View Details-----------------"<<endl;
	cout<<endl<<"Aadhar\tName\tAge\tGender\tShots"<<endl;
	int flag=0;
	for(list<user>::iterator it=l1.begin();it!=l1.end();it++)	//Traverse through l1 list
	{
		if(it->get_aadhar()==m_aadhar_no)	//checks if aadhar number is present in list
		{
			it->view_user();	//Function call to display details of the beneficiary
			break;
		}
		else
		{
                       flag=1;
		}
	}
	if(flag==1)
	{
		cout<<"Aadhar number not found"<<endl;
	}
	system("read a");
	system("clear");
	return EXIT_SUCCESS;
}


int user :: select_centre()
{

	string m_aadhar_no=" ";
	cout<<"Enter your aadhar number: ";	//Accept aadhar number from user
	cin>>m_aadhar_no;
	cout<<endl<<endl;
	vector<string> v;
	int choice=0;
	v.push_back("1. Hawkins");
	v.push_back("2. Riverdale");
	v.push_back("3. Central Perk");
	for(string it:v)	//Loop to print contents of vector
	{
		cout<<it<<endl;
	}
	int flag=0;
	list<user> :: iterator it;
	for(it=l1.begin();it!=l1.end();it++)	//Traverse through l1 list
	{

		if(it->get_aadhar()==m_aadhar_no)	//checks if aadhar number is present in list
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
	{
		cout<<endl<<"Select one centre"<<endl;
		cin>>temp;
		try
		{
			choice=stoi(temp);
		}
		catch(exception& ex)
		{
			cout<<endl<<"Exception Occured...Enter only digits"<<endl;
			return 0;
		}

		if(choice==1)	//If choice is Hawkins
		{
			it->centre = "Hawkins";
			cout<<endl<<"Your centre for vaccination drive is succesfully selected"<<endl;
			cout<<endl<<"__________________________________________________________"<<endl;
		}
		else if(choice==2)	//If choice is Riverdale
		{
			it->centre = "Riverdale";
			cout<<endl<<"Your centre for vaccination drive is succesfully selected"<<endl;
			cout<<endl<<"__________________________________________________________"<<endl;
		}
		else if(choice==3)	//If choice is Central Perk
		{
			it->centre = "Central Perk";
			cout<<endl<<"Your centre for vaccination drive is succesfully selected"<<endl;
			cout<<endl<<"__________________________________________________________"<<endl;
		}
		else
		{
			cout<<endl<<"Invalid Choice";
		}
	}
	else
	{
		cout<<endl<<"Aadhar number not found"<<endl;
	}

	lc.push_back(u1);	//Pushing user class object in list
	list<user>l1 (lc);
	
	system("read a");
	system("clear");
	return 0;
}


int user :: book_slot()	//Function for slot booking
{
	string m_aadhar_no;
	int auto_token;
	time_t t1;
	cout<<"Enter your aadhar number: ";
	cin>>m_aadhar_no;	//Accept aadhar number from user
	cout<<endl<<endl;
	int choice;

	vector<string> v;
	list<user>::iterator it;
	for(it=l1.begin();it!=l1.end();it++)	//Loop to traverse through the list
	{
		if(it->get_centre()=="NA")
		{
			cout<<endl<<"Please select your centre first to book the slot"<<endl;
			return 0;
		}
		else
		{
			cout<<endl<<endl<<"**************Book your slot**************"<<endl<<endl;
			v.push_back("1. Morning");
			v.push_back("2. Afternoon");
			for(string it:v)
			{
				cout<<it<<endl;
			}
			cout<<endl<<endl<<"*****************************************"<<endl<<endl;
			if(it->get_aadhar()==m_aadhar_no)	//checks if aadhar number is present in list
			{
				cout<<endl<<"Select one slot: "<<endl;
				cin>>temp;
				try
				{
					choice=stoi(temp);
				}
				catch(exception& ex)
				{
					cout<<endl<<"Exception Occured...Enter only digits"<<endl;
					return 0;
				}
				srand((unsigned) time(&t1)); //generates random unique token no
				auto_token=rand() % 50;	//Generating a random token
				accum_mutex.lock();; //lock mutex object
				cout<<endl<<"YOUR TOKEN FOR BOOKING IS: **"<<auto_token<<"**"<<endl;
				accum_mutex.unlock();; //release mutex object
				cout<<endl<<"PLEASE CONFIRM YOUR TOKEN"<<endl;
				cin>>temp;	//Accept token from user
				try
				{
					it->token=stoi(temp);
				}
				catch(exception& ex)
				{
					cout<<endl<<"Exception Occured...Enter only digits"<<endl;
					return 0;
				}
				if(it->token==auto_token) //checks the token number
				{
					if(choice==1)	//If slot selected is Morning slot
					{
						while(1)
						{
							
							cout<<"Confirm your time between 10 to 12"<<endl;
							cin>>temp;
							try
							{
								it->time_s=stoi(temp);
							}
							catch(exception& ex)
							{
								cout<<endl<<"Exception Occured...Enter only digits"<<endl;
								return 0;
							}
							if(it->time_s<10 || it->time_s>12)	//checks if time slot is in range
							{
								cout<<endl<<"Please enter valid time slot"<<endl;
								continue;
							}
							else
							{
								break;
							}
						}
					}
					if(choice==2)	//If slot selected is Afternoon slot
					{
						while(1)
						{
							cout<<"Confirm your time between 1 to 4"<<endl;
							cin>>temp;
							try
							{
								it->time_s=stoi(temp);
							}
							catch(exception& ex)
							{
								cout<<endl<<"Exception Occured...Enter only digits"<<endl;
								return 0;
							}
							
							if(it->time_s<1 || it->time_s>4)	//checks if time slot is in range
							{
								cout<<endl<<"Please enter valid time slot"<<endl;
								continue;
							}
							else
							{
								break;
							}
						}
					}
				}
				else
				{
					cout<<endl<<"Entered token is wrong. Please recheck your entered token"<<endl;
					return 0;
				}
			}
			else
			{
				cout<<endl<<"Aadhar number not found"<<endl;
				return 0;
			}
			break;
		}
	}
	lc.push_back(u1);
	list<user>l1 (lc);
	cout<<endl<<"Your Vaccination slot is selected successfully"<<endl;
	cout<<endl<<"__________________________________"<<endl;
	if(it->centre=="Hawkins")	//Decreasing the vaccine units on booking slot based on centres
	{
		--ad.vcount1;
	}
	if(it->centre=="Riverdale")
	{
		--ad.vcount2;
	}
	if(it->centre=="Central Perk")
	{
		--ad.vcount3;
	}
	lc2.push_back(ad);
	l2.clear();
	for(list<admin> :: iterator it=lc2.begin();it!=lc2.end();it++)
	{
		l2.push_back(*it);	//pushing the admin class variables into the list using iterator	
	}
	
	system("read a");
	system("clear");
	return 0;
}


int user :: register_details()
{
	string m_aadhar_no;
	if(l1.empty())	//Checks if file is empty or not
	{
		cout<<"Empty File "<<endl;
		return EXIT_FAILURE;
	}
	cout<<"Enter your Aadhar number to view your details: ";
	cin>>m_aadhar_no;	//Accept aadhar number from user
	cout<<endl<<"----------------View Details-----------------"<<endl<<endl;
	cout<<endl<<"Aadhar\tName\tAge\tGender\tCentre\t\tTime slot\tShots"<<endl;
	int flag=0;
	for(list<user>::iterator it=l1.begin();it!=l1.end();it++)
	{
		if(it->get_aadhar()==m_aadhar_no)	//checks if aadhar number is present in the list
		{
			it->view_registered_user();	//Function call to diaplay registered beneficiaries details
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		cout<<endl<<"No Records Available"<<endl;
	}
	system("read a");
	system("clear");
	return EXIT_SUCCESS;
}


int user :: get_vaccinated()
{
	string m_aadhar_no;
	int m_token;
	if(l1.empty())	//check if file is empty or not
	{
		cout<<"Empty File "<<endl;
		return EXIT_FAILURE;
	}
	cout<<"Enter your Aadhar number: ";
	cin>>m_aadhar_no;
	for(list<user>::iterator it=l1.begin();it!=l1.end();it++)
	{
		if(it->get_time()==0 || it->get_centre()=="NA")	//condition to check if centre and slot is booked
		{
			cout<<endl<<"Please select a centre and time slot first to get vaccinated"<<endl;
			break;
		}
		else
		{
			if(it->get_aadhar()==m_aadhar_no)	//Checks if aadhar number is present in list
			{
				if(it->get_shots()>=3)	//Checks if shots are completed
				{
					cout<<endl<<"You have already completed your 3 doses"<<endl;
					return 0;
				}
				else
				{
					cout<<endl<<"PLEASE CONFIRM YOUR TOKEN"<<endl;
					cin>>temp;
					try
					{
						m_token=stoi(temp);
					}
					catch(exception& ex)
					{
						cout<<endl<<"Exception Occured...Enter only digits"<<endl;
						return 0;
					}
					if(it->token==m_token) //checks the token number
					{
						++it->shots;	//increase the shot count
						cout<<endl<<"***********Congratulations on getting vaccinated**********"<<endl;
						cout<<endl<<"You have completed "<<it->shots<<" doses"<<endl;
						break;
					}
					else
					{
						cout<<endl<<"Entered token is wrong"<<endl;
						return 0;
					}
				}
			}
		}
	}
	lc.push_back(u1);	//pushing user class object into the list
	list<user>l1 (lc);

	return 0;
}


string user :: get_aadhar()	//Function to Fetch aadhar number
{
	return this->aadhar_no;
}
string user :: get_centre()	//Function to Fetch centre
{
	return this->centre;
}

int user :: get_shots()		//Function to Fetch shots
{
	return this->shots;
}
int user :: get_time()		//Function to Fetch time
{
	return this->time_s;
}

int admin :: show_bene_data()	//Function to display all the details of beneficiary
{
	if(l1.empty())	//Checks if file is empty or not
	{
		cout<<"Empty File "<<endl;
		return EXIT_FAILURE;
	}
	cout<<endl;
	cout<<endl<<"Aadhar\tName\tAge\tGender\tCentre\t\tTime slot\tShots"<<endl<<endl;
	for(list<user>::iterator it=l1.begin();it!=l1.end();it++)	//Loop to traverse through the list
	{
		it->view_registered_user(); //Function call to display registered user details
	}
	system("read a");
	system("clear");
	return 0;
}


int admin :: add_vaccine_stock()	// This function is used to  add vaccine stock 
{
	int choice,add=0;
	vector<string> v1;
	v1.push_back("1. Hawkins");
	v1.push_back("2. Riverdale");
	v1.push_back("3. Central Perk");
	for(string it:v1)
	{
		cout<<it<<endl;
	}
	cout<<endl<<"Select the slot in which you want to add vaccine stock: "<<endl;
	cin>>temp;
	try
	{
		choice=stoi(temp);
	}
	catch(exception& ex)
	{
		cout<<endl<<"Exception Occured...Enter only digits"<<endl;
		return 0;
	}
	for(list<admin> :: iterator it=l2.begin();it!=l2.end();it++)	//loop to traverse through th list
	{

		if(choice==1)	//If choice is Hawkins
		{
			cout<<"\n\t\t-->>For Center 1<<--"<<endl; 
			cout<<endl<<"Vaccine in Center *"<<ad.centre1<<"* are: "<<it->vcount1<<endl; 

			cout<<"\n\tEnter Number of vaccines you want to add: "; 
			cin>>temp; 
			try
			{
				add=stoi(temp);
			}
			catch(exception& ex)
			{
				cout<<endl<<"Exception Occured...Enter only digits"<<endl;
				return 0;
			}

			accum_mutex.lock();	//lock mutex object
			it->vcount1=it->vcount1+add;	//Adding vaccine in centre 3
			accum_mutex.unlock(); 	//Release mutex object
			cout<<endl<<"......Adding........"<<endl;
			sleep(2);
			cout<<endl<<endl<<"Vaccines added to the center"<<endl;
		}
		if(choice==2)	//If Choice is Riverdale
		{
			cout<<"\n\t\t-->>For Center 2<<--"<<endl; 
			cout<<endl<<"Vaccine in Center *"<<ad.centre2<<"* are: "<<it->vcount2<<endl; 
			cout<<"\n\tEnter Number of vaccines you want to add: "; 
			cin>>temp; 
			try
			{
				add=stoi(temp);
			}
			catch(exception& ex)
			{
				cout<<endl<<"Exception Occured...Enter only digits"<<endl;
				return 0;
			}
			accum_mutex.lock();	//lock mutex object
			it->vcount2=it->vcount2+add; 	//Adding vaccine in centre 2
			accum_mutex.unlock(); 	//Release mutex object
			cout<<endl<<"......Adding........"<<endl;
			sleep(2);
			cout<<endl<<"Vaccines added to the center"<<endl;
		}
		if(choice==3)	//If choice is Central Perk
		{
			cout<<"\n\t\t-->>For Center 3<<--"<<endl; 
			cout<<endl<<"Vaccine in Center *"<<ad.centre3<<"* are: "<<it->vcount3<<endl; 
			cout<<"\n\tEnter Number of vaccines you want to add: "; 
			cin>>temp; 
			try
			{
				add=stoi(temp);
			}
			catch(exception& ex)
			{
				cout<<endl<<"Exception Occured...Enter only digits"<<endl;
				return 0;
			}
			accum_mutex.lock();	//lock mutex object
			it->vcount3=it->vcount3+add; //Adding vaccine in centre 3
			accum_mutex.unlock(); 	//Release mutex object
			cout<<endl<<"......Adding........"<<endl;
			sleep(2);
			cout<<endl<<"Vaccines added to the center"<<endl;
			system("read");
		}
	}
	system("clear");
	return 0;
}



int admin :: get_vaccine_stock()	// This function fetches the available vaccines in all 3 centres
{
	cout<<centre1<<"\t\t\t"<<vcount1<<endl;
	cout<<centre2<<"\t\t"<<vcount2<<endl;
	cout<<centre3<<"\t\t"<<vcount3<<endl;
	return EXIT_SUCCESS;
}


int admin :: display_vaccine_stock()	// This function displays the available vaccines in all the location
{
	if(l2.empty())	//Checks if file is empty or not
	{
		cout<<"Empty File "<<endl;
		return 0;
	}
	cout<<endl<<endl<<"_____________________________"<<endl<<endl;
	cout<<endl<<endl<<"Centre"<<"\t\t"<<"Vaccine Count"<<endl;
	for(list<admin>::iterator it=l2.begin();it!=l2.end();it++)	//loop to display vaccine stock
	{
		it->get_vaccine_stock();	//Function call to diaplay vaccine stock
	}
	cout<<endl<<"_____________________________"<<endl<<endl;
	system("read a");
	system("clear");
	return EXIT_SUCCESS;

}


int admin :: delete_fully_vaccinated()	// This function is used to remove the details of specified beneficiaries 
{
	int flag=0;
	if(l1.empty())	//Checks if list is empty
	{
		printf("\nEmpty Records\n");
		return 0;
	}
	string  m_aadhar_no;
	cout<<endl<<"\t\t----------------Delete Fully Vaccinated Beneficiary-----------------"<<endl<<endl;
	cout<<endl<<"Enter the Aadhar number whose record you want to delete:";
	cin>>m_aadhar_no;
	for(list<user>::iterator it=l1.begin();it!=l1.end();it++)
	{	
		if(it->get_aadhar()==m_aadhar_no)	//Checking if entered aadhar number is present in list
		{
			if(it->get_shots()==3)	//Condition to check if all three shots are completed
			{

				it=l1.erase(it);	//delete the record
				flag=1;
				break;
			}
			else
			{
				cout<<endl<<endl<<"This beneficiary has not completed his all doses."<<endl<<"----You cannot delete this record.----"<<endl;
				return 0;
			}
		}
	}
	if(flag==1)
	{
		cout<<"The record of aadhar number deleted succesfully"<<endl;
	}
	else
	{
		cout<<endl<<"Beneficiary with aadhar number "<<m_aadhar_no<<" does not exit"<<endl;
	}
	system("read a");
	return EXIT_SUCCESS;
}


int admin :: non_vaccinated()	// This function is used to show not vaccinated beneficiaries
{
	if(l1.empty())	//checks if file is empty
	{
		cout<<endl<<"Empty Records"<<endl;
		return 0;
	}
	cout<<endl<<"\t\t----------------Display Not Vaccinated Beneficiary-----------------"<<endl<<endl;
	cout<<endl<<"Aadhar\tName\tAge\tGender\tCentre\t\tTime slot\tShots"<<endl<<endl;
	int flag=0;
	list<user> :: iterator it;
	for(it=l1.begin();it!=l1.end();it++)
	{
		if(it->get_shots()==0)	//checks if number of shots are zero
		{
			it->view_registered_user(); //calls function to display details of beneficiary
			flag=1;	
		}
	}
	if(flag==0)
	{
		cout<<endl<<"No Records found"<<endl;
	}
	system("read a");
	system("clear");
	return EXIT_SUCCESS;
}


int admin :: fully_vaccinated()	// This function shows fully vaccinated beneficiaries
{
	if(l1.empty())	//checks if file is empty or not
	{
		cout<<endl<<"Empty Records"<<endl;
		return 0;
	}
	cout<<endl<<"\t\t----------------Display Fully Vaccinated Beneficiary-----------------"<<endl<<endl;
	cout<<endl<<"Aadhar\tName\tAge\tGender\tCentre\t\tTime slot\tShots"<<endl<<endl;
	int flag=0;
	list<user> :: iterator it;
	for(it=l1.begin();it!=l1.end();it++)
	{
		if(it->get_shots()==3)
		{
			it->view_registered_user();	//calls function to display details of beneficiary
			flag=1;
		}
	}
	if(flag==0)
	{
		cout<<endl<<"No Records found"<<endl;
	}
	
	system("read a");
	system("clear");
	return EXIT_SUCCESS;
}


int admin :: today_vaccinated()	// This function displays beneficiaries who are vaccinated today
{
	if(l1.empty())
	{
		cout<<"Empty File "<<endl;
		return 0;
	}
	cout<<endl;
	cout<<endl<<"\t\t----------------Display Beneficiary Vaccinated Today-----------------"<<endl<<endl;
	cout<<endl<<"Aadhar\tName\tAge\tGender\tCentre\t\tTime slot\tShots"<<endl<<endl;
	int flag=0;
	list<user> :: iterator it;
	for(it=l1.begin();it!=l1.end();it++)
	{
		if(it->get_shots()>0)
		{
			it->view_registered_user();	//calls function to display details of beneficiary
			flag=1;
		}
		
	}
	if(flag==0)
	{
		cout<<endl<<"No Records found"<<endl;
	}
	
	system("read a");
	system("clear");
	return EXIT_SUCCESS;
}

#endif
