#include <gtest/gtest.h>
#include "../lib/tree_node.cpp"

#include <vector>

using namespace std;

vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> ret;
    
    if (root == nullptr)
        return ret;


    for (auto x : inorderTraversal(root->left)) ret.push_back(x);

    ret.push_back(root->val);

    for (auto x : inorderTraversal(root->right)) ret.push_back(x);

    return ret;
}

TEST(Example, Example1)
{
    auto root = TreeNode(3);
    EXPECT_EQ((vector<int> {3}), inorderTraversal(&root));
}

TEST(Example, Example2)
{
    auto root = TreeNode(1);
    auto right = TreeNode(2);
    auto rightLeft = TreeNode(3);
    root.right = &right;
    root.right->left = &rightLeft;
    EXPECT_EQ((vector<int> {1,3,2}), inorderTraversal(&root));
}

TEST(Example, Example3)
{
    auto root = TreeNode(1);
    auto left = TreeNode(2);
    auto right = TreeNode(3);
    root.right = &right;
    root.left = &left;
    EXPECT_EQ((vector<int> {2,1,3}), inorderTraversal(&root));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}