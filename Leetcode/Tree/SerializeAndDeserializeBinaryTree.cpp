#include "SerializeAndDeserializeBinaryTree.h"
#include <iostream>

void Codec::FillVector(TreeNode* node, vector<int>& flatTree, int& currentIndex)
{
	flatTree.push_back(node->val);
	flatTree.push_back(-1);			// left
	flatTree.push_back(-1);			// right
	int nodeIndex = currentIndex;
	int leftNodeIndex = currentIndex + 1;
	int rightNodeIndex = currentIndex + 2;
	currentIndex += 3;

	// currentIndex is the index of our current node in the vector

	if (node->left != nullptr)
	{
		flatTree[leftNodeIndex] = currentIndex;
		FillVector(node->left, flatTree, currentIndex);
	}

	if (node->right != nullptr)
	{
		flatTree[rightNodeIndex] = currentIndex;
		FillVector(node->right, flatTree, currentIndex);
	}
}

string Codec::serialize(TreeNode* root)
{
	vector<int> flatTree;
	int currentIndex = 0;

	if (root != nullptr)
	{
		FillVector(root, flatTree, currentIndex);

		//cout << "flattree : \n";
		//for (auto el : flatTree)
		//{
		//	cout << el << '\n';
		//}

		const char* charArray = reinterpret_cast<const char*>(flatTree.data());
		int flatTreeSize = flatTree.size();
		int charArraySize = flatTree.size() * sizeof(int) / sizeof(char);
		return string(charArray, charArraySize);
	}

	return string();		// else return empty string
}

TreeNode* Codec::ReconstructTree(vector<int>& flatTree, int currentIndex)
{
	if (currentIndex > -1)
	{
		TreeNode* node = new TreeNode(flatTree[currentIndex]);
		cout << "node with val : " << flatTree[currentIndex] << '\n';
		node->left = ReconstructTree(flatTree, flatTree[currentIndex + 1]);
		node->right = ReconstructTree(flatTree, flatTree[currentIndex + 2]);
		return node;
	}
	
	return nullptr;
}

TreeNode* Codec::deserialize(string data)
{
	if (data.size() > 0)
	{
		const int* myArray = reinterpret_cast<const int*>(data.data());
		vector<int> vec;
		vec.assign(myArray, myArray + data.size() * sizeof(char) / sizeof(int));

		return ReconstructTree(vec, 0);
	}

	return nullptr;
}

bool Codec::TestSolution()
{
	bool succeeded = false;
	TreeNode* root = new TreeNode(4);
	TreeNode* leftChild = new TreeNode(1);
	TreeNode* rightChild = new TreeNode(2);
	TreeNode* leftChildChild = new TreeNode(5);

	root->left = leftChild;
	root->right = rightChild;
	leftChild->left = leftChildChild;

	string result = serialize(root);

	cout << result << '\n';

	TreeNode* deserializedRoot = deserialize(result);

	cout << "Deserialized Tree" << '\n';
	cout << deserializedRoot->val << '\n';
	cout << deserializedRoot->left->val << '\n';
	cout << deserializedRoot->right->val << '\n';
	cout << deserializedRoot->left->left->val << '\n';

	succeeded = (deserializedRoot->val == 4 && deserializedRoot->left->val == 1 && deserializedRoot->right->val == 2 && deserializedRoot->left->left->val == 5);

	delete root;
	delete leftChild;
	delete rightChild;
	delete leftChildChild;
	return succeeded;
}