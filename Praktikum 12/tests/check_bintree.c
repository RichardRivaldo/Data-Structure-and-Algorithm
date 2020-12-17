#include "check.h"
#include "stdio.h"
#include "stdlib.h"
#include "../src/bintree.h"
#include "../src/listrek.h"

/* Cek fungsi pembuatan Tree */
/* Cek Alokasi */
BinTree createTree() {
    /* Menghasilkan sebuah Tree dengan NbElmt(T) = 4. Anggota T adalah
    3 dengan Left(3) = 1 dan Right(3) = 2, dan Left(1) = 4 */
    BinTree Tree1, Tree2, Tree3, Tree4;

    Tree1 = AlokNode(1);
    Tree2 = AlokNode(2);
    Tree4 = AlokNode(4);
    
    Left(Tree1) = Tree4;
    MakeTree(3, Tree1, Tree2, &Tree3);

    return Tree3;
}

BinTree createBTree(){
   /* Membuat Binary Tree */
    BinTree Tree1, Tree2, Tree3, Tree4;

    Tree1 = AlokNode(1);
    Tree3 = AlokNode(3);
    Tree4 = AlokNode(4);
    Right(Tree3) = Tree4;

    MakeTree(2, Tree1, Tree3, &Tree2);

    return Tree2;
}


/* Manajemen Memori */

START_TEST(Dealokasi_TC1) {
  infotype X = 100000;
  BinTree Tree1 = AlokNode(X);

  DealokNode(Tree1);
}


/* Predikat */

/* IsTreeEmpty */
START_TEST(IsTreeEmpty_TC1) {
  BinTree Tree1 = Nil;
  ck_assert_int_eq(1, IsTreeEmpty(Tree1));

  Tree1 = createTree();
  ck_assert_int_eq(0, IsTreeEmpty(Tree1));
}


/* IsTreeOneElmt */
START_TEST(IsTreeOneElmt_TC1) {
  BinTree Tree1;
  ck_assert_int_eq(0, IsTreeOneElmt(Tree1));

  Tree1 = AlokNode(10000);
  ck_assert_int_eq(1, IsTreeOneElmt(Tree1));
}


/* IsUnerLeft*/
START_TEST(IsUnerLeft_TC1) {
  BinTree Tree1 = Nil;
  ck_assert_int_eq(0, IsUnerLeft(Tree1));

  Tree1 = AlokNode(100000);
  BinTree Tree2 = AlokNode(10000);
  Left(Tree1) = Tree2;
  ck_assert_int_eq(1, IsUnerLeft(Tree1));

  BinTree Tree3 = AlokNode(10000);
  Right(Tree1) = Tree3;
  ck_assert_int_eq(0, IsUnerLeft(Tree1));
}


/* IsUnerRight */
START_TEST(IsUnerRight_TC1) {
  BinTree Tree1 = Nil;
  ck_assert_int_eq(0, IsUnerRight(Tree1));

  Tree1 = AlokNode(10000);
  BinTree Tree2 = AlokNode(100000); Right(Tree1) = Tree2;
  ck_assert_int_eq(1, IsUnerRight(Tree1));

  BinTree Tree3 = AlokNode(10000); Left(Tree1) = Tree3;
  ck_assert_int_eq(0, IsUnerRight(Tree1));
}


/* IsBiner */
START_TEST(IsBiner_TC1) {
  BinTree Tree1 = Nil;
  ck_assert_int_eq(0, IsBiner(Tree1));

  Tree1 = AlokNode(100000);
  BinTree Tree2 = AlokNode(100000);
  Right(Tree1) = Tree2;
  ck_assert_int_eq(0, IsBiner(Tree1));

  BinTree Tree3 = AlokNode(100000);
  Left(Tree1) = Tree3;
  ck_assert_int_eq(1, IsBiner(Tree1));
}


/* IsSkewLeft */
START_TEST(IsSkewLeft_TC1) {
    BinTree Tree1 = Nil;
    ck_assert_int_eq(1, IsSkewLeft(Tree1));

    Tree1 = AlokNode(10000);
    BinTree Tree2 = AlokNode(10000);
    Left(Tree1) = Tree2;
    BinTree Tree3 = AlokNode(10000);
    Left(Tree2) = Tree3;
    ck_assert_int_eq(1, IsSkewLeft(Tree1));

    BinTree Tree4 = AlokNode(10000);
    Right(Tree1) = Tree4;
    ck_assert_int_eq(0, IsSkewLeft(Tree1));
}


