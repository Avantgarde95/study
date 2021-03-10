#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <memory>

class Node {
public:
    Node(const std::string& name): m_name(name) {
        // Do nothing.
    }

    void print(int level = 0) {
        printThis(level);
        printChilds(level);
    }

    void addChild(const std::shared_ptr<Node>& child) {
        m_childs.push_back(child);
    }

private:
    void printThis(int level) {
        std::stringstream ss;

        for (int i = 0; i < level - 1; i++) {
            ss << "   ";
        }

        if (level > 0) {
            ss << "|- ";
        }

        ss << m_name << "\n";
        std::cout << ss.str();
    }

    void printChilds(int level) {
        for (auto child: m_childs) {
            child->print(level + 1);
        }
    }

private:
    std::string m_name;
    std::vector<std::shared_ptr<Node>> m_childs;
};

int main() {
    /*
     * Tree 1: 0 - 1 - 2
     *             |
     *             3 - 4 - 5
     *                 |
     * Tree 2: 6 ------+
     *                 |
     *                 7 - 8
     *                 |
     *                 9 - 10 - 11
     */

    std::vector<std::shared_ptr<Node>> nodes;

    for (int i = 0; i <= 11; i++) {
        nodes.push_back(std::make_shared<Node>(std::to_string(i)));
    }

    // Tree 1.
    nodes[0]->addChild(nodes[1]);
    nodes[0]->addChild(nodes[3]);
    nodes[1]->addChild(nodes[2]);
    nodes[3]->addChild(nodes[4]);
    nodes[4]->addChild(nodes[5]);

    // Tree 2.
    nodes[6]->addChild(nodes[4]);
    nodes[6]->addChild(nodes[7]);
    nodes[6]->addChild(nodes[9]);
    nodes[7]->addChild(nodes[8]);
    nodes[9]->addChild(nodes[10]);
    nodes[10]->addChild(nodes[11]);

    nodes[0]->print();
    nodes[6]->print();

    return 0;
}
