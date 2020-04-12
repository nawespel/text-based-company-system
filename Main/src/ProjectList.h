#pragma once


#include <fstream>
#include <vector>
#include "./Project.h"


class ProjectList {
	/*THIS FUNCTION IS NOT USED TO READ THE PROJECT LIST FILE. READING THE FILE IS DONE IN THE CONSTRUCTOR
	Operator overloading function that reads the list of the projects.
	This will be used to read from the text file when the ProjectList object is declared (using a constructor)
	*/
	friend std::istream& operator>>(std::istream &input, ProjectList& projectList);


	/*
	Operator overloading function that prints the list of the projects.
	This will be used to write back to the text file after closing the program
	*/
	friend std::ostream& operator<<(std::ostream &output, ProjectList& projectList);

private:
	std::vector <Project> list;

public:
	/*
	Constuctors. The non-default constructor will read the projects and add them to the project list vector.
	*/
	ProjectList();
	ProjectList(std::string file_name);
	~ProjectList();
	/*
	Public methods
	*/
	void addProject(Project& p);
	void findProjectInfo(Project& p);
	void deleteProject(int id);
	std::vector <Project> getList(); // to be used when adding an employee for validity purposes
};

