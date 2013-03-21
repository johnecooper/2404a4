#ifndef STUDENTNUMBERUI_H
#define STUDENTNUMBERUI_H

#include "Types.h"
#include <gtkmm.h>
 
class StudentNumberUI : public Gtk::Window {
	public:
		StudentNumberUI ( Manager*, bool);
		~StudentNumberUI();
		Manager* manager;
	private:
		void on_nextButton(const Glib::ustring& data);
		void on_backButton(const Glib::ustring& data);
		Gtk::Table aTable;
		Gtk::Label aTitle;
		Gtk::Entry stuNumberEntry;
		Gtk::Button nextButton, backButton;
};

#endif
