//Code Made By
//11EC10001

#include <stdio.h>
#include <stdlib.h>

#define MAXCHILD 50
#define MAXTREES 50
#define STACKSIZE 500
#define NULL 0

struct orchard_treenode
{
    int info;
    struct orchard_treenode *child[MAXCHILD];
};
typedef struct orchard_treenode *NODEPTR_ORCHARD;

struct binary_treenode
{
    int info;
    struct binary_treenode *left;
    struct binary_treenode *right;
};
typedef struct binary_treenode *NODEPTR_BINARY;

NODEPTR_BINARY getnode_binary();
NODEPTR_ORCHARD getnode_orchard();
NODEPTR_ORCHARD create_first_tree();
NODEPTR_ORCHARD create_second_tree();
NODEPTR_ORCHARD create_third_tree();
NODEPTR_ORCHARD create_fourth_tree();
NODEPTR_BINARY convert_orchard_to_binary(NODEPTR_ORCHARD trees[MAXTREES],int length_trees);
NODEPTR_BINARY convert_to_binary(NODEPTR_ORCHARD tree);
void print_bin_tree(NODEPTR_BINARY root);

int main()
{
    NODEPTR_ORCHARD tree1,tree2,tree3,tree4;

    //First of all we have to make the orchard as it is our input

    //Making first input tree with root 1
    tree1 = create_first_tree();

    //Making second input tree with root 11
    tree2 = create_second_tree();

    //Making third input tree with root 14
    tree3 = create_third_tree();

    //Making fourth input tree with root 22
    tree4 = create_fourth_tree();

    //Now convert into binary tree
    NODEPTR_ORCHARD trees[MAXTREES]; //this array will store the root of all the trees
    trees[0] = tree1;
    trees[1] = tree2;
    trees[2] = tree3;
    trees[3] = tree4;
    trees[4] = NULL;

    int num_of_trees; //number of trees in orchard
    num_of_trees = 4;

    NODEPTR_BINARY root;
    root = convert_orchard_to_binary(trees,num_of_trees);

    print_bin_tree(root);

    return 0;
}

NODEPTR_ORCHARD create_first_tree()
{
    NODEPTR_ORCHARD root;
    int i;
    root = getnode_orchard();
    NODEPTR_ORCHARD temp[9];
    for (i = 0; i<9; i++)
    {
        temp[i] = getnode_orchard();
    }

    root->info = 1;
    root->child[0] = temp[0];
    root->child[1] = temp[1];
    root->child[2] = temp[2];
    root->child[3] = NULL;// this marks the end of child for this node

    temp[0]->info = 2;
    temp[0]->child[0] = temp[3];
    temp[0]->child[1] = temp[4];
    temp[0]->child[2] = NULL; // this marks the end of child for this node
    temp[3]->info = 5;
    temp[3]->child[0] = NULL;// the leaf node has no child so child[0] = NULL
    temp[4]->info = 6;
    temp[4]->child[0] = NULL; // the leaf node has no child so child[0] = NULL

    temp[1]->info = 3;
    temp[1]->child[0] = temp[5];
    temp[1]->child[1] = NULL;// this marks the end of child for this node
    temp[5]->info = 7;
    temp[5]->child[0] = NULL;// the leaf node has no child so child[0] = NULL

    temp[2]->info = 4;
    temp[2]->child[0] = temp[6];
    temp[2]->child[1] = temp[7];
    temp[2]->child[2] = temp[8];
    temp[2]->child[3] = NULL;// this marks the end of child for this node
    temp[6]->info = 8;
    temp[6]->child[0] = NULL;// the leaf node has no child so child[0] = NULL
    temp[7]->info = 9;
    temp[7]->child[0] = NULL;// the leaf node has no child so child[0] = NULL
    temp[8]->info = 10;
    temp[8]->child[0] = NULL;// the leaf node has no child so child[0] = NULL

    return (root);
}

