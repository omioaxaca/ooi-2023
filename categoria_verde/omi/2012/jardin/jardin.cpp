/*
https://omegaup.com/arena/problem/jardin
Question P:
 It does not matter how many children intersect each other, the scarf always keeps moving in the original direction.
 This is true because even when the scarf is being carried out by a different children, it will always move in the original direction.
Question N:
 From question P we learnt that the scarf always moves in one direction. If there were no other children, then this child
will carry his own scarf forever. However, because it intercepts with others it will exchange his scarf.
Since we said that scarfs only move in one direction, we can infere that all scarfs that this child will ever intersect are the ones
moving towards him. Note that at each step, all of these scarfs move closer to this child. It is impossible that this child ever
carries out scarfs from children moving against him because at each step they will get further away from him.

Example 1:
Given a child A, imagine we call L to all children to his left moving towards him and R to all children
to his right moving towards him.
(L1->) (L2->) (L3->) (A->) (<-R1) (<-R2)
At start, A carries his scarf. At some point it gets R1's scarf, at a later point L3's, then R2's and finally L2's. 
Note that even when L1's scarf moves towards A, it never reaches A because after getting the scarf from L2, A keeps
moving to the right and never changes direction again.

Now the question is: at which point this children exchanges his scarf? The answer is, every time it intersect the scarf of a
children moving towards him. Note that at this time, the child also changes direction.

After some analysis, it can be observed that the first time the child changes direction is when he arrives
at the middle point between himself and the scarf that was moving towards him at starting time.
This remains true regardless of the amount of children between them (as pointed out in Question P).
Example 2: A={2,1} B={4,1} C={6,1}, D={20, -1}, E={50,-1}
 In this case the first time childA changes direction is at position 11. That is because the distance
 between A and D is 20 - 2 = 18. Then, 18/2=9. A starting position is 2 + 9 gives 11.

Now, once the child has changed its direction, he is moving to the other side. The above statement
remains true. He is going to exchange his scarf at the middle point between him and the scarf that was
moving towards him at the starting time.
Example 3:  X={-2,1} A={2,1} B={4,1} C={6,1}, D={20, -1}, E={50,-1}
 We said before that A changes his direction when he reaches position 11 after 9 steps.
 That also means that A changes his direction at time t=9. Now, X's scarf starts at position -2 and at
 time t=9 is at position 7.
 At t=11, X and A meet at position 9. At this time, A gets X's scarf and changes moving direction.

The same behavior will repeat until:
a) the child has intersected all scarfs that were moving towards him.
b) the child never changes direction again.
c) the time runs out.

We can simulate the intersections with all scarfs, that has O(n/2) complexity for each query, where n can be 10^6.
Given the amount of queries is 50, overal complexity is 25*10^6= 2.5*10^7.
We need to be very very careful in the implementation, since the algorithm needs to be linear.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

struct Child {
  int index;
  int position;
  int direction;
  int scarf;

  bool operator<(const Child& rhs) const {
    return position < rhs.position;
  }
};

// Update the position of the child when it moves towards next child. If no other child, then it keeps
// moving until time runs out.
void updatePosition(Child& child, const Child* otherChild, int& currentTime, const int& targetTime) {
  if (otherChild) {
    // First update original otherChild position. The otherChild has been moving since the start. Hence, we just add the amount of steps
    // it moved since the beginning.
    int currentOtherChildPosition = otherChild->position + currentTime * otherChild->direction;

    int distance = abs(currentOtherChildPosition - child.position);
    // Compute amount of steps to change direction.
    // Steps is floor(distance / 2). Use floor because if they met in the half of a step
    // then they change direction for the other half.
    // Example: A=1 and B=6. Distance is 5. They met after 2.5 steps. A's new position is
    // 1 + 2.5 - 0.5 = 3. Note that the -0.5 is because at 2.5, he starts going the other direction.
    int steps = floor(distance / 2.0);
    // Time to change direction. It rounds up because even if they met at half of step, they will only
    // arrive to the new position after the step is complete.
    int timeToChange = ceil(distance / 2.0);

    int remainingTime = targetTime - currentTime;
    if (timeToChange <= remainingTime) {
      // This child intercepts with the other child.
      child.position += child.direction * steps;
      child.direction *= -1;
      child.scarf = otherChild->index; // He gets the scarf from the other child.
      currentTime += timeToChange;
    }
    else {
      // The child won't reach the other child before target time. So he will never change direction again.
      child.position += child.direction * remainingTime;
      currentTime = targetTime;
    }
  }
  else {
    // No more children moving towards this child, hence this child never changes direction again.
    int remainingTime = targetTime - currentTime;
    child.position += remainingTime * child.direction;
    currentTime = targetTime;
  }
}

// Return first element greater then target.
int lower_bound(const std::vector<Child>& children, int target) {
  int lo = 0;
  int hi = children.size() - 1;
  while (lo < hi) {
    int mid = lo + (hi - lo) / 2;
    if (children[mid].position > target) {
      hi = mid;
    }
    else {
      lo = mid + 1;
    }
  }
  if (children[lo].position > target) {
    return lo;
  }
  return -1;
}

// Return last element smaller than target.
int upper_bound(const std::vector<Child>& children, int target) {
  int lo = 0;
  int hi = children.size() - 1;
  while (lo < hi) {
    int mid = lo + (hi - lo + 1) / 2;
    if (children[mid].position < target) {
      lo = mid;
    }
    else {
      hi = mid - 1;
    }
  }
  if (children[lo].position < target) {
    return lo;
  }
  return children.size();
}

int main() {
  int numChildren;
  scanf("%d", &numChildren);

  // Store the children based on the direction they move. This makes easy to query
  // which is the next scarf that the child will get in O(1) time.
  vector<Child> childrenMovingLeft;
  vector<Child> childrenMovingRight;
  // Keep a dictionary from original index to the children.
  vector<Child> indexToChildren(numChildren+1);
  for (int i = 0; i < numChildren; ++i) {
    Child child;
    child.index = i + 1;
    child.scarf = child.index; // He carries out his own scarf.
    scanf("%d %d", &child.position, &child.direction);
    if (child.direction == 1) {
      childrenMovingRight.push_back(child);
    }
    else {
      childrenMovingLeft.push_back(child);
    }
    indexToChildren[child.index] = child;
  }
  // Sort children by its position.
  sort(childrenMovingRight.begin(), childrenMovingRight.end());
  sort(childrenMovingLeft.begin(), childrenMovingLeft.end());

  int numQueries;
  scanf("%d", &numQueries);
  while (numQueries--) {
    char choice;
    int childIdx;
    int targetTime;
    scanf("\n%c %d %d", &choice, &childIdx, &targetTime);
    if (choice == 'P') {
      const auto& child = indexToChildren[childIdx];
      printf("%d\n", child.position + child.direction * targetTime);
    }
    else {
      auto child = indexToChildren[childIdx];
      // Get the closest children moving towards this child. Use binary search to keep this O(log2n)
      // Child moving towards me from left to right should have a position less than me.
      int right = upper_bound(childrenMovingRight, child.position);
      // Child moving towards me from right to left should have a position greater than me.
      int left = lower_bound(childrenMovingLeft, child.position);

      // Determine this child position based on his changes of direction
      int currentTime = 0;
      while (currentTime < targetTime) {
        // Get the next child that this child is going to intercept.
        const Child* otherChild = nullptr;
        if (child.direction == 1) {
          if (left < childrenMovingLeft.size()) {
            otherChild = &childrenMovingLeft[left++];
          }
        }
        else {
          if (right >= 0) {
            otherChild = &childrenMovingRight[right--];
          }
        }
        updatePosition(child, otherChild, currentTime, targetTime);
      }
      printf("%d\n", child.scarf);
    }
  }
  return 0;
}