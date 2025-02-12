#include<iostream>

using namespace std;

class FitnessTracker{
    string Username;
    int dailyStepGoal;
    int stepsTaken = 0;
    int caloriesBurned = 0;
    
    public:
    FitnessTracker(string name, int goal){
        Username = name;
        dailyStepGoal = goal;
    }
    void setStepsandCalories(int steps){
        stepsTaken += steps;
        caloriesBurned += steps * 10;
    }

    int getCalories(){
        return caloriesBurned;
    }

    int getStepsTaken(){
        return stepsTaken;
    }

    int getDailyStepsGoal(){
        return dailyStepGoal;
    }
};

int main(){
    int num;
    cout<<"Set a goal (of steps) for today"<<endl;
    cin>>num;
    FitnessTracker tracker("Laiba" , num);
    int choice;
    int steps;
    do {
        cout << "1. Calories burned\n2. Progress\n3. Update steps taken\n0. Exit\n";
        cout << "Enter your choice: "<<endl;
        cin >> choice;

        switch (choice) {
            case 1:
                cout<<"Calories Burned are: "<<tracker.getCalories()<<endl<<endl;
                break;
            case 2:
                if(tracker.getStepsTaken() >= tracker.getDailyStepsGoal()){
                    cout<<"The goal has been achieved"<<endl;
                }
                else{
                    cout<<tracker.getDailyStepsGoal() - tracker.getStepsTaken()<<" more steps need to be taken"<<endl<<endl;
                    cout<<tracker.getStepsTaken()<<" number of steps taken"<<endl<<endl;
                }
                break;
            case 3:
                cout<<"Enter number of steps taken"<<endl;
                cin>>steps;
                tracker.setStepsandCalories(steps);
                break;
            case 0:
                cout << "Exiting the program..."<< endl;
                break;
            default:
                cout << "Invalid input! Please enter a valid choice." << endl;
        }
    } while (choice != 0);
 
}