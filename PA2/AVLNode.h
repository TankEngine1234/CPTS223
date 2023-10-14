#include "functions.h"

template <typename T>
class AVLNode
{
    public:
        T data;
        AVLNode* left;
        AVLNode* right;
        int height;

        AVLNode(T newData)
        {
           data = newData;
           left = nullptr;
           right = nullptr;
           height = 0;
        }

	    ~AVLNode()
        {
            if (this->left != nullptr)
            {
                delete this->left;
            }
            if (this->right != nullptr)
            {
                delete this->right;
            }
        }

};