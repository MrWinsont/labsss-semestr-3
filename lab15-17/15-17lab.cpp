#include <iostream>
#include <string>
#include <stack>

struct Node {
    Node* m_left = nullptr;
    Node* m_right = nullptr;
    int m_value;
    Node(int value) {
        m_value = value;
    }
};
class Tree
{
private:
    Node* m_root;
public:
    
    Tree(int value) {
        m_root = new Node(value);
    }
    Tree() {
        m_root = nullptr;
    }
    
    Node* GetRoot() {
        return m_root;
    }
    int getRootValue() {
        return m_root->m_value;
    }

    void insert(Node* node, int value) {
        if (m_root == nullptr) {
            m_root = new Node(value);
            return;
        }
        if (node->m_value == NULL) {
            node->m_value = value;
            
        }
        if (value < node->m_value) {
            if (node->m_left == nullptr) {
                node->m_left = new Node(value);
            }
            else {
                insert(node->m_left, value);
            }
        }
        else if (value >= node->m_value) {
            if (node->m_right == nullptr) {
                node->m_right = new Node(value);
            }
            else {
                insert(node->m_right, value);
            }
        }
    }

    Node* Search(Node* node,int value) {
        if (node == nullptr) {
            return node;
        }
        if (node->m_value == value) {
            return node;
        }
        else if (value < node->m_value) {
            return Search(node->m_left, value);
        }
        else {
            return Search(node->m_right, value);
        }
    }


    Node* GetMin(Node* node) {
        if (node == nullptr) {
            return node;
        }
        else if (node->m_left == nullptr) {
            return node;
        }
        else if (node->m_left != nullptr) {
            return GetMin(node->m_left);
        }
    }

    Node* GetMax(Node* node) {
        if (node == nullptr) {
            return node;
        }
        else if (node->m_right == nullptr) {
            return node;
        }
        else if (node->m_right != nullptr) {
            return GetMax(node->m_right);
        }
    }
    

   Node* Delete(Node* node, int value) {
        if (node == nullptr) {
            return nullptr;
        }
        else if (value < node->m_value) {
            node->m_left = Delete(node->m_left, value);
        }
        else if (value > node->m_value) {
            node->m_right = Delete(node->m_right, value);
        }
        else {
            if ((node->m_left == nullptr) || (node->m_right == nullptr)) {
                if (node->m_left == nullptr) {
                    node = node->m_right;
                }
                else {
                    
                    node = node->m_left;
                    
                }
            }

            else {
                
                node->m_value = GetMin(node->m_right)->m_value;
                node->m_right = Delete(node->m_right, GetMin(node->m_right)->m_value);
                
            }
            
        }
        return node;
   }

    void SetTreeByLine(const std::string& str) {
        std::string tmp = "";
            for (int i = 0; i < str.size(); ++i) {
                if (str[i] >= 48 && str[i] <= 57) {
                    tmp += str[i];
                }
                else if (str[i] == '-' && str[i + 1] >= 48 && str[i + 1] <= 57) {
                    tmp += str[i];
                }
                else {
                    if (tmp.length() != 0) {
                        insert(m_root, std::stoi(tmp));
                        tmp = "";
                    }
                }
            }
    }

    void PrintTreeByLine(Node* node) {
        if (node == nullptr) {
            return;
        }
        std::cout << node->m_value;
        if (node->m_left != nullptr || node->m_right != nullptr) {
            std::cout << " (";
        }
        PrintTreeByLine(node->m_left);
        if (node->m_left != nullptr || node->m_right != nullptr) {
            std::cout << ", ";
        }
        PrintTreeByLine(node->m_right);
        if (node->m_left != nullptr || node->m_right != nullptr) {
            std::cout << ")";
        }
    }

    //lab 15 Обходы
    void straightTraversal(Node* node) {
        if (node == nullptr) {
            return;
        }
        std::cout << node->m_value << " ";
        straightTraversal(node->m_left);
        straightTraversal(node->m_right);
    }

    void backTraversal(Node* node) {
        if (node == nullptr) {
            return;
        }
        backTraversal(node->m_left);
        std::cout << node->m_value << " ";
        backTraversal(node->m_right);
    }

    void terminalTraversal(Node* node) {
        if (node == nullptr) {
            return;
        }
        terminalTraversal(node->m_left);
        terminalTraversal(node->m_right);
        std::cout << node->m_value << " ";
    }

    //lab 16
    void stackStraightTraversal(Node* node) {
        std::stack<Node*> Stack;
        while (!Stack.empty() || node != nullptr) {
            if (!Stack.empty()) {
                node = Stack.top();
                Stack.pop();
            }
            while (node != nullptr) {
                std::cout << node->m_value << " ";
                if (node->m_right != nullptr) {
                    Stack.push(node->m_right);
                }
                node = node->m_left;
            }
        }
    }

   ~Tree() {
       delete m_root;
   }
};
int main()
{
    Tree tree;
    std::string a = "8(3 (1,6(4,7)),10(,14(13,))";
    tree.SetTreeByLine(a);

    bool flag = true;
    while (flag) {
        std::cout << "1.Insert an element to binary tree" << "\n";
        std::cout << "2.Delete an element from binary tree" << "\n";
        std::cout << "3.Get the root of binary tree" << "\n";
        std::cout << "4.Straight Traversal" << "\n";
        std::cout << "5.Back Traversal" << "\n";
        std::cout << "6.Terminal Traversal" << "\n";
        std::cout << "7.exit" << "\n";
        int k;
        std::cin >> k;
        switch (k) 
        {
        case(1):
            int value1;
            std::cout << "enter an element - ";
            std::cin >> value1;
            std::cout << "\n";
            tree.insert(tree.GetRoot(), value1);
            break;
        case(2):
            int value2;
            std::cout << "Enter an element which you want to delete - ";
            std::cin >> value2;
            std::cout << "\n";
            if (tree.Search(tree.GetRoot(), value2) == nullptr) {
                std::cout << "This element already not in tree" << "\n";
                break;
            }
            else {
                tree.Delete(tree.GetRoot(), value2);
            }
            break;
        case(3):
            std::cout << "The top of binary tree " << tree.getRootValue() << "\n";
            break;
        case(4):
            tree.straightTraversal(tree.GetRoot());
            std::cout << "\n";
            break;
        case(5):
            tree.backTraversal(tree.GetRoot());
            std::cout << "\n";
            break;
        case(6):
            tree.terminalTraversal(tree.GetRoot());
            std::cout << "\n";
            break;
        case(7):
            flag = false;
            break;
        }


    }

    if (!flag) {
        tree.PrintTreeByLine(tree.GetRoot());
    }
    std::cout << "\n";
    tree.stackStraightTraversal(tree.GetRoot());
    
    
   
}
