//////////////////////////////////////////////////////////////////////////
// UNDERGRADUATE APPLICATION QUEUE
// Implements a singly linked list of all undergraduate applications

#ifndef UGRADAPPQUEUE_H
#define UGRADAPPQUEUE_H

class UGradApp;

class UGradAppQueue {
  friend class OnePendingUI;
  friend class AllPendingUI;
  friend class StuAppEditUI;
  friend class CourseEditUI;
  friend class WorkEditUI;
  class Node{
    friend class UGradAppQueue;
    friend class OnePendingUI;
    friend class AllPendingUI;
    friend class StuAppEditUI;
    friend class CourseEditUI;
    friend class WorkEditUI;
    private:
      UGradApp*  data;
      Node*      next;
  };

  public:
    UGradAppQueue();
    UGradAppQueue(UGradAppQueue&);
    ~UGradAppQueue();

    void  pushBack(UGradApp*);
    bool  popFront();
    Node* front();
    bool  empty();
    void  clear();
    void  clearCopy();
    int   size()  const;
    void  print() const;
    void  sortByMGPA();
    
  private:
    Node* head;
   
};

#endif

