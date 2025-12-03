#include <assert.h>

int add(int a, int b) {
    int c = a + b;
    return c;
}

int main() {
    int x;
    int y;
    __CPROVER_assume(x > 0 && y > 0);
    int result = add(x, y);

    assert(result > 0); // verify no overflow
    return 0;
}
