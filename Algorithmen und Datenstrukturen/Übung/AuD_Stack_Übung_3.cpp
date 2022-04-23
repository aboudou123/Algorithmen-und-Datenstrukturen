#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int Maxpegel = 1000; // Maximale Stackgröße

typedef struct stack
{ int stackfield[Maxpegel]; // Array, das den Stack simuliert
  int pegel; // Füllstandspegel des Stack
};

void stackerror(const char *message)
/********************************************/
/* Ausgabe Fehlertext                       */
/********************************************/
{ printf("%s\n",message);
  system("PAUSE");
  exit(1);
};

stack* pop(stack *stackpointer)
/********************************************/
/* Entfernen des obersten Elements          */
/* Stack darf nicht leer sein               */
/********************************************/
{ if (stackpointer == NULL)
     stackerror("Fehler: pop aufgerufen mit Nullpointer!\n");
  else if (stackpointer->pegel>0)
         { stackpointer->pegel--;
           return stackpointer;
         } 
       else stackerror("Fehler: pop aufgerufen mit leerem Stack!\n"); 
};

int top(stack *stackpointer)
/********************************************/
/* liefert oberstes Element des Stack       */
/* Stack darf nicht leer sein               */
/********************************************/
{ if (stackpointer == NULL)
     stackerror("Fehler: top aufgerufen mit Nullpointer!\n");
  else if (stackpointer->pegel>0)
         return(stackpointer->stackfield[stackpointer->pegel-1]);
       else stackerror("Fehler: top aufgerufen mit leerem Stack!\n"); 
}; 

stack* push(stack *stackpointer, int i)
/********************************************/
/* Anfügen eines Elements oben auf dem      */
/* Stack                                    */
/********************************************/
{ if (stackpointer == NULL)
     stackerror("Fehler: push aufgerufen mit Nullpointer!\n");
  else if (stackpointer->pegel == Maxpegel)
         stackerror("Fehler: push aufgerufen mit vollem Stack!\n");
       else 
       { stackpointer->stackfield[stackpointer->pegel] = i;
         stackpointer->pegel++;
         return stackpointer;
       };
};

stack* emptystack()
/********************************************/
/* liefert leeren Stack                     */
/********************************************/
{ stack *stackpointer = new stack; // Dynamische Speicherpaltzanforderung für einen Stack
  stackpointer->pegel = 0; // Stack ist noch leer
  return stackpointer;
};

int isempty(stack *stackpointer)
/********************************************/
/* stellt fest, ob Stack leer ist           */
/********************************************/
{ if (stackpointer == NULL)
    stackerror("Fehler: Isempty aufgerufen mit Nullpointer\n");
  else return(stackpointer->pegel == 0);
};

void stackausgabe(stack *stackpointer)
/********************************************/
/* gibt Elemente des Stack aus              */
/********************************************/
{ int counter;
  if (stackpointer == NULL)
    printf("Stackpointer ist NULL\n");
  else if (stackpointer->pegel == 0)
          printf("Stack ist leer\n");
       else for (counter = stackpointer->pegel; counter > 0; counter--)
              printf("%d%s%d\n",counter,"-tes Element: ",stackpointer->stackfield[counter-1]);
};      

int zaehleelemente(stack *stackpointer)
/********************************************/
/* liefert Anzahl der Stackelemente         */
/********************************************/
{ printf("Die Funktion zaehleelemente ist noch nicht implementiert \n");
  return 0;
};

int zaehleelemente2(stack *stackpointer)
/********************************************/
/* liefert Anzahl der Stackelemente         */
/********************************************/
{ if (isempty(stackpointer))
    return 0;
    else return zaehleelemente2(pop(stackpointer))+1;
};

int sucheelement(stack *stackpointer, int i)
/********************************************/
/* stellt fest, ob i im Stack enthalten     */
/********************************************/
{ printf("Die Funktion sucheelement ist noch nicht implementiert \n");
  return 0;  
};     


void stacktest(stack *stackpointer)
{
    char steuerung = 'x';
    int i;
    while ((steuerung != 'e') || (steuerung != 'E'))
    { printf("Bitte Eingabe: T=Top, P=Push, O = Pop, A = Ausgabe\n");
      printf("               I = Isempty, Z = Zaehlen, S = Suchen, E = Ende\n");

      fflush(stdin);
      scanf("%c",&steuerung);
      switch (steuerung)
      { case 't':
        case 'T': i = top(stackpointer);
                  printf("%s%d\n","Topelement: ", i); 
                  break;
        case 'P':
        case 'p': printf("Bitte Zahl eingeben:\n");
                  fflush(stdin);
                  scanf("%d",&i);
                  stackpointer = push(stackpointer,i);
                  break;
        case 'S':
        case 's': printf("Bitte zu suchende Zahl eingeben:\n");
                  fflush(stdin);
                  scanf("%d",&i);
                  if (sucheelement(stackpointer, i))
                    printf("Gesuchtes Element gefunden.\n");
                  else printf("Gesuchtes Element nicht gefunden.\n");
                  break;                    
        case 'O':
        case 'o': stackpointer = pop(stackpointer);
                  break;
        case 'A':
        case 'a': stackausgabe(stackpointer);
                  break;
        case 'I':
        case 'i': if (isempty(stackpointer))
                    printf("Stack ist leer\n");
                  else printf("Stack ist nicht leer\n");
                  break;
        case 'Z':
        case 'z': printf("%s%d\n", "Anzahl Elemente im Stack: ",zaehleelemente2(stackpointer));
                  break;       
        case 'E':
        case 'e': printf("Auf Wiedersehen!\n");
                  return;
        default:  break;
      };
    };
}
    
int main(void) 
{ stack *sp = emptystack();
  stacktest(sp);
  system("PAUSE");
  return 0;
}
