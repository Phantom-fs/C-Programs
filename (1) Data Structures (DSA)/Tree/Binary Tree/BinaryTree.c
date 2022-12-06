//Menu based program on Binary Tree 
//Creation, Insertion, Deletion, Display, Search, Traversal, Count
//coder: Phantom-fs

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//Binary Tree
typedef struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
} tree;

//creating a tree pointer root, which will point to tree we will create (currently null)
tree *root = NULL;

//function to create a tree
tree* createTree (int data)
{
    tree *newTree = (tree*)malloc(sizeof(tree));
    newTree->data = data;
    newTree->left = NULL;
    newTree->right = NULL;
    return newTree;
}

//function to insert an element in tree
tree* insert (int data)
{
    //if tree is empty
    if (root == NULL)
    {
        root = (tree *)malloc(sizeof(tree));
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        return root;
    }

    //if tree is not empty
    tree *temp = root;

    while (1)
    {
        if (data < temp->data)
        {
            if (temp->left == NULL)
            {
                temp->left = createTree(data);
                return temp->left;
            }
            else
            {
                temp = temp->left;
            }
        }
        else
        {
            if (temp->right == NULL)
            {
                temp->right = createTree(data);
                return temp->right;
            }
            else
            {
                temp = temp->right;
            }
        }
    }
}

//function to delete an element from tree
void delete (int data)
{
    //if tree is empty
    if (root == NULL)
    {
        printf("\nTree is empty\n");
        return;
    }

    //if tree is not empty
    tree *temp = (tree *)malloc(sizeof(tree));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return;
}

//function to search an element in tree
void search (int data)
{
    //if tree is empty
    if (root == NULL)
    {
        printf("\nTree is empty\n");
        return;
    }

    //if tree is not empty
    tree *temp = root;

    while (1)
    {
        if (data < temp->data)
        {
            if (temp->left == NULL)
            {
                printf("\nElement not found\n");
                return;
            }
            else
            {
                temp = temp->left;
            }
        }
        else if (data > temp->data)
        {
            if (temp->right == NULL)
            {
                printf("\nElement not found\n");
                return;
            }
            else
            {
                temp = temp->right;
            }
        }
        else
        {
            printf("\nElement found\n");
            return;
        }
    }
}

//traverse tree in preorder
void preorder (tree *root)
{
    if (root == NULL)
    {
        return;
    }

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

//traverse tree in inorder
void inorder (tree *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

//traverse tree in postorder
void postorder (tree *root)
{
    if (root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

//count number of nodes in tree
int countNodes (tree *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
}

//count number of leaves in tree
int countLeaves (tree *root)
{
    if (root == NULL)
    {
        return 0;
    }

    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }

    return countLeaves(root->left) + countLeaves(root->right);
}

int main()
{
    int choice, data;

    while (1)
    {
        printf("\n1. Create Tree (new tree will be created every time)");
        printf("\n2. Insert");
        printf("\n3. Delete");
        printf("\n4. Search");
        printf("\n5. Traverse in Preorder");
        printf("\n6. Traverse in Inorder");
        printf("\n7. Traverse in Postorder");
        printf("\n8. Count Nodes");
        printf("\n9. Count Leaves");
        printf("\n10. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        printf("\n");

        switch (choice)
        {
            case 1:
                printf("\nEnter data: ");
                scanf("%d", &data);
                root = createTree(data);
                break;

            case 2:
                printf("\nEnter data: ");
                scanf("%d", &data);
                insert(data);
                break;

            case 3:
                printf("\nEnter data: ");
                scanf("%d", &data);
                delete(data);
                break;

            case 4:
                printf("\nEnter data: ");
                scanf("%d", &data);
                search(data);
                break;

            case 5:
                preorder(root);
                break;

            case 6:
                inorder(root);
                break;

            case 7:
                postorder(root);
                break;

            case 8:
                printf("\nNumber of nodes: %d", countNodes(root));
                break;

            case 9:
                printf("\nNumber of leaves: %d", countLeaves(root));
                break;

            case 10:
                exit(0);

            default:
                printf("\nInvalid choice\n");
        }

        sleep(2);
        printf("\n");
    }
}
