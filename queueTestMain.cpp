#include "WorkExp.cpp"
#include "WorkExpQueue.cpp"
#include <iostream>
#include "string.h"
#include <sstream>

#define VERBOSE

//class WorkExp;
//class WorkExpQueue;
class Node;
using namespace std;


bool testSubsriptOperator();
bool testAdditionAssignmentOperator1();
bool testAdditionAssignmentOperator2();
bool testAdditionOperator1();
bool testAdditionOperator2();
bool testSubtractionAssignmentOperator1();
bool testSubtractionAssignmentOperator2();
bool testSubtractionOperator1();
bool testSubtractionOperator2();
bool testLogicalNotOperator();

void dataInc();
void dataReset();
void getNewWorkExp(WorkExp*);
string intToString(int); 

int data1=0, data2=0, data3=0, data4=0;


int main(){
#ifdef VERBOSE
	cout<<""<<endl;
#endif	
	WorkExp* e1=new WorkExp(0);
	getNewWorkExp(e1);
	(*e1).print();
	getNewWorkExp(e1);
	(*e1).print();

	return 1;
}

bool testSubsriptOperator(){
#ifdef VERBOSE
	cout<<"Testing Subscipt Operator"<<endl;
#endif
	bool flag=false;
	WorkExp* e1= new WorkExp(0);
	getNewWorkExp(e1);
	WorkExp* e2= new WorkExp(0);
	getNewWorkExp(e2);
	WorkExpQueue queue;	
	queue.pushBack(e1);
	/*if(!(queue[0]==e1){flag=true;
#ifdef VERBOSE
cout<<"Subscript failed on 1 object list."<<endl;
#endif
}*/
	queue.pushBack(e2);	
	/*if(!(queue[1]==e1||!(queue[2]==e2){
	  flag=true;
#ifdef VERBOSE
cout<<"Subscript failed on 2 object list."<<endl;
#endif
}
	 */


	return !flag;
	}

bool testAdditionAssignmentOperator1(){
#ifdef VERBOSE
	cout<<"Testing Addition Assignment Operator 1"<<endl;
#endif
	bool flag=false;
	WorkExp * e1= new WorkExp(0);
	getNewWorkExp(e1);
	WorkExp * e2= new WorkExp(0);
	getNewWorkExp(e2);
	WorkExpQueue queue;	

	//queue+=e1;
	/*if(!(queue[0]==e1||queue.size()==1){flag=true;
#ifdef VERBOSE
cout<<"Addition Assignment Operator failed on adding to empty list."<<endl;
#endif
}*/
	queue.pushBack(e2);	
	//queue+=e2;
	/*if(!(queue.popFront()==eq||queue.popFront()==e2||queue.size()==2){flag=true;
#ifdef VERBOSE
cout<<"Addition Assignment Operator failed on adding to populated list."<<endl;
#endif
	 */
	return !flag;
	}

bool testAdditionAssignmentOperator2(){
#ifdef VERBOSE
	cout<<"Testing Addition Assignment Operator 2"<<endl;
#endif
	bool flag=false;
	WorkExp * e1= new WorkExp(0);
	getNewWorkExp(e1);
	WorkExp * e2= new WorkExp(0);
	getNewWorkExp(e2);
	WorkExp * e3= new WorkExp(0);
	getNewWorkExp(e3);
	WorkExp * e4= new WorkExp(0);
	getNewWorkExp(e4);
	WorkExpQueue queue;
	queue.pushBack(e1);
	queue.pushBack(e2);
	WorkExpQueue queue2;
	queue2.pushBack(e3);
	queue2.pushBack(e4);

	//queue+=queue2;
	/*if(!(queue[0]==e1||queue[1]==e2||queue[2]==e3||queue[3]==e4||queue.size()==4){
	  flag=true;
#ifdef VERBOSE
cout<<"Addition Assignment Operator 2 to maintain item integrity."<<endl;
#endif
}*/
	return !flag;
	}

bool testAdditionOperator1(){
#ifdef VERBOSE
	cout<<"Testing Addition Assignment Operator 1"<<endl;
#endif
	bool flag=false;
	WorkExp * e1= new WorkExp(0);
	getNewWorkExp(e1);
	WorkExp * e2= new WorkExp(0);
	getNewWorkExp(e2);
	WorkExpQueue queue;	

	//queue+e1;
	/*if(!(queue[0]==e1||queue.size()==1){flag=true;
#ifdef VERBOSE
cout<<"Addition Assignment Operator failed on adding to empty list."<<endl;
#endif
}*/
	queue.pushBack(e2);	
	//queue+e2;
	/*if(!(queue.popFront()==eq||queue.popFront()==e2||queue.size()==2){flag=true;
#ifdef VERBOSE
cout<<"Addition Assignment Operator failed on adding to populated list."<<endl;
#endif
	 */
	return !flag;	
}

