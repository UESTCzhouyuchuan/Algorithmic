#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+7;
struct node{
    typedef int SgTreeDataType;
    struct treenode
    {
        int L , R  ;
        SgTreeDataType sum , lazy;
        void update(SgTreeDataType v)
        {
            sum += (R-L+1)*v;
            lazy += v;
        }
    };

    treenode tree[maxn*4];

    inline void push_down(int o)
    {
        SgTreeDataType lazyval = tree[o].lazy;
        tree[2*o].update(lazyval) ; tree[2*o+1].update(lazyval);
        tree[o].lazy = 0;
    }

    inline void push_up(int o)
    {
        tree[o].sum = tree[2*o].sum + tree[2*o+1].sum;
    }

    inline void build_tree(int L , int R , int o)
    {
        tree[o].L = L , tree[o].R = R,tree[o].sum = tree[o].lazy = 0;
        if (R > L)
        {
            int mid = (L+R) >> 1;
            build_tree(L,mid,o*2);
            build_tree(mid+1,R,o*2+1);
        }
    }

    inline void update(int QL,int QR,SgTreeDataType v,int o)
    {
        int L = tree[o].L , R = tree[o].R;
        if (QL <= L && R <= QR) tree[o].update(v);
        else
        {
            push_down(o);
            int mid = (L+R)>>1;
            if (QL <= mid) update(QL,QR,v,o*2);
            if (QR >  mid) update(QL,QR,v,o*2+1);
            push_up(o);
        }
    }

    inline SgTreeDataType query(int QL,int QR,int o)
    {
        int L = tree[o].L , R = tree[o].R;
        if (QL <= L && R <= QR) return tree[o].sum;
        else
        {
            push_down(o);
            int mid = (L+R)>>1;
            SgTreeDataType res = 0;
            if (QL <= mid) res += query(QL,QR,2*o);
            if (QR > mid) res += query(QL,QR,2*o+1);
            push_up(o);
            return res;
        }
    }
}T;
int r,c;
int ans[10005];
string op[10005];
int x1[10005],Y1[10005],x2[10005],y2[10005];
int main()
{
    scanf("%d%d",&r,&c);
    int m;scanf("%d",&m);
    for(int i=1;i<=m;i++)
        cin>>op[i],scanf("%d%d%d%d",&x1[i],&Y1[i],&x2[i],&y2[i]);
    for(int i=1;i<=r;i++){
        T.build_tree(1,c,1);
        for(int j=1;j<=m;j++){
            if(x1[j]<=i&&i<=x2[j]){
                if(op[j][0]=='q')ans[j]+=T.query(Y1[j],y2[j],1);
                if(op[j][0]=='a')T.update(Y1[j],y2[j],1,1);
                if(op[j][0]=='r')T.update(Y1[j],y2[j],-1,1);
            }
        }
    }
    for(int i=1;i<=m;i++)
        if(op[i][0]=='q')
            cout<<ans[i]<<endl;

}
