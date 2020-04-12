#pragma once
#include <iostream>
#include <string>



class Project {

	// Operator overloading function that reads ONE project.
	friend std::istream& operator>>(std::istream &input, Project& project);


	// Operator overloading function that prints ONE project.
	friend std::ostream& operator<<(std::ostream &output, Project& project);


private:
	int ID;
	std::string name;
	std::string location;

public:
	Project();
	Project(int id, std::string name, std::string location);
	int getProjectID();
	std::string getName(); // used for case 6
	std::string getLocation(); // used for case 6
	void setProjectID(int id);

};

