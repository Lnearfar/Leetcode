class Solution {
public:
    int maxArea(vector<int>& height) {
        //V = (j-i)*min(h[i],h[j])
        int l=0,r=height.size()-1;
        int m_area=0,area;
        while(l!=r){
            area=(r-l)*min(height[l],height[r]);
            if(area>m_area) m_area=area;
            height[l]<height[r]?l++:r--;
        }
        return m_area;
    }
};
