class FenwickTree {
    int n;
    vector<int> tree;
public:
    FenwickTree(int n):n(n),tree(n+1,0) {} // 1 based idx

    void add(int idx,int val) {
        while(idx<=n) {
            tree[idx]+=val;
            idx+=idx&(-idx);
        }
    }

    int query(int idx) {
        int sum=0;
        while(idx>0) {
            sum+=tree[idx];
            idx-=idx&(-idx);
        }
        return sum;
    }
};

class NumArray {
public:
    FenwickTree ft;
    vector<int> arr;
    NumArray(vector<int>& nums) : ft(nums.size()){
        int n=nums.size();
        arr=nums;
        for(int i=0;i<n;i++) {
            ft.add(i+1,nums[i]);
        }
    }
    
    void update(int index, int val) {
        int diff=val-arr[index];
        arr[index]=val;
        ft.add(index+1,diff);
    }
    
    int sumRange(int left, int right) {
        // return ft.query(right)-ft.query(left-1);     // default
        return ft.query(right+1)-ft.query(left);        // 1 based indexing
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */