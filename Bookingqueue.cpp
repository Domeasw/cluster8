#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<sstream>
#include<ctime>

using namespace std;

class customer{
	public:

			class node{
				
				public:
				
				string name,tel,date,weight,option,que,status;
				int data;
				node *link;
				node *alink;
				node(){
					this->data = 0;
				}
			};
		int count;
		
		node *head;
		node *tail;
		node *temp;
		
		
		customer(void){
			
			this->head = NULL;
			this->tail = NULL;
			this->count = 1;
			
		}
		
		~customer(){
			
			for(int i = 1; i < this->count; i++){
				node * temp = this->head;
				this->head = this->head->link;
				delete temp;
				temp = NULL;
			}
			this->head = NULL;
			this->tail = NULL;
		}
		
		void add(string name,string tel,string date,string weight,string option,string que,string status){
		
			node *temp = new node;
			temp->name = name;
			temp->tel = tel;
			temp->date = date;
			temp->weight = weight;
			temp->option = option;
			temp->weight = weight;
			temp->que = que;
			temp->status = status;
			temp->link = NULL;
			
		if(this->count == 1){
				
				//temp->data = value;
				//temp->link = NULL;
				this->head = temp;
				this->tail = temp;
				
			
			}else{
				
				//temp->data = value;
				//temp->link = NULL;
				this->tail->link = temp;
				this->tail = this->tail->link;
				
			
			
			}
			
		count++;
		
		}
		
		void set(string date,string weight,string option, int index)
		{
			if (index < count)
			{
				node *ptemp = new node(); 
				int i;
				for (i = 1, ptemp = this->head; i <= index && ptemp != NULL; i++, ptemp = ptemp->link)
				{
					if (i == index)
					{
						ptemp->date = date;
						ptemp->weight = weight;
						ptemp->option = option;
					}
				}
			}
			else
			{
				cout << "no index" << endl;
			}
		}
		
		bool loaddata(){
			string name,tel,date,weight,option,que,status,line;
			ifstream myfile;
			myfile.open("customer.dat");
			
			while(getline(myfile,line)){
				
					name=line.substr(0,line.find(','));
						line.erase(0, line.find(',')+1);
					tel=line.substr(0,line.find(','));
						line.erase(0, line.find(',')+1);
					date=line.substr(0,line.find(','));
						line.erase(0, line.find(',')+1);
					weight=line.substr(0,line.find(','));
						line.erase(0, line.find(',')+1);
					option=line.substr(0,line.find(','));
						line.erase(0, line.find(',')+1);
					que=line.substr(0,line.find(','));
						line.erase(0, line.find(',')+1);
					status=line.substr(0,line.find(','));
						line.erase(0, line.find(',')+1);
				add(name,tel,date,weight,option,que,status);			
				
					
			}//while
		
		}//myfile
		
		void show(){
			node *temp = new node();
			temp = head;
			while(temp!=NULL){
				cout << temp->name << endl;
				
				temp=temp->link;
			}
		}
		
