#include "Employee.h"

Employee::Employee(char* name, const Address& address):emp_name(name), emp_address(address)
{
	projectsize=0;
	projectlist = new Project*[2];
}

Employee::Employee(const Employee&c):emp_name(c.emp_name), emp_address(c.emp_address)
{
	projectsize=0;
	projectlist = new Project*[2];
}

ostream& operator<<(ostream& osObject, const Employee&c)
{
	osObject << "The employee name is: " << c.emp_name << endl << "The address is: " << c.emp_address << endl << "PROJECTS:"<<endl;
	for (int i = 0; i < c.projectsize; i++)
	{
		cout << *c.projectlist[i] << endl;
	}
	return osObject;
}

const Employee &  Employee:: operator=(const Employee& other)
{
	this->emp_name = other.emp_name;
	this->emp_address = other.emp_address;
	this->projectlist = new Project*[2];
	for (int i = 0; i < 2; i++)
	{
		this->projectlist[i] = other.projectlist[i];
	}
	this->projectsize = other.projectsize;

	return *this;
}

void Employee::addProject(Project const *project )
{
	if(projectsize>=2)
		cout << "No new projects can be entered for this employee \n";
	else
	{
		projectlist[projectsize] = new Project(*project);
		projectsize++;
	}
}

void Employee::removeProject(Project const *project)
{
	
	for (int i = 0; i < 2; i++)
	{
		if (projectlist[i]->exists(project))
		{
			for (int j = i; i < 2; j++)
			{
				this->projectlist[j] = projectlist[j + 1];
			}
		}
	}
	projectsize--;
	
}

Employee::~Employee()
{
	delete[]emp_name;
	emp_name = nullptr;
	delete projectlist[0], projectlist[1];
	delete projectlist;
	projectlist = nullptr;

}