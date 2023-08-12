/*
https://omegaup.com/arena/problem/jardin
Question P:
 It does not matter how many children intersect each other, the scarf always keeps moving in the original direction.
Question N:
We already know how to get the position of the scarf. So, given the end position we can infere
its starting position and hence, the index of the children that owns it. So now, we are only interested
in knowing the end position of the child of interest.

To determine the end position of the child. We assume that it goes in the original direction
until it finds another child moving in the opposite direction. It takes them d / 2 steps to
to intersect, where d is the distance between them.
Example 1: childA = {4, 1} childB = {14, -1}. A is at 4 while B is at 14. They are moving towards each other
and the distance between them is d = 14 - 4 = 10. They intersect at 9, after each has moved 5 steps.
Once the original child changes its moving direction, then it will intersect with another child.
The tricky part is to determine at which point the original child changes direction.
After some analysis, it can be observed that the first time the child changes direction is when he arrives
at the middle point between himself and the child that was moving in opposite direction at starting time.
This remains true regardless of the amount of children between them.
Example 2: A={2,1} B={4,1} C={6,1}, D={20, -1}, E={50,-1}
 In this case the first time childA changes direction is at position 11. That is because the distance
 between A and D is 20 - 2 = 18. Then, 18/2=9. A starting position is 2 + 9 gives 11.
 Now, the interesting part is that A and D never intersect. However, D meets with C and changes it direction
 which later meets with B, and finally B meets with A. Understanding this is the key to undestand the solution.

Now, once the child has changed its direction, he is moving to the other side. The above statement
remains true. He is going to change his direction at the middle point between him and the child that was
moving towards him at the starting time. Note that the distance between them hasn't changed because
they were moving in the same direction.
Example 3:  X={-2,1} A={2,1} B={4,1} C={6,1}, D={20, -1}, E={50,-1}
 We said before that A changes its direction when he reaches position 11 after 9 steps.
 That also means that A changes it direction at time t=9. Now, child X starts at position -2 and at
 time t=9 is at position 7. Note how the distance between X and A at the beginning was 4 and it remains
 the same at t=9.
 At t=11, X and A meet at position 9. At this time, A changes direction again.

Now the question is, at what time and position A changes direction again? After some deep analysis
and simulation, we can determine that we can't rely on the first children that was moving on towards us
at the beginning (child D in example above) because we no longer know the direction he is moving.
However, we can use the info from the second child that was moving towards us at the beggining. That
is child E in the example. Why? Because that child has been moving towards us the whole time.
Then, based on the assumptions we made in example 2, we can generalize the problem and determine that
any change in direction is affected only by the children that were moving towards us at the beginning.
Once we change direction because of one of them, we use the info from the next.
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

  bool operator<(const Child& rhs) const {
    return position < rhs.position;
  }
};

// Update the position of the child when it moves towards next child. If no other child, then it keeps
// moving until time runs out.
void updatePosition(Child& child, const int* otherChildPosition, int& currentTime, const int& targetTime) {
  int v = otherChildPosition ? *otherChildPosition : 0;
  // cout << "Update: {" << child.position << "," << child.direction << "} with " << v << ". Current time: " << currentTime << endl;

  if (otherChildPosition) {
    // First update original otherChild position. The othetChild has been moving since the start. Hence, we just add the amount of steps
    // it moved since the beginning.
    int othetChildDirection = child.direction * -1; // Moving towards us.
    int currentOtherChildPosition = *otherChildPosition + currentTime * othetChildDirection;
    // cout << "otherChild current position=" << currentOtherChildPosition << endl;

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
    if (timeToChange > remainingTime) {
      // The child won't reach the other child before target time. So it will never change direction again.
      child.position += child.direction * remainingTime;
      currentTime = targetTime;
    }
    else {
      // Update position and direction.
      child.position += child.direction * steps;
      child.direction *= -1;
      currentTime += timeToChange;
    }
  }
  else {
    // No more children to the right, hence this child never changes direction again.
    int remainingTime = targetTime - currentTime;
    child.position += remainingTime * child.direction;
    currentTime = targetTime;
  }
}

int main() {
  // std::cin.tie(nullptr);
  // std::ios_base::sync_with_stdio(false);

  int numChildren;
  cin >> numChildren;
  vector<Child> children(numChildren);
  std::map<int, Child> indexToChildren;
  for (int i = 0; i < children.size(); ++i) {
    auto& child = children[i];
    child.index = i + 1;
    scanf("%d %d", &child.position, &child.direction);
    // cin >> child.position >> child.direction;
    indexToChildren[child.index] = child;
  }
  sort(children.begin(), children.end());

  int numQueries;
  cin >> numQueries;
  while (numQueries--) {
    char choice;
    int childIdx;
    int targetTime;
    // cin >> choice >> childIdx >> targetTime;
    scanf("\n%c %d %d", &choice, &childIdx, &targetTime);
    if (choice == 'P') {
      // cout << "Question P: " << childIdx << " " << targetTime << endl;
      const auto& child = indexToChildren[childIdx];
      // cout << child.position + child.direction * targetTime << "\n";
      printf("%d\n", child.position + child.direction * targetTime);
    }
    else {
      // cout << "Question N: " << childIdx << " " << targetTime << endl;
      Child child;
      int actualChildIndex = 0;
      for (int i = 0; i < children.size(); ++i) {
        if (children[i].index == childIdx) {
          child = children[i];
          actualChildIndex = i;
          break;
        }
      }

      // Determine this child position based on his changes of direction
      int currentTime = 0;
      int leftChildIdx = actualChildIndex - 1;
      int rightChildIdx = actualChildIndex + 1;
      while (currentTime < targetTime) {
        const int* nextChildPosition = nullptr;
        if (child.direction == 1) {
          while (rightChildIdx < children.size() && children[rightChildIdx].direction == 1) {
            rightChildIdx++;
          }
          if (rightChildIdx < children.size()) {
            nextChildPosition = &children[rightChildIdx++].position;
          }
        }
        else {
          while (leftChildIdx >= 0 && children[leftChildIdx].direction == -1) {
            leftChildIdx--;
          }
          if (leftChildIdx >= 0) {
            nextChildPosition = &children[leftChildIdx--].position;
          }
        }
        updatePosition(child, nextChildPosition, currentTime, targetTime);
        // cout << "After update iteracion " << itr << ": pos=" << child.position << " t=" << currentTime << endl;
      }
      // We know the end position of the child. Now, check which scarf it at this position.
      // cout << "Child position: " << child.position << endl;
      for (auto& c : children) {
        int scarfStartingPosition = child.position - targetTime * child.direction;
        if (c.position == scarfStartingPosition) {
          // cout << i + 1 << "\n"; //1-index
          printf("%d\n", c.index);
          break;
        }
      }
    }
  }

  return 0;
}