		void writefileadd(string name,string tel,string weight,string option,string que,string status){
			
			string Name,Tel,Add,Code,Year,Month,Day,Timeh,Timem,Times,Time,Tim,timee;
			stringstream ss;
		
			time_t now = time(0);
		 	tm *ltm = localtime(&now);
	
			ss << 1900 + ltm->tm_year;
	 		ss >> Year;
	   		ss.clear();
	   		ss << 1 + ltm->tm_mon;
	   		ss >> Month;
	   		
	   		if(Month=="1"||Month=="2"||Month=="3"||Month=="4"||Month=="5"||Month=="6"||Month=="7"||Month=="8"||Month=="9"){	
	   			Month = "0"+Month;
			}
	 		ss.clear();
	  		ss << ltm->tm_mday;
	   		ss >> Day;
	   		if(Day=="1"||Day=="2"||Day=="3"||Day=="4"||Day=="5"||Day=="6"||Day=="7"||Day=="8"||Day=="9"){	
	   			Day = "0"+Day;
			}
	   		ss.clear();
	   		ss << ltm->tm_hour;
	   		ss >> Timeh;
	   		if(Timeh=="1"||Timeh=="2"||Timeh=="3"||Timeh=="4"||Timeh=="5"||Timeh=="6"||Timeh=="7"||Timeh=="8"||Timeh=="9"){	
	   			Timeh = "0"+Timeh;
			}
	   		ss.clear();
	   		ss << 1+ltm->tm_min;
	   		ss >> Timem;
	   		if(Timem=="1"||Timem=="2"||Timem=="3"||Timem=="4"||Timem=="5"||Timem=="6"||Timem=="7"||Timem=="8"||Timem=="9"){	
	   			Timem = "0"+Timem;
			}
	   		ss.clear();
			ss << 1+ltm->tm_sec;
	   		ss >> Times;
	   		if(Times=="1"||Times=="2"||Times=="3"||Times=="4"||Times=="5"||Times=="6"||Times=="7"||Times=="8"||Times=="9"){	
	   			Times = "0"+Times;
			}
	   		ss.clear();
			
			Time = Timeh+":"+Timem+":"+Times;	
			Tim = Day+"-"+Month+"-"+Year;
			timee = Day+"-"+Month+"-"+Year+" "+Time;
			
			ofstream myfile("customer.dat",ios::app);
			if(myfile.is_open()){
			
		
				myfile <<  name <<","<< tel <<","<< timee <<","<< weight <<","<< option <<","<< que << ","<< status <<endl;
		
		
			}//if
	
		}
		
		void writefileset(){
			ofstream myfile("customer.dat",ios::trunc);
			if(myfile.is_open()){
			
			node *temp;	
			temp = head;
			
			
			while(temp!=NULL){
				myfile <<  temp->name <<","<< temp->tel <<","<< temp->date <<","<< temp->weight <<","<< temp->option <<","<< temp->que << ","<< temp->status <<endl;
				temp = temp->link;	
				
			}
	
			myfile.close();
		
			}//if
	
		}
		void beforeadd(string name,string tel,string weight,string option,string q){
		
			string Name,Tel,Add,Code,Year,Month,Day,Timeh,Timem,Times,Time,Tim,timee;
			stringstream ss;
		
			time_t now = time(0);
		 	tm *ltm = localtime(&now);
	
			ss << 1900 + ltm->tm_year;
	 		ss >> Year;
	   		ss.clear();
	   		ss << 1 + ltm->tm_mon;
	   		ss >> Month;
	   		
	   		if(Month=="1"||Month=="2"||Month=="3"||Month=="4"||Month=="5"||Month=="6"||Month=="7"||Month=="8"||Month=="9"){	
	   			Month = "0"+Month;
			}
	 		ss.clear();
	  		ss << ltm->tm_mday;
	   		ss >> Day;
	   		if(Day=="1"||Day=="2"||Day=="3"||Day=="4"||Day=="5"||Day=="6"||Day=="7"||Day=="8"||Day=="9"){	
	   			Day = "0"+Day;
			}
	   		ss.clear();
	   		ss << ltm->tm_hour;
	   		ss >> Timeh;
	   		if(Timeh=="1"||Timeh=="2"||Timeh=="3"||Timeh=="4"||Timeh=="5"||Timeh=="6"||Timeh=="7"||Timeh=="8"||Timeh=="9"){	
	   			Timeh = "0"+Timeh;
			}
	   		ss.clear();
	   		ss << 1+ltm->tm_min;
	   		ss >> Timem;
	   		if(Timem=="1"||Timem=="2"||Timem=="3"||Timem=="4"||Timem=="5"||Timem=="6"||Timem=="7"||Timem=="8"||Timem=="9"){	
	   			Timem = "0"+Timem;
			}
	   		ss.clear();
			ss << 1+ltm->tm_sec;
	   		ss >> Times;
	   		if(Times=="1"||Times=="2"||Times=="3"||Times=="4"||Times=="5"||Times=="6"||Times=="7"||Times=="8"||Times=="9"){	
	   			Times = "0"+Times;
			}
	   		ss.clear();
			
			Time = Timeh+":"+Timem+":"+Times;	
			Tim = Day+"-"+Month+"-"+Year;
			timee = Day+"-"+Month+"-"+Year+" "+Time;
			
			add(name,tel,timee,weight,option,"-","-");
			
		}
		
		
		
