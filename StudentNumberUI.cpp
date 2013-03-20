//////////////////////////////////////////////////////////////////////////
// STUDENT NUMBER UI
// Prompts the user to enter their student number

#include "StudentNumberUI.h"
#include "StuAppEditUI.h"
//////////////////////////////////////////////////////////////////////////
// Default constructor
StudentNumberUI::StudentNumberUI(Manager* aManager, bool) 
: aTable(4,2,false),
  aTitle("Enter your application number:"),
  nextButton("Enter"),
  backButton("Back")
{
  manager = aManager;

  set_default_size(500, 350);
  set_title("Application Number Text");
  set_position(Gtk::WIN_POS_CENTER_ALWAYS);
  
  add(aTable);
  aTable.attach(aTitle, 0, 2, 0, 1,Gtk::EXPAND,Gtk::FILL,0,70);
  aTable.attach(stuNumberEntry,0,2,1,2,Gtk::FILL,Gtk::FILL,0,20);
  aTable.attach(nextButton, 0, 1, 2, 3,Gtk::FILL,Gtk::FILL,40,40);
  aTable.attach(backButton, 1, 2, 2,3,Gtk::FILL,Gtk::FILL,40,40);

  nextButton.signal_clicked().connect(
    sigc::bind<Glib::ustring>( sigc::mem_fun(*this, &StudentNumberUI::on_nextButton), "Enter") );
  backButton.signal_clicked().connect(
    sigc::bind<Glib::ustring>( sigc::mem_fun(*this, &StudentNumberUI::on_backButton), "Back") );

  show_all_children();

  //cout << "CONSTRUCT StudentNumberUI" << endl;
}

//////////////////////////////////////////////////////////////////////////
// Destructor
StudentNumberUI::~StudentNumberUI() {
  //cout << "DESTRUCT StudentNumberUI" << endl;
}

//////////////////////////////////////////////////////////////////////////
// Event handler for student button
void StudentNumberUI::on_nextButton(const Glib::ustring& data){
  int i = atoi(stuNumberEntry.get_text().c_str()); 
  StuAppEditUI* stuEditWin = new StuAppEditUI(manager,false,i);
  stuEditWin->show();
}

//////////////////////////////////////////////////////////////////////////
// Event handler for administrator button
void StudentNumberUI::on_backButton(const Glib::ustring& data){
 // AdminOptionUI* adminWin = new AdminOptionUI(manager);
 // adminWin->show();
  delete this;
}

