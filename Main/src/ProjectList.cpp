#include "./ProjectList.h"

/*
Friends functions
*/

/*
Function description: This function is used to read in projects and store them in a vector
Input to function: Input stream and object of type projectList
Returns: Input stream.
*/
std::istream& operator>>(std::istream &input, ProjectList& projectList) {

	Project p; // temporary object of type project

	for (int i = 0; i < projectList.list.size(); i++) {
		input >> p; // we read EACH project
		projectList.list.push_back(p); // we push each project in the vector		 
	}

	return input;
}

/*
Function description: This function is used to print out the list of projects of the company with their respective details
Input to function: Output stream and object of type prijectList
Returns: Output stream.
*/
std::ostream& operator<<(std::ostream &output, ProjectList& projectList) {
	int number_of_projects = projectList.list.size();

	output << number_of_projects << std::endl;

	for (int i = 0; i < number_of_projects; i++) {
		output << projectList.list[i] << std::endl;
	}

	return output;
}



/*
Constructors
*/
ProjectList::ProjectList() {}

ProjectList::ProjectList(std::string file_name) {
	std::ifstream input(file_name);
	int number_of_projects;

	if (input.fail()) {
		std::cout << "Program failed to load " << file_name << ". Program will exit." << std::endl;
		exit(0);
	}

	input >> number_of_projects;
	// Why are we creating a new project with every loop iteration? Would'nt it work if we create a project before the loop and then re-read it
	// with every iteration?
	// *** yes you are right ***
	Project p; // temporary project
	for (int i = 0; i < number_of_projects; i++) {
		input >> p;
		list.push_back(p);
	}

	input.close();
}

ProjectList :: ~ProjectList() {

	std::ofstream output("projects.txt");
	if (output.fail()) {
		std::cout << "Program failed to save (projects.txt). Program will exit." << std::endl;
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
Function description: This function is used to add a project to the list of projects of the company.
Input to function: Object of type project
Returns: void
*/
void ProjectList::addProject(Project& p) {

	// We need to check the validity of the project. If the ID of the project is already used by another project, it should not be added 
	int id = p.getProjectID();
	bool valid = true;

	for (int i = 0; i < list.size(); i++) {

		if (id == list[i].getProjectID()) {
			valid = false;
			break;
		}

	}

	if (valid == true) {
		std::cout << "Successfully added to the project list." << std::endl;
		list.push_back(p);
	}
	else {
		std::cout << "Cannot add to the project list. The project ID is already used." << std::endl;
	}

}

/*
Function description : This function is used to return the list of projects from the projectsList class
Input to function : None
Returns : The vector "list".
*/
std::vector <Project> ProjectList::getList() {
	return list;
}

/*
Function description: This function is used retrieve the information of a specific project
Input to function: An object of type project
Returns: void
*/
void ProjectList::findProjectInfo(Project& p) {
	int found_at_index = -1; // -1 means the project is not found

	for (int i = 0; i < list.size(); i++) {
		if (list[i].getProjectID() == p.getProjectID()) {
			found_at_index = i;
			break;
		}
	}

	if (found_at_index == -1) {
		std::cout << "Could not find the project." << std::endl;
	}
	else {
		// cout << list[found_at_index]; // does not look nice when printed to the console
		std::cout << "Project name: " << list[found_at_index].getName() << std::endl;
		std::cout << "Project location: " << list[found_at_index].getLocation() << std::endl;
	}

}
/*
Function description: This function is used to delete a specific projecct based on his ID
Input to function: ID of project to be deleted and the employee list.
Returns: void
*/

void ProjectList::deleteProject(int id) {

	int index = -1;
	// first we try to find the project and update the index integer. If it stays as -1 then the project is not found

	for (int i = 0; i < list.size(); i++) {
		if (list[i].getProjectID() == id) {
			index = i;
			break;
		}
	}


	if (index == -1) {
		std::cout << "Could not find the project." << std::endl;
	}
	else { // we delete the project from the project list AND delete it from each employee
		list.erase(list.begin() + index);
		std::cout << "Successfully deleted." << std::endl;
	}
}