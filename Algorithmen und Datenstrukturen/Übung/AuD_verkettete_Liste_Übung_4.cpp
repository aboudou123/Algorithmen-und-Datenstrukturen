#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct liste
{ int listenelement;
  liste *next;
};

void listenerror(const char *message)
{ printf("%s\n",message);
  system("PAUSE");
  exit(1);
};

liste* tail(liste *listpointer)
{ liste *hilfspointer;
  if (listpointer == NULL)
     listenerror("Fehler: tail aufgerufen mit Nullpointer!\n");
  else 
  { hilfspointer = listpointer->next;
    delete listpointer; // Freigabe des Speichers
    return hilfspointer;
  };   
};

int head(liste *listpointer)
{ if (listpointer == NULL)
     listenerror("Fehler: head aufgerufen mit Nullpointer!\n");
  else return listpointer->listenelement;
}; 

liste* append(liste *listpointer, int i)
{ liste *hilfspointer = new liste;
  hilfspointer->listenelement = i;
  hilfspointer->next = listpointer;
  return hilfspointer;
};       
     
liste* emptyliste()  // Anlegen einer leeren Liste
{ return NULL;
};

int isempty(liste * listpointer)  // Liste Leer
{ return(listpointer == NULL);
};

void listenausgabe(liste *listpointer)
{ int counter=1;
  liste *hilfspointer = listpointer;
  if (isempty(listpointer))
    printf("Liste ist leer\n");
  else while (hilfspointer != NULL)
         { printf("%d%s%d\n",counter,"-tes Element: ",hilfspointer->listenelement);
           hilfspointer = hilfspointer->next;
           counter++;
         };
};

liste* anfuegen_hinten_nr(liste *listpointer, int i)
{ /* Hier neue Funktion einfuegen */
  printf("nicht rekursive Funktion zum Anfuegen hinten noch nicht implementiert\n"); 
  return listpointer;
};      

liste* anfuegen_hinten_r(liste *listpointer, int i)
{ /* Hier neue Funktion einfuegen */
  printf("rekursive Funktion zum Anfuegen hinten noch nicht implementiert\n"); 
  return listpointer;
};  
    
void listentest(liste *listpointer)
{
    char steuerung = 'x';
    int i;
    while ((steuerung != 'e') || (steuerung != 'E'))
    { printf("Bitte Eingabe: H=Head, A=Append, T = Tail, P = Ausgabe, I = Isempty, E = Ende\n");
      printf("Z=Anfuegen am Ende (nicht rekursiv), R= Anfuegen am Ende (rekursiv)\n");
      fflush(stdin);
      scanf("%c",&steuerung);
      switch (steuerung)
      { case 'h':
        case 'H': i = head(listpointer);
                  printf("%s%d\n","Headelement: ", i); 
                  break;
        case 'a':
        case 'A': printf("Bitte Zahl eingeben:\n");
                  fflush(stdin);
                  scanf("%d",&i);
                  listpointer = append(listpointer,i);
                  break;
        case 't':
        case 'T': listpointer = tail(listpointer);
                  break;
        case 'P':
        case 'p': listenausgabe(listpointer);
                  break;
        case 'I':
        case 'i': if (isempty(listpointer))
                    printf("Liste ist leer\n");
                  else printf("Liste ist nicht leer\n");
                  break;
        case 'z':
        case 'Z': printf("Bitte Zahl eingeben:\n");
                  fflush(stdin);
                  scanf("%d",&i);
                  listpointer = anfuegen_hinten_nr(listpointer, i);
                  break;
        case 'r':
        case 'R': printf("Bitte Zahl eingeben:\n");
                  fflush(stdin);
                  scanf("%d",&i);
                  listpointer = anfuegen_hinten_r(listpointer, i);
                  break;                  
        case 'E':
        case 'e': printf("Auf Wiedersehen!\n");
                  return;
        default:  break;
      };
    };
}         
  
    
int main(void) 
{ liste *sp = emptyliste();
  listentest(sp);
  system("PAUSE");
  return 0;
}
