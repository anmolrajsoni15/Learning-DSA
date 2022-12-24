#include <iostream>
#include <random>
#include <string>
using namespace std;

class Marks{
public:
	int roll_no;
	string name;

	void Name(string student){
		name = student;
	}
	void generateRoll(){
		roll_no = rand();
		cout<<roll_no<<endl;
	}
};

class Physics : virtual public Marks{
	protected:
		int Phy_marks;
	public:
		void set_Phy_marks(int phy){
			Phy_marks = phy;
		}
};

class Chemistry : virtual public Marks{
	protected:
		int Chem_marks;
	public:
		void set_Chem_marks(int chem){
			Chem_marks = chem;
		}
			
};

class Mathematics : virtual public Marks{
	protected:
		int Maths_marks;
	public:
		void set_Maths_marks(int maths){
			Maths_marks = maths;
		}
};

class Result : public Physics, public Chemistry, public Mathematics{
	public:
		int marks;
		void Totalmarks(){
			marks = Maths_marks+Chem_marks+Phy_marks;
			cout<<"Total marks of "<<name<<" is "<<marks<<endl<<endl;
		}
};

int main() {
	int n;
	cout<<"For how many students you want to store data"<<endl;
	cin>>n;
	Result Student[n];
	int average = 0;
	for (int i = 0; i < n; i++)
	{
		int phy, chem, maths;
		string Student_name;
		cout<<"Enter the student name:- ";
		// getline(cin, Student_name);
		cin>>Student_name;
		Student[i].Name(Student_name);

		cout<<"Enter marks of Physics:- ";
		cin>>phy;
		Student[i].set_Phy_marks(phy);

		cout<<"Enter marks of Chemistry:- ";
		cin>>chem;
		Student[i].set_Chem_marks(chem);

		cout<<"Enter marks of Maths:- ";
		cin>>maths;
		Student[i].set_Maths_marks(maths);

		cout<<"\n"<<Student_name<<" :- "<<endl;
		cout<<"Roll No : ";
		Student[i].generateRoll();
		cout<<"Physics : "<<phy<<endl;
		cout<<"Chemistry : "<<chem<<endl;
		cout<<"Mathematics : "<<maths<<endl;
		cout<<endl;
		Student[i].Totalmarks();

		average = average+Student[i].marks;
	}

	cout<<"\n\n\t\tThe average Score of the class is :- "<<average/n<<"\n\n";

	return 0;
}