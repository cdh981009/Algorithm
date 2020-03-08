#include <iostream>
#include <string>
using namespace std;

#define FOR(i, a, b) for (int (i) = (a); (i) < (b); ++(i))
#define FOR_(i, a, b) for (int (i) = (a); (i) <= (b); ++(i))

struct Node {
    Node* prev;
    Node* next;
    int item;
    Node(): prev(nullptr), next(nullptr), item(0) {}
};

class Deque {
private:
    Node* head;
    Node* tail;
    size_t cnt;
public:
    Deque(): head(new Node), tail(new Node), cnt(0) {
        head->next = tail;
        tail->prev = head;
    }
    size_t size() {return cnt;}
    bool empty() {return cnt == 0;}
    int front() {
        return (empty() ? -1 : head->next->item);
    }
    int back() {
        return (empty() ? -1 : tail->prev->item);
    }
    void push_front(int val) {
        cnt++;
        Node* newNode = new Node;
        newNode->item = val;
        newNode->prev = head;
        newNode->next = head->next;
        head->next->prev = newNode;
        head->next = newNode; 
    }
    void push_back(int val) {
        cnt++;
        Node* newNode = new Node;
        newNode->item = val;
        newNode->prev = tail->prev;
        newNode->next = tail;
        tail->prev->next = newNode;
        tail->prev = newNode; 
    }
    int pop_front() {
        if (empty()) return -1;
        cnt--;
        Node* fNode = head->next;
        int res = fNode->item;
        head->next = fNode->next;
        fNode->next->prev = head;
        delete fNode;
        return res;
    }
    int pop_back() {
        if (empty()) return -1;
        cnt--;
        Node* tNode = tail->prev;
        int res = tNode->item;
        tail->prev = tNode->prev;
        tNode->prev->next = tail;
        delete tNode;
        return res;
    }
    ~Deque() {
        while (!empty())
            pop_front();
        delete head;
        delete tail;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;
    Deque deq;
    while (n--) {
        string q; cin >> q;
        if (q == "push_front") {
            int val; cin >> val;
            deq.push_front(val);
        } else if (q == "push_back") {
            int val; cin >> val;
            deq.push_back(val);
        } else if (q == "pop_front") {
            cout << deq.pop_front() << "\n";
        } else if (q == "pop_back") {
            cout << deq.pop_back() << "\n";
        } else if (q == "size") {
            cout << deq.size() << "\n";
        } else if (q == "empty") {
            cout << deq.empty() << "\n";
        } else if (q == "front") {
            cout << deq.front() << "\n";
        } else if (q == "back") {
            cout << deq.back() << "\n";
        }
    }
    return 0;
}