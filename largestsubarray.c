#include<stdio.h>
#include<math.h>

#define max(x, y) \
    (x > y) ? x : y;
 

int maxSubArrayInt(int *nums, int start, int numsSize, int side)
{
    int x,y;

    if (numsSize == 1)
        return nums[start];
    if (numsSize == 2) {
	    if (nums[start] > 0 && nums[start+1]> 0) {
		return nums[start] + nums[start+1];
	    }
	    else if (side == 0) {
		    if (nums[start] < 0)
			    return nums[start+1];
		    return nums[start]+nums[start+1];
	    } else {
		    if (nums[start+1] < 0)
			    return nums[start];
		    return nums[start]+nums[start+1];
	    }
    }
    x = maxSubArrayInt(nums, 0, (int)ceil((double)numsSize/2),0);
    y = maxSubArrayInt(nums, (int)floor((double)numsSize/2)+1, numsSize-((int)floor((double)numsSize/2)+1),1);
    
    if (x > 0 && y > 0)
        return x + y;
    else {
        if (side == 0) {
            if (x < 0)
                return y;
            return x + y;
        } else {
            if (y < 0)
                return x;
            return x + y;
        }
    }
}

int maxSubArray(int* nums, int numsSize){
    int x, y;
        
    if (numsSize == 1)
        return nums[0];
    if (numsSize == 2) {
        if (nums[0] > 0 && nums[1] > 0) {
            return nums[0] + nums[1];
        }
        else max(nums[0], nums[1]);
    }
    return maxSubArrayInt(nums, 0, numsSize, -1);
}

int main(int argc, char **argv)
{
	int nums[3] = {-2, 1, 3};
	printf ("%d", maxSubArray(nums, 3));
}

