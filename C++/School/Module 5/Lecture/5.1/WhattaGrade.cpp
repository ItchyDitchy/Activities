#include <iostream>

using namespace std;

int main(int argc, char** argv) {

	float grade1, grade2, grade3,
	    gradeAvg, gradeSUM;


	system("CLS");

	cout << "\t\t\t Whatta Grade!!!" << endl;
	cout << "Enter Grade 1: ";
    cin >> grade1;
	cout << "Enter Grade 2: ";
    cin >> grade2;
	cout << "Enter Grade 3: ";
    cin >> grade3;

	gradeSUM = grade1 + grade2 + grade3;
	gradeAvg = gradeSUM / 3;

	cout << "The average of the three(3) exams is: " << gradeAvg;

	if (gradeAvg >= 70)
		cout << " :-)" << endl;
	else
		cout << " :-(" << endl;
	return 0;
}