#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <unordered_map>

using namespace std;

namespace ariel
{
    template <typename T>
    class BinaryTree
    {
        using iterator = typename std::vector<T>::iterator;

        struct Node
        {
            T value;
            Node *right;
            Node *left;

            Node(T val) : value(val), right(nullptr), left(nullptr) {}
            friend std::ostream &operator<<(std::ostream &out, Node const &n){
                out<<" val="<<n.value;
                if (n.left!=nullptr)
                {
                    out<<"left="<<n.left->value;
                }
                  if (n.right!=nullptr)
                {
                    out<<"right="<<n.right->value;
                }
                return out;
                
            }


        };

        Node *root = nullptr;
        vector<T> inorder;
        vector<T> preorder;
        vector<T> postorder;
        unordered_map<T, Node *> nodes_map;
        void in_order(Node *r);

        void post_order(Node *r);

        void pre_order(Node *r);

    public:
        BinaryTree<T>() {}
        ~BinaryTree<T>(){
             inorder.clear();
            in_order(root);
            for (auto &&i : inorder)
            {
               
            
             if (nodes_map.count(i)>0)
             {
                 delete nodes_map[i];
             }
             nodes_map.erase(i);         
            }
        }
        BinaryTree<T> &add_root(T r);

        BinaryTree<T> &add_left(T e, T add);

        BinaryTree<T> &add_right(T e, T add);

        iterator begin()
        {
            inorder.clear();
            in_order(root);

            return inorder.begin();
        }
        iterator end()
        {
            return inorder.end();
        }
        iterator begin_inorder()
        {
            inorder.clear();
            in_order(root);
      
            return inorder.begin();
        }
        iterator end_inorder()
        {
            return inorder.end();
        }
        iterator begin_preorder()
        {
            preorder.clear();
            pre_order(root);

            return preorder.begin();
        }
        iterator end_preorder()
        {
            return preorder.end();
        }
        iterator begin_postorder()
        {
            postorder.clear();
            post_order(root);

            return postorder.begin();
        }
        iterator end_postorder()
        {
            return postorder.end();
        }
        template <typename O>
        friend std::ostream &operator<<(std::ostream &out, BinaryTree<T> const &b);
    };
    template <typename T>
    std::ostream &operator<<(std::ostream &out, BinaryTree<T> const &b)
    {

        out << "tree";
        return out;
    }
    template <typename T>
    void BinaryTree<T>::in_order(Node *r)
    {
        if (r == nullptr)
        {
            return;
        }
        in_order(r->left);
        inorder.push_back(r->value);
        in_order(r->right);
    }

    template <typename T>
    void BinaryTree<T>::post_order(Node *r)
    {
        if (r == nullptr)
        {
            return;
        }
        post_order(r->left);
        post_order(r->right);
        postorder.push_back(r->value);
    }
    template <typename T>
    void BinaryTree<T>::pre_order(Node *r)
    {
        {
            if (r == nullptr)
            {
                return;
            }
            preorder.push_back(r->value);
            pre_order(r->left);
            pre_order(r->right);
        }
    }
    template <typename T>
    BinaryTree<T> &BinaryTree<T>::add_root(T r)
    {
        if (root == nullptr)
        {
            nodes_map[r] = new Node(r);
            root = nodes_map[r];
        }
        else
        {

            root->value=r;
            nodes_map[r]=root;
            

        }

            

        return *this;
    }
    template <typename T>
    BinaryTree<T> &BinaryTree<T>::add_right(T e, T add)
    {
        if (nodes_map[e] == 0)
        {
            throw invalid_argument{"e  does not exsist in the tree"};
        }

        Node *ex = nodes_map[e];
        if (ex->right == nullptr)
        {
            nodes_map[add] = new Node(add);
            Node *new_right = nodes_map[add];
            ex->right = new_right;
        }
        else
        {

            ex->right->value = add;
            nodes_map[add] = ex->right;
            
        }

            

        return *this;
    }
    template <typename T>
    BinaryTree<T> &BinaryTree<T>::add_left(T e, T add)
    {
        if (nodes_map[e] == 0)
        {
            throw invalid_argument{"e does not exsist in the tree"};
        }
        Node *ex = nodes_map[e];
        if (ex->left == nullptr)
        {
            nodes_map[add] = new Node(add);
            Node *new_left = nodes_map[add];
            ex->left = new_left;
        }
        else
        {

            ex->left->value = add;
            nodes_map[add] = ex->left;
        }
   
        
        return *this;
    }
}

