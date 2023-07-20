#include <stdio.h>
#include <stdbool.h>

#define N 3

void stableMatching(int men[][N], int women[][N]) {
    // Array which stores women partner
    int wPartner[N];
    
    // Array which says where the ith man is free or no
    bool mFree[N];

    // initialization
    for (int i = 0; i < N; i++) {
        wPartner[i] = -1;
        mFree[i] = false;
    }
    
    // freeCount says, how many mens are free
    int freeCount = N;
  

    while (freeCount > 0) {
        
        // Identify the free men
        int m;
        for (m = 0; m < N; m++)
            if (!mFree[m])
                break;


        for (int i=0; i<N && !mFree[m]; i++) {
            int w = men[m][i];
            if (wPartner[N-w] == -1) {
                wPartner[N-w] = m;
                mFree[m] = true;
                freeCount--;
            } else {
                int m1 = wPartner[N-w];
  
                if (women[N-w][m] < women[N-w][m1]) {
                    wPartner[N-w] = m;
                    mFree[m] = true;
                    mFree[m1] = false;
                }
            }
        }
    }
  
    printf("Woman\tMan\n");
    for (int i = 0; i < N; i++)
        printf("%d\t\t%d\n", i+1, wPartner[i]+N+1);
}

int main() {
    int men[N][N] = {{1,2,3},{2,3,1},{3,1,2}};
  
    int women[N][N] = {{4,5,6},{5,4,6},{4,5,6}};
    
    stableMatching(men, women);
  
    return 0;
}