/* IsSkewRight */
START_TEST(IsSkewRight_TC1) {
    BinTree Tree1 = Nil;
    ck_assert_int_eq(1, IsSkewRight(Tree1));

    Tree1 = AlokNode(10000);
    BinTree Tree2 = AlokNode(10000);
    Right(Tree1) = Tree2;
    BinTree Tree3 = AlokNode(10000);
    Right(Tree2) = Tree3;
    ck_assert_int_eq(1, IsSkewRight(Tree1));

    BinTree Tree4 = AlokNode(4); Left(Tree1) = Tree4;
    ck_assert_int_eq(0, IsSkewRight(Tree1));
}


/* Search Tree */

/* Search */
START_TEST(SearchTree_T1) {
    BinTree Tree1 = createTree();

    ck_assert_int_eq(0, SearchTree(Tree1, 1000));
    ck_assert_int_eq(1, SearchTree(Tree1, 4));
}


/* Cetak Tree */

/* PrintPreOrder */
START_TEST(PrintPreorder_T1) {
  BinTree Tree1 = createTree();

  printf("Pre Order Tree: ");
  PrintPreorder(Tree1);
  printf("\n");
}


/* PrintInOrder */
START_TEST(PrintInorder_T1) {
  BinTree Tree1 = createTree();

  printf("In Order Tree: ");
  PrintInorder(Tree1);
  printf("\n");
}


/* PrintPostOrder */
START_TEST(PrintPostorder_T1) {
  BinTree Tree1 = createTree();

  printf("Post Order Tree: ");
  PrintPostorder(Tree1);
  printf("\n");
}


/* PrintTree */
START_TEST(PrintTree_T1) {
  BinTree Tree1 = createTree();

  printf("Print Tree : ");
  PrintTree(Tree1, 4);
  printf("\n");
}


/* NbElmt NbDaun */

/* NbElmt */
START_TEST(NbElmt_T1) {
    BinTree Tree1 = createTree();

    ck_assert_int_eq(4, NbElmt(Tree1));
}


/* NbDaun */
START_TEST(NbDaun_T1) {
    BinTree Tree1 = createTree();

    ck_assert_int_eq(2, NbDaun(Tree1));
}


/* Level Tree */

/* Level */
START_TEST(Level_T1) {
    BinTree Tree1 = createTree();

    ck_assert_int_eq(3, Level(Tree1, 4));
    ck_assert_int_eq(1, Level(Tree1, 3));
}


/* Tinggi Tree */

/* Tinggi */
START_TEST(Tinggi_T1) {
    BinTree Tree1 = createTree();

    ck_assert_int_eq(3, Tinggi(Tree1));
}


/* Operasi Daun */

/* Add Daun Kiri */
START_TEST(AddDaunTerkiri_T1) {
    BinTree Tree1 = createTree();

    AddDaunTerkiri(&Tree1, 5);
    ck_assert_int_eq(5, Akar(Left(Left(Left(Tree1)))));
}


/* AddDaun */
START_TEST(AddDaun_T1) {
    BinTree Tree1 = createTree();

    AddDaun(&Tree1, 2, 5, false);
    ck_assert_int_eq(5, Akar(Right(Right(Tree1))));
}


/* Del Daun Kiri */
START_TEST(DelDaunTerkiri_T1) {
    infotype X;
    BinTree Tree1 = createTree();

    DelDaunTerkiri(&Tree1, &X);
    ck_assert_int_eq(4, X);
}


/* DelDaun */
START_TEST(DelDaun_T1) {
    BinTree Tree1 = createTree();

    DelDaun(&Tree1, 4);
    ck_assert_ptr_eq(Nil, Left(Left(Tree1)));
}


/* Tree To List */

/* MakeListDaun */
START_TEST(MakeListDaun_T1) {
    BinTree Tree1 = createTree();
    List List1 = MakeListDaun(Tree1);

    ck_assert_int_eq(4, Info(List1));
    ck_assert_int_eq(2, Info(Next(List1)));
}


/* MakeListPreOrder */
START_TEST(MakeListPreorder_T1) {
    BinTree Tree1 = createTree();
    List List1 = MakeListPreorder(Tree1);

    ck_assert_int_eq(3, Info(List1));

    List1 = Next(List1);
    ck_assert_int_eq(1, Info(List1));

    List1 = Next(List1);
    ck_assert_int_eq(4, Info(List1));

    List1 = Next(List1);
    ck_assert_int_eq(2, Info(List1));
}


