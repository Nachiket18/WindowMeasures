

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

     NOTE: We add index of element in the deque so that comparison can be made
     about the size of window and when was the last max element found.
  */

  holder.push_back(0);
  for (int i = 1; i < window; i++) {

    for (it = holder.end(); it != holder.begin(); --it) {
      if (arr[i] > arr[holder.back()] && !holder.empty()) {
        if (holder.back() == holder.front()) {
          holder.push_front(i);
        }
        holder.pop_back();
      } else {
        holder.push_back(i);
        break;
      }
    }
  }

  /* In second stage of algorithm
     1. We add the value present at deque.front() to temp array(output array)

        From element at index at window we perform
     2. If element(contains index of the input array) at front of queue is out
     of the window of the element being scanned then we remove it (window has
     shifted ahead than max element calculated).

     3. If the element currently being scanned is greater than element pointed
     by (k-1)th index in output array (Name:temp) we pop all the elements from
     the deque that are lesser than presently scanned element and add that
     element to output array (Name:temp) otherwise, we add the element at the
     front of deque to output array. If the element that is scanned is greater
     than element present at front of deque we add the current element to
     output(The notion behind this is that element present in front of deque is
     max element found during current window, if it's lesser than present
     element this measure is taken).
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

    if (arr[i] > temp[k - 1]) {
      for (it = holder.end(); it != holder.begin(); --it) {
        if (arr[i] > arr[holder.back()] && !holder.empty()) {

          if (holder.back() == holder.front()) {
            holder.push_front(i);
          }
          holder.pop_back();
        } else {
          holder.push_back(i);
          break;
        }
      }

      temp[k] = arr[i];

    } else if (arr[i] < arr[holder.front()]) {
      temp[k] = arr[holder.front()];
      holder.push_back(i);
    } else {
      temp[k] = arr[i];
      holder.push_back(i);
    }

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

