#include <iostream>
#include <vector>
using namespace std;

// 直接アドレス表と関連付けるオブジェクトのデータ型
typedef struct _data{
    int key;
    int value;
}object_data;

// コマンドを表す列挙体
typedef enum _command{
    QUIT,
    SEARCH,
    INSERT,
    DELETE
}command;

// 直接アドレス表のサイズ
#define ADDRESS_TABLE_MAXSIZE 15

// 直接アドレス表
vector<object_data> direct_address_table(ADDRESS_TABLE_MAXSIZE);

// 関数プロトタイプ宣言 ============================================================
void direct_address_initialize(vector<object_data> &table);
object_data direct_address_search(const vector<object_data> &table, const int _key);
void direct_address_insert(vector<object_data> &table, object_data object);
void direct_address_delete(vector<object_data> &table, object_data object);

void command_search(void);
void command_insert(void);
void command_delete(void);
bool input_check(const int _key);
// =================================================================================

// 直接アドレス表の初期化
void direct_address_initialize(vector<object_data> &table){
    for(int _key = 0; _key < ADDRESS_TABLE_MAXSIZE; _key++){
        direct_address_table[_key] = { -1, 0 };
    }
}

// 直接アドレス表の探索
object_data direct_address_search(const vector<object_data> &table, const int _key){
    return table[_key];
}

// 直接アドレス表にオブジェクトを挿入
void direct_address_insert(vector<object_data> &table, const object_data object){
    table[object.key] = object;
    return;
}

// 直接アドレス表からオブジェクトを削除
void direct_address_delete(vector<object_data> &table, const object_data object){
    table[object.key] = { -1, 0 };
    return;
}

// SEARCH入力時の処理
void command_search(void) {
    int _key;
    while(true){
        cout << "Input key:";
        cin >> _key;
        if(input_check(_key) == true) break;
    }

    // 直接アドレス表の検索結果
    object_data search_result = direct_address_search(
        direct_address_table,
        _key
    );

    // 直接アドレス表の結果が空オブジェクトの時
    if(search_result.key == -1) {
        cout << "Not found." << endl;
        return;
    }

    cout << "Key:" << search_result.key << " Value:" << search_result.value << endl;

    return;
}

// INSERT入力時の処理
void command_insert(void){
    int _key, _value;
    while(true) {
        cout << "Input (Key, Value):";
        cin >> _key >> _value;
        if(input_check(_key) == true) break;
    }

    // これから挿入したいオブジェクト
    object_data new_object = {
        _key, 
        _value
    };

    // もし既に追加したい位置に既にオブジェクトが存在したら
    // エラーを吐いて処理を終了する
    if(direct_address_search(direct_address_table, new_object.key).key != -1){
        cout << "Object has been existed in this address." << endl;
        return;
    }

    direct_address_insert(direct_address_table, new_object);
    return;
}

// DELETE入力時の処理
void command_delete(void) {
    int _key;
    while(true){
        cout << "Input Key:";
        cin >> _key;
        if(input_check(_key) == true) break;
    }
        
    // これから削除したいオブジェクト
    object_data to_delete_object = direct_address_table[_key];

    // これから削除したい一のオブジェクトがそもそも存在しないとき
    // エラーをはいて処理を終了する
    if(to_delete_object.key == -1){
        cout << "Object has not been existed in this address." << endl;
        return;
    }

    direct_address_delete(direct_address_table, to_delete_object);
    cout << "Deletion Completed." << endl;
    return;
}

// keyの入力チェック(最小値:0, 最大値:ADDRESS_TABLE_MAXSIZE)
bool input_check(const int _key) {
    if(_key < 0 || _key < ADDRESS_TABLE_MAXSIZE) return false;

    return true;
}

int main(){

    // 直接アドレス表を初期化
    direct_address_initialize(direct_address_table);

    while(true){
        cout << "1--search\t2--insert\t3--delete\t0--quit\n" << endl;
        int res = 0;
        cin >> res;
        if(res == QUIT) {
            cout << "Quit." << endl;
            break;
        }

        switch(res){
            case SEARCH:
                cout << "SEARCH" << endl;
                command_search();
                break;
            case INSERT:
                cout << "INSERT" << endl;
                command_insert();
                break;
            case DELETE:
                cout << "DELETE" << endl;
                command_delete();
                break;
            default:
                break;
        }
    }

    return 0;
}