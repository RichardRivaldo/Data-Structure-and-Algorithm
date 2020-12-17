#include "check.h"
#include "stdio.h"
#include "stdlib.h"
#include "../src/listdp.h"

int NbElmt(List L);
void IsiListI(List *L);


/* IsEmpty */
START_TEST(IsEmpty_TC1) {
  List L;
  CreateEmpty(&L);
  ck_assert_int_eq(1, IsEmpty(L));
  InsVLast(&L, 100000000);
  ck_assert_int_eq(0, IsEmpty(L));
}


/* CreateEmpty */
START_TEST(CreateEmpty_TC1) {
  List L;
  CreateEmpty(&L);
  ck_assert_ptr_eq(First(L), Nil);
  ck_assert_ptr_eq(Last(L), Nil);
}


/* Alokasi */
START_TEST(Alokasi_TC1) {
  infotype X = 10;
  address P = Alokasi(X);
  ck_assert_int_eq(Info(P), X);
  ck_assert_ptr_eq(Next(P), Nil);
}


/* Dealokasi */
START_TEST(Dealokasi_TC1) {
  infotype X = 10;
  address P = Alokasi(X);
  Dealokasi(P);
}


/* Search */
START_TEST(Search_T1) {
  List L;
  infotype search = 3;
  IsiListI(&L);
  address P = Search(L, search);
  ck_assert_ptr_ne(P, Nil);
}

START_TEST(Search_T2) {
  List L;
  infotype search = 99;
  IsiListI(&L);
  address P = Search(L, search);
  ck_assert_ptr_eq(P, Nil);
}

START_TEST(Search_T3) {
  List L;
  infotype search = 1;
  CreateEmpty(&L);
  address P = Search(L, search);
  ck_assert_ptr_eq(P, Nil);
}


/* InsVFirst */
START_TEST(InsVFirst_T1) {
  List L;
  infotype X = 5;
  CreateEmpty(&L);
  InsVFirst(&L, X);
  ck_assert_int_eq(NbElmt(L), 1);
  ck_assert_int_eq(Info(First(L)), 5);
}

START_TEST(InsVFirst_T2) {
  List L;
  infotype X = 0;

  IsiListI(&L);
  InsVFirst(&L, X);

  ck_assert_int_eq(NbElmt(L), 4);

  int i = 0;
  address P = First(L);
  while (P != Nil) {
    ck_assert_int_eq(Info(P), i);
    P = Next(P);
    i++;
  }
}


/* InsVLast */
START_TEST(InsVLast_T1) {
  List L;
  infotype X = 10;
  CreateEmpty(&L);
  InsVLast(&L, X);
  ck_assert_int_eq(NbElmt(L), 1);
  ck_assert_int_eq(Info(First(L)), 10);
}

START_TEST(InsVLast_T2) {
  List L;
  infotype X = 4;

  IsiListI(&L);
  InsVLast(&L, X);

  ck_assert_int_eq(NbElmt(L), 4);

  int i = 1;
  address P = First(L);
  while (P != Nil) {
    ck_assert_int_eq(Info(P), i);
    P = Next(P);
    i++;
  }
}


/* DelVFirst */
START_TEST(DelVFirst_T1) {
  List L;
  infotype X;

  IsiListI(&L);
  DelVFirst(&L, &X);

  ck_assert_int_eq(X, 1);
  ck_assert_int_eq(NbElmt(L), 2);

  int i = 2;
  address P = First(L);
  while (P != Nil) {
    ck_assert_int_eq(Info(P), i);
    P = Next(P);
    i++;
  }
}


/* DelVLast */
START_TEST(DelVLast_T1) {
  List L;
  infotype X;

  IsiListI(&L);
  DelVLast(&L, &X);

  ck_assert_int_eq(X, 3);
  ck_assert_int_eq(NbElmt(L), 2);

  int i = 1;
  address P = First(L);
  while (P != Nil) {
    ck_assert_int_eq(Info(P), i);
    P = Next(P);
    i++;
  }
}


/* InsertFirst */
START_TEST(InsertFirst_T1) {
  List L;
  CreateEmpty(&L);

  address P3 = Alokasi(3);
  InsertFirst(&L, P3);
  address P2 = Alokasi(2);
  InsertFirst(&L, P2);
  address P1 = Alokasi(1);
  InsertFirst(&L, P1);
  
  ck_assert_int_eq(NbElmt(L), 3);
  int i = 1;
  address P = First(L);
  while (P != Nil) {
    ck_assert_int_eq(Info(P), i);
    P = Next(P);
    i++;
  }
}


/* InsertAfter */
START_TEST(InsertAfter_T1) {
  List L;
  CreateEmpty(&L);

  address P3 = Alokasi(3);
  InsertFirst(&L, P3);
  address P1 = Alokasi(1);
  InsertFirst(&L, P1);

  address P2 = Alokasi(2);
  InsertAfter(&L, P2, P1);
  
  ck_assert_int_eq(NbElmt(L), 3);
  int i = 1;
  address P = First(L);
  while (P != Nil) {
    ck_assert_int_eq(Info(P), i);
    P = Next(P);
    i++;
  }
}


