#pragma once
#include <functional>
using namespace std;

#define max(a, b) (a > b ? a : b)

template <typename T, typename Comparable = T, T NONE = 0>
class CAVLtree {
	struct Node {
		Node* left;
		Node* right;
		int n;
		int h;
		T elem;
		Node(T elem = NONE) :elem(elem), left(nullptr), right(nullptr), n(1), h(0) {}
	};
	Node* root;
	int len;
	function<Comparable(T)> key;
public:
	CAVLtree(function<Comparable(T)> key = [](T a) {return a; })
		:root(nullptr), key(key), len(0) {}
	~CAVLtree() {
		destroy(root);
	}
	void add(T elem) {
		root = add(root, elem);
		++len;
	}
	T find(Comparable val) {
		return find(root, val);
	}
	void inorder(function<void(T)> proc) {
		inOrder(root, proc);
	}
	int size() { return this->len; }
private:
	Node* add(Node* node, T elem) {
		if (node == nullptr) {
			node = new Node(elem);
		}
		else {
			if (key(elem) < key(node->elem)) {
				node->left = add(node->left, elem);
			}
			else {
				node->right = add(node->right, elem);
			}
			node = balance(node);
		}
		return node;
	}
	T find(Node* node, Comparable val) {
		if (node == nullptr) {
			return NONE;
		}
		else if (val == key(node->elem)) {

			return node->elem;
		}
		else if (val < key(node->elem)) {
			return find(node->left, val);
		}
		else {
			return find(node->right, val);
		}
	}
	void inOrder(Node* node, function<void(T)> proc) {
		if (node != nullptr) {
			inOrder(node->left, proc);
			proc(node->elem);
			inOrder(node->right, proc);
		}
	}
	int height(Node* node) { return node == nullptr ? -1 : node->h; }
	int lenght(Node* node) { return node == nullptr ? 0 : node->n; }
	void update(Node* node) {
		node->h = 1 + max(height(node->left), height(node->right));
		node->n = 1 + lenght(node->left) + lenght(node->right);
	}
	Node* rotLeft(Node* node) {
		Node* aux = node->right;
		node->right = aux->left;
		aux->left = node;
		update(aux->left);
		update(aux);
		return aux;
	}
	Node* rotRight(Node* node) {
		Node* aux = node->left;
		node->left = aux->right;
		aux->right = node;
		update(aux->right);
		update(aux);
		return aux;
	}
	Node* balance(Node* node) {
		int hl = height(node->left);
		int hr = height(node->right);
		if (hl - hr > 1) {
			if (height(node->left->right) > height(node->left->left)) {
				node->left = rotLeft(node->left);
			}
			node = rotRight(node);
		}
		else if (hl - hr < -1) {
			if (height(node->right->left) > height(node->right->right)) {
				node->right = rotRight(node->right);
			}
			node = rotLeft(node);
		}
		else {
			update(node);
		}
		return node;
	}
	void destroy(Node* node) {
		if (node != nullptr) {
			destroy(node->left);
			destroy(node->right);
			delete node;
		}
	}
};