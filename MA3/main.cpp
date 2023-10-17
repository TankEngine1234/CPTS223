#include <map>
#include "TwitterData.hpp"
using namespace std;

int main(int argc, char *argv[])
{
    // Schema: UserName,Last,First,Email,NumTweets,MostViewedCategory
    string raw_data[5][6] = {{"rangerPower", "Smit", "Rick", "smitRick@gmail.com", "1117", "power lifting"},
                             {"kittyKat72", "Smith", "Kathryn", "kat@gmail.com", "56", "health"},
                             {"lexi5", "Anderson", "Alexis", "lexi5@gmail.com", "900", "education"},
                             {"savage1", "Savage", "Ken", "ksavage@gmail.com", "17", "president"},
                             {"smithMan", "Smith", "Rick", "rick@hotmail.com", "77", "olympics"}};
    TwitterData *twitter_data = new TwitterData[5];
    for (int i = 0; i < 5; ++i)
    {
        twitter_data[i].setUserName(raw_data[i][0]);
        twitter_data[i].setActualName(raw_data[i][2] + " " + raw_data[i][1]);
        twitter_data[i].setEmail(raw_data[i][3]);
        twitter_data[i].setNumTweets(stoi(raw_data[i][4]));
        twitter_data[i].setCategory(raw_data[i][5]);
    }

    // Scenario 1
    map<string, TwitterData> map1;
    for (int i = 0; i < 5; i++)
    {
     map1[twitter_data[i].getUserName()] = twitter_data[i];   
    }

    cout << "Print searchByName map:" << endl;
    for (map<string, TwitterData>::iterator it = map1.begin(); it != map1.end(); it++)
    {
        cout << "Key: " << it->first << ", Value: " << it->second.print() << endl;
    }

    cout << "Search for key: savage1 Value: ";
    if (map1.find("savage1") != map1.end())
    {
        cout << map1["savage1"].print() << endl;
        map1.erase("savage1");
    }
    else
    {
        cout << "savage1 couldn't be found!" << endl;
    }

    // Scenario 2
    map<string, TwitterData> map2;
    for (int i = 0; i < 5; i++)
    {
        map2[twitter_data[i].getEmail()] = twitter_data[i];   
    }

    cout << endl;
    cout << "Print searchByEmail map:" << endl;
    for (map<string, TwitterData>::iterator it = map2.begin(); it != map2.end(); it++)
    {
        cout << "Key: " << it->first << ", Value: " << it->second.print() << endl;
    }


    cout << "Search for key: kat@gmail.com Value: ";
    if (map2.find("kat@gmail.com") != map2.end())
    {
        cout << map2["kat@gmail.com"].print() << endl;
        map2.erase("kat@gmail.com");
    }
    else
    {
        cout << "kat@gmail.com couldn't be found!" << endl;
    }

    return 0;
}