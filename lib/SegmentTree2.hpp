const int startLimit = 1, endLimit = 10000007;
struct SegTreeNode
{
    int value=INT_MAX;
    SegTreeNode* left=NULL;
    SegTreeNode* right=NULL;
};

SegTreeNode* rootNode = NULL;
void update(SegTreeNode* &curNode,int st,int ed, int l,int r,int v)
{
    if(curNode==NULL) curNode = new SegTreeNode();
    if(curNode->value<=v) return;
    if(st>=l && ed<=r)
    {
        /// e.g. replace value with smaller one
        curNode->value = min(curNode->value,v);
        return;
    }
    int mid = (st+ed)/2;
    if(r<=mid)  update(curNode->left,st,mid,l,r,v);
    else if(l>mid)  update(curNode->right,mid+1,ed,l,r,v);
    else update(curNode->left,st,mid,l,r,v) , update(curNode->right,mid+1,ed,l,r,v);
}
int read(SegTreeNode* curNode,int st,int ed,int point,int curResult=INT_MAX)
{
    curResult = min(curResult,curNode->value);
    if(st == ed) return curResult;
    int mid = (st+ed)/2;
    if(point<=mid && curNode->left!=NULL) return read(curNode->left,st,mid,point,curResult);
    else if(point>mid && curNode->right!=NULL) return read(curNode->right,mid+1,ed,point,curResult);
    return curResult;
}


rootNode = new SegTreeNode();
