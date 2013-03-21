//////////////////////////////////////////////////////////////////////////
// CREATE COURSES INFORMATION WINDOW
// Prompts user to give more information about related courses

#ifndef COURSEEDITUI_H
#define COURSEEDITUI_H

#include <gtkmm.h>

#include "Types.h"
#include "TakenCourse.h"
#include "TACourse.h"
#include "UGradAppQueue.h"
#include "TakenCourseQueue.h"
class CourseEditUI : public Gtk::Window {
  public:
    CourseEditUI(Manager*, int, UGradAppQueue::Node*);
    ~CourseEditUI();

    Manager*  manager;

    // 0 = TakenCourse
    // 1 = TACourse
    int whichCourse;

  private:
    UGradAppQueue::Node* node;
    void initWindow(Manager*);
    void on_nextButton(const Glib::ustring& data);
    void on_backButton(const Glib::ustring& data);
    void on_courseButton(const Glib::ustring& data);
    void on_firstCourseButton(const Glib::ustring& data);
    void on_nextCourseButton(const Glib::ustring& data);
    TakenCourseQueue * courseQueue;
    // Widgets
    Gtk::Table         createTable;
    Gtk::Label         aLabel, yearLabel, termLabel, finalLabel;
    Gtk::ComboBoxText  yearCombo, termCombo, finalCombo, courseCombo;
    Gtk::Button        nextButton, backButton, courseButton, firstCourseButton, nextCourseButton;
};

#endif

