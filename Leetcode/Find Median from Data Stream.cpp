struct BST {
    struct node {
        int val;
        int size;
        node* left, *right;
        node(int v) : size(1), val(v) {};
    } *Null, *root;
    
    BST() {
        Null = new node(0);
        Null -> size = 0;
        root = Null;
    }
    
    void add(int val, node*& R) {
        if(R == Null) {
            R = new node(val);
            R -> left = R -> right = Null;
            return;
        }
        if(R->val <= val) add(val, R->left);
        else add(val, R->right);
        R->size = R->left->size + R->right->size + 1;
        
    }
    
    int rank(int k) {
        node* t = root;
        while(true) {
            int leftSize =  t -> left -> size;
            if(leftSize == k) return t -> val;
            if(leftSize > k) {
                t = t -> left;
            } else {
                k = k - leftSize - 1;
                t = t -> right;
            }
        }
        return -1;
    }
};




class MedianFinder {
public:
    BST* bst;
    MedianFinder() {
        bst = new BST();
    }
    // Adds a number into the data structure.
    void addNum(int num) {
        bst->add(num, bst->root);
    }
    
    // Returns the median of current data stream
    double findMedian() {
        int sz = bst -> root -> size;
        if(sz % 2 == 0) {
            return 1.0 * (bst -> rank(sz / 2) + bst -> rank(sz / 2 - 1)) / 2;
        } else return bst->rank(sz / 2);
        
    }
};
