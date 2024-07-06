#include<iostream>
#include<cstdlib>
#include "BST.h";

using namespace std;

int main (){
	 
	BST mytree;

	mytree.AddLeaf(10);
	mytree.AddLeaf(8);
	mytree.AddLeaf(9);
	mytree.AddLeaf(7);
	mytree.AddLeaf(12);
	mytree.AddLeaf(11);
	mytree.AddLeaf(15);
	cout<<"---------------------------------------\n";
	cout<<"THE TREE : \n";
	mytree.PrintInOrder();cout<<endl;
	cout<<"Number of Elements in the TREE is : ";
	cout<<mytree.Size()<<endl;
	cout<<"HEIGHT OF the TREE is : ";
	cout<<mytree.height();
	cout<<"\n---------------------------------------\n";

	mytree.printChildren(22);
	mytree.printChildren(mytree.ReturnRootKey());
	mytree.printChildren(12);

	cout<<" The Smallest Element in the Tree is : "<<mytree.findSmall()<<endl;

	cout<<" test for REMOVING ELEMENTS FROM the Tree  : "<<endl;
	  mytree.RemoveNode(12);
	  mytree.RemoveNode(10);
	  //mytree.AddLeaf(20);
	  
	 cout<<"---------------------------------------\n";
	cout<<"THE TREE : \n";
	mytree.PrintInOrder();cout<<endl;
	cout<<"Number of Elements in the TREE is : ";
	cout<<mytree.Size()<<endl;
	cout<<"HEIGHT OF the TREE is : ";
	cout<<mytree.height()<<endl;
	if(mytree.Balanced()) cout<<" the tree is Balanced \n";
	else cout<<" the tree is NOT Balanced \n";
	cout<<"\n---------------------------------------\n";
	cin.get();
	return 0;

	}
