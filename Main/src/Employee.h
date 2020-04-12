#pragma once

#include <iostream>
#include <string>
#include <vector>


class Employee {

	//opertor overloading for reading ONE employee and creating a vector containing the ID of projects each employee works on
	friend std::istream& operator>>(std::istream& input, Employee& employee);

	// operator overloading for printing out ONE employee and the project of IDs they work on
	friend std::ostream& operator<<(std::ostream& output, Employee& employee);
private:
	int ID;
	std::string name;
	std::string rank;
	std::vector <int> project_ID_list; // each employee may be assigned to multiple projects

public:

	Employee();
	Employee(int id, std::string name, std::string rank, std::vector <int> project_id_list);
	void setEmployeeID(int id);
	int getEmployeeID();
	std::string getName(); // used for option 5
	std::string getRank(); // used for option 5
	std::vector <int> getProjectList();
	void removeProject(int index);
};





