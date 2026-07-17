class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxar=0;
        int s=0,e=height.size()-1;
        while(s<e){
            maxar=max(maxar,(e-s)*min(height[e],height[s]));
            if(height[s]<height[e]){
                s++;
            }
            else{
                e--;
            }
        }
        return maxar;
    }
};