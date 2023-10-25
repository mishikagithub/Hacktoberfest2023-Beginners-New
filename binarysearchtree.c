#include<stdio.h>
#include<malloc.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createnode(int data){
    struct node*n;
    n=(struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
}

void Inorder(struct node* root){
    if(root!=NULL){
        Inorder(root->left);
        printf("%d ", root->data);
        Inorder(root->right);     
    }
}

int isBST (struct node* root){
    struct node* prev = NULL;//root node jiska child node nahi hai
    if (root!=NULL){
   if(!isBST(root->left)){
    return 0;
   }
   if (prev!=NULL && root->data <= prev->data){
    return 0;
   }
   prev = root;
   return  isBST(root->right);
    }
    else{
        return 1;
    }
}

int main(){
    struct node*p = createnode(5);
    struct node*p1 = createnode(3);
    struct node*p2 = createnode(6);
    struct node*p3 = createnode(1);
    struct node*p4 = createnode(4);
    

    p->left = p1;
     p->right = p2;
      p1->left = p3;
       p1->right = p4;
     Inorder(p);
     printf("\n");
     printf("%d",isBST(p));
}
