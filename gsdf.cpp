#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

struct cus {
    int l;
    int r;
    int idx;
    int roomid;

    bool operator< (const cus &a) const {
        
        return l < a.l;
    }
};

struct rom {
    int r;
    int roomid;
    bool operator <(const rom &rm) const {
        return r < rm.r;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<cus> a(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i].l >> a[i].r;
        a[i].idx = i;
        a[i].roomid = 0;
    }

    sort(a.begin(), a.end()); 

    set<rom> s;  
    int cnt = 1; 

    a[0].roomid = 1;
    rom firstRoom = { a[0].r, 1 }; 
    s.insert(firstRoom);

    for (int i = 1; i < n; ++i) {
    
        auto it = s.lower_bound({ a[i].l, 0 });

        rom rm;
        
        if (it != s.begin()) {
            --it; 
            rm.roomid = it->roomid;
            s.erase(it); // Remove the old room as its departure time will change
        } else {
            // No available room, assign a new room
            cnt++;
            rm.roomid = cnt;
        }

        // Assign the new departure time for the room
        rm.r = a[i].r;
        s.insert(rm); // Insert the updated room into the set
        a[i].roomid = rm.roomid;
    }

    vector<int> res(n);
    for (int i = 0; i < n; ++i) {
        res[a[i].idx] = a[i].roomid;
    }

    cout << cnt << "\n"; // Total number of rooms used
    for (int i = 0; i < n; ++i) {
        cout << res[i] << " ";
    }

    return 0;
}
