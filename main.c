// Heiko


#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// 1 - creer une fonction qui prend la variable solution, et la variable tableauJoueur (par exemple) : un tableau rempli de 0, cette fonction doit copier certaines valeurs (grace au rand() % N) 
// de solution dans tableauJoueur afin d'initialiser une grille jouable ( car solution est bel est bien la solution, donc pas jouable par définition. ).
// un parametre doit permettre de verifier la condition de victoire en un seul coup (proposer votre façon de faire :) ) 

void copyArray(int tab[8][8], int copy[8][8] ){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            copy[i][j] = tab[i][j];
        }
    }
}



void genGrilleJouable(int soluce[8][8], int tableauJoueur[8][8], int oneshot){

    if (oneshot)
    {
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                tableauJoueur[i][j] = soluce[i][j];    
            }
            
        }

        tableauJoueur[0][0] = 2;
        
    }
    else{

        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if ((rand() % 100) < 50)
                {
                    tableauJoueur[i][j] = soluce[i][j];
                }
                
            }
            
        }
    }
    //return tableauJoueur;
}




// 2- une fonction saisir qui demande au joueur de saisir 3 informations: i, j , et v qui permettront de placer la valeur v aux coordonnées (i,j)





// 3- apres chaque coordonnées il faut verifier les regles du sudoku sur le tableauJoueur donc : 

    // - la fonction verifierLigneColonne ( qui verifie les lignes et les colonnes  sur lesquelles sont la nouvelle valeur)
    // - la fonction verifierGrille (qui fait ceci pour toute la grille et permet de definir la condition de victoire)

int verifierLigneColonne(int tableau[8][8], int ligneOuCol, int num){
    int tab[8] = {2,2,2,2,2,2,2,2};

    int res = 1;
    int equal = 0;
    int suite = 0;

    if (ligneOuCol == 1)
    {
        for (int k = 0; k < 8; k++)
        {
            tab[k] = tableau[num][k];

            if (tab[k] == 1)
            {
                equal++;
                suite++;
            }
            if (tab[k] == 0)
            {
                suite--;
            }
            

        }
        

        /*for (int i = 0; i < 8; i++)
        {
            if (tab[i] == 2)
            {
                res = 0;
            }
        }*/
        
    }
    else{

        for (int i = 0; i < 8; i++)
        {
            tab[i] = tableau[i][num];

            if (tab[i] == 1)
            {
                equal++;
                suite++;
            }
            if (tab[i] == 0)
            {
                suite--;
            }
            
            /*
            if (tab[i] == 2)
            {
                res = 0;
            }*/
            
        }

    }

    if ((equal != 4) || (suite != 0))
    {
        res = 0;
    }
    

    return res;
}

int verifierGrille(int tableau[8][8]){

    int res = 1;

    for (int i = 0; i < 8; i++)
    {
        int verifieLigne = verifierLigneColonne(tableau, 1, i);
        int verifieColonne = verifierLigneColonne(tableau, 0, i);

        if (!(verifieLigne && verifieColonne))
        {
            printf(" Votre solution ne correspond pas aux règles \n");
            res = 0;
        }
        
    }
    
    return res;
}

void afficher(int tab[8][8]){

    printf("    0 1 2 3 4 5 6 7");
    printf("\n");
    printf("    ---------------");
    printf("\n");
    
    for (int i = 0; i < 8; i++)
    {
        printf("%d |", i);

        for (int j = 0; j < 8; j++)
        {
            printf(" %d", tab[i][j]);
        }

        printf("\n");
        
    }

}


int saisir(int grille[8][8]){
    
    int result = 0;

    while (result == 0)
    {
        int tableauTest[8][8] = {
            {2,2,2,2, 2,2,2,2},
            {2,2,2,2, 2,2,2,2},
            {2,2,2,2, 2,2,2,2},
            {2,2,2,2, 2,2,2,2},
            
            {2,2,2,2, 2,2,2,2},
            {2,2,2,2, 2,2,2,2},
            {2,2,2,2, 2,2,2,2},
            {2,2,2,2, 2,2,2,2}
        };

        copyArray(grille, tableauTest);
        int saisie = 0;
        

        printf("Veuillez saisir un Y\n");
        scanf("%d", &saisie);
        int saisieX = saisie;
        printf("Veuillez saisir un X\n");
        scanf("%d", &saisie);
        int saisieY = saisie;

        if(grille[saisieX][saisieY] != 2){
            printf("Cette case est deja remplie\n");
        } 
        else {
            printf("Quelle valeur souhaitez vous inserer ?\n");
            scanf("%d", &saisie);
            int saisieVal = saisie;
            tableauTest[saisieX][saisieY] = saisieVal;
        
            /*if ((verifierLigneColonne(grille, 1, saisieX) && verifierLigneColonne(grille, 0, saisieY)))
            {
                result = 1;
            }*/
            
            result = 1;

            if(result == 1){
                grille[saisieX][saisieY] = saisieVal;
            }
        }
    }
    return result;
        
}



// 4 - Ecrire le code principal qui permet de jouer au joueur :  le programme prend fin quand on gagne 

int main(){
    // Ne pas toucher le code entre les commentaires
    srand( time( NULL ) );


    
    printf("SOLUTION");  
    printf("\n");  
    printf("---------------------------------");  
    printf("\n");  

    int solution[8][8] = {
        {1,1,0,1, 0,1,0,0},
        {0,0,1,0, 1,0,1,1},
        {0,1,0,0, 1,1,0,1},
        {1,0,1,1, 0,0,1,0},
    
        {1,0,1,0, 0,1,1,0},
        {0,1,0,1, 1,0,0,1},
        {1,1,0,0, 1,0,1,0},
        {0,0,1,1, 0,1,0,1}
    };


    for(int i = 0; i < 8; ++i) 
    {
    for(int j = 0; j < 8; ++j)
        printf("%d ", solution[i][j]);
    printf("\n");  
    }
    printf("---------------------------------");  
    printf("\n");  
    //toucher le code entre les commentaires 

    int tableauJoueur[8][8] = { {2,2,2,2 ,2,2,2,2},
                                {2,2,2,2 ,2,2,2,2},
                                {2,2,2,2 ,2,2,2,2},
                                {2,2,2,2 ,2,2,2,2},
                            
                                {2,2,2,2 ,2,2,2,2},
                                {2,2,2,2 ,2,2,2,2},
                                {2,2,2,2 ,2,2,2,2},
                                {2,2,2,2 ,2,2,2,2}};

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){

            printf("%d ", tableauJoueur[i][j]);
        }
        printf("\n");
    }
    int isTurning = 0;

    int oneshot = 1;

    printf("Voulez vous un tableau oneshot ? (oui == 1, non == 0) ");
    scanf("%d", &oneshot);

    

    genGrilleJouable(solution, tableauJoueur, oneshot);
    do{

        int tabRempli = 1;
        afficher(tableauJoueur);
        saisir(tableauJoueur);

        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (tableauJoueur[i][j] == 2)
                {
                    tabRempli = 0;
                    //printf("\n TABREMPLI %d \n", tabRempli);    
                }
                
            }
            
        }
        
        
        if (tabRempli)
        {
            isTurning = verifierGrille(tableauJoueur);
        }
        
    } while(!isTurning);


    printf("GG bro");


    //Ne pas toucher au code ci dessous
    getchar();
    return 0;
}

