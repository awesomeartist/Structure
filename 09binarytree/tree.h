
// 树的节点
typedef struct tree_node {
    // 左孩子指针
    struct tree_node *left;
    // 右孩子指针
    struct tree_node *right;
    // 关键字
    char key;
}tree_node;



// 创建一个节点
tree_node *TreeCreateNode(char key);

// 创建一个二叉树
tree_node *TreeCreate();

// 前序遍历1
void PreorderTraverse1(tree_node *node);

// 前序遍历2
void PreorderTraverse2(tree_node *node);

// 中序编列1
void InorderTraverse1(tree_node *node);

// 中序遍历2
void InorderTraverse2(tree_node *node);

// 后序遍历1
void PosorderTraverse1(tree_node *node);

// 后序遍历2
void PosorderTraverse2(tree_node *node);

// 层次遍历
void LevelTraverse(tree_node *root);