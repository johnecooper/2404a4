//////////////////////////////////////////////////////////////////////////
// WORKEXPQUEUE
// Implements a singly linked list of work experience by applicant


#include "WorkExpQueue.h"

//////////////////////////////////////////////////////////////////////////
// Default constructor
	WorkExpQueue::WorkExpQueue() 
: head(0)
{ 
	//cout << "CONSTRUCT WorkExpQueue" << endl;
}

//////////////////////////////////////////////////////////////////////////
// Copy Constructor
	WorkExpQueue::WorkExpQueue(WorkExpQueue& oldQueue) 
: head(0)
{

	Node  *currNode = oldQueue.head,
	      *prevNode = 0;

	while (currNode != 0){
		Node* newNode = new Node;
		newNode->data = new WorkExp(0);
		*(newNode->data) = *(currNode->data);
		newNode->next = 0;

		if (!head) {
			head     = newNode;
			prevNode = head;
		} else {
			prevNode->next = newNode;
			prevNode       = newNode;
		}
		currNode = currNode->next;
	}
	cout << "COPY CONSTRUCT WorkExpQueue" << endl;
}

//////////////////////////////////////////////////////////////////////////
// Destructor
WorkExpQueue::~WorkExpQueue() {
	//clear();
	cout << "DESTRUCT WorkExpQueue" << endl;
}

//////////////////////////////////////////////////////////////////////////
// Overloaded Operators

WorkExp* WorkExpQueue::operator[](int index)
{
	if (head == 0)
		return 0;
	Node* currNode = head;
	for(int i = 0; i < index; i++)
	{
		currNode = currNode->next;
		if(currNode == 0)
			return 0;
	}
	return currNode->data;
}

WorkExpQueue& WorkExpQueue::operator+=(WorkExp* w)
{
	pushBack(w);
	return *this;
}

WorkExpQueue& WorkExpQueue::operator+=(WorkExpQueue& q)
{
	if(q.head == 0)
	{
		return *this;
	}
	Node* currNode = q.head;
	while(currNode!=0)
	{
		pushBack(currNode->data);
		currNode = currNode->next;
	}
	return *this;
}

WorkExpQueue WorkExpQueue::operator+(WorkExp* w)
{
	WorkExpQueue tempQueue = *this;
	tempQueue.operator+=(w);
	tempQueue.print();
	return tempQueue;
}

WorkExpQueue WorkExpQueue::operator+(WorkExpQueue& q)
{
	WorkExpQueue tempQueue = *this;
	tempQueue.operator+=(q);
	tempQueue.print();
	return tempQueue;
}

void WorkExpQueue::operator-=(WorkExp* w)
{
	if(head == 0 || w == 0)
		return;
	Node *currNode = head;
	Node *tempNode = new Node;
	if((currNode->data) == w)
	{
		std::cout<<"Head!"<<endl;
		tempNode = currNode;
		currNode = currNode->next;
		head = currNode;
		delete tempNode->data;
		delete tempNode;
		std::cout<<"Data at the Head is gone!"<<endl;
		return;
	}  

	while(currNode->next != 0)
	{
		std::cout<<"While!"<<endl;
		if((currNode->next->data) == w)
		{
			std::cout<<"Middle!"<<endl;
			tempNode = currNode->next;
			currNode->next = tempNode->next;
			delete tempNode->data;
			delete tempNode;
			std::cout<<"Data in the middle is gone!"<<endl;
			return;
		}
		std::cout<<"Forward!"<<endl;
		currNode = currNode->next;
	}
	std::cout<<"Data not found!"<<endl;
}

void WorkExpQueue::operator-=(WorkExpQueue& q)
{
	if(q.head == 0)
		return;
	Node* rightCurrNode = q.head;
	while(rightCurrNode!=0)
	{
		this->operator-=(rightCurrNode->data);
		rightCurrNode = rightCurrNode->next;
	}
}

WorkExpQueue WorkExpQueue::operator-(WorkExp* w)
{
	WorkExpQueue tempQueue;
	WorkExpQueue& t = *this;
	t.operator-=(w);
	tempQueue+=(t);
	return tempQueue;
}

WorkExpQueue WorkExpQueue::operator-(WorkExpQueue& q)
{
	WorkExpQueue tempQueue;
	WorkExpQueue& t = *this;
	t.operator-=(q);
	tempQueue+=(t);
	return tempQueue;
}

void WorkExpQueue::operator!()
{
	clear();
}

//////////////////////////////////////////////////////////////////////////
// Adds an item to the back of the queue
void WorkExpQueue::pushBack(WorkExp* newWork){
	Node* tmpNode = new Node;
	tmpNode->data = newWork;
	tmpNode->next = 0;

	Node* currNode;

	// Adding to an empty list
	if (head == 0){
		head = tmpNode;
		return;
	}

	currNode = head;

	// Iterate all the way to the end of the linked list
	while(currNode != 0){
		if(currNode->next == 0)
			break;
		currNode = currNode->next;
	}

	currNode->next = tmpNode;
}

//////////////////////////////////////////////////////////////////////////
// Removes first item in the queue
bool WorkExpQueue::popFront() {
	Node *currNode; 

	if(head == 0)
		return 1;

	currNode = head;
	head = currNode->next;
	delete currNode;

	return 0;
}

//////////////////////////////////////////////////////////////////////////
// Return the first item in the queue
WorkExpQueue::Node* WorkExpQueue::front(){
	return head;
}

//////////////////////////////////////////////////////////////////////////
// Tests whether queue is empty or not
bool WorkExpQueue::empty(){
	if (head == 0)
		return true;
	return false;
}

//////////////////////////////////////////////////////////////////////////
// Clears the queue
void WorkExpQueue::clear(){
	Node *currNode, *nextNode;

	if (head == 0)
		return;

	currNode = head;

	while (currNode != 0) {

		nextNode = currNode->next;

		delete currNode->data;
		delete currNode;
		currNode = nextNode;
	}

	head = 0;
}

//////////////////////////////////////////////////////////////////////////
// Returns the size of the queue
int WorkExpQueue::size() const {
	Node* currNode = head;
	int   count = 0; 

	while (currNode != 0) {
		count++;
		currNode = currNode->next;
	}
	return count;
}

//////////////////////////////////////////////////////////////////////////
// Prints list of courses to std::cout
void WorkExpQueue::print() const {
	Node* currNode = head;

	std::cout << "WORK EXP:" <<endl;
	while (currNode != 0) {
		currNode->data->print();
		currNode = currNode->next;
	}
}



