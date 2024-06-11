#include <iostream>

using namespace std;

typedef struct Studnet {	//初始化结构体变量

	int ID;
	double math_scores;
	double english_scores;
	double computer_scores;
	double total_scores;
}Student;

void Input_student_score(int size, Student* stu); //输入所有学生信息

void Output_student_score(Student s); //输出所有学生信息

void select_student(int ID, Student* stu, int size);	//通过ID查找,输出学生信息

void update_student_score(int ID, int size, double math_scores, double english_scores,
	double computer_scores, Student* stu);	//通过ID查找,更新学生信息

void delete_student_score(int ID, int size, Student* stu);	//通过ID查找,删除学生信息




int main()
{
	int size;
	cout << "Please input the number of students:" << endl;
	cin >> size;
	
	Student stu[10];	//定义一个足够数量的结构体数组
	
	Input_student_score(size, stu);	//开始输入学生信息
	
	while (true) {
		cout << "----------------------------------------------------------------" << endl;
		cout << "输入: 1.查找学生信息 2.更新学生信息 3.删除学生信息	4.输出所有学生信息 5.退出系统" << endl;
		cout << "-" << endl;
		int choice;
		cin >> choice;
		switch (choice) {
		case 1:
			int ID;
			cout << "请输入要查找的学生ID:" << endl;
			cin >> ID;
			select_student(ID, stu, size);
			break;
		case 2:
			
			cout << "请输入要更新的学生ID:" << endl;
			cin >> ID;
			double math_scores, english_scores, computer_scores;
			cout << "请输入新的数学成绩:" << endl;
			cin >> math_scores;
			cout << "请输入新的英语成绩:" << endl;
			cin >> english_scores;
			cout << "请输入新的计算机成绩:" << endl;
			cin >> computer_scores;
			update_student_score(ID, size, math_scores, english_scores, computer_scores, stu);
			break;
			
		case 3:
			
			cout << "请输入要删除的学生ID:" << endl;
			cin >> ID;
			delete_student_score(ID, size, stu);
			break;

		case 4:
			for (int i = 0; i < size; i++) {
				if (stu[i].ID!= 0) {
					Output_student_score(stu[i]);
				}
			}
			break;

		case 5:
			return 0;

		default:
			cout << "输入错误(或不符合规则)，请重新输入！" << endl;
			break;
		}
	}

	return 0;
}

void Input_student_score(int size, Student* stu)
{
	for (int i = 0; i < size; i++) {
		cout << "Please input the ID of student " << i + 1 << ":" << endl;
		cin >> stu[i].ID;
		cout << "Please input the math scores of student " << i + 1 << ":" << endl;
		cin >> stu[i].math_scores;
		cout << "Please input the english scores of student " << i + 1 << ":" << endl;
		cin >> stu[i].english_scores;
		cout << "Please input the computer scores of student " << i + 1 << ":" << endl;
		cin >> stu[i].computer_scores;
		cout << endl << endl;
		stu[i].total_scores = stu[i].math_scores + stu[i].english_scores + stu[i].computer_scores;
	}
}


void Output_student_score(Student s)
{
	cout << "ID:" << s.ID << endl;
	cout << "Math Scores:" << s.math_scores << endl;
	cout << "English Scores:" << s.english_scores << endl;
	cout << "Computer Scores:" << s.computer_scores << endl;
	cout << "Total Scores:" << s.total_scores << endl;
}

void select_student(int ID, Student* stu, int size)
{
	for (int i = 0; i < size; i++) {
		if (stu[i].ID == ID) {
			Output_student_score(stu[i]);
			return;
		}
	}
}


void update_student_score(int ID, int size, double math_scores, double english_scores,
	double computer_scores, Student* stu)
{
	for (int i = 0; i < size; i++) {
		if (stu[i].ID == ID) {
			stu[i].math_scores = math_scores;
			stu[i].english_scores = english_scores;
			stu[i].computer_scores = computer_scores;
			stu[i].total_scores = math_scores + english_scores + computer_scores;
			return;
		}
	}
}


void delete_student_score(int ID, int size, Student* stu)
{
	for (int i = 0; i < size; i++) {
		if (stu[i].ID == ID) {
			stu[i].ID = 0;
			stu[i].math_scores = 0;
			stu[i].english_scores = 0;
			stu[i].computer_scores = 0;
			stu[i].total_scores = 0;
			return;	//删除后，将该位置的ID置为0，其他信息不变
		}
	}
}
