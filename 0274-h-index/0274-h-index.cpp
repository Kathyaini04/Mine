class Solution {
public:
    int hIndex(vector<int>& citations) {

        sort(citations.rbegin(), citations.rend()); // desc sort
        int h=0; // h-index

        for ( int i=0; i< citations.size();i++)
        {
            if(citations[i]>=i+1) // i+1 = paper number
            // checking if curr paper has at least i+1 citations
            {
                h=i+1;
            }
            else
            {
               break; // since list sorted , rest will also fail 
        }
        }
        return h;
    }
};