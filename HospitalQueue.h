#pragma once
#include <string>

class HospitalQueue {
private:
	struct Patient {
		std::string first, last;
		int identification;
		bool isCritical;
		Patient* next;

		Patient() {
			first = "";
			last = "";
			identification = -1;
			isCritical = false;
			next = NULL;
		}

		Patient(std::string _first, std::string _last, int _identification, bool _isCritical) {
			first = _first;
			last = _last;
			identification = _identification;
			isCritical = _isCritical;
			next = NULL;
		}
	};

	Patient* head;
	int capacity;
	int patientCount;

public:
	HospitalQueue();
	void addPatient(std::string _first, std::string _last, int _identification);
	void addCriticalPatient(std::string _first, std::string _last, int _identification);
	void operate();
	void removePatient(int _identification);
	void listPatients();
	void listPatientById(int _identification);
	bool isUniqueId(int _identification);
	~HospitalQueue();
};