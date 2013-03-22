//////////////////////////////////////////////////////////////////////////
// CREATE COURSES INFORMATION UI
// Prompts user to give more information about related courses

#include <fstream>

#include "CourseEditUI.h"
#include "StuAppFormUI.h"
#include "GradAppFormUI.h"
#include "AcceptEditUI.h"
#include "CourseQueue.h"
#include "UGradApp.h"
#include "GradApp.h"
#include "TACourseQueue.h"
using namespace std;
//////////////////////////////////////////////////////////////////////////
// Constructor
CourseEditUI::CourseEditUI(Manager* aManager, int i, UGradAppQueue::Node* n) 
	: createTable(6, 3, false),
	termLabel("Term: "), 
	yearLabel("Year: "),
	nextButton("Next"),
	courseButton("New Course"),
	backButton("Back"),
	node(n),
	courseQueue(n->data->getTakenCrsQueue()),
	TAcourseQueue(n->data->getTACrsQueue())
	  //tCourse(courseQueue->front()->data)
{
	offset = 0;
	yearComboList = new string[MAX_BUF];
	courseComboList = new string[MAX_BUF];
	gradeComboList = new string[MAX_BUF];
	termComboList = new string[3];
	//test = new string[MAX_BUF];
	whichCourse = i;
	initWindow(aManager);
}

//////////////////////////////////////////////////////////////////////////
// Makes the window according to whichCourse
void CourseEditUI::initWindow(Manager* aManager) {
	cout<<"Wotcher!:"<<courseQueue->front()->data->getName()<<":"<<endl;
	manager = aManager;

	set_default_size(500, 550);
	set_title("cuTAES");
	set_modal(true);
	set_position(Gtk::WIN_POS_CENTER_ALWAYS);
	set_deletable(false);
	add(createTable);

	if (whichCourse == 0) {
		aLabel.set_text("Select a related course taken:\nAll courses must be re added to be included in edit.");
		finalLabel.set_text("Final Grade:\nUse bottom buttons to navigate.");
	} 
	else {
		aLabel.set_text("Select a course TA'd for:\n All courses must be re added to be included in edit.");
		finalLabel.set_text("Supervisor: \n Use bottom buttons to navigate.");
		courseCombo.append("None");
	}


	string  superComboList[MAX_BUF];
	string  info[MAX_BUF];
	int    count = 0;
	ifstream infile("info.txt", ios::in);
	int n=0;
	if (!infile) {
		cout << "Could not open file" << endl;
	}
	while (!infile.eof()) {
		getline(infile, info[count]);
		count++;
	}
	//Fill in courses combo
	// Iterate through course queue and put names into comboBox

	CourseQueue::Node* currNode = manager->getCourseQueue()->front();
	while (currNode != 0){ 
		courseCombo.append(currNode->data->getName());
		courseComboList[n]=currNode->data->getName();
		n++;
		currNode = currNode->next;
	}
	courseCombo.set_active(0);

	//Fill the combo
	int i;
	n=0;
	for (i=0; i<(count-1); i++){
		if(info[i] != "~"){
			termCombo.append(info[i]);
			termComboList[n]=info[i];
			n++;}
		else break;
	}
	n=0;
	for( i= i+1; i <(count -1); i++){
		if(info[i] != "~"){
			yearCombo.append(info[i]);    
			yearComboList[n]=info[i];  
			n++;}
		else break;
	}
	n=0;
	if (whichCourse ==0){
		for( i= i+1; i <(count -1); i++){
			finalCombo.append(info[i]);
			gradeComboList[n]=info[i];
			n++;
		}
	}
	else {
		//Read from faculty file using getline function
		count = 0; 
		ifstream infile2("faculty.txt", ios::in);
		if (!infile2) {
			cout << "Could not open file" << endl;
		}
		while (!infile2.eof()) {
			getline(infile2, superComboList[count]);
			count++;
		}
		for (i=0; i<(count); i++){ 
			finalCombo.append(superComboList[i]);
			gradeComboList[i]=superComboList[i];	
	}}


	termCombo.set_active(0);
	yearCombo.set_active(0);
	finalCombo.set_active(0);
	refresh();
	createTable.attach(aLabel, 0, 2, 0, 1, Gtk::FILL,Gtk::FILL, 0, 42);
	createTable.attach(courseCombo, 2, 3, 0, 1, Gtk::FILL,Gtk::FILL, 10, 30);

	createTable.attach(termLabel, 0, 1, 1, 2);
	createTable.attach(termCombo, 1, 3, 1, 2, Gtk::FILL,Gtk::FILL,75, 20); 
	createTable.attach(yearLabel, 0, 1, 2, 3);
	createTable.attach(yearCombo, 1, 3, 2, 3, Gtk::FILL,Gtk::FILL,75, 20); 
	createTable.attach(finalLabel, 0, 1, 3, 4);
	createTable.attach(finalCombo, 1, 3, 3, 4, Gtk::FILL,Gtk::FILL,75, 20); 
	createTable.attach(backButton, 0, 1, 4, 5, Gtk::FILL,Gtk::FILL,5, 50); 
	createTable.attach(courseButton, 1, 2, 4, 5,Gtk::FILL,Gtk::FILL,8, 50);
	createTable.attach(nextButton, 2, 3, 4, 5, Gtk::FILL,Gtk::FILL,5, 50); 
	createTable.attach(firstCourseButton, 0, 1, 6, 7, Gtk::FILL,Gtk::FILL,5, 50); 
	createTable.attach(nextCourseButton, 1, 2, 6, 7, Gtk::FILL,Gtk::FILL,5, 50); 

	nextButton.signal_clicked().connect(
			sigc::bind<Glib::ustring>( sigc::mem_fun(*this, &CourseEditUI::on_nextButton), "Next") );
	backButton.signal_clicked().connect(
			sigc::bind<Glib::ustring>( sigc::mem_fun(*this, &CourseEditUI::on_backButton), "Back") );
	courseButton.signal_clicked().connect(
			sigc::bind<Glib::ustring>( sigc::mem_fun(*this, &CourseEditUI::on_courseButton), "New Course") );
	firstCourseButton.signal_clicked().connect(
			sigc::bind<Glib::ustring>( sigc::mem_fun(*this, &CourseEditUI::on_firstCourseButton), "First Course") );

	nextCourseButton.signal_clicked().connect(
			sigc::bind<Glib::ustring>( sigc::mem_fun(*this, &CourseEditUI::on_nextCourseButton), "Next Course") );


	show_all_children();
	//cout << "CONSTRUCT CourseEditUI" << endl;
}