		void beforeset(string name,string tel,string weight,string option,string q){
		
			string Name,Tel,Add,Code,Year,Month,Day,Timeh,Timem,Times,Time,Tim,timee;
			stringstream ss;
		
			time_t now = time(0);
		 	tm *ltm = localtime(&now);
	
			ss << 1900 + ltm->tm_year;
	 		ss >> Year;
	   		ss.clear();
	   		ss << 1 + ltm->tm_mon;
	   		ss >> Month;
	   		
	   		if(Month=="1"||Month=="2"||Month=="3"||Month=="4"||Month=="5"||Month=="6"||Month=="7"||Month=="8"||Month=="9"){	
	   			Month = "0"+Month;
			}
	 		ss.clear();
	  		ss << ltm->tm_mday;
	   		ss >> Day;
	   		if(Day=="1"||Day=="2"||Day=="3"||Day=="4"||Day=="5"||Day=="6"||Day=="7"||Day=="8"||Day=="9"){	
	   			Day = "0"+Day;
			}
	   		ss.clear();
	   		ss << ltm->tm_hour;
	   		ss >> Timeh;
	   		if(Timeh=="1"||Timeh=="2"||Timeh=="3"||Timeh=="4"||Timeh=="5"||Timeh=="6"||Timeh=="7"||Timeh=="8"||Timeh=="9"){	
	   			Timeh = "0"+Timeh;
			}
	   		ss.clear();
	   		ss << 1+ltm->tm_min;
	   		ss >> Timem;
	   		if(Timem=="1"||Timem=="2"||Timem=="3"||Timem=="4"||Timem=="5"||Timem=="6"||Timem=="7"||Timem=="8"||Timem=="9"){	
	   			Timem = "0"+Timem;
			}
	   		ss.clear();
			ss << 1+ltm->tm_sec;
	   		ss >> Times;
	   		if(Times=="1"||Times=="2"||Times=="3"||Times=="4"||Times=="5"||Times=="6"||Times=="7"||Times=="8"||Times=="9"){	
	   			Times = "0"+Times;
			}
	   		ss.clear();
			
			Time = Timeh+":"+Timem+":"+Times;	
			Tim = Day+"-"+Month+"-"+Year;
			timee = Day+"-"+Month+"-"+Year+" "+Time;
		
			string namet,telt,datet,weightt,optiont,quet,line;
			ifstream myfile;
			myfile.open("customer.dat");
			
			while(getline(myfile,line)){
				
					namet=line.substr(0,line.find(','));
						line.erase(0, line.find(',')+1);
					telt=line.substr(0,line.find(','));
						line.erase(0, line.find(',')+1);
					datet=line.substr(0,line.find(','));
						line.erase(0, line.find(',')+1);
					weightt=line.substr(0,line.find(','));
						line.erase(0, line.find(',')+1);
					optiont=line.substr(0,line.find(','));
						line.erase(0, line.find(',')+1);
					quet=line.substr(0,line.find(','));
				
				node *temp = new node();
				temp = head;
				int count=1;
				while(temp!=NULL){
				
					if(temp->tel==telt){
						
						set(timee,weight,option,count);
							break;
					}
					temp=temp->link;
				count++;
				}
					
				
					
			}//while
			
			
		
		}
		
