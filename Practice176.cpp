/*177. Code: BST to Sorted LL: Given a BST, convert it into a sorted linked list. You have to return the head of LL.*/

/**********************************************************

    Following are the Binary Tree Node class structure and the
    Node class structure

    template <typename T>
    class BinaryTreeNode {
        public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

    template <typename T>
    class Node{
        public:
        T data;
        Node<T> *next;

        Node(T data) {
            this->data = data;
            this->next = NULL;
        }
    };

***********************************************************/

pair<Node<int> *, Node<int> *> helper(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        pair<Node<int> *, Node<int> *> ans;
        ans.first = NULL;
        ans.second = NULL;
        return ans;
    }
    pair<Node<int> *, Node<int> *> leftAns = helper(root->left);
    pair<Node<int> *, Node<int> *> rightAns = helper(root->right);
    pair<Node<int> *, Node<int> *> ans;
    Node<int> *node = new Node<int>(root->data);
    node->next = rightAns.first;
    if (leftAns.second != NULL)
    {
        leftAns.second->next = node;
    }

    if (leftAns.first != NULL)
    {
        ans.first = leftAns.first;
    }
    else
    {
        ans.first = node;
    }

    if (rightAns.second != NULL)
    {
        ans.second = rightAns.second;
    }
    else
    {
        ans.second = node;
    }

    return ans;
}

Node<int> *constructLinkedList(BinaryTreeNode<int> *root)
{
    return helper(root).first;
}