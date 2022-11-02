#include<stdio.h>

struct Distance {
    int feet;
    int inch;
};

struct Distance add_distance(struct Distance d1, struct Distance d2) {
    struct Distance answer;

    answer.feet = d1.feet + d2.feet;
    answer.inch = d1.inch + d2.inch;

    return answer;
}

int main() {
    struct Distance d1;
    struct Distance d2;

    d1.feet = 5;
    d1.inch = 10;

    d2.feet = 3;
    d2.inch = 1;

    struct Distance answer = add_distance(d1, d2);

    printf("%d, %d\n", answer.feet, answer.inch);
    return 0;
}