class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> graph;
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        unordered_set<int> visited;
        return dfs(source, destination, graph, visited);
    }
    
    bool dfs(int node, int destination, unordered_map<int, vector<int>>& graph, unordered_set<int>& visited) {
        if (node == destination) {
            return true;
        }
        visited.insert(node);
        for (int neighbor : graph[node]) {
            if (visited.find(neighbor) == visited.end()) {
                if (dfs(neighbor, destination, graph, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
};

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> graph;
        
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        queue<int> queue;
        unordered_set<int> visited;
        
        queue.push(source);
        visited.insert(source);
        
        while (!queue.empty()) {
            int node = queue.front();
            queue.pop();
            if (node == destination) {
                return true;
            }
            for (int neighbor : graph[node]) {
                if (visited.find(neighbor) == visited.end()) {
                    visited.insert(neighbor);
                    queue.push(neighbor);
                }
            }
        }
        
        return false;
    }
};

class Solution {
    private int[] parent;
    private int[] rank;
    
    public boolean validPath(int n, int[][] edges, int source, int destination) {
        parent = new int[n];
        rank = new int[n];
        
        // Initialize parent pointers and ranks
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
        
        // Union-find operations based on given edges
        for (int[] edge : edges) {
            union(edge[0], edge[1]);
        }
        
        // Check if source and destination belong to the same set
        return find(source) == find(destination);
    }
    
    private int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }
    
    private void union(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
}

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> graph;
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        vector<int> distances(n, numeric_limits<int>::max());
        distances[source] = 0;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> priorityQueue;
        priorityQueue.push({0, source});
        
        while (!priorityQueue.empty()) {
            auto current = priorityQueue.top();
            priorityQueue.pop();
            int currentDistance = current.first;
            int currentNode = current.second;
            
            if (currentNode == destination) {
                return true;
            }
            
            if (currentDistance > distances[currentNode]) {
                continue;
            }
            
            for (int neighbor : graph[currentNode]) {
                int distance = currentDistance + 1; // Assuming unweighted graph
                if (distance < distances[neighbor]) {
                    distances[neighbor] = distance;
                    priorityQueue.push({distance, neighbor});
                }
            }
        }
        
        return false;
    }
};
