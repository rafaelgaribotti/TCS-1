#include "unity.h"
#include "unity_fixture.h"

int identifier(char *ident);

TEST_GROUP(Identifier);

TEST_SETUP(Identifier){
}

TEST_TEAR_DOWN(Identifier){
}

TEST(Identifier, MinSizeAndLetter){
  char string[10] = {"L"};
  TEST_ASSERT_EQUAL(0,identifier(string));
}

TEST(Identifier, MaxSize){
  char string[10] = {"letra6"};
  TEST_ASSERT_EQUAL(0,identifier(string));
}

TEST(Identifier, MinSizeAndNumber){
  char string[10] = {"2"};
  TEST_ASSERT_EQUAL(1,identifier(string));
}

TEST(Identifier, Empty){
  char string[10] = {""};
  TEST_ASSERT_EQUAL(1,identifier(string));
}

TEST(Identifier, BiggerSize){
  char string[10] = {"letras7"};
  TEST_ASSERT_EQUAL(1,identifier(string));
}

TEST(Identifier, SpecialChar){
  char string[10] = {"dd~m"};
  TEST_ASSERT_EQUAL(1,identifier(string));
}
