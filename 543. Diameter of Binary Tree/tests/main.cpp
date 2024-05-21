#include <gtest/gtest.h>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int maxDepth(TreeNode* root) 
{
    if (root == nullptr) 
        return 0;

    int a = root->left == nullptr ?  0 : 1 + maxDepth(root->left);
    int b = root->right == nullptr ?  0 : 1 + maxDepth(root->right);
    return max({a,b});
}

int diameterOfBinaryTree(TreeNode* root) 
{
    if (root == nullptr) 
        return 0;
    
    int a = root->left == nullptr ?  0 : 1 + maxDepth(root->left);
    int b = root->right == nullptr ?  0 : 1 + maxDepth(root->right);
    return max({a + b, diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)});
}

TEST(Example, Example1)
{
    TreeNode *root = new TreeNode(1);
    EXPECT_EQ(0, diameterOfBinaryTree(root));
}

TEST(Example, Example2)
{
    TreeNode *root = new TreeNode(1, new TreeNode(2), nullptr);
    EXPECT_EQ(1, diameterOfBinaryTree(root));
}

TEST(Example, Example3)
{
    TreeNode *root = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(4)), nullptr);
    EXPECT_EQ(2, diameterOfBinaryTree(root));
}


TEST(Example, Example4)
{
    TreeNode *root = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3));
    EXPECT_EQ(3, diameterOfBinaryTree(root));
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}