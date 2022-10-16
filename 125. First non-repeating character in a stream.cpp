// https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1

#include <bits/stdc++.h>

using namespace std;

class Node {
 public:
  char c;
  Node *prev;
  Node *next;
  Node(char ch = '\n') {
    this->c = ch;
    this->next = this->prev = nullptr;
  }
  ~Node() {
    this->c = '\n';
    this->next = this->prev = nullptr;
  }
};

void addToTail(Node *&tail, char value) {
  auto newNode = new Node(value);
  tail->next = newNode;
  newNode->prev = tail;
  tail = tail->next;
}

void removeNode(Node *node, Node *&tail) {
  // node previously deleted
  if (!node) return;

  node->prev->next = node->next;

  if (node->next)
    node->next->prev = node->prev;
  else
    tail = tail->prev;

  delete node;
}

string FirstNonRepeating(string A) {
  // pair<int = freq, Node * = DLL node>
  vector<pair<int, Node *>> mp(26);
  Node *head = new Node(), *tail = head;
  for (auto &ch : A) {
    int index = ch - 'a';
    int &freq = mp[index].first;
    auto &current_node = mp[index].second;

    if (!freq) {
      addToTail(tail, ch);
      current_node = tail;
      freq = 1;
    } else {
      removeNode(current_node, tail);
      current_node = nullptr;
    }

    if (head->next == nullptr)
      ch = '#';
    else
      ch = head->next->c;
  }

  return A;
}

// Approach 2 - queue based approach
string FirstNonRepeating(string A) {
  queue<char> q;
  // store per charater frequency
  vector<int> count(26);

  for (auto &ch : A) {
    int index = ch - 'a';
    q.push(ch);
    count[index]++;

    while (q.empty() != true) {
      if (count[q.front() - 'a'] > 1)
        q.pop();
      else {
        ch = q.front();
        break;
      }
    }
    if (q.empty()) ch = '#';
  }

  return A;
}