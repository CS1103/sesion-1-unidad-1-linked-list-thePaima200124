#include <iostream>
#include <string>
#include <cassert>
#include "Linked_list.h"

using namespace std;

int main()
{
	utec::linked_list_t pp;

	//Probar el metodo push_front
	 
	for (int i = 0; i < 10; i++)
	{
		pp.push_back(i);
	}
	
	for (int i = 0; i < 10; i++)
	{
		cout << pp.item(i) << endl;
	}
	//Verifico el size 

	assert(pp.size() == 10);

	utec::linked_list_t aa(pp);

	for (int i = 0; i < 10; i++)
	{
		cout << aa.item(i) << endl;
	}


	/*
	string result;

	for (int i = 0; i < 10; i++)
	{
		result += to_string(pp.item(i)) + " ";
	}

	assert(result == "9 8 7 6 5 4 3 2 1 0 ");

	//pop_front 
	// probar el metodo push_front 

	for (int i = 0; i < 5; i++)
	{
		pp.pop_front();
	}
	
	//verifico el tamaño

	assert(pp.size() == 5);

	//probar el metodo push front

	for (int i = 0; i < 5; i++)
	{
		pp.pop_front();
	}

	//verifico el tamaño

	assert(pp.size() == 0);
	*/

	cout << "Ejecucion exitosa" << endl; 

}