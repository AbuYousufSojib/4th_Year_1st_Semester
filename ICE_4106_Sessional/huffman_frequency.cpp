#include<bits/stdc++.h>
using namespace std;

struct Node
{
    char data; int frequency;
    Node *left, *right;
    Node(char ch, int freq)
    {
        left=right=NULL;
        data=ch;
        frequency=freq;
    }
};
struct compare
{
    bool operator()(Node*L,Node*R)
    {
        return L->frequency>R->frequency;
    }
};
void printCodes(Node* root, string code)
{
    if(!root)return;
    if(root -> data !='$')
        cout<<root->data<<" ->:"<<code<<endl;
    printCodes(root->left,code+'0');
    printCodes(root->right,code+'1');
}
void huffmanCodes(char vertex[],int freq[],int size)
{
    struct Node *left, *right, *top;
    priority_queue<Node*,vector<Node*>,compare>MinHeap;
    for(int i=0;i<size;i++)
    {
        MinHeap.push(new Node(vertex[i],freq[i]));
    }
    while(MinHeap.size() != 1)
    {
        left = MinHeap.top();MinHeap.pop();
        right = MinHeap.top();MinHeap.pop();
        top = new Node('$',left->frequency+right->frequency);
        top->left = left;
        top->right = right;
        MinHeap.push(top);
    }
    printCodes(MinHeap.top(),"");
}
int main()
{
    int n;
    cout<<"Enter the size of the symbol: "<<endl;
    cin>>n;
    char arr[n+1];int freq[n+1];
    cout<<"Enter the array: ";
    for(int i=0;i<n;i++)cin>>arr[i];
    cout<<"Enter Frequency: ";
    for(int i=0;i<n;i++)cin>>freq[i];
    huffmanCodes(arr, freq, n);

    return 0;
}
