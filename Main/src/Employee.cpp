#include "./Employee.h"

/*
Friend functions
*/

/*
Function description: This function is used to print out an object of type Employee
Input to function: Output stream and object of type Employee
Returns: Output stream.
*/
std::ostream& operator<<(std::ostream& output, Employee& employee) {

	output << employee.ID << " " << employee.name << " " << employee.rank << " " << employee.project_ID_list.size() << std::endl;
	for (int i = 0; i < employee.project_ID_list.size(); i++)
	{
		output << employee.project_ID_list[i] << std::endl;
	}
	return output;
}

/*
Function description: This function is used to read in an object type Employee with its respective details
Input to function: Input stream and object of type Employee
Returns: Input stream.
*/

std::istream& operator>>(std::istream& input, Employee& employee) {

	input >> employee.ID >> employee.name >> employee.rank;
	int number_of_projects_of_employee;
	int project_ID;
	input >> number_of_projects_of_employee;
	employee.project_ID_list.clear();
	for (int i = 0; i < number_of_projects_of_employee; i++)
	{
		input >> project_ID;
		employee.project_ID_list.push_back(project_ID);
	}
	return input;
}


/*
Constructors
*/

Employee::Employee() {
	ID = -1;
	name = "NO_NAME";
	rank = "NO_RANK";
	// the vector is already empty so there is no need to do anything to it
}


Employee::Employee(int id, std::string name, std::string rank, std::vector <int> project_id_list) {
	this->ID = id;
	this->name = name;
	this->rank = rank;
	this->project_ID_list = project_id_list;
}

/*
Public functions
*/

/*
Function description: This function is used to return the ID of an employee
Input to function: None
Returns: ID of an employee.
*/
int Employee::getEmployeeID() {
	return ID;
}

/*
Function description: This function is used to return the name of an employee
Input to function: None
Returns: Name of an employee.
*/
std::string Employee::getName() {
	return name;
}
/*
Function description: This function is used to return the rank of an employee
Input to function: None
Returns: Rank of an employee.
*/
std::string Employee::getRank() {
	return rank;
}

/*
Function description: This function is used to set the ID of an employee
Input to function: ID of an employee
Returns: void
*/
void Employee::setEmployeeID(int id) {
	this->ID = id;
}
/*
Function description: This function is used to return list of project IDs in the Employee class
Input to function: None
Returns: the vector "project_ID_list"
*/
std::vector <int> Employee::getProjectList() {
	return project_ID_list;
}

/*
Function description: This function is used to remove a project ID from the project list vector for the employee
Input: the index to be erased
returns: nothing
*/
void Employee::removeProject(int index) {
	project_ID_list.erase(project_ID_list.begin() + index);
}