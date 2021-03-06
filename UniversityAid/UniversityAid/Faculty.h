#pragma once
#include "Libraries.h"
#include "Departament.h"
#include "Subjects.h"
using namespace std;
class Faculty {

public:
	string name;
	string address;
	vector<Departament> departamentet;
	vector<S_Program> programet;
	vector<Subjects> sub;
	vector<Student> studen;
	vector<int> marks;

	Faculty()
	{
		name = "";
		address = "";
	}
	Faculty(string name, string address, vector<Departament> d, vector<S_Program> prog, vector<Subjects> sub, vector<int> marks)
	{
		this->name = name;
		this->address = address;
		this->departamentet = d;
		this->programet = prog;
		this->sub = sub;
		this->marks = marks;

	}

};

void DebugSize(vector<Faculty> faculties) {

	cout << faculties.size()<<endl;
	for (int i = 0; i < faculties.size(); i++) {
		cout << faculties[i].departamentet.size() << endl;
	}

}

void checkFaculties(vector<Faculty> faculties) {
	cout << R"(
+----------------+
| Available Data |
+----------------+)" << endl;

	for (int i = 0; i < faculties.size(); i++)
	{
		cout << "Information for Faculty " << i + 1 << endl;
		cout << "Name: " << faculties[i].name << endl;
		cout << "Address: " << faculties[i].address << endl;
		cout << " Departaments: " << endl;
		for (int j = 0; j < faculties[i].departamentet.size(); j++)
		{
			cout << " Name: " << faculties[i].departamentet[j].nameDepartament << endl;
			cout << " Id: " << faculties[i].departamentet[j].getId() << endl;
			cout << "  Programs: " << endl;
			for (int k = 0; k < faculties[i].departamentet[j].programet.size(); k++) {
				cout << "  Name: " << faculties[i].departamentet[j].programet[k].nameProgram << endl;
				cout << "  ID: " << faculties[i].departamentet[j].programet[k].getId() << endl;
				cout << "  Years: " << faculties[i].departamentet[j].programet[k].programYears << endl;
				cout << "   Subjects: " << endl;
				for (int l = 0; l < faculties[i].departamentet[j].programet[k].sub.size(); l++) {
					cout << "    Name: " << faculties[i].departamentet[j].programet[k].sub[l].name << endl;
					cout << "    ID: " << faculties[i].departamentet[j].programet[k].sub[l].getCredits() << endl;
					cout << "    Hours: " << faculties[i].departamentet[j].programet[k].sub[l].getHours() << endl;
					cout << "     Pedagogue: " << endl;
					for (int m = 0; m < faculties[i].departamentet[j].programet[k].sub[l].pedagog.size(); m++) {
						cout << "     Name: " << faculties[i].departamentet[j].programet[k].sub[l].pedagog[m].name << endl;
						cout << "     Surname: " << faculties[i].departamentet[j].programet[k].sub[l].pedagog[m].surname << endl;
						cout << "     ID: " << faculties[i].departamentet[j].programet[k].sub[l].pedagog[m].getID() << endl;
						cout << "     Salary: " << faculties[i].departamentet[j].programet[k].sub[l].pedagog[m].getPaga() << endl;
						cout << "     Age: " << faculties[i].departamentet[j].programet[k].sub[l].pedagog[m].getAge() << endl;
						cout << "     Address: " << faculties[i].departamentet[j].programet[k].sub[l].pedagog[m].getAddress() << endl;
						cout << "     Postal Code: " << faculties[i].departamentet[j].programet[k].sub[l].pedagog[m].getPS() << endl;
						cout << "     Birthday: " << faculties[i].departamentet[j].programet[k].sub[l].pedagog[m].getBirthday() << endl;
						cout << "      Students:" << endl;
						for (int n = 0; n < faculties[i].departamentet[j].programet[k].sub[l].pedagog[m].student.size(); n++) {
							cout << "      Name: " << faculties[i].departamentet[j].programet[k].sub[l].pedagog[m].student[n].name << endl;
							cout << "      Surname: " << faculties[i].departamentet[j].programet[k].sub[l].pedagog[m].student[n].surname << endl;
							//cout << "      ID: " << faculties[i].departamentet[j].programet[k].sub[l].pedagog[m].student[n]. << endl;
							cout << "      Age: " << faculties[i].departamentet[j].programet[k].sub[l].pedagog[m].student[n].getAge() << endl;
							cout << "      Address: " << faculties[i].departamentet[j].programet[k].sub[l].pedagog[m].student[n].getAddress() << endl;
							cout << "      Postal Code: " << faculties[i].departamentet[j].programet[k].sub[l].pedagog[m].student[n].getPS() << endl;
							cout << "      Birthday: " << faculties[i].departamentet[j].programet[k].sub[l].pedagog[m].student[n].getBirthday() << endl;
						}
					}
				}
			}
		}
	}
}

