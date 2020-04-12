#include ".\DepartmentList.h"

/*
Friend functions
*/
/*
Function description: This function is used to read in departments and store them in a vector
Input to function: Input stream and object of type departmentList
Returns: Input stream.
*/
std::istream& operator>>(std::istream& input, DepartmentList& departmentList)
{
	int number_of_departments;
	input >> number_of_departments;
	Department department;
	for (int i = 0; i < number_of_departments; i++)
	{
		input >> department;
		departmentList.list.push_back(department);

	}
	return input;
}

/*
Function description: This function is used to print out the list of departments of the company with their respective details
Input to function: Output stream and object of type departmentList
Returns: Output stream.
*/
std::ostream& operator<<(std::ostream& output, DepartmentList& departmentList)
{
	int department_list_size = departmentList.list.size();
	output << department_list_size << std::endl;
	for (int i = 0; i < department_list_size; i++)
	{
		output << departmentList.list[i] << std::endl;
	}
	return output;
}


/*
Constructors
*/

DepartmentList::DepartmentList() {}

DepartmentList::DepartmentList(std::string file_name) {
	std::ifstream input(file_name);
	if (input.fail()) {
		std::cout << "Program failed to load " << file_name << ". Program will exit." << std::endl;
		exit(0);
	}
	int number_of_departments;
	input >> number_of_departments;
	Department department;
	for (int i = 0; i < number_of_departments; i++)
	{
		input >> department;
		list.push_back(department);

	}
	input.close();

}

DepartmentList :: ~DepartmentList() {
	std::ofstream output("departments.txt");
	if (output.fail()) {
		std::cout << "Program failed to save (employees.txt). Program will exit." << std::endl;
		exit(0);
	}
	output << list.size() << std::endl;
	for (int i = 0; i < list.size(); i++) {
		output << list[i];
	}
	output.close();
}

/*
Function description:  This function iterates through the list of departments and deletes the desired employee (if found) by the help of the function deleteEmployeefromDepartment present in the department class.
Input to function: ID of employee to be deleted
Returns: void
*/

void DepartmentList::deleteEmployeefromDepartmentList(int id)
{
	for (int i = 0; i < list.size(); i++)
	{
		list[i].deleteEmployeefromDepartment(id);
	}
}

/*
Function description : This function is used to return the list of departments from the DepartmentList class
Input to function : None
Returns : The vector "list".
*/

std::vector <Department> DepartmentList::getDepartmentList()
{
	return list;
}

/*
Function description : This function is used to return the department from the department list vector.
Input to function : department ID
Returns : The vector "list".
*/

Department& DepartmentList::getDepartment(int departmentID) {
	// The argument is already checked 
	for (int i = 0; i < list.size(); i++) {
		if (list[i].getID() == departmentID) {
			return list[i]; // return this specific department
		}
	}
}