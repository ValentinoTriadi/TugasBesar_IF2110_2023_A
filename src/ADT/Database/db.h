#ifndef DB_H
#define DB_H

#include "../Graf/graf.h"
#include "../Draf/draf.h"
// #include "../Inisialisasi/inisialisasi.h"
#include "../Kicau/tweet.h"
#include "../ListStatik/liststatik.h"
#include "../Matrix/matrix.h"
#include "../MaxHeap/maxheap.h"
#include "../Mesin-Char/charmachine.h"
#include "../Mesin-Kata/wordmachine.h"
#include "../pcolor/pcolor.h"
// #include "../Perintah/perintah.h" 
#include "../PrioQueue/prioqueueReq.h"
#include "../Teman/teman.h"
#include "../Time/adttime.h"
#include "../Time/datetime.h"
#include "../User/user.h"
#include "../Utas/utas.h"
#include "../Profil/profil.h"

extern Profil CurrentUser;
extern userlist DaftarPengguna;
extern ListKicau DaftarKicau;
extern Teman DataTeman;
extern Stack Draf;

// DB Pengguna dengan list statik

// DB Kicau dengan linked list
typedef Kicauan ELMTKICAU;
typedef struct nodekicau* Addresskicau;
typedef struct nodekicau {
    ELMTKICAU info;
    Addresskicau next;
} NODEKICAU;

typedef Addresskicau LISTKICAU;

#define INFOKICAU(p) (p)->info
#define NEXTKICAU(p) (p)->next
// #define IDX_UNDEF (-1)
#define FIRSTKICAU(l) (l)

#endif