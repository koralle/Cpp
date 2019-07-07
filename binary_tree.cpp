#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Node型の定義
typedef struct _Node{
    int key;
    struct _Node *left;
    struct _Node *right;
    struct _Node *parent;
}Node;

// 2分探索木の根 ###############################
typedef struct _Tree{
    Node *root;
}Tree;

Tree *binary_tree = new Tree;
// #############################################

// コマンド ###################################
typedef enum _command{
    QUIT,
    INSERT,
    DELETE,
    SEARCH,
    DISPLAY
}command;
// ############################################

// 関数宣言 ###################################
void inorder_tree_walk(Node *x);
Node *tree_search(Node *x, int k);
Node *tree_min(Node *x);
Node *tree_max(Node *x);
Node *tree_successor(Node *x);
void tree_insert(Tree *T, Node *z);
void transplant(Tree *T, Node *u, Node *v);
void tree_delete(Tree *T, Node *z);
void COMMAND_INSERT();
void COMMAND_DELETE();
void COMMAND_SEARCH();
void RELEASE_BINARY_TREE();
// ###########################################

// 2分探索木Tの中のすべての要素を印刷する #########
void inorder_tree_walk(Node *x){
    if(x == NULL) return;

    inorder_tree_walk(x->left);
    cout << "Node: " << x->key << endl;
    inorder_tree_walk(x->right);

    return;
}
// ###############################################


// 2分木の探索 ###################################
Node *tree_search(Node *x, int k){
    // xがNULL
    if(x == NULL) return x;

    // kに等しいkeyを持つ節点xを見つけた
    if(x->key == k) return x;

    // kよりx.keyが大きい時は左部分木を探索
    if(k < x->key) return tree_search(x->left, k);

    // kよりx.keyが小さい時は右部分木を探索
    else return tree_search(x->right, k);
}
// ##############################################

// 2分木の最小値を探索 #########################
Node *tree_min(Node *x){
    while (x->left != NULL) x = x->left;
    return x;
}
// #############################################

// 2分木の最大値を探索 ########################
Node *tree_max(Node *x){
    while(x->right != NULL) x = x->right;
    return x;
}
// ###########################################

// 次節点を探索 ###################################
Node *tree_successor(Node *x){
    if(x->right != NULL) return tree_min(x->right);

    Node *y = x->parent;
    while(y != NULL && x == y->right) {
        x = y;
        y = y->parent;
    }
    return y;
}
// ###############################################


// 要素の挿入 ####################################
void tree_insert(Tree *T, Node *z){
    Node *y = NULL;
    Node *x = T->root;

    // 同一のkeyを持つ節点は気に導入しない
    if(tree_search(T->root, z->key) != NULL) {
        cout << "Node " << z->key << " is already existed." << endl;
        if(z != NULL) {
            delete z;
            z = NULL;
        }
        return;
    }

    // 木の最下層まで下る
    while(x != NULL){
        y = x;
        if(z->key < x-> key) x = x->left;
        else x = x->right;
    }

    z->parent = y;

    // 節点zに親がいないならば節点zを親にする
    if(y == NULL) T->root = z;

    // yの左の子をzにする
    else if(z->key < y->key) y->left = z;

    // yの右の子をzにする
    else y->right = z;
}
// ###############################################

// ある節点の子である部分木を別の部分木に置き換える #####
void transplant(Tree *T, Node *u, Node *v){
    //
    if (u->parent == NULL) T->root = v;
    else if(u == u->parent->left) u->parent->left = v;
    else u->parent->right = v;

    if(v != NULL) v->parent = u->parent;
}

// 節点zを2分探索木Tから削除する
void tree_delete(Tree *T, Node *z){
// 左の子が存在しない => 節点zを右の子で置き換える
    if(z->left == NULL) transplant(T, z, z->right);

    // 右の子が存在しない => 節点zを左の子で置き換える
    else if(z->right == NULL) transplant(T, z, z->left);

    // 節点zが左の子も右の子も持つ場合
    else{

        // yは右の子を親とする部分木の最小値
        Node *y = tree_min(z->right);

        // yの親がzではない
        if (y->parent != z){

            // yを根とする部分木を作る
            // yの左の子はNULL、右の子はzの右の子
            transplant(T, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }

        // zをyで置き換える
        transplant(T, z, y);
        y->left = z->left;
        y->left->parent = y;
    }
    if(z != NULL) {
        delete z;
        z = NULL;
        cout << "SUCCESS" << endl;
    }
}
// #####################################################


void COMMAND_INSERT(){
    cout << "Input key = ";
    int _key = 0;
    cin >> _key;

    // 節点の作成
    Node *node = new Node;
    node->key = _key;

    // 木に節点を挿入
    tree_insert(
        /*    Tree *T = */ binary_tree,
        /*    Node *z = */ node
    );
}

void COMMAND_DELETE(){
    cout << "Input key = ";
    int _key = 0;
    cin >> _key;

    // まずは_keyをkey属性に持つ節点を探索する
    Node *result = tree_search(
        /* Node *x = */ binary_tree->root,
        /*   int k = */ _key
    );

    if(result == NULL) cout << "Not found." << endl;
    else tree_delete(
        /* Tree *T = */ binary_tree,
        /* Node *z = */ result
    );
}

void COMMAND_SEARCH(){
    cout << "Input key = ";
    int _key = 0;
    cin >> _key;

    Node *result = tree_search(
        /* Node *x = */ binary_tree->root,
        /*   int k = */ _key
    );

    if(result == NULL) cout << "Not found." << endl;
    else cout << result->key << endl;

    return;
}

void RELEASE_BINARY_TREE(){

    // 2分探索木が空なら2分探索木へのポインタへ割り当てたメモリも解放
    if(binary_tree->root == NULL){
        if(binary_tree != NULL){
            delete binary_tree;
            binary_tree = NULL;
        }
        cout << "Binary tree has been deleted." << endl;
        return;
    }
    else{
        // 木が空になるまで根を削除していく
        tree_delete(
            /*    Tree *T = */ binary_tree,
            /* Node *node = */ binary_tree->root
        );
    }
        RELEASE_BINARY_TREE();
}

int main(){

    while(true){
        cout << "1--Insert\t2--Delete\t3--Search\t4--Display\t0--Quit" << endl;
        int res;
        cout << "Res: ";
        cin >> res;

        if(!res) break;

        switch(res){
            case INSERT:
                COMMAND_INSERT();
                break;
            case DELETE:
                COMMAND_DELETE();
                break;
            case SEARCH:
                COMMAND_SEARCH();
                break;
            case DISPLAY:
                inorder_tree_walk(
                    /* Node *x = */ binary_tree->root
                );
                break;
            default:
                cout << "COMMAND ERROR." << endl;
                break;
        }
    }

    // 2分探索木に割り当てたメモリの開放
    RELEASE_BINARY_TREE();

    return 0;
}