		bool checkregistr(string username, string tel)
		{
			string line;
			string checkname,checktel;
			fstream myFile;
			myFile.open("customer.dat", std::ios::in | std::ios::out | std::ios::app);
				while(getline(myFile, line))
				{
					
					
					checkname=line.substr(0,line.find(','));
						line.erase(0, line.find(',')+1);
					checktel=line.substr(0,line.find(','));
					
					if(checktel==tel)
					{
						  	return true;
						  	break;
					}
					else 
					{
						
					}
					
					
				}
				
				return false;
			
		}
		
		bool login(string username, string tel)
		{
			string line;
			string checkname,checktel;
			ifstream myFile;
			myFile.open("customer.dat", std::ios::in | std::ios::out | std::ios::app);
		
				while(getline(myFile, line))
				{
					
					
					checkname=line.substr(0,line.find(','));
						line.erase(0, line.find(',')+1);
					checktel=line.substr(0,line.find(','));
					
					if(checkname==username&&checktel==tel)
					{
						  	return true;
						  	break;
					}
					else 
					{
						
					}
					
					
				}
				
				return false;
			
		}
};

class Bookingqueue{
	//protected:
	public:	
	string *arr_queue;
		string turntel;
		string reserve;
		int max;
		int font;
		int rear;
			
		string *arr_queuereserve;
		int maxreserve;
		int fontreserve;
		int rearreserve;
		int countreserve;
		
		customer *obj_cus;
	
		int count;
		Bookingqueue(int size){
			arr_queue = new string[size];
			max = size;
			font = 0;	
			rear = 0;	
			count = 0;	
			
			arr_queuereserve = new string[100];
			maxreserve = 50;
			fontreserve = 0;	
			rearreserve = 0;	
			countreserve = 0;
			
			obj_cus = new customer();
			//obj_cus = new Customer();	
		}

		~Bookingqueue(){
			delete []arr_queue;
			delete []arr_queuereserve;
		}

		void enqueue(string tel){
		//	cout << obj_cus.cus<<endl;
			if(isFull()==1){	
				enqueuereserve(tel);
			}else{
			//	arr_queue[rear]=obj_cus->cus;
				arr_queue[rear]=tel;
				rear++;
				count++;
			}//if-else
		}
			
		string dequeue(){
			if(isEmpty()==1){
				cout<<"Empty"<<endl;
			}else{
				string dereserve, a;
				turntel = arr_queue[0];
				reserve = turntel;
				for(int i=0;i<rear-1;i++){
					arr_queue[i]=arr_queue[i+1];
				}//for-loop		
				if(countreserve>0){					
					dereserve = dequeuereserve();
					for(int i=count-1;i<max;i++){										
						arr_queue[i]= " ";
						arr_queue[count-1] = dereserve;
					}
					turntel = reserve;
				}else{
					for(int i=count-1;i<max;i++){									
						arr_queue[i]= " ";
					//	arr_queue[count-1] = dereserve;
					}
					turntel = reserve;
					rear--;
					count--;				
				}
			}//if-else			
			return turntel;
		}
		
		void enqueuereserve(string tel){
			if(isFullreserve()==1){			
				cout<<"Reserve Full!"<<endl;
			}else{
				arr_queuereserve[rearreserve]=tel;
				rearreserve++;
				countreserve++;
			}//if-else
		}
			
		string dequeuereserve(){
			if(isEmptyreserve()==1){
				cout<<"Reserve Empty"<<endl;
			}else{						
				turntel = arr_queuereserve[0];
				for(int i=0;i<rearreserve-1;i++){
					arr_queuereserve[i]=arr_queuereserve[i+1];
				}//for-loop		
				
				for(int i=countreserve-1;i<maxreserve;i++){	
					arr_queuereserve[i]= " ";
				}
			}//if-else
			rearreserve--;
			countreserve--;
			return turntel;
		}
		
