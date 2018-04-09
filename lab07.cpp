/* Name: Seth John
   Pawprint: scjc68
   ECE 3220 Lab 7 
   Date: 04/09/2018 */

#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std; 

string MorseCodeArray[]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
string uppercase_text="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string lowercase_text="abcdefghijklmnopqrstuvwxyz";

class Message
{
	private:
		
	protected:
		string message;
	
	public:
		Message();
		// {
			// cout << "Default Message" << endl;
		// }
		Message(string code);
		// {
			// cout << "Parametrized Message" << endl;
		// }
		~Message();
		// {
			// cout << "Destructor Message" << endl;
		// }
		virtual void Print_message(); 
		// {
			// cout << "In Parent" << endl;
		// }
};

Message::Message()    //not called because I did it the way we discussed previously with just the parametric constructor
{
	string beginmsg="";
	// while(beginmsg=="")
	// {
		cout << "Please enter a regular message to start at the beginning of the stack:" << endl;
		//cin >> beginmsg;   //used to read in input string from user
		getline(cin,beginmsg);
		// cin.ignore(256, ' ');
		// cin.ignore(120,'\n');
		//cin.ignore();
	//}
	message=beginmsg;    //used to set user input to message
}

Message::Message(string code)
{
	message=code;      //used to set user input to the message
}

Message::~Message()
{
	//there is nothing to delete since strings are being used 
}

void Message::Print_message()          //used to only print the message in lowercase_text letters
{ 
	cout <<"\nThe message you entered is:" << endl;
	cout << message << endl;
}

class MorseCodeMessage : public Message   //MorseCodeMessage is used as a derived class
{
	private:
		string morse_msg;
	
	public:
		MorseCodeMessage();
		// {
			// cout << "Default MorseCodeMessage" << endl;
		// }
		MorseCodeMessage(string reg_msg);
		// {
			// cout << "Parametrized MorseCodeMessage-1" << endl;
		// }
		string Translate(string trans_msg);
		// {
			// cout << "Parametrized MorseCodeMessage-2" << endl;
		// }
		~MorseCodeMessage();
		// {
			// cout << "Destructor MorseCodeMessage" << endl;
		// }
		virtual void Print_message();
		// {
			// cout << "In Child" << endl;
		// }
};

// MorseCodeMessage::MorseCodeMessage() : Message()    
// {
	// Translate(message);             //translates string to morse_msg 
	// morse_msg=Translate(message);   //used to set translated string to morse_msg data
// }

MorseCodeMessage::MorseCodeMessage(string reg_msg) : Message(reg_msg)    //first the base constructor is called 
{
	Translate(reg_msg);             //translates string to morse_msg 
	morse_msg=Translate(reg_msg);   //used to set translated string to morse_msg data
}

string lowercase_to_morse(char letter)
{
	int ctrl=lowercase_text.find(letter);                //used to find the position of the character in table
	
	if(ctrl!=-1)                                        //if exists return the morse_msg character
	{
		return MorseCodeArray[ctrl];
	}
	else                                                //if letter is not lowercase_text search for uppercase_text letter
	{
		ctrl=uppercase_text.find(letter);
		if(ctrl!=-1)
		{
			return MorseCodeArray[ctrl];
		}
		else                                            //if not in either lowercase_text or uppercase_text table return a space
		{
			return " ";
		}
	}
}

string MorseCodeMessage::Translate(string trans_msg)
{
	int i=0;
	string temp_str="";
	
	for(i=0; i<trans_msg.length(); i++)
	{
		if(trans_msg[i]==' ')                             //if there is a 'space' replace with a '/ '
		{
			temp_str+="/ ";
		}
		else
		{
			temp_str+=lowercase_to_morse(trans_msg[i]);   //used to take each character and convert it 
			temp_str+=" ";                                //used to add a space so it is easier to read
		}
	}
	return temp_str;                                      //morse_msg message is returned
}

// MorseCodeMessage::~MorseCodeMessage() 
// {
	//there is nothing to delete since strings are being used 
// }

void MorseCodeMessage::Print_message()                   //used to print both regular lowercase_text message and the morse_msg 
{
	cout << "\nThe message you entered is:" << endl;
	cout << message << endl;
	cout << "The message you entered in Morse code is:" << endl;
	cout << morse_msg << endl;
}

class MessageStack
{
	private:
		vector<Message*>stack_vec;
	