/* MakeListLevel */
START_TEST(MakeListLevel_T1) {
    BinTree Tree1 = createTree();
    List List1 = MakeListLevel(Tree1, 2);

    ck_assert_int_eq(1, Info(List1));

    List1 = Next(List1);
    ck_assert_int_eq(2, Info(List1));
}


/* BinTree */

/* BinarySearch */
START_TEST(BSearch_T1) {
    BinTree Tree1 = createBTree();

    ck_assert_int_eq(0, BSearch(Tree1,10000));
    ck_assert_int_eq(1, BSearch(Tree1,4));
}


/* InsSearch */
START_TEST(InsSearch_T1) {
    BinTree Tree1 = createBTree();

    InsSearch(&Tree1,5);
    ck_assert_int_eq(5, Akar(Right(Right(Right((Tree1))))));
}


/* DelBTree */
START_TEST(DelBtree_T1) {
    BinTree Tree1 = createBTree();

    DelBtree(&Tree1,4);
    ck_assert_ptr_eq(Nil, Right(Right(Tree1)));
}

/* ********** SUITE DAN EKSEKUSI ********** */
Suite *bintree_suite(void) {
  Suite *s;
  TCase *tc_boolean, *tc_memory, *tc_search, *tc_print, *tc_jumlah, *tc_daun, *tc_level, *tc_tinggi, *tc_list, *tc_BinaryTree;
  s = suite_create("Tree");

  tc_memory = tcase_create("Manajemen Memori");
  tcase_add_test(tc_memory, Dealokasi_TC1);
  suite_add_tcase(s, tc_memory);

  tc_boolean = tcase_create("Predikat");
  tcase_add_test(tc_boolean, IsTreeEmpty_TC1);
  tcase_add_test(tc_boolean, IsTreeOneElmt_TC1);
  tcase_add_test(tc_boolean, IsUnerLeft_TC1);
  tcase_add_test(tc_boolean, IsUnerRight_TC1);
  tcase_add_test(tc_boolean, IsBiner_TC1);
  tcase_add_test(tc_boolean, IsSkewLeft_TC1);
  tcase_add_test(tc_boolean, IsSkewRight_TC1);
  suite_add_tcase(s, tc_boolean);

  tc_search = tcase_create("Search Tree");
  tcase_add_test(tc_search, SearchTree_T1);
  suite_add_tcase(s, tc_search);

  tc_print = tcase_create("Cetak Tree");
  tcase_add_test(tc_print, PrintInorder_T1);
  tcase_add_test(tc_print, PrintPreorder_T1);
  tcase_add_test(tc_print, PrintPostorder_T1);
  tcase_add_test(tc_print, PrintTree_T1);
  suite_add_tcase(s, tc_print);

  tc_jumlah = tcase_create("NbElmt NbDaun");
  tcase_add_test(tc_jumlah, NbElmt_T1);
  tcase_add_test(tc_jumlah, NbDaun_T1);
  suite_add_tcase(s, tc_jumlah);

  tc_daun = tcase_create("Operasi Daun");
  tcase_add_test(tc_daun, AddDaunTerkiri_T1);
  tcase_add_test(tc_daun, AddDaun_T1);
  tcase_add_test(tc_daun, DelDaunTerkiri_T1);
  tcase_add_test(tc_daun, DelDaun_T1);
  suite_add_tcase(s, tc_daun);

  tc_level = tcase_create("Level Tree");
  tcase_add_test(tc_level, Level_T1);
  suite_add_tcase(s, tc_level);

  tc_tinggi = tcase_create("Tinggi Tree");
  tcase_add_test(tc_tinggi, Tinggi_T1);
  suite_add_tcase(s, tc_tinggi);

  tc_list = tcase_create("Tree To List");
  tcase_add_test(tc_list, MakeListDaun_T1);
  tcase_add_test(tc_list, MakeListLevel_T1);
  tcase_add_test(tc_list, MakeListPreorder_T1);
  suite_add_tcase(s, tc_list);

  tc_BinaryTree = tcase_create("BinTree");
  tcase_add_test(tc_BinaryTree, BSearch_T1);
  tcase_add_test(tc_BinaryTree, InsSearch_T1);
  tcase_add_test(tc_BinaryTree, DelBtree_T1);
  suite_add_tcase(s, tc_BinaryTree);

  return s;
}

int main(void) {
  int no_failed = 0;
  Suite *s;
  SRunner *runner;

  s = bintree_suite();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
