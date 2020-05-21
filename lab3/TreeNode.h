#pragma once
class TreeNode {
private:
	int value;
	TreeNode* right;
	TreeNode* left;
public:
	TreeNode(int _value);
	TreeNode();
	~TreeNode();
	int getValue() const;
	bool containsRight() const;
	bool containsLeft() const;
	TreeNode* getRight() const;
	TreeNode* getLeft() const;
	void setLeft(int value);
	void setRight(int value);
};

