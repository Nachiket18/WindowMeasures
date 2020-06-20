#include <iostream>

using namespace std;

void calcWindowMeasures(int arr[], int temp[], int window, int n) {
  int maximum = 0;
  /* This loop helps to calculate the first value of output by calculating the
   * max of elements present in window amount*/
  for (int i = 0; i < window; i++) {
    if (arr[i] > maximum) {
      maximum = arr[i];
    }
  }
  temp[window - 1] = maximum;

  int k = window - 1;
  int tmp = 0;
  int localMax = 0;

  for (int j = window; j < n; j++) {
    /*We have calculated the Max at the element earlier than the one being
     * currently pointed. Re-using it*/
    if (temp[k] < arr[j]) {
      temp[k + 1] = arr[j];
      tmp = 0;
      localMax = 0;
    } else {
      /* It's a special case where the value is lesser than max value present in
      output array for previous element. Need to compare it with elements that
      are present in current window
      */
      tmp++;
      if (arr[j] > localMax) {
        localMax = arr[j];
      }
      /* tmp used to keep track of number of elements scan. USed for comparison
       * with amount in window*/
      if (tmp < window) {
        temp[k + 1] = temp[k];
      } else
        temp[k + 1] = localMax;
    }

    k++;
  }

  for (int i = window - 1; i < n; i++) {
    cout << temp[i] << '\t';
  }
}

int main() {
  int window;
  int arr[14];
  int temp[14];
  int n = 14;

  cout << "Please enter the array for windowed measures" << endl;
  for (int i = 0; i < 14; i++) {
    cin >> arr[i];
  }
  cout << "Please enter the window" << endl;
  cin >> window;
  calcWindowMeasures(arr, temp, window, n);
}
