#pragma once 


#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

struct ListNode {

int val;
ListNode* next;
public:
	ListNode(int val)
	{
		this->val = val;
		this->next = nullptr;
	}

};

class LinkedList {

private:
	ListNode* head;
	ListNode* tail;
	
public:
	LinkedList(){
		this->head = nullptr;
		this->tail = nullptr;	
	}

	void insertFront(int val)
	{
		ListNode* newNode = new ListNode(val);
		if(head)
		{
			newNode->next = head->next;
			head->next = newNode;
		}	
		else{
			head = tail = newNode;	
		}	
	}
	
	void insertEnd(int val)
	{
	
		ListNode* newNode = new ListNode(val);
		if(head)
		{
			tail->next = newNode;
			tail = newNode;
		}	
		else
			head = tail = newNode;	
	}
	
	void display()
	{
		ListNode* temp = head;
		while(temp)
		{
			if(!temp->next)
				cout << temp->val << endl;
			else
				cout << temp->val << " -> ";
		        temp = temp->next;	
		}
	}
	
	void removeNode(int val)
	{
		if (!head)
			return;
		if(head->val == val)
			head = head->next;
		else{
			ListNode* temp = head;
			while(temp->next)
			{
				if(temp->next->val == val)
					break;
				temp = temp->next;
			}
			temp->next = temp->next->next;
		}	
	}
};
