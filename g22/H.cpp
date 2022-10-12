#include <iostream>
#include <array>
#include <vector>
#include <cassert>

constexpr int k = 26;

template<int alpha>
class EerQueue
{
    static_assert(alpha > 0);
public:
    struct Node
    {
        std::array<Node*, alpha> next;
        Node* pre, * fail;
        int len;
        int rightmost_occurence, second_rightmost_occurence;
        int fail_cnt;
        Node() : pre(nullptr), fail(nullptr), len(0), next{}, rightmost_occurence(-1), second_rightmost_occurence(-1), fail_cnt(0) {}
        void updateOccurence(int occurence)
        {
            if(occurence > rightmost_occurence)
            {
                second_rightmost_occurence = rightmost_occurence;
                rightmost_occurence = occurence;
            }
            else if(occurence > second_rightmost_occurence) second_rightmost_occurence = occurence;
        }
    };
private:
    int node_cnt;
    Node* odd_root, * even_root, * cur;
    Node* newNode(int len = 0)
    {
        Node* it = new Node();
        it->len = len;
        return it;
    }
    int start;
    std::vector<int> data;
    std::vector<Node*> prefix_palindrome;
    int size;
    Node* getFail(Node* it, int pos)
    {
        while(pos - it->len - 1 < start || data[pos - it->len - 1] != data[pos])
            it = it->fail;
        return it;
    }
public:
    EerQueue() : node_cnt(0), start(0), size(0)
    {
        odd_root = newNode(-1);
        even_root = newNode(0);
		odd_root->fail = odd_root;
		odd_root->fail_cnt += 1;
		even_root->fail = odd_root;
		odd_root->fail_cnt += 1;
		cur = even_root;
    }
    Node* push(int x)
    {
        assert(0 <= x && x < alpha);
        int pos = data.size();
        data.push_back(x);
        prefix_palindrome.push_back(nullptr);
        Node* it = getFail(cur, pos);
        if(it->next[x] == nullptr)
        {
            Node* tmp = newNode(it->len + 2);
            tmp->pre = it;
            tmp->fail = getFail(it->fail, pos)->next[x];
            if(tmp->fail == nullptr) tmp->fail = even_root;
            tmp->fail->fail_cnt += 1;
            it->next[x] = tmp;
            ++size;
        }
        cur = it->next[x];
        int occurence = pos - cur->len + 1;
        cur->updateOccurence(occurence);
        prefix_palindrome[occurence] = cur;
        return cur;
    }
    void pop()
    {
        assert(start < (int)data.size());
        Node* longest_prefix_palindrome = prefix_palindrome[start];
        if(longest_prefix_palindrome->len == (int)data.size() - start) cur = cur->fail;
        Node* it = longest_prefix_palindrome->fail;
        if(start != (int)data.size() - 1)
        {
            int occurence = start + longest_prefix_palindrome->len - it->len;
            it->updateOccurence(occurence);
            if(prefix_palindrome[occurence] == nullptr || it->len > prefix_palindrome[occurence]->len) prefix_palindrome[occurence] = it;
        }
        if (longest_prefix_palindrome->fail_cnt == 0 && longest_prefix_palindrome->second_rightmost_occurence < start)
        {
            int x = data[start];
            longest_prefix_palindrome->pre->next[x] = nullptr;
            it->fail_cnt -= 1;
            --size;
        }
        ++start;
    }
    int numOfPalindromes()
    {
        return size;
    }
};

void solve()
{
    int n;
    std::cin>>n;
    EerQueue<k> q;
    while(n--)
    {
        std::string op;
        std::cin>>op;
        if(op == "push")
        {
            char c;
            std::cin>>c;
            q.push(c - 'a');
        }
        else q.pop();
        std::cout<<q.numOfPalindromes()<<"\n";
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}
