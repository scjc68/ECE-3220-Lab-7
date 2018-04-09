#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Message
{
	private:
	
	public:
		Message(){
			cout << "Default Message" << endl;
		}
		Message(string code){
			cout << "Parametrized Message" << endl;
		}
		~Message(){
			cout << "Desstructor Message" << endl;
		}
		virtual void print_message(){
			cout << "In Parent" << endl;
		}
};

class MorseCodeMessage:public Message
{
	private:
		string s;
	public:
		MorseCodeMessage(){
			cout << "Default MorseCodeMessage" << endl;
		}
		MorseCodeMessage(string msg){
			cout << "Parametrized MorseCodeMessage-1" << endl;
		}
		string translate(string mes){
			cout << "Parametrized MorseCodeMessage-2" << endl;
		}
		~MorseCodeMessage(){
			cout << "Desstructor MorseCodeMessage" << endl;
		}
		virtual void print_message(){
			cout << "In Child" << endl;
		}
};

class MessageStack
{
	private:
		
	public:
		int i=0;
		vector<Message*>v;
		MessageStack(){
			cout << "Default My Stack" << endl;
		}
		MessageStack(Message* obj){
			cout << "Parametrized My Stack" << endl;
		}
		~MessageStack(){}
		void print_stack(){
			for(int i=0; i<v.size(); i++){
				v[i]->print_message();
			}
		}
};

int main(void)
{
	MessageStack myStack;
	string s1 = "Hello";
	string s2 = "World";
	string s3 = "Goodbye";
	string s4 = "Maybe";
	
	Message m1(s1), m2(s2);
	MorseCodeMessage mm1(s3), mm2(s4);
	myStack.v.push_back(&m1);
	myStack.v.push_back(&mm1);
	
	myStack.print_stack();
	
	// myStack.i=10;
	// cout << myStack.i << endl;
	
	return 0;
}