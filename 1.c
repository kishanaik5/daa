#include <stdio.h>
#include <stdbool.h>

#define S 0

int main() {
    int n;
    printf("Enter the number of men/women:");
    scanf("%d", &n);

    int mlist[n + 1][n + 1];
    int wlist[n + 1][n + 1];
    int mancurrentmatch[n + 1];
    int womencurrentmatch[n + 1];
    int mannextproposal[n + 1];

    printf("Enter the women's preference list:\n");
    for (int i = 1; i <= n; i++) {
        womencurrentmatch[i] = S;
        printf("For women %d:", i);
        for (int j = 1; j <= n; j++) {
            scanf("%d", &wlist[i][j]);
        }
    }

    printf("Enter the men preference list:\n");
    for (int i = 1; i <= n; i++) {
        mancurrentmatch[i] = S;
        mannextproposal[i] = 1;
        printf("For men %d:", i);
        for (int j = 1; j <= n; j++) {
            scanf("%d", &mlist[i][j]);
        }
    }

    bool freemanavail = true;
    int m = 1;

    while (freemanavail) {
        freemanavail = false;
        int w = mlist[m][mannextproposal[m]++];

        if (womencurrentmatch[w] == S) {
            womencurrentmatch[w] = m;
            mancurrentmatch[m] = w;
        } else {
            bool itisbetterproposal = false;
            for (int y = 1; y <= n; y++) {
                if (wlist[w][y] == womencurrentmatch[w]) {
                    break;
                }
                if (wlist[w][y] == m) {
                    itisbetterproposal = true;
                    break;
                }
            }
            if (itisbetterproposal) {
                mancurrentmatch[womencurrentmatch[w]] = S;
                womencurrentmatch[w] = m;
                mancurrentmatch[m] = w;
            }
        }

        for (int x = 1; x <= n; x++) {
            if (mancurrentmatch[x] == S) {
                m = x;
                freemanavail = true;
                break;
            }
        }
    }

    printf("Stable matching:\n");
    for (int i = 1; i <= n; i++) {
        printf("Couple: man %d and woman %d\n", i, mancurrentmatch[i]);
    }

    return 0;
}
