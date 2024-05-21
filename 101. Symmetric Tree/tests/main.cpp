#include <gtest/gtest.h>
#include <vector>
#include <map>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    void bfs(TreeNode *node, vector<TreeNode *> &values, bool invert = true)
    {
        if (node == nullptr)
            return;

        values.push_back(node);
        for (int i = 0; i < values.size(); i++)
        {
            TreeNode *currentNode = values[i];
            if (currentNode == nullptr)
                continue;

            if (invert)
            {
                values.push_back(currentNode->right);
                values.push_back(currentNode->left); 
            }
            else
            {
                values.push_back(currentNode->left);
                values.push_back(currentNode->right);
            }
        }
    };

    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr)
            return true;

        vector<TreeNode *> leftNodes;
        vector<TreeNode *> rightNodes;
        bfs(root->left, leftNodes, false);
        bfs(root->right, rightNodes, true);

        std::cout << "Left nodes: " << leftNodes.size() << std::endl;
        for (auto x : leftNodes)
        {
            if (x != nullptr)
                std::cout << x->val << " ";
            else 
                std::cout << "null" << " ";
        }
        std::cout << std::endl;

        std::cout << "Right nodes: " << rightNodes.size() << std::endl;
        for (auto x : rightNodes)
        {
            if (x != nullptr)
                std::cout << x->val << " ";
            else 
                std::cout << "null" << " ";
        }
        std::cout << std::endl;

        if (leftNodes.size() != rightNodes.size())
            return false;

        int n = leftNodes.size();
        for (int i = 0; i < n; i++)
        {
            if (leftNodes[i] == nullptr && rightNodes[i] != nullptr)
                return false;

            if (leftNodes[i] != nullptr && rightNodes[i] == nullptr)
                return false;

            if (leftNodes[i] == nullptr && rightNodes[i] == nullptr)
                continue;

            if (leftNodes[i]->val != rightNodes[i]->val)
                return false;
        }
        return true;
    }
};

TEST(Example, Example1)
{
    auto s = Solution();
    TreeNode *root = new TreeNode(1);
    EXPECT_EQ(true, s.isSymmetric(root));
}

TEST(Example, Example2)
{
    auto s = Solution();
    TreeNode *left = new TreeNode(2, new TreeNode(3), new TreeNode(4));
    TreeNode *right = new TreeNode(2, new TreeNode(4), new TreeNode(3));
    TreeNode *root = new TreeNode(1, left, right);
    EXPECT_EQ(true, s.isSymmetric(root));
}

TEST(Example, Example3)
{
    auto s = Solution();
    TreeNode *left = new TreeNode(2, nullptr, new TreeNode(3));
    TreeNode *right = new TreeNode(2, nullptr, new TreeNode(3));
    TreeNode *root = new TreeNode(1, left, right);
    EXPECT_EQ(false, s.isSymmetric(root));
}

TEST(Example, Example4)
{
    auto s = Solution();
    TreeNode *left = new TreeNode(2);
    TreeNode *right = new TreeNode(3);
    TreeNode *root = new TreeNode(1, left, right);
    EXPECT_EQ(false, s.isSymmetric(root));
}


int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}