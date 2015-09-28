#include <iostream>
#include <iomanip>
#include "Palindrome.hpp"

int Palindrome::test_string(const std::string& s)
{
	int count_dracula = 0;
	
	//Create Stack
	Stackindrome Stackarino;

	//Create a Queue
	PalinQueue Queuearino;

	//Call Recursion
	enqueue_n_push_yo(s, Queuearino, Stackarino);

	for(int i = 0 ; i < Stackarino.size() ; ++i )
	{
		//check to see if the dequeue matches the pop
		if( Queuearino.dequeue() == Stackarino.pop())
		{
			//if it matches, increment the count
			++count_dracula;
		}
		else
		{
			//If it doesn't match, we are not a palindrome, so return the current count
			return count_dracula;
		}
	}

	//Return -1 if we are a palindrome
	return -1;

}

void Palindrome::enqueue_n_push_yo(std::string mah_string, PalinQueue& mah_q , Stackindrome& mah_staq) 
{
	//make sure the string is not empty
	if(mah_string != "")
	{
		//make sure all of the characters are actually letters
		if(isalpha(mah_string[0]))
		{
			//enqueue the string into the queue 
			mah_q.enqueue(toupper(mah_string[0]));

			//push the string onto the stack
			mah_staq.push(toupper(mah_string[0]));
		}
		//call the recusion
		enqueue_n_push_yo(mah_string.substr(1) , mah_q, mah_staq);
	}
}