/* InsertLast */
START_TEST(InsertLast_T1) {
  List L;
  CreateEmpty(&L);

  address P1 = Alokasi(1);
  InsertLast(&L, P1);
  address P2 = Alokasi(2);
  InsertLast(&L, P2);
  address P3 = Alokasi(3);
  InsertLast(&L, P3);
  
  ck_assert_int_eq(NbElmt(L), 3);
  int i = 1;
  address P = First(L);
  while (P != Nil) {
    ck_assert_int_eq(Info(P), i);
    P = Next(P);
    i++;
  }
}


/* InsertBefore */
START_TEST(InsertBefore_T1) {
  List L;
  CreateEmpty(&L);

  address P3 = Alokasi(3);
  InsertFirst(&L, P3);
  address P1 = Alokasi(1);
  InsertFirst(&L, P1);

  address P2 = Alokasi(2);
  InsertBefore(&L, P2, P3);
  
  ck_assert_int_eq(NbElmt(L), 3);
  int i = 1;
  address P = First(L);
  while (P != Nil) {
    ck_assert_int_eq(Info(P), i);
    P = Next(P);
    i++;
  }
}


/* DelFirst */
START_TEST(DelFirst_T1) {
  List L;
  CreateEmpty(&L);

  address P1 = Alokasi(1);
  InsertLast(&L, P1);
  address P2 = Alokasi(2);
  InsertLast(&L, P2);
  address P3 = Alokasi(3);
  InsertLast(&L, P3);
  
  ck_assert_int_eq(NbElmt(L), 3);
  int i = 1;
  address P = First(L);
  while (P != Nil) {
    ck_assert_int_eq(Info(P), i);
    P = Next(P);
    i++;
  }
}


/* DelP */
START_TEST(DelP_T1) {
  List L;
  IsiListI(&L);
  DelP(&L, 3);
  
  ck_assert_int_eq(NbElmt(L), 2);
  int i = 1;
  address P = First(L);
  while (P != Nil) {
    ck_assert_int_eq(Info(P), i);
    P = Next(P);
    i++;
  }
}

START_TEST(DelP_T2) {
  List L;
  IsiListI(&L);
  DelP(&L, 10);
  
  ck_assert_int_eq(NbElmt(L), 3);
  int i = 1;
  address P = First(L);
  while (P != Nil) {
    ck_assert_int_eq(Info(P), i);
    P = Next(P);
    i++;
  }
}

START_TEST(DelP_T3) {
  List L;
  CreateEmpty(&L);
  DelP(&L, 10);
  
  ck_assert_int_eq(NbElmt(L), 0);
}

START_TEST(DelP_T4) {
  List L;
  CreateEmpty(&L);
  InsVLast(&L, 1);
  DelP(&L, 1);
  
  ck_assert_int_eq(NbElmt(L), 0);
}


/* DelLast */
START_TEST(DelLast_T1) {
  List L;
  IsiListI(&L);

  address P;
  DelLast(&L, &P);
  ck_assert_int_eq(Info(P), 3);
  ck_assert_ptr_eq(Next(P), Nil);
  ck_assert_int_eq(NbElmt(L), 2);

  int i = 1;
  P = First(L);
  while (P != Nil) {
    ck_assert_int_eq(Info(P), i);
    P = Next(P);
    i++;
  }
}

START_TEST(DelLast_T2) {
  List L;
  CreateEmpty(&L);
  InsVLast(&L, 1);

  address P;
  DelLast(&L, &P);
  ck_assert_int_eq(Info(P), 1);
  ck_assert_ptr_eq(Next(P), Nil);
  ck_assert_int_eq(NbElmt(L), 0);
}


/* DelAfter */
START_TEST(DelAfter_T1) {
  List L;
  address Prec, Pdel;
  IsiListI(&L);
  Prec = First(L);
  DelAfter(&L, &Pdel, Prec);

  ck_assert_int_eq(NbElmt(L), 2);
  ck_assert_int_eq(Info(Prec), 1);
  ck_assert_int_eq(Info(Pdel), 2);
}

START_TEST(DelAfter_T2) {
  List L;
  int i;

  address Prec, Pdel;
  IsiListI(&L);
  for (i = 4; i <= 8; i++) {
    InsVLast(&L, i);
  }

  Prec = First(L);
  for (i = 1; i < 3; i++) {
    Prec = Next(Prec);
  }
  DelAfter(&L, &Pdel, Prec);

  ck_assert_int_eq(NbElmt(L), 7);
  ck_assert_int_eq(Info(Prec), 3);
  ck_assert_int_eq(Info(Pdel), 4);

  i = 1;
  address P = First(L);
  while (P != Nil) {
    ck_assert_int_eq(Info(P), i);
    P = Next(P);
    i++;
    if (i == 4) {
      i++;
    }
  }
}


