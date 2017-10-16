#include<iostream>
using namespace std;
const int MAX = 100;
class Student{
private:
	char name[MAX],studyClass[MAX];
	double mathScore, chineseScore, englishScore, GPA;
public:
	friend int compare(Student &s1, Student &s2);
	Student(){
		this->mathScore = 0;
		this->chineseScore = 0;
		this->englishScore = 0;
		strcpy(this->name,"name");
		strcpy(this->studyClass,"class A");
	}
	Student(double mathScore, double chineseScore, double englishScore, char* name , char* studyClass){
		this->mathScore = mathScore;
		this->chineseScore = chineseScore;
		this->englishScore = englishScore;
		strcpy(this->name,name);
		strcpy(this->studyClass,studyClass);
	}
	double getGPA(){
		GPA = (chineseScore + englishScore + mathScore)/3;
		return GPA;
	}; 
	char* getName(){
		return this->name;
	}
	
};
int compare(Student &s1, Student &s2){
	if(s1.GPA > s2.GPA){
		return 1;
	}else if(s1.GPA == s2.GPA){
		return 0;
	}else {
		return -1;
	}
}

int main(){
	Student student1(97,96,95,"LiMing","computer_1"),student2(96,95,97,"Zhenghan_Wang","computer_2");
	cout<<student1.getGPA()<<endl;
	cout<<student2.getGPA()<<endl;
	cout<<"The better one is : "<<endl;
	int result = compare(student1,student2);
	if(result == 1 ){
		cout<< student1.getName() << endl;
	}else if(result ==0){
		cout<< student1.getName()<< " and "<< student2.getName() << endl;
	}else {
		cout<< student2.getName() << endl;
	}
	int n;
	cin >> n;
	return 0;
}
