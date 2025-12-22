#include "mll.h"

int main() {
    ListParent L;
    createListParent(L);

    Genre *G1 = alokasiParent("G001","Action");
    Genre *G2 = alokasiParent("G002","Comedy");
    Genre *G3 = alokasiParent("G003","Horror");
    Genre *G4 = alokasiParent("G004","Romance");

    insertLastParent(L,G1);
    insertLastParent(L,G2);
    insertLastParent(L,G3);
    insertLastParent(L,G4);

    insertLastChild(G1, alokasiChild("FA001","The Raid",101,2011,7.6));
    insertLastChild(G2, alokasiChild("FC001","Agak Laen",119,2024,8.0));
    insertLastChild(G2, alokasiChild("FC002","My Stupid Boss",108,2016,6.8));
    insertLastChild(G3, alokasiChild("FH001","Pengabdi Setan",107,2017,8.4));
    insertLastChild(G4, alokasiChild("FR001","Habibie & Ainun",118,2012,7.6));
    insertLastChild(G4, alokasiChild("FR002","Dilan 1990",110,2018,6.6));

    printStrukturMLL(L);

    cout << "===== SEARCH RATING 8.0 - 8.5 =====" << endl;
    searchFilmByRatingRange(L,8.0,8.5);

    deleteAfterParent(L,G1);
    printStrukturMLL(L);
}
