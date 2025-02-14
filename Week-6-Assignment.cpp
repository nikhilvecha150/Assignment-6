#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

// creating the structure require according to the problem
struct Hu_ff_N_ode {
    char symbol;
    int frequency;
    Hu_ff_N_ode *leftChild;
    Hu_ff_N_ode *rightChild;

    Hu_ff_N_ode(char ch, int freq) {
        symbol = ch;
        frequency = freq;
        leftChild = rightChild = nullptr;
    }
};

// used in order to have a side by side Comparison
struct Fr_e_que_ncy_C_omparator {
    bool operator()(Hu_ff_N_ode* left, Hu_ff_N_ode* right) {
        return left->frequency > right->frequency;
    }
};

// used to make the Preorder Traversal
void pri_n_t_H_u_ffma_n_Codes(Hu_ff_N_ode* currentNode, string code) {
    if (!currentNode) return;


    if (!currentNode->leftChild && !currentNode->rightChild) {
        cout << currentNode->symbol << ": " << code << endl;
    }

    pri_n_t_H_u_ffma_n_Codes(currentNode->leftChild, code + "0");
    pri_n_t_H_u_ffma_n_Codes(currentNode->rightChild, code + "1");
}

// Function to build the Huffman Tree
void con_struct_H_Tr_ee(const string& charSequence, const vector<int>& frequencies) {
    priority_queue<Hu_ff_N_ode*, vector<Hu_ff_N_ode*>, Fr_e_que_ncy_C_omparator> priorityQueue;

    // Pushing all user provided characters its frequencies to the priority queue
    for (size_t i = 0; i < charSequence.size(); i++) {
        priorityQueue.push(new Hu_ff_N_ode(charSequence[i], frequencies[i]));
    }


    while (priorityQueue.size() > 1) {
        Hu_ff_N_ode* leftNode = priorityQueue.top(); priorityQueue.pop();
        Hu_ff_N_ode* rightNode = priorityQueue.top(); priorityQueue.pop();

        Hu_ff_N_ode* combinedNode = new Hu_ff_N_ode('$', leftNode->frequency + rightNode->frequency);
        combinedNode->leftChild = leftNode;
        combinedNode->rightChild = rightNode;

        priorityQueue.push(combinedNode);
    }

    // Displaying the traversal
    pri_n_t_H_u_ffma_n_Codes(priorityQueue.top(), "");
}

int main() {
    string charSequence;
    cout << "Enter the characters as a single string (no spaces): ";
    cin >> charSequence;

    int numCharacters = charSequence.length();
    vector<int> frequencies(numCharacters);

    cout << "Enter the corresponding frequencies: ";
    for (int i = 0; i < numCharacters; i++) {
        cin >> frequencies[i];
    }

    con_struct_H_Tr_ee(charSequence, frequencies);

    return 0;
}
