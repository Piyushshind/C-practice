// Write a program to create binary tree.Find height of the tree and print
// leaf nodes.Find mirror image,print original and mirror image using level-wise printing.

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *right, *left;
};
struct node *createnode(int key)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = key;
    newnode->left = NULL;
    newnode->right = NULL;
    return (newnode);
}
int mirrorimage(struct node *root)
{
    if (root != NULL)
    {
        struct node *temp;
        mirrorimage(root->right);
        mirrorimage(root->left);
        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
}
int height(struct node *root)
{
    int max;
    if (root != NULL)
    {
        int leftsubtree = height(root->left);
        int rightsubtree = height(root->right);
        if (leftsubtree > rightsubtree)
        {
            max = leftsubtree + 1;
            return max;
        }
        else
        {
            max = rightsubtree + 1;
            return max;
        }
    }
}
void Displayinorder(struct node *root)
{
    if (root == NULL)
        return;
    Displayinorder(root->left);
    printf("%d ", root->data);
    Displayinorder(root->right);
}
void printleafnodes(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        printf("\t%d", root->data);
    }
    printleafnodes(root->left);
    printleafnodes(root->right);
}
int main()
{
    struct node *root = createnode(10);
    root->left = createnode(20);
    root->left->left = createnode(40);
    root->left->right = createnode(50);
    root->right = createnode(30);
    root->right->left = createnode(60);
    root->right->right = createnode(70);
    printf("\n original Tree:");
    Displayinorder(root);
    printf("\n");
    printf("\n");
    int max = height(root);
    printf("Height=%d", max);
    printf("\n");
    printf("\n Mirror image:");
    Displayinorder(mirrorimage(root));
    printf("\n");
    printf("\n Leaf nodes:");
    printleafnodes(root);
    return 0;
}
