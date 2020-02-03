 /*
 * Complete the function below.
 * Please store the size of the string array to be returned in result_size pointer. For example,
 * char a[2][6] = {"hello", "world"};
 * *result_size = 2;
 * return a;
 *
 */
 int compare (int first, int second)
 {
     if(first < second)
        return 1;
    return 0;
 }

void helper(vector<int> &arr, vector<string> &ret)
{
    int i = 0;
    int l;
    int r;
    int target;
    //cout << "Size " << arr.size() << endl;
    int prev;
    for (i = 0; i< arr.size(); i++) {
        //cout << i << endl;
        //if (i > 0) {
        //    if (arr[i] == prev);
        //        continue;
        //}
        prev = arr[i];
        
        l = i + 1;
        r = arr.size()-1;
        target = arr[i];
        while (l < r) {
            //cout << "Left "<<l <<" Right "<< r << " Sum " <<arr[l] + arr[r] + target <<endl;
            if (arr[l] + arr[r] + target > 0) {
                r--;
            } else if (arr[l] + arr[r]+target < 0) {
                l++;
            } else {
                char buf[255];
                snprintf(buf, 255, "%d,%d,%d", arr[i], arr[l], arr[r]);
                string x= string(buf);
                //cout << "Here" << *x << endl;
                if (ret.size() > 0) {
                    //cout << ret[ret.size()-1] << "compared with " << x << endl;
                    if(ret[ret.size()-1].compare(x) == 0) {
                        break;
                    }
                }
                ret.push_back(x);
                break;
            }
        }
    }
    
}

vector<string> findZeroSum(vector<int> arr) {
    vector<string> ret;
    int i = 0;
    // Write your code here.
    std::sort (arr.begin(), arr.end(), compare);
    //for (i = 0; i< arr.size(); i++)
    //    cout << arr[i] << endl;
    //cout << endl << endl;
    helper(arr, ret);
    //cout << "size" << ret.size()<< endl;
    /*for (i = 0; i< ret.size(); i++)
        cout << ret[i] << endl;*/
    return ret;
}


