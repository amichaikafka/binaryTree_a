#include "doctest.h"
#include "sources/BinaryTree.hpp"
#include <istream>
#include <string>
#include <set>
using namespace std;
using namespace ariel;

BinaryTree<string> str_tree;

BinaryTree<int> init_init(int i)
{
    BinaryTree<int> ints_tree;
    if (i == 1)
    {
        ints_tree.add_root(1)
            .add_left(1, 2)
            .add_right(1, 17)
            .add_left(2, 3)
            .add_right(2, 10)
            .add_left(17, 18)
            .add_right(17, 25)
            .add_left(3, 4)
            .add_right(3, 7)
            .add_left(10, 11)
            .add_right(10, 14)
            .add_left(18, 19)
            .add_right(18, 22)
            .add_left(25, 26)
            .add_right(25, 29)
            .add_left(4, 5)
            .add_right(4, 6)
            .add_left(7, 8)
            .add_right(7, 9)
            .add_left(11, 12)
            .add_right(11, 13)
            .add_left(14, 15)
            .add_right(14, 16)
            .add_left(19, 20)
            .add_right(19, 21)
            .add_left(22, 23)
            .add_right(22, 24)
            .add_left(26, 27)
            .add_right(26, 28)
            .add_left(29, 30)
            .add_right(29, 31);
    }
    if (i == 2)
    {
        ints_tree.add_root(1);
        for (int j = 2; j < 1001; j++)
        {

            ints_tree.add_right(j - 1, j);
        }
    }
    if (i == 3)
    {
        ints_tree.add_root(1000);
        for (int j = 999; j > 0; j--)
        {

            ints_tree.add_left(j + 1, j);
        }
    }
    return ints_tree;
}
BinaryTree<char> init_str(string str)
{
    BinaryTree<char> chr_tree;
    chr_tree.add_root(str[0]);

    for (unsigned int i = 1; i < str.length(); i++)
    {
        chr_tree.add_left(str[i - 1], str[i]);
    }
    return chr_tree;
}
BinaryTree<char> init_chr(int i)
{
    BinaryTree<char> chr_tree;
    if (i == 1)
    {
        /* code */

        chr_tree.add_root('A')
            .add_left('A', 'B')
            .add_right('A', 'Q')
            .add_left('B', 'C')
            .add_right('B', 'J')
            .add_left('Q', 'R')
            .add_right('Q', 'Y')
            .add_left('C', 'D')
            .add_right('C', 'G')
            .add_left('J', 'K')
            .add_right('J', 'N')
            .add_left('R', 'S')
            .add_right('R', 'V')
            .add_left('Y', 'Z')
            .add_left('D', 'E')
            .add_right('D', 'F')
            .add_left('G', 'H')
            .add_right('G', 'I')
            .add_left('K', 'L')
            .add_right('K', 'M')
            .add_left('N', 'O')
            .add_right('N', 'P')
            .add_left('S', 'T')
            .add_right('S', 'U')
            .add_left('V', 'W')
            .add_right('V', 'X');
    }
    if (i == 2)
    {
        chr_tree.add_root('Z');
        for (char c = 'Y'; c >= 'A'; c--)
        {
            chr_tree.add_right(c + 1, c);
        }
    }
    if (i == 3)
    {
        chr_tree.add_root('a');
        for (char c = 'b'; c <= 'z'; c++)
        {
            chr_tree.add_left(c - 1, c);
        }
    }
    return chr_tree;
}

