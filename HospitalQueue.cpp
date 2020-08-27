#include "HospitalQueue.h"
#include <iostream>

HospitalQueue::HospitalQueue() {
	head = NULL;
	capacity = 5;
	patientCount = 0;
}

void HospitalQueue::addPatient(std::string _first, std::string _last, int _identification) {
	if (patientCount >= capacity) {
		std::cout << "\nHospital is at maximum capacity.\n";

		return;
	}

	if (this->head == NULL) {
		this->head = new Patient(_first, _last, _identification, false);

		patientCount++;

		std::cout << "\nPatient with ID of " << _identification << " was added.\n";
		
		return;
	}

	else {
		if (isUniqueId(_identification) == false) {
			std::cout << "\nA Patient with ID of " << _identification << " is already in the queue.\n";

			return;
		}

		Patient* temp = this->head;

		while (temp->next != NULL) {
			temp = temp->next;
		}

		temp->next = new Patient(_first, _last, _identification, false);

		patientCount++;

		std::cout << "\nPatient with ID of " << _identification << " was added.\n";

		temp = NULL;
		delete temp;

		return;
	}
}

void HospitalQueue::addCriticalPatient(std::string _first, std::string _last, int _identification) {
	if (patientCount >= capacity) {
		std::cout << "Hospital is at maximum capacity.\n";

		return;
	}

	if (this->head == NULL) {
		this->head = new Patient(_first, _last, _identification, true);

		patientCount++;

		std::cout << "\nPatient with ID of " << _identification << " was added.\n";

		return;
	}

	else {
		if (isUniqueId(_identification) == false) {
			std::cout << "\nA Patient with ID of " << _identification << " is already in the queue.\n";

			return;
		}

		if (this->head->isCritical != true) {
			Patient* temp = new Patient(_first, _last, _identification, true);

			temp->next = this->head;
			this->head = temp;

			patientCount++;

			std::cout << "\nPatient with ID of " << _identification << " was added.\n";

			temp = NULL;
			delete temp;

			return;
		}

		else {
			Patient* temp = this->head;
			Patient* temp2 = temp->next;

			while (temp2 != NULL && temp2->isCritical == true) {
				temp2 = temp2->next;
				temp = temp->next;
			}

			if (temp2 == NULL) {
				temp2 = new Patient(_first, _last, _identification, true);

				temp->next = temp2;

				patientCount++;

				std::cout << "\nPatient with ID of " << _identification << " was added.\n";

				temp = NULL;
				temp2 = NULL;

				delete temp;
				delete temp2;

				return;
			}

			else {
				Patient* temp3 = new Patient(_first, _last, _identification, true);

				temp3->next = temp2;
				temp->next = temp3;

				patientCount++;

				std::cout << "\nPatient with ID of " << _identification << " was added.\n";

				temp = NULL;
				temp2 = NULL;
				temp3 = NULL;

				delete temp;
				delete temp2;
				delete temp3;

				return;
			}
		}
	}
}

void HospitalQueue::operate() {
	if (this->head == NULL) {
		std::cout << "There are no patients to operate on.\n";

		patientCount = 0;

		return;
	}

	Patient* temp = this->head->next;

	delete this->head;

	patientCount--;

	this->head = temp;

	std::cout << "Patient moved out of queue for operation.\n";


	temp = NULL;

	delete temp;

	return;
}

void HospitalQueue::removePatient(int _identification) {
	if (this->head == NULL) {
		std::cout << "\nThere are no patients to remove.\n";

		patientCount = 0;

		return;
	}

	if (this->head->identification == _identification) {
		Patient* temp = this->head->next;

		delete this->head;

		patientCount--;

		this->head = temp;

		std::cout << "\nPatient removed from queue.\n";

		temp = NULL;

		delete temp;

		return;
	}

	else {
		Patient* temp = this->head;
		Patient* temp2 = temp->next;

		while (temp2 != NULL && temp2->identification != _identification) {
			temp2 = temp2->next;
			temp = temp->next;
		}

		if (temp2 == NULL) {
			std::cout << "Patient with ID of " << _identification << " was not found.\n";

			temp = NULL;
			temp2 = NULL;

			delete temp;
			delete temp2;

			return;
		}

		else {
			temp->next = temp2->next;

			patientCount--;

			std::cout << "\nPatient removed from queue.\n";

			temp = NULL;

			delete temp;
			delete temp2;

			return;
		}
	}
}

void HospitalQueue::listPatients() {
	if (this->head == NULL) {
		std::cout << "There are no patients to list.\n";

		patientCount = 0;

		return;
	}

	Patient* temp = this->head;

	while (temp != NULL) {
		std::string name = temp->first + " " + temp->last;
		std::string critical = (temp->isCritical) ? "Yes" : "No";

		std::cout << "Patient Name: " << name << " | Patient ID: " << temp->identification << " | Critical: " << critical << "\n";

		temp = temp->next;
	}

	temp = NULL;

	delete temp;
}

void HospitalQueue::listPatientById(int _identification) {
	if (this->head == NULL) {
		std::cout << "\nThere are no patients to list.\n";

		patientCount = 0;

		return;
	}

	Patient* temp = this->head;

	while (temp->next != NULL && temp->identification != _identification) {
		temp = temp->next;
	}

	if (temp->next == NULL && temp->identification != _identification) {
		std::cout << "\nPatient with ID of " << _identification << " was not found.\n";

		temp = NULL;

		delete temp;

		return;
	}

	else {
		std::string name = temp->first + " " + temp->last;
		std::string critical = (temp->isCritical) ? "Yes" : "No";

		std::cout << "\nPatient Name: " << name << " | Patient ID: " << temp->identification << " | Critical: " << critical << "\n";

		temp = NULL;

		delete temp;

		return;
	}
}

bool HospitalQueue::isUniqueId(int _identification) {
	if (this->head == NULL) {
		return true;
	}

	else if (this->head->identification != _identification) {
		return true;
	}

	else {
		Patient* temp = this->head;

		while (temp->next != NULL && temp->identification != _identification) {
			temp = temp->next;
		}

		if (temp->next == NULL && temp->identification == _identification) {
			temp = NULL;

			delete temp;

			return false;
		}

		temp = NULL;

		delete temp;
	}

	return true;
}


HospitalQueue::~HospitalQueue() {
	Patient* temp;

	while (this->head != NULL) {
		temp = this->head;
		head = head->next;

		delete temp;
	}
}