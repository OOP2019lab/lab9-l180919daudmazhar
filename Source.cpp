#include "Address.h"
#include "Project.h"
#include "Employee.h"


Address::Address(char* h_no, char* St_Name, char * City_name,char* Country_name)
{
	
	house_Number = h_no;
	street_Name = St_Name;
	city = City_name;
	country = Country_name;
}

 Address::Address(const Address &c)
 {
	 this->city=c.city;
	 this->country=c.country;
	 this->house_Number = c.house_Number;
	 this->street_Name = c.street_Name;
 }

 ostream& operator<<(ostream& osObject, const Address&c)
 {
	 osObject << c.house_Number << ", " << c.street_Name << ", " << c.city << ", " << c.country;
	 return osObject;
 }

 const Address &  Address:: operator=(const Address& other)
 {
	 this->city = other.city;
	 this->country = other.country;
	 this->house_Number = other.house_Number;
	 this->street_Name = other.street_Name;

	 return *this;
 }

 Address::~Address()
 {
	 house_Number=nullptr;
	 street_Name=nullptr ;
	 city=nullptr;
	 country=nullptr;
 }