TEST_CASE("int pre order")
{
    BinaryTree<int> tree = init_init(1);
    string ex;
    string res;
    //complelte tree
    for (int i = 1; i < 32; i++)
    {
        ex += to_string(i);
    }
    for (auto it = tree.begin_preorder(); it != tree.end_preorder(); ++it)
    {
        res += to_string(*it);
    }
    CHECK(res == ex);
    res = "";
    CHECK_THROWS(tree.add_right(55, 32));
    CHECK_NOTHROW(tree.add_right(31, 32));
    ex += "32";
    for (auto it = tree.begin_preorder(); it != tree.end_preorder(); ++it)
    {
        res += to_string(*it);
    }
    CHECK(res == ex);

    ex = "";
    res = "";
    BinaryTree<int> tree2 = init_init(2);
    //tree with just right side
    for (int i = 1; i < 1001; i++)
    {
        ex += to_string(i);
    }
    for (auto it = tree2.begin_preorder(); it != tree2.end_preorder(); ++it)
    {
        res += to_string(*it);
    }
    CHECK(res == ex);
    res = "";
    CHECK_THROWS(tree2.add_left(9999, 10002));
    CHECK_NOTHROW(tree2.add_right(1000, 1001));
    ex += "1001";
    for (auto it = tree2.begin_preorder(); it != tree2.end_preorder(); ++it)
    {
        res += to_string(*it);
    }
    CHECK(res == ex);
    ex = "";
    res = "";
    BinaryTree<int> tree3 = init_init(3);
    //tree with just left side
    for (int i = 1000; i > 0; i--)
    {
        ex += to_string(i);
    }
    for (auto it = tree3.begin_preorder(); it != tree3.end_preorder(); ++it)
    {
        res += to_string(*it);
    }

    CHECK(res == ex);
    CHECK_NOTHROW(tree3.add_left(1000, 1001));
}
TEST_CASE("int in order")
{
    BinaryTree<int> tree = init_init(1);
    string ex = "54638792121113101514161201921182322241727262825302931";
    string res;
    //complelte tree

    for (auto it = tree.begin_inorder(); it != tree.end_inorder(); ++it)
    {
        res += to_string(*it);
    }
    CHECK(res == ex);
    res = "";
    CHECK_THROWS(tree.add_right(60, 32));
    CHECK_NOTHROW(tree.add_right(31, 32));
    ex += "32";
    for (auto it = tree.begin_inorder(); it != tree.end_inorder(); ++it)
    {
        res += to_string(*it);
    }
    CHECK(res == ex);
    ex = "";
    res = "";
    BinaryTree<int> tree2 = init_init(2);
    //tree with just right side
    for (int i = 1; i < 1001; i++)
    {
        ex += to_string(i);
    }
    for (auto it = tree2.begin_inorder(); it != tree2.end_inorder(); ++it)
    {
        res += "" + to_string(*it);
    }
    CHECK(res == ex);

    ex = "";
    res = "";
    BinaryTree<int> tree3 = init_init(3);
    //tree with just left side
    for (int i = 1; i < 1001; i++)
    {
        ex += to_string(i);
    }
    for (auto it = tree3.begin_inorder(); it != tree3.end_inorder(); ++it)
    {
        res += to_string(*it);
    }

    CHECK(res == ex);
    res = "";
    CHECK_THROWS(tree3.add_left(9999, 12342));
    CHECK_NOTHROW(tree3.add_right(1000, 1001));
    ex += "1001";
    for (auto it = tree3.begin_inorder(); it != tree3.end_inorder(); ++it)
    {
        res += to_string(*it);
    }
    CHECK(res == ex);
}
TEST_CASE("int post order")
{
    BinaryTree<int> tree = init_init(1);
    string ex = "56489731213111516141022021192324221827282630312925171";
    string res;
    //general tree

    for (auto it = tree.begin_postorder(); it != tree.end_postorder(); ++it)
    {
        res += to_string(*it);
    }
    CHECK(res == ex);
    ex = "";
    res = "";
    BinaryTree<int> tree2 = init_init(2);
    //tree with just right side
    for (int i = 1000; i > 0; i--)
    {
        ex += to_string(i);
    }
    for (auto it = tree2.begin_postorder(); it != tree2.end_postorder(); ++it)
    {
        res += to_string(*it);
    }
    CHECK(res == ex);
    res = "";
    CHECK_THROWS(tree2.add_left(9999, 12342));
    CHECK_NOTHROW(tree2.add_right(1000, 1001));
    ex = "1001" + ex;
    for (auto it = tree2.begin_postorder(); it != tree2.end_postorder(); ++it)
    {
        res += to_string(*it);
    }
    CHECK(res == ex);
    ex = "";
    res = "";
    BinaryTree<int> tree3 = init_init(3);
    //tree with just left side
    for (int i = 1; i < 1001; i++)
    {
        ex += to_string(i);
    }
    for (auto it = tree3.begin_postorder(); it != tree3.end_postorder(); ++it)
    {
        res += to_string(*it);
    }

    CHECK(res == ex);
}
TEST_CASE("char pre order")
{
    BinaryTree<char> tree = init_chr(1);
    string ex;
    string res;
    //complelte tree
    for (char c = 'A'; c <= 'Z'; c++)
    {
        ex += c;
    }
    for (auto it = tree.begin_preorder(); it != tree.end_preorder(); ++it)
    {
        res += (*it);
    }
    CHECK(res == ex);
    res = "";
    CHECK_THROWS(tree.add_right(']', '4'));
    CHECK_NOTHROW(tree.add_right('Z', '*'));
    ex += '*';
    for (auto it = tree.begin_preorder(); it != tree.end_preorder(); ++it)
    {
        res += *it;
    }
    CHECK(res == ex);
    ex = "";
    res = "";
    BinaryTree<char> tree2 = init_chr(2);
    //tree with just right side
    for (char c = 'Z'; c >= 'A'; c--)
    {
        ex += c;
    }
    for (auto it = tree2.begin_preorder(); it != tree2.end_preorder(); ++it)
    {
        res += (*it);
    }
    CHECK(res == ex);
    ex = "";
    res = "";
    BinaryTree<char> tree3 = init_chr(3);
    //tree with just left side
    for (char c = 'a'; c <= 'z'; c++)
    {
        ex += c;
    }
    for (auto it = tree3.begin_preorder(); it != tree3.end_preorder(); ++it)
    {
        res += (*it);
    }

    CHECK(res == ex);
}
TEST_CASE("char in order")
{
    BinaryTree<char> tree = init_chr(1);
    string ex = "EDFCHGIBLKMJONPATSURWVXQZY";
    string res;
    //complelte tree

    for (auto it = tree.begin_inorder(); it != tree.end_inorder(); ++it)
    {
        res += (*it);
    }
    CHECK(res == ex);
    ex = "";
    res = "";
    BinaryTree<char> tree2 = init_chr(2);
    //tree with just right side
    for (char c = 'Z'; c >= 'A'; c--)
    {
        ex += c;
    }
    for (auto it = tree2.begin_inorder(); it != tree2.end_inorder(); ++it)
    {
        res += (*it);
    }
    CHECK(res == ex);
    ex = "";
    res = "";
    BinaryTree<char> tree3 = init_chr(3);
    //tree with just left side
    for (char c = 'z'; c >= 'a'; c--)
    {
        ex += c;
    }
    for (auto it = tree3.begin_inorder(); it != tree3.end_inorder(); ++it)
    {
        res += (*it);
    }

    CHECK(res == ex);
}
TEST_CASE("int post order")
{
    BinaryTree<char> tree = init_chr(1);
    string ex = "EFDHIGCLMKOPNJBTUSWXVRZYQA";
    string res;
    //complelte tree

    for (auto it = tree.begin_postorder(); it != tree.end_postorder(); ++it)
    {
        res += (*it);
    }
    CHECK(res == ex);
    ex = "";
    res = "";
    BinaryTree<char> tree2 = init_chr(2);
    //tree with just right side
    for (char c = 'A'; c <= 'Z'; c++)
    {
        ex += c;
    }
    for (auto it = tree2.begin_postorder(); it != tree2.end_postorder(); ++it)
    {
        res += (*it);
    }
    CHECK(res == ex);
    ex = "";
    res = "";
    BinaryTree<char> tree3 = init_chr(3);
    //tree with just left side
    for (char c = 'z'; c >= 'a'; c--)
    {
        ex += c;
    }
    for (auto it = tree3.begin_postorder(); it != tree3.end_postorder(); ++it)
    {
        res += (*it);
    }

    CHECK(res == ex);
}
TEST_CASE("string test")
{
    string s = "Test Amichai";
    string res;
    BinaryTree<char> tree = init_str(s);
    CHECK_THROWS(tree.add_right(']', '4'));
    for (auto it = tree.begin_preorder(); it != tree.end_preorder(); ++it)
    {
        res += *it;
    }
    CHECK(res == s);
    res = "";
    string ex;
    for (unsigned int i = s.length() - 1; i >= 0; i--)
    {
        ex += s[i];
        if (i == 0)
        {
            break;
        }
    }
    for (auto it = tree.begin_inorder(); it != tree.end_inorder(); ++it)
    {
        res += *it;
    }
    CHECK(res == ex);
    res = "";
    for (auto it = tree.begin_postorder(); it != tree.end_postorder(); ++it)
    {
        res += (*it);
    }
    CHECK(res == ex);
}