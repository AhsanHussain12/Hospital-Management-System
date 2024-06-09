#include<iostream>
#include<string>
#include<cstdlib> 
#include<string.h>
#include<conio.h>
#include <Windows.h>
#include <unistd.h>
#include<iomanip>
#include<iostream>
#include<conio.h>
#include<ctime>
#include"classes.h"
using namespace std;
int display(){
	int check,i;
	system("cls");
    cout<<"\n\n";
	cout<<"\t\t\t\t";
	for(i=0;i<50;i++){
	cout<<"\xcd";
	}
	cout<<"\n";

   cout<<"\n\n\t\t\t\t\t  |-- HOSPITAL MANAGEMENT SYSTEM --|";

    cout<<"\n\n\n";
	cout<<"\t\t\t\t";
	for(i=0;i<50;i++){
	cout<<"\xcd";
	}
    cout<<"\n\n";
	for(i=0;i<50;i++){
	cout<<"-";
	}	
	cout<<"\n\n";

cout<<"  * [1] Patient Entry\n";
cout<<"  * [2] Admin Access\n";
cout<<"  * [3] Make Donation\n";
cout<<"  * [0] Exit\n";
	cout<<"\n";
	for(i=0;i<50;i++){
	cout<<"-";
	} 
	cout<<"\n\n Selection:... ";
	cin>>check;
	
	cout<<"\n\n\n";
	system("cls");
		return check;
}

int main(){
	system("color 73");
	int entry,i;
	entry=display();

	while(entry!=0){
	
	switch(entry){
		case 1:
		{
			Patient obj1;
			obj1.patient_arrive();	
		}
			break;
		case 2:{
			
			Admin obj2;
			int x,verify;
			
			verify=obj2.check_pass();
			if(verify==-1){
			x=obj2.admin_options();
			while(x!=0){
			switch(x){
				case 1:
					system("cls");
					obj2.readpatient();
					break;
				case 2:
					system("cls");
					obj2.readdonaters();
					break;
				case 3:
					system("cls");
					obj2.readstaff();
					break;
				case 4:
					system("cls");
					obj2.addstaff();
					break;			
				}
				x=obj2.admin_options();
			  }
			}
				else	{	break;	}
			}
			break;
		
		case 3:
			{
				Philanthropist obj3;
				obj3.philanthropist_arrive();
				
			}
	
			break;
			
		default:
			return 0;
			break;
		}
	cout<<"\n\n\n";	
//	system("pause");
	entry=display();

	}
}
