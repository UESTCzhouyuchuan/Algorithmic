#include<bits/stdc++.h>
using namespace std;
map<string,int>H;
const int max_v=10005;
int V=0;
int getid(string s){
    if(!H[s])H[s]=++V;
    return H[s];
}
vector<int> G[max_v];
vector<int> rG[max_v];
vector<int> vs;
bool used[max_v];
int cmp[max_v];
int sz[max_v];
void add_edge(int from,int to)
{
    G[from].push_back(to);
    rG[to].push_back(from);
}
void dfs(int v)
{
    used[v]=true;
    for(int i=0;i<G[v].size();i++)
    {
        if(!used[G[v][i]])
            dfs(G[v][i]);
    }
    vs.push_back(v);
}
void rdfs(int v,int k)
{
    used[v]=true;
    cmp[v]=k;
    sz[k]++;
    for(int i=0;i<rG[v].size();i++)
    {
        if(!used[rG[v][i]])
            rdfs(rG[v][i],k);
    }
}
int scc()
{
    memset(used,0,sizeof(used));
    vs.clear();
    for(int v=1;v<=V;v++)
    {
        if(!used[v])
            dfs(v);
    }
    memset(used,0,sizeof(used));
    int k=0;
    for(int i=vs.size()-1;i>=0;i--)
    {
        if(!used[vs[i]])
            rdfs(vs[i],k++);
    }
    return k;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    string s1,s2;
    while(cin>>s1){
        if(s1=="END")break;
        cin>>s2;
        G[getid(s1)].push_back(getid(s2));
        rG[getid(s2)].push_back(getid(s1));
    }
    int p=scc();
    vector<int>Ans;
    for(int i=0;i<p;i++)
        Ans.push_back(-sz[i]);
    sort(Ans.begin(),Ans.end());
    for(int i=0;i<min(m,(int)Ans.size());i++)
        cout<<-Ans[i]<<endl;
    for(int i=Ans.size();i<m;i++)
        cout<<"Does not apply!"<<endl;
}
