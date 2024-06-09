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
class Doctor{
	protected:
	string name;
	string type;
	public:
	virtual int get_cons_time()=0;
	string getname(){
		return name;
	}
	string gettype(){
		return type;
	}
};

class Dental: public Doctor{

	public:
	static int dental_token;
		Dental(){
			name="Aslam";
			type="Dental";	
		}
		int get_cons_time(){
			
			for(int i=0;i<120;i++){cout<<"-";}
			cout<<"\n\t\t\t\tDoctor Aslam << Dentist >>"<<endl;
			cout<<"\nAvailable from --->\t\t||4 pm - 6 pm||"<<endl;
			cout<<"\n\n";
			 ++dental_token;
			cout<<"\nToken No: "<<dental_token;
			cout<<"\n\n\n";
			system("Pause");
			system("cls");
			 return dental_token;
		}

		
};
int Dental::dental_token=0;

class Orthopedic:public Doctor{
	public:
	static int ortho_token;
		Orthopedic(){
			name="Ashfaq";
			type="Orthopedic";	
		}
		int get_cons_time(){
			for(int i=0;i<120;i++){cout<<"-";}
			cout<<"\n\t\t\t\tDoctor Ashfaq << Orthopedic >>"<<endl;
			cout<<"\nAvailable from --->\t\t||7 pm - 9 pm||"<<endl;
			cout<<"\n\n";
			++ortho_token;
			cout<<"\nToken No: "<<ortho_token;
			cout<<"\n\n\n";
			system("Pause");
			system("cls");
			 
			 return ortho_token;
		}
	
};
int Orthopedic::ortho_token=0;

class Neurologist:public Doctor{
	public:
	static int neuro_token;
		Neurologist(){
			name="Khwaja ";
			type="Neurologist";	
		}
		int get_cons_time(){
			for(int i=0;i<120;i++){cout<<"-";}
			cout<<"\n\t\t\t\tDoctor Khawaja << Neurologist >>"<<endl;
			cout<<"\nAvailable from --->\t\t||7 pm - 9 pm||"<<endl;
			 ++neuro_token;
			cout<<"\nToken No: "<<neuro_token;
			cout<<"\n\n\n";
			system("Pause");
			system("cls");
			 return neuro_token;
		}
	
};
int Neurologist::neuro_token=0;






