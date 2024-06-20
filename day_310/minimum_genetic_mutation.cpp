class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_map<string,vector<string>> adj;
        bank.push_back(startGene);
        // creating adjency list-> making connections between mutations which have difference 1
        for(string gene1 : bank){
            for(string gene2 : bank){
                int diff = 0;
                for(int i=0; i<8; i++){
                    if(gene1[i] != gene2[i]) diff++;
                }
                if(diff == 1){
                    adj[gene1].push_back(gene2);
                }
            }
        }
        
        unordered_map<string,bool> visited;
        visited[startGene] = true;
        queue<string> q;
        q.push(startGene);
        q.push("null");
        int mutation = 0;

        while(!q.empty()){
            string front = q.front();
            q.pop();

            if(front == "null"){
                if(!q.empty()){
                    q.push("null");
                    mutation++;
                }
                continue;
            }
            visited[front] = true;
            if(front == endGene) return mutation;
            for(string gene : adj[front]){
                if(!visited[gene])
                    q.push(gene);
            }

        }
        return -1;
    }
};
