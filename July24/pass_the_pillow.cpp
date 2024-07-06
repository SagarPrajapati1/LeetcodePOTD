// simulation


class Solution {
public:
    int passThePillow(int n, int time) {
        int currentPillowPosition = 1;
        int currentTime = 0;
        int direction = 1;
        while (currentTime < time) {
            if (0 < currentPillowPosition + direction &&
                currentPillowPosition + direction <= n) {
                currentPillowPosition += direction;
                currentTime++;
            } else {
                // Reverse the direction if the next position is out of bounds
                direction *= -1;
            }
        }
        return currentPillowPosition;
    }
};

// math

class Solution {
public:
    int passThePillow(int n, int time) {
        // Calculate the number of complete rounds of pillow passing
        int fullRounds = time / (n - 1);

        // Calculate the remaining time after complete rounds
        int extraTime = time % (n - 1);

        // Determine the position of the person holding the pillow
        // If fullRounds is even, the pillow is moving forward.
        // If fullRounds is odd, the pillow is moving backward.
        if (fullRounds % 2 == 0) {
            return extraTime + 1;  // Position when moving forward
        } else {
            return n - extraTime;  // Position when moving backward
        }
    }
};


class Solution {
public:
    int passThePillow(int n, int time) {
        bool flag = 0;
        int ans = 1;
        while(time--) {
            if(ans == n) flag = 1;
            if(ans == 1) flag = 0;

            if(flag == 0){
                ans++;
            }
            else if(flag == 1) ans--;
        }    
        return ans;
    }
};




