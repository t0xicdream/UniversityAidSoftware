#include "Student.h"
#include "Faculty.h"
using namespace std;

vector<Faculty> faculties;
void welcomeScreen(void);
void mainMenu();
void addDepartament();
void addFaculty();
void addStudy();
void cls(void);

int main() {

	int ProgramExit = 0;
	while (ProgramExit !=1) {
		welcomeScreen();
		mainMenu();
		int choice;
		cout << "Enter option: (0-12): " << endl;
		cin >> choice;
		cls();
		if (choice == 1) {
			addFaculty();
		}

		if (choice == 2) {
			addDepartament();
		}
		if (choice == 3) {
			addStudy();
		}

		if (choice > 3 && choice < 12) {
			cout << "Under Construction :(" << endl;
			Sleep(5000);
		}

		if (choice <= 0) {
			cout << "Select an option using numbers from 1 - 12" << endl;
		}

		if (choice == 12) {
			return 0;
		}

	}






}

void cls() {
	system("CLS");
	}

void welcomeScreen(void){
	cout << R"(
##############################################################################

 _   _      _                _ _            _   _    _   _____         _ 
| | | |_ _ (_)_ _____ _ _ __(_) |_ _  _    /_\ (_)__| | |_   _|__  ___| |___
| |_| | ' \| \ V / -_) '_(_-< |  _| || |  / _ \| / _` |   | |/ _ \/ _ \ (_-<
 \___/|_||_|_|\_/\___|_| /__/_|\__|\_, | /_/ \_\_\__,_|   |_|\___/\___/_/__/
                                   |__/                                     

##############################################################################
)";
}

void mainMenu() {
	cout << R"(
+----------------------------------------+-------------------------------------------+
|              Add a Faculty             |              Add a Department             |
|                   01                   |                     02                    |
+----------------------------------------+-------------------------------------------+
|           Add a Study Program          |               Add a Subject               |
|                   03                   |                     04                    |
+----------------------------------------+-------------------------------------------+
| Register a Student  in a Study program | Deregister a Student from a Study program |
|                   05                   |                     06                    |
+----------------------------------------+-------------------------------------------+
|            Add Student Marks           |           Delete a Study Program          |
|                   07                   |                     08                    |
+----------------------------------------+-------------------------------------------+
|           Delete a Department          |              Delete a Faculty             |
|                   09                   |                     10                    |
+----------------------------------------+-------------------------------------------+
|             Add a Pedagogue            |                    Exit                   |
|                   11                   |                     12                    |
+----------------------------------------+-------------------------------------------+
)";

}


void addDepartament() {
	cout << R"(
+---------------------+
| Adding a Department |
|                     |
+---------------------+)" << endl;

	cout << "Add ID dhe Departmanet's name" << endl;
	int id;
	string name;
	cin >> id;
	while (cin.fail()) {
		cout << "Wrong input. Please check your data again" << std::endl;
		cin.clear();
		cin.ignore(256, '\n'); //Shiko parametrat tek http://www.cplusplus.com/reference/istream/istream/ignore/ //Parandalon perseritjen e errorit
		cin >> id;
	}
	cin >> name;
	Departament departamentIRi(id, name); //Krijohet nje departament i ri ku regjistrohen id dhe emri
	cout << "Cilit fakultet do i perkasi?" << endl;
	string fName;
	cin >> fName;
	int poz = -1; //Vendoset poz i barabarte me -1, per te mos krijuar konflikte me vektorin ne rast se nuk gjendet emri, pasi poz -1 nuk ekziston ne vektor
	for (int i = 0; i < faculties.size(); i++) //Nje cikel qe bredh ne vektorin faculties per te gjetur emrin e fakultetit te dhene 
	{
		if (faculties[i].name == fName)
		{
			poz = i; //poz merr indexin ku ndodhet emri i fakulteti ne vektor
			break;
		}
	}
	if (poz == -1)
	{
		cout << "This faculty cannot be found" << endl;
		cout << "Check all the exsisiting faculties? (Y/N)" << endl; 
		char input;
		cin >> input;
		if (input == 'y' || 'Y') {
			cls();
			cout << R"(
+----------------+
| Available Data |
|                |
+----------------+)" << endl;

			for (int i = 0; i < faculties.size(); i++)
			{
				cout << "Te dhenat e fakultetit " << i + 1 << endl;
				cout << faculties[i].name << endl;
				cout << faculties [i].address << endl;
				cout << "Departamentet jane: " << endl;
				for (int j = 0; j < faculties[i].departamentet.size(); i++)
				{
					cout << "Emer: " << faculties[i].departamentet[j].nameDepartament << endl;
					cout << "Id: " << faculties[i].departamentet[j].getId() << endl;
				}
			}
		}
			cout << "Press Enter to return to Menu";
			cin.ignore();
			cin.ignore(); //Pse 2 here? https://stackoverflow.com/a/37234270
			return;
	}
	faculties[poz].departamentet.push_back(departamentIRi);
};
void addFaculty() {
	string adresa, emer;
	cout << "Vendosni emrin dhe adresen e Fakultetit" << endl;
	cin >> emer;
	cin >> adresa;
	Faculty fakultetIRi;
	fakultetIRi.name = emer;
	fakultetIRi.address = adresa;
	faculties.push_back(fakultetIRi);
};
void addStudy() {
	

};
