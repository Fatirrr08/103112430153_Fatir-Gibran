#include "mll.h"

int main() {
    ListParent LP;
    createListParent(LP);

    ElmParent *G4 = alokasiNodeParent("G004","Romance");
    ElmParent *G3 = alokasiNodeParent("G003","Horror");
    ElmParent *G2 = alokasiNodeParent("G002","Comedy");
    ElmParent *G1 = alokasiNodeParent("G001","Action");

    insertFirstParent(LP,G4);
    insertFirstParent(LP,G3);
    insertFirstParent(LP,G2);
    insertFirstParent(LP,G1);

    insertLastChild(G1, alokasiNodeChild("FA001","The Raid",101,2011,7.6));
    insertLastChild(G2, alokasiNodeChild("FC001","Agak Laen",119,2024,8.0));
    insertLastChild(G2, alokasiNodeChild("FC002","My Stupid Boss",108,2016,6.8));
    insertLastChild(G3, alokasiNodeChild("FH001","Pengabdi Setan",107,2017,8.4));
    insertLastChild(G4, alokasiNodeChild("FR001","Habibie & Ainun",118,2012,7.6));
    insertLastChild(G4, alokasiNodeChild("FR002","Dilan 1990",110,2018,6.6));

    printStrukturMLL(LP);

    searchFilmByRatingRange(LP,8.0,8.5);

    deleteAfterParent(LP,G1);

    printStrukturMLL(LP);
}
