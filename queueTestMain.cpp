#include "WorkExp.cpp"
#include "WorkExpQueue.cpp"
#include <iostream>
#include <string>
#include "string.h"
#include <sstream>

#include "WorkExpQueue.h"

#define VERBOSE

class WorkExp;
class WorkExpQueue;
class Node;
using namespace std;

int main(){
	WorkExp* e1 = new WorkExp(0);
	(*e1).setDataMembers("1", "1", "1");
	WorkExp*e0 = new WorkExp(0);
	(*e0).setDataMembers("A", "A", "A");
	(*e1).print();
	WorkExp*e2 = new WorkExp(0);
	(*e2).setDataMembers("2", "2", "2");
	(*e2).print();
	WorkExpQueue queue;	
	WorkExpQueue newQueue;
	WorkExpQueue newQueue2;
	WorkExpQueue newerQueue;
	queue.pushBack(e1);
	newQueue.pushBack(e0);
	cout<< " newQueue" << endl;
	newQueue.print();

	//////////////////////////////////////////////////////////////////////////
	// Testing []
	cout << "Test [] " << endl;
	if (queue.size() > 0){
		queue.print();
		queue.pushBack(e2);
		queue.print();
	}

	//////////////////////////////////////////////////////////////////////////
	// Testing += Element
	cout << "Test += element" << endl;
	WorkExp* e3 = new WorkExp(0);
	(*e3).setDataMembers("3", "3", "3");
	queue+=e3;
	queue.print();

	WorkExp* e4 = new WorkExp(0);
	(*e4).setDataMembers("4", "4", "4");
	queue+=e4;
	queue.print();

	//////////////////////////////////////////////////////////////////////////
	// Testing += Queues
	cout << "Test += 2 queues" << endl;
	WorkExp*f1 = new WorkExp(0);
	WorkExp*f2 = new WorkExp(0);
	WorkExp*f3 = new WorkExp(0);
	WorkExp*f4 = new WorkExp(0);
	WorkExp*f5 = new WorkExp(0);
	(*f1).setDataMembers("f1", "f1", "f1");
	(*f2).setDataMembers("f2", "f2", "f2");
	(*f3).setDataMembers("f3", "f3", "f3");
	(*f4).setDataMembers("f4", "f4", "f4");
	(*f5).setDataMembers("f5", "f5", "f5");
	WorkExpQueue queue2;	
	queue2.pushBack(f1);
	queue2.pushBack(f2);
	queue2.pushBack(f3);
	queue2.pushBack(f4);
	queue2.pushBack(f5);

	queue.print(); //print out q1
	queue2.print(); //print out q2
	cout << "q1+=q2" << endl; 
	//	queue+=queue2;
	queue.print();//print out q1 followed by q2

	//////////////////////////////////////////////////////////////////////////
	// Testing + Element
	cout << "Test + element" << endl;
	WorkExp* e5 = new WorkExp(0);
	cout << "======2" << endl;
	(*e5).setDataMembers("5", "5", "5");
	cout << "======3 " << endl;
	newQueue = queue + e5;
	cout << "======4 " << endl;
	newQueue.print();
	cout << "======5 " << endl;

	//////////////////////////////////////////////////////////////////////////
	// Testing + Queue
	cout << "Test + Queue" << endl;
	//WorkExp* e5 = new WorkExp(0);
	//cout << "======2" << endl;
	//(*e5).setDataMembers("5", "5", "5");
	//cout << "======3 " << endl;


	WorkExp*x1 = new WorkExp(0);
	WorkExp*x2 = new WorkExp(0);
	WorkExp*x3 = new WorkExp(0);
	WorkExp*x4 = new WorkExp(0);
	WorkExp*x5 = new WorkExp(0);
	(*x1).setDataMembers("x1", "x1", "x1");
	(*x2).setDataMembers("x2", "x2", "x2");
	(*x3).setDataMembers("x3", "x3", "x3");
	(*x4).setDataMembers("x4", "x4", "x4");
	(*x5).setDataMembers("x5", "x5", "x5");
	newQueue2.pushBack(x1);
	newQueue2.pushBack(x2);
	newQueue2.pushBack(x3);
	newQueue2.pushBack(x4);
	newQueue2.pushBack(x5);
	WorkExpQueue newQueueX;

	cout << "Queue1" << endl;
	queue.print();
	cout << "Queue2" << endl;
	queue2.print();

	cout<< "Queue3" << endl;
	newQueue2.print();
	cout <<  "CASCADING" <<endl;
	newQueueX = queue + queue2 + newQueue2;
	cout << "======5 " << endl;


	//////////////////////////////////////////////////////////////////////////
	// Testing -= element
	cout << endl << "Test -= element" << endl;

	queue.print();
	queue-=e3;
	queue.print();

	//////////////////////////////////////////////////////////////////////////
	// Testing - element
	cout << endl << endl <<"Test - element" << endl;

	queue.print();
	newQueue = queue - e2;
	cout << "queue-e2"  << endl << endl;
	newQueue.print();

	//////////////////////////////////////////////////////////////////////////
	// Testing - queue

	cout << endl << endl <<"Test - queue" << endl;
	newerQueue += e1;
	newerQueue += e2;
	newerQueue += e3;
	newerQueue += e4;
	newerQueue += e5;
	newerQueue.print();
	WorkExpQueue endQueue;

	cout << "queue1" << endl;
	queue.print();
	cout << "queue2" << endl;
	newerQueue.print();
	cout << "queue3" << endl;
	endQueue = newerQueue - queue;
	cout << "final Queue" << endl;
	endQueue.print();



	//////////////////////////////////////////////////////////////////////////
	// Testing -= Queue
	cout<<endl<<endl<<"test-= queue" << endl;

	WorkExpQueue taQueue;
	taQueue += e1;
	taQueue += e2;
	taQueue += e3;
	taQueue += e4;
	taQueue += e5;


	cout << "queue1" << endl;
	queue.print();
	cout << "queue2" << endl;
	taQueue.print();

	taQueue-=queue;
	cout << endl << "queue print (should be 2, 3, 5)" << endl;
	taQueue.print();


	//////////////////////////////////////////////////////////////////////////
	// Testing ! operator
	cout <<endl << endl<< "Testing ! " << endl;
	cout << "Before" << endl;
	taQueue.print();
	!taQueue;
	cout << "should be empty" << endl;
	taQueue.print();

}


