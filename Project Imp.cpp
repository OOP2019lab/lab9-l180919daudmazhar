#include "Project.h"
Project::Project(char* name, int budget, int duration)
{
	this->name = name;
	this->budget = budget;
	this->duration = duration;
}

Project::Project(const Project& c)
{
	this->name = c.name;
	this->budget = c.budget;
	this->duration = c.duration;
}

ostream& operator<<(ostream& osObject, const Project&c)
{
	osObject << "The project name is: " << c.name << endl << "The budget is: " << c.budget << endl <<  "The duration is: "<< c.duration<<endl;
	return osObject;
}

const Project &  Project:: operator=(const Project& other)
{
	this->name = other.name;
	this->budget = other.budget;
	this->duration = other.duration;
	return *this;
}

bool Project::exists(Project const *c)const
{
	if (strlen(name) == strlen(c->name))
	{
		for (int i = 0; i < strlen(name); i++)
		{
			if (name[i] != c->name[i])
			{
				return false;
			}
		}
		return true;
	}
	else
		return false;
}

void Project::setBudget(int i)
{
	this->budget = i;
}

Project::~Project()
{
	delete[]name;
	name = nullptr;
}