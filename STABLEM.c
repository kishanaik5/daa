#include <stdio.h>
#include<stdbool.h>

#define SINGLE 0

int main() {
    int t, n;
    
        printf("Enter the number of men/women: ");
        scanf("%d", &n);

        // Men's and Women's preference lists and current matches
        int mList[n + 1][n + 1];
        int wList[n + 1][n + 1];
        int manCurrentMatch[n + 1];
        int womanCurrentMatch[n + 1];
        int manNextProposal[n + 1];

        // Taking inputs for Women's preference list
        printf("Enter the women's preference list:\n");
        for (int i = 1; i <= n; i++) {
            womanCurrentMatch[i] = SINGLE; // Set each woman to be single
            printf("For woman %d: ", i);
            for (int j = 1; j <= n; j++) {
                scanf("%d", &wList[i][j]);
            }
        }

        // Taking inputs for Men's preference list
        printf("Enter the men's preference list:\n");
        for (int i = 1; i <= n; i++) {
            manCurrentMatch[i] = SINGLE; // Set each man to be single
            manNextProposal[i] = 1; // Each man will start by proposing to the first woman in his list
            printf("For man %d: ", i);
            for (int j = 1; j <= n; j++) {
                scanf("%d", &mList[i][j]);
            }
        }
        
        
        bool freeManAvailable = true; // At the beginning, we have a free man available
        int m = 1; // Taking the first man as free for the first iteration

        while (freeManAvailable)
        {
            freeManAvailable = false;
            int w = mList[m][manNextProposal[m]++]; // The woman that man proposes to

            if (womanCurrentMatch[w] == SINGLE) {
                // The woman is currently free, engage (m and w)
                womanCurrentMatch[w] = m;
                manCurrentMatch[m] = w;
            } else {
                // The woman is engaged, check if it's a better proposal
                bool itsABetterProposal;
                
                // Check her preference list
                for (int y = 1; y <= n; y++) {
                    if (wList[w][y] == womanCurrentMatch[w]) {
                        itsABetterProposal = false;
                        break;
                    }
                    if (wList[w][y] == m) {
                        itsABetterProposal = true;
                        break;
                    }
                }

                if (itsABetterProposal) 
                {
                    manCurrentMatch[womanCurrentMatch[w]] = SINGLE;
                    womanCurrentMatch[w] = m;
                    manCurrentMatch[m] = w;
                }
            }

            for (int x = 1; x <= n; x++) {
                if (manCurrentMatch[x] == SINGLE) {
                    m = x;
                    freeManAvailable = true;
                    break;
                }
            }
        }

        printf("Stable Matching:\n");
        for (int i = 1; i <= n; i++) {
            printf("Couple: Man %d and Woman %d\n", i, manCurrentMatch[i]);
        }
    

    return 0;
}
