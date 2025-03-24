class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        
        sort(meetings.begin(),meetings.end());
        vector<vector<int>>m2;
        m2.push_back(meetings[0]);

        

        for(int i=1;i<meetings.size();i++){
            if(meetings[i][0] <= m2.back()[1] ){
                m2.back()[1] = max(m2.back()[1],meetings[i][1]);
            }
            else{
                m2.push_back(meetings[i]);
            }
        }


        int ans=0;
        ans+=m2[0][0]-1;
        for(int i=1;i<m2.size();i++){
            ans += (m2[i][0]-m2[i-1][1]-1);
        }

        ans += (days-m2.back()[1]);

        return ans;



    }
};