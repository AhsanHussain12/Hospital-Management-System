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
#include<fstream>
#include<string>
using namespace std;
class Person{
	protected:
		char name[50];
		string address;
		char gender;
		int age;
		char con_info[11];
		int id;
		
		public:
			static int incr;
			Person(){	}
			
		int generate_record(){
			
			string search;
			int valid=0;
			ifstream fin;
			ofstream fout;
			
			fin.open("Records.txt",ios::app);
			while(!fin.eof()){
	    	  getline(fin, search); //read data from file object and put it into string.
          	  if (search==name){
          		valid=0;
          		fin.close();
				return 0;
			  }
			  else
		  		valid=1;
      	    	}
      		
			  fin.close();
      		if(valid==1){
      			fout.open("Records.txt",ios::app);
      			fout<<name<<endl;
      			fout.close();
      			return 1;
			  }
			
		}	
		virtual	int getData(){	
			fflush(stdin);			
			cout<<"|| Kindly Fill in the Info ||"<<endl<<endl;	
			cout<<"Name: "; gets(name);
			if(generate_record()==0){  // check whether objects file exists
				return 0;				
			}else{
				cout<<"Age: ";  cin>>age;
				while(1){
				cout<<"Gender[M/F]: "; cin>>gender;
				if(gender=='M'||gender=='F'||gender=='m'||gender=='f'){break;}
				}
				fflush(stdin);
				cout<<"Address :"; getline(cin,address);
				fflush(stdin);	
				cout<<"Contact Number : +92-"; gets(con_info);	
				id=100;	
//				srand(con_info);
				id=id+incr+(rand ()%6)+1;
				incr+=9;
			}

			
	
			}


		//////GETTERS///////	
		int getid(){ return id;	}
		double getcon_info(){	return *con_info;	}
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
	static void load(){
				for (int i=0;i<2;i++){
				cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t";	
   			 	cout<<"Processing Info ";
    			for(int j=0;j<5;j++){
         			cout<<".";
         			sleep(1);
        	     }
        		system("cls");
    		  }
			}
	static void fetching(){
	char x=219;
	for(int i=0;i<1;i++){
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t";
		cout<<"LOADING:";
		for(int j=0;j<10;j++){
			cout<<x;
			sleep(1);
		}
	}
}
		

};


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

class Patient:public Person{
	private:
	string allergies;
	string prev_diseases;
	string PBG;
	char type;
	int Doctoken;
	string Doctype;
	public:
		Patient(){
		}
		void writefile(){
		   ofstream fout;
		    fout.open(name,ios::out);
		    fout<<"Name: "<<name<<endl;	
		    fout<<"Age: "<<age<<endl;
		    fout<<"Gender: "<<gender<<endl;
		    fout<<"Address: "<<address<<endl;
		    fout<<"Contact_info: "<<con_info<<endl;
		    fout<<"Patient ID: "<<id<<endl;
		    fout<<"Blood Group: "<<PBG<<endl;
		    fout<<"Allergies: "<<allergies<<endl;
		    fout<<"Medical Condition: "<<prev_diseases<<endl;
		    fout.close();
		}
		void readfile(){
			string tp;
			ifstream fin;
			fin.open(name,ios::in);
			while(!fin.eof()){
		    getline(fin, tp); //read data from file object and put it into string.
        	cout << tp << "\n"; //print the data of the string
      		}
		}
		
		int getData(){  

			if(Person::getData()==0){
				system("cls");
				console::fetching();
				system("cls");
				cout<<"||  Patient Record Found of "<<name<<" ||"<<endl<<endl;
				return 0;
			}else{
			Blood_group blood_obj;
			if(	blood_obj.checkBG()==1){PBG=blood_obj.getBG();}
			else{	PBG="Unspecified";	}
			fflush(stdin);
		    cout<<"Allergies(if any):....... "; getline(cin,allergies);
		    fflush(stdin);
		    cout<<"Medical Condition(if any):...... "; getline(cin,prev_diseases);
			// write file //
			writefile();
		    }
		}

