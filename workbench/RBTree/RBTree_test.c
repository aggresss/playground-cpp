#include "RBTree.h"

#include <stdio.h>
#include <stdlib.h>

int check(Tree *t)
{
    Node* curnode = NULL;
    int rc = 0;

    curnode = TreeNextElement(t, curnode);
    while (curnode)
    {
        Node* prevnode = curnode;

        curnode = TreeNextElement(t, curnode);

        if (prevnode && curnode && (*(int*)(curnode->content) < *(int*)(prevnode->content)))
        {
            printf("out of order %d < %d\n", *(int*)(curnode->content), *(int*)(prevnode->content));
            rc = 99;
        }
    }
    return rc;
}


int traverse(Tree *t, int lookfor)
{
    Node* curnode = NULL;
    int rc = 0;

    printf("Traversing\n");
    curnode = TreeNextElement(t, curnode);
    /* printf("content int %d\n", *(int*)(curnode->content)); */
    while (curnode)
    {
        Node* prevnode = curnode;

        curnode = TreeNextElement(t, curnode);
        /* if (curnode)
            printf("content int %d\n", *(int*)(curnode->content)); */
        if (prevnode && curnode && (*(int*)(curnode->content) < *(int*)(prevnode->content)))
        {
            printf("out of order %d < %d\n", *(int*)(curnode->content), *(int*)(prevnode->content));
        }
        if (curnode && (lookfor == *(int*)(curnode->content)))
            printf("missing item %d actually found\n", lookfor);
    }
    printf("End traverse %d\n", rc);
    return rc;
}


int test(int limit)
{
    int i, *ip, *todelete;
    Node* current = NULL;
    Tree* t = TreeInitialize(TreeIntCompare);
    int rc = 0;

    printf("Tree initialized\n");

    srand(time(NULL));

    ip = malloc(sizeof(int));
    *ip = 2;
    TreeAdd(t, (void*)ip, sizeof(int));

    check(t);

    i = 2;
    void* result = TreeRemove(t, (void*)&i);
    if (result)
        free(result);

    int actual[limit];
    for (i = 0; i < limit; i++)
    {
        void* replaced = NULL;

        ip = malloc(sizeof(int));
        *ip = rand();
        replaced = TreeAdd(t, (void*)ip, sizeof(int));
        if (replaced) /* duplicate */
        {
            free(replaced);
            actual[i] = -1;
        }
        else
            actual[i] = *ip;
        if (i==5)
            todelete = ip;
        printf("Tree element added %d\n",  *ip);
        if (1 % 1000 == 0)
        {
            rc = check(t);
            printf("%d elements, check result %d\n", i+1, rc);
            if (rc != 0)
                return 88;
        }
    }

    check(t);

    for (i = 0; i < limit; i++)
    {
        int parm = actual[i];

        if (parm == -1)
            continue;

        Node* found = TreeFind(t, (void*)&parm);
        if (found)
            printf("Tree find %d %d\n", parm, *(int*)(found->content));
        else
        {
            printf("%d not found\n", parm);
            traverse(t, parm);
            return -2;
        }
    }

    check(t);

    for (i = limit -1; i >= 0; i--)
    {
        int parm = actual[i];
        void *found;

        if (parm == -1) /* skip duplicate */
            continue;

        found = TreeRemove(t, (void*)&parm);
        if (found)
        {
            printf("%d Tree remove %d %d\n", i, parm, *(int*)(found));
            free(found);
        }
        else
        {
            int count = 0;
            printf("%d %d not found\n", i, parm);
            traverse(t, parm);
            for (i = 0; i < limit; i++)
                if (actual[i] == parm)
                    ++count;
            printf("%d occurs %d times\n", parm, count);
            return -2;
        }
        if (i % 1000 == 0)
        {
            rc = check(t);
            printf("%d elements, check result %d\n", i+1, rc);
            if (rc != 0)
                return 88;
        }
    }
    printf("finished\n");
    return 0;
}

int main(int argc, char *argv[])
{
    int rc = 0;

    while (rc == 0)
        rc = test(999999);
}