		bool isEmpty(){
			if(count==0){
				return true;
			}else{
				return false;
			}//if-else		
		}
			
		bool isFull(){
			if(count==max){
				return true;
			}else{
				return false;
			}//if-else
		}
		
		bool isEmptyreserve(){
			if(countreserve==0){
				return true;
			}else{
				return false;
			}//if-else
			
		}

		bool isFullreserve(){
			if(rearreserve==maxreserve){
				return true;
			}else{
				return false;
			}//if-else
		}

		void show(){
			for(int i=0;i<max;i++){
				cout<<"Queue = "<<arr_queue[i];
				cout<<endl;
			}//for-loop
		}
	
		void showreserve(){
			for(int i=0;i<countreserve;i++){
				cout<<"Queue reserve = "<<arr_queuereserve[i];
				cout<<endl;
			}//for-loop
		}			
};

int main(){
	
	customer *tam = new customer();
	Bookingqueue *obj_queue = new Bookingqueue(5);
	tam->loaddata();
	
	string name,tel,weight,option;
	string yn;
	int num;
   
    menucustomer:
    cout << "1.Newcustomer" << endl;
    cout << "2.Regurlarcustomer" << endl;
    cout << " : ";
    cin >> num;
    
    if(num==1){	
	    regis:	
	    cout << "=============== NewcustomerRegister ============" << endl;
	    cout << "Input Name: ";
	    cin >> name;	
	    cout << "Input tel: ";
	    cin >> tel;
	    
	    if(tam->checkregistr(name,tel)==true)
	   	{
	    	cout<<"Register Notcomplete!!!"<<endl;
	    	goto regis;
	   	}
	   	else if(tam->checkregistr(name,tel)==false)
	   	{   		
	    	cout<<"Register complete!"<<endl;
	    	goto booknew;		
		}
	    system("cls");
	    booknew:
	    cout << "=============== NewcustomerBooking ============" << endl;    
		cout << "Name: " << name << endl; 
	    cout << "Input weight: ";
	    cin >> weight;  
	    back:
	    cout << "Input option(WW,WD,DD): ";
	    cin >> option;
	    if(option=="WW"||option=="WD"||option=="DD"||option=="ww"||option=="wd"||option=="dd"){
	    	goto skip;
		}else{
			goto back;
		}
	    skip:    
	 //add newcus  	 
		tam->beforeadd(name,tel,weight,option,"-");
		tam->writefileadd(name,tel,weight,option,"-","-");
	    obj_queue->enqueue(tel);
		cout << "Booking SucSess!";		    	
	}else if(num==2){
  		login:
  		cout << "=============== RegularCustomer ============" << endl;
  		cout<<"Input your name : ";
    	cin>>name;
    	cout<<"Input your Tel : ";
    	cin>>tel;
    	if(tam->login(name,tel)==true)
    	{
    		cout<<"login complete!!!"<<endl;
    	}
    	else if(tam->login(name,tel)==false)
    	{
    		system ("CLS");
    		cout<<"login again/exit(y/n) : "<<endl;
    		cin >> yn;
			if(yn=="y"){
				goto menucustomer;
			}else{
				goto ex;
			}
    	
		}
    	cout << "=============== RegularCustomerBooking ============" << endl;
   		 cout << "Name:" << name << endl;
	    cout << "Input weight: ";
	    cin >> weight;
	    
	    back2:
	    cout << "Input option(WW,WD,DD): ";
	    cin >> option;
	    if(option=="WW"||option=="WD"||option=="DD"||option=="ww"||option=="wd"||option=="dd"){
	    	goto skip2;
		}else{
			goto back2;
		}
	    skip2:
	// add regular   
		tam->show(); 
		tam->beforeset(name,tel,weight,option," ");
		tam->writefileset();
		obj_queue->enqueue(tel);
		obj_queue->show();	
		
	}else{
		ex:	
		cout << "ExitProGram" << endl;
	}
	
}
