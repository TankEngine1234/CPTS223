#include "AVLTree.h"
#include <algorithm>
#include <random>

int main()
{
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;

    for (int i = 1; i <= 100; i++)
    {
        if (i % 2 != 0)
        {
            v1.push_back(i);
            v2.insert(v2.begin(), i);
            v3.push_back(i);
        }
    }
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(v3.begin(), v3.end(), g);


    AVLTree<int> t1;
    for (int i : v1)
    {
        t1.insert(t1.root, i);
    }

    cout << "AVLTree 1 Height: " << t1.height(t1.root) << endl;
    cout << "AVLTree 1 Validate: " << t1.validate(t1.root) << endl;
    cout << "AVLTree 1 Contains Prints:" << endl;
    for (int i = 1; i <= 100; i++)
    {
        cout << t1.contains(t1.root, i);
    }

    AVLTree<int> t2;
    for (int i : v2)
    {
        t2.insert(t2.root, i);
    }

    cout << "\nAVLTree 2 Height: " << t2.height(t2.root) << endl;
    cout << "AVLTree 2 Validate: " << t2.validate(t2.root) << endl;
    cout << "AVLTree 2 Contains Prints:" << endl;
    for (int i = 1; i <= 100; i++)
    {
        cout << t2.contains(t2.root, i);
    }

    AVLTree<int> t3;
    for (int i : v3)
    {
        t3.insert(t3.root, i);
    }

    cout << "\nAVLTree 3 Height: " << t3.height(t3.root) << endl;
    cout << "AVLTree 3 Validate: " << t3.validate(t3.root) << endl;
    cout << "AVLTree 3 Contains Prints:" << endl;
    for (int i = 1; i <= 100; i++)
    {
        cout << t3.contains(t3.root, i);
    }
}