# Data Structures Lab Assignment

## Student Information

**Name:** Simrah Ahmad
**CMS-ID:** 544211

---

## Overview

This lab assignment contains six C++ programs demonstrating important data structures and their operations.

The programs cover:

1. Doubly Linked List — Creation and Traversal
2. Doubly Linked List — Insertion and Deletion
3. Circular Singly Linked List — Creation and Traversal
4. Circular Singly Linked List — Deletion
5. Stack Using Array
6. Stack Using Linked List

All programs are implemented in **C++** using dynamic memory allocation where required.

---

# Task 1 — Doubly Linked List Creation and Traversal

### Description

This program implements a **Doubly Linked List** using nodes containing:

* Data
* Pointer to the next node
* Pointer to the previous node

The list maintains both a `head` and a `tail` pointer.

### Operations

* `AddNode(int value)` — Adds a node at the end of the list.
* `PrintForward()` — Displays the list from head to tail.
* `PrintReverse()` — Displays the list from tail to head.
* `ClearList()` — Deletes all nodes from the list.

### Example

```text
Forward:
10  20  30

Reverse:
30  20  10
```

### Key Concept

A doubly linked list allows traversal in **both directions** because every node contains both `next` and `prev` pointers.

---

# Task 2 — Doubly Linked List Insertion and Deletion

### Description

This program extends the doubly linked list from Task 1 by adding insertion and deletion operations.

### Operations

* `AddNode(int value)` — Adds a node at the end.
* `InsertBefore(int position, int value)` — Inserts a new node before the specified position.
* `DeleteNode(int value)` — Deletes the first node containing the specified value.
* `PrintForward()` — Displays the list from head to tail.
* `PrintReverse()` — Displays the list from tail to head.
* `ClearList()` — Deletes all nodes.

### Example

Initial list:

```text
10  20  30
```

Insert `15` before position `2`:

```text
10  15  20  30
```

Delete `20`:

```text
10  15  30
```

### Key Concept

When inserting or deleting a node, both `next` and `prev` pointers must be updated correctly to maintain the doubly linked structure.

---

# Task 3 — Circular Singly Linked List

### Description

This program implements a **Circular Singly Linked List**.

In a circular linked list, the last node does not point to `NULL`. Instead, it points back to the first node.

```text
10 → 20 → 30
↑         ↓
└─────────┘
```

### Operations

* `AddNode(int value)` — Adds a node at the end.
* `PrintList()` — Displays each node exactly once.
* `CountNodes()` — Counts the number of nodes.
* `ClearList()` — Deletes all nodes.

### Key Concept

The last node always maintains:

```cpp
tail->next = head;
```

Therefore, traversal cannot use:

```cpp
while(temp != NULL)
```

because `temp` will never become `NULL`.

Instead, traversal stops when the pointer returns to `head`.

---

# Task 4 — Circular Singly Linked List Deletion

### Description

This program extends the circular singly linked list by implementing node deletion.

The program deletes the **first matching node** containing the given value.

### Operations

* `AddNode(int value)` — Adds a node at the end.
* `PrintList()` — Displays the circular list.
* `CountNodes()` — Counts the nodes.
* `DeleteNode(int value)` — Deletes the first matching node.
* `ClearList()` — Deletes all nodes.

### Deletion Cases

The program handles:

1. Empty list
2. Value not found
3. Only one node
4. Deleting the head
5. Deleting the tail
6. Deleting a middle node

### Example

Initial list:

```text
10 → 20 → 30 → back to 10
```

Delete `10`:

```text
20 → 30 → back to 20
```

Delete `30`:

```text
20 → back to 20
```

Delete `20`:

```text
Empty List
```

### Key Concept

After deletion, the circular property must always be maintained:

```cpp
tail->next = head;
```

---

# Task 5 — Stack Using Array

### Description

This program implements a **Stack using an array**.

The stack follows the **LIFO (Last In, First Out)** principle.

```text
Push: 10, 20, 30

Stack:

30 ← Top
20
10
```

### Operations

* `Push()` — Adds an element to the top.
* `Pop()` — Removes the top element.
* `Peek()` — Displays the top element without removing it.
* `IsEmpty()` — Checks whether the stack is empty.
* `IsFull()` — Checks whether the stack is full.
* `Display()` — Displays elements from top to bottom.

### Stack Size

The array has a fixed capacity of:

```text
5 elements
```

If the stack is full, another `Push` operation is rejected.

If the stack is empty, `Pop` and `Peek` operations are rejected.

### Example

After:

```text
Push(10)
Push(20)
Push(30)
Push(40)
Push(50)
```

The stack is:

```text
50 ← Top
40
30
20
10
```

After `Pop()`:

```text
50 is removed
```

The new top is:

```text
40
```

### Key Concept

Array-based stacks have a **fixed capacity**.

---

# Task 6 — Stack Using Linked List

### Description

This program implements a **Stack using a Linked List**.

Unlike the array-based stack, the linked stack uses dynamic memory allocation and does not have a fixed size.

The top of the stack is maintained using a pointer.

### Operations

* `Push()` — Adds a new node at the top.
* `Pop()` — Removes the top node.
* `Peek()` — Displays the top element without removing it.
* `IsEmpty()` — Checks whether the stack is empty.
* `Display()` — Displays the stack from top to bottom.
* `ClearStack()` — Deletes all remaining nodes.

### Example

After:

```text
Push(10)
Push(20)
Push(30)
```

The stack becomes:

```text
30 ← Top
20
10
```

After `Pop()`:

```text
30 is removed
```

The stack becomes:

```text
20 ← Top
10
```

### Key Concept

The linked stack follows the **LIFO** principle and uses dynamic memory allocation.

Unlike an array stack, its capacity is not fixed by an array size.

---

# Important Concepts

## 1. Doubly Linked List

Each node contains:

```text
data
next
prev
```

It supports traversal in both forward and reverse directions.

---

## 2. Circular Singly Linked List

The last node points back to the first node:

```cpp
tail->next = head;
```

Therefore, there is no `NULL` at the end of a non-empty circular list.

---

## 3. Stack

A stack follows:

**LIFO — Last In, First Out**

The element inserted last is removed first.

Example:

```text
Push: 10 → 20 → 30

Pop → 30
Pop → 20
Pop → 10
```

---

# Time Complexity

| Operation  | Doubly Linked List | Circular List | Array Stack | Linked Stack |
| ---------- | -----------------: | ------------: | ----------: | -----------: |
| Add/Push   |               O(1) |          O(1) |        O(1) |         O(1) |
| Pop/Delete |               O(n) |          O(n) |        O(1) |         O(1) |
| Search     |               O(n) |          O(n) |        O(n) |         O(n) |
| Traversal  |               O(n) |          O(n) |        O(n) |         O(n) |

> The deletion/search operations in the linked-list programs may require traversal to find the required node, so they are O(n).

---

# Conclusion

These six programs demonstrate the implementation and manipulation of fundamental data structures in C++.

The assignment covers:

* Doubly linked lists
* Circular singly linked lists
* Array-based stacks
* Linked-list-based stacks
* Dynamic memory allocation
* Pointer manipulation
* Traversal
* Insertion
* Deletion
* LIFO stack operations

The programs also demonstrate how different data structures handle memory, traversal, insertion, deletion, and storage limitations.

---

## Student

**Name:** Simrah Ahmad
**CMS-ID:** 544211
