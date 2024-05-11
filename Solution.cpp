class Solution {
public:
    int maxArea(vector<int>& height) {
        int area;
        int largest = height[0];
        int secondLargest = 0;
        
        for(int i = 1; i < height.size(); ++i)
        {
            /* if(height[i] > largest)
            {
                secondLargest = largest;
                Largest = height[i];
            }
            else if(height[i] > secondLargest)
            {
                secondLargest = height[i];
            }
            */
            if(height[i] > secondLargest)
            {
                if(height[i] > largest)
                {
                     secondLargest = largest;
                     largest = height[i];
                }
                else
                {
                   secondLargest = height[i]; 
                }
            }
        }
        
        // cout << largest << ' ' << secondLargest;
        long long theoreticalMaxArea = secondLargest * (height.size() - 1) ;
        int left = 0;
        int right = height.size() - 1;
        int h;
        
        if(height[left] <= height[right])
        {
            h = height[left];
        }
        else 
        {
            h = height[right];
        }
        
        int maxArea = h * (right - left);
        // cout << "we got here" << endl;
        while(theoreticalMaxArea > maxArea && right > left)
        {
            if(height[left] <= height[right])
            {
                ++left;
                while(right > left && h >= height[left])
                {
                    ++left;
                }
            }
            else 
            {
                --right;
                while(right > left && h >= height[right])
                {
                    --right;
                }
                
            }
            
            if(right == left)
            {
                break;
            }
            
            if(height[left] <= height[right])
            {
                h = height[left];
            }
            else 
            {
                h = height[right];
            }
            
            area = h * (right - left);
            if(area > maxArea)
            {
                maxArea = area;
            }
            
            theoreticalMaxArea =  secondLargest * (right - left - 1);
        }
        
        return maxArea;
        
        
    }
};
