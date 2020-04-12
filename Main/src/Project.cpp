#include "./Project.h"


/*
Friend functions
*/

/*
Function description: This function is used to read in an object type project with its respective details
Input to function: Input stream and object of type project
Returns: Input stream.
*/
std::istream&  operator>>(std::istream &input, Project& project) {
	input >> project.ID >> project.name >> project.location;
	return input;
}

/*
Function description: This function is used to print out an object of type project
Input to function: Output stream and object of type project
Returns: Output stream.
*/
std::ostream&  operator<<(std::ostream &output, Project& project) {
	output << project.ID << " " << project.name << " " << project.location << std::endl;
	return output;
}


/*
Constructors
*/

Project::Project() {
	ID = -1;
	name = "NO_NAME";
	location = "NO_LOCATION";
}

Project::Project(int id, std::string name, std::string location) {
	this->ID = id;
	this->name = name;
	this->location = location;
}

/*
Public functions
*/

/*
Function description: This function is used to return the ID of a project
Input to function: None
Returns: ID of a project
*/
int Project::getProjectID() {
	return ID;
}

/*
Function description: This function is used to set the ID of a project
Input to function: ID of a project
Returns: void
*/
void Project::setProjectID(int id) {
	this->ID = id;
}

/*
Function description: This function is used to return the name of a project
Input to function: None
Returns: Name of a project
*/
std::string Project::getName() {
	return name;
}

/*
Function description: This function is used to return the location of a project
Input to function: None
Returns: Location of a project
*/
std::string Project::getLocation() {
	return location;
}

