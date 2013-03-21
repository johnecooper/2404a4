//////////////////////////////////////////////////////////////////////////
// STUDENT APPLICATION FORM WINDOW
// Prompts user to input their general information

#ifndef STUAPPFORMUI_H
#define STUAPPFORMUI_H

#include "Types.h"
#include <gtkmm.h>

class StuAppFormUI : public Gtk::Dialog {
	public:
		StuAppFormUI(Manager*, bool);
		~StuAppFormUI();

		Manager*  manager;

	private:
		int  isEmpty();
		int  validEntries();
		void errorDialog();
		void on_nextButton(const Glib::ustring& data);
		void on_backButton(const Glib::ustring& data);

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
