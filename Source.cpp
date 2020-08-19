#include <iostream>
#include <string>
#include "HospitalQueue.h"

void menu(HospitalQueue& hospitalQueue);
void clear();

int main() {
	HospitalQueue myHospital;

	menu(myHospital);

	return 0;
}

void menu(HospitalQueue& hospitalQueue) {
	std::cout << "----------------------------------\n";
	std::cout << "Welcome to the hospital queue menu\n\n";
	std::cout << "1. Add a patient\n";
	std::cout << "2. Add a critical patient\n";
	std::cout << "3. Operate on a patient\n";
	std::cout << "4. Remove a patient\n";
	std::cout << "5. List all patients\n";
	std::cout << "6. List a specific patient\n";
	std::cout << "----------------------------------\n";

	int menuChoice;

	std::cin >> menuChoice;
	std::cin.ignore();

	switch (menuChoice) {
	case 1: {
			std::string first, last;
			int identification;

			clear();

			std::cout << "Please enter the patient's first name: ";
			getline(std::cin, first);

			std::cout << "Please enter the patient's last name: ";
			getline(std::cin, last);

			std::cout << "Please enter the patient's ID: ";
			std::cin >> identification;
			std::cin.ignore();

			hospitalQueue.addPatient(first, last, identification);

			std::cout << "\nPress ENTER to continue...\n";
			std::cin.ignore();

			clear();

			menu(hospitalQueue);

			break;
		
		}

	case 2: {
			std::string first, last;
			int identification;

			clear();

			std::cout << "Please enter the patient's first name: ";
			getline(std::cin, first);

			std::cout << "Please enter the patient's last name: ";
			getline(std::cin, last);

			std::cout << "Please enter the patient's ID: ";
			std::cin >> identification;
			std::cin.ignore();

			hospitalQueue.addCriticalPatient(first, last, identification);

			std::cout << "\nPress ENTER to continue...\n";
			std::cin.ignore();

			clear();

			menu(hospitalQueue);

			break;
		}
	case 3: {
			clear();

			hospitalQueue.operate();

			std::cout << "\nPress ENTER to continue...\n";
			std::cin.ignore();

			clear();

			menu(hospitalQueue);

			break;
		}

	case 4: {
			int identification;

			clear();

			std::cout << "Please enter the patient's ID: ";
			std::cin >> identification;
			std::cin.ignore();

			hospitalQueue.removePatient(identification);

			std::cout << "\nPress ENTER to continue...\n";
			std::cin.ignore();

			clear();

			menu(hospitalQueue);

			break;
		}

	case 5: {
			clear();

			hospitalQueue.listPatients();

			std::cout << "\nPress ENTER to continue...\n";
			std::cin.ignore();

			clear();

			menu(hospitalQueue);

			break;
		}

	case 6: {
			int identification;

			clear();

			std::cout << "Please enter the patient's ID: ";
			std::cin >> identification;
			std::cin.ignore();

			hospitalQueue.listPatientById(identification);

			std::cout << "\nPress ENTER to continue...\n";
			std::cin.ignore();

			clear();

			menu(hospitalQueue);

			break;
		}

	default: {
			clear();

			std::cout << "Please enter only from the choices available.\n";


			std::cout << "\nPress ENTER to continue...\n";
			std::cin.ignore();

			clear();

			menu(hospitalQueue);
		}
	}
}

void clear() {
#if defined _WIN32
	system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
	system("clear");
#elif defined (__APPLE__)
	system("clear");
#endif
}