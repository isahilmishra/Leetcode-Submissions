#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
class Solution
{

    using ll = long long;

    typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag,
                 tree_order_statistics_node_update>
        oset;

public:
    
    long long countMajoritySubarrays(vector<int> &a, int k)
    {
        for (int &i : a)
            i = (i == k) ? 1 : -1;
        oset os;
        os.insert(0);
        int n = a.size();
        ll ans = 0, cs = 0;
        for (int i = 0; i < n; i++)
        {
            cs += a[i];
            ans += os.order_of_key(cs);
            os.insert(cs);
        }
        return ans;
    }
};