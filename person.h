class Person{
	protected:
		char name[50];
		string address;
		char gender;
		int age;
		double con_info;
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
			
		virtual	int getData(){		
			cout<<"|| Kindly Fill in the Patitent Info ||"<<endl<<endl;		
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
				cout<<"Contact Number : +92-"; cin>>con_info;	
				id=100;	
				srand(con_info);
				id=id+incr+(rand ()%6)+1;
				incr+=9;
				return 1;
			   }	
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
