#pragma once

#include <iostream>
#include <string>
#include <vector>

class Department {
	// friend functions here
	// Operator overloading to read ONE Department and the employees working in that department .
	friend std::istream& operator>> (std::istream& input, Department& department);
	// Operator overloading to print ONE Department and the ID of employees working in that department
	friend std::ostream& operator<<(std::ostream& output, Department& department);
	// private attributes
private:
	int id;
	std::string name;
	std::string location;
	std::vector <int> Employee_list; // list of IDs of employees
								// public methods	
public:
	int getID();
	void deleteEmployeefromDepartment(int id);
	void addEmployee(int id);
};





