vector<vector<int>> verticalTraversal(TreeNode* root){
    map<int, map<int, multiset<int>>> m; //x,y,set of nodes
    queue <pair<int, pair<int, int>> q; //node, x, y
    q.push({root, {0,0}});
    while(q.empty() == false){
        auto p = q.front();
        TreeNode* temp = p.first;
        int x = p.second.firt;
        int y = p.second.second;

        m[x][y].insert(temp->val);

        if(temp->left != NULL) q.push(temp->left, {x-1, y+1});
        if(temp->right != NULL) q.push(temp->right, {x+1, y+1});

    }

    vector<vector<int>> ans;

    for(auto it : m){
        vector <int> v;
        for(auto q : it.second){
            v.insert(v.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(v);
    }
    return ans;
}