/******************************************************************************
  MANIPULATION DE LISTES
 ******************************************************************************/
#include <iostream>
#include <QDebug>

#include "liste.h"
using namespace std;

/**
 * Convertit un tableau d'entiers en une liste chainee, simplement circulaire.
 *
 * Parametre n : le nombre d'elements de t.
 * Parametre t : tableau d'entiers a convertir.
 *
 * Retourne : la liste equivalente a t.
 */
noeud* listecc(int n, int* t) {
    if (t == NULL || n == 0) return NULL;
    noeud* m = new noeud;
    m->info = t[0];
    noeud* l = m;
    for (int i = 1; i < n; i++) {
        m->succ = new noeud;
        m->succ->info = t[i];
        m = m->succ;
    }
    m->succ = l;
    return l;
}

/**
 * Convertit plusieurs tableaux d'entier en une liste chainee simplement chain�e de liste chain�e circulaire
 *
 * Parametre n : le nombre d'elements de t.
 * Parametres : tableaux d'entiers de taille 4 � ins�rer.
 *
 * Retourne : la liste.
 */
liste listePermutations(int n, ...) {
    if(n==0) return NULL;
    va_list ap;
    va_start(ap, n);
    liste m = new maillon;
    liste l = m;
    for(int i = 0 ; i < n ; i++){ // pour chaqun des tableaux re�us...
        noeud* c = listecc(4, va_arg(ap, int*)); //on cr�e une sous liste chain�e contenant les valeurs du tableau.
        m->info = c; // que l'on ajoute � notre liste simplement chain�e.
        if(i < n-1) {
            m->succ = new maillon;
            m = m->succ;
        }
        else m->succ = NULL;
    }
    va_end(ap);
    return l;
}

/**
 * Supprime une liste chain�e circulaire de noeuds.
 *
 * Parametre l : pointeur sur une adresse noeud.
 *
 */
void detruire(noeud** l) {
    if(l == NULL || *l == NULL) return;
    noeud* n = NULL;
    noeud* s = (*l);
    while((*l)->succ != s) {
        n = (*l);
        (*l) = (*l)->succ;
        delete(n);
    }
    delete *l;
}

/**
 * Supprime une liste chain�e de liste chain�e circulaire (noeuds).
 *
 * Parametre l : pointeur sur une liste.
 *
 * Retourne : (bool�en)? Bonne ex�cution : Param�tre incorrect.
 */
bool deleteListePermutations(liste* l) {
    if (l == NULL) return false;
    while ((*l) != NULL) { // parcourrir la liste et liberer les maillons un a un
        maillon* s = (*l);
        (*l) = (*l)->succ;
        detruire(&(s->info)); // detruire la sous liste circulaire
        delete s;
    }
    return true;
}
