#include "./Department.h"

/*
Friend functions
*/

/*
Function description: This function is used to read in the details of a department from the respective input stream.
Input to function: Input stream and object of type department
Returns: Input stream.
*/
std::istream& operator>> (std::istream& input, Department& department) {
	input >> department.id >> department.location >> department.name;
	int number_of_employees_in_department;
	int employee_ID;
	input >> number_of_employees_in_department;
	// This loop is used to push the back the ID of employees working in ONE Department into the vector of employee IDs
	department.Employee_list.clear();
	for (int i = 0; i < number_of_employees_in_department; i++){
		input >> employee_ID;
		department.Employee_list.push_back(employee_ID);
	}
	return input;
}

/*
Function description: This function is used to print the details of a department into the respective output stream.
Input to function: Output stream and object of type department
Returns: Output stream.
*/
std::ostream& operator<<(std::ostream& output, Department& department) {
	output << department.id << " " << department.location << " " << department.name << " " << department.Employee_list.size() << std::endl;
	int employee_list_size = department.Employee_list.size();
	for (int i = 0; i < employee_list_size; i++){
		output << department.Employee_list[i] << std::endl;
	}
	return output;
}

/*
Function description: This function is used to return the ID of a respective department
Input to function: None
Returns: ID of department
*/
int Department::getID()
{
	return id;
}

/*
Function description: This function is used to delete an employee from a department by removing the employee from the employee list of the department
Input to function: ID of employee to be deleted
Returns: void
*/
void Department::deleteEmployeefromDepartment(int id)
{
	int index = -1;
	for (int i = 0; i < Employee_list.size(); i++){
		// We search for the id of the desired employees in the list of employee IDs in the department
		if (Employee_list[i] == id){
			index = i;
			break;
		}
	}

	if (index != -1){
		Employee_list.erase(Employee_list.begin() + index);
		std::cout << "Employee removed from department ID: " << getID() << " \n";
	}
	//// no need for this else if statement, because each employee is assigned to one department anyway.
	//else
	//	cout << "No employee found with ID " << id << " in department " << getID() << " \n";
}

/*
Function description: This function is used to add an employee to the employee list of the department
Input to function: ID of employee to be added
Returns: void
*/
void Department::addEmployee(int id) {
	Employee_list.push_back(id);
	// cout << "[ADDING employee ID: " << id << " to the employee list of department " << this->name << "]" << endl;
}