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
			if(getData()==0){
		 	readfile();
		 	system("pause");
		 	system("cls");
			}else{
			system("cls");
			S1.load();	
			}
			
    	  }
			void Consultation(){
			int select;
			
			system("cls");
			cout<<"[1]Dental\n[2]Orthopedic\n[3]Neurologist"<<endl;
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
			if(getData()==0){
		 	readfile();
		 	system("pause");
		 	system("cls");
			}else{
			system("cls");
			S1.load();	
			}
			
    	  }
			void Consultation(){
			int select;
			
			system("cls");
			cout<<"[1]Dental\n[2]Orthopedic\n[3]Neurologist"<<endl;
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
			if(getData()==0){
		 	readfile();
		 	system("pause");
		 	system("cls");
			}else{
			system("cls");
			S1.load();	
			}
			
    	  }
			void Consultation(){
			int select;
			
			system("cls");
			cout<<"[1]Dental\n[2]Orthopedic\n[3]Neurologist"<<endl;
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

