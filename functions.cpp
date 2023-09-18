#include "header.h"

Player::Player(char *newname)
{
	strcpy(name, newname);


}


void Player::playGame(LinuxCommandList<LinuxCommandNode<LinuxCommandData<char>>>* myGame)
{
	int noOfQuestions;
	cout << "Enter the number of questions you want (From 5-30):" << endl;
	cin >> noOfQuestions;

	system("pause");
	system("cls");
	srand((unsigned)time(0));

	for (int i = 1; i <= noOfQuestions; i++)
	{
		LinuxCommandNode<LinuxCommandData<char>>* randomnode[3];
		randomnode[0] = myGame->GetNodeAtIndex(rand() % myGame->countofnodes);
		randomnode[1] = myGame->GetNodeAtIndex(rand() % myGame->countofnodes);
		randomnode[2] = myGame->GetNodeAtIndex(rand() % myGame->countofnodes);

		int commandq = rand() % 3;
		cout << "Question Number: " << i << endl;

		for (int j = 0; j < 3; j++)
		{
			cout << j + 1 << ") " << randomnode[j]->lnxCmd.description << endl;
		}
		//validate follwing three kines in a loop only 1,2,3
		cout << "Pick the correct description for the following command: " << randomnode[commandq]->lnxCmd.name << endl;


		int answerchoice;
		
		do
		{
			cin >> answerchoice;
		} while (answerchoice < 1 || answerchoice > 6);

		if (randomnode[answerchoice - 1]->lnxCmd.name == randomnode[commandq]->lnxCmd.name)
		{
			points = points + 1;
			cout << "Correct! " << randomnode[answerchoice - 1]->lnxCmd.name << " - " << randomnode[answerchoice - 1]->lnxCmd.description << "You have been awarded 1 point. Your point total is: " << points << endl;

		}
		else
		{
			points = points - 1;
			cout << "Wrong! " << randomnode[answerchoice - 1]->lnxCmd.name << " - " << randomnode[answerchoice - 1]->lnxCmd.description << "You have lost 1 point. Your point total is: " << points << endl;

		}
		system("pause");
		system("cls");
	}

}