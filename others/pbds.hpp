#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<class T>
using ordered_set =
tree<T, null_type, less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update>;

//insert,erase setと同じ
//find_by_order(k) k番目の取得
//order_of_key(k) lower_bound(k)と同じ