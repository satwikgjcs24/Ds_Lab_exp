#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node*left;
struct node* right;
};
struct node*root=NULL;
struct node* create (int val)
{
struct node*newnode=malloc(sizeof(struct node));
newnode->data=val;
newnode->left=NULL;
newnode->right=NULL;
return newnode;
}
struct node* insert(struct node *root,int j)
{
if (root==NULL)
{
return create(j);
}
if(j>root->data)
{root->right=insert(root->right,j);

}
if(j<root->data)
{
root->left=insert(root->left,j);
}
return root;
}
void  preorder(struct node*root)
{
if(root!=NULL)
{
printf("%d",root->data);
preorder(root->left);
preorder(root->right);
}return;}
void inorder(struct node*root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d",root->data);
        inorder(root->right);
    }
return;
}
void postorder(struct node *root)
{

    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d",root->data);
    }return;
}
void main()
{

    int i,j,m;
    printf("Enter the number of node");
    scanf("%d",&m);
    for(i=0;i<m;i++)
    {

        scanf("%d",&j);
        root=insert(root,j);
    }
    printf("Enter the choies \n 1,for insertion \n2. postorder \n 3.preorder\n4.exit");
    while(1)
    {scanf("%d",&m);switch(m)
    {
        case 1:inorder(root);
                break;
        case 2:postorder(root);
                break;
        case 3:preorder(root);
                break;
        case 4:exit(0);
                break;
    }
}}