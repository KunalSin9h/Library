template<typename Key, typename Val, typename cmp = std::less<Key>>
using ordered_map = __gnu_pbds::tree<Key, Val, cmp, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

template<typename Key, typename cmp = std::less<Key>>
using ordered_set = ordered_map<Key, __gnu_pbds::null_type, cmp>;