bool testAdditionOperator2(){
#ifdef VERBOSE
	cout<<"Testing Addition Assignment Operator 2"<<endl;
#endif
	bool flag=false;
	WorkExp * e1= new WorkExp(0);
	getNewWorkExp(e1);
	WorkExp * e2= new WorkExp(0);
	getNewWorkExp(e2);
	WorkExp * e3= new WorkExp(0);
	getNewWorkExp(e3);
	WorkExp * e4= new WorkExp(0);
	getNewWorkExp(e4);
	WorkExpQueue queue;
	queue.pushBack(e1);
	queue.pushBack(e2);
	WorkExpQueue queue2;
	queue2.pushBack(e3);
	queue2.pushBack(e4);

	//queue+queue2;
	/*if(!(queue[0]==e1||queue[1]==e2||queue[2]==e3||queue[3]==e4||queue.size()==4){
	  flag=true;
#ifdef VERBOSE
cout<<"Addition Assignment Operator 2 to maintain item integrity."<<endl;
#endif
}*/
	return !flag;
	}

bool testSubtractionAssignmentOperator1(){
#ifdef VERBOSE
	cout<<"Testing Subtraction Assignment Operator 1"<<endl;
#endif
	bool flag=false;
	WorkExp * e1= new WorkExp(0);
	getNewWorkExp(e1);
	WorkExp * e2= new WorkExp(0);
	getNewWorkExp(e2);
	WorkExpQueue queue;
	queue.pushBack(e1);
	queue.pushBack(e2);

	//queue-=e1;
	/*if(!(queue[0]==e2||queue.size()==1){flag=true;
#ifdef VERBOSE
cout<<"Subtraction Assignment Operator failed on subtracting from poplulated."<<endl;
#endif
}*/
	
	//queue-=e2;
	/*if(!(queue.size()==0){flag=true;
#ifdef VERBOSE
cout<<"Subtraction Assignment Operator failed on subtracting last item."<<endl;
#endif
	 */
	return !flag;
	}

bool testSubtractionAssignmentOperator2(){
#ifdef VERBOSE
	cout<<"Testing Subtraction Assignment Operator 2"<<endl;
#endif
	bool flag=false;
	WorkExp * e1= new WorkExp(0);
	getNewWorkExp(e1);
	WorkExp * e2= new WorkExp(0);
	getNewWorkExp(e2);
	WorkExp * e3= new WorkExp(0);
	getNewWorkExp(e3);
	WorkExpQueue queue;
	queue.pushBack(e1);
	queue.pushBack(e2);
	queue.pushBack(e3);
	WorkExpQueue queue2;
	queue2.pushBack(e1);
	queue2.pushBack(e3);

	//queue-=queue2;
	/*if(!(queue[0]==e2||queue.size()==1){
	  flag=true;
#ifdef VERBOSE
cout<<"Subtraction Assignment Operator 2 failed."<<endl;
#endif
}*/
	return !flag;
	}
bool testSubtractionOperator1(){
#ifdef VERBOSE
	cout<<"Testing Subtraction Operator 1"<<endl;
#endif
	bool flag=false;
	WorkExp * e1= new WorkExp(0);
	getNewWorkExp(e1);
	WorkExp * e2= new WorkExp(0);
	getNewWorkExp(e2);
	WorkExpQueue queue;
	queue.pushBack(e1);
	queue.pushBack(e2);

	//queue-e1;
	/*if(!(queue[0]==e2||queue.size()==1){flag=true;
#ifdef VERBOSE
cout<<"Subtraction Assignment Operator failed on subtracting from poplulated."<<endl;
#endif
}*/
	
	//queue-e2;
	/*if(!(queue.size()==0){flag=true;
#ifdef VERBOSE
cout<<"Subtraction Assignment Operator failed on subtracting last item."<<endl;
#endif
	 */
	return !flag;
	}

bool testSubtractionOperator2(){
#ifdef VERBOSE
	cout<<"Testing Subtraction Operator 2"<<endl;
#endif
	bool flag=false;
	WorkExp * e1= new WorkExp(0);
	getNewWorkExp(e1);
	WorkExp * e2= new WorkExp(0);
	getNewWorkExp(e2);
	WorkExp * e3= new WorkExp(0);
	getNewWorkExp(e3);
	WorkExpQueue queue;
	queue.pushBack(e1);
	queue.pushBack(e2);
	queue.pushBack(e3);
	WorkExpQueue queue2;
	queue2.pushBack(e1);
	queue2.pushBack(e3);

	//queue-queue2;
	/*if(!(queue[0]==e2||queue.size()==1){
	  flag=true;
#ifdef VERBOSE
cout<<"Subtraction Operator 2 failed."<<endl;
#endif
}*/
	return flag;
	}
bool testLogicalNotOperator(){
	bool flag=false;
	WorkExp * e1= new WorkExp(0);
        getNewWorkExp(e1);
        WorkExp * e2= new WorkExp(0);
        getNewWorkExp(e2);
        WorkExpQueue queue;
//!queue
if(!(queue.size()==0)){
	flag=true;
}
return !flag;
}










void getNewWorkExp(WorkExp* ein){
	dataInc();
	WorkExp e (0);
	e.setResp("Resp:"+intToString(data1));
	e.setDataMembers("Data1:"+intToString(data2),"Data2:"+intToString(data3),"Data3:"+intToString(data4));
	*ein = e;
}

void dataInc(){
	data1++;
	data2++;
	data3++;
	data4++;
}

void dataReset(){
	data1=0;
	data2=0;
	data3=0;
	data4=0;
}

string intToString(int i){
	string s;
	ostringstream convert;
	convert << i;
	s = convert.str();
	return s;
}

