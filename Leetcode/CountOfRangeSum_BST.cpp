typedef long long LL;
struct node {
    LL v, size;
    node *left, *right;

};


struct Tree {
    node *root, *null;

    node* newNode(LL v) {
        node* temp = new node();
        temp -> v = v;
        temp -> left = temp -> right = null;
        temp -> size = 1;
        return temp;
    }

    Tree() {
        null = new node();
        null -> size = 0;
        root = newNode(0);
    }

    void _insert(LL v, node* &r) {
        if(r == null) {
            r = newNode(v);
            return;
        }
        ++(r->size);
        if(v < r -> v) {
            _insert(v, r->left);
        } else if(v > r -> v) {
            _insert(v, r->right);
        } else if(v == r -> v){
            return;
        }
    }
    

    void insert(LL v) {
        _insert(v, root);
    }


    int getLessSum(LL v) {
        int ans = 0;
        node* temp = root;

        while(temp != null) {
            if(temp -> v > v) {
                temp = temp -> left;
            } else if(temp -> v == v) {
                ans += (temp -> size - temp->right->size);
                break;
            } else {
                ans +=  (temp -> size - temp->right->size);
                temp = temp -> right;
            }
        }

        return ans;
    }

    void _dfs(node* root) {
        if(root == null) return;
        _dfs(root->left);
        cout << "value: " << root->v << "cnt: " << root-> size << endl;
        _dfs(root->right);
    }

    void dfs() {
        _dfs(root);
    }
};


class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        LL currentSum = 0;
        int ans = 0;
        Tree* t = new Tree();
        
        for(auto& i : nums) {
            currentSum += i;
            int a = t->getLessSum(currentSum - lower);
            int b = t->getLessSum(currentSum - upper - 1);
            ans += a - b;
            t->insert(currentSum);
        }
        return ans;
    }
};
CountOfRangeSum
