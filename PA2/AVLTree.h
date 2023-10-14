#include "AVLNode.h"

template <typename T>
class AVLTree
{
    public:
        AVLNode<T> *root = nullptr;

        AVLTree()
        {
            this->root = nullptr;
        }

        ~AVLTree()
        {
            delete this->root;
        }

        //height() function 
        int height(AVLNode<T> *node) const
        {
           return node == nullptr ? -1 : node->height;
        }

        //rotateLeft() function 
        void rotateLeft(AVLNode<T> * & k2)
        {
            AVLNode<T> *k1 = k2->left;
            k2->left = k1->right;
            k1->right = k2;
            k2->height = max(height(k2->left), height(k2->right)) + 1;
            k1->height = max(height(k1->left), k2->height) + 1;
            k2 = k1;
        }

        void rotateRight(AVLNode<T> * & k2)
        {
            AVLNode<T> *k1 = k2->right;
            k2->right = k1->left;
            k1->left = k2;
            k2->height = max(height(k2->left), height(k2->right)) + 1;
            k1->height = max(height(k1->left), k2->height) + 1;
            k2 = k1;
        }

        //insert() function 
        void insert(AVLNode<T>* &node, const T& data)
        {
            if (node == nullptr)
            {
                node = new AVLNode<T>(data);
            }  
            else if (data < node->data)
            {
                insert(node->left, data);
                if (height(node->left) - height(node->right) == 2)
                {
                    if (data < node->left->data)
                    {
                        rotateLeft(node);
                    }
                    else
                    {
                        rotateRight(node->left);
                        rotateLeft(node);
                    }
                }
            }
            else if (node->data < data)
            {
                insert(node->right, data);
                if (height(node->right) - height(node->left) == 2)
                {
                    if (node->right->data < data)
                    {
                        rotateRight(node);
                    }
                    else
                    {
                        rotateLeft(node->right);
                        rotateRight(node);
                    }
                }
            }

            node->height = max(height(node->left), height(node->right)) + 1;
        }

        // contains() function 
        bool contains(AVLNode<T>* root, const T& data)
        {
            if (root != nullptr)
            {
                if (root->data == data)
                {
                    return 1;
                }
                else
                {
                    if (data > root->data)
                    {
                        return contains(root->right, data);
                    }
                    else
                    {
                        return contains(root->left, data);
                    }
                }
            }
            else
            {
                return 0;
            }
        }

        int validate(AVLNode<T>* root)
        {
            if (root != nullptr)
            {
                int lefth = height(root->left);
                int righth = height(root->right);

                if (lefth == -1 || righth == -1) return 0;
                
                if (abs(lefth - righth) > 1)
                {
                    return 0;
                }
                else
                {
                    return (validate(root->left) && validate(root->right));
                }
            }
            else
            {
                return 0;
            }
        }
};