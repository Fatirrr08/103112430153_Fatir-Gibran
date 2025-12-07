#include "mll.h"

int main() {
    listParent LP;
    createListParent(LP);

    // Parent 1: Aves
    adrParent P1 = allocNodeParent("G001", "Aves");
    insertLastParent(LP, P1);
    insertLastChild(P1->L_Child, allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3));
    insertLastChild(P1->L_Child, allocNodeChild("AV002", "Bebek", "Air", true, 2.0));

    // Parent 2: Mamalia
    adrParent P2 = allocNodeParent("G002", "Mamalia");
    insertLastParent(LP, P2);
    insertLastChild(P2->L_Child, allocNodeChild("M001", "Harimau", "Hutan", true, 200.0));
    insertLastChild(P2->L_Child, allocNodeChild("M003", "Gorila", "Hutan", false, 160.0));
    insertLastChild(P2->L_Child, allocNodeChild("M002", "Kucing", "Darat", true, 4.0));

    // Parent 3: Pisces
    insertLastParent(LP, allocNodeParent("G003", "Pisces"));

    // Parent 4: Amfibi (Ini yang akan dihapus)
    adrParent P4 = allocNodeParent("G004", "Amfibi");
    insertLastParent(LP, P4);
    insertLastChild(P4->L_Child, allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2));

    // Parent 5: Reptil
    insertLastParent(LP, allocNodeParent("G005", "Reptil"));

    // 3. Operasi DELETE Soal No 3
    // Menghapus node G004 (Amfibi)
    deleteParent(LP, "G004");

    // 4. Menampilkan Output
    // Output diharapkan: Aves, Mamalia, Pisces, Reptil (Amfibi hilang)
    printMLLStructure(LP);

    return 0;
}