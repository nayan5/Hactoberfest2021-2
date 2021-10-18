/*

PROBLEM STATMENT - 
Develope a program in c++ to create Database of Student's Information System containing the following information: Name,RollNo,Class,Division,
DOB,Contact Number,Address etc.
*/

#include<iostream>
using namespace std;//write c++ prog in which base class is student and 2 derived clases 1. personal info 2.Academic Info Try inheritance,poly,abst

class Student{				//Modularity
	private:
		int pin=1122;     	//Bank Pin is kept very private

	friend class Happy;   	//friend Class named Happy
	public:
		int s,x,y;
	~Student()				//Destructor
	{
		//code_for_releasing_memory
	}
	
    static int RollNo;							//Static keyword
    static int getRollNo()
    {
            return RollNo;
    }

	

	Student()								//default constructor
	{
		cout<<"\n***********STUDENT DATABASE*************\n";
	}

	Student(int a,int b)					//parameterized constructor
	{
		x=a;
		y=b;
	}

	Student(const Student &old_obj)			//copy constructor_creating old object: (old_obj)
	{
		x=old_obj.x;
		y=old_obj.y;
	}

	void print()							//declaring x,y for showing use of copy constructor
	{
		cout<<"Length of Student:"<<x<<"\nWeight of Student:"<<y<<"\n";
	}
	
};

class Happy			//A friend class can access both private and protected members of the class in which it has been declared as friend.
{
	public:			//class Happy is friend of class Student
	void display(Student &a)  
    {  
        cout<<"(Value of Pin is : "<<a.pin<<")";  
    }  
};

	
class PersonalInfo:public Student{
	public:
	void A()
	{
		string Name,address;
		char blood_grp[100],DOB[100];
		cout<<"Name:";
		cin>>Name;
		
		cout<<"Address:";
		cin>>address;
		
		cout<<"Blood Group:";
		cin>>blood_grp;
		
		cout<<"DOB:";
		cin>>DOB;
	}
	

	      									
	//Polymorphism
	float result(float x)										
	{
		
		cout<<"Half of you result:"<<x/2;
		
	}
	
	float result(float m,float n)
	{
		cout<<"\nTotal Result:"<<(m+n);
		cout<<"\n";	
	}
	
};

class AcademicInfo:public Student{
	public:

	inline void Academic()
	{
		char roll_no[100];
		string branch,div;
		long long telephone_num,Lisecse_num;
		
		cout<<"Branch:";
		cin>>branch;
		
		cout<<"Number:";
		cin>>telephone_num;
		
		cout<<"Lisencse Number:";
		cin>>Lisecse_num;
		
		
	}

	
};
class P                                          //this pointer
{
		public:

		int clg_no;
		string clg_name;
		int pin_code;
		
		P(int clg_no,string clg_name,int pin_code)
		{
			this->clg_no = clg_no;    
			this->clg_name = clg_name;    
			this->pin_code = pin_code;
		}
		void display()    
		{    
			cout<<"College Number:"<<clg_no<<"  "<<"College Name:"<<clg_name<<"  "<<"PIN CODE:"<<pin_code<<endl;
		}   
};

int Student::RollNo=50;   						//part of static

int main()
{
	P o1=P(10201, "MESCOE", 440031); //creating an object of Employee  
    o1.display();    
   
	PersonalInfo obj_1;							//Hierarchical Inheritance
	AcademicInfo obj_2; 
	obj_1.A();
	
	obj_2.Academic();
	 
	obj_1.result(8.9f);
	obj_1.result(5.0f,3.9f);

	Student obj(163,55);
	Student obj2(obj);
	obj2.print();

	cout<<"RollNO:"<<obj.RollNo;				//declaring through static

	Student a;
	Happy b;
	b.display(a);
	
	
	
}
