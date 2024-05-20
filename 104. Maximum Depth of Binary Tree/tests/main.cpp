#include <gtest/gtest.h>
#include "../src/lib/tree_node.cpp"
#include <map>

using namespace std;

int maxDepth(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    
    return max({maxDepth(root->left), maxDepth(root->right)}) + 1;
}


TEST(Example, DepthZeroExample)
{
    EXPECT_EQ(0, maxDepth(nullptr));
}

TEST(Example, DepthOneExample)
{
    auto root = TreeNode(20);
    EXPECT_EQ(1, maxDepth(&root));
}

TEST(Example, DepthTwoExample)
{
    auto root = TreeNode(20);
    auto right = TreeNode(2);
    root.right = &right;
    EXPECT_EQ(2, maxDepth(&root));
}


TEST(Example, DepthThreeExample)
{
    auto root = TreeNode(20);
    auto right = TreeNode(2);
    auto leftRight = TreeNode(1);
    root.right = &right;
    root.right->left = &leftRight;
    EXPECT_EQ(3, maxDepth(&root));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}