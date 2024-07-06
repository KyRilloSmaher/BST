class BST{

private:

	struct node {
		 int data;
		 node*left;
		 node*right;

		};
	int count;
	node*root;

	void AddLeafPrivate(int key,node*ptr);
	void PrintInOrderPrivate(node*ptr);
	node* ReturnNodePrivate(int key, node*ptr);
	int FindSmallPrivate(node*ptr);
	void RemoveRootMatch();
	void RemoveMatch(node*parent,node*match,bool left);
	void RemoveNodePrivate(int key ,node*ptr);
	int heightt(node* node);
	bool isBalanced(node* root);
public:

	BST();
	node*CreateLeaf(int key);
	void AddLeaf(int key);
	void PrintInOrder();
	node* ReturnNode(int key);
	int ReturnRootKey();
	void printChildren(int k);
	int findSmall();
	void RemoveNode(int key);
	int Size();
	int height();
	bool Balanced();
};