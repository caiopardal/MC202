#ifndef HEAP_H
#define HEAP_H

typedef struct Node
{
  int v;
  int weight;
  struct Node *next;
} Node;

typedef Node *p_node;

/**
 * Checks wether the list has the element v
 */
int has_element(p_node list, int v);

/**
 * Gets the weight of an element v
 */
int get_element_weight(p_node list, int v);

/**
 * Insert an element n at the start of the list and returns the new start of the list
 */
p_node insert_at_start(p_node list, int v, int weight);

/**
 * Remove every element of the list bigger than the threshold
 */
p_node remove_bigger_elements(p_node list, int threshold);

/**
 * Destroy the list
 */
void destroy_list(p_node list);

/**
 * Item holds the priority and vertex of the element
 */
typedef struct
{
  int priority;
  int vertex;
} Item;

/**
 * Priority queue implemented with an min-heap v and an array of indices to find each element more easily
 * The element at the top of the priority queue is the one with minimum priority
 */
typedef struct
{
  Item *v;
  int *indices;
  int count, arr_size;
} PriorityQueue;

typedef PriorityQueue *p_priorityQueue;

/**
 * Swap the content of two Items a and b
 */
void swap_item(Item *a, Item *b);

/**
 * Swap the content of two ints a and b
 */
void swap_int(int *a, int *b);

/**
 * Swap the elements in the positions posA and posB
 */
void swap(p_priorityQueue pq, int posA, int posB);

/**
 * Initialize a priority queue with a maximum size of size
 */
p_priorityQueue initialize_priority_queue(int size);

/**
 * Checks wether a priority queue is empty
 */
int is_empty(p_priorityQueue pq);

/**
 * Returns the vertex of the Item at the top of the queue(minimum priority)
 */
int peek_minimum(p_priorityQueue pq);

/**
 * Gets the priority of the item with vertex v
 */
int get_priority(p_priorityQueue pq, int v);

/**
 * Add an element with vertex v and priority priority to the queue
 */
void push_element(p_priorityQueue pq, int v, int priority);

/**
 * Remove and returns(vertex) the element at the top of the priority queue(minimum priority)
 */
int pop_minimum(p_priorityQueue pq);

/**
 * Lower the priority of the Item with vertex v to new_priority
 */
void lower_priority(p_priorityQueue pq, int v, int new_priority);

/**
 * Balance the heap from bottom to top
 */
void heapify_up(p_priorityQueue pq, int k);

/**
 * Balance the heap from top to bottom
 */
void heapify_down(p_priorityQueue pq, int k);

/**
 * Free the priority queue
 */
void destroy_priority_queue(p_priorityQueue pq);

#endif // HEAP_H