/////////////////////////////////////////////////////////////////////////
// TACOURSE CLASS
// Contains all of the attributes and functions of a TA'd course

#ifndef TACOURSE_H
#define TACOURSE_H

#include "Course.h"

class Course;
class Manager;

class TACourse : public Course {
	public:
		TACourse(string, Manager*);
		~TACourse();

		Manager* manager;

		string  getTerm();
		string  getYear();
		string  getSupervisor();

		void setCourse(string);
		void setDataMembers(string, string, string);


	private:
		string   term;
		string   year;
		string   supervisor;
};

#endif
