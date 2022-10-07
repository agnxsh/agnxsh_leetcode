class MyCalendarThree {
public:
    MyCalendarThree() {
        
    }
    map<int,int> timell;
    int book(int start, int end) {
        timell[start]++;
        timell[end]--;
        int ongoing =0;
        int k=0;
        for( pair<int,int> p : timell)
        {
            k = max(k , ongoing+=p.second);
        }
        return k;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */