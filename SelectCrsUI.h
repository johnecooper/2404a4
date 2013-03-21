//////////////////////////////////////////////////////////////////////////
// SELECT COURSE WINDOW
// Prompts user to select a course

#ifndef SELECTCRSUI_H
#define SELECTCRSUI_H

#include "Types.h"
#include <gtkmm.h>

class SelectCrsUI : public Gtk::Window {
	public:
		SelectCrsUI(Manager*);
		~SelectCrsUI();

		Manager* manager;


	private:
		void on_nextButton(const Glib::ustring& data);
		void on_backButton(const Glib::ustring& data);

		// Widgets
		Gtk::Table         createTable;
		Gtk::Label         createLabel;
		Gtk::Button        nextButton, backButton;
		Gtk::ComboBoxText  m_Combo;
};

#endif
