// classes //
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
class Person{
	protected:
		string name,address;
		char gender;
		int age;
		double con_info;
		int id;
		
		public:
			static int incr;
			Person(){	}
			
		virtual	void getData(){				
				cout<<"Name: "; cin>>name;
				cout<<"Age: ";  cin>>age;
				while(1){
				cout<<"Gender[M/F]: "; cin>>gender;
				if(gender=='M'||gender=='F'||gender=='m'||gender=='f'){break;}
				}
				fflush(stdin);
				cout<<"Address "; getline(cin,address);
				fflush(stdin);
				cout<<"Contact Number : +92-"; cin>>con_info;
				id=100;	
			srand(con_info);
			id=id+incr+(rand ()%6)+1;
			incr+=9;	
			}

		////SETTERS//////
		void setname(string name){ this->name=name; }
		void setaddress(string address){ this->address=address; }
		void setname(double coninfo){ this->con_info=coninfo; }	
		//////GETTERS///////	
		int getid(){ return id;	}
		double getcon_info(){	return con_info;	}
		string getname(){  return name;  }
		string getaddress(){	return address;  }
};
int Person::incr=10;

class Blood_group{
	
	string list_group[6];
	string BG;
	public:
		Blood_group(){
			list_group[0]="A+";	  list_group[1]="B+";
			list_group[2]="AB+";  list_group[3]="AB-";
			list_group[4]="O+";	  list_group[5]="O-";

		}
		bool checkBG(){
			int i,entry=0;
			
			while(entry!=3){
			cout<<"Blood Group(*Upper Case Only*): "; cin>>BG;	
			++entry;
			for(i=0;i<6;i++){	if(BG==list_group[i]){return true;}	  }
		    }
		    return false; 
        }
		string getBG(){	return BG;	}   
		
};

class console{
	
	public:
		int d,m,y;
		
		console(){
			SYSTEMTIME stime;
			GetSystemTime(&stime);
			d=stime.wDay;
			m=stime.wMonth;
			y=stime.wYear;	
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


class Patient:public Person{
	private:
	string allergies;
	string prev_diseases;
	string PBG;
	char type;
	public:
		Patient(){

		}
		void getData(){  
			Person::getData();
			Blood_group blood_obj;
			if(	blood_obj.checkBG()==1){PBG=blood_obj.getBG();}
			else{	PBG="Unspecified";	}
			fflush(stdin);
		    cout<<"Allergies(if any):....... "; getline(cin,allergies);
		    fflush(stdin);
		    cout<<"Medical Condition(if any):...... "; getline(cin,prev_diseases);
		}
		void patient_arrive(){  // 1st call func in main()
			system("cls");
				while(1){
				cout<<"Emergency------>[E]"<<endl;
				cout<<"Consultation--->[C]"<<endl;
				cin>>type;
				if(type=='E'||type=='e'||type=='C'||type=='c'){break;}
				}
				if(type=='E'||type=='e'){
					Emergency();
				}else if(type=='C'||type=='c'){
					Consultation();
				}
		}
		void Emergency(){
			console S1;
			system("cls");
			cout<<"||Our Staff will be with you Shortly||"<<endl;  // in the center
    		Beep(500,3000);
			cin.get();
			system("cls");
			// If file Exist // then No get DATA
			cout<<"|| Kindly Fill in the Patitent Info ||"<<endl<<endl;
			getData();
			system("cls");
			S1.load(); // in the center
    	}
			void Consultation(){
			int select;
			cout<<"[1]Dental\n[2]Orthopedic\n[3]Neurologist"<<endl;
			cin>>select;
			// If file Exist // then No get DATA
			// Else Get DATA// 
			switch(select){
			
				case 1:
					{
					Dental A;
					Doctoken=A.get_cons_time();
					Doctype=A.gettype();
					break;
					}
				case 2:
				{
					Orthopedic B;
					Doctoken=B.get_cons_time();
					Doctype=B.gettype();
					break;	
					}
				case 3:
				{
					Neurologist C;
					Doctoken=C.get_cons_time();
					Doctype=C.gettype();
					break;	
				}
			}

		//////SETTERS///////////
		void setdiseases(string disease){ prev_diseases=prev_diseases+""+disease;	}
		void setallergies(string allergy){ allergies=allergies+""+allergy;	}
		//////GETTERS///////////
		string getPBG(){	return PBG;	} 
		string getdisease(){	return prev_diseases; 	}
		string getallergy(){	return allergies; 	}
};


class Philanthropist:public Person{
	protected:
	
	float don_amnt;
	string source;
	public:
		static int incre;
		void getData(){
			Person::getData();
			cout<<"Enter Donation Amount: ";
			cin>>don_amnt;
			cout<<"Enter Source of Income of Donater: ";
			cin>>source;
		}
		string getSourceIncome(){	return source;	} 
		float getDonationAmount(){	return don_amnt;	} 
};


