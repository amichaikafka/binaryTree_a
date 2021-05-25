#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <map>

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
        map<T, Node *> nodes_map;
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
                delete nodes_map[i];
            }
        }
        BinaryTree<T> &add_root(T r);

        BinaryTree<T> &add_left(T e, T add);

        BinaryTree<T> &add_right(T e, T add);

        iterator begin()
        {
            inorder.clear();
            in_order(root);
            // for (auto &&i : inorder)
            // {
            //     cout << i << ",";
            // }
            // cout<<"\n";

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
            // for (auto &&i : inorder)
            // {
            //     cout << i << ",";
            // }
            // cout<<"\n";
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
            // for (auto &&i : preorder)
            // {
            //     cout << i << ",";
            // }
            // cout<<"\n";
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
            // for (auto &&i : postorder)
            // {
            //     cout << i << ",";
            // }
            // cout<<"\n";
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
            // const iterator it = nodes_map.find(root->value);
            // if (it != nodes_map.end())
            // {

            //     std::swap(nodes_map[r], it->second);
            //     nodes_map.erase(it);
            // }
            // nodes_map[r] = new Node(r);
            // T t=root->value;
            // nodes_map[r]->right = root-right;
            // nodes_map[r]->left = root-left;
            // root=nodes_map[r];
            // delete nodes_map[t];
            // nodes_map.erase(t);
            root->value=r;
            nodes_map[r]=root;
            

        }
        //   for (auto &i : nodes_map)
        //     {
        //         cout<<"r="<<r<<" key="<<i.first<<*(i.second)<<"\n";
        //     }
            

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
            // const iterator it = nodes_map.find(ex->right->value);
            // if (it != nodes_map.end())
            // {

            //     std::swap(nodes_map[add], it->second);
            //     nodes_map.erase(it);
            // }
            ex->right->value = add;
            nodes_map[add] = ex->right;
            
        }
        //   for (auto &i : nodes_map)
        //     {
        //         cout<<"add="<<add<<" key="<<i.first<<*(i.second)<<"\n";
        //     }
            

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
            // const iterator it = nodes_map.find(ex->left->value);
            // if (it != nodes_map.end())
            // {

            //     std::swap(nodes_map[add], it->second);
            //     nodes_map.erase(it);
            // }
            ex->left->value = add;
            nodes_map[add] = ex->left;
        }
        // if (add==2)
        // {
            // for (auto &i : nodes_map)
            // {
            //     cout<<"add="<<add<<" key="<<i.first<<*(i.second)<<"\n";
            // }
            
            /* code */
        // }
        
        return *this;
    }
}

