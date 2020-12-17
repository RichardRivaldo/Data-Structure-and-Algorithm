#include "check.h"
#include "stdio.h"
#include "stdlib.h"
#include "../src/listrek.h"

void IsiListI(List *L);


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


/* IsEmpty */
START_TEST(IsEmpty_TC1) {
  List L = Nil;
  ck_assert_int_eq(1, IsEmpty(L));
  L = Konso(1, L);
  ck_assert_int_eq(0, IsEmpty(L));
}


/* IsOneElmt */
START_TEST(IsOneElmt_TC1){
  List LOne = Nil;
  ck_assert_int_eq(0, IsOneElmt(LOne));
  LOne = Alokasi(1);
  ck_assert_int_eq(1, IsOneElmt(LOne));
}


/* FirstElmt */
START_TEST(FirstElmt_TC1){
  List L = Nil;
  IsiListI(&L);
  ck_assert_int_eq(FirstElmt(L), 1);
}


/* Tail */
/* Dicek melalui penggunaannya dalam fungsi lain */


/* Konso */
START_TEST(Konso_TC1){
  List L = Nil;
  L = Konso(0, L);
  ck_assert_int_eq(0, FirstElmt(L));
  ck_assert_int_eq(1, NbElmtList(L));
}

START_TEST(Konso_TC2){
  List L = Nil;
  IsiListI(&L);
  L = Konso(0, L);
  
  address P = L;
  int i = 0;
  while (P != Nil){
    ck_assert_int_eq(Info(P), i);
    i++;
    P = Tail(P);
  }
  ck_assert_int_eq(4, NbElmtList(L));
}


/* KonsB */
START_TEST(KonsB_TC1){
  List L = Nil;
  L = KonsB(L, 0);
  ck_assert_int_eq(1, NbElmtList(L));
  ck_assert_int_eq(0, FirstElmt(L));
}

START_TEST(KonsB_TC2){
  List L = Nil;
  IsiListI(&L);
  L = KonsB(L, 4);

  address P = L;
  int i = 1;
  while (P != Nil){
    ck_assert_int_eq(Info(P), i);
    i++;
    P = Tail(P);
  }
  ck_assert_int_eq(4, NbElmtList(L));
}


/* Copy */
START_TEST(Copy_TC1){
  List L1 = Nil;
  IsiListI(&L1);
  List L2 = Nil;
  L2 = Copy(L1);
  address P1 = L1;
  address P2 = L2;
  while (P1 != Nil && P2 != Nil)
  {
    ck_assert_int_eq(Info(P1), Info(P2));
    P1 = Tail(P1);
    P2 = Tail(P2);
  }
  ck_assert_int_eq(NbElmtList(L1), NbElmtList(L2));
}

START_TEST(Copy_TC2){
  List L1 = Nil;
  IsiListI(&L1);
  List L2 = Nil;
  MCopy(L1, &L2);
  
  address P1 = L1;
  address P2 = L2;
  while (P1 != Nil && P2 != Nil)
  {
    ck_assert_int_eq(Info(P1), Info(P2));
    P1 = Tail(P1);
    P2 = Tail(P2);
  }
  ck_assert_int_eq(NbElmtList(L1), NbElmtList(L2));
}


/* Concat */
START_TEST(Concat_TC1){
  List L1 = Nil;
  L1 = Konso(1, L1); 
  L1 = KonsB(L1, 2);
  List L2 = Nil;
  L2 = Alokasi(3);
  
  List L3 = Nil;
  L3 = Concat(L1, L2);
  address P = L3;
  int i = 1;
  while (P != Nil){
    ck_assert_int_eq(Info(P), i);
    i++;
    P = Tail(P);
  }
}

START_TEST(Concat_TC2){
  List L1 = Nil;
  L1 = Konso(1, L1); 
  L1 = KonsB(L1, 2);
  List L2 = Nil;
  L2 = Alokasi(3);
  
  List L3 = Nil;
  MConcat(L1, L2, &L3);

  address P = L3;
  int i = 1;
  while (P != Nil){
    ck_assert_int_eq(Info(P), i);
    i++;
    P = Tail(P);
  }
}


/* PrintList */
START_TEST(PrintList_TC1){
  List L = Nil;
  IsiListI(&L);
  PrintList(L);
}


/* Search */
START_TEST(Search_T1) {
  List L = Nil;
  IsiListI(&L);
  infotype search = 3;
  int P = Search(L, search);
  ck_assert_int_eq(P, 1);
}

START_TEST(Search_T2) {
  List L = Nil;
  IsiListI(&L);
  infotype search = 99;
  int P = Search(L, search);
  ck_assert_int_eq(P, 0);
}

START_TEST(Search_T3) {
  List L = Nil;
  infotype search = 1;
  int P = Search(L, search);
  ck_assert_int_eq(P, 0);
}


/* IsiListI: L = [1,2,3] */
void IsiListI(List *L) {
  *L = KonsB(*L, 1);
  *L = KonsB(*L, 2);
  *L = KonsB(*L, 3);
}


/* Suite dan Eksekusi */
Suite *listrek_suite(void) { 
  Suite *s;
  TCase *tc_prototype, *tc_memory, *tc_search, *tc_primitif, *tc_proses;
  s = suite_create("List Rekursif");

  tc_prototype = tcase_create("Prototype");
  tcase_add_test(tc_prototype, IsOneElmt_TC1);
  tcase_add_test(tc_prototype, IsEmpty_TC1);
  tcase_add_test(tc_prototype, FirstElmt_TC1);
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
  tcase_add_test(tc_primitif, Konso_TC1);
  tcase_add_test(tc_primitif, Konso_TC2);
  tcase_add_test(tc_primitif, KonsB_TC1);
  tcase_add_test(tc_primitif, KonsB_TC2);
  tcase_add_test(tc_primitif, Copy_TC1);
  tcase_add_test(tc_primitif, Copy_TC2);
  tcase_add_test(tc_primitif, Concat_TC1);
  tcase_add_test(tc_primitif, Concat_TC2);

  suite_add_tcase(s, tc_primitif);

  tc_proses = tcase_create("Proses");
  tcase_add_test(tc_proses, PrintList_TC1);

  return s;
} 

int main(void) {
  int no_failed = 0;
  Suite *s;
  SRunner *runner;

  s = listrek_suite();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL); 
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}