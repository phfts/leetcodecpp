#include <gtest/gtest.h>
#include "../lib/tree_node.cpp"
#include <vector>

using namespace std;

TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr)
        return root;
    
    if (root->left == nullptr && root->right == nullptr)
        return root;

    auto oldLeft = root->left;
    root->left = root->right;
    root->right = oldLeft;

    invertTree(root->left);
    invertTree(root->right);

    return root;
}

TEST(Example, Example1)
{
    TreeNode root = TreeNode(1);
    TreeNode left = TreeNode(2);
    TreeNode right = TreeNode(3);
    root.left = &left;
    root.right = &right;

    auto invertedTree = invertTree(&root);
    EXPECT_EQ(1, invertedTree->val);
    EXPECT_EQ(3, invertedTree->left->val);
    EXPECT_EQ(2, invertedTree->right->val);
}

TEST(Example, ExampleSimple)
{
    TreeNode root = TreeNode(1);

    auto invertedTree = invertTree(&root);
    EXPECT_EQ(1, invertedTree->val);
    EXPECT_EQ(nullptr, invertedTree->left);
    EXPECT_EQ(nullptr, invertedTree->right);
}


TEST(Example, ExampleWithMissingNode)
{
    TreeNode root = TreeNode(1);
    TreeNode right = TreeNode(3);
    root.right = &right;

    auto invertedTree = invertTree(&root);
    EXPECT_EQ(1, invertedTree->val);
    EXPECT_EQ(3, invertedTree->left->val);
    EXPECT_EQ(nullptr, invertedTree->right);
}

TEST(Example, ComplexExample)
{
    TreeNode root = TreeNode(1);
    TreeNode left = TreeNode(2);
    TreeNode right = TreeNode(3);
    root.left = &left;
    root.right = &right;

    TreeNode fourth = TreeNode(4);
    root.left->right = &fourth;

    auto invertedTree = invertTree(&root);
    EXPECT_EQ(1, invertedTree->val);
    EXPECT_EQ(3, invertedTree->left->val);
    EXPECT_EQ(2, invertedTree->right->val);
    EXPECT_EQ(4, invertedTree->right->left->val);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}