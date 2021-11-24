class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;
        if(firstList.size()==0 || secondList.size()==0 )
            return ans;
        //用每個end去看是否重疊
        int size1 = firstList.size(), size2 = secondList.size();
        int i = 0 ,j = 0;
        bool end = false;
        while(i<size1 && j < size2 && !end){
            
            if(i==size1-1 && firstList[i][1] <= secondList[j][1])
                end = true;
            if(j==size2-1 && secondList[j][1] <= firstList[i][1])
                end = true;
            if(!end && i==size1-1 && j==size2-1)
                end = true;
            if(firstList[i][1] < secondList[j][0]){
                //cout << i << " i++ " << j << endl;//1.end < 2.start
                i++;
            }
            else if(secondList[j][1] < firstList[i][0]){//s.end < 1.start
                //cout << i << " j++ " << j << endl;
                j++;
            }
            else{
                //cout << i << " compute " << j << endl;
               vector<int> temp;
               if(firstList[i][1] >= secondList[j][0]){
                   int t = max(secondList[j][0],firstList[i][0]);
                   temp.push_back(t);
                   int m = min(secondList[j][1],firstList[i][1]);
                   temp.push_back(m);
                   
                   ans.push_back(temp);
                   if(firstList[i][1] <= secondList[j][1])
                        i++;
                   else if(secondList[j][1] <= firstList[i][1])
                        j++;
               } 
            }
            
        }
        
        
        return ans;
    }
};
