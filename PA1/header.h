#ifndef PA1
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <time.h>
#include <fstream>
#include <string.h>

using namespace std;

template <class T>
class LinuxCommandData
{
	public:
		T name[30];
		T description[150];
};

template <class T>
class LinuxCommandNode
{
	public:
		T lnxCmd;
		LinuxCommandNode* next;
};

template <class T>
class LinuxCommandList {
	public:
		int countofnodes = -1;
	protected:
		T* head;

	public:
		
		LinuxCommandList()
		{
			head = NULL;
		}

		~LinuxCommandList()
		{

		}

		void PrintGameRules()
		{
			cout << "This is a matching game" << endl;
			cout << "The objective of the game is to match Linux commands to appropriate lnxCmd.descriptions of those commands." << endl;
			cout << "If a command m is matched, then the player earns 1 point. " << endl;
			cout << "If the command is not matched, then the player loses a point. Yes, negative point totals are possible." << endl;
			cout << "The player selects the number of match questions at the beginning of the game." << endl;
			cout << " The game continues until the number is reached. " << endl;
		}
	
		//void PlayGame();

		void AddCommand(T* newCommand)
		{
			if (head != NULL)
			{
				newCommand->next = head;
				head = newCommand;
			}
			else
			{
				head = newCommand;
				head->next = NULL;
			}
			countofnodes++;
			//cout << "Command added successfully" << endl;
		}



		void RemoveCommand(char* lnxCmdToBeRemoved)
		{
			LinuxCommandNode<LinuxCommandData<char>>* tempHead = new LinuxCommandNode<LinuxCommandData<char>>();
			LinuxCommandNode<LinuxCommandData<char>>* prevNode = NULL;
			tempHead = head;
			while (tempHead != NULL)
			{

				if (strcmp(tempHead->lnxCmd.name, lnxCmdToBeRemoved) == 0)
				{
					if (tempHead == head)
					{
						//means the first node command name matched
						head = tempHead->next;
						free(tempHead);
						countofnodes--;
						return;
					}

					else if (tempHead->next == NULL)
					{
						//means the last node command lnxCmd.name matched
						prevNode->next = NULL;
						free(tempHead);
						countofnodes--;
						return;
					}
					else
					{
						//means the middle node command lnxCmd.name matched
						prevNode->next = tempHead->next;
						free(tempHead);
						countofnodes--;
						return;
					}
				}
				prevNode = tempHead;
				tempHead = tempHead->next;
			}
		
		}

		void ListCommands()
		{
			LinuxCommandNode<LinuxCommandData<char>>* p = new LinuxCommandNode<LinuxCommandData<char>>();
			p = head;
			while (p != NULL)
			{
				cout << p->lnxCmd.name << "," << p->lnxCmd.description << endl;
				p = p->next;
			}
		}

	
		void SaveCommandList()
		{
			ofstream outfile;
			outfile.open("commands.csv");

			LinuxCommandNode<LinuxCommandData<char>>* p = new LinuxCommandNode<LinuxCommandData<char>>();
			p = head;
			while (p != NULL)
			{
				outfile << p->lnxCmd.name << "," << p->lnxCmd.description << endl;
				p = p->next;
			}

			outfile.close();
		}

		T* GetNodeAtIndex(int index)
		{
			if (index <0 || index > countofnodes)
				return NULL;
			LinuxCommandNode<LinuxCommandData<char>>* current = head;

			for (int i = 0; i < countofnodes; i++)
			{
				if (i == index)
				{
					return current;
				}
				else
				{
					current = current->next;
				}
			}
		}
};



class Player
{
public:
	int points = 0;
	char name[50];
public:
	Player(char* newname);
	Player()
	{

	}
	~Player()
	{

	}

	void playGame(LinuxCommandList<LinuxCommandNode<LinuxCommandData<char>>>* myGame);


};

#endif