//////////////////////////////////////////////////////////////////////////
// Destructor
CourseEditUI::~CourseEditUI() {
	//cout << "DESTRUCT CourseEditUI" << endl;
}


//////////////////////////////////////////////////////////////////////////
// Event handler of next button
void CourseEditUI::on_nextButton(const Glib::ustring& data){
	if (whichCourse == 0) {
		TakenCourse* takenCourse = new TakenCourse(courseCombo.get_active_text(), manager);
		takenCourse->setDataMembers(termCombo.get_active_text(), yearCombo.get_active_text(), finalCombo.get_active_text());
		manager->getCurrUGradApp()->getTakenCrsQueue()->pushBack(takenCourse);    
		CourseEditUI* crsInfoWin = new CourseEditUI(manager, 1, node); 
		crsInfoWin->show();
	}
	else {
		if (courseCombo.get_active_text() == "None") {}
		else {
			TACourse* tACourse = new TACourse(courseCombo.get_active_text(), manager);
			tACourse->setDataMembers(termCombo.get_active_text(), yearCombo.get_active_text(), finalCombo.get_active_text()); 
			if (manager->getCurrUGradApp() != 0)
				manager->getCurrUGradApp()->getTACrsQueue()->pushBack(tACourse);
			else
				manager->getCurrGradApp()->getTACrsQueue()->pushBack(tACourse);      
		}
	//Add other application info
	manager->getCurrUGradApp()->setWorkExpQueue(node->data->getWorkExpQueue());
	//manager->getCurrUGradApp->set
	AcceptEditUI * acceptUI = new AcceptEditUI(manager);
	acceptUI ->show();


	}

	delete this;
}

//////////////////////////////////////////////////////////////////////////
// Event handler of back button
void CourseEditUI::on_backButton(const Glib::ustring& data){  
	// Clear taken/TAcourse queues
	if (manager->getCurrUGradApp() != 0) { 
		if (whichCourse == 0) {
			if (!(manager->getCurrUGradApp()->getTakenCrsQueue()->empty()));
			manager->getCurrUGradApp()->getTakenCrsQueue()->clear();
			//StuAppFormUI* stuFormWin = new StuAppFormUI(manager, 0);
			//stuFormWin->show();
		}
		else {
			if (!(manager->getCurrUGradApp()->getTACrsQueue()->empty()));
			manager->getCurrUGradApp()->getTACrsQueue()->clear();
			//CourseEditUI* crsInfoWin = new CourseEditUI(manager, 0); 
			//crsInfoWin->show();
		}
	}
	else {
		if (!(manager->getCurrGradApp()->getTACrsQueue()->empty()));
		manager->getCurrGradApp()->getTACrsQueue()->clear();
		//GradAppFormUI* gradFormWin = new GradAppFormUI(manager, 0);
		//gradFormWin->show();
	}

	delete this;
}

