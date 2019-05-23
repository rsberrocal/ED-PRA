#include <cstdlib>
#include "BST.h"
using namespace std;

/* Examen P3. Arbres binaris de Cerca */
// MAIN CONTROL 1. GRUPS CD
int main(int argc, char** argv) {
        
    //creem un arbre que emmagatzemi enters  
    BST<int> *bst;
    bst = new BST<int>();
          
    /* EXECUCIO EXERCICI 1 */
    cout << "EXECUCIO EXERCICI 1 ... " << endl;
    
    //inserim els elements de l'array a l'arbre        
    int array_ex1 [] = {6,4,2,1,5,7};
    int size_array_ex1 = sizeof(array_ex1) / sizeof(*array_ex1);
        
    for(int i=0;i<size_array_ex1;i++)       
        bst->insert(array_ex1[i]);
    
    bst->showPreorder();
    cout << endl;
    bst->mirall();
    bst->showPreorder();
    cout << endl;
    
    delete bst; 

    
    /* EXECUCIO EXERCICI 2 */
    cout << endl << "EXECUCIO EXERCICI 2 ... " << endl;
    
    BST<int> *bst2;
    bst2 = new BST<int>();
    
    
        //inserim els elements de l'array a l'arbre        
    int array_ex2 [] = {6,3,2,1,5,7};
    int size_array_ex2 = sizeof(array_ex2) / sizeof(*array_ex2);
        
    for(int i=0;i<size_array_ex2;i++)       
        bst2->insert(array_ex2[i]);
    
    bst2->mostraRangs(1,4);
    
    return 0;
}