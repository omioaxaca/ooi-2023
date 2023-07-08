// https://omegaup.com/arena/ooi-2023-verde-f4/#problems/Ordenando-numeros-con-pilas
#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100002;

class Bit {
  public:
    Bit(int numElements) :
      tree(numElements + 1, 0), // 1-indexed
      maxIdx(numElements) {}

    int getSum(int l, int r) {
      return query(r) - query(l - 1);
    }

    int query(int idx) {
      int sum = 0;
      while (idx > 0) {
        sum += tree[idx];
        idx -= (idx & -idx);
      }
      return sum;
    }

    void update(int idx, int val) {
      while (idx <= maxIdx) {
        tree[idx] += val;
        idx += (idx & -idx);
      }
    }


  private:
    vector<int> tree;
    int maxIdx;
};

struct StackInfo {
  int start;
  int end;

  bool contains(int idx) {
    return idx >= start && idx <= end;
  }
};

int main() {
  int elementsA, elementsB;
  cin >> elementsA >> elementsB;
  int numElements = elementsA + elementsB;

  // Use a vector to store the data from the stacks.
  std::vector<int> elements(numElements + 1);
  for (int i = 1; i <= elementsA; ++i) {
    int x;
    cin >> x;
    elements[i] = x;
  }
  for (int i = 1; i <= elementsB; ++i) {
    int x;
    cin >> x;
    elements[elements.size() - i] = x;
  }
  // Set the boundaries of each stack within the elements' array.
  StackInfo stackA = {1, elementsA};
  StackInfo stackB = {elementsA + 1, numElements};

  // Map each value to the index they are placed in the array.
  std::vector<int> valueToIndex(numElements + 1); // +1 because values are 1-indexed.
  for (int i = 0; i < elements.size(); ++i) {
    valueToIndex[elements[i]] = i;
  }

  // Simulate the sorting.
  // Use a BIT to mark the elements already removed from the stack.
  Bit removedElements(numElements);
  for (int value = 1; value <= numElements; ++value) {
    int elementIdx = valueToIndex[value];

    if (stackA.contains(elementIdx)) {
      int elementsToMove = stackA.end - elementIdx;
      elementsToMove -= removedElements.getSum(elementIdx, stackA.end);
      if (elementsToMove > 0) {
        std::cout << elementsToMove << "\n";
      }
      std::cout << "A\n";
      // Update the stacks boundaries.
      stackA.end = elementIdx;
      stackB.start = elementIdx + 1;
    }
    else {
      // element is in stack B
      int elementsToMove = elementIdx - stackB.start;
      elementsToMove -= removedElements.getSum(stackB.start, elementIdx);
      if (elementsToMove > 0) {
        std::cout << -elementsToMove << "\n";
      }
      std::cout << "B\n";
      // Update the stacks boundaries.
      stackA.end = elementIdx - 1;
      stackB.start = elementIdx;
    }
    // Mark the element as removed.
    removedElements.update(elementIdx, 1);
  }

  return 0;
}