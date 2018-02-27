#include "BST.h"

int main() {
    
    BST myTree;

    myTree.add(5);
    myTree.add(2);
    myTree.add(1);
    myTree.add(4);
    myTree.add(3);
    myTree.add(8);
    myTree.add(6);
    myTree.add(7);
    myTree.add(9);
    myTree.add(10);
    myTree.add(11);

    cout << "PREORDEN: "; myTree.print(1);
    cout << "INORDEN: "; myTree.print(2);
    cout << "POSTORDEN: "; myTree.print(3);
    cout << "LEAVES: "; myTree.print(4);
    cout << "NIVEL: "; myTree.print(5);

    cout << "ALTURA: " << myTree.height() << endl;
    cout << "ANCESTROS DEL 7: "; myTree.ancestors(7);
    cout << "ANCESTROS DEL 11: "; myTree.ancestors(11);
    cout << "ANCESTROS DEL 5: "; myTree.ancestors(5);
    cout << "NIVEL DEL 6: " << myTree.whatLevelamI(6) << endl;

    cout << "----------" << endl;
    cout << endl;

    BST mySecondTree(myTree);
    cout << "SECOND TREE" << endl;

    if(mySecondTree == myTree)
        cout << "EQUAL TREES" << endl;
    else
        cout << "NOT EQUAL TREES" << endl;

    mySecondTree.del(4);
    mySecondTree.del(3);
    mySecondTree.del(11);
    mySecondTree.del(8);

    if(mySecondTree == myTree)
        cout << "EQUAL TREES" << endl;
    else
        cout << "NOT EQUAL TREES" << endl;

    cout << "PREORDEN: "; mySecondTree.print(1);
    cout << "INORDEN: "; mySecondTree.print(2);
    cout << "POSTORDEN: "; mySecondTree.print(3);
    cout << "LEAVES: "; mySecondTree.print(4);
    cout << "NIVEL: "; mySecondTree.print(5);

    cout << "ALTURA: " << mySecondTree.height() << endl;
    cout << "ANCESTROS DEL 7: "; mySecondTree.ancestors(7);
    cout << "ANCESTROS DEL 11: "; mySecondTree.ancestors(11);
    cout << "ANCESTROS DEL 5: "; mySecondTree.ancestors(5);
    cout << "NIVEL DEL 6: " << mySecondTree.whatLevelamI(6) << endl;
    cout << "ALTURA: " << mySecondTree.height() << endl;
    cout << "ANCHURA: " << mySecondTree.maxWidth() << endl;

    cout << "-------------" << endl;
    cout << "MIRROR" << endl;
    myTree.mirror();

    cout << "PREORDEN: "; myTree.print(1);
    cout << "INORDEN: "; myTree.print(2);
    cout << "POSTORDEN: "; myTree.print(3);
    cout << "LEAVES: "; myTree.print(4);
    cout << "NIVEL: "; myTree.print(5);

    cout << "ALTURA: " << myTree.height() << endl;
    cout << "ANCESTROS DEL 7: "; myTree.ancestors(7);
    cout << "ANCESTROS DEL 11: "; myTree.ancestors(11);
    cout << "ANCESTROS DEL 5: "; myTree.ancestors(5);
    cout << "NIVEL DEL 6: " << myTree.whatLevelamI(6) << endl;



    return 0;
}
