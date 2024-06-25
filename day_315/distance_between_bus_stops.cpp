class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int n = distance.size();
        int clock = 0, anticlock = 0;

        int src = min(start, destination), dst = max(start, destination);

        for(int i=0; i<n; i++){
            if(i >= src && i < dst){
                clock += distance[i];
            }
            else{
                anticlock += distance[i];
            }
        }
        return min(clock, anticlock);
    }
};
