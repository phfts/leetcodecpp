#include <gtest/gtest.h>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode* left, TreeNode* right) : val(val), left(left), right(right) {}
};

bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (p == nullptr && q == nullptr)
        return true;

    if (p == nullptr && q != nullptr)
        return false;

    if (q == nullptr && p != nullptr)
        return false;

    if (q->val != p->val)
        return false;
    
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

TEST(Example, Example1)
{
    EXPECT_EQ(true, isSameTree(nullptr, nullptr));
    EXPECT_EQ(false, isSameTree(nullptr, new TreeNode(3)));
    EXPECT_EQ(false, isSameTree(new TreeNode(4), new TreeNode(3)));
    EXPECT_EQ(true, isSameTree(new TreeNode(14), new TreeNode(14)));
    EXPECT_EQ(false, isSameTree(new TreeNode(14), new TreeNode(14, new TreeNode(3), nullptr)));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}