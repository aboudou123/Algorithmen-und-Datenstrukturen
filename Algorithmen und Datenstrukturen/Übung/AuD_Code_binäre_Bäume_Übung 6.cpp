#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct b_tree
{ int treeelement;
  b_tree *left;
  b_tree *right;
};

void b_treeerror(const char *message)
{ printf("%s\n",message);
  system("PAUSE");
  exit(1);
};

b_tree* copytree(b_tree *treepointer)
{ b_tree *t_pointer;
  if (treepointer == NULL)
    return NULL;
  else
  { t_pointer = (b_tree*)malloc(sizeof(b_tree));
    t_pointer->treeelement = treepointer->treeelement;
    t_pointer->left=copytree(treepointer->left);
    t_pointer->right=copytree(treepointer->right);
    return t_pointer;
  };
}; 

b_tree* left(b_tree *treepointer)
{ if (treepointer == NULL)
      b_treeerror("Fehler: left aufgerufen mit Nullpointer!\n");
  else return copytree(treepointer->left);
};

b_tree* right(b_tree *treepointer)
{ if (treepointer == NULL)
      b_treeerror("Fehler: right aufgerufen mit Nullpointer!\n");
  else return copytree(treepointer->right);
};

void delete_tree(b_tree *treepointer)
{ if (treepointer != NULL)
  { delete_tree(treepointer->left);
    delete_tree(treepointer->right);
    free(treepointer);
  };
  return;
}
    
b_tree* emptytree()  // Anlegen eines leeren Baums
{ return NULL;
};

int isemptytree(b_tree* treepointer)  // Baum Leer
{ return(treepointer == NULL);
};

b_tree* b_tree_new (b_tree *left, int e, b_tree *right)
{ b_tree* t_pointer = (b_tree*) malloc(sizeof(b_tree));
  t_pointer->left = copytree(left);
  t_pointer->right = copytree(right);
  t_pointer->treeelement = e;
  return t_pointer;
};

int element(b_tree *treepointer)
{ if (treepointer == NULL)
    b_treeerror("Element aufgerufen mit Nullpointer");
  else return treepointer->treeelement;
};
                
void treeoutput(b_tree *treepointer)
{   if (isemptytree(treepointer))
      printf("leer\n");
    else 
    { printf("%d\n",treepointer->treeelement);
      printf("%c",'(');
      treeoutput(treepointer->left);
      printf("%c",')');
      printf("%c",'(');
      treeoutput(treepointer->right);
      printf("%c",')');
    };
};      

int Anzahl_Knoten(b_tree *b)
{ /* Hier Code einfügen */
  return 0; 
};  

int Anzahl_Blaetter(b_tree *b)
{ /* Hier Code einfügen */
  return 0;
};  

int max(int a, int b)
/* Maximum zweier Zahlen */
{ if (a>b)
     return a;
  else return b;
};

int Hoehe(b_tree *b)
{ /* Hier Code einfügen */
  return 0;
};


void treetest()
{ 
    /* Hier wird zunächst ein leerer Baum angelgt. Mit diesem können die
       zu erstellenden Funktionen getestet werden */
       
       b_tree *sp = emptytree();
       printf("Anzahl Knoten eines leeren Baums: %d\n", Anzahl_Knoten(sp));

       printf("Anzahl Blaetter eines leeren Baums: %d\n", Anzahl_Blaetter(sp));

       printf("Hoehe eines leeren Baums: %d\n", Hoehe(sp));

       /* Dann wird ein Baum mit einem Knoten angelgt. Mit diesem können die
       zu erstellenden Funktionen erneut getestet werden */
       
       b_tree *t1 = emptytree();
       b_tree *t2 = emptytree();
       
       sp = b_tree_new(t1, 5, t2);
       
       printf("Anzahl Knoten eines Baums mit einem Knoten: %d\n", Anzahl_Knoten(sp));

       printf("Anzahl Blaetter eines Baums mit einem Knoten: %d\n", Anzahl_Blaetter(sp));

       printf("Hoehe eines Baums mit einem Knoten: %d\n", Hoehe(sp));
       
       /* Hier wird ein Baum mit ingesamt 11 Elementen aufgebaut. Mit diesem können die
       Funktionen getestet werden */
       
       b_tree *sp1 = b_tree_new(emptytree(), 1, emptytree());
       b_tree *sp3 = b_tree_new(emptytree(), 3, emptytree());
       b_tree *sp5 = b_tree_new(emptytree(), 5, emptytree());
       b_tree *sp7 = b_tree_new(emptytree(), 7, emptytree());
       b_tree *sp9 = b_tree_new(emptytree(), 9, emptytree());
       b_tree *sp11 = b_tree_new(emptytree(), 11, emptytree());
       b_tree *sp13 = b_tree_new(emptytree(), 13, emptytree());
       b_tree *sp15 = b_tree_new(emptytree(), 15, emptytree());
       
       b_tree *sp2 = b_tree_new(sp1, 2, sp3);
       b_tree *sp6 = b_tree_new(sp5, 6, sp7);
       b_tree *sp10 = b_tree_new(sp9, 10, sp11);
       b_tree *sp14  = b_tree_new(sp13, 14, sp15);
       b_tree *sp4  = b_tree_new(sp2, 4, sp6);
       b_tree *sp12  = b_tree_new(sp10, 12, sp14);
       b_tree *sp8  = b_tree_new(sp4, 8, sp12);
       
       printf("Anzahl Knoten eines Baums mit 15 Knoten: %d\n", Anzahl_Knoten(sp8));

       printf("Anzahl Blaetter eines Baums mit 15 Knoten: %d\n", Anzahl_Blaetter(sp8));

       printf("Hoehe eines Baums mit 15 Knoten: %d\n", Hoehe(sp8));
}
    
int main(void) 
{ b_tree *sp = emptytree();
  treetest();
  system("PAUSE");
  return 0;
}
