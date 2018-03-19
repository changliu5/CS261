struct data{
    char* content;
    int number;
};

struct Node {
    TYPE         val;
    struct Node *left;
    struct Node *right;
};

struct BSTree {
    struct Node *root;
    int          cnt;
};
