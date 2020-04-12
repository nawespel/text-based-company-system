#pragma once

#include <fstream>
#include <vector>
#include "./Employee.h"
#include "./ProjectList.h"
#include "./DepartmentList.h"

class EmployeeList {
	// friend functions here
	friend std::istream& operator>>(std::istream& input, EmployeeList& employeeList);
	friend std::ostream& operator<<(std::ostream& output, EmployeeList& employeeList);

private:
	std::vector<Employee> list;

public:
	EmployeeList();
	EmployeeList(std::string file_name);
	~EmployeeList();

	void addEmployee(Employee& employeeObject, ProjectList& projectList, int department, DepartmentList& departmentList);
	void findEmployeeInfo(Employee& employeeObject);
	void removeProject(int id);
	bool deleteEmployee(int id);
};



