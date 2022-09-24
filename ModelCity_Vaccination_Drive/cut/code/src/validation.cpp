#include <iostream>
#include <iomanip>
using namespace std;
bool aadhar_len(string a)
{
	int len =a.length();
	if(len==6)
        {
                int c = 0;
                for(int i=0;i<len;++i)
                {
                        if(!isdigit(a[i]))
                        {
                                c++;
                                break;
                        }
                }
                if(c>0)
                {
                        cout<<"Invalid entry"<<endl<<"Aadhar Number should contain only digits"<<endl;
                        return false;
                }
                return true;
        }
        else
        {
                cout<<"Invalid Length"<<endl;
                return false;
        }
	return EXIT_SUCCESS;
}

bool age_validation(string age)
{
	int y;
        if(stoi(age) >= 18 && stoi(age) <= 100)
        {
                if (stoi(age) >=35 )
                {
                        cout<<"Clearance from Doctor: "<<endl;
                        cout<<"1.For yes,enter 1"<<endl<<"2.For no,enter 0"<<endl;
                        cin>>y;
                        if(y == 0)
                        {
                                cout<<"Doctor Clearance needed.Registration not completed."<<endl;
                                return 0;
                        }
                }
                return true;
        }
        else
        {
                cout<<"Not for this Age. Registration not completed"<<endl;
                return false;
        }	
	return EXIT_SUCCESS;
}
bool name_validation(string n)
{	
	 int len2 = n.length();
	 if(len2 >= 5 && len2 <= 15 )
         {
                int c = 0;
                for(int i=0;i<len2;++i)
                {
                        if(!isalpha(n[i]))
                        {
                                c++;
                                break;
                        }
                }
                if(c>0)
                {
                        cout<<"Invalid Name"<<endl<<"Name should contain only alphabets"<<endl;
                        return false;
                }
                return true;
        }
	 if(n==" ")
	 {
		 cout<<"Name cannot be Blank"<<endl;
		 return false;
	 }
        else
        {
                cout<<endl<<"Invalid Length"<<endl;
                return false;
        }
	return EXIT_SUCCESS;
}
bool gender_validation(string g)
{
	if(g =="M" || g=="F" || g=="O")
	{
		return true;
	}

	else
	{
		cout<<"Invalid gender"<<endl;
		return false;
	}
	return EXIT_SUCCESS;
}

