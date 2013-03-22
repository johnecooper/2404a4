///////////////////////////////////////////////////////////////////////////////////////
// ALL PENDING WINDOW
// Shows a list of pending applications for all courses
//   sorted by applicant's major GPA or research area
//NOTE Not subclassed as all functions edited.
#ifndef ALLPACCEPTEDUI_H 
#define ALLACCEPTEDUI_H

#include "Types.h"
#include <gtkmm.h>

class AllAcceptedUI : public Gtk::Window {
  public:
    AllAcceptedUI(Manager*);
    ~AllAcceptedUI();

    Manager* manager;

  private:
    void on_backButton(const Glib::ustring& data);
    void on_cancelButton(const Glib::ustring& data);
    void on_saveButton(const Glib::ustring& data);
    void fillSummary();
    void saveDialog();

    Gtk::Table          aTable;
    Gtk::Label	        aLabel;
    Gtk::Button	        backButton, cancelButton, saveButton;
    Gtk::ListViewText   summary;
    Gtk::ScrolledWindow scrolledWindow;
};

#endif
