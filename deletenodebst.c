struct TreeNode* smallest(struct TreeNode* root)
{
    struct TreeNode * cur=root;
    while(cur->left!=NULL)
    {
        cur=cur->left;
    }
    return cur;
}

struct TreeNode* deleteNode(struct TreeNode* root, int key)
{

	 // base case
    if(root==NULL)
    {
        return root;
    }
    
	// If the key to be deleted is smallerthan the root's key,
    // then it lies in left subtree

    if(key < root->val)
    {
        root->left = deleteNode(root->left,key);
    }
	
	// If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
	
    else if(key > root->val)
    {
        root->right=deleteNode(root->right,key);
    }
	
	 // if key is same as root's key, then This is the node
    // to be deleted
	
    else
    {
		 // node with only one child or no child
		 
        if (root->left == NULL)
        {
            struct TreeNode *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct TreeNode *temp = root->left;
            free(root);
            return temp;
        }
        struct TreeNode *temp = smallest(root->right);
        root->val = temp->val;
        root->right = deleteNode(root->right, root->val);
    }
    
    return root;
}
