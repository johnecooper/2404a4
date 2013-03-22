//////////////////////////////////////////////////////////////////////////
// ACCEPT APPLICATION WINDOW
// Prompts the user to either submit or cancel their application

#include "AcceptEditUI.h"
#include "SubmitAppUI.h"
#include "StuOptionUI.h"
#include "UGradApp.h"

//////////////////////////////////////////////////////////////////////////
// Default constructor
AcceptEditUI::AcceptEditUI(Manager* aManager) 
	: aTable(2, 3, false),
	aLabel("Thank you for editing an application.\n         Would you like to submit? "),
	submitButton("Submit"),
	cancelButton("Cancel"),
	closeButton("Close Application")
{
	manager   = aManager;

	set_default_size(500, 350);
	set_title("cuTAES");
	set_modal(true);
	set_position(Gtk::WIN_POS_CENTER_ALWAYS);
	set_deletable(false);

	add(aTable);

	aTable.attach(aLabel, 0, 2, 0, 1,Gtk::EXPAND,Gtk::FILL,20,100);
	aTable.attach(cancelButton, 0, 1, 1, 2,Gtk::FILL,Gtk::FILL,40,50);
	aTable.attach(submitButton, 1, 2, 1, 2,Gtk::FILL,Gtk::FILL,40,50);
	aTable.attach(closeButton, 2,3,1,2,Gtk::FILL,Gtk::FILL,40,50);

	submitButton.signal_clicked().connect(
			sigc::bind<Glib::ustring>( sigc::mem_fun(*this, &AcceptEditUI::on_submitButton), "Submit") );
	cancelButton.signal_clicked().connect(
			sigc::bind<Glib::ustring>( sigc::mem_fun(*this, &AcceptEditUI::on_cancelButton), "Cancel") );
	closeButton.signal_clicked().connect(
			sigc::bind<Glib::ustring>( sigc::mem_fun(*this, &AcceptEditUI::on_closeButton), "Close Application") );


	show_all_children();

	//cout << "CONSTRUCT AcceptEditUI" << endl;
}

//////////////////////////////////////////////////////////////////////////
// Destructor
AcceptEditUI::~AcceptEditUI() {
	//cout << "DESTRUCT AcceptEditUI" << endl;
}

//////////////////////////////////////////////////////////////////////////
// Open the SubmitApp window, and delete the current window
void AcceptEditUI::on_submitButton(const Glib::ustring& data) {
	manager->saveApp();
	SubmitAppUI* submittedApp = new SubmitAppUI(manager); 
	submittedApp->show();
	delete this;
}

//////////////////////////////////////////////////////////////////////////
// Close the window and delete the application that was being filled
void AcceptEditUI::on_cancelButton(const Glib::ustring& data) {
	manager->cancelApp();
	//StuOptionUI* studentWin = new StuOptionUI(manager);
	//studentWin->show(); 
	delete this;
}

void AcceptEditUI::on_closeButton(const Glib::ustring& data) {
	manager->getCurrUGradApp()->setStatus(CLOSED);
	manager->saveApp();
	//StuOptionUI* studentWin = new StuOptionUI(manager);
	//studentWin->show(); 
	delete this;
}
