#include<iostream>
using namespace std;

class FitnessTracker {
    string userName;
    int dailyStepsGoal;
    int stepsTaken;
    float caloriesBurned;
    float caloriesBurnedGoal;
    float perStepCaloriesBurned;

public:
    FitnessTracker(string username) {
        userName = username;
    }

    void setSteps(int StepsTaken, int DailyStepsGoal,float PerStepCaloriesBurned) {
        stepsTaken = StepsTaken;
       dailyStepsGoal = DailyStepsGoal;
       perStepCaloriesBurned = PerStepCaloriesBurned;
    }

    void calculateCalories() {
        
        caloriesBurned = perStepCaloriesBurned * stepsTaken;
        caloriesBurnedGoal = dailyStepsGoal * perStepCaloriesBurned;
        cout << "EXPECTED CALORIES TO BE BURNED: " << caloriesBurnedGoal << endl;
        cout << "ACTUAL CALORIES BURNED: " << caloriesBurned << endl;
    }

    void notify() {
  

        if (dailyStepsGoal > stepsTaken) {
            int remain = dailyStepsGoal - stepsTaken;
            caloriesBurned = remain * perStepCaloriesBurned;
            cout << caloriesBurned << " CALORIES REQUIRED TO COMPLETE YOUR GOAL" << endl;
        } else {
            cout << "YOU HAVE ACHIEVED YOUR GOAL." << endl;
        }
    }

    void display() {
        cout << "NAME: " << userName << endl;
        cout << "DAILY STEPS GOAL: " << dailyStepsGoal << endl;
        cout << "STEPS TAKEN: " << stepsTaken << endl;
        cout << "EXPECTED CALORIES BURNED: " << caloriesBurnedGoal << endl;
        cout << "ACTUAL CALORIES BURNED: " << caloriesBurned << endl;
    }
};

int main() {
    FitnessTracker tracker("MUZAMIL ALI SULEMAN");
    tracker.setSteps(8000, 10000,0.8);
    tracker.calculateCalories();
    tracker.notify();
    tracker.display();

    return 0;
}