//////////////////////////////////////////////////////////////////////////
// Event handler of course button
void CourseEditUI::on_courseButton(const Glib::ustring& data){ 
	if (courseCombo.get_active_text() == "None") {
		Gtk::MessageDialog dialog(*this, "ERROR!"); 
		dialog.set_secondary_text("Please select a course"); 
		dialog.run();
		return;
	}
	else{
	Gtk::MessageDialog dialog(*this, "Added"); 
		dialog.set_secondary_text("The data has been added."); 
		dialog.run();
		return;

	}

	if (whichCourse == 0) {
		TakenCourse* takenCourse = new TakenCourse(courseCombo.get_active_text(), manager);
		takenCourse->setDataMembers(termCombo.get_active_text(), yearCombo.get_active_text(), finalCombo.get_active_text());
		manager->getCurrUGradApp()->getTakenCrsQueue()->pushBack(takenCourse);
	}
	else {
		TACourse* tACourse = new TACourse(courseCombo.get_active_text(), manager);
		tACourse->setDataMembers(termCombo.get_active_text(), yearCombo.get_active_text(), finalCombo.get_active_text());  
		if (manager->getCurrUGradApp() != 0)
			manager->getCurrUGradApp()->getTACrsQueue()->pushBack(tACourse);
		else
			manager->getCurrGradApp()->getTACrsQueue()->pushBack(tACourse);
	}
	/*
	   if (whichCourse == 0) {
	   CourseEditUI* crsInfoWin = new CourseEditUI(manager, 0, node); 
	   crsInfoWin->show();  
	   } 
	   else {
	   CourseEditUI* crsInfoWin = new CourseEditUI(manager, 1, node); 
	   crsInfoWin->show();
	   }

	   delete this;
	 */
}

void CourseEditUI::on_firstCourseButton(const Glib::ustring& data){
	offset=0;	
	refresh();
}
void CourseEditUI::on_nextCourseButton(const Glib::ustring& data){
	int size;
	if(whichCourse==0)size=courseQueue->size()-1;
	else size=TAcourseQueue->size()-1;
	if (offset<size){

		offset++;
	}
	else{
		offset =0;
	}
	refresh();
}
void CourseEditUI::refresh(){
	if(whichCourse==0){
		TakenCourseQueue::Node * temp = courseQueue->front();	
		int i;
		for(i=0;i<offset;i++){
			temp = temp->next;
		}
		for(i=0;i<3;i++){
			if(termComboList[i]==temp->data->getTerm()){
				termCombo.set_active(i);
				break;
			}
		}
		for(i=0;i<13;i++){
			if(gradeComboList[i]==temp->data->getFinalGrade()){
				finalCombo.set_active(i);
				break;
			}
		}
		for(i=0;i<MAX_BUF;i++){

			if(courseComboList[i]==temp->data->getName()){
				courseCombo.set_active(i);
				break;
			}
		}
		for(i=0;i<MAX_BUF;i++){
			if(yearComboList[i]==temp->data->getYear()){
				yearCombo.set_active(i);
				break;
			}
		}
	}
	else{
	if(!TAcourseQueue->empty()){
TACourseQueue::Node * temp = TAcourseQueue->front();	
		int i;
		for(i=0;i<offset;i++){
			temp = temp->next;
		}

		for(i=0;i<3;i++){
			if(termComboList[i]==temp->data->getTerm()){
				termCombo.set_active(i);
				break;
			}
		}
		for(i=0;i<MAX_BUF;i++){
			if(gradeComboList[i]==temp->data->getSupervisor()){
				finalCombo.set_active(i);
				break;
			}
		}
		for(i=0;i<MAX_BUF;i++){

			if(courseComboList[i]==temp->data->getName()){
				courseCombo.set_active(i);
				break;
			}
		}
		for(i=0;i<MAX_BUF;i++){
			if(yearComboList[i]==temp->data->getYear()){
				yearCombo.set_active(i);
				break;
			}
		}

}
	}
}
