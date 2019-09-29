/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#define dbg(x) cout<<#x<<" "<<x<<" "
#define dbgv(v) for(auto ele:v)cout<<ele<<" "
#define nl cout<<"\n"

void travel_preorder(TreeNode* tree,vector<int>&v){
    if(tree==NULL)return;
    v.push_back(tree->val);
   // dbg(tree->val);nl;
    travel_preorder(tree->left,v);
    travel_preorder(tree->right,v);
    v.push_back(tree->val);
}
vector<int> prefix_function(vector<int> &v) 
{
	int n = (int)v.size();
	vector<int> pi(n);
	for (int i = 1; i < n; i++) 
	{
		int j = pi[i-1];
		while (j > 0 && v[i] != v[j])
			j = pi[j-1];
		if (v[i] == v[j])
			j++;
		pi[i] = j;
	}
	return pi;
}

vector<int> find_occurences(vector<int> &text, vector<int> &pattern)
{
	vector<int> v=pattern;
	v.push_back(-1);
	for(auto &it:text)
		v.push_back(it);
	int sz1=text.size(), sz2=pattern.size();
	vector<int> lps=prefix_function(v);
	vector<int> store;
   // dbgv(lps);nl;
	for(int i=sz2+1;i<=sz1+sz2;i++)
	{
		if(lps[i]==sz2)
			store.push_back(i-sz2*2);
	}
	return store;
}

class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        vector<int>v1,v2;
        travel_preorder(s,v1);
        //for(int ele:v1)cout<<ele<<" ";nl;
       
        travel_preorder(t,v2);
         //for(int ele:v2)cout<<ele<<" ";nl;
        ///dbg(v1.size());dbg(v2.size());
        vector<int> xx=find_occurences(v1,v2);
        return (xx.size()>0);
    }
};
