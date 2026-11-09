#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_08_1_it/lab_08_1_it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest81iter
{
    TEST_CLASS(UnitTest81iter)
    {
    public:
        TEST_METHOD(CountOneGroup)
        {
            char s[101] = "a,b-c";
            Assert::AreEqual(1, Count(s));
        }
        TEST_METHOD(CountTwoGroups)
        {
            char s[101] = "a,b-c,,x-d";
            Assert::AreEqual(2, Count(s));
        }
        TEST_METHOD(CountNoGroups)
        {
            char s[101] = "abc";
            Assert::AreEqual(0, Count(s));
        }
        TEST_METHOD(CountEmptyString)
        {
            char s[101] = "";
            Assert::AreEqual(0, Count(s));
        }
        TEST_METHOD(ChangeOneGroup)
        {
            char s[101] = "a,b-c";
            char* r = Change(s);
            Assert::AreEqual(string("a**c"), string(r));   // результат функції
            Assert::AreEqual(string("a**c"), string(s));   // змінений параметр
            delete[] r;
        }
        TEST_METHOD(ChangeTwoGroups)
        {
            char s[101] = "a,b-c,,x-d";
            char* r = Change(s);
            Assert::AreEqual(string("a**c,**d"), string(r));
            delete[] r;
        }
        TEST_METHOD(ChangeNothingToChange)
        {
            char s[101] = "abc";
            char* r = Change(s);
            Assert::AreEqual(string("abc"), string(r));
            delete[] r;
        }
        TEST_METHOD(ChangeOnlyGroups)
        {
            char s[101] = ",a-,b-";
            char* r = Change(s);
            Assert::AreEqual(string("****"), string(r));
            delete[] r;
        }
    };
}