/* DelBefore */
START_TEST(DelBefore_T1) {
  List L;
  address Succ, Pdel;
  IsiListI(&L);
  Succ = Last(L);
  DelBefore(&L, &Pdel, Succ);

  ck_assert_int_eq(NbElmt(L), 2);
  ck_assert_int_eq(Info(Succ), 3);
  ck_assert_int_eq(Info(Pdel), 2);
}

START_TEST(DelBefore_T2) {
  List L;
  int i;

  address Succ, Pdel;
  IsiListI(&L);
  for (i = 4; i <= 8; i++) {
    InsVLast(&L, i);
  }

  Succ = Last(L);
  for (i = 1; i < 3; i++) {
    Succ = Prev(Succ);
  }
  DelBefore(&L, &Pdel, Succ);

  ck_assert_int_eq(NbElmt(L), 7);
  ck_assert_int_eq(Info(Succ), 6);
  ck_assert_int_eq(Info(Pdel), 5);

  i = 8;
  address P = Last(L);
  while (P != Nil) {
    ck_assert_int_eq(Info(P), i);
    P = Prev(P);
    i--;
    if (i == 5) {
      i--;
    }
  }
}


/* PrintForward */
START_TEST(PrintForward_T1) {
  List L;
  int i;
  IsiListI(&L);
  for (i = 4; i <= 8; i++) {
    InsVLast(&L, i);
  }
  PrintForward(L);
}


/* PrintBackward */
START_TEST(PrintBackward_T1) {
  List L;
  int i;
  IsiListI(&L);
  for (i = 4; i <= 8; i++) {
    InsVLast(&L, i);
  }
  PrintBackward(L);
}

/* IsiListI: L = [1,2,3] */
void IsiListI(List *L) {
  CreateEmpty(L);
  InsVFirst(L, 3);
  InsVFirst(L, 2);
  InsVFirst(L, 1);
}


/* NbElmt(L) */
int NbElmt(List L) {
  int count = 0;
  address P;

  if (!IsEmpty(L)) {
    P = First(L);
    while (P != Nil) {
      count++;
      P = Next(P);
    }
  }

  return count;
}


/* Suite dan Eksekusi */
Suite *listdp_suite(void) { 
  Suite *s;
  TCase *tc_prototype, *tc_memory, *tc_search, *tc_primitif, *tc_proses;
  s = suite_create("List DP");

  tc_prototype = tcase_create("Prototype");
  tcase_add_test(tc_prototype, CreateEmpty_TC1);
  tcase_add_test(tc_prototype, IsEmpty_TC1);
  suite_add_tcase(s, tc_prototype);

  tc_memory = tcase_create("Memory");
  tcase_add_test(tc_memory, Alokasi_TC1);
  tcase_add_test(tc_memory, Dealokasi_TC1);
  suite_add_tcase(s, tc_memory);

  tc_search = tcase_create("Search");
  tcase_add_test(tc_search, Search_T1);
  tcase_add_test(tc_search, Search_T2);
  tcase_add_test(tc_search, Search_T3);
  suite_add_tcase(s, tc_search);

  tc_primitif = tcase_create("Primitif");
  tcase_add_test(tc_primitif, InsVFirst_T1);
  tcase_add_test(tc_primitif, InsVFirst_T2);
  tcase_add_test(tc_primitif, InsVLast_T1);
  tcase_add_test(tc_primitif, InsVLast_T2);
  tcase_add_test(tc_primitif, DelVFirst_T1);
  tcase_add_test(tc_primitif, DelVLast_T1);
  tcase_add_test(tc_primitif, InsertFirst_T1);
  tcase_add_test(tc_primitif, InsertAfter_T1);
  tcase_add_test(tc_primitif, InsertBefore_T1);
  tcase_add_test(tc_primitif, InsertLast_T1);
  tcase_add_test(tc_primitif, DelFirst_T1);
  tcase_add_test(tc_primitif, DelP_T1);
  tcase_add_test(tc_primitif, DelP_T2);
  tcase_add_test(tc_primitif, DelP_T3);
  tcase_add_test(tc_primitif, DelP_T4);
  tcase_add_test(tc_primitif, DelLast_T1);
  tcase_add_test(tc_primitif, DelLast_T2);
  tcase_add_test(tc_primitif, DelAfter_T1);
  tcase_add_test(tc_primitif, DelAfter_T2);
  tcase_add_test(tc_primitif, DelBefore_T1);
  tcase_add_test(tc_primitif, DelBefore_T2);
  suite_add_tcase(s, tc_primitif);

  tc_proses = tcase_create("Proses");
  tcase_add_test(tc_proses, PrintForward_T1);
  tcase_add_test(tc_proses, PrintBackward_T1);

  return s;
} 

int main(void) {
  int no_failed = 0;
  Suite *s;
  SRunner *runner;

  s = listdp_suite();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL); 
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}