#include <stdio.h>
#define ABS(x) (x > 0 ? x : -x)
constexpr double x0 = 1, x1 = 1.2, e = 1e-2, x2 = -0.4, x3 = -0.2, e2 = 5e-5;

// Ex1:
double f(double x) {
    return x*x*x - 2*x - 1;
}
double df(double x) {
    return 3*x*x - 2;
}
double nr(double x) {
    return x - f(x)/df(x);
} 
double sec(double x0, double x1) {
    return (x0*f(x1)-x1*f(x0))/(f(x1)-f(x0));
}

// Ex2:
double f2(double x) {
    return x*x*x - 5*x*x + 17*x + 21;
}
double df2(double x) {
    return 3*x*x - 10*x + 17;
}
double ddf2(double x) {
    return 6*x - 10;
}
double bestx0() {
    for(double x = -1; x <= 1; x+=0.01) if(f2(x)*ddf2(x) > 0) return x;
    return x2;
}
double nr2(double x) {
    return x - f2(x)/df2(x);
} 
double sec2(double x0, double x1) {
    return (x0*f2(x1)-x1*f2(x0))/(f2(x1)-f2(x0));
}

double bi(double l, double r, int& c) {
    while(ABS(r-l) > e2) {
        double mid = (l+r)/2;
        if(f2(mid) > 0) r = mid;
        else l = mid;
        c++;
    }
    return l;
}

int main() {
    // a)
    puts("[0, 5]");
    printf("f(x) | ");
    int m = -1;
    for(int i = 0; i <= 5; i++) {
        printf("%d ", (int)f(i));
        if(m == -1 && i && (f(i-1) < 0) != (f(i) < 0)) m = i;
    }
    printf(" => [%d, %d]\n", m-1, m);

    // Ex1 : NR
    double r0 = x0, r1 = x1;
    int c = 0;
    while(ABS(f(r0)) > e) {
        r0 = nr(r0);
        c++;
    }
    printf("NR x%d: %.2lf\n", c, r0);

    // Ex1 : Sec
    r0 = x0;
    c = 0;
    while(ABS(f(r0)) > e) {
        if(c&1) r0 = sec(r0, r1);
        else r1 = sec(r0, r1);
        c++;
    }
    printf("SEC x%d: %.2lf\n", c, r0);


    // a)
    puts("\n[-6, 3]");
    printf("f(x) | ");
    m = -1;
    for(int i = -6; i <= 3; i++) {
        printf("%d ", (int)f2(i));
        if(m == -1 && (f(i-1) < 0) != (f(i) < 0)) m = i;
    }
    printf(" => [%d, %d]\n", m-1, m);

    // Ex2 : NR
    r0 = bestx0(), r1 = x3;
    c = 0;
    while(ABS(f2(r0)) > e2) {
        r0 = nr2(r0);
        c++;
    }
    printf("NR2 x%d: %.4lf\n", c, r0);

    // Ex2 : Sec
    r0 = x2;
    c = 0;
    while(ABS(f2(r0)) > e2) {
        if(c&1) r0 = sec2(r0, r1);
        else r1 = sec2(r0, r1);
        c++;
    }
    
    printf("SEC2 x%d: %.4lf\n", c, r0);

    c = 0;
    double b = bi(-6, 3, c);
    printf("BI2 x%d: %.4lf\n", c, b);
}
