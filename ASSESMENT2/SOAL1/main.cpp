#include "bst.h"

int main() {
    adr root = NULL;

    insertNode(root,50,"Monitor LED",10);
    insertNode(root,30,"Keyboard RGB",20);
    insertNode(root,70,"Mouse Gaming",15);
    insertNode(root,20,"Kabel HDMI",50);
    insertNode(root,40,"Headset 7.1",12);
    insertNode(root,60,"Webcam HD",8);
    insertNode(root,80,"Speaker BT",5);

    cout << "===== INORDER =====" << endl;
    inorder(root);

    cout << "===== PREORDER =====" << endl;
    preorder(root);

    cout << "===== POSTORDER =====" << endl;
    postorder(root);

    root = deleteNode(root,20);
    cout << "===== SETELAH DELETE 20 =====" << endl;
    inorder(root);

    root = deleteNode(root,30);
    cout << "===== SETELAH DELETE 30 =====" << endl;
    inorder(root);

    root = deleteNode(root,50);
    cout << "===== SETELAH DELETE 50 =====" << endl;
    inorder(root);

    deleteTree(root);
    cout << "===== TREE DIHAPUS =====" << endl;
    inorder(root);
}