		void patient_arrive(){  // 1st call func in main()
			
			system("cls");
				while(1){
				cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\tEmergency------>[E]"<<endl;
				cout<<"\t\t\t\t\t\tConsultation--->[C]"<<endl;
				cout<<"\n\t\t\t\t\t\t";
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
	
			system("cls");
			cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\t||Our Staff will be with you Shortly||"<<endl;  // in the center
    		Beep(500,3000);
			cin.get();
			system("cls");
			// If file Exist // then No get DATA
			if(getData()==0){
		 	readfile();
		 	system("pause");
		 	system("cls");
			}else{
			system("cls");
			console::load();	
			}
			
    	  }
    	  
			void Consultation(){
			int select;
			
			system("cls");
			cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\t[1]Dental\n\t\t\t\t\t\t[2]Orthopedic\n\t\t\t\t\t\t[3]Neurologist"<<endl;
			cin>>select;
			switch(select){
			
				case 1:
					{
					system("cls");
					Dental A;
					Doctoken=A.get_cons_time();
					Doctype=A.gettype();
					break;
					}
				case 2:
				{
					system("cls");
					Orthopedic B;
					Doctoken=B.get_cons_time();
					Doctype=B.gettype();
					break;	
					}
				case 3:
				{
					system("cls");
					Neurologist C;
					Doctoken=C.get_cons_time();
					Doctype=C.gettype();
					break;	
				}
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

	public:
		static double TA_donation;
		void writefile(){
			ofstream fout;
			console A1;
			fout.open("Donaters.txt",ios::app);
			for(int i=0;i<50;i++){fout<<"-";}
			fout<<"\n||"<<A1.d<<"/"<<A1.m<<"/"<<A1.y<<"||"<<endl;
			fout<<"Name: "<<name<<endl;	
		    fout<<"Age: "<<age<<endl;
		    fout<<"Gender: "<<gender<<endl;
		    fout<<"Contact_info: "<<con_info<<endl;
		    fout<<"Address: "<<address<<endl;
		    fout<<"ID: "<<id<<endl;
		    fout<<"Donated Amount $"<<don_amnt<<endl;
		    for(int i=0;i<50;i++){fout<<"-";}
			fout.close();
		}	
	
		void philanthropist_arrive(){
			getData();
			writefile();
		}
		int getData(){
			fflush(stdin);	
				cout<<"Name: "; gets(name);
				cout<<"Age: ";  cin>>age;
				while(1){
				cout<<"Gender[M/F]: "; cin>>gender;
				if(gender=='M'||gender=='F'||gender=='m'||gender=='f'){break;}
				}
				fflush(stdin);
				cout<<"Address :"; getline(cin,address);
				fflush(stdin);	
				cout<<"Contact Number : +92-"; cin>>con_info;	
				id=100;	
//				srand(con_info);
				id=id+incr+(rand ()%6)+1;
				incr+=9;
			    cout<<"Enter Donation Amount: $";
			    cin>>don_amnt;
				TA_donation+=don_amnt;
		}

		float getDonationAmount(){	return don_amnt;	} 
};
double Philanthropist::TA_donation=0;


class Admin{
	int pass;
	string username;
	public:
		
	Admin(){
			username="admin04";
			pass=1122;
		}
	int check_pass(){
			string U_temp;
			int pass_temp;
			
			cout<<"\n\t\t\t\t\t\t Enter Username: "; cin>>U_temp;
			cout<<"\t\t\t\t\t\t Enter Passcode: "; cin>>pass_temp;
			if(U_temp!=username || pass_temp!=pass){
				cout<<"\n\t\t\t\t\t\t||INCORRECT PASSWORD !||"<<endl<<endl;
				system("PAUSE");
				system("CLS");
				return 0;
			}
			else {
				return -1;
			}
		}
	int admin_options(){
			int select;

			system("cls");
			cout<<"\n\t\t\t\t[1] To Check Patient Record "<<endl;
			cout<<"\n\t\t\t\t[2] To Check Donation Record "<<endl;
			cout<<"\n\t\t\t\t[3] To Check Staff Members"<<endl;
			cout<<"\n\t\t\t\t[4] To ADD Staff "<<endl;
			cout<<"\n\t\t\t\t[0] To Main Menu "<<endl;
			cin>>select;
			return select;
			system("cls");
			
		}
	void readpatient(){
			int fail_count=0;
			system("cls");
			cin.ignore();
            char filename[100];
            ifstream infile;
         //   do{
            cout<<"Enter Patients filename: ";
            cin>>filename;
            infile.open(filename);
//            ++fail_count;
//            cout<<fail_count<<endl;
//			}while(infile.fail()||fail_count<2);
			if(!infile){
				cout<<"No record Exists"<<endl;
				getch();
				system("cls");
			}else{
			string line;
			while(!infile.eof())
			{
			getline(infile, line);
			cout << line<<endl;
			}
			infile.close();
			system("pause");
			}

		}
	int readdonaters(){
			system("cls");
      		char tp;
			ifstream fin;
			fin.open("Donaters.txt");
			if(!fin){
				cout<<"No Records Found"<<endl;
				getch();
				system("cls");
				return 0;
			}else{
			
			fin.get(tp);
			while(!fin.eof()){
			cout<<tp;
		    fin.get(tp);
			}
		   }	
			system("pause");
		}
	void addstaff(){
			string name,des;
			float pay;
			ofstream fout;
			cout<<"Enter Staff Name: "; cin>>name;
			fflush(stdin);
			cout<<"Enter Staff Designation: ";cin>>des;
			fflush(stdin);
			cout<<"Enter Staff monthly pay: ";cin>>pay;
			fout.open("Staff.txt",ios::app);
			fout<<name<<"        "<<des<<"        "<<pay<<endl;
			fout.close();
		}
	int readstaff(){
			char tp;
			cout<<"\nNAME      DESIGNATION    MONTHLY PAY\n"<<endl;
			ifstream fin;
			fin.open("Staff.txt",ios::in);
			fin.get(tp);
			if(!fin){
				cout<<"No Records Found"<<endl;
				getch();
				system("cls");
				return 0;	
			}else{
			while(!fin.eof()){
			cout<<tp;
		    fin.get(tp);
      		}
      	  }
      		system("pause");
		}
		
};