NODEPTR_ORCHARD create_second_tree()
{
    NODEPTR_ORCHARD root;
    int i;
    root = getnode_orchard();
    NODEPTR_ORCHARD temp[2];
    for (i = 0; i<2; i++)
    {
        temp[i] = getnode_orchard();
    }

    root->info = 11;
    root->child[0] = temp[0];
    root->child[1] = NULL;// this marks the end of child for this node

    temp[0]->info = 12;
    temp[0]->child[0] = temp[1];
    temp[0]->child[1] = NULL;// this marks the end of child for this node
    temp[1]->info = 13;
    temp[1]->child[0] = NULL;// the leaf node has no child so child[0] = NULL

    return (root);
}

NODEPTR_ORCHARD create_third_tree()
{
    NODEPTR_ORCHARD root;
    int i;
    root = getnode_orchard();
    NODEPTR_ORCHARD temp[7];
    for (i = 0; i<7; i++)
    {
        temp[i] = getnode_orchard();
    }

    root->info = 14;
    root->child[0] = temp[0];
    root->child[1] = NULL;// this marks the end of child for this node

    temp[0]->info = 15;
    temp[0]->child[0] = temp[1];
    temp[0]->child[1] = temp[2];
    temp[0]->child[2] = NULL;// this marks the end of child for this node

    temp[1]->info = 16;
    temp[1]->child[0] = temp[3];
    temp[1]->child[1] = temp[4];
    temp[1]->child[2] = NULL;// this marks the end of child for this node
    temp[3]->info = 18;
    temp[3]->child[0] = NULL;// the leaf node has no child so child[0] = NULL
    temp[4]->info = 19;
    temp[4]->child[0] = NULL;// the leaf node has no child so child[0] = NULL

    temp[2]->info = 17;
    temp[2]->child[0] = temp[5];
    temp[2]->child[1] = temp[6];
    temp[2]->child[2] = NULL;// this marks the end of child for this node
    temp[5]->info = 20;
    temp[5]->child[0] = NULL;// the leaf node has no child so child[0] = NULL
    temp[6]->info = 21;
    temp[6]->child[0] = NULL;// the leaf node has no child so child[0] = NULL

    return (root);
}

NODEPTR_ORCHARD create_fourth_tree()
{
    NODEPTR_ORCHARD root;
    int i;
    root = getnode_orchard();
    NODEPTR_ORCHARD temp[8];
    for (i = 0; i<8; i++)
    {
        temp[i] = getnode_orchard();
    }

    root->info = 22;
    root->child[0] = temp[0];
    root->child[1] = temp[1];
    root->child[2] = temp[2];
    root->child[3] = NULL;// this marks the end of child for this node

    temp[0]->info = 23;
    temp[0]->child[0] = temp[3];
    temp[0]->child[1] = NULL;// this marks the end of child for this node
    temp[3]->info = 26;
    temp[3]->child[0] = NULL;// the leaf node has no child so child[0] = NULL

    temp[1]->info = 24;
    temp[1]->child[0] = temp[4];
    temp[1]->child[1] = temp[5];
    temp[1]->child[2] = NULL;// this marks the end of child for this node
    temp[4]->info = 27;
    temp[4]->child[0] = NULL;// the leaf node has no child so child[0] = NULL
    temp[5]->info = 28;
    temp[5]->child[0] = NULL;// the leaf node has no child so child[0] = NULL

    temp[2]->info = 25;
    temp[2]->child[0] = temp[6];
    temp[2]->child[1] = NULL;// this marks the end of child for this node
    temp[6]->info = 29;
    temp[6]->child[0] = temp[7];
    temp[6]->child[1] = NULL;// this marks the end of child for this node
    temp[7]->info = 30;
    temp[7]->child[0] = NULL;// the leaf node has no child so child[0] = NULL

    return (root);
}


