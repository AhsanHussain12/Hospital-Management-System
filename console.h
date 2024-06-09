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
using namespace std;
class console{
	
	public:
		int d,m,y;
		int hr,min,sec;
		console(){
			SYSTEMTIME stime;
			GetSystemTime(&stime);
			d=stime.wDay;
			m=stime.wMonth;
			y=stime.wYear;	
			hr=stime.wHour;
			min=stime.wMinute;
			sec=stime.wSecond;
		}
		void load(){
				for (int i=0;i<2;i++){
				cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t";	
   			 	cout<<"Processing Info ";
    			for(int j=0;j<5;j++){
         			cout<<".";
         			sleep(1);
        	     }
        		system("cls");
    		  }
			}

};