	public:
		MessageStack();
		//int i=0;
		MessageStack(Message* object);
		// {
			// cout << "Parametrized My Stack" << endl;
		// }
		~MessageStack();
		void Push(Message* object);                 //used to push on stack
		// {
			// for(int i=0; i<v.size(); i++){
				// v[i]->Print_message();
			// }
		// }
		void Pop();                                 //used to pop off stack
		void Print_stack();
};

MessageStack::MessageStack()
{
};

MessageStack::MessageStack(Message* object)
{
	stack_vec.push_back(object);                    //used to push object pointer on stack
}

MessageStack::~MessageStack()
{
	//cout << "Destructor MessageStack" << endl;
}

void MessageStack::Push(Message* object)
{
	stack_vec.push_back(object);                    //used to place the message pointer on stack
}

void MessageStack::Pop()
{
	if(!stack_vec.empty())
	{
		stack_vec.pop_back();
	}
	else
	{
		cout << "\nStack is Empty." << endl;
	}
	
	// int ctrl=stack_vec.size();                      //this way is how to do it not using pop_back;
	// ctrl-=1;                                        //the last spot in the vector is ctrl
	// if(ctrl<1)                                     //checks if nothing has been added to the stack
	// { 
		// cout << "\nStack is Empty." << endl;
	// }
	// else                                            //used to erase the last spot in the vector
	// {
		// stack_vec.erase(stack_vec.begin()+ctrl);
	// }
}

void MessageStack::Print_stack()
{
	int i=0;
	
	if(!stack_vec.empty())
	{
		for(i=stack_vec.size()-1; i>=0; i--)         //used to loop from the end of the stack to the beginning of the stack and prints each message
		{
			stack_vec[i]->Print_message();
		}
	}
	else
	{
		cout << "\nStack is Empty." << endl;
	}
}

int main(void)
{
	int norm=0, option=0, choice_trans=0;
	string reg_msg;
	// Message* BigMess;
	// Message* temp_str=new Message(); //starting point for the stack
	// MessageStack Stack(temp_str);    //used to create the stack
	Message* temp_str;
	MessageStack Stack;
	while(norm==0)
	{
		cout << "\nPlease choose an action below that you would like to execute:" << endl;
		cout << "1.) Enter Message" << endl;
		cout << "2.) Print Stack" << endl;
		cout << "3.) Pop Member Off of Stack" << endl;
		cout << "4.) Exit Program" << endl;
		cout << "Option:  ";
		cin >> option;
		cout << endl;
		cin.ignore();
		if(!(cin.good()))
		{
			cout << "ERROR!! Please choose one of the numbers below for the option that you would like to execute";
			cout << "1.) Enter Message" << endl;
			cout << "2.) Print Stack" << endl;
			cout << "3.) Pop Member Off of Stack" << endl;
			cout << "4.) Exit Program" << endl;
			cout << "Option:  ";
			cin >> option;
			cout << endl;
			cin.ignore();
		}
		
		switch(option)
		{
			case 1:
				{
					cout << "Please enter a message:  ";
					getline(cin,reg_msg);                             //used to read in message from user
					//BigMess=new Message(reg_msg);                 
					
					cout << "Would you like to change this message to Morse Code? Select '1' for Yes and '2' for No." << endl;
					cout << "Option: ";
					cin >> choice_trans;
					
					while(choice_trans!=1&&choice_trans!=2)
					{
						cout << "ERROR!! You must choose '1' for Yes or '2' for No." << endl;
						cout << "Option: ";
						cin >> choice_trans;
					}
					if(choice_trans==1)
					{
						temp_str=new MorseCodeMessage(reg_msg);        //used dynamic binding to set morse_msg to the message pointer
						//BigMess->Print_message();
						//Stack.Push(BigMess);
						temp_str->Print_message();
						Stack.Push(temp_str);
					}
					else
					{
						temp_str=new Message(reg_msg);                    //used to set pointer to a new message
						// BigMess->Print_message();                       //used to print message
						// Stack.Push(BigMess);                           //used to place message on the stack
						temp_str->Print_message();                        //used to print message
						Stack.Push(temp_str);                             //used to place message on the stack
					}
				}
				break;
			
			case 2:
				cout << "Now printing the stack:" << endl;
				Stack.Print_stack();                             //used to print all the members in the stack
				break;
			
			case 3:
				cout << "Now removing the last member on the stack." << endl;
				Stack.Pop();                                      //removes last member from the stack
				break;
			
			case 4:
				cout << "Terminating Program."<< endl;
				return 0; 
				break;
		
			default:                                            //used to catch any incorrect inputs by user
				cout << "ERROR!! The option you have chosen is invalid. Please try again." << endl;
				break;
		}
	}
	return 0;
}
