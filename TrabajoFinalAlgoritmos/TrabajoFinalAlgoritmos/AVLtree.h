/// HOLA PRUEBA
#pragma once
#include <functional>
#include <algorithm>
using namespace std;

#define max(a, b) (a > b ? a : b)

template <typename E, typename Comparable = E, E NONE = 0>
class AVLtree {
	struct Node {
		E data;
		Node* left;
		Node* right;
		int h;
		int n;
		Node(E data = NONE) : data(data), left(nullptr), right(nullptr), h(0), n(1) {}
	};
	Node* root;
	int len;
	function<Comparable(E)> key;
public:
	AVLtree(function<Comparable(E)> key = [](E a) { return a; })
		: root(nullptr), len(0), key(key) {}
	~AVLtree() { destroy(root); }
	E find(Comparable val) {
		return find(root, val);
	}
	int height() { return Node::height(root); }
	int size() { return len; }
	void add(E elem) {
		add(root, elem);
		++len;
	}
	void search(E elem) {}
	void remove(E elem) {}
private:
	E find(Node* node, Comparable val) {
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
		return node;
	}
	Node* rotRight(Node* node) {
		Node* aux = node->left;
		node->left = aux->right;
		aux->right = node;
		update(aux->right);
		update(aux;)
		return node;
	}
	Node* balance(Node* node) {
		int hl = height(node->left);
		int hr = height(node->right);
		if (hl - hr > 1) {
			if (height(node->left->right) > height(node->left->left)) {
				node->left = rotLeft(node->left);
			}
			node = rotRight(node);
		} else if (hl - hr < -1) {
			if (height(node->right->left) > height(node->right->right)) {
				node->right = rotRight(node->right);
			}
			node = rotLeft(node);
		} else {
			update(node);
		}
		return node;
	}
	Node* add(Node* node, E elem) {
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
	void destroy(Node* root) {
		if (root != nullptr) {
			destroy(root->left);
			destroy(root->right);
			delete root;
		}
	}
};