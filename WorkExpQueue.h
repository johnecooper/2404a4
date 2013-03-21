//////////////////////////////////////////////////////////////////////////
// WORKEXPQUEUE
// Implements a singly linked list of work experience by applicant

#ifndef WORKEXPQUEUE_H
#define WORKEXPQUEUE_H

#include "Types.h"
#include "WorkExp.h"

class WorkExpQueue {
  friend class Manager;
  class Node{
    friend class WorkExpQueue;
    friend class Manager;
    private:
      WorkExp* data;
      Node*    next;
  };

  public:
    WorkExpQueue();
    WorkExpQueue(WorkExpQueue&);
    ~WorkExpQueue();

    WorkExp*          operator[](int);
    WorkExpQueue&     operator+=(WorkExp*);
    WorkExpQueue&     operator+=(WorkExpQueue&);
    WorkExpQueue      operator+(WorkExp*);
    WorkExpQueue      operator+(WorkExpQueue&);
    void              operator-=(WorkExp*);
    void              operator-=(WorkExpQueue&);
    WorkExpQueue      operator-(WorkExp*);
    WorkExpQueue      operator-(WorkExpQueue&);    
    void              operator!();
    
    
    void      pushBack(WorkExp*);
    bool      popFront();
    Node*     front();
    bool      empty();
    void      clear();
    int       size()  const;
    void      print() const;
    
  private:
    Node* head;
   
};

#endif

