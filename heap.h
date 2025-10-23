#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
<<<<<<< HEAD
#include <algorithm>
=======
>>>>>>> 259bfe0f9516f8ad4b0c64298908a8ba0973172b

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> heap_;
<<<<<<< HEAD
  int m_;
  PComparator comp_;
=======
  int m_;  
  PComparator comp_; 
  
>>>>>>> 259bfe0f9516f8ad4b0c64298908a8ba0973172b

  void heapifyUp(int index);
  void heapifyDown(int index);
  int getParent(int index) const;
<<<<<<< HEAD
  int getChild(int index, int cNum) const;
=======
  int getChild(int index, int childNum) const;
>>>>>>> 259bfe0f9516f8ad4b0c64298908a8ba0973172b
};

// Add implementation of member functions here

<<<<<<< HEAD
//constructor
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) : m_(m), comp_(c) {
}

//destructor
=======
// Constructor
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) : m_(m), comp_(c) {
    if (m < 2) {
        throw std::invalid_argument("m must be >= 2");
    }
}

// Destructor
>>>>>>> 259bfe0f9516f8ad4b0c64298908a8ba0973172b
template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap() {
}

<<<<<<< HEAD
//empty
template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty()const {
	return heap_.empty();
}

//size
template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const {
	return heap_.size();
=======
// Empty function
template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const {
    return heap_.empty();
}

// Size function
template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const {
    return heap_.size();
}

// Push function
template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item) {
    heap_.push_back(item);
    heapifyUp(heap_.size() - 1);
>>>>>>> 259bfe0f9516f8ad4b0c64298908a8ba0973172b
}

//push
template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item) {
	heap_.push_back(item);
	heapifyUp(heap_.size() - 1);
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
<<<<<<< HEAD
		throw std::underflow_error("Heap is empty");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
	return heap_[0];


=======
    throw std::underflow_error("Heap is empty");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return heap_[0];
>>>>>>> 259bfe0f9516f8ad4b0c64298908a8ba0973172b
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
<<<<<<< HEAD
		throw std::underflow_error("Heap is empty");

=======
    throw std::underflow_error("Heap is empty");
>>>>>>> 259bfe0f9516f8ad4b0c64298908a8ba0973172b
  }
  
  heap_[0] = heap_.back();
  heap_.pop_back();
  
  if (!empty()) {
    heapifyDown(0);
  }
}

<<<<<<< HEAD
	heap_[0] = heap_.back();
	heap_.pop_back();

	if (!empty()) {
		heapifyDown(0);
	}

}

//my helper functions

template <typename T, typename PComparator>
int Heap<T, PComparator>::getParent(int index) const {
	return (index - 1) / m_;
}

template <typename T, typename PComparator>
int Heap<T, PComparator>::getChild(int index, int cNum) const {
	return m_ * index + cNum + 1;
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::heapifyUp(int index) {
	if (index == 0) return;

	int parent = getParent(index);

	if (comp_(heap_[index], heap_[parent])) {
		std::swap(heap_[index], heap_[parent]);
		heapifyUp(parent);
	}
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::heapifyDown(int index) {
	int mIndex = -1;

	for (int i = 0; i < m_; i++) {
		int childIndex = getChild(index, i);
		if (childIndex < static_cast<int>(heap_.size())) {
			if (mIndex == -1 || comp_(heap_[childIndex], heap_[mIndex])) {
				mIndex = childIndex;
			}
		}
	}

	if (mIndex != -1 && comp_(heap_[mIndex], heap_[index])) {
		std::swap(heap_[index], heap_[mIndex]);
		heapifyDown(mIndex);
	}
=======
// Helper functions

template <typename T, typename PComparator>
int Heap<T, PComparator>::getParent(int index) const {
    return (index - 1) / m_;
}

template <typename T, typename PComparator>
int Heap<T, PComparator>::getChild(int index, int childNum) const {
    return m_ * index + childNum + 1;
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::heapifyUp(int index) {
    if (index == 0) return; 
    
    int parent = getParent(index);
    
    if (comp_(heap_[index], heap_[parent])) {
        std::swap(heap_[index], heap_[parent]);
        heapifyUp(parent);
    }
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::heapifyDown(int index) {
    int bestIndex = -1;
    
    for (int i = 0; i < m_; i++) {
        int childIndex = getChild(index, i);
        if (childIndex < static_cast<int>(heap_.size())) {
            if (bestIndex == -1 || comp_(heap_[childIndex], heap_[bestIndex])) {
                bestIndex = childIndex;
            }
        }
    }
    
    if (bestIndex != -1 && comp_(heap_[bestIndex], heap_[index])) {
        std::swap(heap_[index], heap_[bestIndex]);
        heapifyDown(bestIndex);
    }
>>>>>>> 259bfe0f9516f8ad4b0c64298908a8ba0973172b
}

#endif

