/* ADVANTAGES/DISADVANTAGES LINKED LIST:

* Pros: Simplifies the process of inserting and deleting elements
* 
* Cons: Consumes a significant amount of memory, challenging to navigate in reverse, inability to directly access individual elements
* 
* 
* ADVANTAGES/DISADVANTAGES ARRAY:
* 
* Pros: Allows for direct access to individual elements without needing to traverse through others
* 
* 
* 
*/


#include "header.h"

int main(void)
{
	LinuxCommandList<LinuxCommandNode<LinuxCommandData<char>>>* myGame = new LinuxCommandList<LinuxCommandNode<LinuxCommandData<char>>>();
	
	Player* players[20];
	int currentplayerindex = -1;
	
	

	char username[30];
	

	int input;
	do
	{
		cout << "Main Menu" << endl;
		cout << "1.Game Rules" << endl;
		cout << "2.Play Game" << endl;
		cout << "3.Load Previous Game" << endl;
		cout << "4.Add Command" << endl;
		cout << "5.Remove Command" << endl;
		cout << "6.Exit" << endl;
		cout << "Enter your option:" << endl;
		
		cin >> input;
		do
		{
			
			cout << "please enter from 1-6" << endl;
			cin >> input;

		} while (input < 1 || input > 6);
		
		
		switch (input)
		{
		case 1:
			myGame->PrintGameRules();
			system("pause");
			system("cls");
			break;

		case 2:
			FILE * infile;
			infile = fopen("commands.csv", "r");
			if (infile == NULL)
				return NULL;

			cout << "\nLoading file..." << endl;
			while (!feof(infile))
			{
				LinuxCommandNode<LinuxCommandData<char>>* newCommand = new LinuxCommandNode<LinuxCommandData<char>>();

				fscanf(infile, "%[^,],%[^\n]\n", newCommand->lnxCmd.name, newCommand->lnxCmd.description);

				myGame->AddCommand(newCommand);

			}
			//myGame->ListCommands();
			fclose(infile);

			
			cout << "Please enter the username for Player:" << endl;
			cin >> username;
			players[++currentplayerindex] = new Player(username);


			players[currentplayerindex]->playGame(myGame);
			
			
			system("pause");
			system("cls");

			break;

		case 3:
			char savedprofilename[30];
			cout << "Enter the username of the profile you want to resume playing: " << endl;
			cin >> savedprofilename;
			
			for (int i = 0; i <= currentplayerindex; i++)
			{
				if (strcmp(savedprofilename, players[i]->name) == 0)
				{
					cout << "Found player " << players[i]->name << " with points: " << players[i]->points << endl;;
					players[i]->playGame(myGame);

					break;
				}
				
			}
			
		
		break;
		
		case 4:
		{
			
			LinuxCommandNode<LinuxCommandData<char>>* newCommand = new LinuxCommandNode<LinuxCommandData<char>>();
			cout << "Enter name of linux command" << endl;
			cin >> newCommand->lnxCmd.name;
			cout << "Enter description of linux command" << endl;
			cin.ignore();
			cin.getline(newCommand->lnxCmd.description, 150);
			myGame->AddCommand(newCommand);
			myGame->ListCommands();
			system("pause");
			system("cls");
		}
		break;

		case 5:
			char removecommand[30];
			cout << "Enter command name to remove:" << endl;
			cin >> removecommand;
			cout << "removing command" << endl;
			myGame->RemoveCommand(removecommand);
			myGame->ListCommands();
			system("pause");
			system("cls");
			
			break;

		case 6:
			myGame->SaveCommandList();

			ofstream outfile;
			outfile.open("profiles.csv");
			for (int i = 0; i <= currentplayerindex; i++)
			{
				outfile << players[i]->name << "," << players[i]->points << endl;
			}

			outfile.close();

			break;


		}
	} while (input != 6);
}


