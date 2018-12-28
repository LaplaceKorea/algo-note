// https://stackoverflow.com/questions/8031939/finding-maximum-for-every-window-of-size-k-in-an-array
vector<int> max_sub_deque(vector<int> &A,int k)
{
    deque<int> q;
    for(int i=0;i<k;i++)
    {
        while(!q.empty() && A[i] >= A[q.back()])
            q.pop_back();
        q.push_back(i);
    }
    vector<int> res;
    for(int i=k;i<A.size();i++)
    {
        res.push_back(A[q.front()]);
        while(!q.empty() && A[i] >= A[q.back()] )
            q.pop_back();
        while(!q.empty() && q.front() <= i-k)
            q.pop_front();
        q.push_back(i); 
    }
    res.push_back(A[q.front()]);
    return res;
}
