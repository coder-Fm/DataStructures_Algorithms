### Linked Lists
A Linked List is a data structure with zero or several elements. Each element contains a value and link(s) to the other elements. Depending on the number of links, that could be singly linked list, doubly linked list and multiply linked list.

#### Sentinel nodes
Sentinel nodes are widely used in the trees and linked lists as pseudo-heads, pseudo-tails, etc. They serve as the guardians, as the name suggests, and usually they do not hold any data.

#### Sentinel nodes in a Singly Linked list
```Java
public class ListNode {
  // All nodes in our linked list have a type
  // ListNode: (value)+(link to next element)
  int val;
  ListNode next;
  ListNode(int x) {
    val = x;
  }
}
class MyLinkedList {
  int size;

  // sentinel node used as pseudo-head, type: ListNode
  ListNode head;
  public MyLinkedList() {
    size = 0;
    head = new ListNode(0);
  }
}
```
#### Singly Linked list : Add at Index, Add at Head, and Add at Tail
1. Find the predecessor of the node to insert. If the node to be inserted at head, its predecessor is a sentinel head. If the node is to be inserted at tail, its predecessor is the last node.
2. Insert the node by changing the link to the next node.

**Add at Index**
To add a node of value _val_ before the index-th node, we check if the index equal to the length of the linked list, we append node to the end of the linked list.
If the index is greater than the length of the list, the node will be inserted.

```Java
public void addAtIndex(int index, int val) {
  // if index is greater than the length of list, do nothing,
  // node will not be inserted
  if (index > size) {
    return;
  }
  // if index is less than zero = negative, we insert node
  // at the head of list
  if (index < 0) {
    index = 0;
  }
  // increment the size of the linked list by 1 and find the predecessor of
  // the node to be added
  ++size;
  ListNode pred = head;
  for (int i = 0; i < index; ++i) {
    pred = pred.next;
  }
  // node to be added
  ListNode toAdd = new ListNode(val);
  toAdd.next = pred.next;
  pred.next = toAdd;
}
```

#### Singly Linked list : Delete at Index
1. Find the predecessor
2. Delete node by changing the links to the next node.

```Java
public void deleteAtIndex(int index) {
  // if the index is invalid, do nothing
  if (index < 0 || index >= size) {
    return;
  }
  size--;
  // find the predecessor of the node to be deleted
  ListNode pred = head;
  for(int i = 0; i < index; ++i) {
    pred = pred.next;
  }
  pred.next = pred.next.next;
}
```

#### Singly Linked list : Get
1. Check the validity of the index given
2. Start from the sentinel node and do index + 1 steps.

```Java
public int get(int index) {
  if (index < 0 || index >= size) {
    return -1;
  }
  for (int i = 0; i < index + 1; ++i) {
    curr = curr.next;
  }
  return curr.val;
}
```
