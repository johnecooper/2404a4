//////////////////////////////////////////////////////////////////////////
// STUDENT APPLICATION EDIT WINDOW
// Prompts user to input their general information

#ifndef STUAPPEDITUI_H
#define STUAPPEDITUI_H

#include "Types.h"
#include <gtkmm.h>

class StuAppEditUI : public Gtk::Dialog {
	public:
		StuAppEditUI(Manager*,bool, int);
		~StuAppEditUI();

		Manager*  manager;

	private:
		int  isEmpty();
		int  validEntries();
		void errorDialog();
		void on_nextButton(const Glib::ustring& data);
		void on_backButton(const Glib::ustring& data);
		int appNumber;
		Gtk::Table          appTable;
		Gtk::Label          label;
		Gtk::Label* 	aLabel;
		Gtk::ScrolledWindow scrolledWindow;
		Gtk::ComboBoxText   emailCombo, majorCombo, courseCombo;
		Gtk::Entry          stuNumEntry, nameEntry, surnameEntry, majorEntry, 
			emailEntry, yearEntry,cgpaEntry, mgpaEntry;    
		Gtk::Button	        nextButton, backButton;

		bool repeat;
};

#endif
