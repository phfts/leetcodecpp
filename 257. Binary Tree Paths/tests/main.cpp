#include <gtest/gtest.h>
#include <string>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode* left, TreeNode* right) : val(val), left(left), right(right) {}
};

vector<string> binaryTreePaths(TreeNode *root, string priorPath = "")
{
    vector<string> ret;
    if (root == nullptr) 
    {
        ret.push_back(priorPath);
        return ret;
    }

    string prefix = priorPath.size() == 0 ? to_string(root->val) : (priorPath + "->" + to_string(root->val));
    
    if (root->left == nullptr && root->right == nullptr)
    {
        return {prefix};
    }
    
    if (root->left != nullptr)
    {
        auto leftPaths = binaryTreePaths(root->left, prefix);
        ret.insert(ret.end(), leftPaths.begin(), leftPaths.end());
    }
    if (root->right != nullptr)
    {
        auto rightPaths = binaryTreePaths(root->right, prefix);
        ret.insert(ret.end(), rightPaths.begin(), rightPaths.end());
    }

    return ret;
}

TEST(Example, Example1)
{
    TreeNode* root = new TreeNode(1);
    vector<string> expected = {"1"};
    EXPECT_EQ(expected, binaryTreePaths(root));
}


TEST(Example, Example2)
{
    TreeNode* root = new TreeNode(1, new TreeNode(2), nullptr);
    vector<string> expected = {"1->2"};
    EXPECT_EQ(expected, binaryTreePaths(root));
}

TEST(Example, Example3)
{
    TreeNode* root = new TreeNode(1, new TreeNode(2, nullptr, new TreeNode(5)), new TreeNode(3));
    vector<string> expected = { "1->2->5", "1->3" };
    EXPECT_EQ(expected, binaryTreePaths(root));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}