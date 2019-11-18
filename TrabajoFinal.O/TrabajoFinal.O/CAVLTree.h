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
	void find(Comparable val, vector<T>& v) {
		find(root, val, v);
	}
	void findX(Comparable val, vector<T>& v) {
		findX(root, val, v);
	}
	void findMa(Comparable val, vector<T>& v) {
		findMa(root, val, v);
	}
	void findMi(Comparable val, vector<T>& v) {
		findMin(root, val, v);
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
	//AGREGAR ELEMTOS CON EL MISMO NOMBRE
	void find(Node* node, Comparable val, vector<T>& v) {
		if (node == nullptr) {
			return;
		}
		else if (val == key(node->elem)) {
			v.push_back(node->elem);
			find(node->left, val, v);
			find(node->right, val, v);
		}
		else if (val < key(node->elem)) {
			find(node->left, val, v);
		}
		else {
			find(node->right, val, v);
		}
	}
	//AGREGAR ELEMENTOS POR PRIMERA LETRA
	void findX(Node* node, Comparable val, vector<T>& v) {
		if (node == nullptr) {
			return;
		}
		else if (val[0] == key(node->elem)[0]) {
			v.push_back(node->elem);
			findX(node->left, val, v);
			findX(node->right, val, v);
		}
		else if (val[0] < key(node->elem)[0]) {
			findX(node->left, val, v);
		}
		else {
			findX(node->right, val, v);
		}
	}
	//AGREGAR MAYORES ELEMENTOS 
	void findMa(Node* node, Comparable val, vector<T>& v) {
		if (node == nullptr) {
			return;
		}
		else if (val == key(node->elem)) {
			findMa(node->right, val, v);
		}
		else if (val < key(node->elem)) {
			v.push_back(node->elem);
			findMa(node->left, val, v);
			findMa(node->right, val, v);
		}
		else {
			findMa(node->right, val, v);
		}
	}
	//AGREGAR MENORES ELEMENTOS
	void findMin(Node* node, Comparable val, vector<T>& v) {
		if (node == nullptr) {
			return;
		}
		else if (val == key(node->elem)) {
			findMin(node->left, val, v);
		}
		else if (val < key(node->elem)) {
			findMin(node->left, val, v);
		}
		else {
			v.push_back(node->elem);
			findMin(node->left, val, v);
			findMin(node->right, val, v);
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