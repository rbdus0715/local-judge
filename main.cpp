#include <iostream>
#include <list>
#include <string>
using namespace std;

//
enum class Side {LEFT, RIGHT};
struct Node {
	int value;
	int depth;
	Node* parent, * left, * right;

	list<Node*>::iterator pos;
	Node(int value, Node* parent) :value(value), parent(parent) {
		left = right = nullptr;
		depth = 0;
	}
};

class BT {
public:
	BT() : root_node(nullptr) {}
	int size() { return static_cast<int>(node_list.size()); }
	bool empty() { return size() == 0; }
	Node* root() { return root_node; }
	Node* find(int value) {
		if (empty()) return nullptr;
		auto it = node_list.begin();
		while (it != node_list.end()) {
			if ((*it)->value == value) return *it;
			it++;
		}
		return nullptr;
	}
	void insert(Node* pos, int value, Side side) {
		if (empty()) {
			Node* nn = new Node(1, nullptr);
			root_node = nn;
			node_list.push_back(nn);
			nn->pos = node_list.begin();
			nn->depth = 0;
			return;
		}
		if (pos == nullptr) {
			cout << "-1\n";
			return;
		}
		if (side == Side::LEFT && pos->left != nullptr) {
			cout << "-1\n";
			return;
		}
		if (side == Side::RIGHT && pos->right != nullptr) {
			cout << "-1\n";
			return;
		}

		Node* nn = new Node(value, pos);
		if (side == Side::LEFT) pos->left = nn;
		else pos->right = nn;
		node_list.push_back(nn);
		nn->pos = --node_list.end();
		nn->depth = pos->depth + 1;
	}
	void erase(Node* pos) {
		if (pos == root()) {
			for (auto i : node_list) delete i;
			root_node = nullptr;
			node_list.clear();
			return;
		}
		if (pos->left != nullptr) erase(pos->left);
		if (pos->right != nullptr) erase(pos->right);

		if (pos->parent->left == pos) pos->parent->left = nullptr;
		else pos->parent->right = nullptr;
		node_list.erase(pos->pos);
		delete pos;
	}
	void subtract(Node* pos) {
		if (pos == root()) {
			int sum = 0;
			if (pos->left != nullptr) sum += pos->left->value;
			if (pos->right != nullptr) sum += pos->right->value;
			cout << sum << "\n";
			return;
		}
		int parent_sum = pos->parent->value;
		int sum = 0;
		if (pos->left != nullptr) sum += pos->left->value;
		if (pos->right != nullptr) sum += pos->right->value;
		cout << sum - parent_sum << "\n";
	}
	bool flag = false;
	int sum = 0;
	void inorder(int x)
	{
		sum = 0;
		flag = false;
		inorder(root_node, x);

		if (!flag) cout << "-1\n";
		else cout << "\n";
	}
	void inorder(Node* pos, int x)
	{

		if (pos->left != nullptr && !flag)
			inorder(pos->left, x);

		sum += pos->value;
		if (sum > x && !flag)
		{
			flag = true;
			cout << pos->value << " ";
		}

		if (pos->right != nullptr && !flag)
			inorder(pos->right, x);
	}
	void lca(Node* x, Node* y) {
		Node* cur_x = x;
		Node* cur_y = y;
		while (cur_x->depth > cur_y->depth) {
			cur_x = cur_x->parent;
		}
		while (cur_x->depth < cur_y->depth) {
			cur_y = cur_y->parent;
		}
		while (cur_x->value != cur_y->value) {
			cur_x = cur_x->parent;
			cur_y = cur_y->parent;
		}
		cout << cur_x->value << "\n";
	}
	bool is = false;
private:
	Node* root_node;
	list<Node*> node_list;
};


int main() {
	BT tree;
	int N; cin >> N; while (N--) {
		string s; cin >> s;
		if (s == "Insert") {
			int x, v; cin >> x >> v;
			Node* pos = tree.find(x);
			string side; cin >> side;
			if (side == "left")
				tree.insert(pos, v, Side::LEFT);
			else
				tree.insert(pos, v, Side::RIGHT);
		}
		else if (s == "Erase") {
			int v; cin >> v;
			Node* pos = tree.find(v);
			tree.erase(pos);
		}
		else if (s == "Find") {
			int x; cin >> x;
			Node* pos = tree.find(x);
			if (pos == nullptr) cout << "-1\n";
			else cout << "1\n";
		}
		else if (s == "Subtract") {
			int x; cin >> x;
			Node* pos = tree.find(x);
			tree.subtract(pos);
		}
		else if (s == "Order_sum") {
			int x; cin >> x;
			tree.inorder(x);
		}
		else if (s == "LCA") {
			int x, y; cin >> x >> y;
			tree.lca(tree.find(x), tree.find(y));
		}
	}
}

/*
11
Insert 1 1
left Insert 1 2
left Insert 1 3
right Insert 2 4
left Insert 2 5
right Insert 3 6
left Insert 3 7
right Order_travel 6
*/

