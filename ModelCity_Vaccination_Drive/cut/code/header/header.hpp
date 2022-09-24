#ifndef H_HEADER
#define H_HEADER
#include <iostream>
#include <iomanip>
#include <list>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cctype>
#include <vector>
#include <thread>
#include <mutex>


using namespace std;

class user
{
	protected:
		string aadhar_no;
		string name;
		string gender;
		string centre;
		string registration_id;
		int time_s;
		int age;
		int shots;
		int token;
	public:
		// User Corner
		void new_user();
		void registered_user();
		int create_account();
		int view_details();
		int view_user();
		int view_registered_user();
		int select_centre();
		int book_slot();
		int register_details();
		int get_vaccinated();
		string get_aadhar();
		string get_centre();
		int get_shots();
		int get_time();
		int morning_slot(int);
		int afternoon_slot(int);
		friend class admin;

		user()
		{
			time_s=0;
			age=0;
			shots=0;
			token=0;
			centre="NA";
		}
};
class admin
{
	protected:
		string centre1;
		string centre2;
		string centre3;
		int vcount1;
		int vcount2;
		int vcount3;
	public:
		//Admin Corner
		int show_bene_data();
		int add_vaccine_stock();
		int display_vaccine_stock();
		int get_vaccine_stock();
		int delete_fully_vaccinated();
		int non_vaccinated();
		int fully_vaccinated();
		int today_vaccinated();
		friend class user;

		admin()
		{
			centre1="Hawkins";
			centre2="Riverdale";
			centre3="Central Perk";
			vcount1=10;
			vcount2=5;
			vcount3=15;
		}
};
class vaccination : public user,public admin
{
	public:
		void menu();
		void user_login();
		void admin_login();
};

int reg_list_to_file();
int reg_file_to_list();
int vaccine_list_to_file();
int vaccine_file_to_list();
user u1;
admin ad;
fstream fl;
fstream fl2;
list<user> l1;
list<user> lc;
list<admin> l2;
list<admin> lc2;
#endif