void promptocheck(vector<Faculty> faculties) {
	char input;
	cin >> input;
	if (input == 'y' || input == 'Y') {
		cls();
		checkFaculties(faculties);
		cout << "Press Enter to return to Menu";
		cin.ignore();
		cin.ignore();
	}
}

void writeFaculties(vector<Faculty> faculties, int i, ofstream &write) {
	if (write.is_open()) {
		for (int j = 0; j < faculties[i].departamentet.size(); j++)
		{
			write << " Name: " << faculties[i].departamentet[j].nameDepartament << endl;
			write << " Id: " << faculties[i].departamentet[j].getId() << endl;
			write << "  Programs: " << endl;
			for (int k = 0; k < faculties[i].departamentet[j].programet.size(); k++) {
				write << "  Name: " << faculties[i].departamentet[j].programet[k].nameProgram << endl;
				write << "  ID: " << faculties[i].departamentet[j].programet[k].getId() << endl;
				write << "  Years: " << faculties[i].departamentet[j].programet[k].programYears << endl;
				write << "   Subjects: " << endl;
				for (int l = 0; l < faculties[i].departamentet[j].programet[k].sub.size(); l++) {
					write << "    Name: " << faculties[i].departamentet[j].programet[k].sub[l].name << endl;
					write << "    ID: " << faculties[i].departamentet[j].programet[k].sub[l].getCredits() << endl;
					write << "    Hours: " << faculties[i].departamentet[j].programet[k].sub[l].getHours() << endl;
					write << "     Pedagogue: " << endl;
					for (int m = 0; m < faculties[i].departamentet[j].programet[k].sub[l].pedagog.size(); m++) {
						write << "     Name: " << faculties[i].departamentet[j].programet[k].sub[l].pedagog[m].name << endl;
						write << "     Surname: " << faculties[i].departamentet[j].programet[k].sub[l].pedagog[m].surname << endl;
						write << "     ID: " << faculties[i].departamentet[j].programet[k].sub[l].pedagog[m].getID() << endl;
						write << "     Salary: " << faculties[i].departamentet[j].programet[k].sub[l].pedagog[m].getPaga() << endl;
						write << "     Age: " << faculties[i].departamentet[j].programet[k].sub[l].pedagog[m].getAge() << endl;
						write << "     Address: " << faculties[i].departamentet[j].programet[k].sub[l].pedagog[m].getAddress() << endl;
						write << "     Postal Code: " << faculties[i].departamentet[j].programet[k].sub[l].pedagog[m].getPS() << endl;
						write << "     Birthday: " << faculties[i].departamentet[j].programet[k].sub[l].pedagog[m].getBirthday() << endl;
						write << "      Students:" << endl;
						for (int n = 0; n < faculties[i].departamentet[j].programet[k].sub[l].pedagog[m].student.size(); n++) {
							write << "      Name: " << faculties[i].departamentet[j].programet[k].sub[l].pedagog[m].student[n].name << endl;
							write << "      Surname: " << faculties[i].departamentet[j].programet[k].sub[l].pedagog[m].student[n].surname << endl;
							//write << "      ID: " << faculties[i].departamentet[j].programet[k].sub[l].pedagog[m].student[n]. << endl;
							write << "      Age: " << faculties[i].departamentet[j].programet[k].sub[l].pedagog[m].student[n].getAge() << endl;
							write << "      Address: " << faculties[i].departamentet[j].programet[k].sub[l].pedagog[m].student[n].getAddress() << endl;
							write << "      Postal Code: " << faculties[i].departamentet[j].programet[k].sub[l].pedagog[m].student[n].getPS() << endl;
							write << "      Birthday: " << faculties[i].departamentet[j].programet[k].sub[l].pedagog[m].student[n].getBirthday() << endl;
						}
					}
				}
			}
		}
	}
	else {
		cout << "Unable to open file";
	}

}

