//////////////////////////////////////////////////////////////////////////
// STUDENT APPLICATION FORM EDIT WINDOW
// Prompts user to edit their general information

#include <locale>  // for isdigit, isalpha, ispunct, char_traits
#include <fstream>
#include <string>
#include "CourseInfoUI.h"
#include "StuAppEditUI.h"
#include "CourseEditUI.h"
#include "StudentNumberUI.h"
#include "Tools.h"
#include "CourseQueue.h"
#include "UGradApp.h"
#include "UGradAppQueue.h"

//////////////////////////////////////////////////////////////////////////
// Default constructor
StuAppEditUI::StuAppEditUI(Manager* aManager, bool * rpt, int appNumIn) 
	: appTable(11, 3, false),
	label("Please enter your information: "),
	nextButton("Next"),
	backButton("Back"),
	appNumber(appNumIn)
{
	manager = aManager;
	int i=0, count=0;

	set_default_size(700, 475);
	set_title("cuTAES");
	set_position(Gtk::WIN_POS_CENTER_ALWAYS);
	set_deletable(false);

	// Scrolled window settings
	scrolledWindow.set_border_width(5);
	scrolledWindow.set_policy(Gtk::POLICY_ALWAYS, Gtk::POLICY_ALWAYS);
	get_vbox()->pack_start(scrolledWindow);
	appTable.set_row_spacings(11);
	appTable.set_col_spacings(3);

	// Add labels
	appTable.attach(label, 0, 4, 0, 1);
	string stuLabels[9] = {"Select a Course to TA for:", "Student Number*: ", "First Name*: ", "Surname*: ", "Email*: ", 
		"Major*: ", "Current Year Standing*: ", "CPGA*: ", "Major GPA*: " };		      
	for(i = 0; i < 9; i++) {
		aLabel = Gtk::manage(new Gtk::Label(stuLabels[i]));
		aLabel->set_alignment(0, 0.5);
		appTable.attach(*aLabel, 0, 1, i + 1, i + 2);
	}

	// Email combo box
	emailCombo.append("@cmail.carleton.ca");
	emailCombo.append("@connect.carleton.ca");

	// Courses combo box
	// Iterate through course queue and put names into comboBox
	CourseQueue::Node* currNode = manager->getCourseQueue()->front();

	while (currNode != 0){ 
		courseCombo.append(currNode->data->getName());
		currNode = currNode->next;
	}
	courseCombo.set_active(0);

	// Fill in Major combo box from file
	string majors[350];

	ifstream infile("majors.txt", ios::in);
	if (!infile) 
		cout << "Could not open file" << endl;

	while (!infile.eof()) {
		getline(infile, majors[count]);
		count++;
	}

	for (i=0; i<(count); i++) 
		majorCombo.append(majors[i]);

	//Recall the application information
	UGradAppQueue::Node * n = (manager->getUGradApps()->front());
	bool found=false;
	cout<<"Searching for:"<<appNumber<<endl;
	while(n->next != 0){
		if(n->data->getAppNum()==appNumber){
			found=true;
			cout<<"Found app#:" <<n->data->getAppNum()<<endl;
			break;
		}
		else cout<<"Not"<<endl;
		n=n->next;
	}
	if(!found){
		noApplicationDialog();
		cout<<"No application found"<<endl;
		*rpt = false;	
	}
	else{	
		node=n;
		string text, emailName, emailDomain, aMajor;

		stuNumEntry.set_text(n->data->getUndergrad()->getStuNum());
		nameEntry.set_text(n->data->getUndergrad()->getFirstName());
		surnameEntry.set_text(n->data->getUndergrad()->getSurname());

		text = n->data->getUndergrad()->getEmail();
		emailName = text.substr(0, text.find("@"));
		emailDomain = text.substr(text.find("@"));

		emailEntry.set_text(emailName);
		if (emailDomain == "@cmail.carleton.ca")
			emailCombo.set_active(0);
		else
			emailCombo.set_active(1);

		aMajor = n->data->getUndergrad()->getMajor();
		for (i=0; i<count; i++) {
			if (majors[i] == aMajor) {
				majorCombo.set_active(i);
				break;
			}
		}

		yearEntry.set_text(Tools::floatToString(n->data->getUndergrad()->getYear()));
		cgpaEntry.set_text(Tools::floatToString(n->data->getUndergrad()->getCGPA()));
		mgpaEntry.set_text(Tools::floatToString(n->data->getUndergrad()->getMGPA()));

		// Add widgets to table
		appTable.attach(courseCombo, 1, 2, 1, 2);
		appTable.attach(stuNumEntry, 1, 3, 2, 3);
		appTable.attach(nameEntry, 1, 3, 3, 4);
		appTable.attach(surnameEntry, 1, 3, 4, 5);
		appTable.attach(emailEntry, 1, 2, 5, 6);
		appTable.attach(emailCombo, 2, 3, 5, 6);
		appTable.attach(majorCombo, 1, 3, 6, 7);
		appTable.attach(yearEntry, 1, 3, 7, 8);
		appTable.attach(cgpaEntry, 1, 3, 8, 9);
		appTable.attach(mgpaEntry, 1, 3, 9, 10);
		appTable.attach(backButton, 1, 2, 10, 11);
		appTable.attach(nextButton, 2, 3, 10, 11);
		scrolledWindow.add(appTable);

		// Widget action listeners
		nextButton.signal_clicked().connect(
				sigc::bind<Glib::ustring>( sigc::mem_fun(*this, &StuAppEditUI::on_nextButton), "Next") );
		backButton.signal_clicked().connect(
				sigc::bind<Glib::ustring>( sigc::mem_fun(*this, &StuAppEditUI::on_backButton), "Back") );
	
	show_all_children();
	}//cout << "CONSTRUCT StuAppEditUI" << endl;
}

