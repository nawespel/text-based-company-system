#pragma once

#include <fstream>
#include "./Department.h"

class DepartmentList {
	// friend functions here

	friend std::istream& operator>>(std::istream& input, DepartmentList& departmentList);

	friend std::ostream& operator<<(std::ostream& output, DepartmentList& departmentList);
	// private attributes
private:
	std::vector <Department> list;
	// public methods	
public:
	//default constructor of the class DepartmentList
	DepartmentList();
	//Non-default constructor of the class DepartmentList
	DepartmentList(std::string file_name);
	~DepartmentList();
	void deleteEmployeefromDepartmentList(int id);
	std::vector <Department> getDepartmentList();
	Department& getDepartment(int departmentID);
};

