#include <stdio.h>

// simulate dueling between participants
void duel(int left, int right, int *index, int *ability) {
    if (ability[left] > ability[right]) {
        ability[left] -= ability[right];  // reft wins
        *index = left;
    } else if (ability[left] < ability[right]) {
        ability[right] -= ability[left];  // right wins
        *index = right ;
    } else {
        // same ability -> smaller index wins
        *index = left;
        ability[left] -= ability[right];
    }
}

// find the champion
void find_champion(int participants[], int start, int end, int *champion, int *champion_ability) {
    // one participant -> champion
    if (start == end) {
        *champion = start;
        *champion_ability = participants[start];
        return;
    }

    int mid = (start + end) / 2;

    // recursively divide into two halves
    int left, left_ability;
    int right, right_ability;
    find_champion(participants, start, mid, &left, &left_ability);
    find_champion(participants, mid + 1, end, &right, &right_ability);

    // left and right halves
    duel(left, right, champion, participants);
    *champion_ability = participants[*champion];
}

int main() {
    int n; 
    scanf("%d", &n);

    int participants[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &participants[i]);
    }

    int champion, champion_ability;

    // recursively from index 0 to n-1
    find_champion(participants, 0, n - 1, &champion, &champion_ability);

    printf("%d %d\n", champion, champion_ability);

    return 0;
}
