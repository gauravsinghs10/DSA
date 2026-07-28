class Solution {
public:
    void dfs(vector<vector<int>>& rooms, vector<bool>& visited, int curr) {
        visited[curr] = true;
        for (int key : rooms[curr]) {
            if (!visited[key]) {
                dfs(rooms, visited, key);
            }
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        dfs(rooms, visited, 0);
        
        for (bool v : visited) {
            if (!v) {
                return false;
            }
        }
        return true;
    }
};