//////////////////////////////////////////////////////////////////////////
// ACCEPT APPLICATION UI
// Prompts the user to either submit or cancel their application

#ifndef ACCEPTEDITUI_H
#define ACCEPTEDITUI_H

#include "Types.h"
#include <gtkmm.h>

class AcceptEditUI : public Gtk::Window {
  public:
    AcceptEditUI( Manager*);
    ~AcceptEditUI();

    Manager*  manager;

  private:
    void on_submitButton(const Glib::ustring& data);
    void on_cancelButton(const Glib::ustring& data);

    Gtk::Table          aTable;
    Gtk::Label          aLabel;    
    Gtk::Button	        submitButton, cancelButton;
};

#endif
