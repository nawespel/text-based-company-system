#include "./ProjectList.h"
#include "./EmployeeList.h"
#include "./DepartmentList.h"

// Non-member functions
void newLine(std::ostream & output, int a);
void printCommandList();

int main() {

	// Declarations
	bool run = true;
	int command;
	std::ifstream input;
	ProjectList projectList("./textfiles/projects.txt");
	EmployeeList employeeList("./textfiles/employees.txt");
	DepartmentList departmentList("./textfiles/departments.txt");

	std::cout << "Welcome to Company System.";
	newLine(std::cout, 30);

	/*
	After reading the information, we can now ask the user for what they want to do with the loaded data.
	*/
	std::cout << "\t\t\tCommand list:" << std::endl;
	printCommandList();
	newLine(std::cout, 30);
	// the run loop
	while (run) {
		std::cout << "Enter the command: ";
		std::cin >> command;

		switch (command) {
		case 0: // reprint the command list
			newLine(std::cout, 30);
			std::cout << "\t\t\tCommand list" << std::endl;
			printCommandList();
			newLine(std::cout, 30);
			break;
		case 1: // list all departments and their employees
			newLine(std::cout, 10);
			std::cout << "\t\t\tList all departments and their employees" << std::endl;
			std::cout << departmentList;
			newLine(std::cout, 10);
			break;
		case 2: // list all employees and the projects they are working on
			newLine(std::cout, 10);
			std::cout << "\t\t\tList all employees and the projects they work on" << std::endl;
			std::cout << employeeList;
			newLine(std::cout, 10);
			break;

		case 3:
			newLine(std::cout, 10);
			std::cout << "\t\t\tPrint project list" << std::endl;
			std::cout << projectList;
			newLine(std::cout, 10);
			break;

		case 4: // add new employee
		{
			newLine(std::cout, 10);
			std::cout << "\t\t\tAdd new employee" << std::endl;
			// read temporary values including the project IDs list
			int id; std::string name; std::string rank; int num_of_projects; int tmp; int departmentID; std::vector <int> project_id_list;
			std::cout << "Enter the ID of the employee: "; std::cin >> id;
			std::cout << "Enter the name of the employee (without spaces): "; std::cin >> name;
			std::cout << "Enter the rank of the employee (without spaces): "; std::cin >> rank;
			std::cout << "Enter the number of projects he/she is working on: "; std::cin >> num_of_projects;
			for (int i = 0; i < num_of_projects; i++) {
				std::cout << "Enter the ID of project number " << i + 1 << ": ";
				std::cin >> tmp;
				project_id_list.push_back(tmp);
			}
			std::cout << "Enter the ID of the department the employee is working in: "; std::cin >> departmentID;
			// create a temporary employee object using the constructor
			Employee tmpEmployee(id, name, rank, project_id_list);
			// pass the object to addEmployee() function
			employeeList.addEmployee(tmpEmployee, projectList, departmentID, departmentList); // the validity of the employee will be checked inside this function
			newLine(std::cout, 10);
			break;
		}

		case 5: // add new project
		{
			newLine(std::cout, 10);
			std::cout << "\t\t\tAdd new project" << std::endl;
			// read temporary values:
			int id; std::string name; std::string location;
			std::cout << "Enter the ID of the project: "; std::cin >> id;
			std::cout << "Enter the name of the project (without spaces): "; std::cin >> name;
			std::cout << "Enter the location of the project (without spaces): "; std::cin >> location;
			// create a temporary project object using the constructor
			Project project(id, name, location); // validity check is done inside the function
			projectList.addProject(project);
			newLine(std::cout, 10);
			break;
		}
		case 6:
			//Find employee by ID and list their information
		{
			newLine(std::cout, 10);
			std::cout << "\t\t\tFind employee by ID and list their information" << std::endl;
			int id;
			std::cout << "Enter the ID of the employee you wish to find: "; std::cin >> id;
			Employee tmpEmployee;
			tmpEmployee.setEmployeeID(id);
			employeeList.findEmployeeInfo(tmpEmployee);
			newLine(std::cout, 10);
			break;
		}

		case 7:
			// Find project by ID and list its information
		{
			newLine(std::cout, 10);
			std::cout << "\t\t\tFind project by ID and list its information" << std::endl;
			int id;
			std::cout << "Enter the ID of the project: "; std::cin >> id;
			Project tmpProject;
			tmpProject.setProjectID(id);
			projectList.findProjectInfo(tmpProject);
			newLine(std::cout, 10);
			break;
		}

		case 8:
			// Delete an employee by ID
		{
			newLine(std::cout, 10);
			std::cout << "\t\t\tDelete an employee by ID" << std::endl;
			int id;
			std::cout << "Enter the ID of the employee: "; std::cin >> id;
			if (employeeList.deleteEmployee(id));
			departmentList.deleteEmployeefromDepartmentList(id);
			newLine(std::cout, 10);
			break;
		}
		case 9:
		{
			// Delete project by ID
			newLine(std::cout, 10);
			std::cout << "\t\t\tDelete project by ID" << std::endl;
			int id;
			std::cout << "Enter the ID of the project: "; std::cin >> id;
			projectList.deleteProject(id); // delete the project from the project list
			employeeList.removeProject(id); // delete the project from each employee
											/*
											We could've included the second fucntion call in the first one but that would've resulted in Circular Dependency.
											*/
			newLine(std::cout, 10);
			break;
		}
		case 10:
			run = false;
			newLine(std::cout, 20);
			break;


		default:
			newLine(std::cout, 10);
			std::cout << "You have entered an invalid command. Please try again." << std::endl;
			newLine(std::cout, 10);
		}
	}

	std::cout << "Thank you for using Company System.\n";
	/*
	We exit the run loop only when we want to exit the program.
	This is where the destructors will be called and save data back to the file
	*/

	// At the end destructors will be called
	return 0;
}

/*
This function is used for cosmetic effects.
Instead of writing std::cout each time for the dashes, this function saves time for us
*/
void newLine(std::ostream & output, int a) {

	for (int i = 0; i < a; i++) {
		output << "-";
	}
	output << std::endl;
}

/*
Maybe we can have sun menus for extra features? So for example we select Projects then we get
options. Ex: Add a project - Delete a project - View a list of the projects - etc
*/
void printCommandList() {
	std::cout << "0.\tReprint the command list" << std::endl; // x
	std::cout << "1.\tList all departments and their employees" << std::endl; // x
	std::cout << "2.\tList all employees and the projects they work on" << std::endl; // x
	std::cout << "3.\tPrint project list" << std::endl; // x
	std::cout << "4.\tAdd new employee" << std::endl; // x
	std::cout << "5.\tAdd new project" << std::endl; // x
	std::cout << "6.\tFind employee by ID and list their information" << std::endl; // x
	std::cout << "7.\tFind project by ID and list its information" << std::endl; // x
	std::cout << "8.\tDelete an employee by ID" << std::endl; // x
	std::cout << "9.\tDelete project by ID" << std::endl;  // x
	std::cout << "10.\tExit" << std::endl; // x
}