//////////////////////////////////////////////////////////////////////////
// Destructor
StuAppEditUI::~StuAppEditUI() {
	//cout << "DESTRUCT StuAppEditUI" << endl;
}


//////////////////////////////////////////////////////////////////////////
// Checks if any of the entry fields are empty
int StuAppEditUI::isEmpty() {
	if ((stuNumEntry.get_text()).find_first_not_of(' ')  == string::npos ||
			(nameEntry.get_text()).find_first_not_of(' ')    == string::npos ||
			(surnameEntry.get_text()).find_first_not_of(' ') == string::npos ||
			(emailEntry.get_text()).find_first_not_of(' ')   == string::npos ||
			(yearEntry.get_text()).find_first_not_of(' ')    == string::npos ||
			(cgpaEntry.get_text()).find_first_not_of(' ')    == string::npos ||
			(mgpaEntry.get_text()).find_first_not_of(' ')    == string::npos)
		return 1;
	else
		return 0;
}

//////////////////////////////////////////////////////////////////////////
// Checks if all entries are full and valid
// @return 0 if empty or not valid
// @return 1 if fill and valid
int StuAppEditUI::validEntries(){
	if (isEmpty() || (!Tools::validStuNum(stuNumEntry.get_text()) || !Tools::validName(nameEntry.get_text()) ||
				!Tools::validName(surnameEntry.get_text()) || !Tools::validEmail(emailEntry.get_text()) || !Tools::validNumber(yearEntry.get_text()) || 
				!Tools::validGPA(cgpaEntry.get_text()) || !Tools::validGPA(mgpaEntry.get_text()))) {
		errorDialog();
		return 0;
	}
	return 1;
}

//////////////////////////////////////////////////////////////////////////
// Display error dialog
void StuAppEditUI::errorDialog(){
	Gtk::MessageDialog dialog(*this, "ERROR!"); 
	dialog.set_secondary_text(
			"You have left fields blank or entered information incorrectly. \nPlease review your entries."); 
	dialog.run();
}

//////////////////////////////////////////////////////////////////////////
// Display file not found dialog
void StuAppEditUI::noApplicationDialog(){
		Gtk::MessageDialog dialog(*this, "ERROR!"); 
		dialog.set_secondary_text(
				"Application number not found. Returning to previous screen."); 
		dialog.run();
	cout<<"noAppDiag"<<endl;
	//onQuit();
}

//////////////////////////////////////////////////////////////////////////
// Event handler for next button
void StuAppEditUI::on_nextButton(const Glib::ustring& data) {
	if (validEntries()) {
		CourseQueue::Node* currNode = manager->getCourseQueue()->front();
		while (currNode != 0) {
			if (currNode->data->getName() == courseCombo.get_active_text()) { 
				manager->getCurrUGradApp()->setCourse(currNode->data);
				break;
			}
			currNode = currNode->next;
		}

		manager->setUGradInfo( stuNumEntry.get_text(),
				nameEntry.get_text(),
				surnameEntry.get_text(),
				emailEntry.get_text() + emailCombo.get_active_text(),
				majorCombo.get_active_text(),
				Tools::stringToInt(yearEntry.get_text()),
				Tools::stringToFloat(cgpaEntry.get_text()),
				Tools::stringToFloat(mgpaEntry.get_text()) );

		CourseEditUI* crsEditWin = new CourseEditUI(manager, 0,node);
	//	CourseInfoUI* crsEditWin = new CourseInfoUI(manager, 0);
		crsEditWin->show();
		hide();
	}
}

//////////////////////////////////////////////////////////////////////////
// Event handler for back button
void StuAppEditUI::on_backButton(const Glib::ustring& data) {
	manager->cancelApp();
	onQuit();
}

void StuAppEditUI::onQuit(){
	cout<<"onquit"<<endl;
	//StudentNumberUI* stuNumWin = new StudentNumberUI(manager, false); 
	//stuNumWin->show();  
	delete this;
}
