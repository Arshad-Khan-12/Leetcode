class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        vector<int>copy(colors.begin(),colors.end());
        for(int i=0;i<k-1;i++){
            copy.push_back(colors[i]);
       }


       int i=0;
       int j=1;
       int ans = 0;
       while(j<copy.size()){
            if(copy[j] != copy[j-1]){
                if(j-i+1 == k){
                    ans++;
                    j++;
                    i++;
                }
                else{
                    j++;
                }
            }
            else{
                i=j;
                j++;
            }
       }
       return ans;
    }
};