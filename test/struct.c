#include "test.h"

void test1(void)
{
    typedef struct {
        int a;
        char b;
        short c;
        long d;
    } foo_t;
    foo_t foo;
    memset((void*)&foo, 0, sizeof(foo_t));

    expect(foo.a, 0);
    expect(foo.b, 0);
    expect(foo.c, 0);
    expect(foo.d, 0);
}

void test2(void)
{
    typedef struct {
        char a;
        char b;
        char c;
        char d;
    } foo_t;
    foo_t foo;
    memset((void*)&foo, 1, sizeof foo);
    expect(foo.a, 1);
    expect(foo.b, 1);
    expect(foo.c, 1);
    expect(foo.d, 1);
}

void test3(void)
{
    typedef struct {
        char a;
        char b;
        char c;
        char d;
    } foo_t;

    foo_t foo = {1, 2, 3, 4};
    expect(foo.a, 1);
    expect(foo.b, 2);
    expect(foo.c, 3);
    expect(foo.d, 4);
}

void test4(void)
{
    typedef struct {
        union {
            char a;
            char b;
        };
        char c;
        char d;
    } foo_t;

    foo_t foo = {1, 2, 3};
    expect(foo.a, 1);
    expect(foo.b, 1);
    expect(foo.c, 2);
    expect(foo.d, 3);
}

void test5(void)
{
    typedef struct {
        union {
            struct { 
                char b;
                char c;
            };
            short a;
        };
        char d;
        char e;
    } foo_t;

    foo_t foo = {1, 1, 2, 3};
    expect(foo.a, (1 << 8) + 1);
    expect(foo.b, 1);
    expect(foo.c, 1);
    expect(foo.d, 2);
    expect(foo.e, 3);
}

void test6(void)
{
    typedef union {
        char a;
        char b;
        char c;
        char d;
    } foo_t;

    foo_t foo = {1};
    expect(foo.a, 1);
    expect(foo.b, 1);
    expect(foo.c, 1);
    expect(foo.d, 1);
}


int main(void)
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    return 0;
}
