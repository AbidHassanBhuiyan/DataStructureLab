#include <iostream>
using namespace std;

int main() {
    int arr[10];

    cout<<"Enter 10 integer elements:" <<endl;


    for (int i = 0; i < 10; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }

    int closestSum = arr[0] + arr[1];
    int element1 = arr[0];
    int element2 = arr[1];

    for (int i = 0; i < 10; i++) {
        for (int j = i + 1; j < 10; j++) {
            int currentSum = arr[i] + arr[j];
            if ((currentSum)<(closestSum)) {
                closestSum = currentSum;
                element1 = arr[i];
                element2 = arr[j];
            }
        }
    }
    cout << "Two elements with the sum closest to zero: "<< element1<<" and "<< element2 <<endl;
    cout << "Sum: "<<closestSum<<endl;

    return 0;
}
