#include "./EmployeeList.h"


/*
Friend functions
*/

/*
Function description: This function is used to read in employees and store them in a vector
Input to function: Input stream and object of type employeeList
Returns: Input stream.
*/
std::istream& operator>>(std::istream& input, EmployeeList& employeeList)
{
	int number_of_employees;
	input >> number_of_employees;
	Employee employee;
	for (int i = 0; i < number_of_employees; i++)
	{
		input >> employee;
		employeeList.list.push_back(employee);

	}
	return input;

}

/*
Function description: This function is used to print out the list of employees of the company with their respective details
Input to function: Output stream and object of type EmployeeList
Returns: Output stream.
*/
std::ostream& operator<<(std::ostream& output, EmployeeList& employeeList)
{
	output << employeeList.list.size() << std::endl;
	for (int i = 0; i < employeeList.list.size(); i++)
	{
		output << employeeList.list[i] << std::endl;
	}
	return output;
}

/*
Constructors
*/

EmployeeList::EmployeeList() {}
EmployeeList::EmployeeList(std::string file_name)
{
	std::ifstream input(file_name);
	if (input.fail())
	{
		std::cout << "Program failed to load " << file_name << ". Program will exit." << std::endl;
		exit(0);
	}
	int number_of_employees;
	input >> number_of_employees;

	Employee employee;
	for (int i = 0; i < number_of_employees; i++)
	{
		input >> employee;
		list.push_back(employee);
	}
	input.close();
}

EmployeeList :: ~EmployeeList() {
	std::ofstream output("employees.txt");
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
Public functions
*/


/*
Function description: This function is used to add an employee to the list of employees of the company. Also, the employee is assigned a department and a number of projects.
Input to function: Objects of type: Employee, ProjectList and departmentList. An integer that is the ID of the department that the employee will be assigned to
Returns: void
*/
void EmployeeList::addEmployee(Employee& employeeObject, ProjectList& projectList, int department_id, DepartmentList & departmentList) {

	// First we check the validity of the employee. The ID must be new, the projects he/she is working on must be found in the projectList, and the department should also be valid.
	int id = employeeObject.getEmployeeID();
	int counter = 0;
	bool valid_id = true;
	bool valid_project = false;
	bool valid_department = false;
	// Checking the employee ID
	for (int i = 0; i < list.size(); i++) {
		if (id == list[i].getEmployeeID()) {
			valid_id = false;
			break;
		}
	}


	// Checking the projects IDs
	for (int i = 0; i < employeeObject.getProjectList().size(); i++) {

		// this loop takes each project ID and tries to find it in the projectList
		for (int j = 0; j < projectList.getList().size(); j++) {
			if (employeeObject.getProjectList()[i] == projectList.getList()[j].getProjectID()) {
				valid_project = true; // the ith project 
				counter++; // if it's found, the counter will be incremented and we will break from the intermost loop. So even if there were duplicates of the same project ID, it wont be counted and thus counter wont ever be > the number of projects 
				break;
			}
		}

		// Reset the boolean to prepare for the next iteration
		if (valid_project == true)
		{
			valid_project = false;

		} // if we don't find a match, then we basically exit the loop as there is no need to continue
		else if (valid_project == false)
		{
			break;
		}

	}


	// Checking the department ID
	for (int i = 0; i < departmentList.getDepartmentList().size(); i++)
	{
		if (departmentList.getDepartmentList()[i].getID() == department_id)
		{
			valid_department = true;
			break;
		}
	}


	if (valid_id == true && counter == employeeObject.getProjectList().size() && valid_department == true) {
		list.push_back(employeeObject); // add to the employee list
		departmentList.getDepartment(department_id).addEmployee(id); // add the employee id to the department
		std::cout << "Successfully added to the employee list." << std::endl;
	}
	else {
		std::cout << "Cannot add to the employee list. The employee's ID, projects IDs, and/or the depertment ID are not valid." << std::endl;
	}


}

/*
Function description: This function is used retrieve the information of a specific employee
Input to function: An object of type Employee
Returns: void
*/
void EmployeeList::findEmployeeInfo(Employee& employeeObject) {
	int found_at_index = -1; // -1 means the employee is not foud

	for (int i = 0; i < list.size(); i++) {
		if (list[i].getEmployeeID() == employeeObject.getEmployeeID()) {
			found_at_index = i;
			break;
		}
	}

	if (found_at_index == -1) {
		std::cout << "Could not find the employee." << std::endl;
	}
	else {
		// cout << list[found_at_index]; // does not look nice when printed to the console
		std::cout << "Name: " << list[found_at_index].getName() << std::endl;
		std::cout << "Rank: " << list[found_at_index].getRank() << std::endl;
		std::cout << "Projects: ";
		for (int i = 0; i < list[found_at_index].getProjectList().size(); i++) {
			std::cout << list[found_at_index].getProjectList()[i] << " ";
		}
		std::cout << std::endl;
	}

}

/*
Function description: This function is used to delete a specific Employee based on his ID
Input to function: ID of employee to be deleted
Returns: Bool. This is essential in main because if true, the employee will then be deleted from the respective department.
*/
bool EmployeeList::deleteEmployee(int id) {

	int index = -1;
	// first we try to find the employee and update the index integer. If it stays as -1 then the employee is not found

	for (int i = 0; i < list.size(); i++) {
		if (list[i].getEmployeeID() == id) {
			index = i;
			break;
		}
	}


	if (index == -1) {
		std::cout << "Could not find the employee." << std::endl;
		return true;
	}
	else {
		list.erase(list.begin() + index);
		std::cout << "Successfully deleted." << std::endl;
		return false;
	}

}


/*
Function description: This function is usde to remove a project ID from every employee. This is used when we delete a project
Input: project ID to be removed from every employee
Returns: void
*/
void EmployeeList::removeProject(int id) {

	for (int i = 0; i < list.size(); i++) {
		// now we are in the ith index of the employee list vector

		int number_of_projects = list[i].getProjectList().size(); // size of the project id list in the ith project
		int index = -1; // the index in which the project id is stored at is assigned to this variable

						// finding the project 
		for (int j = 0; j < number_of_projects; j++) {
			// now we are in the jth index of the projects_id_list
			if (list[i].getProjectList()[j] == id) {
				index = j;
			}


			if (index != -1) {
				//list[i].getProjectList().erase(list[i].getProjectList().begin() + index);
				list[i].removeProject(index);
				break; // break from the inner loop
			}
		}
	}
}