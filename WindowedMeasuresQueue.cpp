
#include <deque>
#include <iostream>

using namespace std;

void calcWindowMeasureswithQueue(int arr[], int temp[], int window, int n) {

  deque<int> holder;
  deque<int>::iterator it;
  int k = 0;

  /* Stage 1 - We calculate the maximum value during first window elements.
              The dequeue structure works - if the current element is greater
     than holder.back() then we pop it otherwise insert it at back.
  */

  holder.push_back(0);
  for (int i = 1; i < window; i++) {

    for (it = holder.end(); it != holder.begin(); --it) {
      if (arr[i] > arr[holder.back()] && !holder.empty())
        holder.pop_back();
      else {
        holder.push_back(i);
        break;
      }
    }
  }

  /*  Code used while testing
  for (it = holder.begin(); it != holder.end(); ++it){
      cout << '\t' << *it;
  }
  */

  /* In second stage of algorithm
     1. We add the value present at deque.front to temp array(output array)

        From element at index at window we perform
     2. If element(contains index of the input array) at front of queue is out
     of the window of the element being scanned then we remove it (window has
     shifted ahead than max element calculated).

     3. If the element (contains index of the input array ) at back is lesser
     than that of element being scanned, we pop it. We break the loop once such
     element is found

  */

  k = window - 1;
  temp[k] = arr[holder.front()];
  k++;
  for (int i = window; i < n; i++) {
    // printing the largest element of the previous window before moving forward
    deque<int>::iterator it1;
    deque<int>::iterator it2;

    for (it1 = holder.begin(); it1 != holder.end(); ++it1) {
      if (holder.front() < i - (window - 1)) {
        holder.pop_front();
      } else
        break;
    }

    for (it2 = holder.end(); it2 != holder.begin(); --it2) {
      if (arr[holder.back()] < arr[i]) {
        holder.pop_back();
      } else
        break;
    }

    holder.push_back(i);

    temp[k] = arr[holder.front()];

    k++;
  }

  for (int i = window - 1; i < n; i++) {
    cout << temp[i] << '\t';
  }
}

int main() {
  int window;
  int n;

  cout << "Please enter the number of elements";
  cin >> n;

  int arr[n];
  int temp[n];

  cout << "Please enter the array for windowed measures" << endl;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  cout << "Please enter the window" << endl;
  cin >> window;
  calcWindowMeasureswithQueue(arr, temp, window, n);
}
