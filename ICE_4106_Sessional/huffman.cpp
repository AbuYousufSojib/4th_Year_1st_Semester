#include<bits/stdc++.h>
 using namespace std;

 //Node for create structure that means set of data
 struct Node
 {
   char data;float frequency;
   Node *left,*right;
   //Create constructor for assign value
   //here ch means vertex character
   Node (char ch,float freq)
   {
      left=right=NULL;
      data = ch;
      frequency = freq;
   }

 };

 //Node frequency comapare for create compare function

 struct compare
 {
   //ascending order for use L and R just two node
   bool operator()(Node*L,Node*R)
   {return L->frequency > R->frequency;}
 };

 void printCodes(Node* root,string code)
 {
   if(!root)return;
   //when vertex find then print code value
   if(root->data != '$')
      cout<<root->data<<" ->: "<<code<<endl;
   //recursive function use for each root for check
   printCodes(root->left,code+'0');
   printCodes(root->right,code+ '1');
 }
 void HuffmanCodes(char vertex[],float freq[],int size)
 {

   struct Node *left,*right,*top;

   priority_queue<Node*,vector<Node*>,compare>MaxHeap;
   for(int i=0;i<size;i++)
   {
      //constructor called so no object create
      MaxHeap.push(new Node(vertex[i],freq[i]));
   }
   //Continue still exist more than one node
   while(MaxHeap.size() != 1)
   {
      //cout<<MaxHeap.top()->frequency<<" "<<MaxHeap.top()->frequency<<endl;
      //MaxHeap.pop();
      //first two vertex store left and right variable
      //also delete two vertex and assign new vertec name
      left = MaxHeap.top();MaxHeap.pop();
      right = MaxHeap.top();MaxHeap.pop();
      //$ this indicate internal node or sum node
      top = new Node('$',left->frequency+right->frequency);
      top->left = left;
      top->right = right;
      //Now assign new internal node and frequency

      MaxHeap.push(top);

   }
   //Now contain main root exist MaxHeap queue
   //Print this Heap left side assign 0 and right side assign 0 then get code path
   //First call function heap value and null string
   printCodes(MaxHeap.top(),"");

}

 int main()
{

   //Enter number of node
   int n;
   cout<<"Enter symbol size: ";
   cin>>n;
   char arr[n+1];float freq[n+1];
   cout<<"Enter array: ";
   for(int i=0;i<n;i++)cin>>arr[i];
   cout<<"Enter probability: ";
   for(int i=0;i<n;i++)cin>>freq[i];
   HuffmanCodes(arr, freq, n);

   return 0;
}