NODEPTR_BINARY convert_orchard_to_binary(NODEPTR_ORCHARD trees[MAXTREES],int num_of_trees)
{
    NODEPTR_BINARY root;
    root = getnode_binary();
    NODEPTR_BINARY root_array[num_of_trees];
    int i = 0;

    for(i = 0; i<num_of_trees; i++)
    {
        root_array[i] = convert_to_binary(trees[i]); // convert individual tree to binary tree
    }
    for(i=0;i<num_of_trees-1;i++)
    {
        root_array[i]->right = root_array[i+1]; // connect all the four binary trees together into one binary tree
    }
    root = root_array[0];
    return (root);
}

NODEPTR_BINARY convert_to_binary(NODEPTR_ORCHARD tree)
{
    NODEPTR_BINARY root;
    NODEPTR_BINARY p_bin;
    NODEPTR_ORCHARD p_orch;
    NODEPTR_ORCHARD array_orch[STACKSIZE];
    NODEPTR_BINARY array_bin[STACKSIZE];
    int stack_i = 0;

    p_bin = getnode_binary();
    root = p_bin;
    p_orch = tree;
    p_bin->info = p_orch->info;

    array_bin[0] = p_bin; //push p_bin
    array_orch[0] = p_orch;//push p_orch
    int k = 0;
    do
    {
        p_orch = array_orch[stack_i]; //pop array_orch
        p_bin = array_bin[stack_i];   //pop array_bin
        stack_i = stack_i - 1; //decrement stack size
        if (p_orch->child[0]!=NULL)
        {
            //make the first child as the left child
            p_bin->left = getnode_binary();
            p_bin->left->info = p_orch->child[0]->info;
            stack_i++; // increment stack size
            array_orch[stack_i] = p_orch->child[0]; //push
            array_bin[stack_i] =  p_bin->left; //push
            p_bin = p_bin->left; //update p_bin

            //make all the other child as the right child
            k = 1;
            while(p_orch->child[k]!=NULL)
            {
                p_bin->right = getnode_binary();
                p_bin->right->info = p_orch->child[k]->info;
                p_bin = p_bin->right;
                stack_i++; // increment stack size
                array_orch[stack_i] = p_orch->child[k]; //push
                array_bin[stack_i] = p_bin; //push
                k = k+1;
            }
        }
    }
    while(stack_i!=-1); // repeat while stack is not empty

    return (root);
}

void print_bin_tree(NODEPTR_BINARY root)
{
    NODEPTR_BINARY p;
    p = root;
    int stack_i = 0;
    NODEPTR_BINARY stack_array[STACKSIZE];
    stack_array[0] = p; //push
    do
    {
        p = stack_array[stack_i]; //pop
        stack_i = stack_i - 1; //decrement stack size
        if ((p->left!= NULL) && (p->right!=NULL))
        {
            printf("For Node:%d :: Left-Child:%d :: Right-Child:%d\n",p->info,p->left->info,p->right->info);
            stack_i++; // increment stack size
            stack_array[stack_i] = p->right; //push
            stack_i++; // increment stack size
            stack_array[stack_i] = p->left;//push
        }
        else if((p->left==NULL) && (p->right==NULL))
        {
            printf("For Node:%d :: Left-Child:NULL :: Right-Child:NULL\n",p->info);
        }
        else if(p->left==NULL)
        {
            printf("For Node:%d :: Left-Child:NULL :: Right-Child:%d\n",p->info,p->right->info);
            stack_i++; // increment stack size
            stack_array[stack_i] = p->right; //push
        }
        else
        {
            printf("For Node:%d :: Left-Child:%d :: Right-Child:NULL\n",p->info,p->left->info);
            stack_i++; // increment stack size
            stack_array[stack_i] = p->left; //push
        }
    }
    while(stack_i != -1); //repeat while stack is not empty
}

NODEPTR_ORCHARD getnode_orchard()
{
    NODEPTR_ORCHARD p;
    p = (NODEPTR_ORCHARD)malloc(sizeof(struct orchard_treenode));
    return (p);
}

NODEPTR_BINARY getnode_binary()
{
    NODEPTR_BINARY p;
    p = (NODEPTR_BINARY)malloc(sizeof(struct binary_treenode));
    p->left = NULL;
    p->right = NULL;
    return (p);
}

