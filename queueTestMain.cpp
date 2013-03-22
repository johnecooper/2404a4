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
	WorkExpQueue newerQueue;
	queue.pushBack(e1);
	newQueue.pushBack(e0);
	cout<< " newQueue" << endl;
	newQueue.print();


	cout << "Test [] " << endl;
	if (queue.size() > 0){
		queue.print();
		queue.pushBack(e2);
		queue.print();
	}


	cout << "Test += element" << endl;
	WorkExp* e3 = new WorkExp(0);
	(*e3).setDataMembers("3", "3", "3");
	queue+=e3;
	queue.print();

	WorkExp* e4 = new WorkExp(0);
	(*e4).setDataMembers("4", "4", "4");
	queue.pushBack(e4);
	queue.print();

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


	queue.print();
	queue2.print();
	cout << "q1+=q2" << endl;
	queue+=queue2;
	queue.print();

	cout << "Test + element" << endl;
	WorkExp* e5 = new WorkExp(0);
	cout << "======2" << endl;
	(*e5).setDataMembers("5", "5", "5");
	cout << "======3 " << endl;
	newQueue = queue + e5;
	cout << "======4 " << endl;
	newQueue.print();
	cout << "======5 " << endl;

	cout << "Test + Queue" << endl;
	//WorkExp* e5 = new WorkExp(0);
	//cout << "======2" << endl;
	//(*e5).setDataMembers("5", "5", "5");
	//cout << "======3 " << endl;
	queue.print();
	queue2.print();
	newQueue = queue + queue2;
	//cout << "======4 " << endl;
	newQueue.print();
	cout << "======5 " << endl;

	cout << "Test -= element" << endl;

	queue.print();
	queue-=e3;
	queue.print();

	cout << "Test -= queue" << endl;

	queue-=queue2;
	queue.print();

	cout << "Test - element" << endl;

	newQueue = queue - e2;
	newQueue.print();

	newerQueue += e1;
	newerQueue += e2;
	newerQueue += e3;
	newerQueue += e4;
	newerQueue += e5;
	newerQueue.print();
	newQueue = newerQueue - queue;
	newQueue.print();
	/*		queue.print();
			cout << "wwww1" << endl;
			queue -=(e2);
			cout << "wwww2" << endl;
			queue.print();
	 */		

}


