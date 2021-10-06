#include <iostream> 

typedef struct node
{
    unsigned int key;
    struct node *left;
    struct node *right;
} node ;

node *creat_elem(int key)
{
    node *elem = new(node);

    elem->key = key;
    elem->left = NULL;
    elem->right = NULL;
    return elem;
}

void printTree(node *tree)
{
    /*si mon arbre est vide on imprime rien */
    if(!tree) return;


    if(tree->left)  printTree(tree->left);

    std::cout << "Cle = " <<  tree->key << std::endl;

    if(tree->right) printTree(tree->right);
}

void addNode(node **tree, unsigned int key)
{
    node *tmpNode;
    node *tmpTree  = *tree;


    /*fonction pour creer un maillon*/
    node *elem = creat_elem(key);

    /*si mon arbre n'est pas vide*/
    if(tmpTree)
    do
    {
        tmpNode = tmpTree;
        /* si la cle est plus grande le pointeur right sera appeler */
        if(key > tmpTree->key )
        {
            tmpTree = tmpTree->right;
            /*juste pour savoir si le maillon regarder est NULL si elle est pas null cest que on est pas a la fin de l'arbre*/
            if(!tmpTree) tmpNode->right = elem;
        }

        else
        {
            /* si la cle est plus petite le pointeur left sera appeler */
            tmpTree = tmpTree->left;
            /*juste pour savoir si le maillon regarder est NULL si elle est pas null cest que on est pas a la fin de l'arbre*/
            if(!tmpTree) tmpNode->left = elem;
        }
    }
    while(tmpTree);
    /*si mon arbre est vide il devient l'element*/
    else  *tree = elem;
}

void    clear_tree(node *tree)
{

    if(!tree) return;

    if(tree->left)  clear_tree(tree->left);

    if(tree->right) clear_tree(tree->right);
        
    delete(tree);

    tree = NULL;
}

int main(void)
{
    node *Arbre = NULL;

    addNode(&Arbre, 10);

    addNode(&Arbre, 20);
    addNode(&Arbre, 4);
    addNode(&Arbre, 3);
    addNode(&Arbre, 8);
    printTree(Arbre);
    clear_tree(Arbre);
    return (0);
}