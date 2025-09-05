#include <stdio.h>
#include <stdlib.h>
#include <limits.h>



int ninjaTraining(int n, int** points, int index_to_avoid, int total_cols){
	if(n==total_cols) return 0;
	int answer = INT_MIN;
	for(int j =0; j<3; j++){
		int points_earned = 0;
		if(j == index_to_avoid) continue;
			points_earned= points[n][j]+ninjaTraining(n+1, points, j, total_cols);
			if(points_earned>answer) answer = points_earned;
	}
return answer;

	}


int main() {
    int days = 3; 
    int activities = 3; 

    int** points = (int**)malloc(days * sizeof(int*));
    for (int i = 0; i < days; i++) {
        points[i] = (int*)malloc(activities * sizeof(int));
    }

    int arr[3][3] = {
        {10, 40, 70},
        {20, 50, 80},
        {30, 60, 90}
    };

    for (int i = 0; i < days; i++) {
        for (int j = 0; j < activities; j++) {
            points[i][j] = arr[i][j];
        }
    }

    int result = ninjaTraining(0, points, -1, days);
    printf("Maximum points: %d\n", result);

    for (int i = 0; i < days; i++) {
        free(points[i]);
    }
    free(points);

    return 0;
}




