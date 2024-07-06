#include<iostream>
#include<cstdlib>
#include "BST.h"

using namespace std;


BST::BST(){
	  root=nullptr;
	  count=0;
	}

BST::node* BST::CreateLeaf(int key){
	  
	 node* n= new node();
	 n->data=key;
	 n->left=n->right=nullptr;
	 return n;
	}

void BST::AddLeafPrivate(int key,node*ptr){

	if( ptr==nullptr){
		  root=CreateLeaf(key);
		  count++;
		}
	else{
		if( key<ptr->data)
			{
			  ptr->left==nullptr ?
				  ptr->left=CreateLeaf(key),count++:
			      AddLeafPrivate(key,ptr->left);
			}
		else{
			  ptr->right==nullptr ?
				  ptr->right=CreateLeaf(key),count++:
			      AddLeafPrivate(key,ptr->right);
				 
			}
		}
	}


void BST::AddLeaf(int key){

	  AddLeafPrivate(key,root);

		}

int BST::Size(){
	  return count;
	}

void BST::PrintInOrder(){

	PrintInOrderPrivate(root);

	}

void BST::PrintInOrderPrivate(node*ptr){
	 if(ptr!= nullptr){
		 PrintInOrderPrivate(ptr->left);

		 cout<< ptr->data<<" ";

		 PrintInOrderPrivate(ptr->right);

		 }
	}
 
BST::node* BST::ReturnNode( int key)
	{
	  return ReturnNodePrivate(key ,root);

	}

BST::node* BST::ReturnNodePrivate( int key , node*ptr)
	{
	  
	   if( ptr!= nullptr){
		   if(ptr->data== key)
			   {
			      return ptr;
			   }
		   else{ 
			   ptr->data>key?
				   ReturnNodePrivate(key,ptr->left):
			       ReturnNodePrivate(key,ptr->right);
			   }
		   }

	   else{
		     return nullptr;
		   }

	}

int BST:: ReturnRootKey(){
	return root->data;
	}

void BST:: printChildren(int key){

	  node* ptr = ReturnNode(key);

	  if(ptr!=nullptr){
		  cout<<"      -------------------       \n";
		  cout<<" Parent Node is : "<< key <<endl;
		   
		  ptr->left==nullptr?
			  cout<<" Left Child is Null "<<endl:
		      cout<<" Left Child is "<<ptr->left->data<<endl;
		   ptr->right==nullptr?
			  cout<<" Right Child is Null "<<endl:
		      cout<<" Right Child is "<<ptr->right->data<<endl;

			   cout<<"      -------------------       \n";
		  }

	  else{

		  cout<< key << " Not found in tree \n";
		  }
	}

int BST::findSmall(){
	 return FindSmallPrivate(root);
	}

int BST:: FindSmallPrivate(node*ptr){
	 if(ptr==nullptr){
		  return -999999;
		 }
	 else{
		 if(ptr->left==nullptr) return ptr->data;
		 else{ return FindSmallPrivate(ptr->left);}
		 }
	}

void BST::RemoveMatch(node*parent ,node*match ,bool left){
	    
	if(match->left==nullptr && match ->right==nullptr)
		{
		   if(left){
			   parent->left=nullptr;
			   }
		   else {
			      parent->right=nullptr;
			      
			   }
		   delete match; count--;
		}
	else if(match->left!=nullptr && match ->right==nullptr){
		  
		   if(left){
			   parent->left=match->left;
			   match->left=nullptr;

			   }
		   else {
			   parent->right= match->left;
			    match->left=nullptr;
			   }
		   delete match; count--;
		}
	else if(match->left==nullptr && match ->right!=nullptr){
		 
		    if(left){
			   parent->left=match->right;
			   match->right=nullptr;

			   }
		   else {
			   parent->right= match->right;
			    match->right=nullptr;
			   }
		   delete match; count--;
		}
		
	else{
		   int small=FindSmallPrivate(match->right);
		   RemoveNode(small);
		   match->data=small;
		}
	}
 
void BST::RemoveRootMatch(){
	if( root->left==nullptr && root->right==nullptr){
		  delete root; count--;
		}
	else if(root->left!=nullptr && root->right==nullptr) {
		  
		  node*temp=root->left;
		  root->left=nullptr;
		  delete root;
		  root=temp;
		  count--;

		}
	else if(root->left==nullptr && root->right!=nullptr) {
		  
		  node*temp=root->right;
		  root->right=nullptr;
		  delete root;
		  root=temp;
		  count--;

		}
	else{
		int samll=FindSmallPrivate(root->right);
		RemoveNodePrivate(samll,root->right);
		root->data=samll;

		}
	}

void BST::RemoveNodePrivate(int key ,node*ptr)
	{ if(root != nullptr)
	  {
	  if( ptr->data== key)
			 {
		        RemoveRootMatch();
		     }
	     else{
			 if( key< ptr->data && ptr->left!=nullptr){
				 key ==ptr->left->data ?
					 RemoveMatch(ptr,ptr->left,true):
				     RemoveNodePrivate(key,ptr->left);

			   }
			 else  if( key> ptr->data && ptr->right!=nullptr){
				 key ==ptr->right->data ?
					 RemoveMatch(ptr,ptr->right,false):
				     RemoveNodePrivate(key,ptr->right);

			   }

			 else{
				     cout<<" The Key "<<key<<" was Not Found \n";
				 }

		   }
	  }
	else{ 
		   cout<<" THE TREE IS EMPTY \n";
		}
	}

void BST::RemoveNode(int k){
	RemoveNodePrivate(k,root);
	}

int BST::height(){
	 return heightt(root);
	}

int BST::heightt(node* node) {
  
  if (node == nullptr) {
    return 0;
  }

  
  return 1 + std::max(heightt(node->left), heightt(node->right));
}

bool BST::Balanced(){
	  return isBalanced(root);
	}

bool BST::isBalanced(node* root) {
  // Base cases: empty tree or single node
  if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
    return true;
  }

  // Get the heights of left and right subtrees
  int lh = heightt(root->left);
  int rh = heightt(root->right);

  // Check if the difference in heights is greater than 1
  if (abs(lh - rh) > 1) {
    return false;
  }

  // Recursively check if left and right subtrees are balanced
  return isBalanced(root->left) && isBalanced(root->right);
}